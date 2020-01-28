#include<iostream>
#include<queue>
using namespace std;

struct BSTNode{
int data;
BSTNode *left;
BSTNode *right;
};

BSTNode* Find(BSTNode* root,int data)
{
    if(root==NULL)
        return(NULL);
    if(data<root->data)
        return Find(root->left,data);
    else if(data>root->data)
        return Find(root->right,data);
    return root;

}

void Insert(BSTNode *root,int data)
{
    BSTNode *par;
    BSTNode *node=new BSTNode();

    node->data=data;
    node->left=NULL;
    node->right=NULL;

    if(root==NULL)
        root=node;
    else
    {
        par=root;
    while(par!=NULL)
    {
        if(par->data>data)
        {
            if(par->left==NULL)
                par->left=node;
            par=par->left;
        }
        else if(par->data<data)
        {
            if(par->right==NULL)
                par->right=node;
            par=par->right;
        }
    }

    }

}

BSTNode* minValueNode(BSTNode* node)
{
    BSTNode* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}


BSTNode * Delete(BSTNode* root,int data)
{
    BSTNode* temp;
    if(root==NULL)
        cout<<"NO such element exist"<<endl;
    else if(data<root->data)
        root->left=Delete(root->left,data);
    else if(data>root->data)
        root->right=Delete(root->right,data);
    else
    {
        if(root->left && root->right)
        {
            temp=minValueNode(root->left);
            root->data=temp->data;
            root->left=Delete(root->left,root->data);
        }
        else
        {
            temp=root;
            if(root->left==NULL)
                root=root->right;
            if(root->right==NULL)
                root=root->left;
            free(temp);
        }
    }
    return(root);
}


void preorder(BSTNode *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}


void Inorder(BSTNode *root)
{
	if(root)
	{
		preorder(root->left);
		cout<<root->data<<" ";
		preorder(root->right);
	}
}


void postorder(BSTNode *root)
{
	if(root)
	{
		preorder(root->left);
		preorder(root->right);
		cout<<root->data<<" ";
	}
}

void levelorder(BSTNode *root)
{
	queue<BSTNode *> q;
	q.push(root);


	while(q.empty()==false)
	{
	    BSTNode *temp=q.front();
	    cout<<temp->data<<" ";
	    q.pop();


	    if(temp->left!=NULL)
            q.push(temp->left);

        if(temp->right!=NULL)
            q.push(temp->right);

	}
}


int main()
{
    BSTNode *r;
    r=NULL;
    Insert(r,50);
    Insert(r,40);
    Insert(r,20);
    Insert(r,30),
    Insert(r,60);
    Insert(r,70);
    Inorder(r);
    cout<<endl;
    Delete(r,50);
    Inorder(r);
    cout<<endl;
    preorder(r);
    cout<<endl;
    postorder(r);
    cout<<endl;

    levelorder(r);


    return 0;
}
