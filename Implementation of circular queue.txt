#include <iostream>
using namespace std;

#define MAX 5
class queue{
private:
    int a[MAX];
    int Front,rear;
public:
    queue()
    {
        Front=rear=-1;
    }
    int isempty()
    {
        if(Front==-1&&rear==-1)
            return true;
        else
            return false;
    }
    int isfull()
    {
        if((rear+1)%MAX==Front)
            return true;
        else
            return false;
    }
    void Enqueue(int n)
    {
        if(isfull())
            cout<<"Queue is full"<<endl;
        else if(isempty())
        {
            Front=0;
            rear=0;
        }
        else
        {
            rear=(rear+1)%MAX;
        }
        a[rear]=n;

    }

    void Dequeue()
    {
        if(isempty())
            cout<<"Queue is empty"<<endl;
        else if(Front==rear)
        {
            Front=rear=-1;
        }
        else
        {
            Front=(Front+1)%MAX;
        }
    }
    int top()
    {
        if(isempty())
        {
            cout<<"Queue is empty"<<endl;

        }
        else
            return a[Front];
    }
    void display()
    {
        if(isempty())
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {   int  c=(rear+MAX-Front)%MAX+1;
            for(int i=0;i<c;i++)
            {
                int index=(Front+i)%MAX;
                cout<<a[index]<<" ";
            }
        }
    }


};
int main()
{
    queue a;
    a.Enqueue(1);
    a.Enqueue(6);
    a.Enqueue(8);
    a.Enqueue(3);
    a.Enqueue(23);
    a.display();
    cout<<endl;
    a.Dequeue();
    a.Enqueue(4);
    a.display();


    return 0;
}
