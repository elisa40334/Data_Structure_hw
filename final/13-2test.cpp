#include<iostream>
using namespace std;
void dfs(int adjlist[1001][1001],int cal[],int node);
int check[1001] = {};

int main(){
    int n,adjlist[1001][1001] = {},a,cal[1001] = {},yn = 1;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            cin >> a;
            if(a == 1){
                adjlist[i][cal[i]++] = j;
            }
        }
    }

    dfs(adjlist,cal,0);
    
    for (int i = 0; i < n; i++)
    {
        if(!check[i]){
            cout << -1 << endl;
            yn = 0;
            break;
        }
    }
    
    if(yn == 1) cout << 1 << endl;
    
}

void dfs(int adjlist[1001][1001],int cal[],int node){
    if (!check[node])
    {
        // cout << node << " ";
        check[node] = 1;
        for (int i = 0; i < cal[node]; i++)
        {
            dfs(adjlist,cal,adjlist[node][i]);
        }
    }
}