#include <stdio.h>

/*
Question 1: Longest Common Prefix

Write a function to find the longest common prefix string
among an array of strings.

A prefix is the beginning part of a string.

Examples:
Input: ["flower", "flow", "flight"]
Output: "fl"

Input: ["dog", "racecar", "car"]
Output: ""

IMPORTANT:
- You ARE allowed to modify the first string (strs[0])
- You should store the result directly in strs[0]
- Return strs[0] as the result
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }
    
    int minLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < minLen) {
            minLen = len;
        }
    }
    
    int prefixLen = 0;
    for (int col = 0; col < minLen; col++) {
        char ch = strs[0][col];
        int match = 1;
        
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][col] != ch) {
                match = 0;
                break;
            }
        }
        
        if (!match) {
            break;
        }
        prefixLen++;
    }
    
    strs[0][prefixLen] = '\0';
    return strs[0];
}