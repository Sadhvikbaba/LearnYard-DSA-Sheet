class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        unordered_set<int> st;
        vector<vector<int>> ans;
        for(const auto& it : queens) st.insert(it[0] * 8 + it[1]);

        for(int i = king[1]; i >= 0; i--) {
            if(st.find(king[0] * 8 + i) != st.end()) {
                ans.push_back({king[0], i});
                break;
            }
        }

        for(int i = king[1]; i < 8; i++) {
            if(st.find(king[0] * 8 + i) != st.end()) {
                ans.push_back({king[0], i});
                break;
            }
        }

        for(int i = king[0]; i >= 0; i--) {
            if(st.find(i * 8 + king[1]) != st.end()) {
                ans.push_back({i, king[1]});
                break;
            }
        }

        for(int i = king[0]; i < 8; i++) {
            if(st.find(i * 8 + king[1]) != st.end()) {
                ans.push_back({i, king[1]});
                break;
            }
        }

        for(int i = king[0], j = king[1]; i < 8 && j < 8; i++, j++) {
            if(st.find(i * 8 + j) != st.end()) {
                ans.push_back({i, j});
                break;
            }
        }

        for(int i = king[0], j = king[1]; i >= 0 && j >= 0; i--, j--) {
            if(st.find(i * 8 + j) != st.end()) {
                ans.push_back({i, j});
                break;
            }
        }

        for(int i = king[0], j = king[1]; i >= 0 && j < 8; i--, j++) {
            if(st.find(i * 8 + j) != st.end()) {
                ans.push_back({i, j});
                break;
            }
        }

        for(int i = king[0], j = king[1]; i < 8 && j >= 0; i++, j--) {
            if(st.find(i * 8 + j) != st.end()) {
                ans.push_back({i, j});
                break;
            }
        }

        return ans;
    }
};