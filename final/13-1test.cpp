#include<iostream>
using namespace std;

int main(){
    int a,b,adjmatrix[1001][1001] = {},adjlist[1001][1001] = {},cal[1001] = {},max = 0;

    while (cin >> a >> b)
    {
        adjmatrix[a][b] = 1;
        adjmatrix[b][a] = 1;
        adjlist[a][cal[a]++] = b;
        adjlist[b][cal[b]++] = a;
        if(a > max) max = a;
        if(b > max) max = b;
    }

    cout << "Adjacency matrix:\n";
    for (int i = 0; i <= max; i++)
    {
        for (int j = 0; j <= max; j++) {
            cout << adjmatrix[i][j];
            if(j != max) cout << " ";
        }
        cout << endl;
    }

    cout << "\nAdjacency list:\n";
    for (int i = 0; i <= max; i++){
        cout << i << ": ";
        for (int j = 0; j < cal[i] ;j++){
            cout << adjlist[i][j] << " -> ";
        }
        cout << "end" << endl;
    }
    
}