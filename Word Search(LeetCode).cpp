#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
class Solution {
public:
    bool isValid(vector<vector<char>> &board, string &word, int row, int col)
{
    // out of bound condition
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
    {
        return false;
    }
    return true;
}
void findAns(vector<vector<char>> &board, int ind, string &word, int row, int col, bool &ans)
{
    if (ind == word.size())
    {
        ans = true;
        return;
    }
    if (word[ind] != board[row][col])
        return;
    for (int mv = 0; mv < 4; ++mv)
    {
        int cx = row + dx[mv];
        int cy = col + dy[mv];
        if (isValid(board, word, cx, cy))
        {
            char temp = board[row][col];
            board[row][col] = 'X';
            findAns(board, ind + 1, word, cx, cy, ans);
            board[row][col] = temp;
            // action
        }
    }
}
bool exist(vector<vector<char>> &board, string word)
{
    if(board.size()==1&&board[0].size()==1&&word.size()==1)
    return board[0][0]==word[0];
    bool ans=false;
    for(int i=0; i<board.size(); ++i){
        for(int j=0; j<board[0].size(); ++j){
            if(board[i][j]==word[0]){
                findAns(board,0,word,i,j,ans);
                if(ans==true) break;
            }
        }
    }
    return ans;
}
};
