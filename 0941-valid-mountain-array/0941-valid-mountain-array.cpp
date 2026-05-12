class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();

        if(n < 3) return false;

        if(arr[n-1] > arr[n-2]) return false;
        if(arr[0] > arr[1]) return false;

        for(int i = 1; i < n-1; i++){
            if(arr[i-1] == arr[i] || arr[i] == arr[i+1]) return false;
        }

        int peak = 0;
        for(int i = 1; i < n-1; i++){
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]) peak++;
        }

        return peak == 1;
    }
};