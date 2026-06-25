class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int ans= 0;
        for(int &n: derived){
            ans ^= n;
        }
        return ans==0;
    }
};