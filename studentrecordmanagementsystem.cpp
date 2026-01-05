#include <iostream> // basic I/O
#include <fstream> // for file input and output
#include <iomanip>
#include <vector> // uses vector for flexibilty , array has size limit
using namespace std;
struct student { // create struct for simpler pogram
    string name;
    int age;
    string matrixNum;
    float gpa;

};
// function declarations
void addStudent (vector<student> &students);
void dispAll (vector<student> &students);
int searchStudent (vector<student> &students);
void dispStudent (const student &x);
void editStudentFile (vector<student> &students);
void deleteFile (vector <student> &students);
void svtof (vector<student> &students);
void lff (vector<student> &students);
bool duplimatrix (vector<student> &students , string &mtrix);

int main (){
    int choice, index;
    vector<student> students;
    do{ // repeat the main program everytime except when user pick 9th choice
    cout << "----- Welcome to UTM Student File Handling System ----- " << endl;
    cout << "Actions : " << endl;
    cout << "1. Add student " << endl << "2. Display all student " << endl << "3. Search Student by matrix number " << endl;
    cout << "4. Edit student file " << endl << "5. Delete student file  " << endl << "6. Save to file " << endl << "7. Load from file " << endl << "8. Student count" << endl;
    cout << "9. Exit program " <<endl;
    cout << "Choose an action : #" ;

    while(true){
        cin >> choice;
        if ((cin.fail()) || (choice < 1 ) || (choice > 9) ){
        cout << "Invalid Input ! Enter again. " << endl;
        cin.clear();
        cin.ignore (1000 , '\n');
        continue;
    }
    break;}
    
    switch (choice) { // uses switch to analyze users input and match them with cases
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

        case 6: svtof (students);
        break;

        case 7: lff (students);
        break;

        case 8: cout << "Total Student : " << students.size() << endl;
        break;

        case 9: cout << "Thank you !" << endl;
                return 0;
        break;

        default: cout << "Invalid choice ! Enter again : " ;
        break;
    }
    cout << endl;
    }while(choice != 9);

}
// function definitions
template <typename F> // using function template for flexibility
void inputValid (F &x, const string prompt){ // this function is to check input validity
        while (true){
        cout << prompt;
        cin >> x;
        if (cin.fail()){
            cout << "Invalid Input ! Enter again : " ;
            cin.clear();
            cin.ignore( 1000, '\n');
            continue; // will skip the remaining body loop
        }
            break;
        }
    }

void addStudent (vector<student> &students){ // function to add a student to the vector
    cout << endl;
    student newStudent;
    cout << "Name :";
    cin.ignore (1000 , '\n');
    getline (cin , newStudent.name);
    inputValid(newStudent.age , "Age : ");
    do {
        inputValid(newStudent.matrixNum , "Matrix Number : ");
        if (duplimatrix (students , newStudent.matrixNum)){
            cout << "Matrix number already existed ! Enter again : " << endl;
        }
    }while (duplimatrix (students , newStudent.matrixNum));
    
    while (true){
        inputValid(newStudent.gpa , "GPA : ");
        if ((newStudent.gpa >= 0.00) && (newStudent.gpa <= 4.00)){
           break;}
           cout << "Invalid GPA ! Enter again (0.00 - 4.00): ";
    }
    
    students.push_back(newStudent); //pushes new student in the vector from the back
}

void dispAll (vector<student> &students){ // function to display all student in the vector
    cout << endl;
    for ( int i=0 ; i < students.size() ; i++){
        cout << "Student #" << i+1 << ": " << endl;
        cout << "  " << "Name: "<< students[i].name << endl; 
        cout << "  " << "Age: "<< students[i].age << endl;
        cout << "  " << "Matrix Number: "<< students[i].matrixNum << endl;
        cout << "  " << "GPA: "<<setprecision(2) << fixed << students[i].gpa << endl;   
    }
}

int searchStudent (vector<student> &students){ // function to search student based on matrix number
    cout << endl;
    string search;
    cout << "Enter the Matrix Number : " ;
    cin >> search;
    for (int i=0 ; i < students.size() ; i++){
        if (search == students[i].matrixNum){
            return i;
        }  
    }
    return -1; // -1 so that the main program can know search was unsuccessful
}
void dispStudent (const student &x) { // function to display a spesific student
    cout << endl;
    cout << "Name: "<< x.name << endl; 
    cout << "Age: "<< x.age << endl;
    cout << "Matrix Number: "<< x.matrixNum << endl;
    cout << "GPA: "<<setprecision(2) << fixed << x.gpa << endl;
}
void editStudentFile (vector<student> &students){ // function to let user edit a student file
    int c;
    char choice;
    cout << "Search the student by matrix number to edit the file." << endl;
    int index = searchStudent(students);
                if (index >=0){
                    cout << "Student Found !" << endl;
                    dispStudent(students[index]);
                }
                else{
                    cout << "Student does not exist ! " << endl;
                    return; 
                }
    cout << "What would you like to edit? : " << endl;
    inputValid ( c , "1. Name , 2. Age , 3. Matrix Number , 4. GPA , 5. Edit all : ");
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
            cout << "Invalid Input ! only number 1-5. " << endl; 
        }
        inputValid(choice , "Are you sure to edit this file? (y/n) : "); // comfirmation from user
        if (isupper (choice)){
        choice = tolower(choice);
        }
        if(choice == 'y' ){
        cout << "Student file successfully edited ! " << endl;
        }
        else {
        cout << "Edit cancelled ." << endl;
        return; // exiting the function without returning anything (cannot return any value bc void)
        }     
            
}
void deleteFile (vector <student> &students){ // function to delete student file by searching for the matrix number
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
                    return; // exiting the function without returning anything (cannot return any value bc void)
                }
    inputValid(choice , "Are you sure to delete this file? (y/n) : ");
    if (isupper (choice)){
        choice = tolower(choice);
    }
    if(choice == 'y' ){
        students.erase(students.begin() + index);
        cout << "File deleted successfully ! " << endl;
    }
    else {
        cout << "Deletation cancelled ." << endl;
    }

}
void svtof (vector<student> &students){ // fucntion to save to a file called student.txt
    fstream outfile ("student.txt");
    cout << endl;
    for ( int i=0 ; i < students.size() ; i++){
        outfile << "  " << "Name: "<< students[i].name << endl; 
        outfile << "  " << "Age: "<< students[i].age << endl;
        outfile << "  " << "Matrix Number: "<< students[i].matrixNum << endl;
        outfile << "  " << "GPA: "<<setprecision(2) << fixed << students[i].gpa << endl;}
        outfile.close();   
        cout << "File saved successfully . " << endl;
}     
void lff (vector<student> &students){ // function to call from file called student.txt
    fstream infile ("student.txt");
    if (!infile){
        cout << "File does not exist ! " <<endl;
        return;
    }
    students.clear(); // to avoid duplicates

    student temp;
    while (getline (infile , temp.name)){
        infile >> temp.age;
        infile >> temp.matrixNum;
        infile >> temp.gpa;
        infile.ignore (10000 , '\n');

        students.push_back(temp);
    }
    infile.close();
    cout << "Student loaded successfully !" << endl;  
}
bool duplimatrix (vector<student> &students , string &mtrix){ // function to check if there's duplicate matrix number
    for (auto &s : students ){
        if (s.matrixNum == mtrix){
            return true;
        }
    }
     return false;
}