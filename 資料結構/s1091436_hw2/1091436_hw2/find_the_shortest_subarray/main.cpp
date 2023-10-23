// Write your implementation here.
// Feel free to add any code you need in this file.
#include <iostream>
#include <fstream>
#include <vector>
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
	int a, b, c;
	input >> a >> b;
	vector<int> num(a);
	for (int i = 0; i < a; i++) {
		input >> c;
		num[i] = c;
	}
	int min = INT_MAX;
	for (int i = 0; i < num.size(); i++) {
		int sum = num[i];
		for (int j = i + 1; j < num.size(); j++) {
			sum += num[j];
			if (sum >= b) {
				if (j - i < min) {
					min = j - i;
				}
			}
		}
	}
	output << min + 1<<"\n";
	input.close();
	output.close();
}