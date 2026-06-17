class Solution {
public:
    vector<int> findNSE(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);

        for(int i = n-1; i >=0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSE(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n);

        for(int i = 0; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> findNGE(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n);

        for(int i = n-1; i >=0 ; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> findPGE(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> pge(n);

        for(int i = 0; i < n ; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }


    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> nse = findNSE(nums);
        vector<int> pse = findPSE(nums);
        vector<int> nge = findNGE(nums);
        vector<int> pge = findPGE(nums);

        long long total = 0;
        for(int i = 0; i < n; i++){
            long long leftMin = i - pse[i];
            long long rightMin = nse[i]-i;

            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;

            long long smallest = leftMin * rightMin * nums[i];
            long long largest = leftMax * rightMax * nums[i];

            total += (largest-smallest);

        }
        return total;
    }
};