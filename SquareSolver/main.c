#include <stdio.h>
#include <math.h>

void PrintRoots(double roots[3])
{
    switch ((int) roots[0])
    {
        case 0: printf("Infinitely many solutions"); break;
        case 1: printf("No solutions"); break;
        case 2: printf("It is linear (non-quadratic) equation\n[1] Solution: x = %lf", roots[1]); break;
        case 3: printf("D < 0: no real solutions"); break;
        case 4: printf("D = 0\n[1] Solution: x = %lf", roots[1]); break;
        case 5: printf("D > 0\n[1] Solution: x = %lf\n[2] Solution: x = %lf", roots[1], roots[2]); break;
    }
}
void SquareSolver(double const a, double const b, double const c, double roots[3])
{
    const double eps = 1e-07;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                roots[0] = 0;
            }
            else
            {
                roots[0] = 1;
            }
        }
        else
        {
            roots[0] = 2;
            roots[1] = -c/b;
        }
    }
    else
    {
        double const discriminant = b*b - 4*a*c;
        if (discriminant < -eps)
        {
            roots[0] = 3;
        }
        else if (fabs(discriminant) <= eps)
        {
            roots[0] = 4;
            roots[1] = -b/2/a;
        }
        else
        {
            roots[0] = 5;
            roots[1] = (-b + sqrt(discriminant))/2/a; roots[2] = (-b -sqrt(discriminant))/2/a;
        }
    }
}

int main(void)
{
    double a, b, c;
    double roots[3] = {NAN, NAN, NAN}; // roots[0] - code of print; roots[1], roots[2] - solutions (if they exist)
    printf("Input values of a, b, c coefficients:");
    scanf("%lf %lf %lf", &a, &b, &c);
    SquareSolver(a, b, c, roots);
    PrintRoots(roots);
    return 0;
}
