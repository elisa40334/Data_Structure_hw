#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int cal = 0;
        while (n%i == 0)
        {
            if(n%(i*i) == 0){
                do
                {
                    cal++;
                    n/=i;
                } while (n % i == 0);
                cout << i << "^" << cal;
            }
            else
            {
                n /= i;
                cout << i;
            }
            if (n != 1)
            {
                cout << " * ";
            }
        }
    }
    cout << endl;
    return 0;
}