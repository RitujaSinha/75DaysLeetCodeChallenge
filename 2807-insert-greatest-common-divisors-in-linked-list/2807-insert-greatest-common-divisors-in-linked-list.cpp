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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;

        while(temp->next != NULL){
            int n1 = temp->val;
            int n2 = temp->next->val;

            int res = __gcd(n1, n2);

            ListNode* newNode = new ListNode(res);

            // newNode->val = res;
            // newNode->next = NULL;

            newNode->next = temp->next;
            temp->next = newNode;

            temp=temp->next->next;
        }
        return head;
    }
};