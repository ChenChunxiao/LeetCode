/*
 * atoi.cpp
 *
 *  Created on: 2014年11月7日
 *      Author: xiaochun
 *
 *  Implement atoi to convert a string to an integer.
 *  Hint: Carefully consider all possible input cases.
 *  If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *  Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
 *  You are responsible to gather all the input requirements up front.
 */

#include <stdio.h>
#include <limits.h>

class Solution {
public:
    int atoi(const char *str) {
        if (NULL == str || *str == '\0') {
            return 0;
        }

        int result = 0;
        int n = 0;
        int flag = 1;

        while (*str == ' ') ++str;

        if (*str == '-') {
            ++str;
            flag = -1;
        } else if (*str == '+') {
            ++str;
        }

        for (; *str != '\0'; ++str) {
            if (*str < '0' || *str > '9') {
                break;
            }

            n = flag * (*str - '0');

            if (1 == flag && (result > INT_MAX / 10 || INT_MAX - result * 10 < n)) {
                result = INT_MAX;
                break;
            }

            if (-1 == flag && (result < INT_MIN / 10 || INT_MIN - result * 10 > n)) {
                result = INT_MIN;
                break;
            }

            result = result * 10 + n;
        }

        return result;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.atoi("1"));
    printf("%d\n", s.atoi("123"));
    printf("%d\n", s.atoi("-123"));
    printf("%d\n", s.atoi("2147483647"));
    printf("%d\n", s.atoi("2147483648"));
    printf("%d\n", s.atoi("-2147483648"));
    printf("%d\n", s.atoi("-2147483649"));
    return 0;
}

