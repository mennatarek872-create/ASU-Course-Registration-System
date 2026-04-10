#include <iostream>
#include <string>
using namespace std;
// Structs (ممنوع تعديلها)
struct Student {
    int StudentID;
    string Name;
    string Password;
    int Level;
    int RegisteredCourses[10];
    int NumberOfRegisteredCourses = 0;
};

struct Course {
    int CourseID;
    string CourseName;
    string InstructorName;
    int CreditHours;
    int MaxCapacity;
    int CurrentEnrolled = 0;
    string Day;
    string Time;
};

struct Admin {
    int AdminID;
    string Name;
    string Password;
};


// Global Arrays

Student students[50];
Course courses[20];
Admin admins[3];

int studentCount = 0;
int courseCount = 0;
int adminCount = 1;


// Function Prototypes (13 Functions)

void studentLogin() {
   
}

void studentSignUp() {

}

void viewAvailableCourses() {

}

void registerCourse() {

}

void dropCourse() {

}

void viewMyCourses() {
}

void studentLogout() {

}
void adminLogin() {

}

void addCourse() {
}

void editCourse() {

}

void deleteCourse() {
}

void viewAllStudents() {

}

void adminLogout() {
}

