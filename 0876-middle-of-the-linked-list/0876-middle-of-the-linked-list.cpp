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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;

        int count =0;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp=temp->next;
        }

        int middleNode = count/2+1;
        temp=head;

        while(temp != NULL){
            middleNode--;
            if(middleNode == 0){
                break;
            }
            temp=temp->next;
        }
        // ListNode* middle = temp->next;
        // temp->next = temp->next->next;

        // delete middle;
        return temp;
    }
};