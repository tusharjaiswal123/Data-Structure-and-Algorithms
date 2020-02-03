void push(int a)
{   
    if(s.empty() || a<s.top())
    s.push(a);
    
    else
    s.push(s.top());
    
}

bool isFull(int n)
{
    if(s.size()==n)
    return true;
    else
    return false;
}

bool isEmpty()
{
    return s.empty();
}

int pop()
{   
    if(s.empty())
    return -1;
    
    int k=s.top();
    s.pop();
    
    return k;
}

int getMin()
{
   int ans=s.top();
   
   return ans;
}
