void helper(node *p,bool reset)
{
    if(p==NULL)
    return;
    
    static node* next=NULL;
    if(reset)
    {
        next=NULL;
    }
    
    helper(p->right,0);
    p->next=next;
    next=p;
    helper(p->left,0);
}
void populateNext(struct node* p)
{
    if(p==NULL)
    return;
    
    helper(p,true);
    
}
