//2x2 linear equation solver based on Cramer's Rule
#include<stdio.h>
double cramer(double [][3],double*, double*);

int main()
{
  double coefficient[2][3];
  int i,j;
  double x, y;

  printf("Type in the order(i.e. ax+by=c)\n" );
//Input the coefficient
  for (i = 0; i<=2-1; i++)
  {
    printf(" equation %d coefficient:", i+1 );
    for (j = 0; j<=3-1; j++)
      scanf("%lf",&coefficient[i][j] );
    printf("\n" );
  }

  cramer(coefficient, &x, &y);

  printf("=====The result===\n" );
  printf("x = %.6f\n",x );
  printf("y = %.6f\n",y );
}

double cramer(double coe[][3], double* x, double* y)
{
  double D, Dx, Dy; //determinant

  D = coe[0][0]*coe[1][1]-coe[1][0]*coe[0][1];
  Dx = coe[0][2]*coe[1][1]-coe[1][2]*coe[0][1];
  Dy = coe[0][0]*coe[1][2]-coe[1][0]*coe[0][2];
  if (D == 0)
    {printf("No solution. Result shown below is valid.\n" );}
  else
  {
    *x = Dx/D;
    *y = Dy/D;
  }

  return 0;
}
