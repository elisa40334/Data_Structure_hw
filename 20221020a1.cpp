#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    while (getline(cin,str))
    {
        string ans,a;
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
        if (int(str[jj]) < 48 || int(str[jj]) > 57)
        {
            
            for (int i = jj; i < str.length(); i++)
            {
                // cout << "i:" << str[i] << endl;
                if ((int(str[i]) < 48 || int(str[i]) > 57) && str[i] != 'a')
                {
                    a[++cal] = str[i];
                }
                else
                {
                    if (int(str[i+1]) >= 48 && int(str[i+1]) <= 57)
                    {
                        if (ans[ans.length()-1] == ')')
                        {
                            ans += a[cal];
                            cal--;
                        }
                        ans += "(";
                        ans += str[i];
                        ans += a[cal];
                        ans += str[i+1];
                        ans += ")";
                        i++;cal--;
                    }
                    else
                    {
                        if (ans[ans.length()-1] == ')')
                        {
                            ans += a[cal];
                            cal--;
                        }
                        if (cal != -1)
                        {
                            ans += a[cal--];
                        }
                        ans += str[i];
                    }
                }
            }
            cout << a;
            cout << ans << endl;
        }
        else if (int(str[kk]) < 48 || int(str[kk]) > 57)
        {
            for (int i = kk; i >= 0; i--)
            {
                if ((int(str[i]) < 48 || int(str[i]) > 57) && str[i] != 'a')
                {
                    a[++cal] = str[i];
                }
                else
                {
                    // if (a[cal] == '*' || a[cal] == '/' || a[cal] == '%')
                    // {
                    //     ans = "(" + ans;
                    //     ans =  ans + ")";

                    // }
                    cout << ans << endl;
                    if ((int(str[i-1]) >= 48 && int(str[i-1]) <= 57) )
                    {
                        if (ans[0] == '(')
                        {
                            ans = a[cal] + ans;
                            cal--;
                        }
                        ans = ")" + ans;
                        ans = str[i] + ans;
                        ans = a[cal] + ans;
                        ans = str[i-1] + ans;
                        ans = "(" + ans;
                        i--;cal--;
                    }
                    else
                    {
                        if (ans[0] == '(')
                        {
                            ans = a[cal--] + ans;
                        }
                        ans = str[i] + ans;
                        if (cal != -1)
                        {
                            ans = a[cal] + ans;
                            cal--;
                        }
                    }
                }
            }
            // cout << "a" << a << endl;
            cout << ans << endl;
        }
        else
        {
            cout << "same" << endl;
        }
        
    }
    
}
