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
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int> vec;
        ListNode* temp = head;
        while(temp != NULL){
            vec.push_back(temp->val);
            temp = temp ->next;
        }

        // reverse(vec.begin(), vec.end());
        int n = vec.size();
        vector<int> ans(n, 0);

        stack<int> st;
        for(int i = n-1; i >=0; i--){
            while(!st.empty() && st.top() <= vec[i]){
                st.pop();
            }

            ans[i] = st.empty() ? 0 : st.top();
            st.push(vec[i]);
        }
        return ans;
    }
};