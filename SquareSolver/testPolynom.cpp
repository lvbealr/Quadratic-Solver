#include <cstdio>

#include "polynomStruct.h"

int main() {
    polynom quadraticPolynom;
    polynomInitialize(&quadraticPolynom, 2, 1, 3, 1);
    printf("%lg %lg %lg\n", quadraticPolynom.a, quadraticPolynom.b, quadraticPolynom.c);
    printf("%d", quadraticPolynom.maxRootCount);
}