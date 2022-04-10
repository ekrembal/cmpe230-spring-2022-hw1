#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define EPS 0.00001
enum type{OP, NUM, MAT, VEC, SCA};typedef struct Variable {int feature;int dim1,dim2;double val[1000][1000];}Variable;struct Variable * createScalar(){Variable *newNode = (Variable*)malloc(sizeof(Variable));newNode->feature = SCA;newNode->dim1 = 1;newNode->dim2 = 1;return newNode;}struct Variable * createVector(int a){Variable *newNode = (Variable*)malloc(sizeof(Variable));newNode->feature = VEC;newNode->dim1 = a;newNode->dim2 = 1;return newNode;}struct Variable * createMatrix(int a , int b){Variable *newNode = (Variable*)malloc(sizeof(Variable));newNode->feature = MAT;newNode->dim1 = a;newNode->dim2 = b;return newNode;}struct Variable * multiplication(struct Variable * a, struct Variable * b){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));if( (a->dim1 == 1 && a->dim2 == 1 ) && (b->dim1 == 1 && b->dim2 == 1)){newNode->feature = SCA;newNode->dim1=1;newNode->dim2=1;newNode->val[0][0] = a->val[0][0] * b->val[0][0];}else if( (a->dim1 == 1 && a->dim2 == 1 ) && !(b->dim1 == 1 && b->dim2 == 1) ){newNode->feature = MAT;newNode->dim1=b->dim1;newNode->dim2=b->dim2;for( int i = 0 ; i < b->dim1 ; i++ ){for( int j = 0 ; j < b->dim2 ; j++ ){newNode->val[i][j] = a->val[0][0] * b->val[i][j];}}}else if( !(a->dim1 == 1 && a->dim2 == 1 ) && (b->dim1 == 1 && b->dim2 == 1) ){newNode->feature = MAT;newNode->dim1=a->dim1;newNode->dim2=a->dim2;for( int i = 0 ; i < a->dim1 ; i++ ){for( int j = 0 ; j < a->dim2 ; j++ ){newNode->val[i][j] = b->val[0][0] * a->val[i][j];}}}else if( !(a->dim1 == 1 && a->dim2 == 1 ) && !(b->dim1 == 1 && b->dim2 == 1) ){newNode->feature = MAT;newNode->dim1=a->dim1;newNode->dim2=b->dim2;for( int i = 0 ;  i < a->dim1 ; i++ ){for( int j = 0 ; j < b->dim2 ; j++ ){newNode->val[i][j]=0;for( int k = 0 ; k < a->dim2 ; k++ ){newNode->val[i][j] += (a->val[i][k] * b->val[k][j]);}}}}return newNode;}struct Variable * generateScalarFromNumber(double var){Variable *newNode = (Variable*)malloc(sizeof(Variable));newNode->feature = SCA;newNode->dim1 = 1;newNode->dim2 = 1;newNode->val[0][0]=var;return newNode;}struct Variable * addition( struct Variable *a , struct Variable *b ){struct Variable *newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->feature = a->feature;newNode->dim1 = a->dim1;newNode->dim2 = a->dim2;for( int i = 0 ;  i < a->dim1 ; i++ ){for(int j = 0 ; j < a->dim2 ; j++ ){newNode->val[i][j] = a->val[i][j] + b->val[i][j];}}return newNode;}struct Variable * substraction(struct Variable *a, struct Variable *b){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->feature = a->feature;newNode->dim1 = a->dim1;newNode->dim2 = a->dim2;for( int i = 0 ;  i < a->dim1 ; i++ ){for(int j = 0 ; j < a->dim2 ; j++ ){newNode->val[i][j] = a->val[i][j] - b->val[i][j];}}return newNode;}struct Variable * squareroot( struct Variable *a){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->feature = a->feature;newNode->dim1 = 1;newNode->dim2 = 1;newNode->val[0][0]=sqrt(a->val[0][0]);return newNode;}struct Variable * transpose( struct Variable * a){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->feature = a->feature;newNode->dim1 = a->dim2;newNode->dim2 = a->dim1;for( int i = 0 ; i < a->dim1 ; i++ ){for( int j = 0 ; j < a->dim2 ; j++ ){newNode->val[j][i] = a->val[i][j];}}return newNode;}double mut(double x){return (x < 0)?-x:x;}struct Variable * choose( struct Variable * expr1, struct Variable * expr2, struct Variable * expr3, struct Variable * expr4 ){if( mut(expr1->val[0][0] - 0) < EPS ){return expr2;}else if( expr1->val[0][0] > 0){return expr3;}else if( expr1->val[0][0] < 0 ){return expr4;}return expr1;}void print( struct Variable * a){for( int i = 0 ; i < a->dim1 ; i++ ){for( int  j = 0 ; j < a->dim2 ; j++ ){if((a->val[i][j] - (int)a->val[i][j])<EPS){printf("%d ",(int)a->val[i][j]);}else{printf("%lf ",a->val[i][j]);}}printf("\n");}}void printsep(){printf("----------\n");}bool isLower(struct Variable * a, struct Variable * b){return (a->val[0][0] <= b->val[0][0]);}void increase( struct Variable * a, struct Variable * b){a->val[0][0] += b->val[0][0];return;}struct Variable * getSingleIndexInt(struct Variable * a , int index ){index--;struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));int row = index / a->dim2;int column = index % a->dim2;newNode->dim1=1;newNode->dim2=1;newNode->feature=SCA;newNode->val[0][0]=a->val[row][column];return newNode;}struct Variable * getSingleIndex(struct Variable * a , struct Variable * index ){int temp = index->val[0][0] - 1;struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));int row = temp / a->dim2;int column = temp % a->dim2;newNode->dim1=1;newNode->dim2=1;newNode->feature=SCA;newNode->val[0][0]=a->val[row][column];return newNode;}struct Variable * getDoubleIndexInt(struct Variable * a , int x, int y ){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->dim1=1;newNode->dim2=1;newNode->feature=SCA;newNode->val[0][0]=a->val[x - 1][y - 1];return newNode;}struct Variable * getDoubleIndex(struct Variable * a , struct Variable * x, struct Variable * y ){struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));newNode->dim1=1;newNode->dim2=1;newNode->feature=SCA;newNode->val[0][0]=a->val[(int)x->val[0][0] - 1][(int)y->val[0][0] - 1];return newNode;}void assign(struct Variable * a, struct Variable * b ){a->dim1 = b->dim1;a->dim2 = b->dim2;a->feature = b->feature;for( int i = 0 ; i < 999 ; i++){for( int j  = 0 ;  j  < 999 ; j++){a->val[i][j] = b->val[i][j];}}return;}void assignToFlatten(struct Variable * a , double var , int index ){int row = index / a->dim2;int column = index % a->dim2;a->val[row][column] = var ;return;}void assignToIndex(struct Variable * a, struct Variable * index, struct Variable * var  ){a->val[(int)index->val[0][0] - 1][0] = var->val[0][0];return;}void assignToDoubleIndex(struct Variable * a, struct Variable * index1, struct Variable* index2, struct Variable * var ){a->val[(int)index1->val[0][0] - 1][(int)index2->val[0][0] - 1] = var->val[0][0];return;}
int main(){
Variable *A = createMatrix(2, 2);
Variable *InvA = createMatrix(2, 2);
Variable *detA = createScalar();
Variable *minusOne = createScalar();
Variable *a = createScalar();
Variable *b = createScalar();
Variable *c = createScalar();
Variable *d = createScalar();
Variable *jjX2A9VNFsfJ4qH = generateScalarFromNumber(2);
Variable *LoGBufBRBHNmNqf = generateScalarFromNumber(1);
Variable *fzxc0WG0lVAj6AT = substraction(jjX2A9VNFsfJ4qH, LoGBufBRBHNmNqf);
assign(minusOne, fzxc0WG0lVAj6AT);
assignToFlatten(A, 1, 0);assignToFlatten(A, 2, 1);assignToFlatten(A, 3, 2);assignToFlatten(A, 5, 3);
Variable *gqHSf71iezcBdjb = generateScalarFromNumber(1);
Variable *EHKvrLK5t5pJqPy = generateScalarFromNumber(1);
Variable *XqfK9Nxwuggw4mF = getDoubleIndex( A, gqHSf71iezcBdjb, EHKvrLK5t5pJqPy );
assign(a, XqfK9Nxwuggw4mF);
Variable *olx4OhLjzJCaRYs = generateScalarFromNumber(1);
Variable *gZQKLSjEy4CZwcD = generateScalarFromNumber(2);
Variable *ehHGCc0Fy6fV74l = getDoubleIndex( A, olx4OhLjzJCaRYs, gZQKLSjEy4CZwcD );
assign(b, ehHGCc0Fy6fV74l);
Variable *649VOR3g7qLY34A = generateScalarFromNumber(2);
Variable *AQWygqUNk06ONHx = generateScalarFromNumber(1);
Variable *VRab5y965CSUrp2 = getDoubleIndex( A, 649VOR3g7qLY34A, AQWygqUNk06ONHx );
assign(c, VRab5y965CSUrp2);
Variable *kGR7Q0B0MwbPNRB = generateScalarFromNumber(2);
Variable *7BJI6dqpRz1glsX = generateScalarFromNumber(2);
Variable *BBKNLvwJByKkPJn = getDoubleIndex( A, kGR7Q0B0MwbPNRB, 7BJI6dqpRz1glsX );
assign(d, BBKNLvwJByKkPJn);
Variable *JsDClAyQ67Rr71R = multiplication(a, d);
Variable *83pEVYSS5RyWOLZ = multiplication(b, c);
Variable *LVXDSZ7h6HJk0tJ = substraction(JsDClAyQ67Rr71R, 83pEVYSS5RyWOLZ);
assign(detA, LVXDSZ7h6HJk0tJ);
Variable *BfIewjUiks8qojm = generateScalarFromNumber(1);
Variable *Z4HUXbH5Xp338Xs = generateScalarFromNumber(1);
assignToDoubleIndex(InvA, BfIewjUiks8qojm, Z4HUXbH5Xp338Xs, d);
Variable *bwQ4YUInOGVfXYO = generateScalarFromNumber(1);
Variable *2XleWRbjzwgnZRc = generateScalarFromNumber(2);
Variable *xRhcckQQlPEutoN = multiplication(minusOne, b);
assignToDoubleIndex(InvA, bwQ4YUInOGVfXYO, 2XleWRbjzwgnZRc, xRhcckQQlPEutoN);
Variable *WWajJb4pssczxPD = generateScalarFromNumber(2);
Variable *NwTtplfjV5Z9yBm = generateScalarFromNumber(1);
Variable *zye88fNJe8BcXsq = multiplication(minusOne, c);
assignToDoubleIndex(InvA, WWajJb4pssczxPD, NwTtplfjV5Z9yBm, zye88fNJe8BcXsq);
Variable *B6reMIm1YyBMjfi = generateScalarFromNumber(2);
Variable *NlSUTIn5yMpo9Eo = generateScalarFromNumber(2);
assignToDoubleIndex(InvA, B6reMIm1YyBMjfi, NlSUTIn5yMpo9Eo, a);
print(InvA);
printsep();
print(detA);
return 0;
}
