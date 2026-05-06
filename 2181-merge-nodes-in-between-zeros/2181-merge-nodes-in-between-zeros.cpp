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
    ListNode* mergeNodes(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;

        ListNode* temp = head;
        temp=temp->next;

        vector<int> a;
        int sum  =0;
        while(temp != NULL){
            sum += (temp->val);

            if(temp ->val == 0){
                a.push_back(sum);
                sum = 0;
            }
            temp= temp->next;
        }

        ListNode* newHead = new ListNode(a[0]);
        ListNode* curr = newHead;

        for(int i =1; i < a.size(); i++){
            curr->next = new ListNode(a[i]);
            curr=curr->next;
        }
        return newHead;
    }
};