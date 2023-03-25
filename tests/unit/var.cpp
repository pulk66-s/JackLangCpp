#include <criterion/criterion.h>
#include "eq.hpp"

Test(var, simple) {
    testVar("a", "a");
}

Test(var, simpleWithSpaces) {
    testVar("  a  ", "a");
}

Test(var, simpleWithSpacesAndTabs) {
    testVar("  \ta  \t", "a");
}

Test(var, normal) {
    testVar("abc", "abc");
}

Test(var, normalWithSpaces) {
    testVar("  abc  ", "abc");
}

Test(var, normalWithSpacesAndTabs) {
    testVar("  \tabc  \t", "abc");
}

Test(var, normalWithNumbers) {
    testVar("abc123", "abc123");
}

Test(var, normalWithNumbersWithSpaces) {
    testVar("  abc123  ", "abc123");
}

Test(var, normalWithNumbersWithSpacesAndTabs) {
    testVar("  \tabc123  \t", "abc123");
}

Test(var, normalWithNumbersAndUnderscore) {
    testVar("abc_123", "abc_123");
}

Test(var, normalWithNumbersAndUnderscoreWithSpaces) {
    testVar("  abc_123  ", "abc_123");
}

Test(var, normalWithNumbersAndUnderscoreWithSpacesAndTabs) {
    testVar("  \tabc_123  \t", "abc_123");
}

Test(var, shuffle) {
    testVar("a1b2c3", "a1b2c3");
}

Test(var, shuffleWithSpaces) {
    testVar("  a1b2c3  ", "a1b2c3");
}

Test(var, shuffleWithSpacesAndTabs) {
    testVar("  \ta1b2c3  \t", "a1b2c3");
}

Test(var, shuffleWithNumbers) {
    testVar("a1b2c3d4e5", "a1b2c3d4e5");
}

Test(var, shuffleWithNumbersWithSpaces) {
    testVar("  a1b2c3d4e5  ", "a1b2c3d4e5");
}

Test(var, shuffleWithCase) {
    testVar("a1B2c3D4e5", "a1B2c3D4e5");
}

Test(var, shuffleWithCaseWithSpaces) {
    testVar("  a1B2c3D4e5  ", "a1B2c3D4e5");
}

Test(var, shuffleWithCaseWithSpacesAndTabs) {
    testVar("  \ta1B2c3D4e5  \t", "a1B2c3D4e5");
}
