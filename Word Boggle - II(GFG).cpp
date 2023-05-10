// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
	void dfs(int row, int col, vector<vector<char>>& board, int index,vector<vector<int>> &visited,string &word, bool & isword){
    
    int l=word.length();
    int m=board.size();
    int n=board[0].size();
    if(index==l){
    // cout<<"Mil gaya : "<<row<<" "<<col<<" "<<index<<" "<<l<<endl;
    isword=true;
    // return true;
    }
    if(row>=m||row<0||col>=n||col<0||board[row][col]!=word[index])
    return ;
    if(visited[row][col])
    return ;
    
    if(board[row][col]==word[index]){
        // cout<<row<<" "<<col<<" "<<index<<" "<<word[index]<<endl;
        index++;
    }
    visited[row][col]=1;
    dfs(row-1,col,board,index,visited,word,isword);
    dfs(row+1,col,board,index,visited,word,isword);
    dfs(row,col+1,board,index,visited,word,isword);
    dfs(row,col-1,board,index,visited,word,isword);
    dfs(row-1,col-1,board,index,visited,word,isword);
    dfs(row+1,col+1,board,index,visited,word,isword);
    dfs(row-1,col+1,board,index,visited,word,isword);
    dfs(row+1,col-1,board,index,visited,word,isword);
    visited[row][col]=0;
    
    
}
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    vector<string> ans;
	   vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
     int m=board.size();
     int n=board[0].size();
    //  bool isw=false;
     unordered_map<string, int> track;
     for(auto word: dictionary){
         if(track[word]>0)
         continue;
         track[word]++;
         bool isword=false;
         int index=0;
     for(int i=0; i<m ; ++i){
        //  bool check=false;
         for(int j=0; j<n ; ++j){
             if(board[i][j]==word[index]){
                dfs(i,j,board,index,visited,word,isword);
                if(isword){
                ans.push_back(word);
                break;
                }
             }
         }
         if(isword)
         break;
     }
     }
     return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends
