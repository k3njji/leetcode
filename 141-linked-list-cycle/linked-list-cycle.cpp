/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> mappu;

        ListNode* curr = head;

        while(curr){
            if(mappu[curr]){
                return true;
            }

            mappu[curr] = true;
            curr = curr->next;
        }

        return false;
    }
};