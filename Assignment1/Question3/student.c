#include "Student.h"
#include <stdlib.h>

//You are given a large integer represented as an integer array digits, where:

//digits[i] is the i-th digit of the integer
//digits are ordered from most significant to least significant
//there are no leading 0s (except the number 0 itself in some of our tests)
//Goal: Add 1 to the number and return the resulting digits array.

//Example 1:
//Input: digits = [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
//Incrementing by one gives 4321 + 1 = 4322.
//Thus, the result should be [4,3,2,2].

//Example 2:
//Input: digits = [9]
//Output: [1,0]
//Explanation: The array represents the integer 9.
//Incrementing by one gives 9 + 1 = 10.
//Thus, the result should be [1,0].

//Return value (int*): the output digits array.
//Output parameter (returnSize): set *returnSize to the number of digits in the returned array.

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if (returnSize == NULL) return NULL;

    if (digitsSize <= 0) {
        int* out = (int*)malloc(sizeof(int));
        if (!out) return NULL;
        out[0] = 1;
        *returnSize = 1;
        return out;
    }

    // Check if all digits are 9
    int all9 = 1;
    for (int i = 0; i < digitsSize; ++i) {
        if (digits[i] != 9) { all9 = 0; break; }
    }

    if (all9) {
        int* out = (int*)malloc((size_t)(digitsSize + 1) * sizeof(int));
        if (!out) return NULL;
        out[0] = 1;
        for (int i = 1; i <= digitsSize; ++i) out[i] = 0;
        *returnSize = digitsSize + 1;
        return out;
    }

    // Otherwise, copy and add one from the end
    int* out = (int*)malloc((size_t)digitsSize * sizeof(int));
    if (!out) return NULL;
    for (int i = 0; i < digitsSize; ++i) out[i] = digits[i];

    for (int i = digitsSize - 1; i >= 0; --i) {
        if (out[i] == 9) {
            out[i] = 0;
        } else {
            out[i] += 1;
            break;
        }
    }

    *returnSize = digitsSize;
    return out;
}


