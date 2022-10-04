#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "fact.h"

void factorialTest(void)
{
    CU_ASSERT(factorial(0) == 1);
    CU_ASSERT(factorial(1) == 1);
    CU_ASSERT(factorial(4) == 24);
    CU_ASSERT(factorial(6) == 720);
}

long factorial(int size)
{
    long fact;
    fact = 1;
    for (int i=1; i<=size; i++) {fact *= i;}
    return fact;
}

int main()
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("fact_test", 0, 0);
    CU_add_test(suite, "fact_fun", factorialTest);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
