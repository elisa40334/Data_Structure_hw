#include<iostream>
using namespace std;
bool Dposi[1000] = {};
int Dcount = 0,listb[1000][1000] = {},calb[1000] = {};
void Depthtree(int n,int lista[1000][1000],int cala[],int max,int last);

int main(){
    int a,b,lista[1000][1000] = {},cala[1000] = {},max = 0;
    while (cin >> a >> b)
    {
        lista[a][cala[a]++] = b;
        lista[b][cala[b]++] = a;
        if (a > max) max = a;
        if (b > max) max = b;
    }
    // cout << "\nAdjacency lista:\n";
    // for (int i = 0; i <= max; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < cala[i]; j++)
    //     {
    //         cout << lista[i][j] << " -> ";
    //     }
    //     cout << "end\n";
    // }
    cout << "Depth First Search:\n";
    Depthtree(0,lista,cala,max,0);
    cout << "\n";

    cout << "\nAdjacency lista:\n";
    for (int i = 0; i <= max; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < calb[i]; j++)
        {
            cout << listb[i][j] << " -> ";
        }
        cout << "end\n";
    }
    cout << "Depth First Search:\n";
    Depthtree(0,lista,cala,max,0);
    cout << "\n";
}

void Depthtree(int n,int lista[1000][1000],int cala[],int max,int last){
    if (Dposi[n]) return;
    Dposi[n] = true;
    Dcount++;
    cout << n;
    if(Dcount <= max) cout << " ";

    if (n != last)
    {
        listb[last][calb[last]++] = n;
        listb[n][calb[n]++] = last;
    }
    
    for (int i = 0; i < cala[n]; i++)
    {
        Depthtree(lista[n][i],lista,cala,max,n);
    }
}

