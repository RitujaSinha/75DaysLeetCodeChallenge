/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL) return root;

        queue<TreeNode* > q;
        q.push(root);
        bool flag = false;

        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> level;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);

                level.push_back(node);
            }

            if(flag){
                int i = 0, j = level.size()-1;
                while(i < j){
                    swap(level[i]->val, level[j]->val);
                    i++; j--;
                }
            }
            flag =!flag;
        }
        return root;
    }
};