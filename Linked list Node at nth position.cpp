#include <iostream>

using namespace std;

typedef struct node{
int data;
node* next;
};

node* head;

void insert(int data,int pos)
{
    node* temp1=new node();
    temp1->data=data;
    temp1->next=NULL;

    if(pos==1)
    {
       temp1->next=head;
       head=temp1;
       return;
    }
    node* temp2=new node();
    temp2=head;
    for(int i=1;i<pos-1;i++)
    {
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;

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

    insert(4,1);
    insert(6,2);
    insert(98,2);
    insert(45,1);
    display();

    return 0;
}
