#ifndef BST_H
#define BST_H

#include "Vector.h"
#include "Collection.h"
#include "Utility.h"
#include <cmath>

/**
 * @class BST
 * @brief Binary search tree with various functions
 * @tparam B The element datatype stored in the BST
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */

template <class B>
class BST{
    private:

        /**
         * @struct Node
         * @brief Represents a node in the BST.
         */
        struct Node{
            B data; /**< The value stored in the node*/
            Node* left; /**< Pointer to the left child node */
            Node* right; /**< Pointer to the right child node */

            /**
             * @brief Constructor initializes the node with a given value
             * @param val The value to store in the node
             * @return void
             */
            Node(B val);
        };

        Node* root; /**< The pointer that represents as the start of the bst*/
        int count; /**< Number of nodes in bst */

    public:

        /**
         * @brief Function creates a balanced bst object from the given vector
         * @param v The vector that will be used to build the bst
         * @return A bst object that is balanced
         */
        static BST buildBalancedBST(const Vector<B>& v);

        /**
         * @brief Function balances the structure of the current tree
         * @return void
         */
        void balanceItSelf();

        /**
         * @brief Function that collects node data to a Collection object using function pointer
         * @param c A Collection object
         * @param funcPtr A function pointer
         * @return void
         */
        void inOrderTraversalCollect(Collection<B>& c, void (Collection<B>::* funcPtr)(const B&)) const;

        /**
         * @brief Default constructor initializes the bst to default value
         * @return void
         */
        BST();

        /**
         * @brief Destructor destroys tree
         * @return void
         */
        ~BST();

        /**
         * @brief Copy constructor copies from other bst
         * @return void
         */
        BST(const BST& other);

        /**
         * @brief Checks if the bst is empty
         * @return True ifbst is empty, false otherwise
         */
        bool isEmpty() const;

        /**
         * @brief Clears the current tree
         * @return void
         */
        void destroyTree();

        /**
         * @brief Assignment operator
         * @param other Other bst to copy from
         * @return Reference to this bst
         */
        BST& operator=(const BST& other);

        /**
         * @brief Inserts a new node to the bst
         * @param item The item to be added to the bst
         * @return bool
         */
        bool insert(const B& item);

        /**
         * @brief Searches for a node with specified target
         * @param target The target to search for
         * @return void
         */
        bool search(const B& target) const;

        /**
         * @brief Deletes a node with the specified target
         * @param deleteTarget The target to delete
         * @return bool
         */
        bool deleteNode(const B& deleteTarget);

        /**
         * @brief Performs in-order traversal to display elements
         * @return void
         */
        void inOrderTraversal() const;

        /**
         * @brief Performs pre-order traversal to display elements
         * @return void
         */
        void preOrderTraversal() const;

        /**
         * @brief Performs post-order traversal to display elements
         * @return void
         */
        void postOrderTraversal() const;

        /**
         * @brief Retrieves the size of the bst
         * @return An int as the size
         */
        int size() const;
    
    private:

        /**
         * @brief Creates a new balanced bst node from given sorted vector
         * @param sortedV Reference to the sorted vector
         * @param start The start position of the vector
         * @param end The end position of the vector
         * @return A new balanced Node object 
         */
        static Node* buildBalancedBSTHelper(const Vector<B>& sortedV, int start, int end);
        
        /**
         * @brief Helper function replaces the crurrent bst with a new balanced bst
         * @param node Reference to the node to be balanced
         * @return void
         */
        void balanceItSelfHelper(Node*& node);

        /**
         * @brief Helper function uses in-order traversal to collect element to a Collection object using function pointer
         * @param node The starting root node
         * @param c Reference to the Collection object
         * @param funcPtr Function pointer
         * @return void
         */
        void inOrderTraversalCollectHelper(const Node* node, Collection<B>& c, void (Collection<B>::*& funcPtr)(const B&)) const;
        
        /**
         * @brief Helper function clears the given node of a bst
         * @param node The node to be cleared
         * @return void
         */
        void destroyTreeHelper(Node* node);

        /**
         * @brief Helper function finds the node with minimum value in a subtree
         * @param node The starting node
         * @return A Node pointer to the minimum node
         */
        Node* findMin(Node* node) const;

