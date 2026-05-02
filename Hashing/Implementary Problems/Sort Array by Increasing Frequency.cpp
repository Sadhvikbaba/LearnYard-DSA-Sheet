class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>> check(201, {0, 0});

        for(int i = -100; i <= 100; i++) check[i + 100].second = i;

        for(int& it : nums) check[it + 100].first++;

        sort(check.begin(), check.end(), [](auto& a, auto& b){
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });

        vector<int> ans;

        for(int i = 0; i < 201; i++){
            while(check[i].first--) ans.push_back(check[i].second);
        }

        return ans;
    }
};