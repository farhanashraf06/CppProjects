#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <fstream>

using namespace std;
struct order{
    char intensity;
    char milkChoice;
    bool syrup;
    char whisk;
    string Address;
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
void chooseDrink(vector <order> &x);
void intensity (order &x);
void syrup (order &x);
void milk (order &x);
void whisk (order &x);
void dispOrderSummary (vector <order> &x);
void calcGrandTotal (vector <order> &x);


int main (){
    vector<order> urOrder;
    int choices;
    cout << " -------------------------------------------------------- " << endl;
    cout << " ----- Welcome to Farhan's Matcha Ordering System ! ----- " << endl;
    cout << " -------------------------------------------------------- " << endl;
    cout << " Our Menu : " << endl;
    displayMenu ();
    chooseDrink(urOrder);
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

        for (int j = 0; j < qty; j++) {
            order temp;
            temp.totalPrice = price[index] * qty;
            cout << "Customisation for cup #" << j + 1 << endl;

            intensity(temp);
            milk(temp);
            syrup(temp);
            whisk(temp);
            inputValidation(temp.Address, "Enter your address : ");



            urOrder.push_back(temp);
        }
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
void intensity (order &x){
    inputValidation (x.intensity , "Intensity (N = Normal / H = High) : ");
    x.intensity = toupper (x.intensity);
    if ( x.intensity == 'H'){
        x.totalPrice += 1.00;
    }
}

void syrup (order &x){

    inputValidation(x.syrup, "Add syrup? (1 = Yes, 0 = No): ");
    if (x.syrup == 1){
        x.totalPrice += 0.50;
    }
}

void milk (order &x){
    inputValidation(x.milkChoice, "Milk ( O = Oatmilk / D = Dairy ): ");
    x.milkChoice = toupper (x.milkChoice);
    if (x.milkChoice == 'O' ){
        x.totalPrice += 1.50;
    }
}
void whisk (order &x){
    inputValidation(x.whisk, "Whisk Method? (A = Hot Whisk , B = Cold Whisk): ");
    x.whisk = toupper (x.whisk);
    if ( x.whisk == 'B'){
        x.totalPrice +=1.00;
    }
}
void calcGrandTotal (vector <order> &x){
    
}
void dispOrderSummary (vector <order> &x){
    ofstream outFile;
    outFile.open("Farhan's Matcha Receipt.txt");

}






