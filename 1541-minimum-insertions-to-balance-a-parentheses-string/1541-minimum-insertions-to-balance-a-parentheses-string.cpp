class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int open = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } 
            else {
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } 
                else {
                    ans++;
                }
                if (open == 0) {
                    ans++;
                } 
                else {
                    open--;
                }
            }
        }
        ans += 2 * open;
        return ans;
    }
};