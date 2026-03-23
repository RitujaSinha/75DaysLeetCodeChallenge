class Solution {
public:
    int minDeletions(string s) {
        int n =s.size();

        unordered_map<int, int> m;
        for(int i =0; i<n; i++){
            m[s[i]]++;
        }

        vector<int> temp;
        for(auto &it: m){
            temp.push_back(it.second);
        }

        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;

        int op=0;
        mp[temp[0]]++;
        for(int i=1; i < temp.size(); i++){
            if(mp.find(temp[i]) != mp.end()){
                int val = temp[i];
                val--;
                op++;
                while(val > 0 && mp.find(val) != mp.end()){
                    val--;
                    op++;
                }
                mp[val]++;
                continue;
            }
            mp[temp[i]]++;
        }
        return op;
    }
};