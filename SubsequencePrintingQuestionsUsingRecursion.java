import java.util.ArrayList;

public class SubsequencePrintingQuestionsUsingRecursion {
    public static void printAllSumSubsequence(int[] arr, int sum, int index, ArrayList<Integer> result) {
        if (index >= arr.length) {
            int total = 0;

            for (int res : result) {
                total += res;
            }

            if (total == sum) {
                for (int res : result) {
                    System.out.print(res + " ");
                }
                System.out.println();
            }

            return;
        }

        result.add(arr[index]);
        printAllSumSubsequence(arr, sum, index + 1, result);

        result.remove(result.size() - 1);
        printAllSumSubsequence(arr, sum, index + 1, result);
    }

    public static boolean printOnlyOneSumSubsequence(int[] arr, int sum, int index, ArrayList<Integer> result) {
        if (index >= arr.length) {
            int total = 0;

            for (int res : result) {
                total += res;
            }

            if (total == sum) {
                for (int res : result) {
                    System.out.print(res + " ");
                }
                System.out.println();

                return true;
            }

            return false;
        }

        result.add(arr[index]);
        if (printOnlyOneSumSubsequence(arr, sum, index + 1, result) == true) {
            return true;
        }

        result.remove(result.size() - 1);
        if (printOnlyOneSumSubsequence(arr, sum, index + 1, result) == true) {
            return true;
        }

        return false;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 1 };
        ArrayList<Integer> result = new ArrayList<>();
        int sum = 2;

        printAllSumSubsequence(arr, sum, 0, result);
    }
}