#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
bool checkValid(string&, bool&);
void format(string&);
void display(string, bool);
void checkNegative(bool&, string&);
void displayNames();
int main(){
    string digit;
    bool neg = false;
    displayNames();
    while (true){
        cout << "Enter a 12 digit (maximum) precision number: ";
        cin >> digit;
        checkNegative(neg, digit);
        if (checkValid(digit,neg)) break;
    }

    format(digit);
    display(digit, neg);
    cin.ignore();
    cin.get();
    return 0;
}

bool checkValid(string &check, bool& neg){
    int digs = 0;
    int dec = check.find(".");
    for (int rep = 0; rep < check.length(); rep++){
        if (isdigit(check.at(rep))){
            digs += 1;
        }
        else if (!isdigit(check.at(rep)) && dec != rep){
            cout << "All values must be numeric except for optional negative and optional decimal point" << endl;
            return false;
        }
    }
    if (digs > 12){
        cout << "Too many digits" << endl;
        return false;
    }
    else if (check == "0"){
        neg = false;
        return true;
    }
    return true;
}

void format(string &digit){
    int dec = digit.find(".");
    int start = dec;

    if (dec == -1){
        start = digit.length();
    }
    else if (dec == digit.length()-2){
        digit.append("0");
    }
    else if (dec != -1){
        //Do dec + 3 because dec + 1 will give us the amount up to and including the decimal
        // but since we want the stop 2 spots higher for the 2 decimal points we have to add 2
        digit = digit.substr(0,dec+3);
    }


    for (int rep = start; rep > 0; rep -= 3){
        if (rep != start){
            digit.insert(rep, ",");
        }
    }
    digit.insert(0, "$");
}

void display(string digit, bool neg){
    cout << "Number into currency format: ";
    if (neg){
        cout << "-" << digit << endl;
    }
    else{
        cout << digit << endl;
    }
}

void checkNegative(bool &neg, string &digit){
    if (digit.at(0) == '-'){
            neg = true;
            digit = digit.substr(1);
    }
}

void displayNames(){
    cout << "Student name:" << setw(18) << "Glen Dsouza" << endl;
    cout << "Student number:" << setw(14) << "900914917" << endl;
    cout << "Student name:" << setw(24) << "Jordon Marchesano" << endl;
    cout << "Student number:" << setw(14) << "900536880" << endl;
    cout << endl << endl;
}
