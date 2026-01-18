/*
Problem: String to Integer
Platform: LeetCode
Difficulty: Medium
Link: https://leetcode.com/problems/string-to-integer-atoi/

Approach:
- Read each char of the string
- Build a string with only valid signs and digits found from the original string
- Start parsing the digits of the new string and adding them into a INT variable
- Break if it crosses the limits of 32-bit signed integer
- return the final signed value

Time Complexity: O(N)
Space Complexity: O(N)

Key Insight:

*/

#include <iostream>
#include <string>
#include <math.h>
#include <unordered_map>
#include <climits>
using namespace std;

// code here
int myAtoi(string s)
{
    string num = "";
    int n = s.size(); // Size of the string
    bool space = false;
    int value = 0; // Final Integer Value
    int neg = 1;   // To store if the string has negative sign
    int dig;       // To store digits
    bool parsingStarted = false;
    for (int i = 0; i < n; i++)
    {
        space = isspace(s[i]);
        if (space && !parsingStarted) // if whitespace is found & has not started yet
        {
            continue; // skip to the next char
        }
        // Sign Checking at start
        else if ((s[i] == '-' || s[i] == '+') && !parsingStarted)
        {
            if (s[i] == '-')
            {
                neg = -1; // If the char is '-' sign
            }
            parsingStarted = true; // Parsing started when - or + sign is found
        }

        else if (!isdigit(s[i]))
        {
            break; // Break the loop on any non-digit character
        }
        else if (isdigit(s[i]))
        {
            num += s[i]; // Add the digit to the num string
            parsingStarted = true;
        }
    }

    // Time to loop through the num string and build the integer brick-by-brick
    for (int i = 0; i < num.size(); i++)
    {
        dig = num[i] - '0'; // How should i explain this ? '5' - '0' = 5 . So yeah! Let it happen

        // These gave me a hard time

        // If the signed value is greater than max value of 32-bit INT , then stop the conversion and return the MAX INT
        if ((value * neg > INT_MAX / 10 || value * neg >= INT_MAX / 10 && dig > INT_MAX % 10))
        {
            return INT_MAX;
        }

        // If the signed value is lesser than min value of 32-bit INT , then stop the conversion and return the MIN INT
        else if (value * neg < INT_MIN / 10 || value * neg <= INT_MIN / 10 && dig > 7)
        {
            return INT_MIN;
        }

        // Else keep the conversion ON
        else
        {
            value = value * 10 + dig; // Shifting the value to left and adding the digits
        }
    }

    return value * neg; // Return the value with sign
}

int main()
{
    string s;
    cout << "Enter : ";
    getline(cin, s);
    cout << myAtoi(s);
    return 0;
}