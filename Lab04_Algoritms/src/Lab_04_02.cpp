#include "Tree.h"
using std::cout; using std::cin; using std::endl;

int main() {
    Node* root = nullptr;
    while (true) {
        cout << "BST меню: 1) Insert  2) Delete  3) Search  4) ShowTree  5) Successor  6) Predecessor  7) InOrder  8) Exit\n> ";
        int op; if (!(cin >> op)) return 0;
        if (op == 8) break;
        if (op == 1) {
            cout << "Ключ для вставки: "; datatype k; cin >> k;
            auto res = InsertNodeBST(root, k);
            if (!res) cout << "Дублікат: такий ключ вже існує." << endl;
        } else if (op == 2) {
            cout << "Ключ для видалення: "; datatype k; cin >> k;
            Node* t = SearchNodeBST(root, k);
            if (!t) cout << "Не знайдено." << endl;
            else { DeleteNodeBST(root, t); cout << "Видалено." << endl; }
        } else if (op == 3) {
            cout << "Ключ для пошуку: "; datatype k; cin >> k;
            Node* t = SearchNodeBST(root, k);
            cout << (t ? "Знайдено." : "Не знайдено.") << endl;
        } else if (op == 4) {
            ShowTree(root);
        } else if (op == 5) {
            cout << "Ключ для Successor: "; datatype k; cin >> k;
            Node* t = SearchNodeBST(root, k);
            if (!t) cout << "Не знайдено вузол." << endl;
            else {
                Node* s = SuccessorNodeBST(t);
                if (s) cout << "Successor: " << s->key << endl; else cout << "Немає (максимальний елемент)." << endl;
            }
        } else if (op == 6) {
            cout << "Ключ для Predecessor: "; datatype k; cin >> k;
            Node* t = SearchNodeBST(root, k);
            if (!t) cout << "Не знайдено вузол." << endl;
            else {
                Node* p = PredecessorNodeBST(t);
                if (p) cout << "Predecessor: " << p->key << endl; else cout << "Немає (мінімальний елемент)." << endl;
            }
        } else if (op == 7) {
            InOrder(root); cout << '\n';
        }
    }
    FreeTree(root);
    return 0;
}
