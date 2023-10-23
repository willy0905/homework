#include "list.hpp"
// Write your implementation here.
// Feel free to add any code you need in this file.
int count_list_groups(int n, std::vector<ListNode*>& lists)
{
	std::vector<int> num(n);
	int count = 0;
	for (int i = 0; i < n; i++) {
		num[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		while (lists[i]->next != NULL) {
			lists[i] = lists[lists[i]->next->id];
		}
		num[lists[i]->id] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (num[i] == 1) {
			count++;
		}
	}
	return count;
}
