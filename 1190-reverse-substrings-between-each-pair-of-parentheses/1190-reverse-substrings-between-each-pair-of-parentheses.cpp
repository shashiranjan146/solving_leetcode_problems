class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        stack<int> st;
        for (char c : s) {
            if (c == '(') {
                st.push(ans.size());
            }
            else if (c == ')') {
                int pos = st.top();
                st.pop();
                reverse(ans.begin() + pos, ans.end());
            }
            else {
                ans += c;
            }
        }
        return ans;
    }
};