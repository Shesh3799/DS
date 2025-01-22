#include <bits/stdc++.h>
using namespace std;

/*

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

Input: s = "()[]{}"

Output: true

Link: https://leetcode.com/problems/valid-parentheses/description/

*/

bool isValid(string s)
{
    stack<char> st;
    for (const char &c : s)
    {
        if (c == '{' || c == '(' || c == '[')
        {
            st.push(c);
        }
        else if (st.empty() ||
                 c == '}' && st.top() != '{' ||
                 c == ']' && st.top() != '[' ||
                 c == ')' && st.top() != '(')
        {
            return false;
        }
        else
            st.pop();
    }
    return st.empty();
}

int main()
{
    string s = "()[]{}";
    cout << isValid(s) << endl;

    return 0;
}