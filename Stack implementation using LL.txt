#include<iostream>
using namespace std;

#define MAX 100

typedef struct node{
int data;
node* next;
};
node* top=NULL; //head is replaced by top

int isempty()
     {
     if(top==NULL)
        return true;
     else
        return false;
     }


void push(int n)
{

    node* newnode=new node();
    newnode->data=n;
    newnode->next=top;
    top=newnode;

}

void pop()
{
    if(isempty())
        cout<<"stack is empty"<<endl;
    else
    {
    node* temp;
    temp=top;
    top=top->next;
    free(temp);
    }
}

void display()
{
    node* temp;
    temp=top;
    cout<<"stack is: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}




int main()
{
     push(89);
     push(45);
     push(71);
     display();
     cout<<endl;
     pop();
     pop();
     push(52);
     push(63);
     display();

    return 0;
}
