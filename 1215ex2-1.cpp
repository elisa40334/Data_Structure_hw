#include<iostream>
using namespace std;
bool Dposi[1000] = {},check[1000] = {},exedge[1000][1000] = {false};
int Dcount = 0,listb[1000][1000] = {},calb[1000] = {},dfs[1000] = {},low[1000] = {};
void redrew(int n,int lista[1000][1000],int cala[],int last);
void Depthtree(int n,int list[1000][1000],int cal[],int max);
void loww(int n,int lista[1000][1000],int listb[1000][1000],int cala[1000],int calb[1000]);

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
    redrew(3,lista,cala,3);
    // cout << "\n";

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
    Depthtree(3,listb,calb,max);
    // cout << "\n";
    cout << "   ";
    for (int i = 0; i <= max; i++)
    {
        cout << " " << i;
    }
    
    cout << "\ndfn ";
    for (int i = 0; i <= max; i++){
        cout << dfs[i];
        if(i != max) cout << " ";
    }
    cout << "\nlow ";;
    for (int i = 0; i <= max; i++)
    {
        loww(i,lista,listb,cala,calb);
    }
    for (int i = max; i >= 0; i--)
    {
        for (int j = 1; j < calb[i]; j++)
        {
            if (low[listb[i][j]] < low[i])
            {
                low[i] = low[listb[i][j]];
            }
            
        }
        
    }
    
    for (int i = 0; i <= max; i++)
    {
        cout << low[i];
        if(i != max) cout << " ";
    }
}

void redrew(int n,int lista[1000][1000],int cala[],int last){
    if (check[n]) return;
    check[n] = true;
    if (n != last)
    {
        listb[last][calb[last]++] = n;
        listb[n][calb[n]++] = last;
        exedge[n][last] = true;
        exedge[last][n] = true;
    }
    for (int i = 0; i < cala[n]; i++)
    {
        redrew(lista[n][i],lista,cala,n);
    }
}

void Depthtree(int n,int list[1000][1000],int cal[],int max){
    if (Dposi[n]) return;
    Dposi[n] = true;
    dfs[n] = Dcount;
    low[n] = dfs[n];
    Dcount++;
    // cout << n;
    // if(Dcount <= max) cout << " ";
    for (int i = 0; i < cal[n]; i++)
    {
        Depthtree(list[n][i],list,cal,max);
    }
}

void loww(int n,int lista[1000][1000],int listb[1000][1000],int cala[1000],int calb[1000]){
    for (int i = 0; i < cala[n]; i++)
    {
        if (low[lista[n][i]] < low[n] && !exedge[n][lista[n][i]])
        {
            low[n] = low[lista[n][i]];
        }
    }
}
