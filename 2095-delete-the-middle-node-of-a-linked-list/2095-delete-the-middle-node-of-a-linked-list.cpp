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
    ListNode* deleteMiddle(ListNode* head) {
        // ListNode* fast = head;
        // ListNode* slow = head;

        // while(fast->next != NULL || fast != NULL){
        //     fast = fast->next->next;
        //     slow = slow->next;
        // }

        if(head ==  NULL || head->next == NULL) return NULL;

        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp ->next;
        }

        int middle = cnt/2;

        temp = head;
        while(middle!=1){
            middle--;
            temp = temp ->next;
        }

        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;

        return head;
    }
};