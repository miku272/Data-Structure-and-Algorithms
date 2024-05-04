import java.util.HashSet;

public class LongestSubstringWithoutRepeatingCharacters {
    public static int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) {
            return 0;
        }

        if (s.length() == 1) {
            return 1;
        }

        int maxLen = 0, leftPoint = 0, rightPoint = 0;
        HashSet<Character> uniqueAlphabets = new HashSet<Character>();

        while (rightPoint < s.length()) {
            if (!uniqueAlphabets.contains(s.charAt(rightPoint))) {
                uniqueAlphabets.add(s.charAt(rightPoint));

                rightPoint++;

                maxLen = Math.max(maxLen, uniqueAlphabets.size());
            } else {
                uniqueAlphabets.remove(s.charAt(leftPoint));

                leftPoint++;
            }
        }

        return maxLen;
    }

    public static void main(String[] args) {
        // String str = "abcabcbb";
        // String str = "bbbbb";
        // String str = "pwwkew";
        String str = "aab";
        // String str = "au";

        System.out.println(lengthOfLongestSubstring(str));
    }
}
