class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& nums) {
        int n = nums.size();
        vector<unordered_set<string>> st(n);

        for(int i = 0; i < n; i++){
            for(string& str : nums[i]) {
                st[i].insert(str);
            }
        }

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            bool valid = true;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(st[i].size() > st[j].size()) continue;

                bool isSubset = true;
                for(const string& str : st[i]){
                    if(st[j].find(str) == st[j].end()){
                        isSubset = false;
                        break;
                    }
                }
                if(isSubset) {
                    valid = false;
                    break;
                }
            }
            if(valid)ans.push_back(i);
        }
        return ans;
    }
};