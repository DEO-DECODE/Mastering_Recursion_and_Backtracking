//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
bool isSafe(vector<vector<int>> &m, int row, int col, int n)
  {
    if (row >= n || col >= n || row < 0 || col < 0)
      return false;
    if (m[row][col] != 1)
      return false;
    return true;
  }
class Solution{
    public:
    char moves[4] = {'U', 'D', 'L', 'R'};
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  vector<string> ans;
  void ratinmaze(string &curr, vector<vector<int>> &m, int n, int row, int col)
  {
    if (row == n - 1 && col == n - 1)
    {
      ans.push_back(curr);
      return;
    }
    for(int mv=0; mv <4; ++mv){
      int cr=row+dx[mv], cc=col+dy[mv];
      if(isSafe(m,cr,cc,n)){
        m[row][col]=0;
        curr.push_back(moves[mv]);
        ratinmaze(curr,m,n,cr,cc);
        curr.pop_back();
        m[row][col]=1;
      }
    }
  }
  vector<string> findPath(vector<vector<int>> &m, int n)
  {
      if(m[0][0]!=1) return ans;
    string curr;
    ratinmaze(curr,m,n,0,0);
    return ans;
  }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
