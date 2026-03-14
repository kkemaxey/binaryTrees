#ifndef BINARYTREES_H
#define BINARYTREES_H
using namespace std;

struct TreeNode
{
    char data;
    TreeNode* left;
    TreeNode* right;
};

typedef TreeNode* BinaryTree;

BinaryTree buildTree (string&);
bool isBST (BinaryTree);
int node_count (BinaryTree);
int height (BinaryTree);
bool isFullBT (BinaryTree);
bool isCompleteBT (BinaryTree);
int BFS_count (BinaryTree);
bool isValidTree (string);
void preOrder (BinaryTree);
void inOrder (BinaryTree);
void postOrder (BinaryTree);
bool isAlpha(char);
bool isDigit(char);
bool isAlNum(char);
int max(int, int);
int pow (int, int);

template <typename XType>
class Queue
{
    private:
        struct Qnode
        {
            XType data;
            Qnode* next;
        };

        Qnode* front;
        Qnode* back;
        int size;
        
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        bool isFull();
        void enqueue(XType);
        XType dequeue();
};

#include "queue.tpp"
#endif