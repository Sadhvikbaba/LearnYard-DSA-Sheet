class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size() , ind = -1;

        for(int i = n-2 ; i >= 0 ; i-- ){
            if(a[i] < a[i+1]){
                ind = i;
                break;
            }
        }

        if(ind == -1){
            reverse(a.begin() , a.end());
            return;
        }

        for(int i = n-1 ; i >= 0 ; i--){
            if(a[ind] < a[i]){
                swap(a[ind] , a[i]);
                break;
            }
        }
        reverse(a.begin() + ind + 1 , a.end());
    }
};