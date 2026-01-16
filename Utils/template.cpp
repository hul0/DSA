/*
Problem: Length of Last Word
Platform: LeetCode
Difficulty: Easy
Link: https://leetcode.com/problems/length-of-last-word/

Approach:
- Sort the array of strings
- Compare the first and last string
- Common prefix of these two is the answer

Time Complexity: O(n log n * m)
Space Complexity: O(1)

Key Insight:
Lexicographical sorting brings closest strings together.
*/

#include <bits/stdc++.h>
using namespace std;

// code here
