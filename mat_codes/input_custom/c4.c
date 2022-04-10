#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define EPS 0.00001
enum type{OP, NUM, MAT, VEC, SCA};typedef struct Variable {int feature;int dim1,dim2;double val[1000][1000];}Variable;struct Variable * createScalar(){Variable *newNode = (Variable*)malloc(sizeof(Variable));newNode->feature = SCA;newNode->dim1 = 1;newNode->dim2 = 1;return newNode;}struct Variable * createVector(int a){Variable *newNode = (Variable*)malloc(sizeof(Variable));newNode->feature = VEC;newNode->dim1 = a;newNode->dim2 = 1;return newNode;}struct Variable * createMatrix(int a , int b){Variable *newNode = (Variable*)malloc(sizeof(Variable));newNode->feature = MAT;newNode->dim1 = a;newNode->dim2 = b;return newNode;}struct Variable * multiplication(struct Variable * a, struct Variable * b){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));if( (a->dim1 == 1 && a->dim2 == 1 ) && (b->dim1 == 1 && b->dim2 == 1)){newNode->feature = SCA;newNode->dim1=1;newNode->dim2=1;newNode->val[0][0] = a->val[0][0] * b->val[0][0];}else if( (a->dim1 == 1 && a->dim2 == 1 ) && !(b->dim1 == 1 && b->dim2 == 1) ){newNode->feature = MAT;newNode->dim1=b->dim1;newNode->dim2=b->dim2;for( int i = 0 ; i < b->dim1 ; i++ ){for( int j = 0 ; j < b->dim2 ; j++ ){newNode->val[i][j] = a->val[0][0] * b->val[i][j];}}}else if( !(a->dim1 == 1 && a->dim2 == 1 ) && (b->dim1 == 1 && b->dim2 == 1) ){newNode->feature = MAT;newNode->dim1=a->dim1;newNode->dim2=a->dim2;for( int i = 0 ; i < a->dim1 ; i++ ){for( int j = 0 ; j < a->dim2 ; j++ ){newNode->val[i][j] = b->val[0][0] * a->val[i][j];}}}else if( !(a->dim1 == 1 && a->dim2 == 1 ) && !(b->dim1 == 1 && b->dim2 == 1) ){newNode->feature = MAT;newNode->dim1=a->dim1;newNode->dim2=b->dim2;for( int i = 0 ;  i < a->dim1 ; i++ ){for( int j = 0 ; j < b->dim2 ; j++ ){newNode->val[i][j]=0;for( int k = 0 ; k < a->dim2 ; k++ ){newNode->val[i][j] += (a->val[i][k] * b->val[k][j]);}}}}return newNode;}struct Variable * generateScalarFromNumber(double var){Variable *newNode = (Variable*)malloc(sizeof(Variable));newNode->feature = SCA;newNode->dim1 = 1;newNode->dim2 = 1;newNode->val[0][0]=var;return newNode;}struct Variable * addition( struct Variable *a , struct Variable *b ){struct Variable *newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->feature = a->feature;newNode->dim1 = a->dim1;newNode->dim2 = a->dim2;for( int i = 0 ;  i < a->dim1 ; i++ ){for(int j = 0 ; j < a->dim2 ; j++ ){newNode->val[i][j] = a->val[i][j] + b->val[i][j];}}return newNode;}struct Variable * substraction(struct Variable *a, struct Variable *b){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->feature = a->feature;newNode->dim1 = a->dim1;newNode->dim2 = a->dim2;for( int i = 0 ;  i < a->dim1 ; i++ ){for(int j = 0 ; j < a->dim2 ; j++ ){newNode->val[i][j] = a->val[i][j] - b->val[i][j];}}return newNode;}struct Variable * squareroot( struct Variable *a){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->feature = a->feature;newNode->dim1 = 1;newNode->dim2 = 1;newNode->val[0][0]=sqrt(a->val[0][0]);return newNode;}struct Variable * transpose( struct Variable * a){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->feature = a->feature;newNode->dim1 = a->dim2;newNode->dim2 = a->dim1;for( int i = 0 ; i < a->dim1 ; i++ ){for( int j = 0 ; j < a->dim2 ; j++ ){newNode->val[j][i] = a->val[i][j];}}return newNode;}double mut(double x){return (x < 0)?-x:x;}struct Variable * choose( struct Variable * expr1, struct Variable * expr2, struct Variable * expr3, struct Variable * expr4 ){if( mut(expr1->val[0][0] - 0) < EPS ){return expr2;}else if( expr1->val[0][0] > 0){return expr3;}else if( expr1->val[0][0] < 0 ){return expr4;}return expr1;}void print( struct Variable * a){for( int i = 0 ; i < a->dim1 ; i++ ){for( int  j = 0 ; j < a->dim2 ; j++ ){if((a->val[i][j] - (int)a->val[i][j])<EPS){printf("%d ",(int)a->val[i][j]);}else{printf("%lf ",a->val[i][j]);}}printf("\n");}}void printsep(){printf("----------\n");}bool isLower(struct Variable * a, struct Variable * b){return (a->val[0][0] <= b->val[0][0]);}void increase( struct Variable * a, struct Variable * b){a->val[0][0] += b->val[0][0];return;}struct Variable * getSingleIndexInt(struct Variable * a , int index ){index--;struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));int row = index / a->dim2;int column = index % a->dim2;newNode->dim1=1;newNode->dim2=1;newNode->feature=SCA;newNode->val[0][0]=a->val[row][column];return newNode;}struct Variable * getSingleIndex(struct Variable * a , struct Variable * index ){int temp = index->val[0][0] - 1;struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));int row = temp / a->dim2;int column = temp % a->dim2;newNode->dim1=1;newNode->dim2=1;newNode->feature=SCA;newNode->val[0][0]=a->val[row][column];return newNode;}struct Variable * getDoubleIndexInt(struct Variable * a , int x, int y ){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->dim1=1;newNode->dim2=1;newNode->feature=SCA;newNode->val[0][0]=a->val[x - 1][y - 1];return newNode;}struct Variable * getDoubleIndex(struct Variable * a , struct Variable * x, struct Variable * y ){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->dim1=1;newNode->dim2=1;newNode->feature=SCA;newNode->val[0][0]=a->val[(int)x->val[0][0] - 1][(int)y->val[0][0] - 1];return newNode;}void assign(struct Variable * a, struct Variable * b ){a->dim1 = b->dim1;a->dim2 = b->dim2;a->feature = b->feature;for( int i = 0 ; i < 999 ; i++){for( int j  = 0 ;  j  < 999 ; j++){a->val[i][j] = b->val[i][j];}}return;}void assignToFlatten(struct Variable * a , double var , int index ){int row = index / a->dim2;int column = index % a->dim2;a->val[row][column] = var ;return;}void assignToIndex(struct Variable * a, struct Variable * index, struct Variable * var  ){a->val[(int)index->val[0][0] - 1][0] = var->val[0][0];return;}void assignToDoubleIndex(struct Variable * a, struct Variable * index1, struct Variable* index2, struct Variable * var ){a->val[(int)index1->val[0][0] - 1][(int)index2->val[0][0] - 1] = var->val[0][0];return;}
int main(){
Variable *_A = createMatrix(2, 2);
Variable *_i = createScalar();
Variable *_j = createScalar();
Variable *_t = createScalar();
print(_t);
printsep();
printsep();
printsep();
assignToFlatten(_A, 1, 0);assignToFlatten(_A, 2, 1);assignToFlatten(_A, 3, 2);assignToFlatten(_A, 4, 3);
Variable *_jjX2A9VNFsfJ4qH = generateScalarFromNumber(1);
Variable *_LoGBufBRBHNmNqf = generateScalarFromNumber(1);
Variable *_fzxc0WG0lVAj6AT = getDoubleIndex( _A, _jjX2A9VNFsfJ4qH, _LoGBufBRBHNmNqf );
Variable *_gqHSf71iezcBdjb = generateScalarFromNumber(1);
Variable *_EHKvrLK5t5pJqPy = generateScalarFromNumber(2);
Variable *_XqfK9Nxwuggw4mF = getDoubleIndex( _A, _gqHSf71iezcBdjb, _EHKvrLK5t5pJqPy );
Variable *_ehHGCc0Fy6fV74l = generateScalarFromNumber(1);
Variable *_gZQKLSjEy4CZwcD = generateScalarFromNumber(2);
Variable *_VRab5y965CSUrp2 = generateScalarFromNumber(1);
Variable *_olx4OhLjzJCaRYs = getDoubleIndex( _A, _gZQKLSjEy4CZwcD, _VRab5y965CSUrp2 );
Variable *_AQWygqUNk06ONHx = generateScalarFromNumber(2);
Variable *_BBKNLvwJByKkPJn = generateScalarFromNumber(2);
Variable *_649VOR3g7qLY34A = getDoubleIndex( _A, _AQWygqUNk06ONHx, _BBKNLvwJByKkPJn );
Variable *_kGR7Q0B0MwbPNRB = generateScalarFromNumber(1);
for(assign(_i,_fzxc0WG0lVAj6AT); isLower(_i,_XqfK9Nxwuggw4mF); increase(_i,_ehHGCc0Fy6fV74l)){
for(assign(_j,_olx4OhLjzJCaRYs); isLower(_j,_649VOR3g7qLY34A); increase(_j,_kGR7Q0B0MwbPNRB)){
Variable *_7BJI6dqpRz1glsX = addition(_j, _i);
Variable *_JsDClAyQ67Rr71R = addition(_7BJI6dqpRz1glsX, _t);
assign(_t, _JsDClAyQ67Rr71R);
print(_t);
}}
print(_t);
return 0;
}
