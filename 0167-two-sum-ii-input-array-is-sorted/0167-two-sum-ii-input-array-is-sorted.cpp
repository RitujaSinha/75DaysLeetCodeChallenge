class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int i =0, j =n-1;
        while(i < j){ // = can't be allow optimization
            int pairs = numbers[i] + numbers[j];

            if(pairs > target) j--;
            else if(pairs < target) i++;
            else return {i+1, j+1};
        }
        return {-1, -1};
    }
};