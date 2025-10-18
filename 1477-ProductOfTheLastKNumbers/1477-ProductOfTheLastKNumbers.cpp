// Last updated: 18/10/2025, 09:02:43
class ProductOfNumbers {
private:
    vector<int> prefixProducts; // Stores the cumulative product
public:
    ProductOfNumbers() {
        prefixProducts = {1}; // Start with a dummy 1 to handle division cases
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProducts = {1}; // Reset if zero is added
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        int size = prefixProducts.size();
        if (k >= size) return 0; // If k is larger than available numbers, return 0 (reset case)
        return prefixProducts.back() / prefixProducts[size - k - 1];
    }
};
