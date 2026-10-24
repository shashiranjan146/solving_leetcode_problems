class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string start = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);
        if (start > end)
            return 0;

        int daysInMonth[] = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };
        auto toDays = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            for (int i = 0; i < month - 1; i++) {
                day += daysInMonth[i];
            }
            return day;
        };
        return toDays(end) - toDays(start) + 1;
    }
};