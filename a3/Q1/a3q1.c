#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "avg_and_max.h"

double arrayOne[10] = {-1.3, -1.45, -220, -100, -0.1, -0.1234, -200};
double arrayTwo[10] = {-1.3, 1.45, 220, 100, 0, 200, 0.1234};

void testAverage(void)
{
    CU_ASSERT(average(arrayOne, 7) == -74.7104857142857);
    CU_ASSERT(average(arrayTwo, 7) == 74.3247714285714);
}

double average(double array[], int size)
{
    double sum = 0;
    for (int i=0; i<size-1; i++) {sum += array[i];}
    return sum / size;
}

int main()
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("avg_test", 0, 0);
    CU_add_test(suite, "avg_fun", testAverage);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
