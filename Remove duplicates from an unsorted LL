Node *removeDuplicates(Node *root)
{
    Node *p,*q,*temp;
    p=root;
    q=p->next;
    temp=root;
    
    map<int,int> m;
    
    m[p->data]++;
    
    while(q!=NULL)
    {   
        m[q->data]++;
        if(m[q->data]>1)
        {   
            m[q->data]--;
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
