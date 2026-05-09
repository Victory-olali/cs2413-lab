#include <stdio.h>
#include <stdbool.h>

/*
Question 3: Is Subsequence

Given two strings s and t, return true if s is a subsequence of t,
or false otherwise.

A subsequence of a string is a new string formed from the original
string by deleting some characters without changing the order of
the remaining characters.

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

Hint:
- This can be solved using two pointers.
*/

bool isSubsequence(char* s, char* t) {
    int sIdx = 0;
    int tIdx = 0;
    
    while (s[sIdx] != '\0' && t[tIdx] != '\0') {
        if (s[sIdx] == t[tIdx]) {
            sIdx++;
        }
        tIdx++;
    }
    
    return s[sIdx] == '\0';
}