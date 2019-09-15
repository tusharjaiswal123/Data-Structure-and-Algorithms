#include <iostream>

using namespace std;

typedef struct node{
int data;
node* next;
};

node *head;

void insert(int data)
{
    node *temp1=new node();

    if(head==NULL)
    {
        temp1->data=data;
        temp1->next=NULL;
        head=temp1;
    }
    else
    {
        node* temp2=new node();
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

    void delet(int n)
    {
        node *temp1=new node();
        temp1=head;

        if(n==1)
        {
            head=temp1->next;
            free(temp1);
            return;
        }

        for(int i=1;i<n-1;i++)
            temp1=temp1->next;
        node *temp2=new node();
        temp2=temp1->next;

        temp1->next=temp2->next;
        free(temp2);

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
    cout<<"enter the position for deleting node ";
    cin>>a;
    delet(a);
    display();
    return 0;
}
