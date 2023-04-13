#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
unordered_map<char, string> mp;
void sol(vector<string> &v , string digits, string ans, int index)
{
    if (index >= digits.size())
    {
        v.push_back(ans);
        return;
    }

    for (int i = 0; i < mp[digits[index]].size(); i++)
    {
        ans.push_back(mp[digits[index]][i]);

        sol(v, digits, ans, index+1);
        ans.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    string ans = "";
    vector<string> v;
    if (digits.empty())
        return v;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
    int index = 0;
    sol(v, digits, ans, index);
    return v;
}
};
