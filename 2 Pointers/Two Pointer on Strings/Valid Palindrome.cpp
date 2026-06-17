class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(const char& ch : s) {
            if(ch == ' ') continue;
            if('A' <= ch && ch <= 'Z') temp.push_back(ch + 32);
            else if('a' <= ch && ch <= 'z') temp.push_back(ch);
            else if('0' <= ch && ch <= '9') temp.push_back(ch);
        }
        int i = 0, j = temp.size() - 1;

        while(i <= j){
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};