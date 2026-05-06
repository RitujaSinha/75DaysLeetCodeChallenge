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
    int pairSum(ListNode* head) {
        ListNode* temp = head;

        vector<int> a;
        while(temp != NULL){
            a.push_back(temp->val);
            temp = temp->next;
        }

        int maxi = -1;
        int n = a.size();
        for(int i = 0; i <= (n/2)-1; i++){
            maxi = max(a[i] + a[n-1-i], maxi);
        }
        return maxi;
    }
};