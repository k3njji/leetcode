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
    void reorderList(ListNode*& head) {
        stack<int> max_pq;
        queue<int> min_pq;

        ListNode* curr = head;
        int count = 0;

        while(curr){
            min_pq.push(curr->val);
            // max_pq.push(curr->val);

            curr = curr->next;
            count++;
        }

        queue<int> temp_min = min_pq;

        while(!temp_min.empty()){
            max_pq.push(temp_min.front());
            temp_min.pop();
        }
        
        int temp = count / 2;

        // ListNode* heads = nullptr;
        // ListNode* ans = nullptr;

        while(temp != 0){

            // ListNode* node = new ListNode(min_pq.top());
            // min_pq.pop();

            // if(!heads){
                // heads = node;
                // ans = heads;
                // head->val = min_pq.top();

            // }else{
                // ans->next = node;
                // ans = ans->next;
            // }
            head->val = min_pq.front();
            head = head->next;
            // ListNode* node2 = new ListNode(max_pq.top());
            // max_pq.pop();
            head->val = max_pq.top();
            head = head->next;
            max_pq.pop();
            min_pq.pop();
            // ans->next = node2;
            // ans = ans->next;

            temp--;
        }

        if(count % 2 != 0){
            // ListNode* node3 = new ListNode(min_pq.top());
            head->val = min_pq.front();
            // ans->next = node3;
            // ans = ans->next;
        }

        // while(heads){
        //     cout << heads->val;
        //     heads = heads->next;
        // }

        // head = heads;
    }
};