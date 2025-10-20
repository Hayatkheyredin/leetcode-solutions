class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        int count = 0;
        while (i >= 0) {
            if (s[i] == ' ' && count == 0) {
                i--;
            } else if (s[i] == ' ' && count != 0) {
                break;
            } else {
                count++;
                i--;
            }
        }
        return count;
    }
};