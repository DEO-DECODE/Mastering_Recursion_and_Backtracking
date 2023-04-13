#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isvalid(vector<vector<char>> &grid, int row, int col, char n)
{
  int r = (row / 3) * 3;
  int c = (col / 3) * 3;
  // checking in that matrix;
  for (int i = r; i < r + 3; i++)
  {
    for (int j = c; j < c + 3; j++)
    {
      if (grid[i][j] == n)
        return false;
    }
  }
  for (int j = 0; j < 9; j++)
  {
    if (grid[row][j] == n)
      return false;
  }
  for (int i = 0; i < 9; i++)
  {
    if (grid[i][col] == n)
      return false;
  }
  return true;
}
void solution(vector<vector<char>> &board, int row, int col, vector<vector<char>> &aux)
{
  if (row == 9)
  {
    for (int i = 0; i < 9; ++i)
    {
      for (int j = 0; j < 9; ++j)
      {
        aux[i][j] = board[i][j];
      }
    }
    return;
  }
  int r = row;
  int c = col;
  if (c < 8)
  {
    r = row;
    c = col + 1;
  }
  else
  {
    r = row + 1;
    c = 0;
  }
  if (board[row][col] != '.')
  {
    solution(board, r, c, aux);
  }
  else
  {
    for (char ch = '1'; ch <= '9'; ++ch)
    {
      if (isvalid(board, row, col, ch))
      {
        char temp = board[row][col];
        board[row][col] = ch;
        solution(board, r, c, aux);
        board[row][col] = temp;
      }
    }
  }
}
void solveSudoku(vector<vector<char>> &board)
{
  vector<vector<char>> aux(9, vector<char>(9, '.'));
  solution(board, 0, 0, aux);
  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      board[i][j] = aux[i][j];
    }
  }
}
};
