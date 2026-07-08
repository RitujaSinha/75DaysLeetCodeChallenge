class Solution {
public:
    bool solve(int p1, int p2, int i,int j,bool flag, vector<int> &nums){
        if(i > j) return p1>= p2;


        int scorep1First = false, scorep1End = false;
        int scorep2First = false, scorep2End = false;
        int best1 = false, best2 = false;
        if(flag){
            scorep1First = solve(p1+nums[i], p2, i+1, j, !flag, nums);
            scorep1End = solve(p1+nums[j], p2, i, j-1, !flag, nums);

            best1  =scorep1First || scorep1End;
            return best1;
        } 

            scorep2First = solve(p1, p2+nums[i], i+1, j, !flag, nums);
            scorep2End = solve(p1, p2+nums[j], i, j-1, !flag, nums);

            best2  = scorep2First && scorep2End;
            return best2;
        
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve(0, 0, 0,nums.size()-1,1, nums);
    }
};