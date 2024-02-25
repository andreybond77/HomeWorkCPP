
#include <iostream>
using namespace std;

struct Node {
    int key;
    struct Node* left, * right;
};


Node* newNode(int item)
{
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


void showAll(Node* root)
{
    if (root != NULL) {
        showAll(root->left);
        cout<< " " << root->key;
        showAll(root->right);
    }
}


Node* insert(Node* node, int key)
{
   
    if (node == NULL)
        return newNode(key);

   
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

   
    return node;
}


Node* deleteNode(Node* root, int k)
{
    
    if (root == NULL)
        return root;

    
    if (root->key > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->key < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }

    
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    
    else {

        Node* succParent = root;

      
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        
        root->key = succ->key;

        
        delete succ;
        return root;
    }
    
}


int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 33);
    root = insert(root, 57);
    root = insert(root, 45);
    root = insert(root, 73);
    root = insert(root, 69);

   
    showAll(root);
    cout << endl;
    
    root = deleteNode(root,57 );
    showAll(root);
    cout << endl;

    return 0;
}