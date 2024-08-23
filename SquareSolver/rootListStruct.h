#ifndef ROOT_LIST_STRUCT_H_
#define ROOT_LIST_STRUCT_H_

/// @brief Max Roots Number Of Quadratic Equation
const int MAX_ROOT_COUNT = 2;

/// @brief Invalid Value of Roots Number
const int INVALID_COUNT = -1;

/// @brief Set Of Possible Equation Types
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
/**
 * @brief Struct That Contains True Number Of Quadratic Equation Roots, Roots List and Equation Type
 * 
 */
struct rootList {
    int count                    = 0;
    double roots[MAX_ROOT_COUNT] = {};
    solveCode status             = INVALID;
};
/*/ ROOTLIST STRUCT /*/

/*/ FUNCTION PROTOTYPES /*/
/**
 * @brief Initialize and Destruct RootList Struct 
 * 
 * @param [out] roots 
 */
void rootListInitialize(rootList *roots);
void rootListDestruct(rootList *roots);

/**
 * @brief Get the Root Count Of Quadratic Equation
 * 
 * @param [in] roots 
 * @return int 
 */
int getRootCount(const rootList *roots);

/**
 * @brief Push Root To RootList
 * 
 * @param [out] roots 
 * @param [in] root 
 * @return true 
 * @return false 
 */
bool pushRoot(rootList *roots, double root);

/**
 * @brief Print List Of Roots
 * 
 * @param [in] roots 
 */
void printRoot(const rootList *roots);

/**
 * @brief Set the Type (Status) Of Quadratic Equation
 * 
 * @param [out] roots 
 * @param [in] statusCode 
 */
void setStatus(rootList *roots, solveCode statusCode);

/**
 * @brief Print Result Of Equation Solve
 * 
 * @param [in] roots 
 */
void printResult(rootList *roots);
/*/ FUNCTION PROTOTYPES /*/
#endif 