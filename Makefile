build:
	gcc -o matlang2c parser.c
	./matlang2c mat_codes/ex1.mat
	# ./matlang2c mat_codes/ex2.mat
	./matlang2c mat_codes/ex3.mat
	./matlang2c mat_codes/ex4.mat
	./matlang2c mat_codes/ex5.mat
	./matlang2c mat_codes/handmade1.mat
	./matlang2c mat_codes/handmade2.mat
	./matlang2c mat_codes/inv2by2.mat
	./matlang2c mat_codes/convolution.mat
	./matlang2c mat_codes/operations.mat
	./matlang2c mat_codes/sieve.mat
	./matlang2c mat_codes/print_cycles.mat