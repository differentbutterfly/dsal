#include <iostream>
using namespace std;
struct Node{
    Node *left,*right;
    int data;
    bool isThreaded;
    Node(int data){
        this->data = data;
        right = left = nullptr;
        isThreaded = false;
    }
};


Node *leftMost(Node *root){
    while(root && root->left){
        root = root->left;
    }
    return root;
}

void inOrderTraversal(Node *root){
    Node *curr = leftMost(root);

    cout<<"Inorder traversal of Threared bin tree \n";
    while(curr){
    cout<<curr->data<<" "<<endl;

    if(curr->isThreaded)
    curr = curr->right;

    else
    curr = leftMost(curr->right);
    }
    cout<<endl;
}


void binToThreadedHelper(Node *curr,Node *&prev){
    if(!curr) return ;
    
    binToThreadedHelper(curr->left,prev);

    if(prev && prev->right == nullptr){
        prev->right = curr;
        prev->isThreaded = true;
    }
    prev = curr;
    binToThreadedHelper(curr->right,prev);
}

void binToThreaded(Node *root){
    Node *prev = nullptr;
    binToThreadedHelper(root,prev);
}

void showThreads(Node *root){
    if(!root) return ;

    showThreads(root->left);
    if(root->isThreaded && root->right){
        cout<<"Thread from "<<root->data<<" to "<<root->right->data<<endl;
    }
    if(!root->isThreaded){
        showThreads(root->right);
    }

}

int main() {
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    
 

    binToThreaded(root);

    inOrderTraversal(root);

    showThreads(root);
   return 0;
}