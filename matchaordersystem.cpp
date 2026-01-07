#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct order{
    string drinkName;
    char intensity;
    string intensityName;
    char milkChoice;
    string milkName;
    char syrup;
    string syrupName;
    char whisk;
    string whiskName;
    double totalPrice=0;
};

const int SIZE = 3;
const vector<string> drinks {
    "Matcha Latte", "Strawberry Matcha" , "Blueberry Matcha"
};
const vector<double> price {
    8.00 , 9.50 , 9.5
};

void displayMenu ();
template <typename T>
void inputValidation(T &x , string y);
void inputValidationString(string &x , string y);
void chooseDrink(vector <order> &x);
void intensity (order &x);
void syrup (order &x);
void milk (order &x);
void whisk (order &x);
void dispOrderSummary (vector <order> &x);
double calcGrandTotal (vector <order> &x);


int main (){

    vector<order> urOrder;
    char choice;
    string name;
    string address;
    do{
    cout << " -------------------------------------------------------- " << endl;
    cout << " ----- Welcome to Farhan's Matcha Ordering System ! ----- " << endl;
    cout << " -------------------------------------------------------- " << endl;
    cout << " Our Menu : " << endl;
    displayMenu ();
    cout << endl;
    inputValidationString(name , "Enter your name : ");
    cout << endl;
    inputValidationString(address , "Enter your address : ");
    cout << endl;
    chooseDrink(urOrder);
    dispOrderSummary(urOrder);
    cout << endl << "Do you wish to enter another order?(Y = yes / N = No) : ";
    cin >> choice;
    choice = toupper(choice);
    } while(choice == 'Y');
    cout << "Thank you for ordering !" << endl;
    return 0;
}

void displayMenu (){
    for (int i=0; i < SIZE ; i++){
        cout << i+1 << ". "<< drinks[i] << " - RM " << price[i] << endl;
    }
}

void chooseDrink(vector<order> &urOrder){
    int drinkTypes;
    inputValidation(drinkTypes, "How many different drinks would you like to order (max 3)? : ");

    for (int i = 0; i < drinkTypes; i++) {

        int choice, qty;

        cout << endl <<"Drink Type #" << i + 1 << endl;

        do {
            inputValidation(choice, "Choose your drink (1-3): ");
        } while (choice < 1 || choice > 3);
        int index = choice - 1;

        cout << endl << drinks[index] << endl << endl; 
        inputValidation( qty , "How many cups of this drink? : ");
        cout << endl;
        for (int j = 0; j < qty; j++) {
            order temp;
            temp.totalPrice = price[index];
            cout << "Customisation for cup #" << j + 1 << endl;
            temp.drinkName = drinks[index];
            intensity(temp);
            milk(temp);
            syrup(temp);
            whisk(temp);
            cout << endl;
            urOrder.push_back(temp);
        }
        cout << endl;
    }
}

template <typename T>
void inputValidation(T &x , string y){
    cout << y;
    while (true){
            cin >> x;
            if (cin.fail()){
            cin.clear();
            cin.ignore(1000 , '\n');
            cout << "Invalid input ! Try again : ";
            continue;  
        }
     break;}
 }
 void inputValidationString(string &x , string y){
    cout << y;
    while (true){
            getline ( cin >> ws , x);
            if (cin.fail()){
            cin.clear();
            cin.ignore(1000 , '\n');
            cout << "Invalid input ! Try again : ";
            continue;  
        }
     break;}
 }

void intensity (order &x){
    while (true){
            inputValidation (x.intensity , "Intensity (N = Normal / H = High) : ");
            x.intensity = toupper (x.intensity);
            if ( (x.intensity != 'N') && (x.intensity != 'H') ){
            cin.fail();
            cin.clear();
            cin.ignore(1000 , '\n');
            cout << "Invalid choice ! Try again : ";
            continue;  
            }
            break;
        }
    if ( x.intensity == 'H'){
        x.totalPrice += 1.00;
    }
    if (x.intensity == 'N'){
        x.intensityName = "Normal";
    }
    else {
        x.intensityName = "High";
    }
}

