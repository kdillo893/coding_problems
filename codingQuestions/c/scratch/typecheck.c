#include<stdio.h>


int main(int argc, char* argv[], char* envp[]) {
  //the below errors 
  // char c 		= 0x41424344;
  char c = '1';
  //the below errors 
	//int i 		= 1.5;
  int i = 1;
	unsigned int u 	= -1;
	float f 	= 10;
	double d 	= 2.5F;

	printf("c = %c, i = %d, u = %u, f = %f, d = %f\n", c,i,u,f,d);

	int r1 = f/d;
	int r2 = f/(int)d;

	printf("r1 = %d, r2 = %d\n", r1,r2);
}
