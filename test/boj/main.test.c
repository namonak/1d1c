#include "boj/test_cases.h"
#include "unity.h"

#ifdef TEST
int main() {
    UNITY_BEGIN();
    RUN_TEST(test_no10998);
    RUN_TEST(test_no10807);
    RUN_TEST(test_no27866);
    RUN_TEST(test_no15439);
    UNITY_END();
    return 0;
}

void setUp(void) {
}

void tearDown(void) {
}
#endif
