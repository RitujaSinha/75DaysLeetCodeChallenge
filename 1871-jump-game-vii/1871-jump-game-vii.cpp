class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        // unordered_multimap<char, int> m;
        // for(int i = 0; i < n; i++){
        //     if(s[i] == '0')
        //     m.insert({s[i], i});
        // }

        int farthest = 0;

        while(!q.empty()){
            int index = q.front();
            q.pop();

            if(index==n-1) return true;

            // for(int j = 0; j < n; j++){
            //     if(s[j]=='0'){
            //         if(index+minJump <= j && j <= min(index+maxJump, n-1)){
            //             if(!vis[j]){
            //                 q.push(j);
            //                 vis[j] = 1;
            //             }
            //         }
            //     }
            // }

            // auto range = m.equal_range('0');

            // for(auto it= range.first; it!= range.second;){
            //     int j = it->second;
            //         if(index+minJump <= j && j <= min(index+maxJump, n-1)){
            //             if(!vis[j]){
            //                 q.push(j);
            //                 vis[j] = 1;
            //             }
            //             it = m.erase(it);
            //         } else ++it;
            //     }
            // }


            int start = max(index+minJump, farthest);
            int end = min(index+maxJump, n-1);

            for(int j = start; j <= end; j++){
                if(!vis[j] && s[j] == '0'){
                    q.push(j);
                    vis[j] = 1;
                }
            }
            farthest = end+1;
        }
        
        return false;
    }
};