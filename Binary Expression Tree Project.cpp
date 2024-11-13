#include "BinaryExpressionTree.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream inputFile("RpnData.txt");
    std::ofstream outputFile("Results.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string postfixExpression;
    binaryExpressionTree expressionTree;

    while (getline(inputFile, postfixExpression)) {
        expressionTree.buildExpressionTree(postfixExpression);
        double result = expressionTree.evaluateExpressionTree();
        outputFile << "Postfix: " << postfixExpression << "\n";
        outputFile << "Result: " << result << "\n\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
