```cpp
#include <iostream>
#include <vector>
using namespace std;
 
void backtrack(vector<vector<int>>& result, vector<int>& current, int start, int n, int k) {
	if (current.size() == k) {              //如果当前组合的大小等于k，将其加入到结果中
        result.push_back(current);			
        return;
    }

	for (int i = start; i <= n; i++) {				//遍历所有可能的数
		current.push_back(i);						//将当前数加入到当前组合中
		backtrack(result, current, i + 1, n, k);	//递归
		current.pop_back();							//删除最后一个元素 ，回溯
    }
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> result;             //  存放结果
	vector<int> current;					//  存放当前组合
	backtrack(result, current, 1, n, k);	//  回溯 从一开始
	return result;                          //  返回结果
}

int main()
{
    int n, k;
	cout << "n = ";
	cin >> n;
	cout << "k = ";
    cin >>  k;
    vector<vector<int>> result = combine(n, k);//函数调用

    //输出结果
    int i = result.size();
	int size = i;
	cout << "[";
    if (size > 1) cout << endl;
	for (auto& v : result) {
		if (size > 1) cout << "    ";
		cout << "[";
		for (int j = 0; j < v.size(); j++) {
			cout << v[j];
			if (j != v.size() - 1) {
				cout << ",";
			}
		}
		cout << "]"; 
		if (size>1) cout << "," << endl; 
		if (--i) cout << endl;
	}
	cout << "]";

    return 0;
}
```