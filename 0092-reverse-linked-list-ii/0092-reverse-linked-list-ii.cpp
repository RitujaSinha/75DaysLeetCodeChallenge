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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        vector<int> vec;
        ListNode* temp = head;
        while(temp != NULL){
            vec.push_back(temp->val);
            temp = temp ->next;
        }

        int i = left-1, j = right-1;
        while(i < j){
            swap(vec[i], vec[j]);
            i++; j--;
        }

        temp = head;
        int idx = 0;
        while(temp != NULL){
            temp->val=vec[idx++];
            temp = temp->next;
        }
        return head;
    }
};