        /**
         * @brief Helper function copies from a given node
         * @param node The starting node to be copied
         * @return A Node pointer to the new copied node
         */
        Node* copyTree(const Node* node) const;

        /**
         * @brief Helper function inserts a new element into the bst
         * @param node Reference to the starting node
         * @param item Reference to the item to be inserted
         * @return True if the item is inserted, false otherwise
         */
        bool insertHelper(Node*& node, const B& item);

        /**
         * @brief Helper function searches for a target element in the bst
         * @param node Reference to the starting node
         * @param target Reference to the target to be searched for
         * @return True if the target is found, false otherwise
         */
        bool searchHelper(const Node* node, const B& target) const;

        /**
         * @brief Helper function deletes a target element in the bst
         * @param node Reference to the starting node
         * @param deleteTarget Reference to the delete target
         * @return True if target is deleted, false otherwise
         */
        bool deleteNodeHelper(Node*& node, const B& deleteTarget);

        /**
         * @brief Helper function uses function pointer to perform in, pre, or post-order display
         * @param funcPtr The function pointer
         * @return void
         */
        void traverse(void (BST::* funcPtr)(const Node*) const) const;

        /**
         * @brief Performs in-order traversal display
         * @param node Reference to the starting node
         * @return void
         */
        void inOrderTraverse(const Node* node) const;

        /**
         * @brief Performs pre-order traversal display
         * @param node Reference to the starting node
         * @return void
         */
        void preOrderTraverse(const Node* node) const;

        /**
         * @brief Performs post-order traversal display
         * @param node Reference to the starting node
         * @return void
         */
        void postOrderTraverse(const Node* node) const;

};

template <class B>
BST<B>::Node::Node(B val): data(val), left(nullptr), right(nullptr){}
        
template <class B>
BST<B>::BST(): root(nullptr), count(0){}

template <class B>
BST<B>::~BST(){destroyTree();}

template <class B>
BST<B>::BST(const BST& other): root(nullptr), count(0){
    root = copyTree(other.root);
    count = other.count;
}

template <class B>
BST<B>& BST<B>::operator=(const BST& other){
    if(this == &other){
        return *this;
    }else{
        destroyTreeHelper(root);
        root = copyTree(other.root);
        count = other.count;
        return *this;
    }
}

template <class B>
void BST<B>::destroyTree(){
    destroyTreeHelper(root);
    root = nullptr;
    count = 0;
}

template <class B>
void BST<B>::destroyTreeHelper(Node* node){
    if(node == nullptr){
        return;
    }
    destroyTreeHelper(node->left);
    destroyTreeHelper(node->right);
    delete node;
}

template <class B>
bool BST<B>::isEmpty() const{
    return root == nullptr && count == 0;
}

template <class B>
typename BST<B>::Node* BST<B>::findMin(Node* node) const{
    if(node == nullptr){
        return nullptr;
    }
    if(node->left == nullptr){
        return node;
    }
    return findMin(node->left);
}

template <class B>
typename BST<B>::Node* BST<B>::copyTree(const Node* node) const{
    if(node == nullptr){
        return nullptr;
    }
    if(node != nullptr){
        Node* newNode = new Node(node->data);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }
}

template <class B>
bool BST<B>::insert(const B& item){
    bool result = insertHelper(root, item);
    if(result) count++;
    return result;
}

template <class B>
bool BST<B>::insertHelper(Node*& node, const B& item){
    if(node == nullptr){
        node = new Node(item);
        return true;
    }
    else if(item < node->data) return insertHelper(node->left, item);
    else if(item > node->data) return insertHelper(node->right, item);
    else return false;
}

template <class B>
bool BST<B>::search(const B& target) const{
    bool isFound = searchHelper(root, target);
    return isFound;
}

template <class B>
bool BST<B>::searchHelper(const Node* node, const B& target) const{
    if(node == nullptr){
        return false;
    }
    if(target == node->data) return true;
    else if(target < node->data) return searchHelper(node->left, target);
    else if(target > node->data) return searchHelper(node->right, target);
}

template <class B>
bool BST<B>::deleteNode(const B& deleteTarget){
    bool result = deleteNodeHelper(root, deleteTarget);
    if(result) count--;
    return result;
}

