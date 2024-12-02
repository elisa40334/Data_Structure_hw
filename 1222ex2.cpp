#include<iostream>
using namespace std;
void find(int n,int weight1[501][501],int edge1[501][501],int cal1[501],int edge2[501][501],int cal2[501],int maxnode,int counter);
int ans[501];

int main(){
    int n,cal1[501] = {},a,b,c,maxnode = 0,edge1[501][501] = {},counter = 0,weight1[501][501] = {};
    int cal2[501] = {},edge2[501][501] = {};
    cin >> n;
    for (int i = 0; i < 501; i++)
    {
        ans[i] = 2e8;
    }
    
    while (cin >> a >> b >> c)
    {
        weight1[b][cal1[b]] = c;
        edge1[b][cal1[b]++] = a;
        edge2[a][cal2[a]++] = b;
        if (maxnode < a) maxnode = a;
        if (maxnode < b) maxnode = b;
    }
    ans[n] = 0;
    find(n,weight1,edge1,cal1,edge2,cal2,maxnode,counter);
    for (int i = 0; i <= maxnode; i++)
    {
        cout << i << ": " <<  ans[i] << "\n";
    }
    
}

void find(int n,int weight1[501][501],int edge1[501][501],int cal1[501],int edge2[501][501],int cal2[501],int maxnode,int counter){
    if (n <= maxnode && counter <= maxnode){
        counter++;
        // cout <<  "klasjflkja:" << n << endl;
        for (int i = 0; i < cal1[n]; i++)
        {
            if (ans[n] > (ans[edge1[n][i]] + weight1[n][i]))
            {
                ans[n] = ans[edge1[n][i]] + weight1[n][i];
            }
        }
        for (int i = 0; i < cal2[n]; i++)
        {
            // cout << edge2[n][i] << endl;
            find(edge2[n][i],weight1,edge1,cal1,edge2,cal2,maxnode,counter);
        }
    }
}