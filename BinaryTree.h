#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

template <typename elemType>
struct nodeType {
    elemType info;
    nodeType* left;
    nodeType* right;
};

template <typename elemType>
class binaryTreeType {
public:
    // Destructor definition moved here
    virtual ~binaryTreeType() {
        destroyTree(root);
    }

    // Destroy tree method moved here
    void destroyTree(nodeType<elemType>*& p) {
        if (p) {
            destroyTree(p->left);
            destroyTree(p->right);
            delete p;
            p = nullptr;
        }
    }

    virtual void inorderTraversal() const = 0;
    virtual void preorderTraversal() const = 0;
    virtual void postorderTraversal() const = 0;

    virtual void search(const elemType& searchItem) const = 0;
    virtual void insert(const elemType& insertItem) = 0;
    virtual void deleteNode(const elemType& deleteItem) = 0;

protected:
    nodeType<elemType>* root;
};

#endif
