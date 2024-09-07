#ifndef CUSTOM_ASSERT_H_
#define CUSTOM_ASSERT_H_   

// TODO align \ symbols
#define customAssert(expression, returnMessage) do { \
    if (!(expression)) { \
        printf("Assertion Error: %s, file (%s), function (%s), line %d\n", \
                #expression, __FILE__, __FUNCTION__, __LINE__); \
        return returnMessage; \
    } \
} while (0)

// why do while 

#endif