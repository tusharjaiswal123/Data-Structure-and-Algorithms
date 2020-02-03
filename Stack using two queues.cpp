1.make one operation in o(1) time 
2.make second operation costly

void QueueStack :: push(int x)
{
    q1.push(x);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{   
    if(q1.empty())
    return -1;
    
    while(q1.size()!=1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int k=q1.front();
    q1.pop();
    
    swap(q1,q2);
    
    return k;
    

}
