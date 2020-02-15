int findMaxDiff(int A[], int n)
{ 
    
    int l[n],r[n],i,k=0,ans=0;
    stack<int> s;
    
    s.push(A[0]);
    l[0]=0;
    for(i=1;i<n;i++)
    {
        if(A[i]>s.top())
        {
            l[i]=s.top();
            s.push(A[i]);
        }
        else
        {
            while(!s.empty() && A[i]<=s.top() )
            {
                s.pop();
            }
            if(s.empty())
            {
                l[i]=0;
                s.push(A[i]);
            }
            else
            {
            l[i]=s.top();
            s.push(A[i]);
            }
        }
    }
    
    r[n-1]=0;
    stack<int> s2;
    s2.push(A[n-1]);
    for(i=n-2;i>=0;i--)
    {
        if(A[i]>s2.top())
        {
            r[i]=s2.top();
            s2.push(A[i]);
        }
        else
        {
            while(!s2.empty() && A[i]<=s2.top() )
            {
                s2.pop();
            }
            if(s2.empty())
            {
                r[i]=0;
                s2.push(A[i]);
            }
            else
            {
                r[i]=s2.top();
                s2.push(A[i]);
            }
        }
    }
    
    
    
    for(i=0;i<n;i++)
    {   
        int m=r[i]-l[i];
        k=abs(m);
        ans=max(ans,k);
    }
    
    return ans;
}
