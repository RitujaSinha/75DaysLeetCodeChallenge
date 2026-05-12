class Solution {
public:
    bool isValid(vector<vector<int>>& tasks, int energy){
        int n = tasks.size();

        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b){
            return (a[1]-a[0]) > (b[1]-b[0]);
        });

        for(int i = 0; i < tasks.size(); i++){
            if(tasks[i][1] > energy) return false;

            energy = energy- tasks[i][0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        
        int st = 1;
        int sum = 0;
        for(auto &it: tasks){
            sum += it[1];
        }
        int end = sum;

        int ans = 0;
        while(st <= end){
            int mid = st + (end-st)/2;

            if(isValid(tasks, mid)){
                ans = mid;
                end = mid-1;
            } else{
                st=mid+1;
            }
        }
        return ans;
    }
};