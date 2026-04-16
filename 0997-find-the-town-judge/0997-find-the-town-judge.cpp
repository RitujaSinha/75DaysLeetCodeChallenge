class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> vis(n+1, 0);
        vis[0] =2;

        for(int i =0; i < trust.size(); i++){
            vis[trust[i][0]]++;
        }

        int judge = -1;
        for(int i =1; i < vis.size(); i++){
            if(vis[i] == 0){
                judge = i;
            }
        }

        if(judge == -1) return -1;

        int count =0;
        for(int i =0; i < trust.size(); i++){
            if(trust[i][1] == judge){
                count++;
            }
        }

        if(count == n-1) return judge;

        return -1;
    }
};