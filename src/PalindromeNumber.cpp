/*
 * PalindromeNumber.h
 *
 *  Created on: 2014年11月7日
 *      Author: xiaochun
 *
 *  Could negative integers be palindromes? (ie, -1)
 *  If you are thinking of converting the integer to string, note the restriction of using extra space.
 *  You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
 *  you know that the reversed integer might overflow. How would you handle such case?
 *  There is a more generic way of solving this problem.
 */

#include <stdio.h>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        if (x < 10) {
            return true;
        }

        int n = 10;
        int temp = x;
        while (temp >= 100) {
            n *= 10;
            temp /= 10;
        }

        temp = x;
        int m = 1;
        while (n > 0) {
            if ((temp / n) % 10 != (temp / m) % 10) {
                return false;
            }

            n /= 10;
            m *= 10;

            if (n == m) {
                break;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.isPalindrome(101));
    printf("%d\n", s.isPalindrome(1001));
    printf("%d\n", s.isPalindrome(121));
    printf("%d\n", s.isPalindrome(1001001));
}

