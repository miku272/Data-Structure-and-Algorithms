public class LongestPalindromicSubstring {
    public static int getPalindromeLenght(String str, int left, int right) {
        while (left >= 0 && right < str.length() && str.charAt(left) == str.charAt(right)) {
            left--;
            right++;
        }

        return right - left - 1;
    }

    public static String longestPalindromicString(String str) {
        if (str == null || str.length() < 1) {
            return "";
        }

        int start = 0, end = 0, length1 = 0, length2 = 0, length = 0;

        for (int i = 0; i < str.length(); i++) {
            length1 = getPalindromeLenght(str, i, i);
            length2 = getPalindromeLenght(str, i, i + 1);

            length = Math.max(length1, length2);

            if (length > end - start) {
                start = i - (length - 1) / 2;
                end = i + length / 2;
            }
        }

        return str.substring(start, end + 1);
    }

    public static void main(String[] args) {
        String str = "abaa";

        System.out.println(getPalindromeLenght(str, 0, str.length()));
    }
}