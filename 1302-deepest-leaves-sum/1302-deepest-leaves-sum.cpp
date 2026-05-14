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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int maxDepth = 0;

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                int depth = q.front().second;
                q.pop();

                maxDepth = max(depth, maxDepth);

                if(node->left != NULL) q.push({node->left, depth+1});
                if(node->right != NULL) q.push({node->right, depth+1});
            }
        }

        queue<pair<TreeNode*, int>> q1;
        q1.push({root, 1});

        int sum = 0;
        while(!q1.empty()){
            int size= q1.size();

            for(int i =0; i < size; i++){
                TreeNode* node = q1.front().first;
                int d = q1.front().second;
                q1.pop();

                if(d == maxDepth){
                    sum += (node->val);
                }
                
                if(node->left != NULL) q1.push({node->left, d+1});
                if(node->right != NULL) q1.push({node->right, d+1});
            }
        }
        return sum;
    }
};