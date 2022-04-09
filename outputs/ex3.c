input filename is mat_codes/ex3.mat
output filename is file.c
Variable A = createMatrix(3, 3);
Variable T = createMatrix(1, 1);
Variable x = createVector(3);
Variable y = createVector(3);
Variable r = createScalar();
Variable i = createScalar();
assignMultiple(&A, 0.5, 0, 0.5, 0, 0, 0.5, 0.5, 1, 0);
assignMultiple(&x, 1, 1, 1);
Var lrfkQyuQFjKXyQV = generateScalarFromNumber(1);
Var NRTySFrzrmzlYGF = generateScalarFromNumber(10);
Var vEulQfpDBHlqDqr = generateScalarFromNumber(1);
for(assign(i,lrfkQyuQFjKXyQV); isLower(i,NRTySFrzrmzlYGF); increase(i,vEulQfpDBHlqDqr)){
Variable rCRwDnXeuOQqekl = multiplication( x , A );
y = rCRwDnXeuOQqekl
YEYYY(9, 13)->( y - x ) 
YEYYY(9, 13)->( y - x ) 
YEYYY(9, 13)->( y - x ) 
YEYYY(9, 13)->( y - x ) 
YEYYY(9, 13)->( y - x ) 
Variable AITGDPHCSPIjtHb = substraction( y , x );
Variable sFyfvlADzPBfudk = transpose( AITGDPHCSPIjtHb );
Variable KlrwqAOzMiXrpif = substraction( y , x );
Variable EffECLhbVFUkBye = multiplication( KlrwqAOzMiXrpif , sFyfvlADzPBfudk );
T = EffECLhbVFUkBye
Var TxWJLkNgbqQmBxQ = generateScalarFromNumber(1);
Var CQptkhHqrQdwfcA = generateScalarFromNumber(1);
Variable qfQOJWTwosILEeZ = getDoubleIndex( T, TxWJLkNgbqQmBxQ, CQptkhHqrQdwfcA );
Variable YSSYoQcJomwUFBd = sqrt( qfQOJWTwosILEeZ );
r = YSSYoQcJomwUFBd
print(&r);
x = y
}
printsep();
print(&x);
