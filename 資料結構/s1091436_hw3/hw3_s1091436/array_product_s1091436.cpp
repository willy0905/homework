#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
	ifstream input;
	input.open("input.txt");
	if (!input.is_open())
	{
		cerr << "failed to open test data\n";
		return 1;
	}
	int n;
	vector<int>arr;
	vector<int>mem;
	vector<int>ans;
	string str = "0";
	input >> n;
	for (int i = 0; i < n; i++) {
		int num;
		input >> num;
		arr.push_back(num);
	}
	for(int i=0;i<n;i++){
		for (int j = i; j < n; j++) {
			if (arr[i] == arr[j]) {
				for (int k = 0; k < mem.size(); k++) {
					if (mem[k] < arr[i]) {
						ans.push_back(mem[k]);
					}
				}
			}
			else {
				mem.push_back(arr[j]);
			}
		}
		mem.clear();
	}
	long long int num = 1;
	for (int i = 0; i < ans.size(); i++) {
		num *= ans[i];
		if (num > 1000000007) {
			num = num % 1000000007;
		}
	}
	ofstream output_file("output.txt", std::ios::binary);
	if (output_file.is_open()) {
		output_file << num << endl;
		output_file.close();
	}
}