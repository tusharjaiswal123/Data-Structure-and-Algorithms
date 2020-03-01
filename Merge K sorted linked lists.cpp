Node * mergeKLists(Node *arr[], int N)
{
    priority_queue<Node *,vector<Node *>,greater<Node*>> q;
    
    int i;
    
    for(i=0;i<N;i++)
    {
        if(arr[i]!=NULL)
        q.push(arr[i]);
    }
    
    Node *head=NULL;
    Node *curr;
    
    while(!q.empty())
    {
        Node *temp=q.top();
        q.pop();
        
        if(temp->next!=NULL)
        q.push(temp->next);
        
        if(head==NULL)
        {
            head=temp;
            curr=temp;
        }
        else
        {
        curr->next=temp;
        curr=temp;
        }
    
    }
    
    return head;
}
