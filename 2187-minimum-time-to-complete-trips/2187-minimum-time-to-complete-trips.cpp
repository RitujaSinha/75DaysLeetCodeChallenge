class Solution {
public:
    bool isValid(vector<int>& time, int totalTrips, long long minTime){
        long long trips = 0;

        for(int i =0; i < time.size(); i++){
            trips += minTime/time[i];

            if (trips >= totalTrips) return true;
        }
        return trips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        
         long long st = 1;
        // long long mini = *min_element(time.begin(), time.end());
        // long long end = mini * totalTrips;
        long long end = LLONG_MAX;

        long long ans =0;
        while(st <= end){
            long long mid= st + (end-st)/2;

            if(isValid(time, totalTrips, mid)){
                ans = mid;
                end=mid-1;
            } else{
                st = mid+1;
            }
        }
        return ans;
    }
};