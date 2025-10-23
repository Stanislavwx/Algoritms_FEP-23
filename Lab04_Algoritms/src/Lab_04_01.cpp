#include "Tree.h"
using std::cout; using std::cin; using std::endl;

int main() {
    Node* root = nullptr;
    while (true) {
        cout << "Виберіть функцію:  1) CreateTree  2) ShowTree  3) InfixOrder  4) PostfixOrder  5) PrefixOrder  6) Exit\n> ";
        int op; if (!(cin >> op)) return 0;
        if (op == 6) break;
        if (op == 1) {
            FreeTree(root);
            cout << "Введіть розмір дерева: ";
            int n; cin >> n;
            cout << "Ввести власні ключі? (1=так, 0=ні): ";
            int own; cin >> own;
            if (own) {
                std::vector<datatype> keys(n);
                for (int i = 0; i < n; ++i) { cout << "Введіть ключ: "; cin >> keys[i]; }
                int idx = 0;
                CreateTree(root, n, &keys, &idx);
            } else {
                CreateTree(root, n, nullptr, nullptr);
            }
            cout << "Tree has been created." << endl;
        } else if (op == 2) {
            ShowTree(root);
        } else if (op == 3) {
            InOrder(root); cout << '\n';
        } else if (op == 4) {
            PostOrder(root); cout << '\n';
        } else if (op == 5) {
            PreOrder(root); cout << '\n';
        }
    }
    FreeTree(root);
    return 0;
}
