build:
	gcc -o matlang2c parser.c
	./matlang2c mat_codes/handmade1.mat
	# ./matlang2c mat_codes/ex2.mat