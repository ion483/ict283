#include "IntBST.h"

IntBST::IntBST(): root(nullptr){}

IntBST::~IntBST(){
    destroyTree();
}

IntBST::IntBST(const IntBST& other): root(nullptr){
    Node* newNode = copyTree(other.root);
    root = newNode;
}

IntBST::Node::Node(int val): data(val), left(nullptr), right(nullptr){}

IntBST::Node* IntBST::copyTree(const Node* other) const{
    if(other == nullptr){
        return nullptr;
    }
    Node* newNode = new Node(other->data);
    newNode->left = copyTree(other->left);
    newNode->right = copyTree(other->right);
    return newNode;
}

bool IntBST::isEmpty() const{
    return root == nullptr;
}

void IntBST::destroyTree(){
    destroyTreeHelper(root);
    root = nullptr;
}

void IntBST::destroyTreeHelper(Node* node){
    if(node == nullptr){
        return;
    }
    destroyTreeHelper(node->left);
    destroyTreeHelper(node->right);
    delete node;
}
        
IntBST& IntBST::operator=(const IntBST& other){
    if(this != &other){
        destroyTree();
        root = copyTree(other.root);
    }
    return *this;
}

bool IntBST::insert(const int& item){
    bool result = insertHelper(root, item);
    return result;
}

bool IntBST::insertHelper(Node*& node, const int& item){
    if(node == nullptr){
        Node* newNode = new Node(item);
        node = newNode;
        return true;
    }
    else if(item < node->data) return insertHelper(node->left, item);
    else if(item > node->data) return insertHelper(node->right, item);
    else return false;
}

void IntBST::search(const int& target) const{
    bool isFound = searchHelper(root, target);
    if(isFound) std::cout << target << " is found\n";
    else std::cout << target << " is not found\n";
}

bool IntBST::searchHelper(const Node* node, const int& target) const{ /*can not use const Node*& node here in const member function becuase it doesnt guerantee it wont make root point to other data*/
    if(node == nullptr){
        return false;
    }
    if(target == node->data) return true;
    else if(target < node->data) return searchHelper(node->left, target);
    else if(target > node->data) return searchHelper(node->right, target);
}

bool IntBST::deleteNode(const int& deleteTarget){
    bool result = deleteNodeHelper(root, deleteTarget);
    return result;
}

bool IntBST::deleteNodeHelper(Node*& node, const int& deleteTarget){
    if(node == nullptr){
        return false;
    }
    if(deleteTarget < node->data) return deleteNodeHelper(node->left, deleteTarget);
    if(deleteTarget > node->data) return deleteNodeHelper(node->right, deleteTarget);
    if(deleteTarget == node->data){
        if(node->left == nullptr && node->right == nullptr){
            delete node;
            node = nullptr;
            return true;
        }else if(node->right == nullptr){
            Node* tempNode = node;
            node = node->left;
            delete tempNode;
            return true;
        }else if(node->left == nullptr){
            Node* tempNode = node;
            node = node->right;
            delete tempNode;
            return true;
        }else{
            Node* minNode = findMin(node->right);
            node->data = minNode->data;
            deleteNodeHelper(node->right, minNode->data);
            return true;
        }
    }
}

IntBST::Node* IntBST::findMin(Node* node) const{
    if(node == nullptr){
        return node;
    }
    if(node->left == nullptr){
        return node;
    }
    return findMin(node->left);
}

void IntBST::traverse(void (IntBST::* funcPtr)(Node*) const) const{
    (this->*funcPtr)(root);
}

void IntBST::inOrderTraversal() const{
    traverse(&IntBST::inOrderTraverse);
    std::cout << '\n';
}

void IntBST::inOrderTraverse(Node* node) const{
    if(node == nullptr){
        return;
    }
    inOrderTraverse(node->left);
    std::cout << node->data << " ";
    inOrderTraverse(node->right);
}

void IntBST::preOrderTraversal() const{
    traverse(&IntBST::preOrderTraverse);
    std::cout << '\n';
}

void IntBST::preOrderTraverse(Node* node) const{
    if(node == nullptr){
        return;
    }
    std::cout << node->data << " ";
    preOrderTraverse(node->left);
    preOrderTraverse(node->right);
}

void IntBST::postOrderTraversal() const{
    traverse(&IntBST::postOrderTraverse);
    std::cout << '\n';
}

void IntBST::postOrderTraverse(Node* node) const{
    if(node == nullptr){
        return;
    }
    postOrderTraverse(node->left);
    postOrderTraverse(node->right);
    std::cout << node->data << " ";
}





       

        
       