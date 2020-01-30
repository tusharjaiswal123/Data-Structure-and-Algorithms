#include <iostream>

using namespace std;

typedef struct node{
int data;
node* next;
};

node* head;

void insert(int data)
{
    node* temp1=new node();
    if(head==NULL)
    {
    temp1->data=data;
    temp1->next=NULL;
    head=temp1;
    }
    else
    {
     node *temp2=new node();
     temp2=head;
     while(temp2->next!=NULL)
     {
         temp2=temp2->next;
     }
     temp2->next=temp1;
     temp1->data=data;
     temp1->next=NULL;

    }


}
void display()
{
    node*temp;

    temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    head=NULL;

    insert(4);
    insert(6);
    insert(98);
    insert(45);
    display();

    return 0;
}
