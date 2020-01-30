#include <iostream>

using namespace std;

typedef struct node{
int data;
node* next;
};

 node* insert(node* head,int data)
 {
     node* newnode=new node();
     if(head==NULL)
     {
         newnode->data=data;
         newnode->next=NULL;
             head=newnode;
     }
     else
     {
         node *temp;
         temp=head;

         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
         temp->next=newnode;
         newnode->data=data;
         newnode->next=NULL;

     }
     return head;
 }

 void Print(node* head)
 {
     if(head!=NULL)
     {
         Print(head->next);
         cout<<head->data<<" ";
     }
 }






    void display(node* head)
    {
        node *temp;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }



int main()
{
    node *head;
    head=NULL;
     int a;
    head=insert(head,4);
    head=insert(head,6);
    head=insert(head,98);
    head=insert(head,45);
    Print(head);




    return 0;
}
