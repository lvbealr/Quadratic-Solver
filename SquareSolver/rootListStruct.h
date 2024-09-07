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
 * 
 * @return int Success/Failure Return Code [0/1] 
 */
int rootListInitialize(rootList *roots);
int rootListDestruct(rootList *roots);

/**
 * @brief Get the Root Count Of Quadratic Equation
 * 
 * @param [in] roots 
 * @return int Success/Failure Return Code [0/1] 
 */
int getRootCount(const rootList *roots);

/**
 * @brief Push Root To RootList
 * 
 * @param [out] roots 
 * @param [in] root 
 * @return int Success/Failure Return Code [0/1] 
 */
int pushRoot(rootList *roots, double root);

/**
 * @brief Print List Of Roots
 * 
 * @param [in] roots 
 * @return int Success/Failure Return Code [0/1] 
 */
int printRoot(const rootList *roots);

/**
 * @brief Set the Type (Status) Of Quadratic Equation
 * 
 * @param [out] roots 
 * @param [in] statusCode 
 * @return int Success/Failure Return Code [0/1] 
 */
int setStatus(rootList *roots, solveCode statusCode);

/**
 * @brief Print Result Of Equation Solve
 * 
 * @param [in] roots 
 * @return int Success/Failure Return Code [0/1] 
 */
int printResult(rootList *roots);
/*/ FUNCTION PROTOTYPES /*/
#endif 