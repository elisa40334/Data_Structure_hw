#include<iostream>
#include<string>
using namespace std;
struct oprule //運算子規則
{
	string op;
	int isp, icp;
};

int main() {
	int n; //資料筆數
	oprule opsi[8]; //存入運算子規則
	opsi[0].op = "(", opsi[0].isp = 0, opsi[0].icp = 20, opsi[1].op = ")", opsi[1].isp = 19, opsi[1].icp = 19, opsi[2].op = "+", opsi[2].isp = 12, opsi[2].icp = 12, opsi[3].op = "-", opsi[3].isp = 12, opsi[3].icp = 12, opsi[4].op = "*", opsi[4].isp = 13, opsi[4].icp = 13, opsi[5].op = "/", opsi[5].isp = 13, opsi[5].icp = 13, opsi[6].op = "%", opsi[6].isp = 13, opsi[6].icp = 13, opsi[7].op = "e", opsi[7].isp = 0, opsi[7].icp = 0;

	cin >> n;
	for (int i = 0; i <= n; i++) //從第一筆測資開始
	{
		string ans,str; //str是讀入的字串，ans是輸出的字串
		oprule a, b,stor[100]; //a是存放目前運算子的，stor是儲存運算子stack的
		int top = -1; //stack的元素最高位子

		getline(cin, str);
		str += 'e';
		//cout << str << ":" << str.length() << endl;
		for (int j = 0; j < str.length(); j++) //一個一個讀入字元
		{
			if (int(str[j]) >= 48 && int(str[j]) <= 57) { //若為數字直接輸出
				ans += str[j];
			}
			else if(str[j] != ' ') //非數字非空格時（原則上只能是運算子
			{
				for (int k = 0; k < 8; k++)  //檢查此運算子的規則，並且將規則存入a
				{
					if (opsi[k].op[0] == str[j])
					{
						a = opsi[k];
						break;
					}
				}
				//cout << a.op << endl;
				if (top >= 0) //當stor中有運算子的時候
				{
					//cout << "hiiii";
					int topl = top; //先將top隨便用一個參數存起來，不讓for迴圈與top互相干擾
					for (int k = topl; k >= 0; k--)
					{
						if (a.icp <= stor[k].isp)
						{
							ans += stor[k].op; 
							top--;
						}
						else  //只要有一個不符合規則就離開for迴圈
						{
							break;
						}
					}
					if (a.op == ")")
					{
						int x;
						for (x = top; x >= 0; x--)
						{
							if (stor[x].op != "(") {
								ans += stor[x].op;
							}
							else
							{
								break;
							}
						}
						top = x-1;
					}
					// if (a.op == "e")
					// {
					// 	/* code */
					// }
					
					else
					{
						stor[++top] = a;
					}
					// cout << "star" <<endl;
					// for (int i = 0; i <= top; i++)
					// {
					// 	cout << i << ":" << stor[i].op;
					// }
					
					// cout << endl;
				}
				else
				{
					//cout << "hi";
					stor[++top] = a;
					//cout << top << ":" << stor[top].op << endl;
				}
			}
            // cout << ans << endl;
		}

		//輸出資料
		// for (int i = 0; i < ans.length(); i++)
		// {
		// 	if (i != ans.length() - 1) {
		// 		cout << ans[i] << " ";
		// 	}
		// 	else
		// 	{
		// 		cout << ans[i] << endl;
		// 	}
		// }
		for (int i = 0; i < ans.length(); i++)
		{
			cout << ans[i];
		}
		cout << endl;
	}
}