class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> ans;

        if(n == 0) return ans;

        unordered_map<int, int> x, y, p_diag, s_diag;
        unordered_set<long long> s;

        for(const auto& it : lamps) {
            if(s.insert(1ll * it[0] * n + it[1]).second) {
                x[it[0]]++;
                y[it[1]]++;
                p_diag[it[0] + it[1]]++;
                s_diag[it[0] - it[1]]++;
            }

            s.insert(1ll * it[0] * n + it[1]);
        }

        for(const auto& it : queries) {
            if(x[it[0]] > 0 || y[it[1]] > 0 || p_diag[it[0] + it[1]] > 0 || s_diag[it[0] - it[1]] > 0) {
                ans.push_back(1);
            } else ans.push_back(0);
            for(int i = -1; i <= 1; i++) {
                    for(int j = -1; j <= 1; j++) {
                        int qx = it[0] + i;
                        int qy = it[1] + j;
                        long long temp = 1ll * qx * n + qy;

                        if(qx >= 0 && qx < n && qy >= 0 && qy < n && s.count(temp)) {
                            s.erase(temp);
                            x[qx]--;
                            y[qy]--;
                            p_diag[qx + qy]--;
                            s_diag[qx - qy]--;
                        }
                    }
                }
        }
        return ans;
    }
};