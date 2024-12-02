#include<iostream>
using namespace std;

int main(){
    int tree[1001] = {},n,v,l,r,cal = 1;
    cin >> n;
    cin >> v >> l >> r;
    tree[cal++] = v;
    tree[cal++] = l;
    tree[cal++] = r;

    while (cin >> v)
    {
        int node;
        if (v == -1) break;
        cin >> l >> r;

        for (int i = 1; i <= cal; i++)
        {
            if (tree[i] == v)
            {
                tree[i*2] = l;
                tree[i*2+1] = r;
                cal = i*2+1;
                break;
            }
        }
    }
    
    for (int i = 1; i <= cal; i++)
    {
        cout << tree[i] << " ";
    }
    
}