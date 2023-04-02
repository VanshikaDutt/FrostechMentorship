//https://leetcode.com/problems/swap-nodes-in-pairs/

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *newHead = head->next;
		head->next = swapPairs(newHead->next);
		newHead->next = head;
		return newHead;
	}
};
