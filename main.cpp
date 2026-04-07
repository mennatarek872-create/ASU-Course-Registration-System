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


// Authentication
void signUp();
int studentLogin();
bool adminLogin();
bool isStudentIDExist(int id);

// Course Management
void addCourse();
void viewAllCourses();
int searchCourse(int courseID);
void increaseStudentCount(int courseID);
void decreaseStudentCount(int courseID);

// Student Logic
void viewAvailableCourses();
void registerCourse(int studentIndex, int courseID);
void dropCourse(int studentIndex, int courseID);
void viewStudentSchedule(int studentIndex);

// --- Function Prototypes (TEEEEEEEEEEEEEEST) ---

void showMainMenu();       // القائمة الرئيسية (Login/Exit)
void showAdminMenu();      // قائمة الأدمن (إدارة الكورسات)
void showStudentMenu();    // قائمة الطالب (تسجيل الكورسات)

// --- Global Data ---
Student students[100];
Course courses[50];
int totalStudents = 0;
int totalCourses = 0;

// --- Main Control ---
int main() {
    // سيتم استدعاء فانكشن الـ Load من الملفات هنا (تيم A و B)
    
    showMainMenu();
    
    return 0;
}

// --- تنفيذ الـ Menu (شغل الليدر) ---
void showMainMenu() {
    cout << "====================================" << endl;
    cout << "   WELCOME TO ASU COURSE SYSTEM     " << endl;
    cout << "====================================" << endl;
    cout << "1. Login" << endl;
    cout << "2. Exit" << endl;
    cout << "Choice: ";
}
