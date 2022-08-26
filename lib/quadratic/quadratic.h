#ifndef QUADRATIC_H
#define QUADRATIC_H

/**
 * @file quadratic.h
 * @author MeerkatBoss
 * @brief Contains definitions for equation solvers
 * @version 0.1
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Enum representing number of roots
 * of an equation
 */
enum root_count
{
    NO_ROOTS    =  0, /*!< Equation has no roots */
    SINGLE_ROOT =  1, /*!< Equation has only one root */
    TWO_ROOTS   =  2, /*!< Equation has two distinct roots */
    INF_ROOTS   = -1  /*!< Any real number is a solution */
};

/**
 * @brief Enum representing status of solving
 * equation
 */
enum solve_status
{
    SOLVE_SUCCESS =  0, /*!< Equation solved successfully */
    SOLVE_ERROR   = -1  /*!< Failed to solve equation */
};

/**
 * @brief Base struct for storing equation solving result
 * @note DO NOT change order of fields. Having roots[] at end
 * and nroots in the beginning is critical for using in generic case
 */
typedef struct
{
    enum root_count nroots;
    double roots[0];
} EquationResultBase;


/**
 * @brief Typename for static equation solving result
 * @param num - number of roots of equation
 */
#define EQUATION_RESULT(num) EquationResult##num

/**
 * @brief Struct for storing equation result with compile-time
 * known number of roots
 * @param num - number of roots
 */
#define DEFINE_EQUATION_RESULT(num)                                         \
    typedef struct                                                          \
    {                                                                       \
        union {                                                             \
            EquationResultBase base; /*!< base struct (used for upcast) */  \
            enum root_count nroots; /*!< number of roots */                 \
        };                                                                  \
        double roots[num]; /*!< roots array */                              \
    } EquationResult##num

/**
 * @brief Store linear equation roots
 */
DEFINE_EQUATION_RESULT(1);

/**
 * @brief Store quadratic equation roots
 */
DEFINE_EQUATION_RESULT(2);

/**
 * @brief Stack-allocate struct with dynamic root count
 * @param num - number of roots
 * @return Allocated struct
 */
#define local_generic_result(num)  \
    ((EquationResultBase*) alloca( \
        sizeof(EquationResultBase) + (num)*sizeof(double))))

/**
 * @brief Allocate struct with dynamic root count
 * 
 * @param[in] root_count - number of roots
 * @return Allocated struct
 */
EquationResultBase *generic_result(size_t root_count);

/**
 * @brief Solves equations ax^2 + bx + c = 0
 * 
 * @param[in] a - first coefficient of an equaion
 * @param[in] b - second coefficient of an equation
 * @param[in] c - third coefficient of an equation
 * @param[out] result - pointer to struct storing roots
 * @return STATUS_SUCCESS if equation was solved sucessfully,
 * STATUS_ERROR if equation could not be solved. See errno for
 * more info.
 * 
 * @note If there is only one solution to the equation, result->roots[0]
 * is not changed. If there are no roots or an infinite amount of roots,
 * both result->roots[0] and result->roots[1] are not changed.
 * If there are two roots, result->roots[0] < result->roots[1]
 */
int solve_quadratic(double a, double b, double c,
                    EQUATION_RESULT(2) *result);

/**
 * @brief Solves equations ax + b = 0
 * 
 * @param[in] a - first coefficient of an equation
 * @param[in] b - second coefficient of an equation
 * @param[in] result - pointer to struct storing roots
 * @return STATUS_SUCCESS if equation was solved sucessfully,
 * STATUS_ERROR if equation could not be solved. See errno for
 * more info.
 * 
 * @note If there are no roots or an infinite amount of roots,
 * result->roots is not changed
 */
int solve_linear(double a, double b, EQUATION_RESULT(1) *result);

#endif
