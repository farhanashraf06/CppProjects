#include <iostream>
#include <vector>
#include <iomanip>
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


int main (){
    vector<order> urOrder;
    int choices;
    cout << " -------------------------------------------------------- " << endl;
    cout << " ----- Welcome to Farhan's Matcha Ordering System ! ----- " << endl;
    cout << " -------------------------------------------------------- " << endl;
    cout << " Our Menu : " << endl;
    displayMenu ();
    inputValidation (choices , " How many different drink would you like to order ? : ");
    urOrder.resize (choices);
    

    return 0;
}
void displayMenu (){
    for (int i=0; i < SIZE ; i++){
        cout << i+1 << ". "<< drinks[i] << " - RM " << price[i] << endl;
    }
}
void chooseDrink(vector<order> &urOrder){
    for (int i =0; i < urOrder.size(); i++ ) {
        cout << "\nOrder #" << i+1 << " : " ;
        inputValidation (urOrder[i].drinkChoice , "Choose your drink choice (1-3) : ");
        inputValidation (urOrder[i].drinkAmount, "How many of this drink wouldd you like :");

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
        continue;  }
     }
     return;   }