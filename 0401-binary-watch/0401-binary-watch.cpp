class Solution {
public:
    int countBits(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                int bits = countBits(hour) + countBits(minute);
                if (bits == turnedOn) {
                    string time = to_string(hour) + ":";
                    if (minute < 10)
                        time += "0";

                    time += to_string(minute);
                    ans.push_back(time);
                }
            }
        }

        return ans;
    }
};