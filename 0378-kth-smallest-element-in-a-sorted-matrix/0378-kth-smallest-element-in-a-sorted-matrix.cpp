class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        vector<int> arr;
        for(int i  =0; i < n; i++){
            for(int j =0; j < n; j++){
                arr.push_back(matrix[i][j]);
            }
        }

        priority_queue<int> pq;
        for(int i = 0; i < n*n; i++){
            pq.push(arr[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};