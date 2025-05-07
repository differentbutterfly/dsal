#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int data){
        this->data=data;
        left=nullptr,right=nullptr;
    }
};

void traversal(Node *root){
    if(root == nullptr) return;

    cout<<root->data<<" ";
    traversal(root->left);
    traversal(root->right);
}

Node *insert(Node *&root,int x){
    if(root == nullptr){
        root = new Node( x);
    }
    else if(x >= root->data){
        root->right = insert(root->right,x);
    }
    else if(x <= root->data){
        root->left = insert(root->left,x);
    }
    return root;
}


int height(Node *root){
    if(root == nullptr) return 0;

    int leftSubTreeHeight = 1 + height(root->left);
    int rightSubTreeHeight = 1 + height(root->right);

    return max(leftSubTreeHeight,rightSubTreeHeight);
}

void search(Node *root,int key,bool present){
    if(root == nullptr) return ;

    if(root->data == key){
        present = true;
    }
    else if(key > root->data){
        search(root->right,key,present);
    }
    else if(key < root->data){
        search(root->left,key,present);
    }
}

void mirror(Node *root){
    if(root == nullptr) return;
    mirror(root->left);
    mirror(root->right);

    swap(root->left,root->right);
}


int minimum(Node *root){
    if(root == nullptr) return-1;
    if (root->left == nullptr){
        return root->data;
    }
    return minimum(root->left);
}



int main() {
Node *root = nullptr;
int ch;

do
{
    cout << "\nBinary Search Tree Operations Menu:\n";
        cout << "1. Insert a node\n";   //
        cout << "2. Display (Preorder Traversal)\n";//
        cout << "3. Find height of the tree\n";//
        cout << "4. Find minimum value in the tree\n";//
        cout << "5. Search for a value\n";//
        cout << "6. Mirror the tree\n";//
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        
        switch (ch)
        {
        case 0:
            break;
        case 1:
            /* insert new node */
            int element;
            cout<<"Enter value for new node"<<endl;
            cin>>element;
            insert(root,element);
            cout<<"Element added to tree"<<endl;
            break;
        case 2:
            cout<<"traversal in preorder \n";
            traversal(root);
            break;
        
        case 3:
            cout<<"max height if tree: "<<height(root)<<endl;
            
            break;

        case 4:
        cout<<"min element in tree: " <<minimum(root);
        break;
        
        case 5:
            int key;
            cout<<"Enter the element to search\n";
            cin>>key;
            bool present;
            search(root,key,present);
            if(present){
                cout<<"Key is present in BST \n";
            }else{
                cout<<"Key not is present in BST \n";
            }
            break;
        case 6:
        mirror(root);
        cout << "The BST has been mirrored.\n";
        break;

        default:
        cout << "Invalid choice. Please try again.\n";
            break;
        }
} while (ch != 0);

   return 0;
}