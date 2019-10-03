import java.util.Arrays;
import java.util.Scanner;

public class RansomNote {

    private static void checkMagazine(String[] magazine, String[] note) {
        Arrays.sort(magazine);
        Arrays.sort(note);

        int notePosition = 0;
        int magazinePosition = 0;

        while (notePosition < note.length && magazinePosition < magazine.length) {

            if (magazine[magazinePosition].equals(note[notePosition])) {
                notePosition++;
                magazinePosition++;
            } else {
                magazinePosition++;
            }
        }

        if (notePosition == note.length) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int numberOfWordsInMagazine = scanner.nextInt();
        int numberOfWordsInNote = scanner.nextInt();
        scanner.nextLine();

        String[] magazine = scanner.nextLine().split(" ");
        String[] note = scanner.nextLine().split(" ");

        checkMagazine(magazine, note);
    }

}