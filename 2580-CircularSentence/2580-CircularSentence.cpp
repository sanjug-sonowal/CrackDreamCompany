// Last updated: 18/10/2025, 08:59:53
class Solution {
public:
    bool isCircularSentence(string sentence) {
         vector<string> words;
        string word = "";

        for (char c : sentence) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) words.push_back(word);

        int n = words.size();
        for (int i = 0; i < n; i++) {
            string curr = words[i];
            string next = words[(i + 1) % n];
            if (curr.back() != next.front()) {
                return false;
            }
        }
        return true;
    }
};