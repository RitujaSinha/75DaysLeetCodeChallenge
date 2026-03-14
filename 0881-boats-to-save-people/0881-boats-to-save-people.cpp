class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        unordered_map<int, int> mpp;
        for(int i =0; i < n; i++){
            mpp[people[i]]++;
        }

        sort(people.rbegin(), people.rend());

        int boats =0;
        for(int i =0; i < n; i++){
            if(mpp.find(people[i]) != mpp.end()){
            if(people[i] <= limit){
                boats++;
                mpp[people[i]]--;
                if(mpp[people[i]] <= 0) mpp.erase(people[i]);
                int more = limit - people[i];

                // if(more > 0){
                //     if(mpp.find(more) != mpp.end()){
                //         mpp[more]--;
                //         if(mpp[more] <= 0) mpp.erase(more);
                //     }  
                // }

                while(more!=0){
                    if(mpp.find(more) != mpp.end()){
                        mpp[more]--;
                        if(mpp[more] <= 0) mpp.erase(more);
                        break;
                    } 
                    more--;
                }

            }
            }
        }
        return boats;
    }
};