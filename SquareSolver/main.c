#include <stdio.h>
#include <math.h>

void SquareSolver(double const a, double const b, double const c)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                printf("0 = 0: infinitely many solutions");
            }
            else
            {
                printf("%lf != 0: no solutions", c);
            }
        }
        else
        {
            if (c == 0)
            {
                printf("It is linear (non-quadratic) equation\nSolution: x = 0");
            }
            else
            {
                printf("It is linear (non-quadratic) equation\nSolution: x = %lf", -c/b);
            }
        }
    }
    else
    {
        double const D = b*b - 4*a*c;
        if (D < 0)
        {
            printf("D < 0: no real solutions");
        }
        else if (D == 0)
        {
            printf("D = 0\nSolution: x = %lf", -b/2/a);
        }
        else
        {
            double x1 = (-b + sqrt(D))/2/a;
            double x2 = (-b -sqrt(D))/2/a;
            printf("D > 0\nSolutions: x1 = %lf\tx2 = %lf", x1, x2);
        }
    }
}

int main(void)
{
    double a, b, c;
    printf("Input values of a, b, c coefficients:");
    scanf("%lf %lf %lf", &a, &b, &c);
    SquareSolver(a, b, c);
    return 0;
}
