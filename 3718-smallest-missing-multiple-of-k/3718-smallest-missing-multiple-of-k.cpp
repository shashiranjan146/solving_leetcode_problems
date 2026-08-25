class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // unordered_set<int> st(nums.begin(), nums.end());
        // for (int i = 1; ; i++) {
        //     int multiple = i * k;
        //     if (st.find(multiple) == st.end()) {
        //         return multiple;
        //     }
        // }
        vector<bool> freq(101,0);
        for(int i=0;i<nums.size();i++)
        freq[nums[i]] = 1;
        int i = k;
        while(i <= 100) {
            if(!freq[i])
            return i;
            i += k;
        }
        return ((100 / k) + 1) * k;
    }
};