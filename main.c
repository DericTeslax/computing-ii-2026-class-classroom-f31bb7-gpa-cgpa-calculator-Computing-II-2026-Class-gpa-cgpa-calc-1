/*
Name: MUTYABA DERICK 
Registration Number: 25/U/BIE/01399/PE
*/

#include <stdio.h>

int main(void) {
    /* Variables */
    // Semester I course details
    const char *sem1_codes[] = {
        "TEMB1101", "TEMB1102", "TEMB1103", "TEMB1104",
        "TEMB1105", "TEMB1106", "TEMB1107", "TEMB1108"
    };
    const char *sem1_names[] = {
        "Fundamentals of Engineering Mathematics",
        "Biochemistry and Medical Physics",
        "Electrical Engineering Science",
        "Mechanics I",
        "Computing I",
        "Mechanical Drawing",
        "Engineering Profession",
        "Functional Anatomy and Physiology I"
    };
    const int sem1_credits[] = {4, 3, 3, 3, 3, 3, 2, 3};

    // Semester II course details
    const char *sem2_codes[] = {
        "TEMB1201", "TEMB1202", "TEMB1203", "TEMB1204",
        "TEMB1205", "TEMB1206", "TEMB1207", "TEMB1208"
    };
    const char *sem2_names[] = {
        "Further Engineering Mathematics",
        "Computing II",
        "Mechatronics Drawing",
        "Fluid Mechanics",
        "Thermodynamics",
        "Workshop Practice",
        "Functional Anatomy and Physiology II",
        "Electronics I"
    };
    const int sem2_credits[] = {4, 3, 3, 3, 3, 3, 3, 3};

    int scores[16];
    double total_weighted = 0.0;
    int total_credits = 0;

    /* Read 16 scores */
    printf("=== SEMESTER I ===\n");
    for (int i = 0; i < 8; i++) {
        printf("Enter score for %s - %s (%d credits): ", 
               sem1_codes[i], sem1_names[i], sem1_credits[i]);
        scanf("%d", &scores[i]);
    }

    printf("\n=== SEMESTER II ===\n");
    for (int i = 0; i < 8; i++) {
        printf("Enter score for %s - %s (%d credits): ", 
               sem2_codes[i], sem2_names[i], sem2_credits[i]);
        scanf("%d", &scores[8 + i]);
    }

    /* Validate input */
    for (int i = 0; i < 16; i++) {
        if (scores[i] < 0 || scores[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
        }
    }

    /* Compute Semester I GPA */
    double sem1_weighted = 0.0;
    int sem1_credits_sum = 0;

    // Display header for report
    printf("\n----------------------------------------------------------------------------------------------------\n");
    printf("Course Code  Course Name                              Score  Grade  Grade Pt  Credit  Weighted\n");
    printf("----------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 8; i++) {
        int score = scores[i];
        double grade_point;
        char grade_letter;

        // Grade conversion using 4.0 scale
        if (score >= 80) {
            grade_point = 4.0;
            grade_letter = 'A';
        } else if (score >= 70) {
            grade_point = 3.0;
            grade_letter = 'B';
        } else if (score >= 60) {
            grade_point = 2.0;
            grade_letter = 'C';
        } else if (score >= 50) {
            grade_point = 1.0;
            grade_letter = 'D';
        } else {
            grade_point = 0.0;
            grade_letter = 'F';
        }

        double weighted = grade_point * sem1_credits[i];
        sem1_weighted += weighted;
        sem1_credits_sum += sem1_credits[i];

        printf("%-11s %-40s %5d     %c      %.1f      %2d      %6.1f\n",
               sem1_codes[i], sem1_names[i], score, grade_letter, 
               grade_point, sem1_credits[i], weighted);
    }

    double sem1_gpa = sem1_weighted / sem1_credits_sum;
    printf("\nSemester I GPA: %.2f\n", sem1_gpa);

    total_weighted += sem1_weighted;
    total_credits += sem1_credits_sum;

    /* Compute Semester II GPA */
    printf("\n----------------------------------------------------------------------------------------------------\n");
    printf("Course Code  Course Name                              Score  Grade  Grade Pt  Credit  Weighted\n");
    printf("----------------------------------------------------------------------------------------------------\n");

    double sem2_weighted = 0.0;
    int sem2_credits_sum = 0;

    for (int i = 0; i < 8; i++) {
        int score = scores[8 + i];
        double grade_point;
        char grade_letter;

        if (score >= 80) {
            grade_point = 4.0;
            grade_letter = 'A';
        } else if (score >= 70) {
            grade_point = 3.0;
            grade_letter = 'B';
        } else if (score >= 60) {
            grade_point = 2.0;
            grade_letter = 'C';
        } else if (score >= 50) {
            grade_point = 1.0;
            grade_letter = 'D';
        } else {
            grade_point = 0.0;
            grade_letter = 'F';
        }

        double weighted = grade_point * sem2_credits[i];
        sem2_weighted += weighted;
        sem2_credits_sum += sem2_credits[i];

        printf("%-11s %-40s %5d     %c      %.1f      %2d      %6.1f\n",
               sem2_codes[i], sem2_names[i], score, grade_letter,
               grade_point, sem2_credits[i], weighted);
    }

    double sem2_gpa = sem2_weighted / sem2_credits_sum;
    printf("\nSemester II GPA: %.2f\n", sem2_gpa);

    total_weighted += sem2_weighted;
    total_credits += sem2_credits_sum;

    /* Compute CGPA */
    double cgpa = total_weighted / total_credits;
    printf("CGPA: %.2f\n", cgpa);

    /* Determine classification */
    if (cgpa >= 3.60) {
        printf("Classification: First Class\n");
    } else if (cgpa >= 3.00) {
        printf("Classification: Second Class Upper\n");
    } else if (cgpa >= 2.00) {
        printf("Classification: Second Class Lower\n");
    } else {
        printf("Classification: Pass\n");
    }
    return 0;
}
