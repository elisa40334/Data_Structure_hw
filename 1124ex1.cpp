#include<iostream>
using namespace std;
struct node
{
    int data = 0,index = 0;
};

int main(){
    int n,a,nl,nr,count = 0,posi = 1,last;
    node tree[1024];
    cin >> n;
    cin >> a;
    while (a != -1)
    {
        cin >> nl >> nr;
        
        if (count == 0)
        {
            tree[count].data = a;
            tree[count].index = posi;
            tree[++count].data = nl;
            tree[count].index = 2*posi;
            tree[++count].data = nr;
            tree[count].index = 2*posi+1;
            // cout << tree[count-2].data <<":" <<tree[count-1].data <<":" << tree[count].data <<endl;
        }
        else
        {
            for (int i = 0; i <= count; i++)
            {
                if (a == tree[i].data)
                {
                    tree[tree[i].index*2-1].data = nl;
                    tree[tree[i].index*2-1].index = tree[i].index*2;
                    tree[tree[i].index*2].data = nr;
                    tree[tree[i].index*2].index = tree[i].index*2+1;
                    count = tree[i].index*2;
                    // cout << a  << ":::"<< tree[count-1].data <<":" << tree[count].data <<endl;
                    break;
                }
            }
        }
        cin >> a;
        if (a == -1)
        {
            if (nr != 0) last = nr;
            else last = nl;
        }
        
    }
    
    for (int i = 0; tree[i].data != last; i++)
    {
        cout << tree[i].data << " ";
    }
    cout << tree[count].data << endl;
}