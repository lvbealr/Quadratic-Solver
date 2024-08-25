#ifndef CUSTOM_ASSERT_H_
#define CUSTOM_ASSERT_H_

enum assertionCode {
    POINTER_IS_NULL = 0,
};

const char* assertCodeString[] = {"POINTER_IS_NULL", "VALUE_IS_NAN"};

bool customAssert(bool expression, assertionCode code, int line, const char *file, const char *function);

#endif