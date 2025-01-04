# Student Report Management System in C

# Student Record Management System

## Aim
To develop a system to store and manage student records using structures, files, and arrays in C programming. The system should allow users to add, search, and update student records.

---

## Algorithm

### Step 1: Define the Student Structure
- Create a structure `Student` with the fields:
  - `id` (integer): Student ID.
  - `name` (string): Student Name.
  - `grade` (float): Student Grade.

### Step 2: Display Menu
- Provide a menu with the following options:
  1. Add Student
  2. Search Student
  3. Update Student
  4. Display All Students
  5. Exit

### Step 3: Add Student
- Prompt the user for the student's details (ID, Name, Grade).
- Append the new record to the file `students.dat`.

### Step 4: Search Student
- Prompt the user for the student ID to search.
- Read records from `students.dat` and compare the `id` field.
- Display the record if found, otherwise inform the user.

### Step 5: Update Student
- Prompt the user for the student ID to update.
- Read records from `students.dat` and locate the matching `id`.
- Update the student's details and write the updated record back to the file.

### Step 6: Display All Students
- Read all student records from `students.dat`.
- Display each student's details.

### Step 7: Exit
- Terminate the program when the user chooses the exit option.

---

## Output

### Sample Run

