PROBLEM:

Given An array of Alphabets and their frequency. Your task is to print all the given alphabets Huffman Encoding.
Note: If two elements have same frequency, then the element which if at first will be taken on left of Binary Tree and other one to right.
Input:
First line consists of test cases T. First line of every test case consists of string of alphabets and second line consists of its frequencies.
Output:
Print the HuffmanCodes in single line, with n spaces of each alphabet's HuffmanCodes respectively. In PreOrder form of Binary Tree.
Constraints:
1<=T<=100
1<=|String length|<=26
Example:
Input:
1
abcdef
5 9 12 13 16 45
Output:
0 100 101 1100 1101 111 


SOLUTION:

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};

class cmp
{   
    public:
    bool operator()(Node *a,Node *b)
    {
        return a->data > b->data;
    }
};

void print(Node *root,string s)
{
    if(root->left==NULL && root->right==NULL)
    {
        cout<<s<<" ";
        return;
    }
    print(root->left,s+"0");
    print(root->right,s+"1");
}

int main() {
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    string s;
	    cin>>s;
	    
	    int n,i;
	    n=s.length();
	    
	    int a[n];
	    priority_queue<Node*,vector<Node*>,cmp> p;
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	        Node *temp=new Node();
	        temp->data=a[i];
	        temp->left=NULL;
	        temp->right=NULL;
	        
	        p.push(temp);
	    }     
	    
	    while(p.size()!=1)
	    {
	        Node *u=p.top();
	        p.pop();
	        Node *v=p.top();
	        p.pop();
	        
	        Node *temp=new Node();
	        temp->data=u->data+v->data;
	        temp->left=u;
	        temp->right=v;
	        
	        p.push(temp);
	    }
	    
	    Node *root=p.top();
	    string str="";
	    print(root,str);
	    cout<<endl;
	    
	    
	    
	}
	
	
	return 0;
}
