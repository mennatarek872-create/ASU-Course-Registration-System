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


// Function Prototypes (13 Functions)

// team a
void studentLogin();
void studentSignUp();
void adminLogin();
bool isStudentIDExist(int id);
void studentLogout();// extra task
void adminLogout(); // extra task

//-----------------------------------------------------------------------
// team b
void addCourse() ;
void viewAllStudents() ;
void increaseStudentCount(int courseID);
void decreaseStudentCount(int courseID);
void viewAllCourses();
int searchCourse(int courseID);
void editCourse();
void deleteCourse() ;
//-----------------------------------------------------------------------
//team c
void viewAvailableCourses();
void registerCourse();
void dropCourse() ;
void viewMyCourses();
//-----------------------------------------------------------------------
