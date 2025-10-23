#pragma once
#include <iostream>
#include <vector>

using datatype = int;

struct Node {
    datatype key;
    Node* parent;
    Node* left;
    Node* right;
    explicit Node(datatype k) : key(k), parent(nullptr), left(nullptr), right(nullptr) {}
};

// ===== Частина 1: звичайне бінарне дерево =====
void CreateTree(Node*& root, int n,
                const std::vector<datatype>* keys = nullptr,
                int* idx = nullptr);
// Відображення дерева (красиве ASCII): праве вгорі, ліве внизу
void ShowTree(const Node* root, int L = 0);
void PreOrder(const Node* root);
void InOrder(const Node* root);
void PostOrder(const Node* root);
void FreeTree(Node*& root);

// ===== Частина 2: BST =====
Node* CreateRootBST(datatype key);
Node* SearchNodeBST(Node* root, datatype key);
Node* InsertNodeBST(Node*& root, datatype key); // nullptr якщо дублікат
Node* MinimumNodeBST(Node* root);
Node* MaximumNodeBST(Node* root);
Node* SuccessorNodeBST(Node* pNode);
Node* PredecessorNodeBST(Node* pNode);
bool  DeleteNodeBST(Node*& root, Node* delNode);
