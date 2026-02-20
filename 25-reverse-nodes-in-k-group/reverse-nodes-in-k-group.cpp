class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // head tail start end startTemp endTemp
        if(!head || k == 1) return head;

        ListNode* dummyHead = new ListNode(0);     
        dummyHead->next = head;   
        ListNode* curr = head;
        ListNode* start = dummyHead;
        int count = 0;

        while(curr){
            count++;

            if(count == k){
                ListNode* starting = start->next;
                ListNode* ending = curr->next;

                ListNode* prev = ending;
                ListNode* trav = starting;


                while(count!=0){
                    ListNode* temp = trav->next;
                    trav->next = prev;
                    prev = trav;
                    trav = temp;
                    count--;
                }

                start->next = prev;

                start = starting;
                curr = ending;

            }else{
                curr = curr->next;
            }
        }

        return dummyHead->next;
    }
};
