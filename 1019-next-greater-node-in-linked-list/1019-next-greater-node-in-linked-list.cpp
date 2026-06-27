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
        if(head == NULL || head->next == NULL){
            return {};
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        temp = prev;
        stack<ListNode*> st;
        vector<int> ans;

        while(temp != NULL){

            while(!st.empty() && (st.top()->val) <= (temp->val)){
                st.pop();
            }

            if(st.empty()){
                ans.push_back(0);
            } else{
                ans.push_back(st.top()->val);
            }

            st.push(temp);
            temp = temp->next;
        }   

        reverse(ans.begin(), ans.end());
        return ans;
    }
};