class ProductOfNumbers {
    vector<int> arr;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(arr.size() == 0) arr.push_back(num);
        else arr.push_back(num * arr.back());
        if(arr.back() == 0) arr.clear();
        return;
    }
    
    int getProduct(int k) {
        if(arr.size() == 0 || k > arr.size()) return 0;
        if(k == arr.size()) return arr[arr.size() - 1];
        int sz = arr.size();
        return arr[sz - 1] / arr[sz - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */