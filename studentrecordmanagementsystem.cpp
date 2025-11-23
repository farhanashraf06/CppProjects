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
int main (){
    int choice, index;
    vector<student> students;
    do{
    cout << "----- Welcome to UTM Student File Handling System ----- " << endl;
    cout << "Actions : " << endl;
    cout << "1. Add student " << endl << "2. Display all student " << endl << "3. Search Student by matrix number " << endl;
    cout << "4. Edit student file " << endl << "3. Delete student file  " << endl << "5. Save to file " << endl << "6. Load from file " << endl << "7. Exit" << endl ;
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
        
        case 4:
        break;
        
        case 5:
        break;

        case 6:
        break;

        case 7:
        break;
    }

    }while(choice != 7);
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
    student newStudent;
    cout << "Name :";
    cin >> ws;
    getline (cin , newStudent.name);
    inputValid(newStudent.age , "Age : ");
    inputValid(newStudent.matrixNum , "Matrix Number : ");
    inputValid(newStudent.gpa , "GPA : ");
    students.push_back(newStudent);
}
void dispAll (vector<student> &students){
    for ( int i=0 ; i < students.size() ; i++){
        cout << "Student #" << i+1 << ": " << endl;
        cout << "  " << "Name: "<< students[i].name << endl; 
        cout << "  " << "Age: "<< students[i].age << endl;
        cout << "  " << "Matrix Number: "<< students[i].matrixNum << endl;
        cout << "  " << "GPA: "<<setprecision(2) << fixed << students[i].gpa << endl;   
    }
}
int searchStudent (vector<student> &students){
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
    cout << "Name: "<< x.name << endl; 
    cout << "Age: "<< x.age << endl;
    cout << "Matrix Number: "<< x.matrixNum << endl;
    cout << "GPA: "<<setprecision(2) << fixed << x.gpa << endl;
}
void editStudentFile (vector<student> &students){
    cout << "Search the student by matrix number to edit the file." << endl;
    searchStudent (vector<student> &students);
    cout << ""
     
}
            
        
    
    
