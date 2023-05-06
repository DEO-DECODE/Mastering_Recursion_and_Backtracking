//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int winnerOfGame(int n, int k)
{
    if (n == 1)
        return 0;
    int y = winnerOfGame(n - 1, k);
    return (y + k) % n;
}
int safePos(int n, int k)
{
    return winnerOfGame(n, k) + 1;
}
    
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends
