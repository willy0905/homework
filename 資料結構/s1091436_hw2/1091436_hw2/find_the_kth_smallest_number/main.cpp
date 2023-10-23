// Write your implementation here.
// Feel free to add any code you need in this file.
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {
	string input_filename;
	cin >> input_filename;
	ifstream input;
	input.open(input_filename);
	string output_filename;
	output_filename = input_filename[0];
	output_filename += ".out.txt";
	ofstream output(output_filename);
	if (!input.is_open())
	{
		cerr << "failed to open test data\n";
		return 1;
	}
	vector<int> arr;
	int n, m, num, type_num;
	char type;
	input >> n >> m;
	for (int i = 0; i < n; i++) {
		input >> num;
		arr.push_back(num);
	}
	for (int i = 0; i < m; i++) {
		input >> type >> type_num;
		if (type == 'q') {
			sort(arr.begin(), arr.end());
			output << arr[type_num - 1] << endl;
		}
		else {
			arr.push_back(type_num);
		}
	}
	input.close();
	output.close();
}