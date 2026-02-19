class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* prev = dummyHead;
        ListNode* curr = head;
        int count = 0;

        while(curr){
            count++;

            if(count == k){
                ListNode* groupStart = prev->next;
                ListNode* nextGroup = curr->next;

                ListNode* temp = groupStart;
                ListNode* prevNode = nextGroup;

                while (temp != nextGroup) {
                    ListNode* next = temp->next;
                    temp->next = prevNode;
                    prevNode = temp;
                    temp = next;
                }

                prev->next = prevNode;
                prev = groupStart;

                count = 0;

                curr = nextGroup;
            }else{
                curr = curr->next;
            }
        }

        return dummyHead->next;
    }
};
