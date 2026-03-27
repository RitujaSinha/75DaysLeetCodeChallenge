class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> t(n, 1);
        vector<int> prevIdx(n, -1);

        int maxL =1;
        int lastIdx = 0;

        for(int i =0; i < n; i++){
            for(int j =0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(t[i] < t[j]+1){
                        t[i] = t[j]+1;
                        prevIdx[i] = j;
                    }

                    if(t[i] > maxL){
                        maxL = t[i];
                        lastIdx =i;
                    }
                }
            }
        }

        vector<int> result;
        while(lastIdx != -1){
            result.push_back(nums[lastIdx]);
            lastIdx = prevIdx[lastIdx];
        }
        return result;
    }
};