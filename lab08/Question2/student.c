#include <stdio.h>
#include <string.h>

/*
Question 2: Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the
first occurrence of needle in haystack, or -1 if needle is not
part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1

Note:
- You may use a simple nested-loop solution.
- Do not use library substring search functions.
*/

int strStr(char* haystack, char* needle) {
    if (needle[0] == '\0') {
        return 0;
    }
    
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);
    
    if (needleLen > haystackLen) {
        return -1;
    }
    
    for (int i = 0; i <= haystackLen - needleLen; i++) {
        int match = 1;
        for (int j = 0; j < needleLen; j++) {
            if (haystack[i + j] != needle[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            return i;
        }
    }
    
    return -1;
}