queue<ll> modifyQueue(queue<ll> q, int k)
{
    stack<ll> s;
    queue<ll> q1;
    
    for(int i=0;i<k;i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty())
    {
        q1.push(s.top());
        s.pop();
    }
    while(!q.empty())
    {
        q1.push(q.front());
        q.pop();
    }
    
    return q1;
}
