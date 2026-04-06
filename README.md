# 🌳 Pointer-Based Binary Tree Analyzer 🌳

> A comprehensive C++ system for constructing, traversing, and analyzing non-linear data structures. This project builds a custom Binary Tree from preorder string representations and performs deep structural analysis using recursive pointer logic.

## 🎮 How to Play
*   **Build the Tree**: Enter a preorder string where characters represent nodes and periods (`.`) represent empty subtrees (e.g., `AB..C..`).
*   **View Traversal**: The system automatically prints the tree in **Preorder, Inorder, Postorder, and Level-order** formats.
*   **Structural Analysis**: The program calculates and displays the tree's height, total node count, and specific classifications.
*   **Validation**: The system checks if your input string is a mathematically valid representation of a binary tree before building.
*   **BST Check**: The engine determines if your custom tree happens to satisfy Binary Search Tree properties without using sorting shortcuts.

## ✨ Features
- **Dynamic Tree Construction**: Implements `BuildTree(string s)` to transform serialized preorder strings into a linked pointer structure.
- **Structural Intelligence**: Includes specialized functions to detect **Full Binary Trees** and **Complete Binary Trees**.
- **Multi-Level Traversal**: Features standard depth-first searches (DFS) and a breadth-first (Level-order) traversal.
- **Recursive Analysis**: Uses pure recursive logic for `height()`, `node_count()`, and `IsBST()` without relying on external libraries.
- **Error Resilience**: Robustly handles invalid tree strings and ensures no nodes contain the reserved `.` character.

## 🛠️ Tech Stack
- **Language**: C++
- **Data Structure**: Binary Tree (Linked Nodes/Pointers).
- **Dependencies**: Standard I/O and String handling libraries only.
- **Input Format**: 
    - **Tree String**: Preorder sequence with dots for nulls (e.g., `H.E.L.L.O..`).
    - **Allowed Characters**: Any single character except `.`.

## 🚀 Quick Start

### Compilation

If you have the files locally and the g++ compiler, first navigate to the file location and just run `g++ binaryFunctions.cpp binaryDriver.cpp -o [your_desired_file_name].exe`

To clone and run locally:
```bash
git clone https://github.com
cd binaryTrees
