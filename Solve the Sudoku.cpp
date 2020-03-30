PROBLEM:

Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (mat[][]). The task to print a solved Sudoku. For simplicity you may assume that there will be only one unique solution.

Sample Sudoku for you to get the logic for its solution:


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 9*9 space separated values of the matrix mat[][] representing an incomplete Sudoku state where a 0 represents empty block.
Output:
For each test case, in a new line, print the space separated values of the solution of the the sudoku.
Constraints:
1 <= T <= 10
0 <= mat[] <= 9
Example:
Input:
1
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1 
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
Output:
3 1 6 5 7 8 4 9 2 5 2 9 1 3 4 7 6 8 4 8 7 6 2 9 5 3 1 2 6 3 4 1 5 9 8 7 9 7 4 8 6 3 1 2 5 8 5 1 7 9 2 6 4 3 1 3 8 9 4 7 2 5 6 6 9 2 3 5 1 8 7 4 7 4 5 2 8 6 3 1 9


SOLUTION:

#include <iostream>
using namespace std;

bool findemptycell(int a[9][9],int &row,int &col)
{
    int i,j;
    
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(a[i][j]==0)
            {
                row=i;
                col=j;
                return true;
            }
        }
    }
    
    return false;
}

bool isSafe(int a[9][9],int row,int col,int num)
{
    int i,j,u,v;
    
    for(i=0;i<9;i++)
    {
        if(a[row][i]==num)
        return false;
        
        if(a[i][col]==num)
        return false;
    }
    
    u=row/3;
    v=col/3;
    
    for(i=3*u;i<3*u+3;i++)
    {
        for(j=3*v;j<3*v+3;j++)
        {
            if(a[i][j]==num)
            return false;
        }
    }
    
    return true;
    
}

bool sudoku(int a[9][9])
{   
    int row,col;
    
    if(findemptycell(a,row,col)==false)
    return true;
    
    for(int num=1;num<=9;num++)
    {
        if(isSafe(a,row,col,num))
        {
            a[row][col]=num;
            
            if(sudoku(a))
            return true;
            
            a[row][col]=0;
        }
    }
    return false;
    
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{   
	    int a[9][9];
	    int i,j;
	    
	    for(i=0;i<9;i++)
	    {
	        for(j=0;j<9;j++)
	        cin>>a[i][j];
	    }
	    
	    if(sudoku(a)==true)
	    {
	    for(i=0;i<9;i++)
	    {
	        for(j=0;j<9;j++)
	        {
	            cout<<a[i][j]<<" ";
	        }
	        //cout<<endl;
	    }
	    
	    cout<<endl;
	    }
	    
	    
	}
	return 0;
}
