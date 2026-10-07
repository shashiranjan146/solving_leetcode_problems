class Solution {
public:
    unordered_set<string> ans;
    int n;
    void dfs(string &s, int i, int leftRemove, int rightRemove,int open, string &cur) {
        if (open < 0)
            return;

        if (i == n) {
            if (leftRemove == 0 &&
                rightRemove == 0 &&
                open == 0) {
                ans.insert(cur);
            }
            return;
        }
        if (n - i < leftRemove + rightRemove)
            return;

        char c = s[i];
        if (c == '(' && leftRemove > 0) {
            dfs(s, i + 1, leftRemove - 1,
                rightRemove, open, cur);
        }

        if (c == ')' && rightRemove > 0) {
            dfs(s, i + 1, leftRemove,
                rightRemove - 1, open, cur);
        }
        cur.push_back(c);
        if (c == '(') {
            dfs(s, i + 1, leftRemove,
                rightRemove, open + 1, cur);
        }
        else if (c == ')') {
            dfs(s, i + 1, leftRemove,
                rightRemove, open - 1, cur);
        }
        else {
            dfs(s, i + 1, leftRemove,
                rightRemove, open, cur);
        }

        cur.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        int leftRemove = 0;
        int rightRemove = 0;
        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {
                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }
        string cur;
        dfs(s, 0,
            leftRemove,
            rightRemove,
            0,
            cur);

        return vector<string>(ans.begin(), ans.end());
    }
};