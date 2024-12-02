#include<iostream>
using namespace std;
void check(int tree[],int cal);
void deletenode(int tree[],int cal,int posi);
int tree[1001] = {};

int main(){
    int n,cal = 1;

    while (cin >> n)
    {
        if (cal == 1)
        {
            tree[cal++] = n;
        }
        else
        {
            tree[cal++] = n;
            check(tree,cal-1);
        }
    }
    for (int i = 1; i < cal; i++) cout << "[" << i << "]" << tree[i] << " ";
    cout << endl;

    while (cal-1 != 0)
    {
        tree[1] = tree[cal-1];
        cal--;
        deletenode(tree,cal-1,1);
        for (int i = 1; i < cal; i++) cout << "[" << i << "]" << tree[i] << " ";
        cout << endl;
    }
}

void deletenode(int tree[],int cal,int posi){
    int chlidl = -1,chlidr = -1,cc = -1;

    if(posi*2 <= cal) chlidl = posi*2;
    if(posi*2+1 <= cal) chlidr = posi*2+1;
    if (chlidl == -1 && chlidr == -1) return;
    else if (chlidl != -1 && chlidr != -1)
    {
        if (tree[chlidl] < tree[chlidr]) cc = chlidl;
        else cc = chlidr;
        // cout << "::" << cc << "::" << cal << endl;
    }
    else
    {
        
        if (chlidl != -1) cc = chlidl;
        else if (chlidr != -1) cc = chlidr;
    }
    
    if (cc != -1)
    {
        if (tree[cc] < tree[posi])
        {
            int temp = tree[posi];
            tree[posi] = tree[cc];
            tree[cc] = temp;
            // cout << "::" << cc << "::" << cal << endl;
            deletenode(tree,cal,cc);
        }
    }
    
    
}

void check(int tree[],int cal){
    int parent = cal/2;
    if (tree[cal] < tree[parent])
    {
        int temp = tree[cal];
        tree[cal] = tree[parent];
        tree[parent] = temp;
        check(tree,parent);
    }
}