#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "avg_and_max.h"

double arrayOne[10] = {-1.3, -1.45, -220, -100, -0.1, -0.1234, -200};
double arrayTwo[10] = {-1.3, 1.45, 220, 100, 0, 200, 0.1234};

void testMax(void)
{
    CU_ASSERT(max(arrayOne, 7) == -0.1);
    CU_ASSERT(max(arrayTwo, 7) == 220);
}

double max(double array[], int size)
{
    double max = array[0];
    for (int i=0; i<size; i++)
    {
        if(max < array[i]) {max = array[i];}
    }
    return max;
}

int main()
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("max_test", 0, 0);
    CU_add_test(suite, "max_fun", testMax);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
