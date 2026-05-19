class Solution {
public:
    struct comp{
        bool operator() (string &a, string &b){
        if(a.size() == b.size()) return a>b;
        return a.size() > b.size();
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();

        priority_queue<string, vector<string>, comp> pq;

    
        for(auto &num: nums){
            pq.push(num);
            if(!pq.empty() && pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};