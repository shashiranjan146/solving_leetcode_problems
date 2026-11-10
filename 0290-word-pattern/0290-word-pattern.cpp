class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string w = words[i];
            if (mp1.count(ch) && mp1[ch] != w)
                return false;
            if (mp2.count(w) && mp2[w] != ch)
                return false;

            mp1[ch] = w;
            mp2[w] = ch;
        }

        return true;
    }
};