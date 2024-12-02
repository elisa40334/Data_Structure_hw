#include<iostream>
using namespace std;
void find(int n,int weight1[1001][1001],int edge1[1001][1001],int cal1[1001],int maxnode);
int ans[1001];

int main(){
    int n,cal1[1001] = {},a,b,c,check[1001] = {},maxnode = 0,edge1[1001][1001] = {},counter = 0,weight1[1001][1001] = {};

    cin >> n;
    for (int i = 0; i < 1001; i++)
    {
        ans[i] = 2e8;
    }
    
    while (cin >> a >> b >> c)
    {
        weight1[b][cal1[b]] = c;
        edge1[b][cal1[b]++] = a;
        if (maxnode < a) maxnode = a;
        if (maxnode < b) maxnode = b;
    }
    ans[n] = 0;
    find(n,weight1,edge1,cal1,maxnode);
}

void find(int n,int weight1[1001][1001],int edge1[1001][1001],int cal1[1001],int maxnode){
    for (int i = 0; i < cal1[n]; i++)
    {
        if (ans[edge1[n][i]] > (ans[n] + edge1[n][i]))
        {
            ans[edge1[n][i]] = ans[n] + edge1[n][i];
        }
        
    }
    
}