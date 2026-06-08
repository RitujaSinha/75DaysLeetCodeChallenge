class Solution {
public:
    int climbStairs(int n) {

        if(n==1 || n== 2) return n;
        
        int prevPrev = 1; // 1 steps to reach 1 stair
        int prev = 2;

        // i+1, i+2

        // -1, 0 // out of bound

        for(int i = 3; i < n+1; i++){
            int curr = prevPrev + prev;


            prevPrev = prev;
            prev = curr;
        }
        return prev;
    }
};

// 3

// 1, 2, 3

