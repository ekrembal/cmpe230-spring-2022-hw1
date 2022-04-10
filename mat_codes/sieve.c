#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define EPS 0.00001
enum type{OP, NUM, MAT, VEC, SCA};typedef struct Variable {int feature;int dim1,dim2;double val[1000][1000];}Variable;struct Variable * createScalar(){Variable *newNode = (Variable*)malloc(sizeof(Variable));newNode->feature = SCA;newNode->dim1 = 1;newNode->dim2 = 1;return newNode;}struct Variable * createVector(int a){Variable *newNode = (Variable*)malloc(sizeof(Variable));newNode->feature = VEC;newNode->dim1 = a;newNode->dim2 = 1;return newNode;}struct Variable * createMatrix(int a , int b){Variable *newNode = (Variable*)malloc(sizeof(Variable));newNode->feature = MAT;newNode->dim1 = a;newNode->dim2 = b;return newNode;}struct Variable * multiplication(struct Variable * a, struct Variable * b){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));if( (a->dim1 == 1 && a->dim2 == 1 ) && (b->dim1 == 1 && b->dim2 == 1)){newNode->feature = SCA;newNode->dim1=1;newNode->dim2=1;newNode->val[0][0] = a->val[0][0] * b->val[0][0];}else if( (a->dim1 == 1 && a->dim2 == 1 ) && !(b->dim1 == 1 && b->dim2 == 1) ){newNode->feature = MAT;newNode->dim1=b->dim1;newNode->dim2=b->dim2;for( int i = 0 ; i < b->dim1 ; i++ ){for( int j = 0 ; j < b->dim2 ; j++ ){newNode->val[i][j] = a->val[0][0] * b->val[i][j];}}}else if( !(a->dim1 == 1 && a->dim2 == 1 ) && (b->dim1 == 1 && b->dim2 == 1) ){newNode->feature = MAT;newNode->dim1=a->dim1;newNode->dim2=a->dim2;for( int i = 0 ; i < a->dim1 ; i++ ){for( int j = 0 ; j < a->dim2 ; j++ ){newNode->val[i][j] = b->val[0][0] * a->val[i][j];}}}else if( !(a->dim1 == 1 && a->dim2 == 1 ) && !(b->dim1 == 1 && b->dim2 == 1) ){newNode->feature = MAT;newNode->dim1=a->dim1;newNode->dim2=b->dim2;for( int i = 0 ;  i < a->dim1 ; i++ ){for( int j = 0 ; j < b->dim2 ; j++ ){newNode->val[i][j]=0;for( int k = 0 ; k < a->dim2 ; k++ ){newNode->val[i][j] += (a->val[i][k] * b->val[k][j]);}}}}return newNode;}struct Variable * generateScalarFromNumber(double var){Variable *newNode = (Variable*)malloc(sizeof(Variable));newNode->feature = SCA;newNode->dim1 = 1;newNode->dim2 = 1;newNode->val[0][0]=var;return newNode;}struct Variable * addition( struct Variable *a , struct Variable *b ){struct Variable *newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->feature = a->feature;newNode->dim1 = a->dim1;newNode->dim2 = a->dim2;for( int i = 0 ;  i < a->dim1 ; i++ ){for(int j = 0 ; j < a->dim2 ; j++ ){newNode->val[i][j] = a->val[i][j] + b->val[i][j];}}return newNode;}struct Variable * substraction(struct Variable *a, struct Variable *b){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->feature = a->feature;newNode->dim1 = a->dim1;newNode->dim2 = a->dim2;for( int i = 0 ;  i < a->dim1 ; i++ ){for(int j = 0 ; j < a->dim2 ; j++ ){newNode->val[i][j] = a->val[i][j] - b->val[i][j];}}return newNode;}struct Variable * squareroot( struct Variable *a){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->feature = a->feature;newNode->dim1 = 1;newNode->dim2 = 1;newNode->val[0][0]=sqrt(a->val[0][0]);return newNode;}struct Variable * transpose( struct Variable * a){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->feature = a->feature;newNode->dim1 = a->dim2;newNode->dim2 = a->dim1;for( int i = 0 ; i < a->dim1 ; i++ ){for( int j = 0 ; j < a->dim2 ; j++ ){newNode->val[j][i] = a->val[i][j];}}return newNode;}double mut(double x){return (x < 0)?-x:x;}struct Variable * choose( struct Variable * expr1, struct Variable * expr2, struct Variable * expr3, struct Variable * expr4 ){if( mut(expr1->val[0][0] - 0) < EPS ){return expr2;}else if( expr1->val[0][0] > 0){return expr3;}else if( expr1->val[0][0] < 0 ){return expr4;}return expr1;}void print( struct Variable * a){for( int i = 0 ; i < a->dim1 ; i++ ){for( int  j = 0 ; j < a->dim2 ; j++ ){if((a->val[i][j] - (int)a->val[i][j])<EPS){printf("%d ",(int)a->val[i][j]);}else{printf("%lf ",a->val[i][j]);}}printf("\n");}}void printsep(){printf("----------\n");}bool isLower(struct Variable * a, struct Variable * b){return (a->val[0][0] <= b->val[0][0]);}void increase( struct Variable * a, struct Variable * b){a->val[0][0] += b->val[0][0];return;}struct Variable * getSingleIndexInt(struct Variable * a , int index ){index--;struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));int row = index / a->dim2;int column = index % a->dim2;newNode->dim1=1;newNode->dim2=1;newNode->feature=SCA;newNode->val[0][0]=a->val[row][column];return newNode;}struct Variable * getSingleIndex(struct Variable * a , struct Variable * index ){int temp = index->val[0][0] - 1;struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));int row = temp / a->dim2;int column = temp % a->dim2;newNode->dim1=1;newNode->dim2=1;newNode->feature=SCA;newNode->val[0][0]=a->val[row][column];return newNode;}struct Variable * getDoubleIndexInt(struct Variable * a , int x, int y ){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->dim1=1;newNode->dim2=1;newNode->feature=SCA;newNode->val[0][0]=a->val[x - 1][y - 1];return newNode;}struct Variable * getDoubleIndex(struct Variable * a , struct Variable * x, struct Variable * y ){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->dim1=1;newNode->dim2=1;newNode->feature=SCA;newNode->val[0][0]=a->val[(int)x->val[0][0] - 1][(int)y->val[0][0] - 1];return newNode;}void assign(struct Variable * a, struct Variable * b ){a->dim1 = b->dim1;a->dim2 = b->dim2;a->feature = b->feature;for( int i = 0 ; i < 999 ; i++){for( int j  = 0 ;  j  < 999 ; j++){a->val[i][j] = b->val[i][j];}}return;}void assignToFlatten(struct Variable * a , double var , int index ){int row = index / a->dim2;int column = index % a->dim2;a->val[row][column] = var ;return;}void assignToIndex(struct Variable * a, struct Variable * index, struct Variable * var  ){a->val[(int)index->val[0][0] - 1][0] = var->val[0][0];return;}void assignToDoubleIndex(struct Variable * a, struct Variable * index1, struct Variable* index2, struct Variable * var ){a->val[(int)index1->val[0][0] - 1][(int)index2->val[0][0] - 1] = var->val[0][0];return;}
int main(){
Variable *i = createScalar();
Variable *j = createScalar();
Variable *primes = createVector(100);
Variable *fzxc0WG0lVAj6AT = generateScalarFromNumber(1);
Variable *jjX2A9VNFsfJ4qH = generateScalarFromNumber(1);
assignToIndex(primes, fzxc0WG0lVAj6AT, jjX2A9VNFsfJ4qH);
Variable *LoGBufBRBHNmNqf = generateScalarFromNumber(2);
Variable *XqfK9Nxwuggw4mF = generateScalarFromNumber(0);
assignToIndex(primes, LoGBufBRBHNmNqf, XqfK9Nxwuggw4mF);
Variable *gqHSf71iezcBdjb = generateScalarFromNumber(2);
Variable *EHKvrLK5t5pJqPy = generateScalarFromNumber(100);
Variable *ehHGCc0Fy6fV74l = generateScalarFromNumber(1);
Variable *olx4OhLjzJCaRYs = addition(i, i);
Variable *gZQKLSjEy4CZwcD = generateScalarFromNumber(100);
for(assign(i,gqHSf71iezcBdjb); isLower(i,EHKvrLK5t5pJqPy); increase(i,ehHGCc0Fy6fV74l)){
for(assign(j,olx4OhLjzJCaRYs); isLower(j,gZQKLSjEy4CZwcD); increase(j,i)){
print(i);
Variable *VRab5y965CSUrp2 = getSingleIndex( primes, i );
print(VRab5y965CSUrp2);
printsep();
Variable *649VOR3g7qLY34A = getSingleIndex( primes, i );
Variable *AQWygqUNk06ONHx = getSingleIndex( primes, j );
Variable *BBKNLvwJByKkPJn = getSingleIndex( primes, j );
Variable *7BJI6dqpRz1glsX = generateScalarFromNumber(1);
Variable *kGR7Q0B0MwbPNRB = choose( 649VOR3g7qLY34A, 7BJI6dqpRz1glsX, AQWygqUNk06ONHx, BBKNLvwJByKkPJn );
assignToIndex(primes, j, kGR7Q0B0MwbPNRB);
}}
Variable *JsDClAyQ67Rr71R = generateScalarFromNumber(1);
Variable *83pEVYSS5RyWOLZ = generateScalarFromNumber(100);
Variable *LVXDSZ7h6HJk0tJ = generateScalarFromNumber(1);
for(assign(i,JsDClAyQ67Rr71R); isLower(i,83pEVYSS5RyWOLZ); increase(i,LVXDSZ7h6HJk0tJ)){
Variable *BfIewjUiks8qojm = getSingleIndex( primes, i );
Variable *bwQ4YUInOGVfXYO = generateScalarFromNumber(1);
Variable *2XleWRbjzwgnZRc = generateScalarFromNumber(2);
Variable *xRhcckQQlPEutoN = generateScalarFromNumber(3);
Variable *Z4HUXbH5Xp338Xs = choose( BfIewjUiks8qojm, bwQ4YUInOGVfXYO, 2XleWRbjzwgnZRc, xRhcckQQlPEutoN );
print(Z4HUXbH5Xp338Xs);
}
return 0;
}
