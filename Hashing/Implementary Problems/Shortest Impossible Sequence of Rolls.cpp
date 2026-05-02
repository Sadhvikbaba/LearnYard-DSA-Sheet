class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> st;
        int count = 0;

        for(int& it : rolls){ 
            st.insert(it);
            if(st.size() == k){
                count++;
                st.clear();
            }
        }
        return count + 1;
    }
};