#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

void add(Node* node, int value) {
    if (node->data != value) {
        if (node->data < value) {
            if (node->right == nullptr) {
                node->right = new Node(value);
            } else {
                return add(node->right, value);
            }
        }

        else {
            if (node->left == nullptr) {
                node->left = new Node(value);
            } else {
                return add(node->left, value);
            }
        }
    }
}

void print(Node* node) {
    if (node->left != nullptr) {
        print(node->left);
    }
    std::cout << node->data << '\n';
    if (node->right != nullptr) {
        print(node->right);
    }
}

void delete_tree(Node* node) {
   
    if (node->left != nullptr) {
        delete_tree(node->left);
    }
    
    if (node->right != nullptr) {
        delete_tree(node->right);
    }
    delete node;
   
}



int main() {
    Node* root = new Node(8);

    add(root, 10);
    std::cout << std::endl;
    add(root, 9);
    std::cout << std::endl;
    add(root, 15);
    std::cout << std::endl;
    add(root, 1);
    std::cout << std::endl;
    add(root, 2);
    std::cout << std::endl;
    add(root, 3);
    std::cout << std::endl;
    add(root, 4);
    std::cout << std::endl;

    print(root);
    delete_tree(root);
    

    return 0;
}