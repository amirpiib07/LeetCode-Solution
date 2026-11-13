
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;

        for(int i = 0; i < order.size(); i++) {
            m[order[i]] = i;
        }

        for(int i = 1; i < words.size(); i++) {
            string s = words[i - 1];
            string w = words[i];

            int j = 0;

            while(j < s.size() && j < w.size()) {
                if(s[j] == w[j]) {
                    j++;
                }
                else {
                    if(m[s[j]] > m[w[j]]) {
                        return false;
                    }
                    break;
                }
            }

           
            if(j == w.size() && s.size() > w.size()) {
                return false;
            }
        }

        return true;
    }
};
