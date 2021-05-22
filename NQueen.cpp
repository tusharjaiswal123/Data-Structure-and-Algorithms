PROBLEM:



The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 
Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above


Example 2:
Input: n = 1
Output: [["Q"]]
 

Constraints:
1. 1 <= n <= 9
  
  

  
SOLUTION:



class Solution {
public:
    
    bool issafe(int r,int c,int n,vector<string> &board)
    {
        int i,j;
        
        for(i=0;i<c;i++)
        {
            if(board[r][i]=='Q')
                return false;
        }
        
        i=r;
        j=c;
        
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q')
                return false;
            
            i--;
            j--;
        }
        
        i=r;
        j=c;
        
        while(i<n && j>=0)
        {
            if(board[i][j]=='Q')
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    void nqueen(int col,int n,vector<string> &board,vector<vector<string>> &ans)
    {
        if(col>=n)
        {
            ans.push_back(board);
            return;
        }
            
        for(int i=0;i<n;i++)
        {
            if(issafe(i,col,n,board))
            {
                board[i][col] = 'Q';
                nqueen(col+1,n,board,ans);
                board[i][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n);
        string s;
        
        for(int i=0;i<n;i++)
            s.push_back('.');
        
        for(int i=0;i<n;i++)
            board[i]=s;
        
        nqueen(0,n,board,ans);
        
        return ans;
    }
};
