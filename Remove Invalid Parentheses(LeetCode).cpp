#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string &str)
{
    int brack = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(')
            brack++;
        else if (str[i] == ')')
            brack--;
        if (brack < 0)
            return false;
    }
    return brack == 0;
}
vector<string> removeInvalidParentheses(string s)
{
    vector<string> answers;
    if (s.size() == 0)
    {
        answers.push_back("");
        return answers;
    }
    queue<string> q;
    q.push(s);
    unordered_set<string> vis;
    vis.insert(s);
    bool found = false;
    while (q.size() > 0)
    {
        int sz = q.size();
        for (int j = 0; j < sz; ++j)
        {

            string currentString = q.front();
            q.pop();
            if (isValid(currentString))
            {
                answers.push_back(currentString);
                found = true;
            }
            if (found)
                continue;
            for (int i = 0; i < currentString.size(); ++i)
            {
                if (currentString[i] == '(' || currentString[i] == ')')
                {
                    string temp = currentString.substr(0, i);
                    string remString = currentString.substr(i + 1);
                    string finalString = temp + remString;
                    if (vis.find(finalString) == vis.end())
                    {
                        q.push(finalString);
                        vis.insert(finalString);
                    }
                }
            }
        }
        if (found)
            break;
    }
    return answers;
}
};
