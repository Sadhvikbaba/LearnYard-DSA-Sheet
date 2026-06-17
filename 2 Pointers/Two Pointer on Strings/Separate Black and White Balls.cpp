class Solution {
public:
    long long minimumSteps(string s) {
        long long zero = 0, one = 0;
        int n = s.size();

        for(const char& ch : s) {
            if(ch == '0'){
                zero += one;
            } else one++;
        }
        return zero;
    }
};