build:
	gcc -o matlang2c parser.c
	./matlang2c mat_codes/ex1.mat > outputs/ex1.c
	./matlang2c mat_codes/ex2.mat > outputs/ex2.c
	./matlang2c mat_codes/ex3.mat > outputs/ex3.c
	./matlang2c mat_codes/ex4.mat > outputs/ex4.c
	./matlang2c mat_codes/ex5.mat > outputs/ex5.c
	./matlang2c mat_codes/handmade1.mat > outputs/handmade1.c
	./matlang2c mat_codes/handmade2.mat > outputs/handmade2.c
	# ./matlang2c mat_codes/ex2.mat