#include <stdio.h>
#include "nwtfr.h"

#define SQRT3D2 0.866025403784439

#define N 3

int main(void) {
	
	double u[N] = {1, -.5, -.5}, v[N] = {0,SQRT3D2,-SQRT3D2}, zr = 0.85826, 
	zi = -1.07692, tolcnv = 1e-3; 
	int maxit = 15, j ; 
	j = cnvnwt (zr, zi, tolcnv, maxit, N,  u, v); 
	printf("j:  %d  \n", j ); 
	return 0; 
	
	}
/*
int main(void) {
	
	double u[N] = {1, -.5, -.5}, v[N] = {0,SQRT3D2,-SQRT3D2}, x = 0.1, 
	y = 0.3, px, py; 
	avalp(x, y, &px,&py, N , u, v);	
	printf("zr %.16g zi %.16g \n", px,py); 
	return 0;  
	
	} 
	*/
