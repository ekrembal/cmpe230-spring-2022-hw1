Variable *A = createMatrix(1, 5);
assignToFlatten(A, 1, 0);assignToFlatten(A, 2, 1);assignToFlatten(A, 3, 2);assignToFlatten(A, 4, 3);assignToFlatten(A, 5, 4);
Variable *i = createVector(3);
assignToFlatten(i, 1, 0);assignToFlatten(i, 0, 1);assignToFlatten(i, 1, 2);
Variable *NRTySFrzrmzlYGF = generateScalarFromNumber(2);
Variable *lrfkQyuQFjKXyQV = getSingleIndex( i , NRTySFrzrmzlYGF );
Variable *rCRwDnXeuOQqekl = generateScalarFromNumber(3);
Variable *vEulQfpDBHlqDqr = getSingleIndex( i , rCRwDnXeuOQqekl );
Variable *AITGDPHCSPIjtHb = substraction( lrfkQyuQFjKXyQV , vEulQfpDBHlqDqr );
assignToSingleIndex(i, ], AITGDPHCSPIjtHb);
Variable *PRINTMATRIX = createMatrix(2, 2);
Variable *KlrwqAOzMiXrpif = generateScalarFromNumber(2);
Variable *sFyfvlADzPBfudk = getSingleIndex( i , KlrwqAOzMiXrpif );
Variable *qfQOJWTwosILEeZ = generateScalarFromNumber(3);
Variable *TxWJLkNgbqQmBxQ = generateScalarFromNumber(2);
Variable *CQptkhHqrQdwfcA = generateScalarFromNumber(1);
Variable *EffECLhbVFUkBye = choose( qfQOJWTwosILEeZ, TxWJLkNgbqQmBxQ, CQptkhHqrQdwfcA, sFyfvlADzPBfudk );
Variable *fXudZHiftaKCZVH = generateScalarFromNumber(1);
Variable *YSSYoQcJomwUFBd = getDoubleIndex( A, fXudZHiftaKCZVH, EffECLhbVFUkBye );
assignToDoubleIndex(PRINTMATRIX, ,, ], YSSYoQcJomwUFBd);
print(PRINTMATRIX);
print(getDoubleIndex(PRINTMATRIX, 1, 1));
print(getDoubleIndex(PRINTMATRIX, 2, 2));
