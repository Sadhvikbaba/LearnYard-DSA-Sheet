#include<numeric>

class Solution {
private: 
    int GCD(int a, int b) { 
        while(b) { 
            a %= b; 
            swap(a, b); 
        } 
        return a; 
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        int n = nums.size();

        for(const int& it : nums) {
            long long curr = it;

            while(!st.empty()) {
                long long temp = st.back();
                int gcd = GCD(temp, curr);
                if(gcd == 1) break;

                curr = (temp / gcd) * curr;
                st.pop_back();
            }
            st.push_back(curr);
        }
        return st;
    }
};