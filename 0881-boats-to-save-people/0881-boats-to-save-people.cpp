class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        sort(people.begin(), people.end());

        int boat = 0;

        int i = 0, j = n-1;
        while(i <= j){
            if(((people[i] + people[j]) <= limit) && i != j){
                boat++;
                i++; j--;
            } else if((people[j] > people[i]) && people[j] <= limit){
                boat++;
                j--;
            } else if((people[i] > people[j]) && people[i] <= limit){
                boat++;
                i++;
            } else if(i==j){
                boat++;
                i++;
                j--;
            } else{
                boat+=2;
                i++;
                j--;
            }
        }
        return boat;
    }
};