/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL) return 0;

        queue<pair<Node*, int>> q;
        q.push({root, 1});

        int maxDepth = 0;
        while(!q.empty()){
            int size = q.size();
            
            for(int i =0; i < size; i++){
                Node* node = q.front().first;
                int depth = q.front().second;
                q.pop();

                maxDepth = max(depth, maxDepth);

                for(auto child: node->children){
                    q.push({child, depth+1});
                }
            }
        }
        return maxDepth;
    }
};