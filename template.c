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
i = createScalar();
n = createScalar();
x = createVector(2);
y = createVector(2);
A = createMatrix(2,2);
B = createMatrix(2,2);
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