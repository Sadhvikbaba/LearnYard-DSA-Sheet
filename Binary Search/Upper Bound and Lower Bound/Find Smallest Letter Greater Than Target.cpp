class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0, high = letters.size() - 1, ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(letters[mid] <=target) low = mid + 1;
            else {
                if(letters[mid] != target) ans = mid;
                high = mid - 1;
            }
        }
        if(ans == -1) return letters[0];
        return letters[ans];
    }
};