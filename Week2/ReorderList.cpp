//https://leetcode.com/problems/reorder-list/

class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head || !head->next) return;

		ListNode *slow = head, *fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode *prev = nullptr, *curr = slow, *next = nullptr;
		while (curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		ListNode *p1 = head, *p2 = prev;
		while (p2->next) {
			ListNode *tmp = p1->next;
			p1->next = p2;
			p1 = tmp;

			tmp = p2->next;
			p2->next = p1;
			p2 = tmp;
		}
	}
};