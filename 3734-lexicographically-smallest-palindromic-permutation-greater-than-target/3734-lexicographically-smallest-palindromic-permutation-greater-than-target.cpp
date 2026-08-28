class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";
        auto calendrix = s;
        vector<int> half(26);
        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        int m = n / 2;
        string prefix;
        auto feasible = [&](const string& pref, vector<int>& rem) {
            string left = pref;
            for (int c = 25; c >= 0; c--) {
                left += string(rem[c], char('a' + c));
            }

            string right = left;
            reverse(right.begin(), right.end());

            string candidate = left;
            if (n % 2)
                candidate += mid;
            candidate += right;

            return candidate > target;
        };
        for (int pos = 0; pos < m; pos++) {
            bool found = false;
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0)
                    continue;

                half[c]--;
                prefix.push_back('a' + c);

                if (feasible(prefix, half)) {
                    found = true;
                    break;
                }
                prefix.pop_back();
                half[c]++;
            }

            if (!found)
                return "";
        }
        string right = prefix;
        reverse(right.begin(), right.end());
        string ans = prefix;
        if (n % 2)
            ans += mid;

        ans += right;

        if (ans <= target)
            return "";

        return ans;
    }
};