#include<iostream>
using namespace std;
struct heap
{
    int vv;
};


int main(){
    int n,total = 1,posi = 1;
    heap a[10001];
    while (cin >> n)
    {
        if (total == 0)
        {
            a[1].vv = n;
        }
        else if (a[posi+1].vv == '\0')
        {
            a[posi+1].vv = n;
        }
        else if (a[posi+2].vv == '\0')
        {
            a[posi+2].vv = n;
            posi++;
        }
        total++;
        int check = total-1;
        // cout << check;
        while (check != 1 && n < a[check/2].vv)
        {
            // cout << "aa" << check <<"bb" << a[check/2].vv <<"bb";
            heap temp = a[check];
            a[check] = a[check/2];
            a[check/2] = temp;
            check /= 2;
        }
        a[check].vv = n;
        
        for (int i = 1; i < total; i++)
        {
            cout << "[" << i << "]" <<  a[i].vv<<" ";
        }
        cout << endl;
    }
    
}