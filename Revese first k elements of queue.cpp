queue<ll> modifyQueue(queue<ll> q, int k)
{
    stack<ll> s;
    
    for(int i=0;i<k;i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    
    ll m=q.size()-k;
    
    while(m--)
    {
        ll w=q.front();
        q.pop();
        q.push(w);
    }
    
    return q;
}
