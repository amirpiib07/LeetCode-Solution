class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0];
        int sc = source[1];

        int tr = target[0];
        int tc = target[1];

        if(sr == tr && sc == tc) return 0;
        if(abs(sr - tr) % 2 != abs(sc - tc) % 2) return -1;
        if(abs(sr - tr) == abs(sc - tc)) return 1;
        return 2;
    }
};