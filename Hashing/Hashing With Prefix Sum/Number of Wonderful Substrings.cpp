class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long> freq(1024, 0);
        long long ans = 0;
        int mask = 0;
        freq[0] = 1;

        for(const char& ch : word) {
            int ind = ch - 'a';
            mask ^= 1 << ind;
            ans += freq[mask];
            for(int i = 0; i < 10; i++) {
                ans += freq[mask ^ (1 << i)];
            }
            freq[mask]++;
        }
        return ans;
    }
};