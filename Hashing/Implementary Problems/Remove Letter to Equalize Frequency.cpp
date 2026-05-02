class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> mpp;

        for(char& ch : word) mpp[ch]++;
        int cnt = 0, ans = 0;
        unordered_map<int, int> mpp2;

        for(auto& it : mpp){
            mpp2[it.second]++;
        }

        if(mpp2.size() == 1){
            auto it = mpp2.begin();
            return (it -> first == 1 || it -> second == 1);
        }

        if(mpp2.size() == 2){
            auto it1 = mpp2.begin();
            auto it2 = next(it1);

            int f1 = it1->first, c1 = it1->second;
            int f2 = it2->first, c2 = it2->second;

            if(f1 > f2){
                swap(f1, f2);
                swap(c1, c2);
            }

            if(f1 == 1 && c1 == 1) return true;
            if(f2 == f1 + 1 && c2 == 1) return true;
        }
        return false;
    }
};