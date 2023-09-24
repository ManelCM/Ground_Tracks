#include <stdio.h>
#include <math.h>
#include "bisnwt.h"
#include <assert.h>
#define TOL 1e-12
#define MAXIT 10
struct kepler_prm {
   double e, M;};
   
double kepler (double E, void *prm) {
   struct kepler_prm *pkprm=prm;
   return E-(pkprm->e)*sin(E)-(pkprm->M);
}

double derivada_kepler (double E, void*prm){
	struct kepler_prm *pkprm=prm;
	return (1-(pkprm->e)*cos(E));
}

int main (int argc, char *argv[]) {
struct kepler_prm kprm;
double PI = 3.14159265358979323846;
double e,T,M0,tf;
int nt;
   if (argc<6
         || sscanf(argv[1], "%lf", &e)!=1
         || sscanf(argv[2], "%lf", &T)!=1
         || sscanf(argv[3], "%lf", &M0)!=1
         || sscanf(argv[4], "%lf", &tf)!=1
         || sscanf(argv[5], "%d", &nt)!=1
      ) {
      fprintf(stderr,"%s e T M0 tf nt\n", argv[0]);
      return -1;
   } 
kprm.e=e;
for(int i=0;i<=nt;i++){
	double ti=i*(tf/nt);
	printf("%f ",ti);
	double M =(2*PI*ti)/T+M0;
	printf(" %.16g ",M);
	kprm.M=M;
	double a=M-PI;
	double b=M+PI;
	double delta=0.01;
	double E; 
	bisnwt(a,b,&E,&delta,TOL,MAXIT,&kepler,&derivada_kepler,&kprm); //guardem el valor de l'arrel de bisnwt 	
	double n_v=E/(2*PI);//per mirar la volta on estem
	double part_entera = floor(n_v);//abans era modf per seprar
	double part_decimal=n_v-part_entera;
	double v=acos((e-cos(E))/(e*cos(E)-1));//dona un valor entre 0 i pi.
	if(part_decimal<0.5){//ens trobem a la 1a mitja volta	
		v=v+(2*part_entera)*PI;}
	else{v=-v+(part_entera*2+2)*PI;}
	printf(" %.16g \n",v);
	}
   return 0;
}
