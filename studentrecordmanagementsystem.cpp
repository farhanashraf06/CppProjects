#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
struct student {
    string name;
    int age;
    string matrixNum;
    float gpa;

};
void addStudent (vector<student> &students);
void dispAll (vector<student> &students);
int searchStudent (vector<student> &students);
void dispStudent (const student &x);
void editStudentFile (vector<student> &students);
void deleteFile (vector <student> &students);
int main (){
    int choice, index;
    vector<student> students;
    do{
    cout << "----- Welcome to UTM Student File Handling System ----- " << endl;
    cout << "Actions : " << endl;
    cout << "1. Add student " << endl << "2. Display all student " << endl << "3. Search Student by matrix number " << endl;
    cout << "4. Edit student file " << endl << "5. Delete student file  " << endl << "6. Save to file " << endl << "7. Load from file " << endl << "8. Exit" << endl ;
    cout << "Choose an action : #" ;

    while(true){
        cin >> choice;
        if ((cin.fail()) || (choice < 1 ) || (choice > 7) ){
        cout << "Invalid Input ! Enter again. " << endl;
        cin.clear();
        cin.ignore (1000 , '\n');
        continue;
    }
    break;}
    switch (choice) {
        case 1: addStudent(students);
        break;

        case 2: dispAll (students);
        break;
        
        case 3: index = searchStudent(students);
                if (index >=0){
                    cout << "Student Found !" << endl;
                    dispStudent(students[index]);
                }
                else{
                    cout << "Student does not exist ! " << endl;
                }

        break;
        
        case 4: editStudentFile (students);
        break;
        
        case 5: deleteFile (students);
        break;

        case 6:
        break;

        case 7:
        break;

        case 8:
        break;

        default:
        break;
    }
    cout << endl;
    }while(choice != 8);
return 0;
}
template <typename F>
void inputValid (F &x, const string prompt){
        while (true){
        cout << prompt;
        cin >> x;
        if (cin.fail()){
            cout << "Invalid Input ! Enter again : " ;
            cin.clear();
            cin.ignore( 1000, '\n');
            continue;
        }
            break;
        }
    }
void addStudent (vector<student> &students){
    cout << endl;
    student newStudent;
    cout << "Name :";
    cin.ignore (1000 , '\n');
    getline (cin , newStudent.name);
    inputValid(newStudent.age , "Age : ");
    inputValid(newStudent.matrixNum , "Matrix Number : ");
    inputValid(newStudent.gpa , "GPA : ");
    students.push_back(newStudent);
}
void dispAll (vector<student> &students){
    cout << endl;
    for ( int i=0 ; i < students.size() ; i++){
        cout << "Student #" << i+1 << ": " << endl;
        cout << "  " << "Name: "<< students[i].name << endl; 
        cout << "  " << "Age: "<< students[i].age << endl;
        cout << "  " << "Matrix Number: "<< students[i].matrixNum << endl;
        cout << "  " << "GPA: "<<setprecision(2) << fixed << students[i].gpa << endl;   
    }
}
int searchStudent (vector<student> &students){
    cout << endl;
    string search;
    cout << "Enter the Matrix Number : " ;
    cin >> search;
    for (int i=0 ; i < students.size() ; i++){
        if (search == students[i].matrixNum){
            return i;
        }  
    }
    return -1;
}
void dispStudent (const student &x) {
    cout << endl;
    cout << "Name: "<< x.name << endl; 
    cout << "Age: "<< x.age << endl;
    cout << "Matrix Number: "<< x.matrixNum << endl;
    cout << "GPA: "<<setprecision(2) << fixed << x.gpa << endl;
}
void editStudentFile (vector<student> &students){
    int c;
    cout << "Search the student by matrix number to edit the file." << endl;
    int index = searchStudent(students);
                if (index >=0){
                    cout << "Student Found !" << endl;
                    dispStudent(students[index]);
                }
                else{
                    cout << "Student does not exist ! " << endl;
                }
    cout << "What would you like to edit? : " << endl;
    inputValid ( c , "1. Name , 2. Age , 3. Matrix Number , 4. GPA , 5. Edit all ");
    switch (c){
        case 1:
            cout << "Enter new name : " << endl;
            cin.ignore (1000 , '\n');
            getline (cin , students[index].name);
            break;
        case 2:
            inputValid(students[index].age , "Enter new age : ");
            break;
         case 3:
            inputValid(students[index].matrixNum , "Enter new matrix number : ");
            break;
        case 4:
            inputValid(students[index].gpa , "Enter new GPA : ");
            break;
        case 5:
            cin.ignore (1000 , '\n');
            cout << "Enter new name : " << endl;
            getline (cin , students[index].name);
            inputValid(students[index].age , "Enter new age : ");
            inputValid(students[index].matrixNum , "Enter new matrix number : ");
            inputValid(students[index].gpa , "Enter new GPA : ");
            break;
        default :
            cout << "Invalid Input ! only number 1-5. " << endl; }     
            cout << "Student file successfully edited ! " << endl;
}
void deleteFile (vector <student> &students){
    int c;
    char choice;
    cout << "Search the student by matrix number to delete the file." << endl;
    int index = searchStudent(students);
                if (index >=0){
                    cout << "Student Found !" << endl;
                    dispStudent(students[index]);
                }
                else{
                    cout << "Student does not exist ! " << endl;
                }
    inputValid(choice , "Are you sure to delete this file? (y/n) : ")
    if (isupper (choice)){
        choice = tolower(choice);
    }
    if(choice == y ){
        students.erase(students.begin() + index)
        cout << "File deleted successfully ! " << endl;
    }
    else {
        cout << "Deletation cancelled ." << endl;
    }

}
void svtof (vector<student> &students){
    fstream.outfile ("student.txt");
    
}   
        
    
    
