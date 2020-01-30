#include <iostream>
using namespace std;

#define MAX 100

 class stack{
 private:
  int top;
  int s[MAX];
 public:

      stack()
      {
          top=-1;
      }

     int isempty()
     {
     if(top==-1)
        return true;
     else
        return false;
     }
     int isfull()
     {
         if(top==MAX-1)
            return false;
         else
            return true;
     }


     void push(int n)
     {
       if(isfull())
        {
       s[++top]=n;
        }
        else
            cout<<"Error:stack overflow"<<endl;
     }


     void pop()
     {
         if(isempty())
         cout<<"stack is empty"<<endl;
         else
         top--;

     }
     void display()
     {
         cout<<"Stack is "<<endl;
         for(int i=top;i>=0;i--)
         {
          cout<<s[i]<<" ";
         }
     }
 };
int main()
{
    stack s1;
    s1.push(5);
    s1.push(4);
    s1.push(7);
    s1.push(9);
    s1.display();
    s1.push(79);

    s1.pop();
    s1.pop();
    s1.push(17);
    cout<<endl;
    s1.display();
    return 0;
}
