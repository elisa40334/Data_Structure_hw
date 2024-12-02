#include<iostream>
using namespace std;
#include <time.h>//引入標頭檔案

int main()
{
    int a,b = 10;
    clock_t start,now;//定義clock_t變數
    cin >> a;
    start = clock(); //開始時間
    while (a != b)
    {
        cin >> a;
        now = clock();//現在時間
        cout << double(now-start)/CLOCKS_PER_SEC << endl;
    }
    
    
}