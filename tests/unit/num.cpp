#include <criterion/criterion.h>
#include "eq.hpp"

Test(num, positiveDigit) {
    testNum("1", 1);
}

Test(num, negativeDigit) {
    testNum("-1", -1);
}

Test(num, positiveNumber) {
    testNum("123", 123);
}

Test(num, negativeNumber) {
    testNum("-123", -123);
}

Test(num, positiveNumberWithSpaces) {
    testNum("  123  ", 123);
}

Test(num, negativeNumberWithSpaces) {
    testNum("  -123  ", -123);
}

Test(num, positiveNumberWithSpacesAndTabs) {
    testNum("  \t123  \t", 123);
}

Test(num, negativeNumberWithSpacesAndTabs) {
    testNum("  \t-123  \t", -123);
}
