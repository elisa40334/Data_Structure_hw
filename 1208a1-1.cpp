#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
public:
    int find(int n, vector<vector<int>>& trust) {
        int check[1001][1001] = {},cal[1001] = {};
        for (int i = 0; i < trust.size(); i++) check[trust[i][0]][cal[trust[i][0]]++] = trust[i][1];
        int posi = 1,x;
        // cout << x;
        for (int q = 1; q < 3; q++){
            for (int j = 0; j <= cal[q]; j++)
            {
                posi = 1;
                x = check[q][j];
                for (int i = 1; i <= n; i++)
                {
                    int k;
                    for (k = 0; k <= cal[i]; k++) if (check[i][k] == x) break;
                    if (k == cal[i])
                    {
                        posi = 0;
                        // cout <<"::" << q << ":::" << check[i][k] << endl;
                        break;
                    }
                }
                // cout <<"::" << q << endl;
                if (posi == 1 && cal[x] == 0) return x;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<vector<int>> v;
    int a, b;
    while(cin >> a >> b)
        v.emplace_back(vector<int>({a, b}));

    cout << sol.find(n, v) << '\n';
}