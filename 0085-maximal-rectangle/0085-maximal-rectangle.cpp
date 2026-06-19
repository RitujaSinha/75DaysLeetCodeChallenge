class Solution {
public:
    int hist(vector<int>& heights) {
          int n = heights.size();

          stack<int> st;

        int maxArea  =0;
          for(int i = 0; i < n; i++){

            while(!st.empty() && heights[st.top()] > heights[i]){
                
                int element = st.top(); st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, heights[element] * (nse-pse-1));

            }
            st.push(i);
          }


          while(!st.empty()){
            int element = st.top(); st.pop();

            int nse = n;
            int pse = st.empty() ? -1: st.top();

            maxArea = max(maxArea, heights[element] * (nse-pse-1));
          }
          return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> pSum(m, vector<int> (n));

        for(int col = 0; col < n; col++){
            int sum = 0;
            for(int row = 0; row < m; row++){
                sum += 1;

                if(matrix[row][col] == '0') sum = 0;

                pSum[row][col] = sum;
            }
        }

        int maxArea = 0;
        for(int i = 0; i < m; i++){
            maxArea = max(maxArea, hist(pSum[i]));
        }
        return maxArea;
    }
};