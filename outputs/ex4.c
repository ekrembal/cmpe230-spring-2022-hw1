input filename is mat_codes/ex4.mat
output filename is file.c
Variable A = createMatrix(4, 4);
Variable T = createMatrix(1, 1);
Variable x = createVector(4);
Variable xy2 = createVector(4);
Variable s = createScalar();
assignMultiple(&A, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 1, 1, 2, 3, 4);
assignMultiple(&x, 1, 1, 1, 1);
assignMultiple(&xy2, 2, 1, 3, 1);
Variable lrfkQyuQFjKXyQV = transpose( x );
Variable NRTySFrzrmzlYGF = multiplication( xy2 , A );
Variable vEulQfpDBHlqDqr = multiplication( NRTySFrzrmzlYGF , lrfkQyuQFjKXyQV );
T = vEulQfpDBHlqDqr
Var AITGDPHCSPIjtHb = generateScalarFromNumber(1);
Var sFyfvlADzPBfudk = generateScalarFromNumber(1);
Variable rCRwDnXeuOQqekl = getDoubleIndex( T, AITGDPHCSPIjtHb, sFyfvlADzPBfudk );
s = rCRwDnXeuOQqekl
print(&s);
temp1 = multiply
temp2 = transpose
temp3 = multiply
