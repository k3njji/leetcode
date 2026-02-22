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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int count = 0;
        while(curr){
            count++;
            curr = curr->next;
        }

        int target = count - n;

        curr = head;
        if(target == 0){
            if(head->next){

                ListNode* temp = curr->next;
                curr->next = NULL;
                // free(curr);
                return temp;
            }else{
                return NULL;
            }
        }else{
            // curr = head;
            int count = 1;
            while(curr){
                cout << count << target << endl;
                cout << curr->val << endl;
                if(count == target){
                    ListNode* temp = curr->next->next;
                    curr->next->next = NULL;
                    // free(curr->next);
                    curr->next = temp;
                    return head;
                }
                curr = curr->next;
                count++;
            }
        }

        return head;
    }
};