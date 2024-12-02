#include<iostream>
#include<string>
using namespace std;

int main(){
    int max = 0;
    string str,ans;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        int len = 0;
        for (int j = str.length()-1; j > i; j--)
        {
            string stra,strb;
            for (int q = i; q <= j; q++)
            {
                stra += str[q];
                
            }
            for (int q = j; q >= i; q--)
            {
                strb += str[q];
                
            }
            //cout << stra << endl << strb << endl;
            if (stra == strb && j-i+1 > max)
            {
                ans = stra;
                max = j-i+1;
            }
        }
        
    }
    cout << ans << endl;
}