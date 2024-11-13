#include "BinaryExpressionTree.h"
#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <stdexcept>

void binaryExpressionTree::buildExpressionTree(const std::string& postfixExpression) {
    std::stack<nodeType<std::string>*> stack;
    std::stringstream ss(postfixExpression);
    std::string token;

    while (ss >> token) {
        if (isOperator(token)) {
            nodeType<std::string>* operand2 = stack.top(); stack.pop();
            nodeType<std::string>* operand1 = stack.top(); stack.pop();

            nodeType<std::string>* operatorNode = new nodeType<std::string>{ token, nullptr, nullptr };
            operatorNode->left = operand1;
            operatorNode->right = operand2;
            stack.push(operatorNode);
        }
        else {
            nodeType<std::string>* operandNode = new nodeType<std::string>{ token, nullptr, nullptr };
            stack.push(operandNode);
        }
    }

    root = stack.top(); // The last element will be the root of the tree.
    stack.pop();
}

bool binaryExpressionTree::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

double binaryExpressionTree::applyOperator(double operand1, double operand2, const std::string& op) const {
    if (op == "+") return operand1 + operand2;
    else if (op == "-") return operand1 - operand2;
    else if (op == "*") return operand1 * operand2;
    else if (op == "/") return operand1 / operand2;
    else throw std::invalid_argument("Invalid operator");
}

double binaryExpressionTree::evaluateExpressionTree(nodeType<std::string>* node) const {
    if (!node) return 0.0;

    // If the node is a leaf node (operand)
    if (node->left == nullptr && node->right == nullptr) {
        return std::stod(node->info);
    }

    // Otherwise, it's an operator node
    double operand1 = evaluateExpressionTree(node->left);
    double operand2 = evaluateExpressionTree(node->right);

    return applyOperator(operand1, operand2, node->info);
}

void binaryExpressionTree::inorder(nodeType<std::string>* p) const {
    if (p) {
        inorder(p->left);
        std::cout << p->info << " ";
        inorder(p->right);
    }
}

void binaryExpressionTree::preorder(nodeType<std::string>* p) const {
    if (p) {
        std::cout << p->info << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

void binaryExpressionTree::postorder(nodeType<std::string>* p) const {
    if (p) {
        postorder(p->left);
        postorder(p->right);
        std::cout << p->info << " ";
    }
}
