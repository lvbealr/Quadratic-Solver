#include <cstdio>
#include <cctype>

void stdinClean() {
    int currentSymbol = 0;
    currentSymbol = getchar();
    while (currentSymbol != '\n' && currentSymbol != EOF) {
        currentSymbol = getchar();
    }
}
