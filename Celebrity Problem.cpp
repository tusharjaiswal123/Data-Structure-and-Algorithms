int getId(int M[MAX][MAX], int n)
{
    stack<int> s;
    int i;
    
    for(i=0;i<n;i++)
    s.push(i);
    
    while(s.size()>1)
    {
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
    
        if(M[a][b]==1)
            s.push(b);
        else
            s.push(a);
    }
    
    int c=s.top();
    
    for(i=0;i<n;i++)
    {
        if(i==c)
        continue;
        
        if(M[i][c]==0 || M[c][i]==1)
        {
            return -1;
        }
    }
    
    return c;
    
    
}
