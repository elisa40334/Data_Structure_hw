#include<iostream>
using namespace std;
struct posi
{
    int node,weight;
};
void find(int n,posi aa[10001][1001],int check[],int cal[],int maxnode);

int main(){
    posi aa[10001][1001];
    int n,cal[10001] = {},a,b,c,check[10001] = {},maxnode = 0;

    cin >> n;

    while (cin >> a >> b >> c)
    {
        aa[a][cal[a]++].node = b;
        aa[a][cal[a]++].weight = c;
        aa[b][cal[b]++].node = a;
        aa[b][cal[b]++].weight = c;
        if (maxnode < a) maxnode = a;
        if (maxnode < b) maxnode = b;
    }
    
    find(n,aa,check,cal,maxnode);
    
}

void find(int n,posi aa[10001][1001],int check[],int cal[],int maxnode){
    if (n < maxnode)
    {
        int minweigth = 2e8,minnode = 0;
        for (int i = 0; i < cal[n]; i++)
        {
            if(aa[n][i].weight < minweigth){
                minweigth = aa[n][i].weight;
                minnode = i;
            }
        }
        cout << "<" << n << "," << minnode << ">" << endl;
        find(minnode,aa,check,cal,maxnode);
    }
    return;
}