int detectloop(Node *head) {
    
    Node *slow,*fast;
    slow=head;
    fast=head;
    
    while(slow!=NULL && fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
        
        if(slow==NULL || fast==NULL)
        break;
        
        fast=fast->next;
        
        if(fast==slow)
        {
            return 1;
        }
    }
    return 0;
    
}
