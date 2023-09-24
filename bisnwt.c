#include <math.h>
#include <stdio.h>
int bisnwt (double a, double b, double *arr, double *dlt,double tol, 
             int maxit,double (*f)(double,void*), double (*df)(double,void*), 
             void *prm){
	int convergeix=0;
	double c=(a+b)*0.5;
while (convergeix==0){
	//printf("BISECCI�: \n ");
   //printf("-----------------------------\n");
  while(fabs(b-a)>*dlt){
  	c=(a+b)*0.5;
    //	printf("a %f ",a);
    //	printf("b %f ",b);
    //	printf("c: %lf \n",c);
	if ((*f)(c,prm)*(*f)(b,prm)<=0){a=c;}
	else{b=c;}
	}
	if(*dlt<=tol){*arr=c;return -1;}  
//printf("\n");printf("NEWTON \n");
//printf("-----------------------------\n");
  double dif=2003; 
  int i=0;
  while(dif>=tol && i<maxit){//en newton la x1 �s posterior a c (c =x0)
  	 double f_c=(*f)(c,prm);
         double fc_der=(*df)(c,prm);
 	  if ((*f)(c,prm)==0){*arr=c; 
 	      //printf("ITERACI�: %d\n",i+1);
 	     //printf("VALOR DE C: %.16g\n",c);printf("\n");
 	      return(i+1);}
    double x1=c-(f_c/fc_der);
    dif=fabs(x1-c); 
    c=x1;
    i++;
         //printf("ITERACI�: %d\n",i);printf("VALOR DE C: %.16g\n",c);printf("\n");
  } 
  if(dif<tol){*arr=c;convergeix=1; return i;}
  else{*dlt=*dlt/2;}
}
  return 0;} 

 	
 	 
 		
 	
 	 
