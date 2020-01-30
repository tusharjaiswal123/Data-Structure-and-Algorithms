#include <iostream>
using namespace std;

typedef struct node{
int data;
node* next;
};

node *Front=NULL;
node *rear=NULL;

void Enqueue(int n)
{
    node *temp=new node();
    temp->data=n;
    temp->next=NULL;
    if(Front==NULL&&rear==NULL)
    {
        Front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}

void Dequeue()
{
    node *temp;
    temp=Front;
    if(Front==NULL)
    {
        cout<<"Queue is empty"<<endl;
    }
    else if(Front==rear)
    {
        Front=rear=NULL;
    }
    else
    {
        Front=Front->next;
    }
    free(temp);
}

int FRONT()
{
    if(Front==NULL)
        cout<<"Queue is empty"<<endl;
    else
    {
        return rear->data;
    }
}

void display()
{
    node *temp;
    temp=Front;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Enqueue(47);display();
    Enqueue(6);display();
    Enqueue(4);display();
    Enqueue(5);display();
    Enqueue(2);display();
    Enqueue(3);display();
    Enqueue(8);display();

    Dequeue();display();
    Dequeue();display();
    Dequeue();display();
    Enqueue(10);display();
    Enqueue(12);display();
    cout<<FRONT();



    return 0;
}
