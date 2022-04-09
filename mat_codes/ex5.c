Variable *A = createMatrix(4, 4);
Variable *count = createScalar();
Variable *incr = createScalar();
Variable *i = createScalar();
Variable *j = createScalar();
assignToFlatten(A, 0, 0);assignToFlatten(A, 1, 1);assignToFlatten(A, 2, 2);assignToFlatten(A, 3, 3);assignToFlatten(A, 4, 4);assignToFlatten(A, 5, 5);assignToFlatten(A, 6, 6);assignToFlatten(A, 7, 7);assignToFlatten(A, 8, 8);assignToFlatten(A, 9, 9);assignToFlatten(A, 1, 10);assignToFlatten(A, 1, 11);assignToFlatten(A, 1, 12);assignToFlatten(A, 2, 13);assignToFlatten(A, 3, 14);assignToFlatten(A, 4, 15);
Variable *lrfkQyuQFjKXyQV = generateScalarFromNumber(0);
assign(count, lrfkQyuQFjKXyQV);
Variable *NRTySFrzrmzlYGF = generateScalarFromNumber(1);
Variable *vEulQfpDBHlqDqr = generateScalarFromNumber(4);
Variable *rCRwDnXeuOQqekl = generateScalarFromNumber(1);
Variable *AITGDPHCSPIjtHb = generateScalarFromNumber(1);
Variable *sFyfvlADzPBfudk = generateScalarFromNumber(4);
Variable *KlrwqAOzMiXrpif = generateScalarFromNumber(1);
for(assign(i,NRTySFrzrmzlYGF); isLower(i,vEulQfpDBHlqDqr); increase(i,rCRwDnXeuOQqekl)){
for(assign(j,AITGDPHCSPIjtHb); isLower(j,sFyfvlADzPBfudk); increase(in,KlrwqAOzMiXrpif)){
Variable *EffECLhbVFUkBye = getDoubleIndex( A, i, j );
Variable *TxWJLkNgbqQmBxQ = generateScalarFromNumber(4);
Variable *qfQOJWTwosILEeZ = substraction(EffECLhbVFUkBye, TxWJLkNgbqQmBxQ);
Variable *YSSYoQcJomwUFBd = generateScalarFromNumber(0);
Variable *fXudZHiftaKCZVH = generateScalarFromNumber(1);
Variable *sYBlOetsWCRFHPX = generateScalarFromNumber(1);
Variable *CQptkhHqrQdwfcA = choose( YSSYoQcJomwUFBd, fXudZHiftaKCZVH, sYBlOetsWCRFHPX, qfQOJWTwosILEeZ );
assign(incr, CQptkhHqrQdwfcA);
Variable *PRbsshSjXDFileB = addition(incr, count);
assign(count, PRbsshSjXDFileB);
}}
print(count);
