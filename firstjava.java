import java.util.Scanner;

public class firstjava {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter something:");
        String input = scanner.nextLine();
        System.out.println("You entered: " + input);
    }
}
