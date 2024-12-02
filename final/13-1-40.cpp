// 0 3
// 1 2
// 1 3
// 2 3

#include<iostream>
using namespace std;

int main(){
    int a,b,list[1000][1000] = {},cal[1000] = {},max = 0,check[1000][1000] = {};
    while (cin >> a >> b)
    {
        list[a][cal[a]++] = b;
        list[b][cal[b]++] = a;
        check[a][b] = 1;
        check[b][a] = 1;
        if (a > max) max = a;
        if (b > max) max = b;
    }
    cout << "Adjacency matrix:\n";
    for (int i = 0; i <= max; i++)
    {
        for (int j = 0; j <= max; j++)
        {
            cout << check[i][j];
            if (j != max)
            {
                cout << " ";
            }
            
        }
        cout << "\n";
    }
    cout << "\nAdjacency list:\n";
    for (int i = 0; i <= max; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < cal[i]; j++)
        {
            cout << list[i][j] << " -> ";
        }
        cout << "end\n";
    }
    
}