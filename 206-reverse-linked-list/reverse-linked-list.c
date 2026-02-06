/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* curr = head;
    struct ListNode* tail = NULL;

    while(curr){
        struct ListNode* temp = curr;
        curr = curr->next;

        temp->next = tail;
        tail = temp;        
    }

    return tail;
}