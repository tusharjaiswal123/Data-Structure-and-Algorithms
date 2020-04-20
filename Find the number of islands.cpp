PROBLEM:

A group of connected 1's forms an island. The task is to complete the method findIslands() which returns the number of islands present.
The function takes three arguments the first is the boolean matrix A and then the next two arguments are N and M denoting the size(N*M)
of the matrix A . 
Input:
The first line of input will be the number of testcases T, then T test cases follow. The first line of each testcase contains two space
separated integers N and M. Then in the next line are the NxM inputs of the matrix A separated by space .
Output:
For each testcase in a new line, print the number of islands present. 
User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function findIslands().
Constraints:
1 <= T <= 100
1 <= N, M <= 100
0 <= A[i][j] <= 1
Example(To be used only for expected output) :
Input
2
3 3
1 1 0 0 0 1 1 0 1
4 4
1 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0
Output
2
2


SOLUTION:


bool inside(int x,int y,int N,int M)
{
    if(x>=0 && x<N && y>=0 && y<M)
    return true;
    
    else
    return false;
}
int findIslands(vector<int> A[], int N, int M) {
    
    int n,m,i,j,ans=0;
    
    vector<vector<bool>> vis(N,vector<bool>(M,false));
    vector<pair<int,int>> dir{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}};
    
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if(A[i][j]==1 && !vis[i][j])       //apply bfs
            {   
                ans++;
                queue<pair<int,int>> q;
                q.push({i,j});
                
                while(!q.empty())
                {
                    pair<int,int> p=q.front();
                    q.pop();
                    vis[p.first][p.second]=true;
                    
                    for(pair<int,int> m:dir)
                    {   
                        int row=p.first+m.first;
                        int col=p.second+m.second;
                        if(inside(row,col,N,M) && !vis[row][col] && A[row][col]==1)
                        {
                            q.push({row,col});
                            vis[row][col]=true;
                        }    
                    }
                }
            }
        }
    }
    
    return ans;
    
}
