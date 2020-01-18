void reverse(Node **head_ref)
{
   Node *curr=*head_ref;
   Node *prev=NULL;
   Node *next;
   
   while(curr!=NULL)
   {
       next=curr->next;
       curr->next=prev;
       curr->prev=next;
       prev=curr;
       curr=next;
   }
   *head_ref=prev;
}
