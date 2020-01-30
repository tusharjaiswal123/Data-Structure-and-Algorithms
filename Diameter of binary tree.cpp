int height(Node *node)
{
if(node==NULL) return 0;
return max(height(node->left),height(node->right))+1;
}

int diameter(Node *node)
{
if(node==NULL) return 0;
return max(height(node->left)+height(node->right)+1,max(diameter(node->left),diameter(node->right)));
}