template <class B>
bool BST<B>::deleteNodeHelper(Node*& node, const B& deleteTarget){
    if(node == nullptr){
        return false;
    }
    if(deleteTarget < node->data) return deleteNodeHelper(node->left, deleteTarget);
    else if(deleteTarget > node->data) return deleteNodeHelper(node->right, deleteTarget);
    else if(deleteTarget == node->data){
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

template <class B>
void BST<B>::traverse(void (BST::* funcPtr)(const Node*) const) const{
    (this->*funcPtr)(root);
}

template <class B>
void BST<B>::inOrderTraversal() const{
    std::cout << "inorder display: \n";
    traverse(&BST::inOrderTraverse);
    std::cout << '\n';
}

template <class B>
void BST<B>::inOrderTraverse(const Node* node) const{
    if(node == nullptr){
        return;
    }
    inOrderTraverse(node->left);
    std::cout << node->data << " ";
    inOrderTraverse(node->right);
}

template <class B>
void BST<B>::preOrderTraversal() const{
    std::cout << "preorder display: \n";
    traverse(&BST::preOrderTraverse);
    std::cout << '\n';
}

template <class B>
void BST<B>::preOrderTraverse(const Node* node) const{
    if(node == nullptr){
        return;
    }
    std::cout << node->data << " ";
    preOrderTraverse(node->left);
    preOrderTraverse(node->right);
}

template <class B>
void BST<B>::postOrderTraversal() const{
    std::cout << "postorder display: \n";
    traverse(&BST::postOrderTraverse);
    std::cout << '\n';
}

template <class B>
void BST<B>::postOrderTraverse(const Node* node) const{
    if(node == nullptr){
        return;
    }
    postOrderTraverse(node->left);
    postOrderTraverse(node->right);
    std::cout << node->data << " ";
}

template <class B>
int BST<B>::size() const{
    return count;
}

template <class B>
void BST<B>::inOrderTraversalCollect(Collection<B>& c, void (Collection<B>::* funcPtr)(const B&)) const{
    inOrderTraversalCollectHelper(root, c, funcPtr);
}

template <class B>
void BST<B>::inOrderTraversalCollectHelper(const Node* node, Collection<B>& c, void (Collection<B>::*& funcPtr)(const B&)) const{
    if(node == nullptr) return;
    inOrderTraversalCollectHelper(node->left, c, funcPtr);
    (c.*funcPtr)(node->data);
    inOrderTraversalCollectHelper(node->right, c, funcPtr);
}

template <class B>
void BST<B>::balanceItSelf(){
    balanceItSelfHelper(root);
}

template <class B>
void BST<B>::balanceItSelfHelper(Node*& node){
    Collection<B> c;
    void (Collection<B>::* funcPtr)(const B&) = &Collection<B>::collect;
    inOrderTraversalCollectHelper(node, c, funcPtr);

    Vector<B> collection;

    for(int i = 0; i<c.getSize(); i++){
        collection.Insert(c[i], collection.GetSize());
    }

    Node* balancedNode = BST<B>::buildBalancedBSTHelper(collection, 0, collection.GetSize()-1);
    destroyTreeHelper(node);
    node = balancedNode;
    count = collection.GetSize();
}

template <class B>
BST<B> BST<B>::buildBalancedBST(const Vector<B>& v){
    Utility u;
    Vector<B> sortedV = u.getSortedData(v);
    Vector<B> uniqueSortedV = u.getUniqueData(sortedV);
    Node* balancedNode = buildBalancedBSTHelper(uniqueSortedV, 0, uniqueSortedV.GetSize()-1);
    BST<B> balancedBST;
    balancedBST.root = balancedNode;
    balancedBST.count = uniqueSortedV.GetSize();
    return balancedBST;
}

template <class B>
typename BST<B>::Node* BST<B>::buildBalancedBSTHelper(const Vector<B>& uniqueSortedV, int start, int end){
    if(start > end){
        return nullptr;
    }
    int mid = start + (end-start)/2;
    Node* newNode = new Node(uniqueSortedV[mid]);
    newNode->left = buildBalancedBSTHelper(uniqueSortedV, start, mid-1);
    newNode->right = buildBalancedBSTHelper(uniqueSortedV, mid+1, end);
    return newNode;
}

#endif