//load course from file

 void loadCourses(){
      ifstream file("courses.txt");
      if(!file)
      return;
      file>>totalCourses;
      file.ignore();
      for(i=0 , i<totalCourses, i++){
      getline(file,courses[i].CourseName);
      getline(file,courses[i].InstructorName);
      file>>courses[i].CreditHours;
     file>>courses[i].MaxCapacity;
      file>>courses[i].CurrentEnrolled;
      file.ignore();
     getline(file,courses[i].Day);
      getline(file,courses[i].Time);

}
      file.close();
    }


 //save course to file

 void saveCourses(){
    ofstream file("courses.txt");
    file<<totalCourses<<endl;
    for(i=0 , i<totalCourses, i++){
      file<<courses[i].courseID;
      file<<courses[i].CourseName<<endl;
      file<<courses[i].InstructorName<<endl;
      file<<courses[i].CreditHours;
      file<<courses[i].MaxCapacity;
      file<<courses[i].Day;
      file<<courses[i].Time;

   }

   file.close()
}


//course management
//add courses

    bool addCourse(){
    if (totalCourses>=20){
        cout<<"Sorry!! Max limit reached,cannot add more courses."<<endl;
        return;
    }
    course newCourse;
    cout<<"---Add new course---"<<endl;
    cout<<"Enter course ID:"<<endl;
    cin>>newCourse.CourseID;
    for(int i=0; i<totalCourses;i++){
        if(courses[i].CourseID == newCourse.CourseID){
        cout<<"CourseID already exists,please use a different ID!!<<endl;
        return false;
    }

}

    cin.ignore();            //لتجاهل السطر الجديد
    cout<<"Enter Course Name:"<<endl;
    getline(cin,newCourse.CourseName);
    cout<<"Enter Instructor Name:"<<endl;
    getline(cin,newCourse.InstructorName);
    cout<<"Enter Credit Hours:"<<endl;
    cin>>newCourse.CreditHours;
    cout<<"Enter Max Capacity:"<<endl;
    cin>>newCourse.MaxCapacity;
    newCourse.CurrentEnrolled=0;      //الكورس الجديد خالي من الطلاب
    cin.ignore();
    cout<<"Enter Day:<<endl;
    getline(cin,newCourse.Day);
    cout<<"Enter Time:"<<endl;
    getline(cin,newCourse.Time);

    courses[totalCourses]=newCourse;
    totalCourses++;
    cout<<"Course added successfully."<<endl
    return true;
    }

// Edit course                                (InstructorName و CreditHours و MaxCapacity) يسمح للأدمن تعديل ال 

void editCourse(){
int CourseID;
cout<<"Enter course ID:"<<endl;
cin>>CourseID;
int index= searchCourse(CourseID);
if(index==-1){
    cout<<"Course not found:"<<endl;
    return;
}
   cout<<"Editing course:"<<courses[index].CourseName<<endl;
   int choice;
   cout<<"What do you want to edit?"<<endl;
   cout<<"Press 1 to change course name."<<endl;
   cout<<"Press 2 to change instructor name."<<endl;
   cout<<"Press 3 to change credit hours."<<endl;
   cout<<"Press 4 to change max capacity."<<endl;
   cout<<"Press 5 to change day."<<endl;
   cout<<"Press 6 to change time."<<endl;
   cout<<"Enter your choice:"<<endl;
 cin>>choice;
switch (choice){
    case 1:
           cout<<"Enter new course name:"<<endl;
             cin>>courses[index].CourseName;
    case 2:
     cout<<"Enter new instructor name:"<<endl;
             cin>>courses[index].InstructorName;
    case 3:
     cout<<"Enter new credit hours:"<<endl;
             cin>>courses[index].CreditHours;
    case 4:
     cout<<"Enter new max capacity:"<<endl;
             cin>>courses[index].MaxCapacity;
    case 5:
     cout<<"Enter new day:"<<endl;
             cin>>courses[index].Day;
    case 6:
 cout<<"Enter new time:"<<endl;
             cin>>courses[index].Time;
             default:
             cout<<"Invalid choice!!"<<endl;
             return;
      }
      cout<<"Course updated successfully."<<endl;
}


//-----delete course-----
void deleteCourse(){
	int id;
	cout<<"Enter course ID to delete:";
	cin>>id;
	int index= searchCourse(courseID);
	if(index==-1){
		 cout<<"course not found.\n";
		 return;
	 }
	 if(courses[index].CurrentEnrolled>0)
	 {
		 cout<<"cannot delete this course...students are enrolled.\n";
		 return;
	 }
	 for(int i=0;i<courseCount-1;i++)
	 {
		 courses[i]=courses[i+1];
	 }
	 courseCount--;
	 cout<<"Course is successfully deleted\n";

}


//------------course management------------
//----search course----
 int searchCourse(int courseID){
	 for(int i=0;i<courseCount;i++)
	 {
		 if(courses[i].courseID==courseID)
		 {
			cout<<"course found at index:"<<i<<endl;
			 return i;
		 }
	 }
	 cout<<"course not found\n";
	 return -1;
 }


//-------admin functions-------
//----view all students----
void viewAllStudents(){
	if(studentCount==0)
	{
		cout<<"No students available.\n";
		return;
	}
	cout<<"Name|ID|Number of registered courses\n";
	cout<<"-------------------------------------";
	for(int i=0;i<studentCount;i++)
	{
		cout<<students[i].Name<<"|"
		<<students[i].StudentID<<"|"
		<<students[i].NumberOfRegisteredCourses<<"|"
		<<endl;

	}
}


//course management
//view all courses

if(totalCourses==0){
    cout<<"No courses available!!"<<endl;
    retun;
}

cout<<"\n#All Courses#\n"<<endl;
      cout<<string(100,'-')<<endl;
      cout<<left<<setw(10)<<"CourseID"
           <<setw(25)<<"CourseName"
           <<setw(25)<<"InstructorName"
           <<setw(10)<<"CreditHours"
           <<setw(15)<<"Time"
           <<setw(10)<<"Day" 
           <<setw(10)<<"Available"<<endl;
           cout<<string(100,'-')<<endl;
for(int i=0; i<totalCourses; i++){
    int Available=courses[i].MaxCapacity-course[i].CurrentEnrolled;

     cout<<left<<setw(10)<<CourseID
           <<setw(25)<<courses[i].CourseName
           <<setw(25)<<courses[i].InstructorName
           <<setw(10)<<courses[i].CreditHours
           <<setw(10)<<courses[i].Time
           <<setw(10)<<courses[i].Day 
           <<setw(10)<<Available<<endl;
           cout<<string(100,'-')<<endl;
}


//----increase student count----
 void increaseStudentCount(int courseID){
	 int index= searchCourse(courseID);
	 if(index==-1){
		 cout<<"course not found.\n";
		 return;
	 }
	 if(courses[index].CurrentEnrolled<courses[index].MaxCapacity)
	 {
	 courses[index].CurrentEnrolled++;
	 }
	 else{
		 cout<<"course is full.\n";
	 }
 
 }



//----decrease student count----
void decreaseStudentCount(int courseID){
	int index= searchCourse(courseID);
	if(index==-1){
		 cout<<"course not found.\n";
		 return;
	 }
	 if(courses[index].CurrentEnrolled>0).
	 {
	 courses[index].CurrentEnrolled--;
	 }
}

