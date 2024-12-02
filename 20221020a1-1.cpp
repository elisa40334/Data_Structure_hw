#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    while (getline(cin,str))
    {
        string ans,a[100];
        int cal = -1;
        int jj;
        int kk;
        for (jj = 0; jj < str.length(); jj++)
        {
            if (str[jj] != '(')
            {
                break;
            }
        }
        for (kk = str.length()-1; kk >= 0; kk--)
        {
            if (str[kk] != ')')
            {
                break;
            }
        }
        if (int(str[0]) < 48 || int(str[0]) > 57)
        {
            // cout << "bb;";
            
            
            
        }
        else 
        {
            // cout << "aa" << endl;
            for (int i = 0; i < str.length(); i++)
            {
                
                if (int(str[i]) >= 48 && int(str[i]) <= 57)
                {
                    a[++cal] = str[i];
                    // cout << a << str[i];
                }
                else
                {
                    // cout << "ho" << endl;
                    if (cal >= 1)
                    {
                        ans += "(";
                        ans += a[cal-1];
                        ans += str[i];
                        ans += a[cal];
                        ans += ")";
                        cal -= 2;
                    }
                    else if (cal == 0)
                    {
                        if (ans[ans.length()-1] == ')')
                        {
                            ans += str[i];
                            ans += a[cal--];
                        }
                        else
                        {
                            ans = "(" + ans;
                            ans += ")";
                            ans += str[i];
                            ans += a[cal--];
                        }
                    }
                }
                // cout << cal << ":" << a[cal] << endl;
            }
            cout << ans << endl;
        }
        
    }
    
}
