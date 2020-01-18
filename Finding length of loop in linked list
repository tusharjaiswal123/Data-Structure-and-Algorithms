int countNodesinLoop(struct Node *head)
{
     Node *fast,*slow;
     fast=head;
     slow=head;
     
     int flag=0;
     
     while(slow!=NULL && fast!=NULL)
     {
         slow=slow->next;
         fast=fast->next;
         if(fast==NULL)
         {
             flag=0;
             break;
         }
         fast=fast->next;
         if(fast==slow)
         {
             flag=1;
             break;
         }
         
     }
     
     if(flag==0)
     {
         return 0;
     }
     else
     {
        Node *temp;
        temp=head;
        int ans=1;
        
        while(slow!=temp)
        {
            slow=slow->next;
            temp=temp->next;
        }
        temp=temp->next;
        
        while(temp!=slow)
        {
            temp=temp->next;
            ans++;
        }
        return ans;
     }
     
}
