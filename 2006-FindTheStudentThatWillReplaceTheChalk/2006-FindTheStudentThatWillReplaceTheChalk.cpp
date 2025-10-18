// Last updated: 18/10/2025, 09:01:12
class Solution {
 public:
  int chalkReplacer(vector<int>& chalk, int k) {
    k %= accumulate(chalk.begin(), chalk.end(), 0L);
    if (k == 0)
      return 0;

    for (int i = 0; i < chalk.size(); ++i) {
      k -= chalk[i];
      if (k < 0)
        return i;
    }

    throw;
  }
};