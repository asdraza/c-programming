#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "gcd.h"

void testGCD_A(void)
{
    CU_ASSERT(gcdA(42,56) == 14);
    CU_ASSERT(gcdA(48,18) == 6);
    CU_ASSERT(gcdA(270,192) == 6);
    CU_ASSERT(gcdA(1237,24) == 1);
    CU_ASSERT(gcdA(4200000,3780000) == 420000);
    CU_ASSERT(gcdA(0,0) == 0);
}

int gcdA(int a, int b)
{
    int temp;
    while(b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("gcdA_test", 0, 0);
    CU_add_test(suite, "gcdA_fun", testGCD_A);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
