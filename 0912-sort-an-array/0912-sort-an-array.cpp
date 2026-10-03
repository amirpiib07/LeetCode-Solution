class Solution {
private:
    void hpf(auto& a, int idx, int n) {
        int b = idx;
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;
        if(l < n && a[l] > a[b]) {
            b = l;
        }
        if(r < n && a[r] > a[b]) {
            b = r;
        }
        
        if(b != idx) {
            swap(a[idx], a[b]);
            hpf(a, b, n);
        }
        
        return;
    }
    
    void h_s(auto& a) {
        int n = a.size();
        for(int idx = n / 2 - 1; idx >= 0; idx--) {
            hpf(a, idx, n);
        }
        
        for(int idx = n - 1; idx > 0; idx--) {
            swap(a[0], a[idx]);
            hpf(a, 0, idx);
        }
        
        return;
    }
    
public:
    vector<int> sortArray(vector<int>& a) {
        h_s(a);
        return a;
    }
};