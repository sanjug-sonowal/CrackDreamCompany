// Last updated: 18/10/2025, 09:01:22
class Solution {
    public boolean checkIfPangram(String s) {
       	   boolean attendance[] = new boolean[26];

        for (char ch : s.toLowerCase().toCharArray()) {
            if (ch >= 'a' && ch <= 'z') {
                attendance[ch - 'a'] = true;
            }
        }

        for (boolean present : attendance) {
            if (!present) return false;
        }

        return true;
    }
}