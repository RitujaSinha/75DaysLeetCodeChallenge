class Solution {
public:
    bool judgeCircle(string moves) {
        int n =moves.size();

        // int sum = 0;
        // for(int i = 0; i < n; i++){
        //     if(moves[i] == 'U') sum += 1;
        //     else if(moves[i] == 'D') sum-=1;
        //     else if(moves[i] == 'R') sum+=1;
        //     else if(moves[i] == 'L') sum-=1;
        // }
        // return sum==0;

        int down = 0, right =0, left =0, upper=0;
        
        for(int i = 0; i < n; i++){
            if(moves[i] == 'U') upper++;
            else if(moves[i] == 'D') down+=1;
            else if(moves[i] == 'R') right+=1;
            else if(moves[i] == 'L') left+=1;
        }
        return (upper == down) && (right == left);
    }
};