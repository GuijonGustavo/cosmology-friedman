/*
 # Made by:
 # Gustavo Magallanes-Guijón <gustavo.magallanes.guijon@ciencias.unam.mx>
 # Instituto de Astronomia UNAM
 # Ciudad Universitaria
 # Ciudad de Mexico
 # Mexico
 # mar dic 22 22:43:09 CST 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Constants*/
double H = 0.07154245 ;//H en Gyrs
double Or = 8.2e-5;
double Om = 0.25;
double Ol = 0.75;
double Ok = 1 - (0.25 + 8.4e-5 +0.75);

FILE *fp, *fp1, *fp2, *fp3, *fp4, *fp5, *fp6;

/*BEGIN Prototypes*/

double friedman_m(double a);

double friedman_r(double a);

double friedman_l(double a);

double friedman_k(double a);

double friedman_m_l(double a);

double friedman_m_k(double a);

double friedman(double a);

double euler(double f(double x), double x0, double y0, double x, double h);

void loop();

void openfiles();
/*END Prototypes*/

/*BEGIN Functions*/

/*Function main*/

int main()
{  

openfiles();
loop();
}

/*friedman matter*/
double friedman_m(double a){
    return H*(sqrt(Om/a*a*a));
}

/*friedman radiation*/
double friedman_r(double a){
  return H*(sqrt(Or/(a*a*a*a)));
}

/*friedman lambda*/
double friedman_l(double a){
  return H*(sqrt(Ol));
}

/*friedman K*/
double friedman_k(double a){
  return H*(sqrt(Ok)/(a*a));
}

/*friedman matter + lambda*/
double friedman_m_l(double a){
  return H*(sqrt( Ol*(a*a) + Om/(a*a*a)));
}

/*friedman all*/
double friedman_all(double a){
  return H*(sqrt(Or/(a*a*a*a) + Om/(a*a*a) + Ol*(a*a)));
}

/*friedman matter + lambda*/
double friedman_m_k(double a){
  return H*(sqrt(Om/a))+ Ok;
}

/*Euler method*/
double euler(double f(double x), double x0, double y0, double x, double h){
      double y;
      while(fabs(x-x0)>0.0000000001){
          y=y0+h*f(x0);
          y0=y;
          x0=x0+h;
      }
      return y;
  }

void openfiles(){
  // Make the files to write the solutions
  fp = fopen("friedman_m.dat","w");
  fp1 = fopen("friedman_r.dat","w");
  fp2 = fopen("friedman_l.dat", "w");
  fp3 = fopen("friedman_k.dat","w");
  fp4 = fopen("friedman_m_l.dat","w");
  fp5 = fopen("friedman_all.dat","w");
  fp6 = fopen("friedman_m_k.dat","w");
}

void loop(){

  double sol, a;
  /* The initial condition is:
      a(13) = 1
  */
  double a0 = 1 , t0 = 13;

  for(a= 1; a <= 33; a = a + 0.01){
    sol = euler(friedman_m, a0, t0, a, 0.005);
    fprintf(fp,"%lf\t%lf\n",a,sol);

    sol = euler(friedman_r, a0, t0, a, 0.005);
    fprintf(fp1,"%lf\t%lf\n",a,sol);

    sol = euler(friedman_l, a0, t0, a, 0.005);
    fprintf(fp2,"%lf\t%lf\n",a,sol);

    sol = euler(friedman_k, a0, t0, a, 0.005);
    fprintf(fp3,"%lf\t%lf\n",a,sol);

    sol = euler(friedman_m_l, a0, t0, a, 0.005);
    fprintf(fp4,"%lf\t%lf\n",a,sol);

    sol = euler(friedman_m_k, a0, t0, a, 0.005);
    fprintf(fp6,"%lf\t%lf\n",a,sol);

    sol = euler(friedman_all, a0, t0, a, 0.005);
    fprintf(fp5,"%lf\t%lf\n",a,sol);
    }
}
/*END Functions*/
