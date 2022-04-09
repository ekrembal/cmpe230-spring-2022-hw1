#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "enums.h"
#include <stdbool.h>

#define N 1000000
#define M 1000
// VEC / SCA / MAT/ NUM/ OP
typedef struct Variable {
    char *name;
    int feature;
    int dim1,dim2;
    double val[1000][1000];
}Variable;
/*
struct Variable *createVariable(){
    struct Variable *newVar = (struct Variable*)malloc(sizeof(struct Variable));
    return  newVar;
}
*/
struct Variable * createScalar(){
    Variable *newNode = (Variable*)malloc(sizeof(Variable));
    newNode->feature = SCA;
    newNode->dim1 = 1;
    newNode->dim2 = 1;
    return newNode;
}
struct Variable * createVector(int a){
    Variable *newNode = (Variable*)malloc(sizeof(Variable));
    newNode->feature = VEC;
    newNode->dim1 = a;
    newNode->dim2 = 1;
    return newNode;
}
struct Variable * createMatrix(int a , int b){
    Variable *newNode = (Variable*)malloc(sizeof(Variable));
    newNode->feature = MAT;
    newNode->dim1 = a;
    newNode->dim2 = b;
    return newNode;
}




struct Variable * multiplication(struct Variable * a, struct Variable * b){
    struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    
    //SCALAR * SCALAR
    if( (a->dim1 == 1 && a->dim2 == 1 ) && (b->dim1 == 1 && b->dim2 == 1)){
        newNode->feature = SCA;
        newNode->dim1=1;
        newNode->dim2=1;
        newNode->val[0][0] = a->val[0][0] * b->val[0][0];
    }
    //SCALAR * ( MATRIX OR VECTOR )
    
    else if( (a->dim1 == 1 && a->dim2 == 1 ) && !(b->dim1 == 1 && b->dim2 == 1) ){
        newNode->feature = MAT;
        newNode->dim1=b->dim1;
        newNode->dim2=b->dim2;
        for( int i = 0 ; i < b->dim1 ; i++ ){
            for( int j = 0 ; j < b->dim2 ; j++ ){
                newNode->val[i][j] = a->val[0][0] * b->val[i][j];
            }
        }
    }
    // (MATRIX OR VECTOR) * SCALAR

    else if( !(a->dim1 == 1 && a->dim2 == 1 ) && (b->dim1 == 1 && b->dim2 == 1) ){
        newNode->feature = MAT;
        newNode->dim1=a->dim1;
        newNode->dim2=a->dim2;
        for( int i = 0 ; i < a->dim1 ; i++ ){
            for( int j = 0 ; j < a->dim2 ; j++ ){
                newNode->val[i][j] = b->val[0][0] * a->val[i][j];
            }
        }
    }
    // (MATRIX OR VECTOR) * (MATRIX OR VECTOR)
    else if( !(a->dim1 == 1 && a->dim2 == 1 ) && !(b->dim1 == 1 && b->dim2 == 1) ){
        newNode->feature = MAT;
        newNode->dim1=a->dim1;
        newNode->dim2=b->dim2;
        for( int i = 0 ;  i < a->dim1 ; i++ ){
            for( int j = 0 ; j < b->dim2 ; j++ ){
                newNode->val[i][j]=0;
                for( int k = 0 ; k < a->dim2 ; k++ ){

                    newNode->val[i][j] += (a->val[i][k] * b->val[k][j]);
                }
            }
        }
    }
    return newNode;
    
}

struct Variable * generateScalarFromNumber(double var){
    Variable *newNode = (Variable*)malloc(sizeof(Variable));
    newNode->feature = SCA;
    newNode->dim1 = 1;
    newNode->dim2 = 1;
    newNode->val[0][0]=var;
    return newNode;
}

struct Variable * addition( struct Variable *a , struct Variable *b ){
    
    struct Variable *newNode = (struct Variable*)malloc(sizeof(struct Variable));
    
    newNode->feature = a->feature;
    newNode->dim1 = a->dim1;
    newNode->dim2 = a->dim2;
    for( int i = 0 ;  i < a->dim1 ; i++ ){
        for(int j = 0 ; j < a->dim2 ; j++ ){
            newNode->val[i][j] = a->val[i][j] + b->val[i][j];
        }
    }
    return newNode;
    
}

