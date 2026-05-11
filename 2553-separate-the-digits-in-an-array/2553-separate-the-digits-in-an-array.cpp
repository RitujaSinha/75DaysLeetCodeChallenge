class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;
        for(int i = 0; i < n; i++){

            int num = nums[i];
            vector<int> temp;
            while(num > 0){
                int rem = num % 10;
                temp.push_back(rem);
                num /=10;
            }
            
            for(int i = temp.size()-1; i >=0; i--){
                res.push_back(temp[i]);
            }
        }
        return res;
    }
};