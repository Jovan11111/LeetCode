
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *ret = new ListNode(0);
        ret->next = head;
        ListNode *h1 = ret;
        ListNode *h2 = ret;

        for (int i = 0; i <= n; i++) {
            h1 = h1->next;
        }

        while (h1) {
            h1 = h1->next;
            h2 = h2->next;
        }

        h2->next = h2->next->next;

        return ret->next;
    }
};
