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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(0); 
        ListNode* lessPtr = lessHead;          
        ListNode* greaterHead = new ListNode(0);  
        ListNode* greaterPtr = greaterHead;       
        
        while (head != nullptr) {
            if (head->val < x) {
                lessPtr->next = head;
                lessPtr = lessPtr->next;
            } else {
                greaterPtr->next = head;
                greaterPtr = greaterPtr->next;
            }
            
            head = head->next;
        }
        
        greaterPtr->next = nullptr;  
        lessPtr->next = greaterHead->next;  
        
        return lessHead->next; 
    }
};
