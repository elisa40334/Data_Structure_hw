#include<iostream>
using namespace std;
void check(int tree[],int cal);

int main(){
    int tree[1001] = {},n,cal = 1;

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
        for (int i = 1; i < cal; i++)
        {
            cout << "[" << i << "]" << tree[i] << " ";
        }
        cout << endl;
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