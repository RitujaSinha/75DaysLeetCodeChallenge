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
    ListNode* removeNodes(ListNode* head) {
        if(head  == NULL || head->next == NULL) return head;
        ListNode* temp = head;

        vector<int> nums;
        while(temp != NULL){
            nums.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> res;
        int maxi = INT_MIN;

        for(int i = nums.size()-1; i >= 0; i--){
            if(maxi <= nums[i]){
                res.push_back(nums[i]);
                maxi = nums[i];
            }
        }
        reverse(res.begin(), res.end());

        ListNode* newHead = new ListNode(res[0]);
        ListNode* curr = newHead;

        for(int i =1; i < res.size(); i++){
            curr->next = new ListNode(res[i]);
            curr = curr->next;
        }
        return newHead;
    }
};