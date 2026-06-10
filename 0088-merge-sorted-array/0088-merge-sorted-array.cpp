class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> sort(m+n);
        int i = 0, j =0;
        int idx =0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                sort[idx++] = nums1[i++];
            } else{
                sort[idx++] = nums2[j++];
            }
        }

        while(j < n){
            sort[idx++] = nums2[j++];
        }

        while(i < m){
            sort[idx++] = nums1[i++];
        }

        
        for(int i = 0; i < m+n; i++){
            nums1[i] = sort[i];
        }
    }
};