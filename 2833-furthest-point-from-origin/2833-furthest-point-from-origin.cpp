class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n  =moves.size();

        int left= 0, right =0;
        for(int i =0; i < n; i++){
            if(moves[i] == 'R') right++;
            else if(moves[i] == 'L') left++;
        }

        int curr1 =0;
        if(left > right){
            for(int  i=0; i < n; i++){
                if(moves[i] == '_') curr1++;
                else if(moves[i] == 'L') curr1++;
                else curr1--;
            }
        }

        int curr2 =0;
        if(left < right){
            for(int  i=0; i < n; i++){
                if(moves[i] == '_') curr2++;
                else if(moves[i] == 'R') curr2++;
                else curr2--;
            }
        }
        int curr3= 0;
        if(left == right){
            for(int  i=0; i < n; i++){
                if(moves[i] == '_') curr3++;
            }
        }
        return max({curr1, curr2, curr3});
    }
};