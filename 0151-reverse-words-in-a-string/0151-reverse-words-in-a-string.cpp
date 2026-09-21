class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        for (char ch : s) {
            if (ch == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } 
            else {
                word += ch;
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string ans;
        for (int i = 0; i < words.size(); i++) {
            if (i > 0)
                ans += " ";
            ans += words[i];
        }

        return ans;
    }
};