#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
bool checkValid(string&);
void format(string&);
void display(string, bool);
void checkNegative(bool&, string&);
int main(){
    string digit;
    bool neg = false;

    while (true){
        cout << "Enter a 12 digit (maximum) precision number: ";
        cin >> digit;
        checkNegative(neg, digit);
        if (checkValid(digit)) break;
    }

    format(digit);
    display(digit, neg);
    cin.ignore();
    cin.get();
    return 0;
}

bool checkValid(string &check){
    int digs = 0;
    for (int rep = 0; rep < check.length(); rep++){
        if (isdigit(check.at(rep))){
            digs += 1;
        }
    }
    if (digs > 12){
        cout << "Too many digits" << endl;
        return false;
    }
    else if (check.length() > 13){
        cout << "Too many characters" << endl;
        return false;
    }
    else if (check == "0"){
        check = "0.00";
        return true;
    }
    else if (check.find(".") == -1){
        cout << "No decimal found" << endl;
        return false;
    }
    else if (!(check.find(".") == check.length()-3 || check.find(".") == check.length()-4)){
        cout << "Decimal not in the right position" << endl;
        return false;
    }
    return true;
}

void format(string &digit){
    int dec = digit.find(".");
    if (dec == -1){
        dec = digit.length();
    }
    for (int rep = dec; rep > 0; rep -= 3){
        if (rep != dec){
            digit.insert(rep, ",");
        }
    }
    if (digit.find(".") == digit.length()-4){
        digit.erase(digit.length() -1, 1);
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
