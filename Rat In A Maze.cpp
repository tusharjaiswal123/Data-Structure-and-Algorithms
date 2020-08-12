PROBLEM:

Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (n-1, n-1). Find all possible paths that the rat can take to reach from
source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line contains an integer
N denoting the size of the square matrix. The next line contains N*N space separated values of the matrix m where 0's represents blocked paths and 1 represent valid paths.
Output:
For each test case output will be space separated sorted strings denoting all directions, which the rat could take to reach the destination. Print -1 if no such path exists.
User Task:
Your task is to complete the function printPath() which returns a sorted array of strings denoting all the possible paths which the rat can take to reach the destination at
(n-1, n-1). If no such path exists the function should return empty array.

Constraints:
1 <= T <= 100
2 <= N <= 5
0 <= matrix[i][j] <= 1
Example
Input:
3
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1
2
1 0 1 0 
Output:
DRDDRR
DDRDRR DRDDRR
-1

SOLUTION:

void maze(int m[MAX][MAX],int x,int y,int n,string s,vector<string>& str)
{   
    
    if(x>=n || y>=n || x<0 || y<0 || m[x][y]==0 || m[x][y]==2)
    return;
    
    if(x==n-1 && y==n-1)
    {
        str.push_back(s);
        return;
    }
    
    
    m[x][y]=2;
    
    maze(m,x+1,y,n,s+'D',str);
    maze(m,x-1,y,n,s+'U',str);
    maze(m,x,y+1,n,s+'R',str);
    maze(m,x,y-1,n,s+'L',str);
    
    m[x][y]=1;
    
}

vector<string> printPath(int m[MAX][MAX], int n)
{
	vector<string> str;
	str.clear();
	
	maze(m,0,0,n,"",str);
	
	sort(str.begin(),str.end());
	
	return str;
}
