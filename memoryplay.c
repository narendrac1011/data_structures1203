#include <stdio.h>
#include <stdlib.h>

//Blah Function takes an integer, and gives u the square of that integer
int * blah(int val) {
	int x;
	int * pointer = &x;
	x = val*val;
	return pointer;
}

//Main Function
int main(int argc, char **argv) {
	int * b = blah(5);
	printf("%d.\n", *b);
	return 0;
}