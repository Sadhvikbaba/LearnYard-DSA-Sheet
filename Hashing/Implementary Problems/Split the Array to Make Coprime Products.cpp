class Solution {
private:
    static vector<int> getPrimeFactors(int num) {
        vector<int> factors;

        for(int i = 2; i * i <= num; i++) {
            if(num % i == 0) {
                factors.push_back(i);

                while(num % i == 0) num /= i;
            }


        }
        if(num > 1) factors.push_back(num);
        return factors;
    }

public:
    int findValidSplit(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size(), lastMax = 0;
        vector<vector<int>> mpp2(n);

        for(int i = 0; i < n; i++) {
            mpp2[i] = getPrimeFactors(nums[i]);
            
            for(const int& it : mpp2[i]) mpp[it] = i;
        }

        for(int i = 0; i < n; i++) {
            for(const int& it : mpp2[i]) {
                lastMax = max(lastMax, mpp[it]);
            }

            if(i == lastMax && i < n - 1) return i;
        }
        return -1;
    }
};