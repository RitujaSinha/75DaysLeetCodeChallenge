class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();

        map<string, int> mpp;

        for(int i =0; i < n; i++){
            mpp[words[i]]++;
        }

        auto cmp = [](pair<int,string> &a, pair<int,string> &b){
            if(a.first == b.first)
                return a.second > b.second; // smaller word first
            return a.first < b.first;       // higher freq first
        };

        priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(cmp)> pq(cmp);
        
        for(auto &it: mpp){
            pq.push({it.second, it.first});
        }

        vector<string> result;

        while(!pq.empty() && k--){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};