class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> vis(n+2, 0);

        for(int i =0; i < n; i++){
            vis[edges[i][0]]++;
            vis[edges[i][1]]++;
        }

        int count =0;
        int ans =0;
        for(int i =1; i < vis.size(); i++){
            if(count < vis[i]){
                count = vis[i];
                ans = i;
            }
        }
        return ans;
    }
};