class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        int n = s.size();
        string prefix = "";
        for (int i = 0; i < n; i++) {
            int cur = target[i] - 'a';
            if (cnt[cur] > 0) {
                cnt[cur]--;
                prefix += target[i];
            } 
            else {
                for (int c = cur + 1; c < 26; c++) {
                    if (cnt[c] > 0) {
                        string ans = prefix;
                        ans += char('a' + c);
                        cnt[c]--;
                        for (int j = 0; j < 26; j++) {
                            ans += string(cnt[j], char('a' + j));
                        }

                        return ans;
                    }
                }
                break;
            }
            if (i == n - 1) {
                break;
            }
        }
        for (int i = prefix.size() - 1; i >= 0; i--) {
            cnt[prefix[i] - 'a']++;
            int cur = target[i] - 'a';
            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string ans = prefix.substr(0, i);
                    ans += char('a' + c);
                    cnt[c]--;
                    for (int j = 0; j < 26; j++) {
                        ans += string(cnt[j], char('a' + j));
                    }

                    return ans;
                }
            }
        }

        return "";

    }
};