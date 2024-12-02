#include<iostream>
using namespace std;
struct node
{
    int data;
    node *nl;
    node *nr;
};
void printTree(node *up,node *first,int count,int check);

int main(){
    int n,total = 0;
    node *tree = new node;
    node *first;
    while (cin >> n)
    {
        int count = 0;
        if (total == 0)
        {
            tree->nl = nullptr;
            tree->nr = nullptr;
            tree->data = n;
            first = tree;
            total++;
            cout << tree->data << endl;
        }
        else
        {
            node *temp = new node;
            temp->nl = nullptr;
            temp->nr = nullptr;
            temp->data = n;
            total++;
            if (tree->nl == nullptr)
            {
                cout << "left" << endl;
                tree->nl = temp;
            }
            else if (tree->nr == nullptr)
            {
                cout << "right" << endl;
                tree->nr = temp;
                tree = tree->nl;
            }
            cout << tree->data << endl;
        }
        if (first->nr != nullptr)
        {
            cout << "kk" << first->nr->data << endl;
        }
        
        cout << "[" << ++count << "]" << first->data;
        printTree(first,first,count,0);
        cout << endl;
    }
    
}

void printTree(node *up,node *now,int count,int check){
    // cout <<"chcek" << check << "check";
    if (now->nl != nullptr)
    {
        cout << "[" << ++count << "]" << now->nl->data;
    }
    if (now->nr != nullptr)
    {
        cout << "[" << ++count << "]" << now->nr->data;
    }
    if (now->nl != nullptr && check == 0) {
        // cout << "aa" << now->nl->data;
        printTree(now,now->nl,count,1);
        }
    if (up->nr != nullptr && check == 1) {
        // cout << "bb" << up->nr->data;
        printTree(up,up->nr,count,2);
        }
    else if(check == 2 && up->nl->nl!= nullptr) {
        // cout << "cc";
        printTree(up->nl,up->nl->nl,count,0);
        }
}