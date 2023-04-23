
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkIp(string str)
{
  for (int i = 0; i < str.size(); ++i)
    {
      string temp="";
      while (str[i] != '.' && i < str.size())
      {
        temp+=(str[i]);
        i++;
      }
      // cout<<temp<<endl;
      // prefix zeroes
      if(temp.size()>3) return false;
      if (temp.size() >= 1)
      {
        if (temp[0] == '0' && temp.size() > 1)
        {
          return false;
        }
        if (stoi(temp) < 0 || stoi(temp) > 255)
        {
          return false;
        }
      }
    }
  return true;
}
void allCombinations(string &s, int ind, int dotCount, unordered_set<string> &collec)
{
  // out of bound condition
  if (ind >= s.size()+1)
  {
    return;
  }
  if (dotCount == 0)
  {
    if (checkIp(s))
    {
      collec.insert(s);
    }
    return;
  }
  s.insert(ind, ".");
  allCombinations(s, ind + 2, dotCount - 1, collec);
  s.erase(ind, 1);
  allCombinations(s, ind + 1, dotCount, collec);
}
vector<string> restoreIpAddresses(string s)
{
  unordered_set<string> collec;
  allCombinations(s, 1, 3, collec);
  vector<string> finAns;
  for (auto strs : collec)
  {
    finAns.push_back(strs);
  }
  return finAns;
}
};
