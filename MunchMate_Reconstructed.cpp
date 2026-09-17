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
	
	const int MAX_ITEMS = 15;                       
    
    string choice[MAX_ITEMS];       
    float price[MAX_ITEMS] = {0};         
    int servings[MAX_ITEMS] = {0};        
    
    float total_Purchase = 0; 
    char options; 
    int tryAgain;        
    
    int itemCount = 0;
    float cash = 0, change = 0;
    int refNumber = rand() % 9000 + 1000; 

    // Screen 1: Welcome Screen
    clrscr();
    gotoxy(16, 5);  cout << "========================================";
    gotoxy(16, 6);  cout << "|   Hungry? Welcome to MunchMate!        |";
    gotoxy(16, 7);  cout << "========================================";
    gotoxy(16, 15); cout << "    ---- Press enter to proceed ----";
    getch();

    // Screen 2: Customer Registration
    clrscr();
    gotoxy(16, 5); cout << "============== MunchMate Food App ==============";
    gotoxy(16, 9); cout << "Customer's Name: ";
    getline(cin, name);
    gotoxy(16, 15); cout << "\t---- Press enter to proceed ----";
    cin.ignore(); 

    // Menu Selection Loop
    
    char moreFromCategory;
    char moreCategories;
    
    do {
    if (itemCount >= MAX_ITEMS) {
        gotoxy(17, 11);
        cout << "Maximum order capacity of " << MAX_ITEMS << " items reached!";
        break;
    }

    clrscr();

    gotoxy(17, 3); cout << "============== MunchMate Food App ==============";
    gotoxy(17, 6); cout << "1. Meals";
    gotoxy(17, 7); cout << "2. Snacks";
    gotoxy(17, 8); cout << "3. Beverages";
    gotoxy(17, 10); cout << "Enter your choice (1-3): ";

    int categoryChoice;
    cin >> categoryChoice;

    // Validate category choice
    while (categoryChoice < 1 || categoryChoice > 3) {
        gotoxy(17, 12);
        cout << "Invalid choice! Please enter 1, 2, or 3: ";
        cin >> categoryChoice;
    }
       
    // Inner loop: allows multiple items from the same category

do {
    int itemSelect = 0;
    bool validSelection = false;

    clrscr();

    gotoxy(3, 3);
    cout << "==========================================================================" << endl;

    gotoxy(32, 5);
    cout << "MunchMate MENU" << endl << endl;
    
    // --- CATEGORY 1: MEALS ---
    if (categoryChoice == 1)
   {
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t|          Meal         |         Price         |\n";
        cout << "\t\t-------------------------------------------------\n";
        cout << "\t\t| 1. Fish Fillet        |          128          |\n";
        cout << "\t\t| 2. Sisig              |          135          |\n";
        cout << "\t\t| 3. Beef Steak         |          120          |\n";
        cout << "\t\t| 4. Adobo              |          85           |\n";
        cout << "\t\t| 5. Liempo             |          135          |\n";
        cout << "\t\t-------------------------------------------------\n\n";
            
        gotoxy(3, 18); cout << "Enter item choice (1-5): ";
        cin >> itemSelect;

    while (itemSelect < 1 || itemSelect > 5) {
    gotoxy(3, 20);
    cout << "Invalid choice! Please enter a number from 1 to 5: ";
   
    
    gotoxy(3, 18); cout << "Enter item choice (1-5): ";
    cin >> itemSelect;
    
    }

    switch(itemSelect) {
    case 1: choice[itemCount] = "Fish Fillet"; price[itemCount] = 128; break;
    case 2: choice[itemCount] = "Sisig";       price[itemCount] = 135; break;
    case 3: choice[itemCount] = "Beef Steak";  price[itemCount] = 120; break;
    case 4: choice[itemCount] = "Adobo";       price[itemCount] = 85;  break;
    case 5: choice[itemCount] = "Liempo";      price[itemCount] = 135; break;
   }

    validSelection = true;
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
            
            gotoxy(3, 18);
            cout << "Enter item choice (1-5): ";
            cin >> itemSelect;

            while (itemSelect < 1 || itemSelect > 5) {
            gotoxy(3, 20);
            cout << "Invalid choice! Please enter a number from 1 to 5: ";

            gotoxy(3, 18);
            cout << "                              ";

            gotoxy(3, 18);
            cout << "Enter item choice (1-5): ";
            cin >> itemSelect;
}

            switch(itemSelect) {
                case 1: choice[itemCount] = "Churros";      price[itemCount] = 100; break;
                case 2: choice[itemCount] = "French Fries"; price[itemCount] = 45;  break;
                case 3: choice[itemCount] = "Spaghetti";    price[itemCount] = 75;  break;
                case 4: choice[itemCount] = "Beef Burger";  price[itemCount] = 32;  break;
                case 5: choice[itemCount] = "Mango Float";  price[itemCount] = 120; break;
            }
            validSelection = true;
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
            
            gotoxy(3, 18);
            cout << "Enter item choice (1-5): ";
            cin >> itemSelect;
 
            while (itemSelect < 1 || itemSelect > 5) {
            gotoxy(3, 20);
            cout << "Invalid choice! Please enter a number from 1 to 5: ";

            gotoxy(3, 18);
            cout << "                              ";

            gotoxy(3, 18);
            cout << "Enter item choice (1-5): ";
            cin >> itemSelect;
}

        switch(itemSelect) {
                case 1: choice[itemCount] = "Mango Shake"; price[itemCount] = 75; break;
                case 2: choice[itemCount] = "Buko Pandan"; price[itemCount] = 50; break;
                case 3: choice[itemCount] = "Iced Tea";    price[itemCount] = 33; break;
                case 4: choice[itemCount] = "Coke";        price[itemCount] = 20; break;
                case 5: choice[itemCount] = "Sprite";      price[itemCount] = 20; break;
            }
             validSelection = true;
        }

        gotoxy(3, 20); cout << "==========================================================================" << endl;
        gotoxy(3, 22); cout << "Customer's Name: " << name << endl << endl;
        gotoxy(3, 24); cout << "\t\t\t\tMunchMate App" << endl;
        gotoxy(3, 25); cout << "\t\t\t\tFoods & Beverages" << endl << endl;

        string catLabel = (categoryChoice == 1) ? "Meal: " : (categoryChoice == 2) ? "Snacks: " : "Beverage: ";
        gotoxy(3, 27); cout << catLabel << choice[itemCount] << endl;

        // Automatically display the price and skip manual input
        if (validSelection) {
            gotoxy(3, 28); cout << "Price: " << price[itemCount] << endl;
           gotoxy(3, 29);
        cout << "Servings: ";
        cin >> servings[itemCount];

    while (servings[itemCount] <= 0) {
    gotoxy(3, 30);
    cout << "Invalid servings! Please enter a number greater than 0: ";
    cin >> servings[itemCount];
}
        } else {
            gotoxy(3, 28); cout << "Price: 0" << endl;
            gotoxy(3, 29); cout << "Servings: 0" << endl;
            servings[itemCount] = 0;
        }

        total_Purchase += (price[itemCount] * servings[itemCount]);
        itemCount++;
        
       gotoxy(3, 31);
       cout << "Add another item from this category? (Y/N): ";
       cin >> moreFromCategory;

  } while ((moreFromCategory == 'Y' || moreFromCategory == 'y') 
         && itemCount < MAX_ITEMS);

    // Ask if the customer wants to order from another category
    if (itemCount >= MAX_ITEMS) {
    gotoxy(3, 33);
    cout << "Maximum order capacity of "
         << MAX_ITEMS
         << " items reached!";
    getch();
}
    else {
    gotoxy(3, 33);
    cout << "Would you like to order from another category? (Y/N): ";
    cin >> moreCategories;
}
    
    // End of the outer menu loop
}   while ((moreCategories == 'Y' || moreCategories == 'y')
         && itemCount < MAX_ITEMS);

    // Screen 4: Order Summary Screen
    clrscr();
    gotoxy(3, 3);cout << "==========================================================================" << endl;
    gotoxy(3, 5);cout << "Customer's Name: " << name << endl << endl;
    gotoxy(3, 7);cout << "\t\t\t\tMunchMate App" << endl;
    gotoxy(3, 8);cout << "\t\t\t\tFoods & Beverages" << endl << endl;

    for (int i = 0; i < itemCount; i++) {
    string summaryLabel = "Item: ";

    if (choice[i] == "Fish Fillet" || choice[i] == "Sisig" ||
        choice[i] == "Beef Steak" || choice[i] == "Adobo" ||
        choice[i] == "Liempo") {
        summaryLabel = "Meal: ";
    }
    else if (choice[i] == "Churros" || choice[i] == "French Fries" ||
             choice[i] == "Spaghetti" || choice[i] == "Beef Burger" ||
             choice[i] == "Mango Float") {
        summaryLabel = "Snacks: ";
    }
    else if (choice[i] == "Mango Shake" || choice[i] == "Buko Pandan" ||
             choice[i] == "Iced Tea" || choice[i] == "Coke" ||
             choice[i] == "Sprite") {
        summaryLabel = "Beverage: ";
    }

    int row = 10 + (i * 4);

    gotoxy(3, row);
    cout << summaryLabel << choice[i];

    gotoxy(3, row + 1);
    cout << "Price: " << price[i];

    gotoxy(3, row + 2);
    cout << "Servings: " << servings[i];
}

    // Payment Processing
    int paymentRow = 10 + (itemCount * 4) + 1;

    gotoxy(3, paymentRow);
    cout << "Total Purchase: " << total_Purchase;

