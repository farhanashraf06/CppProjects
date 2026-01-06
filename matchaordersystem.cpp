#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
struct order{
    int drinkChoice;
    int drinkAmount;
    char intensity;
    char milkChoice;
    bool syrup;
    char whisk;
    string Address;
    char time;
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
void chooseDrink(vector<order> &urOrder);


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

        cout << "\nDrink #" << i + 1 << endl;

        do {
            inputValidation(choice, "Choose your drink (1-3): ");
        } while (choice < 1 || choice > 3);

        inputValidation(qty, "How many cups of this drink? ");

        for (int j = 0; j < qty; j++) {
            order temp;

            temp.drinkChoice = choice;
            temp.drinkAmount = 1;

            cout << "Customisation for cup #" << j + 1 << endl;

            inputValidation(temp.intensity, "Intensity (L/M/H): ");
            inputValidation(temp.milkChoice, "Milk (O/D): ");
            inputValidation(temp.syrup, "Add syrup? (1=Yes, 0=No): ");

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