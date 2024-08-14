#include <stdio.h>
#include <math.h>

void PrintRoots(int code, double roots[2])
{
    switch (code)
    {
        case 0: printf("Infinitely many solutions"); break;
        case 1: printf("No solutions"); break;
        case 2: printf("It is linear (non-quadratic) equation\n[0] Solution: x = %lf", roots[0]); break;
        case 3: printf("D < 0: no real solutions"); break;
        case 4: printf("D = 0\n[0] Solution: x = %lf", roots[0]); break;
        case 5: printf("D > 0\n[0] Solution: x = %lf\n[1] Solution: x = %lf", roots[0], roots[1]); break;
    }
}
int SquareSolver(double const a, double const b, double const c, double roots[2])
{
    const double eps = 1e-07;
    if (fabs(a) <= eps)
    {
        if (fabs(b) <= eps)
        {
            if (fabs(c) <= eps)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            roots[0] = -c/b;
            return 2;
        }
    }
    else
    {
        double const discriminant = b*b - 4*a*c;
        if (discriminant < -eps)
        {
            return 3;
        }
        else if (fabs(discriminant) <= eps)
        {
            roots[0] = -b/2/a;
            return 4;
        }
        else
        {
            roots[0] = (-b + sqrt(discriminant))/2/a; roots[1] = (-b -sqrt(discriminant))/2/a;
            return 5;
        }
    }
}

int main(void)
{
    double a = NAN; double b = NAN; double c = NAN;
    double roots[2] = {NAN, NAN};
    printf("Input values of a, b, c coefficients:");
    scanf("%lf %lf %lf", &a, &b, &c);
    int code = SquareSolver(a, b, c, roots);
    PrintRoots(code, roots);
    return 0;
}
