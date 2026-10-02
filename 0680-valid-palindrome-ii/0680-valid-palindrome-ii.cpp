class Solution {
private:
    bool Ispallindromic(string s,int left,int right) {
        while(left<right) {
            if(s[left]!=s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<r) {
            if(s[l]!=s[r]) {
               return Ispallindromic(s,l+1,r) || Ispallindromic(s,l,r-1);
            }
            l++;
            r--;
        }
        return true;
    }
};