/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* sortedHead = head;
        ListNode* unsortedHead = head->next;
        sortedHead->next = nullptr;

        while (unsortedHead != nullptr) {
            ListNode* curr = unsortedHead;
            unsortedHead = unsortedHead->next;

            if (curr->val < sortedHead->val) {
                curr->next = sortedHead;
                sortedHead = curr;
            } else {
                ListNode* search = sortedHead;
                while (search->next != nullptr && curr->val > search->next->val) {
                    search = search->next;
                }
                curr->next = search->next;
                search->next = curr;
            }
        }

        return sortedHead;
    }
};
