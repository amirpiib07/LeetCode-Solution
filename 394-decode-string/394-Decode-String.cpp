class Solution {
public:
    string decodeString(string s) {

        stack<int> val;
        stack<string> word;

        int count = 0;
        string curr = "";

        for (int idx = 0; idx < s.size(); idx++) {

            char ch = s[idx];

            
            if (ch >= '0' && ch <= '9') {
                count = count * 10 + (ch - '0');
            }

            
            else if (ch == '[') {
                val.push(count);
                word.push(curr);

                count = 0;
                curr = "";
            }

            
            else if (ch == ']') {

                int repeat = val.top();
                val.pop();

                string previous = word.top();
                word.pop();

                string temp = "";

                for (int i = 0; i < repeat; i++) {
                    temp += curr;
                }

                curr = previous + temp;
            }

            
            else {
                curr += ch;
            }
        }

        return curr;
    }
};