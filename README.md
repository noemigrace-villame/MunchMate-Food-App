# 🍔🧋🥓 MunchMate Food App (C++ Console POS System)📲🖨

A terminal-based Point-of-Sale (POS) restaurant ordering application developed as a final project for the **Computer Programming Fundamentals** course at **National University Manila**. 

*Note: Due to a hardware migration, the complete `.cpp` source files were cleared, but one of the revisions during the process of editing is still save- the architecture, interface design, and compilation outputs. It's documented below as proof of functional logic. Hope to recover my files soon*

## 🚀 Technical Features & Programming Concepts Applied
- **Dynamic Transaction Identifiers:** Implemented a unique random reference number generator algorithm for each purchase transaction. Every successful order automatically generates an tracking code, simulating a real-world restaurant order pickup workflow.
- **Custom UI Rendering:** Applied `gotoxy()` coordinate mapping and `clrscr()` buffer clearing in Dev-C++ to build a structured, screen-by-screen terminal interface instead of a standard scrolling text line.
- **Data Collections:** Handled user order paths using multiple parallel array models:
  - `string choice` for tracking active menu selections.
  - `float price` for storing numeric pricing points.
  - `int servings` for recording targeted item quantities.
- **Robust Input Validation:** Implemented structural error boundaries (e.g., catching out-of-range pricing inputs with loop resets to ensure safe system execution).
- **Transactional Calculations:** Created backend logic for computational operations (`Total Purchase`, `Cash Tendered`, and `Change Due`).

---

## 📸 System Workflow & Execution Output

### 1. Welcome & Onboarding Screen
A clean layout prompting the user for terminal initiation and customer mapping.
![Welcome Screen](welcome.png)

### 2. Main Menu Selection & Dynamic Categories
The interface switches between main categories (Meals, Snacks, Beverages) utilizing dynamic user input selection.
![Menu Categorization](menu.png)

### 3. Error Handling & Input Validation Range
Demonstrating runtime exception tracking when data entry falls outside allowed boundaries.
![Input Validation](validation.png)

### 4. Automated Financial Receipt Output
Generates a structured final breakdown showing distinct line items, total calculations, and precise cashier change outputs.
![Receipt Generator](receipt.png)

---

## 🛠️ Code Snippet Architecture (Variable Declarations)
As shown in my IDE architecture captures, the structural memory spaces were declared using clean typing workflows:

```cpp
// Variable Mapping Used in Dev-C++ Workspace
string name;               // Customer mapping identity
string choice;             // Active food array variables
float price;               // Price array matrices
int servings;              // Active serving volumes
float totalPurchase;       // Aggregate total variable
char options;              // Navigation option variables
int tryAgain;              // Re-try validation control tracking
```
