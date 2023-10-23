// Write your implementation here.
// Feel free to add any code you need in this file.
#include <iostream>
#include <stack>
#include <fstream>
using namespace std;
int main() {
	string input_filename;
	cin >> input_filename;
	ifstream input;
	string output_filename;
	output_filename = input_filename[0];
	output_filename += ".out.txt";
	ofstream output(output_filename);
	input.open(input_filename);
	if (!input.is_open())
	{
		cerr << "failed to open test data\n";
		return 1;
	}
	stack<int>num;
	int size;
	char sym[10][2];
	string str;
	bool check = true;
	input >> size;
	for (int i = 0; i < size; i++) {
		input >> sym[i][0] >> sym[i][1];
	}
	input >> str;
	for (int i = 0; i < str.length(); i++) {
		check = true;
		int place;
		for (int j = 0; j < size; j++) {
			if (str[i] == sym[j][1]) {
				check = false;
				place = j;
				break;
			}
		}
		if (check) {
			num.push(str[i]);
		}
		else {
			if (num.empty()) {
				output << "NO\n";
				return 0;
			}
			char tem = num.top();
			num.pop();
			if (tem != sym[place][0]) {
				output << "NO\n";
				return 0;
			}
		}
	}
	output << "YES\n";
	input.close();
	output.close();
	return 0;
}