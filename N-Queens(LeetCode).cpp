#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool issafe(vector<vector<string>> &board, int r, int c, int n){
    
    //Making sure ji upar koii naa ho.
    for(int i=r-1; i>=0; i--){
        // cout<<i<<" "<<c<<endl;
        if(board[i][c]=="Q") return false;
    }
    // cout<<"\n\n";
    //Making sure ki rightupper wala diagonal me koii naa ho.
    int row=r-1, col=c+1;
    while (row>=0&&col<n)
    {
        // cout<<row<<" "<<col<<endl;
        if(board[row][col]=="Q") return false;
        row--; col++;
    }
    // cout<<"\n\n";
    //Making sure ki lefttupper wala diagonal me koii naa ho.
    row=r-1, col=c-1;
    while (row>=0&&col>=0)
    {
        // cout<<row<<" "<<col<<endl;
        if(board[row][col]=="Q") return false;
        row--; col--;
    }
    return true;
}
void nqueen(vector<vector<string>> &board, int r, int n, vector<vector<string>> &collection){
    if(r==n){
        vector<string> tempans;
        for(int i=0; i<n; ++i){
            string temp="";
            for(int j=0; j<n; ++j){
                temp+=board[i][j];
            }
            tempans.push_back(temp);
        }
        collection.push_back(tempans);
    }
    for(int j=0; j<n; ++j){
        if(issafe(board, r, j, n)){
            board[r][j]="Q";
            nqueen(board,r+1,n,collection);
            board[r][j]=".";
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
     vector<vector<string>> board(n,vector<string>(n,"."));
     vector<vector<string>> collection;
     nqueen(board,0,n,collection);
     return collection;
}
};
