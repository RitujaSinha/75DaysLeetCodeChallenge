class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<int> vis(n, 0);
        queue<int> q; //index
        q.push(0);
        vis[0] = 1;

        int farthest = 0;

        while(!q.empty()){
            int index = q.front();
            q.pop();

            if(index== n-1) return true;

            int start = max(index +minJump, farthest);
            int end= min(index+ maxJump, n-1);

            for(int i = start; i <= end; i++){
                if(s[i] == '0' && !vis[i]){
                    q.push(i);
                    vis[i] = 1;
                }
            }
            farthest =end+1;
        }
        return false;
    }
};