/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        int maxHeight = 0;
        int leftHeight = 0, rightHeight = 0;
        if(root->right)
        {
            rightHeight++; // Ако съществува десен наследник увеличаваме височината от дясно с едно.
            rightHeight += height(root->right); // Добавяме височината на дясното под дърво.
        }
        if(root->left)
        {
            leftHeight++; // Ако съществува ляв наследник увеличаваме височината от ляво с едно.
            leftHeight += height(root->left); // Добавяме височината на лявото под дърво.
        }
        maxHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight; // Сравняваме ги и връщаме по-голямата.
        return maxHeight;
    }
