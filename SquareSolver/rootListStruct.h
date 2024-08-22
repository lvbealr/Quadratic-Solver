#ifndef ROOT_LIST_STRUCT_H_
#define ROOT_LIST_STRUCT_H_

const int MAX_ROOT_COUNT = 2;
const int INVALID_COUNT = -1;

enum solveCode {
    LINEAR_INF_ROOTS    = 0, // a, b, c = 0
    LINEAR_NO_ROOTS     = 1, // a, b = 0; c != 0
    LINEAR_ONE_ROOT     = 2, // a = 0; b != 0
    QUADRATIC_NO_ROOTS  = 3, // D < 0
    QUADRATIC_ONE_ROOT  = 4, // D = 0
    QUADRATIC_TWO_ROOTS = 5, // D > 0
    INVALID             = 6
};

/*/ ROOTLIST STRUCT /*/
struct rootList {
    int count                    = 0;
    double roots[MAX_ROOT_COUNT] = {};
    solveCode status             = INVALID;
};
/*/ ROOTLIST STRUCT /*/

/*/ FUNCTION PROTOTYPES /*/
void rootListInitialize(rootList *roots);
void rootListDestruct(rootList *roots);
int getRootCount(const rootList *roots);
bool pushRoot(rootList *roots, double root);
void printRoot(const rootList *roots);
void setStatus(rootList *roots, solveCode statusCode);
void printResult(rootList *roots);
/*/ FUNCTION PROTOTYPES /*/
#endif 