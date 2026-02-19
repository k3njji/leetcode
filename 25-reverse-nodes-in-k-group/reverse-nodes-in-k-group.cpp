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

                while(count!=0){
                    ListNode* next = temp->next;
                    temp->next = prevNode;
                    prevNode = temp;
                    temp = next;
                    count--;
                }

                prev->next = prevNode;
                prev = groupStart;

                curr = nextGroup;
            }else{
                curr = curr->next;
            }
        }

        return dummyHead->next;
    }
};
