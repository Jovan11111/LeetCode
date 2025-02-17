
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *cur = head;
        int len = 1;
        if (!head || !head->next) return head;
        while (cur->next) {
            cur = cur->next;
            len++;
        }
        cur->next = head;
        k = len - k % len;
        while (k > 1) {
            head = head->next;
            k--;
        }
        cur = head->next;
        head->next = nullptr;
        return cur;
    }
};