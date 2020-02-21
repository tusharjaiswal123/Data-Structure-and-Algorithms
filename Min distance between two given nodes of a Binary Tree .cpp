Node * lca(Node * root,int a,int b)
   {
       if(root==NULL)
       return NULL;
       
       if(root->data==a || root->data==b)
       return root;
       
       Node *left=lca(root->left,a,b);
       Node *right=lca(root->right,a,b);
       
       if(left!=NULL && right!=NULL)
       return root;
       
       else
       {
           if(left)
           return left;
           else
           return right;
       }
   }
   
   int findlevel(Node *p,int a,int level)
   {    
       if(p==NULL)
       return -1;
       
       if(p->data==a)
       return level;
       
       int left=findlevel(p->left,a,level+1);
       if(left==-1)
       return findlevel(p->right,a,level+1);
       else
       return left;
       
   }
int findDist(Node* root, int a, int b)
{
    Node *p=lca(root,a,b);
    
    int d1=findlevel(p,a,0);
    int d2=findlevel(p,b,0);
    
    return d1+d2;
    
}
