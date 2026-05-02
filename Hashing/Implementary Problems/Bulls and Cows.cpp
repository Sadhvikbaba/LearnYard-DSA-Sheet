class Solution {
public:
    string getHint(string secret, string guess) {
        int cows = 0, bulls = 0, n =secret.size();
        vector<int> count(10, 0);

        for(int i = 0; i < n; i++) {
            if(secret[i] == guess[i]) bulls++;
            else {
                int s = secret[i] - '0', g = guess[i] - '0';
                if(count[s] < 0) cows++;
                if(count[g] > 0) cows++;
                count[s]++;
                count[g]--;
            }
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};