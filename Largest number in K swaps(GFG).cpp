//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    void findMax(string &str, int k, int ind, string &ans){
		ans=max(ans, str);
		if(k==0) return ;
		for(int i=ind; i<str.size(); ++i){
			for(int j=ind+1; j<str.size(); ++j){
				if(str[j]>str[i]){
					swap(str[i], str[j]);
					findMax(str,k-1,i+1,ans);
					swap(str[i], str[j]);
				}
			}
		}
	}
    string findMaximumNum(string str, int k)
    {
       // code here.
	   string ans=str;
	   findMax(str,k,0, ans);
	   return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
