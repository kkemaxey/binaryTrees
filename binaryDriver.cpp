#include <iostream>
#include <string>
#include "binaryTrees.h"
using namespace std;

//-------------------------------------------------------------------------
// This will handle the input validation for the string and printing format
//-------------------------------------------------------------------------

int main()
{
    string userInput;
    
    do
    {
        cout << "Please enter the preorder of your tree -> ";
        getline(cin, userInput);
    } while (!isValidTree(userInput));

    BinaryTree tree;
    tree = buildTree(userInput);

    cout << endl;

    cout << "==========================================" << endl;
    cout << "DFS Prints: " << endl << endl;
    cout << "PreOrder: ";
    preOrder(tree);
    cout << endl;
    
    cout << "InOrder ";
    inOrder(tree);
    cout << endl;
    
    cout << "PostOrder: ";
    postOrder(tree);
    cout << endl;
    
    cout << "==========================================" << endl;
    cout << "Stats:" << endl << endl;
    cout << "Node Count: " << node_count(tree) << endl;
    cout << "Height: " << height(tree) << endl;
    
    
    cout << "==========================================" << endl;
    cout << "Tree Type:" << endl << endl;
    cout << "Binary Search Tree: ";
    if (isBST(tree)) cout << "True" << endl;
    else cout << "False" << endl;
    
    cout << "Complete Binary Tree: ";
    if (isCompleteBT(tree)) cout << "True" << endl;
    else cout << "False" << endl;
    
    cout << "Perfect Binary Tree: ";
    if (isFullBT(tree)) cout << "True" << endl;
    else cout << "False" << endl;
    cout << "==========================================" << endl;
    
    return 0;
}