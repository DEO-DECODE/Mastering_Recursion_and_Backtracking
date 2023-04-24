#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string &str)
{
  string temp = str;
  reverse(str.begin(), str.end());
  return temp == str;
}
void allComb(string s, set<vector<string>> &collec, vector<string> &curr)
{
  if (s.size() == 0)
  {
    collec.insert(curr);
    return;
  }
  // two possiblity
  int sz = s.size();
  for (int i = 1; i <= sz; ++i)
  {
    string sbs = s.substr(0, i);
    if (isPalindrome(sbs))
    {
      curr.push_back(sbs);
      allComb(s.substr(i), collec, curr);
      curr.pop_back();
    }
  }
}
vector<vector<string>> partition(string s)
{
  vector<string> curr;
  set<vector<string>> collec;
  vector<vector<string>> finAns;
  allComb(s, collec, curr);
  for (auto vec : collec){
      finAns.push_back(vec);
  }
  return finAns;
}
};
