#include<iostream>
using namespace std;
void find(int n,int edge[1001][1001],int check[],int cal[],int maxnode,int counter);
int ans = 0;

int main(){
    int n,cal[1001] = {},a,b,c,check[1001] = {},maxnode = 0,edge[1001][1001] = {},counter = 0;

    cin >> n;
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            edge[i][j] = -2e8;
        }
    }
    
    while (cin >> a >> b >> c)
    {
        edge[a][b] = c;
        edge[b][a] = c;
        if (maxnode < a) maxnode = a;
        if (maxnode < b) maxnode = b;
    }
    
    find(n,edge,check,cal,maxnode,counter);
    cout << "\nThe cost of minimum spanning tree: " << ans << endl;
}

void find(int n,int edge[1001][1001],int check[],int cal[],int maxnode,int counter){
    if (n < maxnode && counter < maxnode)
    {
        check[n] = 1;
        counter++;
        int minweigth = 2e8,minnode = 0;
        for (int i = 0; i <= maxnode; i++)
        {
            // cout << i << "::" << check[i] << endl;
            if(edge[n][i] < minweigth && edge[n][i] != -2e8 && check[i] != 1){
                minweigth = edge[n][i];
                minnode = i;
            }
        }
        ans += minweigth;
        cout << counter << ": <" << n << "," << minnode << ">" << endl;
        find(minnode,edge,check,cal,maxnode,counter);
    }
    return;
}