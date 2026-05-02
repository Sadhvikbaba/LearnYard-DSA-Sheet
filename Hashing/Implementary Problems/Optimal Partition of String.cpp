class Solution {
public:
    int partitionString(string s) {
        int mask = 0;
        int count = 1;

        for (char c : s) {
            int bit = c - 'a';

            if (mask & (1 << bit)) {
                count++;
                mask = 0;
            }

            mask |= (1 << bit);
        }

        return count;
    }
};