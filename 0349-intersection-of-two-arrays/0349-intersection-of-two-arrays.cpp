class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        if(n1 == 1 && n2 == 1 && nums1[0] ==nums2[0]) {
            res.push_back(nums1[0]);
            return res;
        }

        if(n2 == 1){
            for(int i = 0; i < n1; i++){
                if(nums1[i] == nums2[0]){
                    res.push_back(nums2[0]);
                    return res;
                }
            }
        }

         if(n1 == 1){
            for(int i = 0; i < n2; i++){
                if(nums2[i] == nums1[0]){
                    res.push_back(nums1[0]);
                    return res;
                }
            }
        }

        int i = 0, j = 0;
        while(i < n1 && j < n2){
            if(i > 0 && nums1[i] == nums1[i-1]){
                i++;
                continue;
            }

            if(j > 0 && nums2[j] == nums2[j-1]){
                j++;
                continue;
            }
            
            if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                i++; j++;
            } else if(nums1[i] < nums2[j]){
                i++; 
            } else{
                j++;
            }
        }
        return res;
    }
};