#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct node
{
    string data;
    bool lcheck,rcheck;
    node *nl;
    node *nr;
};
void insert(string a,node *first,string nl,string nr);
void preorder (node *ptr);

int main(){
    string a;
    node *tree;
    node *first;
    node *last;
    cin >> a;
    while (a != "0")
    {
        string nl,nr,k;
        cin >> k;
        node *temp1 = new node;
        if (a == "r")
        {
            if ((int(k[1])-48) == 1 && (int(k[2])-48)%2 == 1)
            {
                node *temp2 = new node;
                nl = k;
                temp2->data = nl;
                temp2->nl = nullptr;
                temp2->nr = temp1;
                temp2->lcheck = false;
                temp2->rcheck = false;
                temp1->lcheck = true;
                temp1->nl = temp2;
                cin >> k;
            }
            if ((int(k[1])-48) == 1 && (int(k[2])-48)%2 == 0)
            {
                nr = k; 
                node *temp3 = new node;
                temp3->data = nr;
                temp3->nl = temp1;
                temp3->nr = nullptr;
                temp3->lcheck = false;
                temp3->rcheck = false;
                temp1->rcheck = true;
                temp1->nr = temp3;
                cin >> k;
            }
            // cout << a << endl;
            temp1->data = a;
            first = temp1;
            tree = temp1;
        }
        else
        {
            if ((int(k[1])-48 == int(a[1])-47) && (int(k[2])-48)%2 == 1){
                // cout << "kk\n" ;
                nl = k;
                nr = "\0";
                cin >> k;
            }
            if ((int(k[1])-48 == int(a[1])-47) && (int(k[2])-48)%2 == 0){
                nr = k;
                cin >> k;
            }
            insert(a,tree,nl,nr);
        }
        // preorder (first);
        // cout << endl;
        cout << first->nl->data << ":" << first->nr->data << endl;
        // cout << a << nl << nr << endl;
        a = k;
    }
    preorder (first);
}

void insert(string a,node *tree,string nl,string nr){
    int posiarray[1000];
    int layer = int(a[1])-48;
    int posi = int(a[2])-48;
    node *up;
    
    // cout << tree->data << layer << posi << endl;
    while (layer != 1)
    {
        posiarray[layer] = posi;
        posi = ceil(posi/2);
        layer--;
    }
    // cout << ":::::" << tree->data << layer << posi << endl;
    posiarray[layer] = posi;
    posiarray[layer+1] = 0;
    // cout << posiarray[1] << endl;
    for (int i = 1; posiarray[i] != 0; i++)
    {
        if (posiarray[i+1] == 0)
        {
            up = tree;
        }
        if (posiarray[i]%2 == 1)
        {
            tree = tree->nl;
        }
        else{
            tree = tree->nr;
        }
    }
    cout << "::::" << tree->data << endl;
    if (nl != "\0")
    {
        cout << "nl" << endl;
        node *temp1 = new node;
        temp1->data = nl;
        temp1->nl = up;
        temp1->nr = tree;
        temp1->lcheck = false;
        temp1->rcheck = false;
        tree->nl = temp1;
        tree->lcheck = true;
        cout << tree->nl->data << endl;
    }
    if (nr != "\0"){
        cout << "nr" << endl;
        node *temp2 = new node;
        temp2->data = nr;
        temp2->nl = tree;
        temp2->nr = up;
        temp2->lcheck = false;
        temp2->rcheck = false;
        tree->nr = temp2;
        tree->rcheck = true;
        // cout << tree->nr->data << endl;
    }
}
void preorder (node *ptr) { /*前序走訪*/
    if (ptr ) {
        cout << ptr->data << " ";
        if (ptr->lcheck)
        {
            // cout << "aa";
            preorder (ptr->nl);
        }
        if (ptr->rcheck)
        {
            // cout << "bb";
            preorder (ptr->nr);
        }
    }
    return;
}