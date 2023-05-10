//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void perm(string &str, int ind, vector<string> &ans)
  {
    if (ind >= str.size())
    {
      ans.push_back(str);
      return;
    }
    // Case of pick
    str.insert(ind, " ");
    perm(str, ind + 2, ans);
    str.erase(ind, 1);
    // case of not pick
    perm(str, ind + 1, ans);
  }
  vector<string> permutation(string str)
  {
    vector<string> ans;
    perm(str, 1, ans);
    return ans;
  }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends
