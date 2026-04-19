class Solution {
public:
    int binarySearch(int idx, int target, vector<int>& nums){
        int n = nums.size();
        int st =0, end = n-1;

        int ans =0;
        while(st <= end){
            int mid = st + (end-st)/2;

            if(idx <= mid){
                if(target <= nums[mid]){
                    ans = mid-idx;
                    st = mid+1;
                } else{
                    end = mid-1;
                }
            } else{
                st = mid +1;
            }
        }
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int maxi = 0;
        for(int i =0; i < n1; i++){
            maxi = max(binarySearch(i, nums1[i], nums2), maxi);
        }
        return maxi;
    }
};