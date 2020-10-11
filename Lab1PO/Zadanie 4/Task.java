import java.time.LocalDate;
import java.util.Scanner;
import java.time.format.DateTimeFormatter;

class BoardOfDirectors {
    private int numberOfMembers;
    private double averageAmountOfResolutions;
    private int numberOfResolutionEnties;
    private float currentBudget;
    private LocalDate scheduledAssembly;
    private LocalDate lastAssembly;
    private String companyName;


    public void setNumberOfMembers(int amount) {
        this.numberOfMembers = amount;
    }

    public void dismissNumberOfMembers(int amount) {
        if(amount > numberOfMembers) {
            System.out.println("You can't dismiss more members then the board contains.");
        } else {
            this.numberOfMembers -= amount;
        }
    }

    public int getNumberOfMembers() {
        return numberOfMembers;
    }

    public void insertNewResolutionEntry(int value) {
        this.averageAmountOfResolutions = (this.averageAmountOfResolutions*numberOfResolutionEnties + value)/(++this.numberOfResolutionEnties);
    }

    public double getAverageAmountOfResolutions() {
        return this.averageAmountOfResolutions;
    }

    public void increaseCurrentBudget(float increase) {
        this.currentBudget += increase;
    }

    public void decreaseCurrentBudget(float decrease) {
        this.currentBudget -= decrease;
    }

    public float getCurrentBudget() {
        return currentBudget;
    }

    public LocalDate parseDate(String date) {
        DateTimeFormatter dt = DateTimeFormatter.ofPattern("yyyy-MM-dd");
        return LocalDate.parse(date, dt);
    }

    public void setScheduledAssembly(String date) {
        this.overrideAssembly();
        LocalDate parsed = parseDate(date);
        if ((scheduledAssembly == null && lastAssembly == null) || parsed.isAfter(lastAssembly)) {
            this.scheduledAssembly = parsed;
        } else {
            System.out.println("You cannot schedule assembly further or equal in the past then the last held assembly.");
        }

    }

    public void overrideAssembly() {
        if (scheduledAssembly != null) {
            this.lastAssembly = scheduledAssembly;
            this.scheduledAssembly = null;
        }
    }

    public LocalDate getLastAssembly() {
        this.overrideAssembly();
        return lastAssembly;
    }

    public void setCompanyName(String name) {
        this.companyName = name;
    }

    public String getCompanyName() {
        return companyName;
    }
}

public class Task {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BoardOfDirectors board = new BoardOfDirectors();


        System.out.printf("Insert number of members appointed by the general meeting: ");
        int numberOfMembers = scanner.nextInt();
        scanner.nextLine();
        board.setNumberOfMembers(numberOfMembers);

        System.out.printf("Insert number of members to dismiss: ");
        int numberOfMembersToDismiss = scanner.nextInt();
        scanner.nextLine();
        board.dismissNumberOfMembers(numberOfMembersToDismiss);

        System.out.println("Current number of members is " + board.getNumberOfMembers() + ".");

        System.out.printf("Insert over how many years were resolutions passed: ");
        int numberOfYears = scanner.nextInt();
        scanner.nextLine();
        for (int i = 1; i <= numberOfYears; i++) {
            System.out.printf("Insert number of resolutions passed in year " + i +": ");
            int numberOfResolutions = scanner.nextInt();
            scanner.nextLine();
            board.insertNewResolutionEntry(numberOfResolutions);
        }

        System.out.println("Average amount of resolutions passed over the years is " + board.getAverageAmountOfResolutions() + ".");

        System.out.printf("Insert increase in budget: ");
        float increaseInBudget = scanner.nextFloat();
        scanner.nextLine();
        board.increaseCurrentBudget(increaseInBudget);
        
        System.out.printf("Insert decrease in budget: ");
        float decreaseInBudget = scanner.nextFloat();
        scanner.nextLine();
        board.decreaseCurrentBudget(decreaseInBudget);

        System.out.println("Current budget is " + board.getCurrentBudget() + ".");

        System.out.printf("Insert date of future assembly in format yyyy-mm-dd: ");
        String date = scanner.nextLine();
        board.setScheduledAssembly(date);

        System.out.printf("Insert another date of future assembly (next one) in format yyyy-mm-dd: ");
        String date2 = scanner.nextLine();
        board.setScheduledAssembly(date2);

        System.out.println("Last assembly happened: " + (board.getLastAssembly() != null ? board.getLastAssembly() : "never") + ".");

        System.out.printf("Insert company name: ");
        String companyName = scanner.nextLine();
        board.setCompanyName(companyName);

        System.out.println("Company name is '" + board.getCompanyName() + "'.");

            

        scanner.close();
    }
}