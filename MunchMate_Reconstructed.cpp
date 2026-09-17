//Name : Noemi Grace S. Villame
//Course: ENCFAP2L
//Section: BSCE_CIV226
//Prof Engr. Marlon G. Bagara

#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<windows.h>
#include<process.h>
#include<cstdlib>
#include<ctime>
#include<math.h>

using namespace std;

void gotoxy(int, int);
void clrscr();

void gotoxy(int x, int y) {
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

void clrscr() {
    system("cls");
}

int main() {
    srand(time(0));
    
    string name;                          
    
    // FIXED: Explicitly declared as standard array tracks with a size of 5
    string choice[5];       
    float price[5] = {0};         
    int servings[5] = {0};        
    
    float total_Purchase = 0; 
    char options; 
	int tryAgain;          
    
    int itemCount = 0;
    float cash = 0, change = 0;
    int refNumber = rand() % 9000 + 1000; 

    // Screen 1: Welcome Screen
    clrscr();
    gotoxy(16, 5);  cout << "========================================";
    gotoxy(16, 6);  cout << "|  Hungry? Welcome to MunchMate!       |";
    gotoxy(16, 7);  cout << "========================================";
    gotoxy(16, 15); cout << "---- Press enter key to proceed ----";
    getch();

    // Screen 2: Customer Registration
    clrscr();
    gotoxy(2, 3); cout << "============== MunchMate Food App ==============";
    gotoxy(2, 5); cout << "Customer's Name: ";
    getline(cin, name);
    gotoxy(15, 10); cout << " Click to proceed >>> ";
    cin.ignore(); 

    // Menu Selection Loop
    do {
        if (itemCount >= 5) {
            cout << "\nMaximum order capacity of 5 items reached!";
            break;
        }

        clrscr();
        gotoxy(2, 3); cout << "============== MunchMate Food App ==============";
        gotoxy(17, 6); cout << "1. Meals";
        gotoxy(17, 7); cout << "2. Snacks";
        gotoxy(17, 8); cout << "3. Beverages";
        gotoxy(17, 10); cout << "Enter your choice: ";
        int categoryChoice;
        cin >> categoryChoice;

        clrscr();
        gotoxy(0, 2); cout << "==========================================================================" << endl;
        gotoxy(32, 4); cout << "MunchMate MENU" << endl << endl;
        
        int itemSelect = 0;
        float inputPrice = 0;
        bool validSelection = false;

        // --- CATEGORY 1: MEALS ---
        if (categoryChoice == 1) {
            cout << "\t\t-------------------------------------------------\n";
            cout << "\t\t|          Meal         |         Price         |\n";
            cout << "\t\t-------------------------------------------------\n";
            cout << "\t\t| 1. Fish Fillet        |          128          |\n";
            cout << "\t\t| 2. Sisig              |          135          |\n";
            cout << "\t\t| 3. Beef Steak         |          120          |\n";
            cout << "\t\t| 4. Adobo              |          85           |\n";
            cout << "\t\t| 5. Liempo             |          135          |\n";
            cout << "\t\t-------------------------------------------------\n\n";
            
            cout << "Enter item choice (1-5): ";
            cin >> itemSelect;
            
            switch(itemSelect) {
                case 1: choice[itemCount] = "Fish Fillet"; price[itemCount] = 128; break;
                case 2: choice[itemCount] = "Sisig";       price[itemCount] = 135; break;
                case 3: choice[itemCount] = "Beef Steak";   price[itemCount] = 120; break;
                case 4: choice[itemCount] = "Adobo";        price[itemCount] = 85;  break;
                case 5: choice[itemCount] = "Liempo";       price[itemCount] = 135; break;
                default: choice[itemCount] = "N/A";        price[itemCount] = 0;   break;
            }
            validSelection = (itemSelect >= 1 && itemSelect <= 5);
        } 
        // --- CATEGORY 2: SNACKS ---
        else if (categoryChoice == 2) {
            cout << "\t\t-------------------------------------------------\n";
            cout << "\t\t|         Snacks        |         Price         |\n";
            cout << "\t\t-------------------------------------------------\n";
            cout << "\t\t| 1. Churros            |          100          |\n";
            cout << "\t\t| 2. French Fries       |          45           |\n";
            cout << "\t\t| 3. Spaghetti          |          75           |\n";
            cout << "\t\t| 4. Beef Burger        |          32           |\n";
            cout << "\t\t| 5. Mango Float        |          120          |\n";
            cout << "\t\t-------------------------------------------------\n\n";
            
            cout << "Enter item choice (1-5): ";
            cin >> itemSelect;
            
            switch(itemSelect) {
                case 1: choice[itemCount] = "Churros";      price[itemCount] = 100; break;
                case 2: choice[itemCount] = "French Fries"; price[itemCount] = 45;  break;
                case 3: choice[itemCount] = "Spaghetti";    price[itemCount] = 75;  break;
                case 4: choice[itemCount] = "Beef Burger";  price[itemCount] = 32;  break;
                case 5: choice[itemCount] = "Mango Float";  price[itemCount] = 120; break;
                default: choice[itemCount] = "N/A";        price[itemCount] = 0;   break;
            }
            validSelection = (itemSelect >= 1 && itemSelect <= 5);
        } 
        // --- CATEGORY 3: BEVERAGES ---
        else if (categoryChoice == 3) { 
            cout << "\t\t-------------------------------------------------\n";
            cout << "\t\t|       Beverages       |         Price         |\n";
            cout << "\t\t-------------------------------------------------\n";
            cout << "\t\t| 1. Mango Shake        |          75           |\n";
            cout << "\t\t| 2. Buko Pandan        |          50           |\n";
            cout << "\t\t| 3. Iced Tea           |          33           |\n";
            cout << "\t\t| 4. Coke               |          20           |\n";
            cout << "\t\t| 5. Sprite             |          20           |\n";
            cout << "\t\t-------------------------------------------------\n\n";
            
            cout << "Enter item choice (1-5): ";
            cin >> itemSelect;
            
            switch(itemSelect) {
                case 1: choice[itemCount] = "Mango Shake"; price[itemCount] = 75; break;
                case 2: choice[itemCount] = "Buko Pandan"; price[itemCount] = 50; break;
                case 3: choice[itemCount] = "Iced Tea";    price[itemCount] = 33; break;
                case 4: choice[itemCount] = "Coke";        price[itemCount] = 20; break;
                case 5: choice[itemCount] = "Sprite";      price[itemCount] = 20; break;
                default: choice[itemCount] = "N/A";        price[itemCount] = 0;  break;
            }
            validSelection = (itemSelect >= 1 && itemSelect <= 5);
        }

        cout << "==========================================================================" << endl;
        cout << "Customer's Name: " << name << endl << endl;
        cout << "\t\t\t\tMunchMate App" << endl;
        cout << "\t\t\t\tFoods & Beverages" << endl << endl;

        string catLabel = (categoryChoice == 1) ? "Meal: " : (categoryChoice == 2) ? "Snacks: " : "Beverage: ";
        cout << catLabel << choice[itemCount] << endl;

        // Interactive Price Verification System
        if (validSelection) {
            do {
                cout << "Price: ";
                cin >> inputPrice;
                if (inputPrice != price[itemCount]) {
                    cout << "Invalid price...Out of range." << endl;
                }
            } while (inputPrice != price[itemCount]);
            
            cout << "Servings: ";
            cin >> servings[itemCount];
        } else {
            cout << "Price: 0" << endl;
            cout << "Servings: 0" << endl;
            servings[itemCount] = 0;
        }

        total_Purchase += (price[itemCount] * servings[itemCount]);
        itemCount++;

        cout << "\nDo you want to add more items? (Y/N): ";
        cin >> options;

    } while ((options == 'Y' || options == 'y') && itemCount < 5);

    // Screen 4: Order Summary Screen
    clrscr();
    cout << "==========================================================================" << endl;
    cout << "Customer's Name: " << name << endl << endl;
    cout << "\t\t\t\tMunchMate App" << endl;
    cout << "\t\t\t\tFoods & Beverages" << endl << endl;

    for (int i = 0; i < itemCount; i++) {
        string summaryLabel = "Item: ";
        if(choice[i] == "Fish Fillet" || choice[i] == "Sisig" || choice[i] == "Beef Steak" || choice[i] == "Adobo" || choice[i] == "Liempo") summaryLabel = "Meal: ";
        else if(choice[i] == "Churros" || choice[i] == "French Fries" || choice[i] == "Spaghetti" || choice[i] == "Beef Burger" || choice[i] == "Mango Float") summaryLabel = "Snacks: ";
        else if(choice[i] == "Mango Shake" || choice[i] == "Buko Pandan" || choice[i] == "Iced Tea" || choice[i] == "Coke" || choice[i] == "Sprite") summaryLabel = "Beverage: ";
        
        cout << summaryLabel << choice[i] << endl;
        cout << "Price: " << price[i] << endl;
        cout << "Servings: " << servings[i] << endl << endl;
    }
    cout << "Press enter to view receipt...";
    getch();

    // Payment Processing
    clrscr();
    cout << "Total Purchase: " << total_Purchase << endl;
    do {
        cout << "Enter Cash Amount: ";
        cin >> cash;
        if (cash < total_Purchase) {
            cout << "Insufficient Cash! Please try again.\n";
        }
    } while (cash < total_Purchase);
    change = cash - total_Purchase;
    // Screen 5: Final Receipt Screenclrscr();
cout << "==========================================================================" << endl;
cout << "\t\t\t\tOrder Receipt\n\n";
cout << "Customer's Name: " << name << endl;
cout << "Reference Number: " << refNumber << endl << endl;
cout << "\t\t\t\tMunchMate\n";
cout << "\t\t\t\tFood & Beverages\n\n";cout << left << setw(25) << "Food" << setw(15) << "Price" << setw(15) << "Servings" << "Total" << endl;
cout << "--------------------------------------------------------------------------" << endl;
for (int i = 0; i < itemCount; i++) {float itemTotal = price[i] * servings[i];
cout << left << setw(25) << choice[i]<< setw(15) << price[i]<< setw(15) << servings[i]<< itemTotal << endl;}
cout << "--------------------------------------------------------------------------" << endl;
cout << left << setw(40) << "Total purchase:" << total_Purchase << endl;
cout << left << setw(40) << "Cash:" << cash << endl;
cout << "--------------------------------------------------------------------------" << endl;
cout << left << setw(40) << "Change:" << change << endl;
cout << "--------------------------------------------------------------------------" << endl;
cout << "\n\t------ You can claim your order within 24 hours only ------\n";
cout << "\t--------------------- NOTHING FOLLOWS ---------------------\n";
cout << "\nPress enter to exit...";
getch();

// Screen 6: Final Thank You Interface Outputclrscr();
clrscr();
cout << "========== Thank you for using MunchMate Food App! ==========\n\n";
cout << "Present your reference number to the cashier to claim your order.\n";
cout << "The MunchMate service crew will deliver your food to your table.\n\n";
cout << "==================== Enjoy ka- MunchMate! ====================\n";return 0;}
