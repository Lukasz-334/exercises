#include <cmath>
#include <iostream>
class Node {
public:
    Node(int d) {
        data = d;
        node_counter++;
        left = nullptr;
        right = nullptr;
    }
    ~Node() {
        delete left;
        delete right;
    }

    void add(Node* node, int value);
    int height(Node* node);
    void print(Node* node);

    Node* left;
    Node* right;

    int level_counter = 0;
    int data;

    static int node_counter;
};

int Node::node_counter = 0;

void Node::add(Node* node, int value) {
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

int Node::height(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);
    return std::max(left, right)+1;
}

void Node::print(Node* node) {
    if (node->left != nullptr) {
        print(node->left);
    }
    
    if (node->right != nullptr) {
        print(node->right);
    }
    std::cout << node->data << '\n';
}

int main() {
    Node root(8);
    Node* wsk = &root;

  //  root.add(wsk, 10);
  //  root.add(wsk, 5);
  //  root.add(wsk, 2);
  //  root.add(wsk, 7);
  //  root.add(wsk, 12);
  //  root.add(wsk, 9);
  //  root.add(wsk, 15);
    std::cout << std::endl;

    root.print(wsk);
    std::cout << std::endl;
    std::cout << "number of nodes " << root.node_counter;
    std::cout << std::endl;
    std::cout << "height "<<root.height(wsk) << std::endl;

    return 0;
}
