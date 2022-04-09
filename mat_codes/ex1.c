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
print(i);
Variable *rCRwDnXeuOQqekl = multiplication(A, B);
assign(B, rCRwDnXeuOQqekl);
Variable *AITGDPHCSPIjtHb = multiplication(B, x);
assign(y, AITGDPHCSPIjtHb);
print(getSingleIndexInt(y, 1));
}
