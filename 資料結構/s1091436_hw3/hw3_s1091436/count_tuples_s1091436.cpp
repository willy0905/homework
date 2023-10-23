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
    vector<int>arr;
    int n, d,num=0;
    input >> n >> d;
    for (int i = 0; i < n; i++) {
        int tem;
        input >> tem;
        arr.push_back(tem);
    }
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            if (arr[i] <= arr[j] && arr[j] - arr[i] <= d) {
                for (int k = j+1; k < n; k++) {
                    if (arr[j] <= arr[k]  && arr[k] - arr[j] <= d) {
                        num++;
                    }
                }
            }
        }
    }
    ofstream output_file("output.txt", std::ios::binary);
    if (output_file.is_open()) {
        output_file << num << "\n";
        output_file.close();
    }
}