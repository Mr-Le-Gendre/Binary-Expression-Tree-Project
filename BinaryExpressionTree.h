#ifndef BINARY_EXPRESSION_TREE_H
#define BINARY_EXPRESSION_TREE_H

#include "BinaryTree.h"
#include <stack>
#include <string>
#include <iostream>
#include <cctype>
#include <cmath>

class binaryExpressionTree : public binaryTreeType<std::string> {
public:
    binaryExpressionTree() : binaryTreeType<std::string>() {}

    void buildExpressionTree(const std::string& postfixExpression);

    double evaluateExpressionTree() const {
        return evaluateExpressionTree(root);
    }

    void inorderTraversal() const override {
        inorder(root);
    }

    void preorderTraversal() const override {
        preorder(root);
    }

    void postorderTraversal() const override {
        postorder(root);
    }

    void search(const std::string& searchItem) const override {}
    void insert(const std::string& insertItem) override {}
    void deleteNode(const std::string& deleteItem) override {}

private:
    bool isOperator(const std::string& token) const;
    double applyOperator(double operand1, double operand2, const std::string& op) const;
    double evaluateExpressionTree(nodeType<std::string>* node) const;

    void inorder(nodeType<std::string>* p) const;
    void preorder(nodeType<std::string>* p) const;
    void postorder(nodeType<std::string>* p) const;
};

#endif // BINARY_EXPRESSION_TREE_H
