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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next){
            return head;
        }

        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast){
            ListNode* gc = new ListNode();
            gc->val = gcd(slow->val, fast->val);
            gc->next = fast;
            slow->next = gc;
            slow = fast;
            fast = fast->next;
        }

        return head;
    }

private:
    int gcd(int a, int b){
        // cout << a << b << endl;
        while(b!=0){
            int temp = b;
            b = a%b;
            a = temp;
        }

        return a;
    }
};