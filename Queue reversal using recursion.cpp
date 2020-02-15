void helper(queue<long long int> &q)
{
    if(q.empty())
    return;
    
    long long int k=q.front();
    q.pop();
    
    helper(q);
    
    q.push(k);
}

queue<long long int> rev(queue<long long int> q)
{
    helper(q);
    
    return q;
}
