#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
struct Node
{
    int key, depth;
    struct Node* left, * right;
};
struct Node* newNode(int item, int depth)
{
    struct Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    temp->depth = depth;
    return temp;
}
int preorder(Node* root)
{
    int num = 0;
    if (root != NULL)
    {
        num += preorder(root->left);
        num += preorder(root->right);
        return num + root->key * root->depth;
    }
    else {
        return 0;
    }
}
vector<Node*> getTrees(vector<int>arr, int start, int end, int depth)
{
    vector<Node*> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<Node*> ltrees = getTrees(arr, start, i - 1, depth + 1);
        vector<Node*> rtrees = getTrees(arr, i + 1, end, depth + 1);
        for (int j = 0; j < ltrees.size(); j++)
        {
            for (int k = 0; k < rtrees.size(); k++)
            {
                Node* node = newNode(arr[i], depth);
                node->left = ltrees[j];
                node->right = rtrees[k];
                trees.push_back(node);
            }
        }
    }
    return trees;
}
int main()
{

    ifstream input("input.txt", ios::in);
    if (!input.is_open()) {
        cout << "Failed to open file.\n";
        return 1;
    }
    int size, num;
    input >> size;
    vector<int>arr;
    for (int i = 0; i < size; i++) {
        input >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    vector<Node*> trees = getTrees(arr, 0, arr.size() - 1, 1);
    int min = INT_MAX;
    cout << trees.size()<<endl;
    for (int i = 0; i < trees.size(); i++)
    {
        int sum = preorder(trees[i]);
        if (sum < min) {
            min = sum;
        }
    }
    ofstream output_file("output.txt", std::ios::binary);
    if (output_file.is_open()) {
        output_file << min << endl;
        output_file.close();
    }
    return 0;
}