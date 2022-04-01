#define N 1000000
#define M 1000
struct variable{
    int dim1, dim2, type;
    int *a;
};


struct variable{
    int dim1, dim2, type;
}

tr(variable(5, 1, vector)) -> variable(1, 5, matrix)

testMultiply(variable(2, 4, matrix) , variable(4, 2, matrix)) > variable(2, 2, matrix, [1, 2, 3, 4])
testMultiply(variable(2, 4, matrix) , variable(3, 2, matrix)) > NULL

multiply(a1, a2);


struct matrix{
    int dim1;
    int dim2;
    int ar[M][M];
};
struct vector{
    int dim;
    int ar[N];
};
struct scalar{
    int val;
};
// MATRIX X MATRIX
struct variable multiply(struct variable, struct variable);
void add(struct variable, struct variable);
void subtract(struct variable, struct variable);
struct matrix multiply(struct matrix mat1, struct matrix mat2){
    struct matrix ans;
    ans.dim1=mat1.dim1;
    ans.dim2=mat2.dim2;
    for( int i = 0 ; i < mat1.dim1 ; i++ ){
        for( int j = 0 ; j < mat2.dim2 ; j++ ){
            for( int k = 0 ; k < mat1.dim2 ){
                ans.ar[i][j]+=(mat1.ar[i][k] * mat2.ar[k][j]);        
            }
        }
    }
    return ans;
}
// MATRIX X VECTOR
struct vector multiply(struct matrix mat, struct vector vec){
    struct vector ans;
    ans.dim = mat.dim1;
    for( int i = 0 ; i < mat.dim1 ; i++ ){
        for( int j = 0 ; j < mat.dim2 ; j++ ){
            ans.ar[i]+= ( mat.ar[i][j] * vec.ar[j]);
        }
    }
    return ans;
}
// MATRIX X SCALAR
struct matrix multiply(struct matrix mat, struct scalar c){
    struct matrix ans;
    ans.dim1 = mat.dim1;
    ans.dim2 = mat.dim2;
    for( int i = 0 ; i < mat.dim1 ; i++ ){
        for( int j = 0 ; j <mat.dim2 ; j++){
            ans.ar[i][j] = mat.ar[i][j] * c.val;
        }
    }
    return ans;
}
//VECTOR X VECTOR
struct scalar multiply( struct vector vec1 , struct vector vec2){
    struct scalar ans;
    for( int i = 0 ; i < vec1.dim ; i++){
        ans.val+=(vec1.ar[i] * vec2.ar[vec2.dim-i-1];       
    }
    return ans;
}
//VECTOR X SCALAR
struct vector multiply( struct vector vec , struct scalar c){
    struct vector ans;
    ans.dim = vec.dim;
    for( int i = 0 ; i < ans.dim ; i++ ){
        ans.ar[i]=vec.ar[i] * c.val;
    }
    return ans;
}
// SCALAR X SCALAR
struct scalar multiply(struct scalar a, struct scalar b){
    struct scalar ans;
    ans.val=a.val * b.val;
    return ans.val;
}
// PRINT MATRIX
void print_matrix(struct matrix mat){
    for( int i = 0 ; i < mat.dim1 ; i++ ){
        for( int j = 0 ; j < mat.dim2 ; j++ ){
            printf("%d ",mar.ar[i][j]);
        }
        printf("\n");
    }
    return
}
// PRINT VECTOR
void print_vector(struct vector vec){
    for( int i = 0 ; i < vec.dim ; i++ ){
        printf("%d\n", vec.ar[i]);
    }
    return
}
//PRINT SCALAR
void print_scalar(struct scalar c){
    printf("%d\n",c.val );
    return
}
void create_vector(){

}
void create_matrix(){

}
void create_scalar(){

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
