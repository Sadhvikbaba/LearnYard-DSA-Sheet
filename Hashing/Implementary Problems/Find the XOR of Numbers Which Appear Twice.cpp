class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<bool> check(51, false);
        int xor1 = 0;

        for(int it : nums){
            if(check[it]) xor1 ^= it;
            else check[it] = true;
        }

        return xor1;
    }
};