#include <iostream>
using namespace std;

#define MAX 10
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
        if(rear==MAX-1)
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
            a[rear]=n;
        }
        else
        {
            rear++;
            a[rear]=n;
        }

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
            Front++;
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
        {
            for(int i=Front;i<=rear;i++)
                cout<<a[i]<<" ";
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
    a.display();
    cout<<endl;
    a.Dequeue();
    a.Enqueue(56);
    a.Enqueue(47);
    a.Dequeue();
    a.Dequeue();
    a.display();


    return 0;
}
