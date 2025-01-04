#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "students.dat"

typedef struct
{
    int id;
    char name[50];
    float grade;
} Student;

void addStudent();
void searchStudent();
void updateStudent();
void displayAllStudents();

int main()
{
    int choice;
    while (1)
    {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Update Student\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            searchStudent();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            displayAllStudents();
            break;
        case 5:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addStudent()
{
    FILE *file = fopen(FILE_NAME, "ab");
    if (!file)
    {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Student Grade: ");
    scanf("%f", &s.grade);

    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);
    printf("Student added successfully!\n");
}

void searchStudent()
{
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file)
    {
        printf("Error opening file!\n");
        return;
    }

    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, file))
    {
        if (s.id == id)
        {
            printf("Student Found:\n");
            printf("ID: %d\n", s.id);
            printf("Name: %s\n", s.name);
            printf("Grade: %.2f\n", s.grade);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student with ID %d not found.\n", id);
    }
    fclose(file);
}

void updateStudent()
{
    FILE *file = fopen(FILE_NAME, "rb+");
    if (!file)
    {
        printf("Error opening file!\n");
        return;
    }

    int id;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, file))
    {
        if (s.id == id)
        {
            printf("Student Found:\n");
            printf("ID: %d\n", s.id);
            printf("Name: %s\n", s.name);
            printf("Grade: %.2f\n", s.grade);

            printf("\nEnter new details:\n");
            printf("Enter Student Name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter Student Grade: ");
            scanf("%f", &s.grade);

            fseek(file, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, file);
            printf("Student updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student with ID %d not found.\n", id);
    }
    fclose(file);
}

void displayAllStudents()
{
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file)
    {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("\n--- All Student Records ---\n");
    while (fread(&s, sizeof(Student), 1, file))
    {
        printf("ID: %d, Name: %s, Grade: %.2f\n", s.id, s.name, s.grade);
    }
    fclose(file);
}
