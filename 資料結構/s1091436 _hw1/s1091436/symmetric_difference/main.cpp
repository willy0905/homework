#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    int place = 0;
    set<int>mem1,mem2,mem;
    string str1,str2;
    getline(cin, str1);
    getline(cin, str2);
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] == 32){
            string str = str1.substr(place, i-place);
            int num = atoi(str.c_str());
            if (!mem1.count(num)) {
                mem1.insert(num);
            }
            place = i + 1;
        }
        if (i == str1.length() - 1) {
            string str = str1.substr(place);
            int num = atoi(str.c_str());
            if (!mem1.count(num)) {
                mem1.insert(num);
            }
        }
    }
    place = 0;
    for (int i = 0; i < str2.length(); i++) {
        if (str2[i] == 32) {
            string str = str2.substr(place, i - place);
            int num = atoi(str.c_str());
            if (!mem2.count(num)) {
                mem2.insert(num);
            }
            place = i+1;
        }
        if (i == str2.length() - 1) {
            string str = str2.substr(place);
            int num = atoi(str.c_str());
            if (!mem2.count(num)) {
                mem2.insert(num);
            }
        }
    }
    for (int i : mem1) {
        mem.insert(i);
    }
    for (int i : mem2) {
        if (mem.count(i)) {
            mem.erase(i);
        }
        else {
            mem.insert(i);
        }
    }
    for (int i : mem) {
        cout << i << " ";
    }
}
