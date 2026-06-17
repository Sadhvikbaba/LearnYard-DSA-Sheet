class Solution {
public:
    bool canChange(string start, string target) {
        int r = 0, l = 0, n = start.size();

        while(l < n && r < n) {
            while(l < n && start[l] == '_')l++;
            while(r < n && target[r] == '_')r++;

            if(l == n || r == n) break;

            if(start[l] != target[r]) return false;
            
            if(start[l] == 'R' && r < l) return false;
            if(start[l] == 'L' && l < r) return false;
            l++;
            r++;
        }

        while(l < n && start[l] == '_') l++;
        while(r < n && target[r] == '_') r++;

        return l == n && r == n;
    }
};