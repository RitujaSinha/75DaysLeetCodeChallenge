class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();

        unordered_multimap<int, int> m;

        for(int i=0; i< n; i++){
            m.insert({groupSizes[i] , i});
        }

        sort(groupSizes.begin(), groupSizes.end());

        vector<vector<int>> result;
        vector<int> temp;

        int l=0, r=0;
        int val =-1;
        while(r< n){
            val = groupSizes[l];

            int cnt = val;
            while(cnt--){
                auto it = m.find(val);  
                int v = it->second;
                temp.push_back(v);
                m.erase(it);             
                r++; 
            }

            result.push_back(temp);
            temp.clear();

            l=r;
        }
        return result;
    }
};