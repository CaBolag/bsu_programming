#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

class Node {
private:
    Node* left_ = nullptr;
    Node* right_ = nullptr;
    int key_;
public:
    Node* GetLeft() {
        return left_;
    }

    Node* GetRight() {
        return right_;
    }

    int GetKey() {
        return key_;
    }

    void SetRight(Node* right) {
        right_ = right;
    }

    void SetLeft(Node* left) {
        left_ = left;
    }

    Node(int key) :key_(key) {};
};


class BinarySearchTree {
public:
    BinarySearchTree() = default;
    ~BinarySearchTree();

    Node* GetRoot();
    void Insert(int key);
    void PreOrderTraversal(Node* node, std::vector<int>& keys);

private:
    Node* root_ = nullptr;
    void DestroyNode(Node* node);
};


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    BinarySearchTree bts;
    int value;
    while (std::cin >> value) {
        bts.Insert(value);
    }

    std::vector<int> keys;
    bts.PreOrderTraversal(bts.GetRoot(),keys);
    int index=0;
    while (index < keys.size()) {
        std::cout << keys[index]<<"\n";
        index++;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}


BinarySearchTree::~BinarySearchTree() {
    DestroyNode(root_);
}

void BinarySearchTree::DestroyNode(Node* node) {
    if (node) {
        DestroyNode(node->GetLeft());
        DestroyNode(node->GetRight());
        delete node;
    }
}


Node* BinarySearchTree::GetRoot() {
    return root_;
}

void BinarySearchTree::Insert(int key) {
    if (root_ == nullptr) {
        root_ = new Node(key);
        return;
    }

    Node* current = root_;
    while (current) {
        if (current->GetKey() < key) {
            if (!current->GetRight()) {
                current->SetRight(new Node(key));
                return;
            }
            current = current->GetRight();
        }
        else {
            if (!current->GetLeft()) {
                current->SetLeft(new Node(key));
                return;
            }
            current = current->GetLeft();
        }
    }
}

void BinarySearchTree::PreOrderTraversal(Node* node, std::vector<int>& keys) {
    if (!node) {
        return;
    }
    keys.push_back(node->GetKey());
    PreOrderTraversal(node->GetLeft(),keys);
    PreOrderTraversal(node->GetRight(),keys);
}