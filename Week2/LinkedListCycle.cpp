//https://leetcode.com/problems/linked-list-cycle/

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr) {
			return false;
		}

		ListNode* slow = head;
		ListNode* fast = head->next;

		while (fast != nullptr && fast->next != nullptr) {
			if (slow == fast) {
				return true;
			}

			slow = slow->next;
			fast = fast->next->next;
		}

		return false;
	}
};