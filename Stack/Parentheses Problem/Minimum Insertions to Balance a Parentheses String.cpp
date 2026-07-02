class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, need = 0;

        for(const char& ch : s) {
            if(ch == '(') {
                if(need & 1) {
                    ans++;
                    need--;
                }
                need += 2;
            } else {
                need--;

                if(need == -1) {
                    ans++;
                    need = 1;
                }
            }
        }
        return ans + need;
    }
};