struct Variable * substraction(struct Variable *a, struct Variable *b){
    struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    newNode->feature = a->feature;
    newNode->dim1 = a->dim1;
    newNode->dim2 = a->dim2;
    for( int i = 0 ;  i < a->dim1 ; i++ ){
        for(int j = 0 ; j < a->dim2 ; j++ ){
            newNode->val[i][j] = a->val[i][j] - b->val[i][j];
        }
    }
    return newNode;
}
struct Variable * squareroot( struct Variable *a){
    struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    newNode->feature = a->feature;
    newNode->dim1 = 1;
    newNode->dim2 = 1;
    newNode->val[0][0]=sqrt(a->val[0][0]);
    return newNode;
}
struct Variable * transpose( struct Variable * a){
    struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    newNode->feature = a->feature;
    newNode->dim1 = a->dim2;
    newNode->dim2 = a->dim1;
    for( int i = 0 ; i < a->dim1 ; i++ ){
        for( int j = 0 ; j < a->dim2 ; j++ ){
            newNode->val[j][i] = a->val[i][j];
        }
    }
    return newNode;
}
struct Variable * choose( struct Variable * expr1, struct Variable * expr2, struct Variable * expr3, struct Variable * expr4 ){
    if( expr1->val[0][0] == 0 ){
        return expr2;
    }
    else if( expr1->val[0][0] > 0){
        return expr3;
    }
    else if( expr1->val[0][0] < 0 ){
        return expr4;
    }
    return expr1;// not to get warning from compiler
}
void print( struct Variable * a){
    for( int i = 0 ; i < a->dim1 ; i++ ){
        for( int  j = 0 ; j < a->dim2 ; j++ ){
            printf("%lf ",a->val[i][j]);
        }
        printf("\n");
    }
}
bool isLower(struct Variable * a, struct Variable * b){
    return (a->val[0][0] <= b->val[0][0]);
}
void increase( struct Variable * a, struct Variable * b){
    a->val[0][0]+= b->val[0][0];
    return;
}

struct Variable * getSingleIndex(struct Variable * a , int index ){
        struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
        int row = index / a->dim2;
        int column = index % a->dim2;
        newNode->dim1=1;
        newNode->dim2=1;
        newNode->feature=SCA;
        newNode->val[0][0]=a->val[row][column];
        return newNode;
}
void assign(struct Variable * a, struct Variable * b ){
    a->dim1 = b->dim1;
    a->dim2 = b->dim2;
    a->feature = b->feature;
    a->name = b->name;
    for( int i = 0 ; i < 999 ; i++){
        for( int j  = 0 ;  j  < 999 ; j++){
            a->val[i][j] = b->val[i][j];
        }
    }
    return;
}
void assignToFlatten(struct Variable * a , double var , int index ){
        int row = index / a->dim2;
        int column = index % a->dim2;
        printf("%d\n",row);
        printf("%d\n",column);

        a->val[row][column] = var ;
        return;
}
//double* getDoublePointer(struct Variable a, int index){
//    if(a.dim1==1 && a.dim2==1){
//        return &a.val[0][0];
//    }
//    if((a.dim1==1 && a.dim2!=1) || (a.dim1!=1 && a.dim2==1)){
//        return &a.val[0][index];
//    }
//    if((a.dim1!=1 && a.dim2!=1)){
//        return &a.val[index/a.dim1][index%a.dim1];
//    }
//}

