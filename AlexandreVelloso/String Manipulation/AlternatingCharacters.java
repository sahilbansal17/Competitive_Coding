import java.util.Scanner;

public class AlternatingCharacters {

    private static int alternatingCharacters(String query) {
        int numberOfDeletions = 0;

        for(int i = 1; i < query.length(); i++){
            if(query.charAt(i) == query.charAt(i-1)){
                numberOfDeletions++;
            }
        }

        return numberOfDeletions;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int numberOfQueries = Integer.parseInt(scanner.nextLine());

        for(int i = 0; i < numberOfQueries; i++){
            String query = scanner.nextLine();

            System.out.println(alternatingCharacters(query));
        }

        scanner.close();
    }

}
