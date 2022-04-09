input filename is mat_codes/ex1.mat
output filename is file.c
Variable i = createScalar();
Variable n = createScalar();
Variable x = createVector(2);
Variable y = createVector(2);
Variable A = createMatrix(2, 2);
Variable B = createMatrix(2, 2);
Var lrfkQyuQFjKXyQV = generateScalarFromNumber(10);
n = lrfkQyuQFjKXyQV
assignMultiple(&x, 1, 1);
assignMultiple(&A, 1, 1, 1, 0);
assignMultiple(&B, 1, 0, 0, 1);
print(&x);
Var NRTySFrzrmzlYGF = generateScalarFromNumber(1);
Var vEulQfpDBHlqDqr = generateScalarFromNumber(1);
for(assign(i,NRTySFrzrmzlYGF); isLower(i,n); increase(i,vEulQfpDBHlqDqr)){
Variable rCRwDnXeuOQqekl = multiplication( B , A );
B = rCRwDnXeuOQqekl
Variable AITGDPHCSPIjtHb = multiplication( x , B );
y = AITGDPHCSPIjtHb
print(&y[1]);
}
