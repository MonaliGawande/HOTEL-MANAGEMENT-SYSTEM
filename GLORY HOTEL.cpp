#include <iostream>
#include <iomanip>
using namespace std;

struct MenuItem {
    string name;
    int price;
};

void printMenu(const MenuItem menu[], int size) {
    cout << "\nMenu:\n" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << " " << menu[i].name << " " << menu[i].price << "/-" << endl;
    }
    cout << "0 Exit" << endl;
}

int main() {
    MenuItem menu[] = {
        {"Samosa",20},
        {"Dosa\t",30},
        {"Tea\t",10}
    };

    int quantity;
    int choice;
    int totalBill = 0;

    cout << "***** Welcome to The Glory Hotel! *****\n\n" << endl;

    do {
        printMenu(menu, sizeof(menu) / sizeof(menu[0]));

        cout << "\nEnter your Choice: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > sizeof(menu) / sizeof(menu[0])) {
            cout << "Invalid choice! Please try again." << endl;
            continue;
        }

        cout << "Enter number of plates: ";
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Invalid quantity! Please try again." << endl;
            continue;
        }

        totalBill += menu[choice - 1].price * quantity;
    } while (true);

    cout << "\n\n::Your Bill::\n\n" << endl;
    cout << "  Sr.No.| Item   | Qty | Rate | Sub Total" << endl;
    cout << "-----------------------------------------------" << endl;

    int srNo = 1;
    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        int subTotal = menu[i].price * quantity;
        if (quantity > 0) {
            cout << setw(7) << srNo << " | " << setw(6) << menu[i].name << " | " << setw(3) << quantity << " | " << setw(4) << menu[i].price << " | " << setw(9) << subTotal << "/-" << endl;
            srNo++;
        }
    }

    cout << "-----------------------------------------------\n" << endl;
    cout << "\nGrand Total: " << totalBill << "/-" << endl;

    int cash;
    do {
        cout << endl << "Enter Your Cash: ";
        cin >> cash;

        if (cash < totalBill) {
            cout << "Please pay " << totalBill - cash << " Rs. more" << endl;
        } else {
            break;
        }
    } while (true);

    if (cash > totalBill) {
        cout << "\nReturn Amount: " << cash - totalBill << endl;
    }

    cout << "\n-------- T H A N K  Y O U! ----------" << endl;
    cout << "\n----- V I S I T  A G A I N! -------" << endl;
    cout << "\n**********************************************" << endl;

    return 0;
}
