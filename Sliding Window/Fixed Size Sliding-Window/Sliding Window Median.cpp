class Solution {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    unordered_map<int, int> mpp;
    int smallSize = 0, largeSize = 0;

    void rebalance() {
        while(smallSize > largeSize + 1) {
            large.push(small.top());
            small.pop();
            smallSize--;
            largeSize++;

            pruneSmall();
        }
        while(smallSize < largeSize) {
            small.push(large.top());
            large.pop();
            smallSize++;
            largeSize--;

            pruneLarge();
        }
    }

    void pruneSmall() {
        while(!small.empty() && mpp[small.top()] > 0) {
            mpp[small.top()]--;
            small.pop();
        }
    }

    void pruneLarge() {
        while(!large.empty() && mpp[large.top()] > 0) {
            mpp[large.top()]--;
            large.pop();
        }
    }

    void insert(int num) {
        if(small.empty() || num <= small.top()) {
            small.push(num);
            smallSize++;
        } else {
            large.push(num);
            largeSize++;
        }
        rebalance();
    }

    void erase(int num) {
        mpp[num]++;

        if(num <= small.top()) smallSize--;
        else largeSize--;

        if(!small.empty() && small.top() == num) pruneSmall();
        if(!large.empty() && large.top() == num) pruneLarge();

        rebalance();
    }

    double getMedian(int num) {
        if(num & 1) return small.top();
        return (1ll * small.top() + large.top()) / 2.0;
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        int left = 0, right = 0, n = nums.size();
        
        while(right < k) insert(nums[right++]);

        ans.push_back(getMedian(k));

        while(right < n) {
            insert(nums[right++]);

            erase(nums[left++]);

            ans.push_back(getMedian(k));
        }

        return ans;
    }
};