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
        ListNode* temp = head;
        int cnt =0;
        
        if(head == NULL) return head;

        if(head->next == NULL) return NULL;
        
        while(temp != NULL){
            cnt++;
            temp=temp->next;
        }

        int middleNode = cnt/2 + 1;

        temp = head;
        while(temp != NULL){
            middleNode--;
            if(middleNode  == 1) break;
            temp=temp->next;
        }

        ListNode* delNode=temp->next;

        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};