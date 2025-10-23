#include "Tree.h"
#include <iomanip>
#include <cassert>
#include <string>

static void buildTree(Node*& root, int n, const std::vector<datatype>& keys, int& idx) {
    if (n <= 0) { root = nullptr; return; }
    root = new Node(keys[idx++]);
    int n_left  = n / 2;
    int n_right = n - n_left - 1;
    buildTree(root->left,  n_left,  keys, idx);
    if (root->left)  root->left->parent  = root;
    buildTree(root->right, n_right, keys, idx);
    if (root->right) root->right->parent = root;
}

// ================= Частина 1: звичайне бінарне дерево =================

void CreateTree(Node*& root, int n, const std::vector<datatype>* keys, int* idx) {
    if (n <= 0) { root = nullptr; return; }
    if (keys && idx) {
        int localIdx = *idx;
        buildTree(root, n, *keys, localIdx);
        *idx = localIdx;
        return;
    }
    std::vector<datatype> autoKeys(n);
    for (int i = 0; i < n; ++i) autoKeys[i] = i + 1;
    int localIdx = 0;
    buildTree(root, n, autoKeys, localIdx);
}


// --- красивий друк дерева (праве піддерево зверху) ---
static void showPretty(const Node* node,
                       const std::string& prefix,
                       bool isLeft,
                       int depth)
{
    if (!node) return;

    // 1) Праве піддерево (малюється зверху)
    if (node->right) {
        // Для кореня НЕ додаємо відступ; з другого рівня додаємо звичні "│   " або "    "
        std::string nextPrefix = prefix + (depth > 0 ? (isLeft ? "│   " : "    ") : "");
        showPretty(node->right, nextPrefix, /*isLeft=*/false, depth + 1);
    }

    // 2) Поточний вузол
    if (depth == 0) {
        // Корінь — без конектора, без відступу
        std::cout << node->key << '\n';
    } else {
        // Усі інші рівні — з конекторами
        std::cout << prefix << (isLeft ? "└── " : "┌── ") << node->key << '\n';
    }

    // 3) Ліве піддерево (малюється знизу)
    if (node->left) {
        std::string nextPrefix = prefix + (depth > 0 ? (isLeft ? "    " : "│   ") : "");
        showPretty(node->left, nextPrefix, /*isLeft=*/true, depth + 1);
    }
}

void ShowTree(const Node* root, int /*L*/) {
    showPretty(root, /*prefix=*/"", /*isLeft=*/true, /*depth=*/0);
}



void PreOrder(const Node* p) { //(Prefix)обхід у прямому порядку(вузол → ліво → право)
    if (!p) return;
    std::cout << p->key << ' ';
    PreOrder(p->left);
    PreOrder(p->right);
}

void InOrder(const Node* p) { //(Infix)обхід у внутрішньому порядку:(ліво → вузол → право) 1 2 3 4 5 для BST завжди дає відсортовані ключі.
    if (!p) return;
    InOrder(p->left);
    std::cout << p->key << ' ';
    InOrder(p->right);
}

void PostOrder(const Node* p) { //(Postfix)обхід у зворотньому порядку: (ліво → право → вузол)
    if (!p) return;
    PostOrder(p->left);
    PostOrder(p->right);
    std::cout << p->key << ' ';
}

void FreeTree(Node*& root) {
    if (!root) return;
    FreeTree(root->left);
    FreeTree(root->right);
    delete root;
    root = nullptr;
}

// ================= Частина 2: BST =================

Node* CreateRootBST(datatype key) { return new Node(key); }

Node* SearchNodeBST(Node* root, datatype key) {
    Node* p = root;
    while (p) {
        if (key == p->key) return p; // якщо key рівний поточному вузлу — знайшли
        p = (key < p->key) ? p->left : p->right; //якщо key менше — ідемо вліво, інакше вправо
    } //Повертає: адресу вузла або nullptr, якщо такого елемента нема.
    return nullptr;
}

Node* InsertNodeBST(Node*& root, datatype key) {
    if (!root) { root = CreateRootBST(key); return root; } //Якщо дерева нема — робимо корінь через CreateRootBST(key), повертаємо його.
    Node* p = root; Node* prev = nullptr;
    while (p) {
        prev = p;
        if (key == p->key) return nullptr; //якщо по дорозі зустріли такий самий ключ — нічого не вставляємо і повертаємо nullptr
        p = (key < p->key) ? p->left : p->right; //інакше йдемо ліворуч/праворуч, докbи не дійдемо до nullptr
    }
    Node* nw = new Node(key); 
    nw->parent = prev;//на місце nullptr вставляємо новий вузол 
    if (key < prev->key) prev->left = nw; else prev->right = nw; 
    return nw; //Повертає: адресу вставленого вузла або nullptr, якщо такий ключ вже існує.
}

Node* MinimumNodeBST(Node* root) { //від кореня йдемо вліво, доки не дійдемо до найменшого елемента
    if (!root) return nullptr;
    Node* p = root;
    while (p->left) p = p->left;
    return p;
}

Node* MaximumNodeBST(Node* root) { //від кореня йдемо вправо, доки не дійдемо до найбільшого елемента
    if (!root) return nullptr;
    Node* p = root;
    while (p->right) p = p->right;
    return p;
}

Node* SuccessorNodeBST(Node* x) { //наcтупник
    if (!x) return nullptr;
    if (x->right) return MinimumNodeBST(x->right);//якщо є праве піддерево, то наступник — мінімальний елемент у ньому,інакше йдемо вгору по дереву, доки не знайдемо вузол, який є лівою дитиною свого батька
    Node* p = x->parent;//потім повертаємо цього батька
    while (p && x == p->right) { x = p; p = p->parent; }//якщо такого немає, то наступника немає (поточний елемент — максимальний)
    return p;
}

Node* PredecessorNodeBST(Node* x) {//попередник
    if (!x) return nullptr;
    if (x->left) return MaximumNodeBST(x->left);//якщо є ліве піддерево, то попередник — максимальний елемент у ньому
    Node* p = x->parent;//
    while (p && x == p->left) { x = p; p = p->parent; }//інакше йдемо вгору по дереву, доки не знайдемо вузол, який є правою дитиною свого батька, потім повертаємо цього батька
    return p;
}

bool DeleteNodeBST(Node*& root, Node* del) {
    if (!del) return false;
    if (del->left && del->right) { //якшо вузол має двох дітей, знаходимо його наступника, копіюємо його ключ у видаляємий вузол, а потім видаляємо наступника
        Node* succ = SuccessorNodeBST(del);
        del->key = succ->key;
        del = succ;
    }
    Node* child = del->left ? del->left : del->right;//якшо вузол має одну дитину або не має дітей, просто видаляємо його, замінюючи його дитиною (або nullptr)
    if (child) child->parent = del->parent;
    if (!del->parent) {
        root = child;
    } else if (del == del->parent->left) {
        del->parent->left = child;
    } else {
        del->parent->right = child;
    }
    delete del;
    return true;
}
