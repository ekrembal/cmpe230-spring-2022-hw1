#include <math.h>
#define N 1000000
#define M 1000

typedef struct Variable {
    char *name;
    int feature;
    int dim1,dim2;
    double val[1000][1000];
}Variable;

struct Variable multiplication(struct Variable a, struct Variable b){
    struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    //SCALAR * SCALAR
    if( (a.dim1 == 1 && a.dim2 == 1 ) && (b.dim1 == 1 && b.dim2 == 1)){
        newNode->feature = SCA;
        newNode.dim1=1;
        newNode.dim2=1;
        newNode.val[0][0] = a.val[0][0] * b.val[0][0];
    }
    //SCALAR * ( MATRIX OR VECTOR )
    
    if( (a.dim1 == 1 && a.dim2 == 1 ) && !(b.dim1 == 1 && b.dim2 == 1) ){
        newNode->feature = MAT;
        newNode.dim1=b.dim1;
        newNode.dim2=b.dim2;
        for( int i = 0 ; i < b.dim1 ; i++ ){
            for( int j = 0 ; j < b.dim2 ; j++ ){
                newNode.val[i][j] = a.val[0][0] * b.val[i][j];
            }
        }
    }
    // (MATRIX OR VECTOR) * SCALAR
    if( !(a.dim1 == 1 && a.dim2 == 1 ) && (b.dim1 == 1 && b.dim2 == 1) ){
        newNode->feature = MAT;
        newNode.dim1=a.dim1;
        newNode.dim2=a.dim2;
        for( int i = 0 ; i < a.dim1 ; i++ ){
            for( int j = 0 ; j < a.dim2 ; j++ ){
                newNode.val[i][j] = a.val[0][0] * a.val[i][j];
            }
        }
    }
    // (MATRIX OR VECTOR) * (MATRIX OR VECTOR)
    if( !(a.dim1 == 1 && a.dim2 == 1 ) && !(b.dim1 == 1 && b.dim2 == 1) ){
        newNode->feature = MAT;
        newNode.dim1=a.dim1;
        newNode.dim2=b.dim2;
        for( int i = 0 ;  i < a.dim1 ; i++ ){
            for( int j = 0 ; j < b.dim2 ; j++ ){
                for( int k = 0 ; k < a.dim2 ; k++ ){
                    newNode.val[i][j]+=(a.val[i][k] + b.val[k][j]);
                }
            }
        }
    }
    return newNode;
}

struct Variable generateScalarFromNumber(double var){
    Variable *newNode = (Variable*)malloc(sizeof(Variable));
    newNode->feature = SCA;
    newNode->dim1 = 1;
    newNode->dim2 = 1;
    return newNode;
}
struct Variable addition( struct Variable a , struct Variable b ){
    struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    newNode->feature = a.feature;
    newNode->dim1 = a.dim1;
    newNode->dim2 = a.dim2;
    for( int i = 0 ;  i < a.dim1 ; i++ ){
        for(int j = 0 ; j < a.dim2 ; j++ ){
            newNode.val[i][j] = a.val[i][j] + b.val[i][j];
        }
    }
    return newNode;
}

struct Variable substraction(struct Variable a, struct Variable b){
    struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    newNode->feature = a.feature;
    newNode->dim1 = a.dim1;
    newNode->dim2 = a.dim2;
    for( int i = 0 ;  i < a.dim1 ; i++ ){
        for(int j = 0 ; j < a.dim2 ; j++ ){
            newNode.val[i][j] = a.val[i][j] - b.val[i][j];
        }
    }
    return newNode;
}
struct Variable sqrt( struct Variable a){
    struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    newNode->feature = a.feature;
    newNode->dim1 = 1;
    newNode->dim2 = 1;
    newNode.val[0][0]=sqrt(a.val[0][0]);
    return newNode;
}
struct Variable transpose( struct Variable a){
    struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    newNode->feature = a.feature;
    newNode->dim1 = a.dim2;
    newNode->dim2 = a.dim1;
    for( int i = 0 ; i < a.dim1 ; i++ ){
        for( int j = 0 ; j < a.dim2 ; j++ ){
            newNode.val[j][i] = a.val[i][j];
        }
    }
    return newNode;
}
struct Variable choose( struct Variable expr1, struct Variable expr2, struct Variable expr3, struct Variable expr4 ){
    if( expr1.val[0][0] == 0 ){
        return expr2;
    }
    else if( expr1.val[0][0] > 0){
        return expr3;
    }
    else if( expr1.val[0][0] < 0 ){
        return expr4;
    }
}
void print( struct Variable a){
    for( int i = 0 ; i < a.dim1 ; i++ ){
        for( int  j = 0 ; j < a.dim2 ; j++ ){
            printf("%lf",a.val[i][j]);
        }
        printf("\n");
    }
}
void assign(double *ptr, double val){
    *ptr = val;
    return;
}
double* getDoublePointer(struct Variable a, int index){
    if(a.dim1==1 && a.dim2==1){
        return a.val;
    }
    if((a.dim1==1 && !a.dim2==1) || (!a.dim1==1 && a.dim2==1)){
        return *(a.val+index);
    }
    if((!a.dim1==1 && !a.dim2==1)){
        return *((a.val+index/dim1)+index%dim1)
    }
    return &(a+index);
}





/*
# this program computes fibonacci
# numbers
# variable definitions
scalar i
scalar n
vector x[2]
vector y[2]
matrix A[2,2]
matrix B[2,2]
# statements
n = 10
x = { 1 1 }
A = { 1 1 1 0 }
B = { 1 0 0 1 }
print(x)
for(i in 1:n:1) {
    B = A*B
    y = B*x
    print(y[1])
}
*/
int main(){
struct variable i = createScalar(i);
struct variable n = createScalar(n);
struct variable x = createVector(x,2);
struct variable y = createVector(y,2);
struct variable A = createMatrix(A,2,2);
struct variable B = createMatrix(B,2,2);
assign(n, 10);
assign(x, 1, 1);
assign(A, 1, 1, 1, 0);
assign(B, 1, 0, 0, 1);
print(x);
for(int i = 1; i <= n; i++){
assign(B, multiply(A, B));
assign(y, multiply(B, x));
print(getValueOf(y, 1));
}
}
