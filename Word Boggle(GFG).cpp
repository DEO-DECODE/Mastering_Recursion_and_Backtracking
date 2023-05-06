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
     
     for(auto word: dictionary){
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
