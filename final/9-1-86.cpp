// This_is_a_[Beiju]_text
// [[]][][]Happy_Birthday_to_Tsinghua_University

#include<iostream>
#include <vector>
#include<string>
using namespace std;
int main() {
	string str;
	vector<string>::iterator loca;
	int count;
	while (getline(cin, str))
	{
		vector<string> v;
		
		
		int check = 0;
		for (int i = 0; i < str.length(); i++) {
			string a;
			int j = i;
			while (str[j] != '\0')
			{
				if (str[j] == '[' || str[j] == ']' || str[j] == '_')
				{
					a = str[j];
					i = j;
					j++;
					break;
				}
				else if (str[j + 1] == '\0')
				{
					a += str[j];
					i = j;
					j++;
					break;
				}
				else if (str[j+1] == '_' || str[j + 1] == '[' || str[j + 1] == ']')
				{
					a += str[j];
					i = j;
					j++;
					break;
				}
				else
				{
					a += str[j];
				}
				j++;
			}
			//cout << a << endl;
			if (a == "[")
			{
				check = 1;
				count = 0;
			}
			else if (a == "]")
			{
				check = 0;
			}
			else
			{
				if (check == 1)
				{
					v.insert(v.begin(), a);
					count += 1;
					check = 2;
				}
				else if (check == 0)
				{
					v.push_back(a);
				}
				else if (check == 2)
				{
					vector<string>::iterator it;
					it = v.begin();
					v.insert(it + count, a);
					count++;
				}
			}
		}
		vector<string>::iterator it;
		for (it = v.begin(); it < v.end(); it++)
		{
			cout << *it;
		}
		cout << endl;
		check = 0;
	}
}