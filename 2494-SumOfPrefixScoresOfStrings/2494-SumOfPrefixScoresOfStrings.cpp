// Last updated: 18/10/2025, 09:00:09
struct TrieNode {
  TrieNode* children[26];
  int count;
  
  TrieNode() : count(0) {
    // Initialize all children to nullptr
    for (int i = 0; i < 26; ++i) {
      children[i] = nullptr;
    }
  }
};

class Solution {
 public:
  vector<int> sumPrefixScores(vector<string>& words) {
    vector<int> ans;
    
    // Insert all words into the Trie
    for (const string& word : words)
      insert(word);

    // Calculate the score for each word
    for (const string& word : words)
      ans.push_back(getScore(word));

    return ans;
  }

 private:
  TrieNode* root = new TrieNode();  // Root of the Trie

  // Insert a word into the Trie and increment the count at each node
  void insert(const string& word) {
    TrieNode* node = root;
    for (const char c : word) {
      const int i = c - 'a';
      if (node->children[i] == nullptr) {
        node->children[i] = new TrieNode();  // Create node only if it doesn't exist
      }
      node = node->children[i];
      ++node->count;  // Increment the count for the current node
    }
  }

  // Get the score for a word by summing the count at each node in the Trie
  int getScore(const string& word) {
    TrieNode* node = root;
    int score = 0;
    for (const char c : word) {
      node = node->children[c - 'a'];
      score += node->count;  // Add the count of the current node to the score
    }
    return score;
  }
};