int main(){
    /*
    printf("AAAAAAAAAA");
    // VARIABLE DEFINITIONS
    printf("HERE1\n");
    
    
    struct Variable *sc1 = (struct Variable*)malloc(sizeof(struct Variable));
    sc1->dim1=1;
    sc1->dim2=1;
    sc1->feature=SCA;
    sc1->val[0][0]=5;
    printf("HERE2\n");
    
    struct Variable *sc2 = (struct Variable*)malloc(sizeof(struct Variable));
    sc2->dim1=1;
    sc2->dim2=1;
    sc2->feature=SCA;
    sc2->val[0][0]=3;
    printf("HERE3\n");
    
    
    struct Variable *v1 = (struct Variable*)malloc(sizeof(struct Variable));
    v1->dim1=5;
    v1->dim2=1;
    v1->feature=VEC;
    v1->val[0][0]=1; v1->val[1][0]=2; v1->val[2][0]=3; v1->val[3][0]=4; v1->val[4][0]=5; 

    printf("HERE4\n");
    
    
    struct Variable *v2 = (struct Variable*)malloc(sizeof(struct Variable));
    v2->dim1=4;
    v2->dim2=1;
    v2->feature=VEC;
    v2->val[0][0]= 2; v2->val[1][0]= 3; v2->val[2][0]= 4; v2->val[3][0]= 5; 
    
    printf("HERE5\n");

    
    struct Variable *m1 = (struct Variable*)malloc(sizeof(struct Variable));
    m1->dim1 = 3;
    m1->dim2 = 2;
    m1->feature = MAT;
    m1->val[0][0] = 1; m1->val[0][1] = 2;
    m1->val[1][0] = 3; m1->val[1][1] = 4;
    m1->val[2][0] = 5; m1->val[2][1] = 6;  
    
    printf("HERE6\n");
    
    struct Variable *m2 = (struct Variable*)malloc(sizeof(struct Variable));
    m2->dim1 = 2;
    m2->dim2 = 4;
    m2->feature = MAT;
    m2->val[0][0] = 1; m2->val[0][1] = 2; m2->val[0][2] = 3; m2->val[0][3] = 4;
    m2->val[1][0] = 1; m2->val[1][1] = 2; m2->val[1][2] = 3; m2->val[1][3] = 4;
    printf("HERE7\n");
    
    struct Variable *m3 = (struct Variable*)malloc(sizeof(struct Variable));
    m3->dim1 = 2;
    m3->dim2 = 4;
    m3->feature = MAT;
    m3->val[0][0] = 1; m3->val[0][1] = 2; m3->val[0][2] = 3; m3->val[0][3] = 4;
    m3->val[1][0] = 1; m3->val[1][1] = 2; m3->val[1][2] = 3; m3->val[1][3] = 4;
    printf("HERE7\n");

    
    struct Variable *ans ; // =(struct Variable*)malloc(sizeof(struct Variable));
    
    printf("\n CREATE SCALAR TEST\n");
    ans = createScalar();
    print(ans);

    printf("\n CREATE VECTOR TEST\n");
    ans = createVector(10);
    print(ans);

    printf("\n CREATE MATRIX TEST\n");
    ans = createMatrix(4,3);
    print(ans);    

    assignToFlatten(ans,5 , 8);

    print(ans);    



    printf("\nADDITION TEST\n");
    ans = addition(m2,m3);
    print(ans);

    printf("\nSUBTRACTION TEST\n");
    ans = substraction(m2,m3);
    print(ans);

    printf("\nCHOOSE TEST\n");
    ans = choose(sc1,v1,v2,m1);
    print(ans);

    printf("\nTRANSPOSE TEST VECTOR\n");
    ans = transpose(v1);
    print(ans);

    printf("\nTRANSPOSE TEST MATRIX\n");
    ans = transpose(m1);
    print(ans);

    printf("\nSQUAREROOT TEST\n");
    ans = squareroot(sc1);
    print(ans);

    printf("\nGENERATESCALARFROMNUMBER TEST\n");
    ans = generateScalarFromNumber(5   );
    print(ans);

    printf("\nSCALAR X SCALAR MULTIPLICATION TEST\n");
    ans = multiplication(sc1,sc2);
    print(ans);

    printf("\nMATRIX X SCALAR MULTIPLICATION TEST\n");
    ans = multiplication(m1,sc2);
    print(ans);

    printf("\nSCALAR X VECTOR MULTIPLICATION TEST\n");
    ans = multiplication(sc1,v1);
    print(ans);

    
    printf("\nMATRIX X MATRIX MULTIPLICATION TEST\n");
    ans = multiplication(m1,m2);
    print(ans);
    */
Variable *i = createScalar();
Variable *n = createScalar();
Variable *x = createVector(2);
Variable *y = createVector(2);
Variable *A = createMatrix(2, 2);
Variable *B = createMatrix(2, 2);
Variable *lrfkQyuQFjKXyQV = generateScalarFromNumber(10);
assign(n, lrfkQyuQFjKXyQV);
assignToFlatten(x, 1, 0);assignToFlatten(x, 1, 1);
assignToFlatten(A, 1, 0);assignToFlatten(A, 1, 1);assignToFlatten(A, 1, 2);assignToFlatten(A, 0, 3);
assignToFlatten(B, 1, 0);assignToFlatten(B, 0, 1);assignToFlatten(B, 0, 2);assignToFlatten(B, 1, 3);
print(x);
Variable *NRTySFrzrmzlYGF = generateScalarFromNumber(1);
Variable *vEulQfpDBHlqDqr = generateScalarFromNumber(1);
for(assign(i,NRTySFrzrmzlYGF); isLower(i,n); increase(i,vEulQfpDBHlqDqr)){
Variable *rCRwDnXeuOQqekl = multiplication(A, B);
assign(B, rCRwDnXeuOQqekl);
Variable *AITGDPHCSPIjtHb = multiplication(B, x);
assign(y, AITGDPHCSPIjtHb);
print(getSingleIndex(y, 1));
}

    

    
    

}


