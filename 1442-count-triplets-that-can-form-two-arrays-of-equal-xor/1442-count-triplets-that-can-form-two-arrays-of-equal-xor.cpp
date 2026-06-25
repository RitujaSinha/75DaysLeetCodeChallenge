class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();

        int count = 0;
        for(int i = 0; i < n; i++){
            int a  = 0;

            for(int j = i; j < n; j++){
                int b = 0;
                a^=arr[j];

                for(int k = j+1; k < n; k++){
                    b^= arr[k];

                    if(a == b) count++;
                }
            }
        }
        return count;
    }
};