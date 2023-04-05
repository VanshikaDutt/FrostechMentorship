//https://leetcode.com/problems/palindrome-linked-list/
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next) {
			return true;
		}
		ListNode *slow = head, *fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *prev = nullptr, *curr = slow->next, *next;
		while (curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		ListNode *p1 = head, *p2 = prev;
		while (p2) {
			if (p1->val != p2->val) {
				return false;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		curr = prev, prev = nullptr;
		while (curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		slow->next = prev;

		return true;
	}
};