/*
Problem: Length of Last Word
Platform: LeetCode
Difficulty: Easy
Link: https://leetcode.com/problems/length-of-last-word/
Runtime: 0ms 
Beats: 100%

Approach:
- Traverse the string and insert the words in a stack
- Count length of the top element of stack

Time Complexity: O(N)
Space Complexity: O(1)

Key Insight:


*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// code here

// function to get the length of last string

int lengthOfLastWord(string s)
{
    int n = s.size();  // length of the string
    string last = "";  // empty last string
    bool isWhiteSpace; // A boolean to store if the character is a whitespace

    // Loop through the characters from last
    for (int i = n - 1; i >= 0; i--)
    {
        isWhiteSpace = isspace(s[i]); // checking if the current char is whitespace
        if (!isWhiteSpace)
        {
            last += s[i]; //  if char is not a ws , add it to the last
        }
        if (isWhiteSpace && last != "")
        {
            break; //  if last is not empty and the char is a ws , break (because we have already found the last word)
        }
    }
    return last.size();
}

// Main Function
int main()
{
    string s;
    cout << "Enter the string:";
    getline(cin, s); // getline() to get the full sentence , cin stops at whitespace
    cout << lengthOfLastWord(s);
    return 0;
}