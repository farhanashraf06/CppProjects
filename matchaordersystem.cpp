#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct order{
    char drinkChoice;
    int drinkAmount;
    char intensity;
    char milkChoice;
    bool syrup;
    char whisk;
    string Address;
    char time;
};
void displayMenu ();


int main (){
    vector<order> urOrder;
    cout << " -------------------------------------------------------- " << endl;
    cout << " ----- Welcome to Farhan's Matcha Ordering System ! ----- " << endl;
    cout << " -------------------------------------------------------- " << endl;
    cout << " Our Menu : " << endl;
    displayMenu ();
    

    return 0;
}
void displayMenu (){
    cout << " a. Matcha Latte - RM 8 " << endl << " a. Strawberry Matcha - RM 9.5 " << endl << " a. Blueberry Matcha - RM 9.5 ";
}
void chooseDrink(vector<order> urOrder){
    for (int i =0; i < 3; i++ ) {
        cout << "Choose your drink choice (a-c) : ";
        cin >> urOrder[i].drinkChoice;
        cout << "How many of this drink would you like ? : " ;
        cin >>urOrder[i].drinkAmount;
    }

}