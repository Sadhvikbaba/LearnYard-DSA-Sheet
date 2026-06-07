class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        for(const char& ch : customers) {
            penalty += (ch == 'Y');
        }
        int miniI = 0, n = customers.size(), miniPenalty = penalty;

        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') penalty--;
            else penalty++;

            if(miniPenalty > penalty) {
                miniPenalty = penalty;
                miniI = i + 1;
            }
        }

        return miniI;
    }
};