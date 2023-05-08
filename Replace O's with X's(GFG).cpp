//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// Surrounded Regions(LeetCode)
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
class Solution{
public:

void replaceOwithX(vector<vector<char>> &board, int r, int c)
{
    int n = board.size(), m = board[0].size();
    queue<pair<int, int>> q;
    q.push({r, c});
    board[r][c] = 'Z';
    while (q.size() > 0)
    {
        auto currPr = q.front();
        q.pop();
        for (int mv = 0; mv < 4; ++mv)
        {
            int childX = currPr.first + dx[mv], childY = currPr.second + dy[mv];
            if (childX >= 0 && childX < n && childY >= 0 && childY < m)
            {
                if (board[childX][childY] == 'O')
                {
                    board[childX][childY] = 'Z';
                    q.push({childX, childY});
                }
            }
        }
    }
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
    {
        
    for (int i = 0; i < n; ++i)
    {
        if (board[i][0] == 'O')
        {
            replaceOwithX(board, i, 0);
        }
        if (board[i][m - 1] == 'O')
        {
            replaceOwithX(board, i, m - 1);
        }
    }
    for (int j = 0; j < m; ++j)
    {
        if (board[0][j] == 'O')
        {
            replaceOwithX(board, 0, j);
        }
        if (board[n - 1][j] == 'O')
        {
            replaceOwithX(board, n - 1, j);
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(board[i][j]=='Z'){
                board[i][j]='O';
            }
            else{
                board[i][j]='X';
            }
        }
    }
    return board;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
