#include <iostream>

using namespace std;

typedef struct node{
int data;
node* next;
};


node* insert(node *head,int data)
{
    node *newnode=(node*)malloc(sizeof(node));

    newnode->data=data;
    newnode->next=head;

    head=newnode;
    return head;
}

void display(node* head)
{

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;

    }
    cout<<endl;
}

int main()
{
    int x,n,i;
    node* head=NULL;

        cout<<"length of linked list: ";
        cin>>x;

        for(i=0;i<x;i++)
        {
            cout<<"enter the number: ";
            cin>>n;
            head=insert(head,n);
            display(head);
        }
    return 0;
}
