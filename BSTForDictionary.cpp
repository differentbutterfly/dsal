#include <iostream>
#include <string>
using namespace std;

struct Node {
    Node *left, *right;
    string word, meaning;

    Node(string word, string meaning) {
        this->word = word;
        this->meaning = meaning;
        left = nullptr;
        right = nullptr;
    }
};

// Insert a word-meaning pair into the BST
Node* insert(Node* root, string word, string meaning) {
    if (root == nullptr) {
        root = new Node(word, meaning);
    } else if (word < root->word) {
        root->left = insert(root->left, word, meaning);
    } else {
        root->right = insert(root->right, word, meaning);
    }
    return root;
}

// Update the meaning of an existing word
void updateMeaning(Node* root, string word, string newMeaning) {
    if (root == nullptr) {
        cout << "Keyword not found\n";
        return;
    }
    if (word < root->word) {
        updateMeaning(root->left, word, newMeaning);
    } else if (word > root->word) {
        updateMeaning(root->right, word, newMeaning);
    } else {
        root->meaning = newMeaning;
        cout << "Meaning updated\n";
    }
}

// Display dictionary in ascending order
void displayInAsc(Node* root) {
    if (root != nullptr) {
        displayInAsc(root->left);
        cout << root->word << " ---> " << root->meaning << endl;
        displayInAsc(root->right);
    }
}

// Display dictionary in descending order
void displayInDec(Node* root) {
    if (root != nullptr) {
        displayInDec(root->right);
        cout << root->word << " ---> " << root->meaning << endl;
        displayInDec(root->left);
    }
}

// Find the number of comparisons to search a word
int maxComparisions(Node* root, string word) {
    int count = 0;
    while (root != nullptr) {
        count++;
        if (word == root->word) {
            return count;
        } else if (word < root->word) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return 0; // Not found
}

// Find minimum node (used in deletion)
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Delete a word from the BST
Node* deleteWord(Node* root, string word) {
    if (root == nullptr) return root;

    if (word < root->word) {
        root->left = deleteWord(root->left, word);
    } else if (word > root->word) {
        root->right = deleteWord(root->right, word);
    } else {
        // Node found: handle deletion cases

        // Case 1: Only right child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: Only left child
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->word = temp->word;
        root->meaning = temp->meaning;
        root->right = deleteWord(root->right, temp->word);
    }

    return root;
}

// MAIN
int main() {
    Node* root = nullptr;
    string word, meaning, newMeaning;
    int choice, comparisons;

    do {
        cout << "\nDictionary Menu:\n";
        cout << "1. Add New Keyword\n";//
        cout << "2. Delete Keyword\n";//
        cout << "3. Update Meaning\n";//
        cout << "4. Display Ascending\n";//
        cout << "5. Display Descending\n";//
        cout << "6. Find Max Comparisons\n";//
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                break;

            case 1:
                cout << "Enter word: ";
                cin >> word;
                cout << "Enter meaning: ";
                cin.ignore(); // flush newline
                getline(cin, meaning);
                root = insert(root, word, meaning);
                break;

            case 2:
                cout << "Enter word to delete: ";
                cin >> word;
                root = deleteWord(root, word);
                cout << "Word deleted (if existed).\n";
                break;

            case 3:
                cout << "Enter word to update: ";
                cin >> word;
                cin.ignore();
                cout << "Enter new meaning: ";
                getline(cin, newMeaning);
                updateMeaning(root, word, newMeaning);
                break;

            case 4:
                cout << "Dictionary in Ascending Order:\n";
                displayInAsc(root);
                break;

            case 5:
                cout << "Dictionary in Descending Order:\n";
                displayInDec(root);
                break;

            case 6:
                cout << "Enter word to search: ";
                cin >> word;
                comparisons = maxComparisions(root, word);
                if (comparisons > 0) {
                    cout << "Comparisons required: " << comparisons << endl;
                } else {
                    cout << "Keyword not found\n";
                }
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
