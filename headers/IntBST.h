#ifndef INTBST_H
#define INTBST_H

#include <iostream>

class IntBST{
    public:
        IntBST();
        ~IntBST();
        IntBST(const IntBST& other); 

        bool isEmpty() const;
        void destroyTree();
        IntBST& operator=(const IntBST& other);

        void inOrderTraversal() const;
        void preOrderTraversal() const;
        void postOrderTraversal() const;

        bool insert(const int& item);
        void search(const int& target) const;
        bool deleteNode(const int& deleteTarget);
    private:
        struct Node{
            int data;
            Node* left;
            Node* right;

            Node(int val);
        };

        Node* root;

    private:
        void destroyTreeHelper(Node* node);

        bool insertHelper(Node*& node, const int& item);
        bool searchHelper(const Node* node, const int& target) const;
        bool deleteNodeHelper(Node*& node, const int& deleteTarget);

        void inOrderTraverse(Node* node) const;
        void preOrderTraverse(Node* node) const;
        void postOrderTraverse(Node* node) const;

        Node* findMin(Node* node) const;
        Node* copyTree(const Node* other) const;
        void traverse(void (IntBST::* funcPtr)(Node*) const) const;
};

#endif