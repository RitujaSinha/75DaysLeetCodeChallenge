class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        set<int> st;

        for(int i =0; i < nums1.size(); i++){
            st.insert(nums1[i]);
        }
        
        for(int i =0; i < nums2.size(); i++){
            st.insert(nums2[i]);
        }
        if(st.size() == 2 * n) return -1; // Invalid

        unordered_map<int, int> mpp;
        unordered_map<int, int> mpp2;
        for(int i =0; i < n; i++){
            mpp[nums1[i]]++;
        }

        for(int i =0; i < n; i++){
            mpp2[nums2[i]]++;
        }

        if(mpp == mpp2) return 0;

        unordered_map<int, int> mpp1;
         for(int i =0; i < n; i++){
            mpp1[nums1[i]]++;
        }
         for(int i =0; i < n; i++){
            mpp1[nums2[i]]++;
        }

        for(auto &it: mpp1){
            if(it.second % 2 == 1){
                return -1;
            }
        }

        if(mpp.size() ==1 && mpp2.size() ==1){
            int size = n;

            return n/2;
        }

        vector<int> arr1;
        vector<int> arr2;
        for(auto &it: mpp){
            arr1.push_back(it.second);
        }
         for(auto &it: mpp){
            arr2.push_back(it.second);
        }

        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int l=0, r=0;
        bool ok = false;
        while(l < arr1.size() && r < arr2.size()){
            if(arr1[l] != arr2[r]) break;
            else ok= true;
        }

        if(ok) return 1;
        
        int op =0;
        for(int i =0; i < n; i++){
            if(mpp.find(nums2[i]) == mpp.end()){
                op++;
            }
        }

        if(mpp.size() ==2 && mpp2.size() == 1) return 1;

        return op == 0 ? 0 : op/2;
    }
};