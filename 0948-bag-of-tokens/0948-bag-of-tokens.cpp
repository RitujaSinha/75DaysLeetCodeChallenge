class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        sort(tokens.begin(), tokens.end());

        int score =0, maxScore =0;
        int i=0, j =n-1;
        while(i <= j){
            if(power >= tokens[i]){
                score++;
                maxScore = max(maxScore, score);
                power -=tokens[i];
                i++;
            } else if(score >=1){
                score--;
                power+=tokens[j];
                j--;
            } else{
                break;
            }
        }
        return maxScore;
    }
};