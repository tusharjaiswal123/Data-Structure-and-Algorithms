Node *removeDuplicates(Node *root)
{
    Node *p,*q,*temp;
    p=root;
    q=p->next;
    
    while(q!=NULL)
    {
        if(p->data==q->data)
        {
            temp=q;
            p->next=q->next;
            q=q->next;
            free(temp);
        }
        else
        {
            p=p->next;
            q=p->next;
        }
    }
    return root;
    
}
