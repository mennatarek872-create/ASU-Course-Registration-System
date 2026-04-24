#include<iostream>
#include<string>
#include<cstring>
#include<conio.h>
#include<fstream>
#include<iomanip>
using namespace std;
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
Student students[50];
Course courses[20];
Admin admins[3];

int studentCount = 0;
int courseCount = 0;
int adminCount = 1;

void viewAvailableCourses();
void registerCourse(int index);
void dropCourse(int studentIndex);
void viewMyCourses(int studentIndex);
    
   

//view Available Courses
void viewAvailableCourses(){
    if (courseCount == 0) {
        cout << "No courses available!!" << endl;
        return;
    }
    cout << "\n# All Available Courses #\n" << endl;
    cout << string(100, '-') << endl;
    cout << left << setw(10) << "CourseID"
        << setw(25) << "CourseName"
        << setw(25) << "InstructorName"
        << setw(15) << "CreditHours"
        << setw(15) << "Time"
        << setw(10) << "Day"
        << setw(10) << "Available" << endl;
    cout << string(100, '-') << endl;
    bool found = false;

    for (int i = 0; i < courseCount; i++) {
        if (courses[i].CurrentEnrolled < courses[i].MaxCapacity) {
            int availablePlaces = courses[i].MaxCapacity - courses[i].CurrentEnrolled;
            cout << left << setw(10) << courses[i].CourseID
                << setw(25) << courses[i].CourseName
                << setw(25) << courses[i].InstructorName
                << setw(15) << courses[i].CreditHours
                << setw(15) << courses[i].Time
                << setw(10) << courses[i].Day
                << setw(10) << availablePlaces << endl;
            found = true;

        }
    }
    cout << string(100, '-') << endl;
    if (!found) {
        cout << "Sorry, all courses are currently full!" << endl;
    }

}


//register Course
void registerCourse(int index) {

    // 1. Check if the student has reached the maximum course limit
    if (students[index].NumberOfRegisteredCourses >= 10) {
        cout << "You reached the limit of 10 courses." << endl;
        return;
    }

    int id;
    cout << "Enter the Course ID you want to register: ";
    cin >> id;
    int courseIndex = searchCourse(id);

    // 2. Check if the course exists in the system
    if (courseIndex == -1) {
        cout << "Course not found" << endl;
        return;
    }

    // 3. Check if the student is already enrolled in this course
    for (int i = 0; i < students[index].NumberOfRegisteredCourses; i++) {
        if (students[index].RegisteredCourses[i] == id) {
            cout << "You are already registered in this course." << endl;
            return;
        }
    }

    // 4. Check for time conflicts with already registered courses
    for (int i = 0; i < students[index].NumberOfRegisteredCourses; i++) {

        int regID = students[index].RegisteredCourses[i];

        int regIndex = searchCourse(regID);

        if (regIndex != -1) {

            if (courses[regIndex].Day == courses[courseIndex].Day && courses[regIndex].Time == courses[courseIndex].Time) {

                cout << "Time Conflict! You have another course on " << courses[courseIndex].Day << " at " << courses[courseIndex].Time << endl;
                return;
            }

        }

    }

    // 5. Check if the course has reached its maximum capacity        
    if (courses[courseIndex].CurrentEnrolled >= courses[courseIndex].MaxCapacity) {
        cout << "This course is full." << endl;
        return;
    }
    //course registration  
    increaseStudentCount(id);
    int pos = students[index].NumberOfRegisteredCourses;
    students[index].RegisteredCourses[pos] = id;
    students[index].NumberOfRegisteredCourses++;
    cout << "SUCCESS: Registered in [" << courses[courseIndex].CourseName << "]" << endl;
    cout << "Total courses registered: " << students[index].NumberOfRegisteredCourses << "/10" << endl;
}



//-----drop course-----//
void dropCourse(int studentIndex) {
	int courseID;
	cout << "Enter the Course ID you want to drop: ";
	cin >> courseID;
    int dropcourse_index = -1;
    for (int i = 0; i < students[studentIndex].NumberOfRegisteredCourses; i++)
    {
        if (students[studentIndex].RegisteredCourses[i] == courseID)
        {
            dropcourse_index = i;
            break;
        }
    }

    if (dropcourse_index == -1) {
        cout << " ERROR!!!You are not registered in this course." << endl;
        return;
    }
    else {
        for (int i = dropcourse_index; i < students[studentIndex].NumberOfRegisteredCourses - 1; i++) {
            students[studentIndex].RegisteredCourses[i] = students[studentIndex].RegisteredCourses[i + 1];
        }
        students[studentIndex].NumberOfRegisteredCourses--;
        decreaseStudentCount(courseID);
        cout << "Course dropped successfully!" << endl;
    }
}

//-----view my courses-----//
void viewMyCourses(int studentIndex)
{
	if (students[studentIndex].NumberOfRegisteredCourses==0) {
        cout << "You are not registered in any courses!!!" << endl;
        return;
	}
    cout << "\n#MY COURSES#\n" << endl;
    cout << string(100, '-') << endl;
    cout << left << setw(10) << "CourseID"
        << setw(25) << "CourseName"
        << setw(25) << "InstructorName"
        << setw(15) << "CreditHours"
        << setw(15) << "Time"
        << setw(10) << "Day" << endl;
    cout << string(100, '-') << endl;
    for (int i = 0; i < students[studentIndex].NumberOfRegisteredCourses; i++) 
    {
        int courseID = students[studentIndex].RegisteredCourses[i];
        int index= searchCourse(courseID);

        if (index != -1)
        {

            cout << left << setw(10) << courses[index].CourseID
                << setw(25) << courses[index].CourseName
                << setw(25) << courses[index].InstructorName
                << setw(10) << courses[index].CreditHours
                << setw(10) << courses[index].Time
                << setw(10) << courses[index].Day << endl;
            cout << string(100, '-') << endl;
        }
     }

    }
