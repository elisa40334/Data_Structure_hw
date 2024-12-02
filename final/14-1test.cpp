#include<iostream>
using namespace std;
int check[1001] = {};
void dfs(int adjlist[1001][1001],int cal[],int node,int max);
void bfs(int adjlist[1001][1001],int cal[],int node,int max);
int aa;

int main(){
    int a,b,adjlist[1001][1001] = {},cal[1001] = {},max = 0,waitlist[1001] = {},waitcal = 1,checkb[1001] = {};

    aa = 0;
    while (cin >> a >> b)
    {
        adjlist[a][cal[a]++] = b;
        adjlist[b][cal[b]++] = a;
        if(a > max) max = a;
        if(b > max) max = b;
    }
    cout << "Depth First Search:\n";
    dfs(adjlist,cal,0,max);
    cout << "\n\n";

    cout << "Breadth First Search:\n";
    waitlist[0] = 0;
    cout << "0 ";
    checkb[0] = 1;
    for (int i = 0; i < waitcal; i++)
    {
        // cout << waitlist[i] <<":::\n";
        for (int j = 0; j < cal[waitlist[i]]; j++)
        {
            if(checkb[adjlist[waitlist[i]][j]] == 0) {
                cout << adjlist[waitlist[i]][j] <<" ";
                checkb[adjlist[waitlist[i]][j]] = 1;
                waitlist[waitcal++] = adjlist[waitlist[i]][j];
            }
        }
        
    }

    
    cout << "\n";
}


void dfs(int adjlist[1001][1001],int cal[],int node,int max){
    if (!check[node])
    {
        cout << node;
        check[node] = 1;
        if(aa != max) cout << " ";
        aa++;
        for (int i = 0; i < cal[node]; i++)
        {
            dfs(adjlist,cal,adjlist[node][i],max);
        }
    }
}