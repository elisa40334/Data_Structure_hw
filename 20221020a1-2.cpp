#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    for (int n = 0; n < 3;n++)
    {
        getline(cin,str);
        string ans,a[10000];
        int cal = -1;
        if (int(str[0]) < 48 || int(str[0]) > 57)
        {
            // cout << "bb;";
            for (int i = str.length()-1; i >= 0; i--){
                if (int(str[i]) >= 48 && int(str[i]) <= 57)
                {
                    a[++cal] = str[i];
                    // cout << a[cal];
                }
                else
                {
                    if (cal >= 1)
                    {
                        string aa;
                        aa += ("(" +a[cal] + str[i] + a[cal-1] + ")");
                        ans = aa;
                        a[--cal] = aa;
                    }
                    
                }
            }
            ans.erase(0,1);
            ans.erase(ans.length()-1,1);
            // for (int i = 1; i < ans.length()-1; i++)
            // {
            //     cout << ans[i];
            // }
            cout << ans << endl;
            
        }
        else if (int(str[str.length()-1]) < 48 || int(str.length()-1) > 57)
        {
            // cout << "aa" << endl;
            for (int i = 0; i < str.length(); i++)
            {
                if (int(str[i]) >= 48 && int(str[i]) <= 57)
                {
                    a[++cal] = str[i];
                    // cout << a[cal];
                }
                else
                {
                    // cout << "ho" << endl;
                    if (cal >= 1)
                    {
                        string aa;
                        aa = "(";
                        aa += (a[cal-1]+str[i]+a[cal]);
                        aa += ")";
                        // cout << aa;
                        ans = aa;
                        a[--cal] = aa;
                    }
                    
                    
                }
                // cout << cal << ":" << a[cal] << endl;
            }
            ans.erase(0,1);
            ans.erase(ans.length()-1,1);
            // for (int i = 1; i < ans.length()-1; i++)
            // {
            //     cout << ans[i];
            // }
            cout << ans << endl;
        }
        else
        {
            cout << "same" << endl;
        }
    }
}