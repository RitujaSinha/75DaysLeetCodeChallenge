class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0) return false;

        unordered_map<int, int> freq;
        for(int num: hand){
            freq[num]++;
        }

        sort(hand.begin(), hand.end());
        for(int i = 0; i < n; i++){
            if(freq[hand[i]] == 0) continue;

            int start = hand[i];

            for(int j = 0; j < groupSize; j++){
                int card = start + j;

                if(freq[card] == 0) return false;
                freq[card]--;
            }
        }

        return true;
    }
};