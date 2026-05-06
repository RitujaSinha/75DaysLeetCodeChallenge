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
    void reorderList(ListNode* head) {
        ListNode* temp = head;

        vector<int> nums;
        while(temp != NULL){
            nums.push_back(temp->val);
            temp=temp->next;
        }

        int i = 0, j = nums.size()-1;

        vector<int> ans;
        while(i <= j){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++; j--;
        }
        
        temp = head;
        int idx = 0;
        while(temp != NULL){
            temp->val = ans[idx++];
            temp=temp->next;
        }
    }
};