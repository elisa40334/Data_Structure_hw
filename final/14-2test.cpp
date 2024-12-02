#include<iostream>
using namespace std;
void redraw(int adjlist[1001][1001],int cal[],int max,int node);
void dfs(int adjlist[1001][1001],int cal[],int max,int node);
void findlow(int adjlist[1001][1001],int cal[],int max,int node);
int dfn[1001] = {},check[1001] = {},aa = 0,oplist[1001] = {},newlist[1001][1001]= {},newcal[1001] = {},checka[1001] = {},low[1001] = {};

int main(){
    int a,b,adjlist[1001][1001] = {},cal[1001] = {},max = 0;

    while (cin >> a >> b)
    {
        adjlist[a][cal[a]++] = b;
        adjlist[b][cal[b]++] = a;
        if(a > max) max = a;
        if(b > max) max = b;
    }
    // for (int i = 0; i <= max; i++)
    // {
    //     cout << i <<": ";
    //     for (int j = 0; j < cal[i]; j++)
    //     {
    //         cout << adjlist[i][j] << "->";
    //     }
    //     cout << "end\n";
    // }
    // cout << "end\n";
    redraw(adjlist,cal,max,0);

    // for (int i = 0; i <= max; i++)
    // {
    //     cout << dfn[i];
    // }
    for (int i = 0; i <= max; i++)
    {
        cout << i <<": ";
        for (int j = 0; j < newcal[i]; j++)
        {
            cout << newlist[i][j] << "->";
        }
        cout << "end\n";
    }
    dfs(newlist,newcal,max,3);
    for (int i = 0; i <= max; i++)
    {
        check[i] = 0;
    }
    
    findlow(newlist,newcal,max,3);
}

void findlow(int adjlist[1001][1001],int cal[],int max,int node){
    if (!check[node])
    {
        
    }
    
}

void redraw(int adjlist[1001][1001],int cal[],int max,int node){
    if (check[node] == 0)
    {
        check[node] = 1;
        for (int i = 0; i < cal[node]; i++)
        {
            // if(!check[adjlist[node][i]]) cout << node << "::" << adjlist[node][i] << "\n";
            if(!check[adjlist[node][i]]) {
                newlist[node][newcal[node]++] = adjlist[node][i];
                newlist[adjlist[node][i]][newcal[adjlist[node][i]]++] = node;
            }
            redraw(adjlist,cal,max,adjlist[node][i]);
        }
    }
}

void dfs(int adjlist[1001][1001],int cal[],int max,int node){
    if (!checka[node])
    {
        cout << node;
        checka[node] = 1;
        dfn[node] = aa;
        oplist[aa++] = node;
        for (int i = 0; i < cal[node]; i++){
            dfs(adjlist,cal,max,adjlist[node][i]);
        }
    }
}