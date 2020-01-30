struct node*update(struct node*start,int p)
{
    node *temp,*m,*q;
    temp=start;
    m=start;
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    
    temp->next=start;
    start->prev=temp;
    
    p--;
    while(p--)
    {
        m=m->next;
    }
    q=m->next;
    m->next=NULL;
    q->prev=NULL;
    start=q;
}