do {
    gotoxy(3, paymentRow + 1);
    cout << "Enter Cash Amount: ";
    cin >> cash;

    if (cash <= 0) {
        gotoxy(3, paymentRow + 2);
        cout << "Invalid amount! Please enter a positive amount.";
    }
    else if (cash < total_Purchase) {
        gotoxy(3, paymentRow + 2);
        cout << "Insufficient Cash! Please try again.";
    }

} while (cash <= 0 || cash < total_Purchase);

change = cash - total_Purchase;
    
    // Screen 5: Final Receipt Screen
    clrscr();
    gotoxy(3, 3); cout << "==========================================================================" << endl;
    gotoxy(3, 5); cout << "\t\t\t\tOrder Receipt\n\n";
    gotoxy(3, 7);cout << "Customer's Name: " << name << endl;
    gotoxy(3, 8); cout << "Reference Number: " << refNumber << endl << endl;
    gotoxy(3, 10);cout << "\t\t\t\tMunchMate\n";
    gotoxy(3, 11);cout << "\t\t\t\tFood & Beverages\n\n";
    gotoxy(3, 13); cout << left << setw(25) << "Food" << setw(15) << "Price" << setw(15) << "Servings" << "Total" << endl;
    gotoxy(3, 14); cout << "--------------------------------------------------------------------------" << endl;
    
    for (int i = 0; i < itemCount; i++) {
    float itemTotal = price[i] * servings[i];

    gotoxy(3, 15 + i);
    cout << left << setw(25) << choice[i]
         << setw(15) << price[i]
         << setw(15) << servings[i]
         << itemTotal;
}

    int receiptRow = 15 + itemCount;

    gotoxy(3, receiptRow);
    cout << "--------------------------------------------------------------------------";

    gotoxy(3, receiptRow + 1);
    cout << left << setw(40) << "Total purchase:" << total_Purchase;

    gotoxy(3, receiptRow + 2);
    cout << left << setw(40) << "Cash:" << cash;

    gotoxy(3, receiptRow + 3);
    cout << "--------------------------------------------------------------------------";

    gotoxy(3, receiptRow + 4);
    cout << left << setw(40) << "Change:" << change;

    gotoxy(3, receiptRow + 5);
    cout << "--------------------------------------------------------------------------";
    
    int messageRow = receiptRow + 7;

    gotoxy(3, messageRow);
    cout << "------ You can claim your order within 24 hours only ------";

    gotoxy(3, messageRow + 1);
    cout << "--------------------- NOTHING FOLLOWS ---------------------";

    gotoxy(3, messageRow + 3);
    cout << "Press enter to exit...";
    getch();

    // Screen 6: Final Thank You Interface Output
    clrscr();
    gotoxy(3, 7); cout << "========== Thank you for using MunchMate Food App! ==========\n\n";
    gotoxy(3, 8); cout << "Present your reference number to the cashier to claim your order.\n";
    gotoxy(3, 9); cout << "The MunchMate service crew will deliver your food to your table or choose Home Delivery :p \n\n";
    gotoxy(3, 10); cout << "==================== Enjoy ka- MunchMate! ====================\n";
    
    return 0;
}