#include <iostream>
#include <string>
#include "binaryTrees.h"
using namespace std;

//----------------------------------------------------------------------------------------
// This function will recursively read the string and build the tree based on the preorder
//----------------------------------------------------------------------------------------

BinaryTree buildTree (string& s)
{
    if (s.empty()) return nullptr;
    
    char c = s[0];
    s.erase(0,1);

    if (c == '.') return nullptr;

    BinaryTree root = new TreeNode;
    root->data = c;
    root->left = buildTree(s);
    root->right = buildTree(s);

    return root;
}

//------------------------------------------------------------------------------------------------
// Check for the 4 cases. left child no right, right child no left, both children, and no children
//------------------------------------------------------------------------------------------------

bool isBST (BinaryTree T)
{
    if (!T || (!T->left && !T->right)) return true;
    else
    {
        if ((T->left && T->left->data < T->data) && !T->right) return isBST (T->left);
        else if ((T->right && T->right->data > T->data) && !T->left) return isBST (T->right);
        else if ((T->left && T->left->data < T->data) && (T->right && T->right->data > T->data))
        return isBST (T->left) && isBST (T->right);
        else return false;
    } 
}


//-------------------------------------------------------------------------------
// Because I keep track of how many nodes are in the list, I can just return size O(n)
//-------------------------------------------------------------------------------

int node_count (BinaryTree T)
{
    if (!T) return 0;
    else return (node_count (T->left) + node_count (T->right) + 1);
}


//---------------------------------------------------------------------------------
// Checks the height of the left and right subtree and returns the max between them O(n)
//---------------------------------------------------------------------------------

int height (BinaryTree T)
{
    return (!T ? 0 : max(height(T->left), height(T->right)) + 1);
}


//-------------------------------------------------------------------------------
// The tree is full if the node count is equal to 2^k - 1 with k being the height O(n)
//-------------------------------------------------------------------------------

bool isFullBT (BinaryTree T)
{
    return (node_count(T) == pow(2, height(T)) - 1);
}


//------------------------------------------------------
// This function checks the complete structure of a tree O(n)
//------------------------------------------------------

bool isCompleteBT (BinaryTree T)
{
    return (BFS_count(T) == node_count(T));
}


//------------------------------------------------------------------------------------------------------------
// This does a breadth first search through the tree counting each node and stops when it first sees a nullptr O(n)
//------------------------------------------------------------------------------------------------------------

int BFS_count (BinaryTree T)
{
    if (!T) return 0;
    Queue<BinaryTree> q;

    q.enqueue(T);
    int count = 0;
    
    while (!q.isEmpty())
    {
        TreeNode* curr = q.dequeue();

        if (!curr) break;
        
        count++;
        q.enqueue(curr->left);
        q.enqueue(curr->right);
    }
    return count;
}


//-----------------------------------------------------------------------------------------------------------------------------
// This checks each node and ensures it has two children. If they don't or if there's children of a null root then return false
//-----------------------------------------------------------------------------------------------------------------------------

bool isValidTree (string s)
{
    if (s.empty()) return true;
    
    int emptyNodes = 1;

    while (!s.empty())
    {
        
        char c = s[0];
        s.erase(0,1);
        
        if (emptyNodes <= 0) 
        {
            cout << "Invalid input." << endl;
            return false;
        }

        if (isAlNum(c)) emptyNodes++; 
        else if (c == '.') emptyNodes--;
        else
        {
            cout << "Invalid input." << endl;
            return false;
        }
    }

    if (emptyNodes == 0) return true;
    else
    {
        cout << "Invalid input." << endl;
        return false;
    }
}


//---------------------
// Prints the pre order O(n)
//---------------------

void preOrder (BinaryTree T)
{
    if (!T) cout << ".";
    else
    {
        cout << T->data;
        preOrder(T->left);
        preOrder(T->right);
    }
}


//--------------------
// Prints the in order O(n)
//--------------------

void inOrder (BinaryTree T)
{
    if (!T) cout << ".";
    else
    {
        inOrder(T->left);
        cout << T->data;
        inOrder(T->right);
    }
}


//----------------------
// Prints the post order O(n)
//----------------------

void postOrder (BinaryTree T)
{
    if (!T) cout << ".";
    else
    {
        postOrder(T->left);
        postOrder(T->right);
        cout << T->data;
    }
}


//------------------------------------------------------------------------
// This returns true if the character is an uppercase or lowercase letter
//------------------------------------------------------------------------

bool isAlpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}


//-----------------------------------------------
// This returns true if the character is a digit
//-----------------------------------------------

bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}


//------------------------------------
// Checks if the value is alphanumeric
//------------------------------------

bool isAlNum (char c)
{
    return isAlpha(c) || isDigit(c);
}


//------------------------
// Finds the maximum value O(1)
//------------------------

int max (int a, int b)
{
    return (a <= b ? b : a);
}


//---------------------------------
// This returns a to the power of b O(logn)
//---------------------------------

int pow (int a, int b) 
{
    if (b == 0) return 1;
    if (b % 2 == 0)
    {
        int half = pow (a, b / 2);
        return half * half;
    } 
    else
    {
        return a * pow (a, b - 1);
    }
}

//==========================================================================================
