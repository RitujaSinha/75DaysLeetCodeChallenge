class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        
        int n = words.size();

        int i = 1;

        if(words[startIndex] == target) return 0;//Hnadled it at the startIndex only

        while(i <= n){
            if(words[(startIndex + i) % n] == target || 
            words[(startIndex - i + n) % n] == target){
                return i;
            }
            i++;
        }
        return -1;
    }
};