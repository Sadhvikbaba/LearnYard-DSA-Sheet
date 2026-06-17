class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0, n = chars.size();

        while(i < n) {
            char ch = chars[i];
            int start = i;

            while(i < n && chars[i] == ch) i++;
            int cnt = i - start;
            chars[j++] = ch;
            if(cnt > 1) {
                for(const char& ch : to_string(cnt)) chars[j++] = ch;
            }
        }
        return j;
    }
};