class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i = 0, j = n-1;

        int maxWater = 0;
        while(i < j){
            int hei = min(height[i], height[j]);
            int width = j-i;

            maxWater = max(hei * width, maxWater);

            if(height[i] > height[j]) j--;
            else i++;
        }
        return maxWater;
    }
};