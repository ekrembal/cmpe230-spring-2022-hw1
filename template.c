struct variable{
    bool isMatrix;
    bool isVector;
    bool isScalar;
    int dim1, dim2;
    int *a;
};

struct variable multiply(struct variable, struct variable);
void add(struct variable, struct variable);
void subtract(struct variable, struct variable);

struct matrix multiply(struct matrix, struct scalar){
    //for( int i = 0 ; i < matrix.dim1 ; i++ ){
    //    for( int j = 0 ; j < matrix.dim2 ; j++ ){
    //        matrix.a[i][j] = matrix.a[i][j] * scalar.a;
    //    }
    //}
    
    //Opening File
    FILE *fp=fopen("file.c", "a");
    if(fp==NULL) {
        perror("Error opening file.");
    }
    fprintf(fp, "for( int i = 0 ; i < %d ; i++ ){\n", matrix.dim1);
    fprintf(fp, "   for( int j = 0 ; j < %d ; j++ ){\n",matrix.dim2);
    fprintf(fp, "       m", 2012);
    fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);
    fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);
    fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);



    // Closing File
    fclose(fp);
}

struct matrix multiply(struct matrix, struct matrix){

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
struct variable i = createScalar();
struct variable n = createScalar();
struct variable x = createVector(2);
struct variable y = createVector(2);
struct variable A = createMatrix(2,2);
struct variable B = createMatrix(2,2);
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