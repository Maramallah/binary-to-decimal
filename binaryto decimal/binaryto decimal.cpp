#include <iostream>
#include <bitset>
#include <string>
#include <cmath>
#include <limits>

using namespace std;
void println(char x, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << x;
    }
    cout << endl;
}
void tap(int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "\t";
    }
}
int ReadNumber() {
    int Number;
    cin >> Number;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one: ";
        cin >> Number;
    }
    return Number;
}
void ReadChoice(int& choice) {

    choice = ReadNumber();

    while (choice != 1 && choice != 2) {
        cout << "Invalid option. Please enter 1 or 2: ";
        choice = ReadNumber();
    }
}
void ReadContinue(int& continue1) {
    cout << "DDO YOU WANT TO CONVERT ANOTHER NUMBER? [1] Yes [2] No: ";
    continue1 = ReadNumber();

    while (continue1 != 1 && continue1 != 2) {
        cout << "Invalid option. Please enter 1 or 2: ";
        continue1 = ReadNumber();
    }
}
void DTB()
{
    int decimal;
    cout << "ENTER THE DECIMAL NUMBER: ";
    decimal = ReadNumber();
    int arr[100]{};
    int size1 = 0;

    while (decimal != 0)
    {
        int reminder = decimal % 2;
        if (reminder == 0)
        {
            arr[size1++] = 0;
        }
        else
        {
            arr[size1++] = 1;
        }
        decimal /= 2;
    }

    cout << "THE BINARY VALUE IS: ";
    for (int i = size1 - 1; i >= 0; i--)
    {
        cout << arr[i] << "";
    }
    cout << endl;
    println('-', 100);
}
void BTD()
{
    string binary;
    bool isValidBinary = false;

    while (!isValidBinary) {
        cout << "ENTER THE BINARY NUMBER: ";
        cin >> binary;
        isValidBinary = true;
        for (char c : binary) {
            if (c != '0' && c != '1') {
                isValidBinary = false;
                cout << "Invalid binary input. Please enter a valid binary." << endl;
                break;
            }
        }
    }
    int arr[binary.size()];
    int x = stoi(binary);

    for (int i = 0; i < binary.size(); i++)
    {
        arr[i] = x % 10;
        x = x / 10;
    }
    int decimal = 0;
    for (int i = 0; i < binary.size(); i++)
    {
        if (arr[i] == 1)
        {
            decimal += pow(2, i);
        }
    }
    cout << "THE DECIMAL VALUE IS : " << decimal << endl;
    println('-', 100);


}
void Header()
{
    int choice;
    int continue1;
    println('*', 100);
    tap(5);
    cout << "MY CONVERTER" << endl;
    println('*', 100);
    do
    {

        cout << "1- BINARY TO DECIMAL" << endl;

        cout << "2- DECIMAL TO BINARY" << endl;
        println('-', 100);
        cout << "ENTER YOUR CHOICE: ";
        ReadChoice(choice);
        println('-', 100);
        if (choice == 1)
        {
            BTD();
        }
        else if (choice == 2)
        {
            DTB();
        }

        ReadContinue(continue1);
        println('-', 100);
    } while (continue1 != 2);
    println('*', 100);
    cout << "Thanks FOR USING MY PROGRAM" << endl;
    println('*', 100);
}


int main()
{
    Header();
    return 0;
}



