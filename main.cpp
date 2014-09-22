#include <iostream>
#include <climits>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left, *right;

    TreeNode() : value(),left(NULL),right(NULL) {};
    TreeNode(int val) : value(val),left(NULL),right(NULL) {};
};


void show_LVR(TreeNode *a)
{
    if(a== nullptr)
    {
        return;
    }
    show_LVR(a->left);
    cout << (a->value) << endl;
    show_LVR(a->right);
}


int czy_jest(TreeNode *a, int b)
{
    if(a == nullptr)
    {
        return 0;
    }
    else if(a->value == b)
    {
        return 2;
    }
    czy_jest(a->left, b);
    czy_jest(a->right, b);

    return 0;
}


void dodaj_wartosc(int a, TreeNode *wsk)
{
    if( !czy_jest(wsk, a) )
    {
        if (wsk == nullptr) {wsk->value = a; return;}
        else if (a < (wsk->value) && wsk->left == nullptr) { wsk->left = new TreeNode; wsk->left->value =a ; return; }
        else if (a < (wsk->value)) {dodaj_wartosc(a, wsk->left);return;}
        else if (a >= (wsk->value) && wsk->right == nullptr) { wsk->right = new TreeNode; wsk->right->value =a ; return;}
        else if (a >= (wsk->value)) { dodaj_wartosc(a, wsk->right);return;}
    }
    else
    {
        cout << a  <<" ----wartosc jest juz na liscie!\n" << endl;
    }
}


int main()
{
    int root_wartosc;
    cout << "wprowadz wartosc -> root <-  :";
    cin >>root_wartosc;

    TreeNode *root = new TreeNode(root_wartosc);

    int liczba = 1;

    while (liczba != 0)
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "\npodaj liczbe do wprowadzenia: [0 - koniec programu]";
        cin >> liczba;

        dodaj_wartosc(liczba, root);
        show_LVR(root);
        cout << "\n\n---------------\n\n";
    }

    return 0;
}

