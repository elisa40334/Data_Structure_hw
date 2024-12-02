#include<iostream>
#include<string>
using namespace std;
struct heap
{
    int vv;
};


int main(){
    int n,total = 1,posi = 1,count = 0,cal = 1;
    string str,b[10001];
    heap a[10001];

    getline(cin,str);
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] != ' ') b[count] += str[i];
        else count++;
    }
    
    str = b[0];
    while (cal != count+1)
    {
        // cout << str << endl;
        n = stoi(str);
        // cout << n << endl;
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
        str = b[cal];
        cal++;
    }
    for (int i = 1; i < total; i++)
    {
        cout << "[" << i << "]" <<  a[i].vv<<" ";
    }
    cout << endl;

    
    for (int j = 0; j <= total; j++)
    {
        a[1] = a[--total];

        int check = 1;
        // cout << total;
        while (check < total-1)
        {
            // cout << "!!";
            // cout << "check" << check << endl;
            heap temp;
            if (a[check*2+1].vv < a[check*2].vv)
            {
                temp = a[check*2+1];
            }
            else{
                temp = a[check*2];
            }
            if (a[check].vv > temp.vv && temp.vv == a[check*2+1].vv)
            {
                // cout <<"bb";
                // cout << "check" << check << endl;
                a[check*2+1] = a[check];
                a[check] = temp;
                check = check*2+1;
            }
            else if (a[check].vv > temp.vv && temp.vv == a[check*2].vv)
            {
                // cout <<"aa";
                // cout << "check" << check << endl;
                a[check*2] = a[check];
                a[check] = temp;
                check *= 2;
                // cout << "check" << check << "::" <<  total << endl;
            }
            else break;
        }
        for (int i = 1; i < total; i++)
        {
            cout << "[" << i << "]" <<  a[i].vv<<" ";
        }
        cout << endl;
    }
    
}