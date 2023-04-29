class Solution {
public:
    void allComb(string &s, unordered_set<string> &collec, int ind)
{
  if (ind >= s.size())
  {
    collec.insert(s);
    return;
  }
  // two possiblity
  if (s[ind] >= '0' && s[ind] <= '9') // digit hai us index pe
    allComb(s, collec, ind + 1);
  else
  {
    char ch, temp = s[ind];
    if (islower(s[ind]))
      ch = toupper(s[ind]);
    if (isupper(s[ind]))
      ch = tolower(s[ind]);
    // no transformation
    allComb(s, collec, ind + 1);
    s[ind] = ch;
    allComb(s, collec, ind + 1);
    s[ind] = temp;
  }
}
vector<string> letterCasePermutation(string s)
{
  unordered_set<string> collec;
  allComb(s,collec,0);
  vector<string> finAns;
  for(auto str: collec){
    finAns.push_back(str);
  }
  return finAns;
}
};
