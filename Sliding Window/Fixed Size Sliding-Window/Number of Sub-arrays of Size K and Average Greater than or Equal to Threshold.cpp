class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int left = 0, right = 0, sum = 0, ans = 0;
        for(; right < k; right++) {
            sum += arr[right];
        }
        double avg = (double)sum / k;
        if(avg >= threshold) ans++;

        while(right < n) {
            sum += arr[right++];
            sum -= arr[left++];
            
            avg = (double)sum / k;
            if(avg >= threshold) ans++;
        }
        return ans;
    }
};