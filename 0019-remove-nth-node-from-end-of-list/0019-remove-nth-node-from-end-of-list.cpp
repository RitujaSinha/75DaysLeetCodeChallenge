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
        ListNode* temp = head;

        if(head == NULL) return NULL;
        if(head -> next == NULL &&  n==1) return NULL;

        int count =0;
        while(temp != NULL){
            count++;
            temp=temp->next;
        }

        int nthNode = count - n;    
        temp=head;

        if(n == count) return head->next;

        int cnt =0;
        while(temp != NULL){
            cnt++;
            if(cnt == nthNode) break;
            temp= temp->next;
        }

        temp->next = temp->next->next;


        return head;
    }
};