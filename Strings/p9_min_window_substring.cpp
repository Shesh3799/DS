#include <bits/stdc++.h>
using namespace std;

bool compareIfValid(int mp1[], int mp2[])
{
    for (int i = 0; i < 256; i++)
    {
        if (mp2[i] != mp1[i] && mp1[i] != 0)
        {
            return false;
        }
    }
    return true;
}
string minWindow(string s, string t)
{
    int mp[256] = {0};
    for (char c : t)
    {
        mp[c]++;
    }

    int start = 0;
    int end = 0;
    int actual_start = 0;
    int actual_end = 0;
    int len = s.length();
    int mp2[256] = {0};
    int min_len = 0;
    while (start <= end && end <= len)
    {
        if (compareIfValid(mp, mp2))
        {
            min_len = min(min_len, end - start + 1);
            actual_start = start;
            actual_end = end - 1;
            if (start < len)
                mp2[s[start]]--;
            start++;
        }
        else
        {
            if (end < len)
                mp2[s[end]]++;
            end++;
        }
    }
    cout << actual_start << " " << actual_end << " " << min_len << endl;
    return s.substr(actual_start, actual_end - actual_start + 1);
}

int main()
{
    string s = "ADOBECODEBANC", t = "ABC";

    cout << minWindow(s, t) << endl;

    return 0;
}