void syrup (order &x){
    while (true){
            inputValidation(x.syrup, "Add syrup? (Y = Yes, N = No): ");
            x.syrup = toupper (x.syrup);
            if ( (x.syrup != 'Y') && (x.syrup != 'N') ){
            cin.fail();
            cin.clear();
            cin.ignore(1000 , '\n');
            cout << "Invalid choice ! Try again : ";
            continue;  
            }
            break;
        }
    if (x.syrup == 'Y'){
        x.totalPrice += 0.50;
    }
    if (x.syrup == 'Y'){
        x.syrupName = "Yes";
    }
    else {
        x.syrupName = "No";
    }
}

void milk (order &x){
    while (true){
            inputValidation(x.milkChoice, "Milk ( O = Oatmilk / D = Dairy ): ");
            x.milkChoice = toupper (x.milkChoice);
            if ( (x.milkChoice != 'O') && (x.milkChoice != 'D') ){
            cin.fail();
            cin.clear();
            cin.ignore(1000 , '\n');
            cout << "Invalid choice ! Try again : ";
            continue;  
            }
            break;
        }
    if (x.milkChoice == 'O' ){
        x.totalPrice += 1.50;
    }
    if (x.milkChoice == 'O'){
        x.milkName = "Oat Milk";
    }
    else {
        x.milkName = "Dairy Milk";
    }
}

void whisk (order &x){
    while (true){
            inputValidation(x.whisk, "Whisk Method? (A = Hot Whisk , B = Cold Whisk): ");
            x.whisk = toupper (x.whisk);
            if ( (x.whisk != 'A') && (x.whisk != 'B') ){
            cin.fail();
            cin.clear();
            cin.ignore(1000 , '\n');
            cout << "Invalid choice ! Try again : ";
            continue;  
            }
            break;
        }
        if ( x.whisk == 'B'){
        x.totalPrice +=1.00;
    }
    if (x.whisk == 'A'){
        x.whiskName = "Hot Whisk";
    }
    else {
        x.whiskName = "Cold Whisk";
    }
}

double calcGrandTotal (vector <order> &x){
    double grandTotal=0;
    for ( int i=0 ; i < x.size(); i++){
        grandTotal += x[i].totalPrice;
    }
    return grandTotal;
}

void dispOrderSummary (vector <order> &x){
    ofstream outFile;
    double subtotal = calcGrandTotal (x);
    outFile.open("Farhan's Matcha Receipt.txt");
    cout << fixed << setprecision(2);
    outFile << fixed << setprecision(2);
    cout << "=======================================" << endl;
    cout << "       Farhan Matcha Receipt           " << endl;
    cout << "=======================================" << endl;
    cout << "Item Customization          Price (RM)" << endl;
    cout << "---------------------------------------" << endl;
    outFile << "=======================================" << endl;
    outFile << "       Farhan Matcha Receipt           " << endl;
    outFile << "=======================================" << endl;
    outFile << "Item Customizatiion          Price (RM)" << endl;
    outFile << "---------------------------------------" << endl;

    for ( int i=0; i < x.size(); i++){
        cout << x[i].drinkName << endl;
        cout << setw(5) << "- Intensity : " << x[i].intensityName << endl;
        cout << setw(5) << "- Milk : " << x[i].milkName << endl;
        cout << setw(5) << "- Syrup : " << x[i].syrupName << endl;
        cout << setw(5) << "- Whisk : " << x[i].whiskName << endl;
        cout << setw(5) << "- Cup's price : " << setw(23) <<x[i].totalPrice << endl;
        cout << "---------------------------------------" << endl;

        outFile << x[i].drinkName << endl;
        outFile << setw(5) << "- Intensity : " << x[i].intensityName << endl;
        outFile << setw(5) << "- Milk : " << x[i].milkName << endl;
        outFile << setw(5) << "- Syrup : " << x[i].syrupName << endl;
        outFile << setw(5) << "- Whisk : " << x[i].whiskName << endl;
        outFile << setw(5) << "- Cup prices : " <<  setw(23) << x[i].totalPrice << endl;
        outFile << "---------------------------------------" << endl;
    }
    cout << "Subtotal" << setw(31) << subtotal << endl;
    outFile << "Subtotal" << setw(31) << subtotal << endl;

    cout << "Delivery fee" << setw(27) << "3" << endl;
    outFile << "Delivery fee" << setw(27) << "3" << endl;

    subtotal+=3;
    cout << "Grand Total" << setw(28) << subtotal << endl;
    cout << "---------------------------------------" << endl;
    outFile << "Grand Total" << setw(28) << subtotal << endl;
    outFile << "---------------------------------------" << endl;
}






