// Last updated: 18/10/2025, 09:01:34
class Solution {
public:
    bool halvesAreAlike(string s) {
    int vowelcountera = 0;
    int vowelcounterb = 0;
    int start = 0;
    int end = s.size() - 1;
    int mid = start + (end - start) / 2;

    vector<char> a;
    vector<char> b;

    for (int i = start; i <= mid; i++) {
        a.push_back(s[i]);
    }

    for (int j = mid + 1; j <= end; j++) {
        b.push_back(s[j]);
    }

    for (int k = 0; k < a.size(); k++) {
        if (a[k] == 'a' || a[k] == 'e' || a[k] == 'i' || a[k] == 'o' || a[k] == 'u' ||
            a[k] == 'A' || a[k] == 'E' || a[k] == 'I' || a[k] == 'O' || a[k] == 'U') {
            vowelcountera++;
        }
    }

    for (int l = 0; l < b.size(); l++) {
        if (b[l] == 'a' || b[l] == 'e' || b[l] == 'i' || b[l] == 'o' || b[l] == 'u' ||
            b[l] == 'A' || b[l] == 'E' || b[l] == 'I' || b[l] == 'O' || b[l] == 'U') {
            vowelcounterb++;
        }
    }

    return vowelcountera == vowelcounterb;
}
};