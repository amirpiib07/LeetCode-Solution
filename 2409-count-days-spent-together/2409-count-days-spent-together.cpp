
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        
        if (leaveAlice < arriveBob || leaveBob < arriveAlice)
            return 0;

        int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        string start;

        int a_s = stoi(arriveAlice.substr(0, 2));
        int b_s = stoi(arriveBob.substr(0, 2));

        if (a_s < b_s) {
            start = arriveBob;
        } else if (b_s < a_s) {
            start = arriveAlice;
        } else {
            int a_d = stoi(arriveAlice.substr(3, 2));
            int b_d = stoi(arriveBob.substr(3, 2));

            if (a_d < b_d)
                start = arriveBob;
            else
                start = arriveAlice;
        }

        string end;

        int a_e = stoi(leaveAlice.substr(0, 2));
        int b_e = stoi(leaveBob.substr(0, 2));

        if (a_e < b_e) {
            end = leaveAlice;
        } else if (b_e < a_e) {
            end = leaveBob;
        } else {
            int a_d = stoi(leaveAlice.substr(3, 2));
            int b_d = stoi(leaveBob.substr(3, 2));

            if (a_d < b_d)
                end = leaveAlice;
            else
                end = leaveBob;
        }

        int ans = 0;

        int s_m = stoi(start.substr(0, 2));
        int e_m = stoi(end.substr(0, 2));

        int d_s = stoi(start.substr(3, 2));
        int d_e = stoi(end.substr(3, 2));

        if (s_m == e_m)
            return d_e - d_s + 1;

        for (int m = s_m; m <= e_m; ++m) {
            if (m == s_m) {
                ans += month[m - 1] - d_s + 1;
            } else if (m == e_m) {
                ans += d_e;
            } else {
                ans += month[m - 1];
            }
        }

        return ans;
    }
};
