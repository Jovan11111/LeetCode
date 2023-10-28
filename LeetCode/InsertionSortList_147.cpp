
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
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return head;
        ListNode *sortedHead = head;
        ListNode *sortedTail = head;
        while (sortedTail->next) {
            if (sortedTail->val <= sortedTail->next->val) {
                sortedTail = sortedTail->next;
                continue;
            }
            ListNode *toBeInserted = sortedTail->next;
            sortedTail->next = sortedTail->next->next;
            if (toBeInserted->val < sortedHead->val) {
                toBeInserted->next = sortedHead;
                sortedHead = toBeInserted;
                continue;
            }
            ListNode *temp = sortedHead;

            while (temp->next and toBeInserted->val >= temp->next->val) temp = temp->next;
            toBeInserted->next = temp->next;
            temp->next = toBeInserted;
        }
        return sortedHead;

    }
};