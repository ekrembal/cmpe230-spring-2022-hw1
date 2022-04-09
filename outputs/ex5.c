input filename is mat_codes/ex5.mat
output filename is file.c
Variable A = createMatrix(4, 4);
Variable count = createScalar();
Variable incr = createScalar();
Variable i = createScalar();
Variable j = createScalar();
assignMultiple(&A, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 1, 1, 2, 3, 4);
Var lrfkQyuQFjKXyQV = generateScalarFromNumber(0);
count = lrfkQyuQFjKXyQV
Var NRTySFrzrmzlYGF = generateScalarFromNumber(1);
Var vEulQfpDBHlqDqr = generateScalarFromNumber(4);
Var rCRwDnXeuOQqekl = generateScalarFromNumber(1);
Var AITGDPHCSPIjtHb = generateScalarFromNumber(1);
Var sFyfvlADzPBfudk = generateScalarFromNumber(4);
Var KlrwqAOzMiXrpif = generateScalarFromNumber(1);
for(assign(i,NRTySFrzrmzlYGF); isLower(i,vEulQfpDBHlqDqr); increase(i,rCRwDnXeuOQqekl)){
for(assign(j,AITGDPHCSPIjtHb); isLower(j,sFyfvlADzPBfudk); increase(in,KlrwqAOzMiXrpif)){
Variable EffECLhbVFUkBye = getDoubleIndex( A, i, j );
Var TxWJLkNgbqQmBxQ = generateScalarFromNumber(4);
Variable qfQOJWTwosILEeZ = substraction( EffECLhbVFUkBye , TxWJLkNgbqQmBxQ );
Var YSSYoQcJomwUFBd = generateScalarFromNumber(0);
Var fXudZHiftaKCZVH = generateScalarFromNumber(1);
Var sYBlOetsWCRFHPX = generateScalarFromNumber(1);
Variable CQptkhHqrQdwfcA = choose( YSSYoQcJomwUFBd, fXudZHiftaKCZVH, sYBlOetsWCRFHPX, qfQOJWTwosILEeZ );
incr = CQptkhHqrQdwfcA
Variable PRbsshSjXDFileB = addition( incr , count );
count = PRbsshSjXDFileB
}}
print(&count);
