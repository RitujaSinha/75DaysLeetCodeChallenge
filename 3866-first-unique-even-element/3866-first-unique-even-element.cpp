class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();

        if(n ==1 && nums[0] % 2 ==0){
            return nums[0];
        }

        unordered_map<int, int> mpp;

        for(int i =0; i < n; i++){
            if(nums[i] % 2 == 0){
                mpp[nums[i]]++;
            }
        }

        vector<int> arr;

        for(auto &it: mpp){
            if(it.second == 1){
                arr.push_back(it.first);
            }
        }

        for(int i =0; i < n; i++){
            for(int j =0; j < arr.size(); j++){
                if(nums[i] == arr[j]){
                    return nums[i];
                }
            }
        }
        return -1;
    }
};