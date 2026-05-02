class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> mpp;
        vector<int> count(10, 0);

        for(char& ch : s)mpp[ch]++;

        count[0] = mpp['z'];
        count[2] = mpp['w'];
        count[4] = mpp['u'];
        count[6] = mpp['x'];
        count[8] = mpp['g'];
        count[1] = mpp['o'] - count[0] - count[2] - count[4];
        count[3] = mpp['h'] - count[8];
        count[5] = mpp['f'] - count[4];
        count[7] = mpp['s'] - count[6];
        count[9] = mpp['i'] - count[5] - count[8] - count[6];

        string ans = "";

        for(int i = 0; i < 10; i++){
            while(count[i]--) ans.push_back(i + '0');
        }

        return ans;

    }
};