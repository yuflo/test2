#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
int str2int(char *s);
void printbit(unsigned x);

int main(int argc, char *argv[]){
	
	int x = str2int(argv[1]),
		p = str2int(argv[2]),
		n = str2int(argv[3]),
		y = str2int(argv[4]);

	//printbit(getbits(x, p, n));
	//setbits(x, p, n, y);
	//invert(x, p, n);
	rightrot(x, n);
	printf("git test..");
}

int str2int(char *s){
	int n=0, i=0;
	while(*s != '\0'){
		n = n*10 + *(s++) - '0';
	}
	return n;
}

void printbit(unsigned x){
	int l = 8 * sizeof(unsigned);
	//printf("%d\n", l);
	char buf[64];

	for(int i=0; i<l; i++){
		unsigned m = ~0<<(i);
		buf[l-i-1] = ((unsigned)(x & m & ~(m<<1)) == (unsigned)pow(2,i)) + '0';
	}
	buf[l] = '\0';
	printf("%s\n", buf);
}

unsigned getbits(unsigned x, int p, int n){
	return (x>>(p+1-n) & ~(~0<<n));
}

unsigned setbits(unsigned x, int p, int n, unsigned y){

	/*printbit(~(~0<<(p+1) | ~(~0<<(p+1-n))));
	printbit(x);
	printbit(y);
	printf("\n");*/
	x |= ~(~0<<(p+1) | ~(~0<<(p+1-n))); 
	printbit(x);
	x &=((~0<<n | y)<<(p+1-n) | ~(~0<<(p+1-n)));
	return x;
}

unsigned invert(unsigned x, int p, int n){

	unsigned m = ~0<<(p+1) | ~(~0<<(p+1-n)); 
	return (~(x | m) | (x & m));

}
unsigned rightrot(unsigned x, int n){
	return ((~(~0<<n) & x)<<(8*sizeof(unsigned)-n) | x>>n);
}

