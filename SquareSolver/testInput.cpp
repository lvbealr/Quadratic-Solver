#include <cstdlib>
#include <cstdio>
#include <cctype>

bool inputCheck(char coefficient_str[100]) {
    bool positiveGreatOneNum = isdigit(coefficient_str[0]);
    bool positiveLessOneNum  = coefficient_str[0] == '.' && isdigit(coefficient_str[1]);
    bool negativeGreatOneNum = coefficient_str[0] == '-' && isdigit(coefficient_str[1]);
    bool negativeLessOneNum  = coefficient_str[0] == '-' && coefficient_str[1] == '.' && isdigit(coefficient_str[2]);
    return !(positiveGreatOneNum || positiveLessOneNum || negativeGreatOneNum || negativeLessOneNum);
}

bool coefficientInput(char coefficientName, double *coefficient) {
    const size_t INPUT_STRING_SIZE = 100;
    char coefficient_str[INPUT_STRING_SIZE] = "";
    const int TRY_COUNT = 3;

    for (int tryNum = 0; tryNum < TRY_COUNT; tryNum++) {
        printf("Input valid value of coefficient %c:", coefficientName);
        scanf("%100s", coefficient_str);

        if (inputCheck(coefficient_str)) {
            while (getchar() != '\n') {}
            continue;
        }
        else {
            *coefficient = atof(coefficient_str);
            while (getchar() != '\n') {}
            return true;
        }
    }
    return false;
}