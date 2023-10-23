#include<iostream> 
#include<string> 
using namespace std; 
int main() { 
	string str; 
	int fre[26] = { 0 }; 
	cin >> str; 
	for (int i = 0; i < str.length(); i++) { 
		if (str[i] >= 'a' && str[i] <= 'z') {
			fre[str[i] - 'a']++; 
		} 
	} 
	for (int i = 0; i < 26; i++) { 
		cout << fre[i] << " "; 
	} 
}