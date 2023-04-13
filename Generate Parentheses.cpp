#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   vector<string> collec;
void allPoss(string &curr, int op, int clos, int n){
    if(op==n&&clos==n){
        collec.push_back(curr);
        return;
    }
    if(op<=n){
        curr.push_back('(');
        allPoss(curr, op+1 , clos, n);
        curr.pop_back();
    }
    if(clos<op){
        curr.push_back(')');
        allPoss(curr, op , clos+1, n);
        curr.pop_back();
    }
}
vector<string> generateParenthesis(int n)
{
    string curr;
    allPoss(curr, 0,0,n);
    return collec;
}
};
