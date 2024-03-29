#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    int strStr(string haystack, string needle) {
        // First Approach 
        //size_t found = haystack.find(needle);
        //return found;

        // Second Approach
        int h = haystack.size(), n = needle.size();
        if (n > h) 
            return -1;
        
        const int kBase = 3;
        unsigned long long h_hash = 0, n_hash = 0, power_str = 1;
        for (int i = 0; i < n; ++i){
            power_str = i ? power_str * kBase: 1;
            h_hash = h_hash * kBase + haystack[i];
            n_hash = n_hash * kBase + needle[i];
        }
        
        for (int i = n; i < h; ++i){
            if (h_hash == n_hash && !haystack.compare(i-n, n, needle)){
                return i-n; // found match
            }
            
            h_hash -= haystack[i-n] * power_str;
            h_hash = h_hash * kBase + haystack[i];
        }
        
        if (h_hash == n_hash && haystack.compare(h-n, n, needle) == 0){
            return h-n;
        }
        return -1;
    }
};

int main() {

    string haystack = "hello", needle = "po";
    Solution obj;
    cout << obj.strStr(haystack, needle);
    return 0;

}