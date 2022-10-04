#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "gcd.h"



void testGCD_C(void)
{
    CU_ASSERT(gcdC(42, 56) == 14);
    CU_ASSERT(gcdC(48, 18) == 6);
    CU_ASSERT(gcdC(270, 192) == 6);
    CU_ASSERT(gcdC(1237,24) == 1);
    CU_ASSERT(gcdC(4200000, 3780000) == 420000);
    CU_ASSERT(gcdC(0, 0) == 0);
}



int gcdC(int a, int b)
{
    if (b == 0) {return a;}
    else {return gcdC(b, a%b);}
}



int main()
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("gcdC_test", 0, 0);
    CU_add_test(suite, "gcdC_fun", testGCD_C);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
