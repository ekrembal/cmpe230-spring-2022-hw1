#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "enums.h"
#include <stdbool.h>

#define N 1000000
#define M 1000
#define EPS 0.00001
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
double mut(double x){
    return (x < 0)?-x:x;
}
struct Variable * choose( struct Variable * expr1, struct Variable * expr2, struct Variable * expr3, struct Variable * expr4 ){
    if( mut(expr1->val[0][0] - 0) < EPS ){
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
            if((a->val[i][j] - (int)a->val[i][j])<EPS){
                printf("%d ",(int)a->val[i][j]);
            }
            else{
                printf("%lf ",a->val[i][j]);
            }
        }
        printf("\n");
    }
}
void printsep(){
    printf("----------\n");
}
bool isLower(struct Variable * a, struct Variable * b){
    return (a->val[0][0] <= b->val[0][0]);
}
void increase( struct Variable * a, struct Variable * b){
    a->val[0][0] += b->val[0][0];
    return;
}

struct Variable * getSingleIndexInt(struct Variable * a , int index ){
        index--;
        struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
        int row = index / a->dim2;
        int column = index % a->dim2;
        newNode->dim1=1;
        newNode->dim2=1;
        newNode->feature=SCA;
        newNode->val[0][0]=a->val[row][column];
        return newNode;
}
struct Variable * getSingleIndex(struct Variable * a , struct Variable * index ){
        index->val[0][0]--;
        struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
        int row = (int)index->val[0][0] / a->dim2;
        int column = (int)index->val[0][0] % a->dim2;
        newNode->dim1=1;
        newNode->dim2=1;
        newNode->feature=SCA;
        newNode->val[0][0]=a->val[row][column];
        return newNode;
}

struct Variable * getDoubleIndexInt(struct Variable * a , int x, int y ){
        struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
        newNode->dim1=1;
        newNode->dim2=1;
        newNode->feature=SCA;
        newNode->val[0][0]=a->val[x - 1][y - 1];
        return newNode;
}
struct Variable * getDoubleIndex(struct Variable * a , struct Variable * x, struct Variable * y ){
        struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
        newNode->dim1=1;
        newNode->dim2=1;
        newNode->feature=SCA;
        newNode->val[0][0]=a->val[(int)x->val[0][0] - 1][(int)y->val[0][0] - 1];
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
        
    a->val[row][column] = var ;
    return;
}
void assignToIndex(struct Variable * a, struct Variable * index, struct Variable * var  ){
    a->val[(int)index->val[0][0] - 1][0] = var->val[0][0];
    return;
}
void assignToDoubleIndex(struct Variable * a, struct Variable * index1, struct Variable* index2, struct Variable * var ){
    a->val[(int)index1->val[0][0] - 1][(int)index2->val[0][0] - 1] = var->val[0][0];
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



Variable *A = createMatrix(2, 2);
Variable *InvA = createMatrix(2, 2);
Variable *detA = createScalar();
Variable *minusOne = createScalar();
Variable *NRTySFrzrmzlYGF = generateScalarFromNumber(2);
Variable *vEulQfpDBHlqDqr = generateScalarFromNumber(1);
Variable *lrfkQyuQFjKXyQV = substraction(NRTySFrzrmzlYGF, vEulQfpDBHlqDqr);
assign(minusOne, lrfkQyuQFjKXyQV);
assignToFlatten(A, 1, 0);assignToFlatten(A, 2, 1);assignToFlatten(A, 3, 2);assignToFlatten(A, 5, 3);
Variable *a = createScalar();
Variable *b = createScalar();
Variable *c = createScalar();
Variable *d = createScalar();
Variable *AITGDPHCSPIjtHb = generateScalarFromNumber(1);
Variable *sFyfvlADzPBfudk = generateScalarFromNumber(1);
Variable *rCRwDnXeuOQqekl = getDoubleIndex( A, AITGDPHCSPIjtHb, sFyfvlADzPBfudk );
assign(a, rCRwDnXeuOQqekl);
Variable *EffECLhbVFUkBye = generateScalarFromNumber(1);
Variable *qfQOJWTwosILEeZ = generateScalarFromNumber(2);
Variable *KlrwqAOzMiXrpif = getDoubleIndex( A, EffECLhbVFUkBye, qfQOJWTwosILEeZ );
assign(b, KlrwqAOzMiXrpif);
Variable *CQptkhHqrQdwfcA = generateScalarFromNumber(2);
Variable *YSSYoQcJomwUFBd = generateScalarFromNumber(1);
Variable *TxWJLkNgbqQmBxQ = getDoubleIndex( A, CQptkhHqrQdwfcA, YSSYoQcJomwUFBd );
assign(c, TxWJLkNgbqQmBxQ);
Variable *sYBlOetsWCRFHPX = generateScalarFromNumber(2);
Variable *PRbsshSjXDFileB = generateScalarFromNumber(2);
Variable *fXudZHiftaKCZVH = getDoubleIndex( A, sYBlOetsWCRFHPX, PRbsshSjXDFileB );
assign(d, fXudZHiftaKCZVH);
Variable *xwBCTOaYaxzFBjb = multiplication(a, d);
Variable *KRxIRImqPZWMSHl = multiplication(b, c);
Variable *PJhtAZhbuXhwaDL = substraction(xwBCTOaYaxzFBjb, KRxIRImqPZWMSHl);
assign(detA, PJhtAZhbuXhwaDL);
assignToDoubleIndex(InvA, 1, 1, d);
Variable *PTOyeziWkMGSovq = multiplication(minusOne, b);
assignToDoubleIndex(InvA, 1, 2, PTOyeziWkMGSovq);
Variable *zGDIxrPDdZpLcrW = multiplication(minusOne, c);
assignToDoubleIndex(InvA, 2, 1, zGDIxrPDdZpLcrW);
assignToDoubleIndex(InvA, 2, 2, a);
print(InvA);
printsep();
print(detA);

    

    
    

}


