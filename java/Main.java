import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Student {
    // Step 1: Student details
    String name;
    int regNo;
    String course;
    int[] marks = new int[6];
    int total;
    int rank;

    // Constructor
    Student(String name, int regNo, String course, int[] marks) {
        this.name = name;
        this.regNo = regNo;
        this.course = course;
        this.marks = marks;

        // Step 4: Calculate total
        for (int i = 0; i < 6; i++) {
            total = total + marks[i];
        }
    }
}

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Step 2: Create array of students
        System.out.print("Enter number of students: ");
        int n = sc.nextInt();
        sc.nextLine();

        Student[] students = new Student[n];

        // Step 3: Read student details
        for (int i = 0; i < n; i++) {

            System.out.println("Enter details of student " + (i + 1));

            System.out.print("Name: ");
            String name = sc.nextLine();

            System.out.print("Reg No: ");
            int regNo = sc.nextInt();
            sc.nextLine();

            System.out.print("Course: ");
            String course = sc.nextLine();

            int[] marks = new int[6];

            for (int j = 0; j < 6; j++) {
                System.out.print("Enter mark for subject "
                                 + (j + 1) + ": ");
                marks[j] = sc.nextInt();
            }

            sc.nextLine();

            students[i] = new Student(name, regNo, course, marks);
        }

        // Step 5: Sort in descending order of total
        Arrays.sort(students, new Comparator<Student>() {
            public int compare(Student s1, Student s2) {
                return Integer.compare(s2.total, s1.total);
            }
        });

        // Step 6: Assign ranks
        for (int i = 0; i < n; i++) {

            if (i == 0) {
                students[i].rank = 1;
            }
            else if (students[i].total == students[i - 1].total) {
                // Same total -> same rank
                students[i].rank = students[i - 1].rank;
            }
            else {
                // Different total -> rank based on position
                students[i].rank = i + 1;
            }
        }

        // Step 7: Display result
        System.out.println();
        System.out.printf("%-10s %-20s %-12s %-10s %-5s%n",
                "RegNo", "Name", "Course", "Total", "Rank");

        System.out.println("-----------------------------------------------");

        for (int i = 0; i < n; i++) {
            System.out.printf("%-10d %-20s %-12s %-10d %-5d%n",
                    students[i].regNo,
                    students[i].name,
                    students[i].course,
                    students[i].total,
                    students[i].rank);
        }

        sc.close();
    }
}
