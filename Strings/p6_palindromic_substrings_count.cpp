#include <bits/stdc++.h>
using namespace std;

/*

*/

bool isPalindrome(string s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
    }
    return true;
}

int countSubstrings(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            if (isPalindrome(s, i, j))
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    string s = "aaa";
    cout<<"Total number of palindromic substrings = "<<countSubstrings(s)<<endl;

    return 0;
}