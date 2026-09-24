class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            int sum=0;
            int n=nums[i];
            while(n) {
                int r=n%10;
                sum+=r;
                n/=10;
            }
            if(sum==i) {
                return i;
            }
        }
        return -1;
    }
};