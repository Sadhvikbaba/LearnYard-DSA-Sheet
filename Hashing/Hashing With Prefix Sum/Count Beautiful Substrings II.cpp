class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        int n = s.size();
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            char it = s[i];
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') arr[i] = 1;
            else arr[i] = -1;
        }
        int d = 1, balance = 0, ans = 0;
        while((1LL * d * d) % (4 * k) != 0) d++;

        map<pair<int,int>, int> mpp;
        mpp[{0, d - 1}] = 1;

        for(int i = 0; i < n; i++) {
            balance += arr[i];
            ans += mpp[{balance, i % d}];
            mpp[{balance, i % d}]++;
        }

        return ans;

    }
};