#include <stdio.h>
#include <math.h>

void PrintRoots(int code, double array[2])
{
    switch (code)
    {
        case 0: printf("Infinitely many solutions"); break;
        case 1: printf("No solutions"); break;
        case 2: printf("It is linear (non-quadratic) equation\nSolution: x = %lf", array[0]); break;
        case 3: printf("D < 0: no real solutions"); break;
        case 4: printf("D = 0\nSolution: x = %lf", array[0]); break;
        case 5: printf("D > 0\nSolutions: x = %lf\t x = %lf", array[0], array[1]); break;
    }
}

void SquareSolver(double const a, double const b, double const c, double array[2])
{
    const double eps = 1e-06;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                PrintRoots(0, array);
            }
            else
            {
                PrintRoots(1, array);
            }
        }
        else
        {
            array[0] = -c/b;
            PrintRoots(2, array);
        }
    }
    else
    {
        double const discriminant = b*b - 4*a*c;
        if (discriminant < eps)
        {
            PrintRoots(3, array);
        }
        else if (fabs(discriminant) <= eps)
        {
            array[0] = -b/2/a;
            PrintRoots(4, array);
        }
        else
        {
            array[0] = (-b + sqrt(discriminant))/2/a; array[1] = (-b -sqrt(discriminant))/2/a;
            PrintRoots(5, array);
        }
    }
}

int main(void)
{
    double a, b, c;
    double array[2];
    printf("Input values of a, b, c coefficients:");
    scanf("%lf %lf %lf", &a, &b, &c);
    SquareSolver(a, b, c, array);
    return 0;
}
