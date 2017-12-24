/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
bool left(Node* root, int parentData)
{
   if(root)
   {
        if(root->data > parentData)
            return false;
        else
           return left(root->left,root->data) && right(root->right,root->data);
   }
    else
        return true;    
}
bool right(Node* root, int parentData)
{
    if(root)
    {
        if(root->data < parentData)
            return false;
        else
            return right(root->right,root->data) && left(root->left, root->data);
    }
    else
        return true;
}

bool checkBST(Node* root) {
    if(root)
          return left(root->left,root->data) && right(root->right,root->data);
    else
        return false;
   }
