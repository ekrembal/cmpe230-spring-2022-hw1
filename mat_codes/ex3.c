Variable *A = createMatrix(3, 3);
Variable *T = createMatrix(1, 1);
Variable *x = createVector(3);
Variable *y = createVector(3);
Variable *r = createScalar();
Variable *i = createScalar();
assignToFlatten(A, 0.5, 0);assignToFlatten(A, 0, 1);assignToFlatten(A, 0.5, 2);assignToFlatten(A, 0, 3);assignToFlatten(A, 0, 4);assignToFlatten(A, 0.5, 5);assignToFlatten(A, 0.5, 6);assignToFlatten(A, 1, 7);assignToFlatten(A, 0, 8);
assignToFlatten(x, 1, 0);assignToFlatten(x, 1, 1);assignToFlatten(x, 1, 2);
Variable *lrfkQyuQFjKXyQV = generateScalarFromNumber(1);
Variable *NRTySFrzrmzlYGF = generateScalarFromNumber(10);
Variable *vEulQfpDBHlqDqr = generateScalarFromNumber(1);
for(assign(i,lrfkQyuQFjKXyQV); isLower(i,NRTySFrzrmzlYGF); increase(i,vEulQfpDBHlqDqr)){
Variable *rCRwDnXeuOQqekl = multiply(A, x);
assign(y, rCRwDnXeuOQqekl);
Variable *AITGDPHCSPIjtHb = substraction(y, x);
Variable *sFyfvlADzPBfudk = transpose( AITGDPHCSPIjtHb );
Variable *KlrwqAOzMiXrpif = substraction(y, x);
Variable *EffECLhbVFUkBye = multiply(sFyfvlADzPBfudk, KlrwqAOzMiXrpif);
assign(T, EffECLhbVFUkBye);
Variable *TxWJLkNgbqQmBxQ = generateScalarFromNumber(1);
Variable *CQptkhHqrQdwfcA = generateScalarFromNumber(1);
Variable *qfQOJWTwosILEeZ = getDoubleIndex( T, TxWJLkNgbqQmBxQ, CQptkhHqrQdwfcA );
Variable *YSSYoQcJomwUFBd = sqrt( qfQOJWTwosILEeZ );
assign(r, YSSYoQcJomwUFBd);
print(r);
assign(x, y);
}
printsep();
print(x);
