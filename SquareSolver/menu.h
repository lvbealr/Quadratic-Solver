#ifndef MENU_H_
#define MENU_H_

/**
 * @brief Activate Manual Mode To Input Coefficients Of Quadratic Equation
 * 
 * @return int 
 */
int manualMode();

/**
 * @brief Activate Test Mode To Check The Programm With Test Values
 * 
 */
void testMode();

/**
 * @brief Activate Google Test Mode To Check The Programm With Test Values
 * 
 */
void googleTestMode(int argc, char *argv[]);
#endif