#include <iostream>

using namespace std;

typedef struct node{
int data;
node* next;
};

node *head;

void insert(int n)
{
    node *newnode=new node();

    if(head==NULL)
    {
        newnode->data=n;
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
        newnode->data=n;
        newnode->next=NULL;
    }
}

void reverse()
{
    node *current,*prev,*next;

    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;


}

    void display()
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
    head=NULL;
     int a;
    insert(4);
    insert(6);
    insert(98);
    insert(45);
    display();
    cout<<endl;
    reverse();
    display();



    return 0;
}
