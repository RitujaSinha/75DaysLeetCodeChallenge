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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> vec;

        if(head == NULL || head->next == NULL) return head;

        ListNode* temp= head;
        while(temp != NULL && temp->next != NULL){
            vec.push_back(temp->val);
            temp=temp->next->next;
        }

        if(temp) vec.push_back(temp->val);

        temp= head->next;
        while(temp != NULL && temp->next != NULL){
            vec.push_back(temp->val);
            temp=temp->next->next;
        }

        if(temp) vec.push_back(temp->val);

        int i =0;
        temp=head;
        while(temp != NULL){
            temp->val = vec[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};