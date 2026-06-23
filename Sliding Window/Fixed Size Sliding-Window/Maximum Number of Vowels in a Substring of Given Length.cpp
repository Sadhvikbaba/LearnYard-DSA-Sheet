class Solution {
private:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int n = s.size(), cnt = 0, maxCnt = 0;

        for(int i = 0; i < k; i++) {
            if(isVowel(s[i]))cnt++;
        }

        int r = k, l = 0;
        maxCnt = cnt;

        while(r < n) {
            if(isVowel(s[r++])) cnt++;

            if(isVowel(s[l++])) cnt--;
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};