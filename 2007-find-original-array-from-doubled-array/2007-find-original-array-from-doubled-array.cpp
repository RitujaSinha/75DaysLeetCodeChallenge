class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();

        if(n % 2 == 1) return {};

        sort(changed.begin(), changed.end());

        unordered_map<int, int> mp;
        for(int &n: changed){
            mp[n]++;
        }

        vector<int> original;

        for(int i = 0; i < n; i++){

            if(mp.find(changed[i]) == mp.end()) continue; 

            if(changed[i] == 0){
                if(mp.find(0) != mp.end()){
                    if(mp[0] <= 1) continue;
                }
            }

            if(mp.find(changed[i]*2) != mp.end()){
                mp[changed[i]]--;
                mp[changed[i]*2]--;
                if(mp[changed[i]] == 0) mp.erase(changed[i]);
                if(mp[changed[i]*2] == 0) mp.erase(changed[i]*2);
                original.push_back(changed[i]);
            }
        }

        if(original.size() != n/2) return {};
        return original;
    }
};