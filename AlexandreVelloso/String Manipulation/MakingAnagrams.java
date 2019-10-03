import java.util.Scanner;

public class MakingAnagrams {

    private static int absolute(int number) {
        if (number < 0) {
            return number * -1;
        }

        return number;
    }

    private static int makeAnagram(String a, String b) {
        int[] occurrencesFromA = new int[256];
        int[] occurrencesFromB = new int[256];

        for (int i = 0; i < a.length(); i++) {
            occurrencesFromA[(int) a.charAt(i)]++;
        }

        for (int i = 0; i < b.length(); i++) {
            occurrencesFromB[(int) b.charAt(i)]++;
        }

        int numberOfDeletions = 0;

        for (int i = 0; i < 256; i++) {
            numberOfDeletions += absolute(occurrencesFromA[i] - occurrencesFromB[i]);
        }

        return numberOfDeletions;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String a = scanner.nextLine();
        String b = scanner.nextLine();

        scanner.close();

        System.out.println(makeAnagram(a, b));
    }
}
