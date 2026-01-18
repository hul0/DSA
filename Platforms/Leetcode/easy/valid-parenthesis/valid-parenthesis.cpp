/*
Problem: Valid Parenthesis
Platform: LeetCode
Difficulty: Easy
Link: https://leetcode.com/problems/valid-parentheses/

Approach:
- Push Unmatched brackets to the stack
- Pop when the matching pair is found
- Return if the stack is empty or not at the end

Time Complexity: O(N)
Space Complexity: O(N)

Key Insight:
Bracket Checking requires LIFO method
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Code

bool isValid(string s)
{
    int n = s.size(); // size of the string
    stack<char> st; // A Stack to store the parenthesis
    if (n % 2 == 1) // can't be valid if it isnt a even number
        return false;
    for (int i = 0; i < n; i++)
    {
        if(st.empty()){
            st.push(s[i]);  // first push into the stack
        }
        // To check the bracket pair
        // if we found the pair , pop the top 
        else if (s[i] == ')' && st.top() == '(')
        {
            st.pop();
        }
        else if (s[i] == '}' && st.top() == '{')
        {
            st.pop();
        }
        else if (s[i] == ']' && st.top() == '[')
        {
            st.pop();
        }
        // if nope , then push the bracket into the stack
        else {
            st.push(s[i]);
        }

    }
    // if the stack is empty , it woul mean that all the proper pairs for bracket was found
    return st.empty();

    // Tentiu So Moz :)
}



int main()
{
    string s;
    cout << "Enter : ";
    cin >> s;
    cout << isValid(s);
}