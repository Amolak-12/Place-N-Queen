#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> UpperDiagonalCheck;
unordered_map<int,bool> LowerDiagonalCheck;
void printSolution(vector<vector<char>>& board, int col , int n ,int& count)
{
  for(int i = 0;i<n;i++)
    {
      for(int j = 0; j<n;j++)
        {
          cout  << board[i][j] << " ";
        }
      cout << endl;
    }
  count++;
  cout << endl << endl << endl;
}

bool isSafe(vector<vector<char>>& board,int row, int col , int n)
{
  //Check that placing Queen at current cell is safe or not

  int i =row;
  int j =col;
  //Check left
  while(j>=0 )
    {
      if(board[i][j] == 'Q')
      {
        return false;
      }
      j--;
    }

   i =row;
   j =col;
  //Check Upperleft Diagonal
  while(i>=0 && j>=0)
    {
      if(board[i][j] == 'Q')
      {
        return false;
      }
      i--;
      j--;
    }

  i =row;
  j =col;
  //Check Lowerleft Diagonal
  while(i < n && j >=0)
    {
      if(board[i][j] == 'Q')
      {
        return false;
      }
      i++;
      j--;
    }
  return true;
}
void Solve(vector<vector<char>>& board, int col , int n ,int& count)
{
  //Base case
  if(col>=n)
  {
    printSolution(board,col,n,count);
    return;
  }

  //Processing
  for(int row=0;row<n;row++)
    {
      if(isSafe(board,row,col,n))
      {
        
        //Making Queen
        board[row][col] = 'Q';
        rowCheck[row] = true;
        UpperDiagonalCheck[n-1+col-row] = true;
        LowerDiagonalCheck[row+col] = true;
        //Recursive Relation
        Solve(board,col+1,n,count);
        //Backtracking
        board[row][col] = '-';
      }
    }
}
int main() {
  int n =6;
  int col = 0;
  int count = 0;
  vector<vector<char>>board(n,vector<char>(n,'-'));

  Solve(board,col,n,count);
  cout << count << endl;
  
}