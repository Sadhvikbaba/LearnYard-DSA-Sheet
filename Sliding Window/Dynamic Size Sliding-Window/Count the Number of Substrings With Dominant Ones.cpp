class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        long long ans = 0;

        long long len = 0;
        for(char c : s) {
            if(c == '1') {
                len++;
                ans += len;
            } else {
                len = 0;
            }
        }

        for(int i = 1; i * i + i <= n; i++) {
            int zeroes = 0, l = 0, eones = 0;
            for(int right = 0; right < n; right++) {
                if(s[right] == '0') {
                    zeroes++;
                    eones = 0;
                }
                while(zeroes > i) {
                    if(s[l] == '0') zeroes--;
                    l++;
                    eones = 0;
                }

                while(zeroes == i && l <= right && s[l] == '1') {
                    eones++;
                    l++;
                }

                if(zeroes == i) {
                    int len = right - l + 1;
                    int temp = len - i;
                    int ones = temp + eones;
                    if(ones >= i * i) ans += min(eones + 1, ones - i * i + 1);
                }
            }
        }
        return (int)ans;
    }
};