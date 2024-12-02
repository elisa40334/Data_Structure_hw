#include<iostream>
using namespace std;
struct heap
{
    int vv,lindex,rindex;
};


int main(){
    int n,total = 0,posi = 0;
    heap a[10001];
    while (cin >> n)
    {
        if (total == 0)
        {
            cout << n;
            a[0].vv = n;
            a[0].lindex = posi+1;
            a[0].rindex = posi+2;
            total++;
        }
        else if (a[a[posi].lindex].vv == '\0')
        {
            a[a[posi].lindex].vv = n;
            a[posi].l = a[posi+1];
            a[posi+1].vv = n;
            total++;
        }
        else if (a[posi].r == nullptr)
        {
            a[posi].rr = n;
            a[posi].r = a[posi+2];
            a[posi+2].vv = n;
            total++;
            posi++;
        }
        
        
    }
    
}