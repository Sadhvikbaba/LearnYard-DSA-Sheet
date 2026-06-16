class Solution {
public:
    int nextGreaterElement(int num) {

        string a = to_string(num);
        int n = a.size(), ind = -1;

        for(int i = n-2 ; i >= 0 ; i-- ){
            if(a[i] < a[i+1]){
                ind = i;
                break;
            }
        }

        if(ind == -1)return - 1;

        for(int i = n-1 ; i >= 0 ; i--){
            if(a[ind] < a[i]){
                swap(a[ind] , a[i]);
                break;
            }
        }
        reverse(a.begin() + ind + 1 , a.end());
        long long ans = stol(a);

        if(ans > INT_MAX) return -1;
        return ans;
        
    }
};