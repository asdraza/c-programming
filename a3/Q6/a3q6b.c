#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "gcd.h"


void testGCD_B(void)

{
    CU_ASSERT(gcdB(42, 56) == 14);
    CU_ASSERT(gcdB(48, 18) == 6);
    CU_ASSERT(gcdB(270, 192) == 6);
    CU_ASSERT(gcdB(1237, 24) == 1);
    CU_ASSERT(gcdB(4200000, 3780000) == 420000);
    CU_ASSERT(gcdB(0, 0) == 0);
}



int gcdB(int a, int b)
{
    while (a!=b)
    {
        if (a>b) {a=a-b;}
        else {b=b-a;}
    }
    return a;
}



int main()
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("gcdB_test", 0, 0);
    CU_add_test(suite, "gcdB_fun", testGCD_B);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
