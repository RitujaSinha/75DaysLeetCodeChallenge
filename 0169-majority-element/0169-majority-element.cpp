class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] == nums[j]) count++;

                if(count > n/2) return nums[i];
            }
        }
        return -1;
    }
};


// n/2 times

// i
// 3, 3, 2, 4, 3
             
// count = 3;

// 3 >5/2
// 3 is majprity element