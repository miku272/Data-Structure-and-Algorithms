import java.util.ArrayList;

public class SubsequencePrintingQuestionsUsingRecursion {
    public static void printSumSubsequence(int[] arr, int sum, int index, ArrayList<Integer> result) {
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
        printSumSubsequence(arr, sum, index + 1, result);

        result.remove(result.size() - 1);
        printSumSubsequence(arr, sum, index + 1, result);
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 3 };
        ArrayList<Integer> result = new ArrayList<>();
        int sum = 3;

        printSumSubsequence(arr, sum, 0, result);
    }
}