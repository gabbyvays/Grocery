//--------------- menu.cpp ---------------
//Gabrielle Vays

#include <iostream>
#include "Grocery.h"

using namespace std;
void ShowMenu()
{
    cout << "\tWelcome to the Grocery Store!";
    cout << "\n\tA \tAdd an item to inventory ";
    cout << "\n\tR \tRemove an item";
    cout << "\n\tL \tList the items in the Grocery Store ";
    cout << "\n\tM \tShow this Menu";
    cout << "\n\tC \tCheck out ";
}

char GetAChar(const char* prompt)
// Prompt the user and get a single character,
// discarding the Return character.
// Used in GetCommand.
{
    char option;			// the char to be returned

    cout << prompt;		// Prompt the user
    cin >> option;			// Get a char,
    option = toupper(option);	// and convert it to uppercase
    cin.get();				// Discard newline char from input.
    return option;
}

bool Legal(char s)
// Determine if a particular character, c, corresponds
// to a legal menu command.  Returns true if legal, false if not.
// Used in GetCommand.
{
    return	((s == 'A') || (s == 'R') || (s == 'L') || (s == 'M') ||
               (s == 'C'));
}

char GetCommand()
// Prompts the user for a menu command until a legal
// command character is entered.  Return the command character.
// Calls GetAChar, Legal, ShowMenu.
{
    char cmd = GetAChar("\n\n>");	// Get a command character.

    while (!Legal(cmd))		// As long as it's not a legal command,
    {				// display menu and try again.
        cout << "\nIllegal command, please try again . . .";
        ShowMenu();
        cmd = GetAChar("\n\n>");
    }
    return cmd;
}

int main()
{
    int current_item = 0;//number of items
    int max_items = 3;//max number of items
    GroceryItem* groceryList = new GroceryItem[max_items];
    int itemIndex = -1;
    char namex[30];
    double pricex = -1;

    ShowMenu();				// Display the menu.
    char command;			// menu command entered by user
    do {
        command = GetCommand();		// Retrieve a command.
        switch (command)
        {
            case 'A':
                if(current_item == max_items)
                {
                    max_items = current_item + 3;			// Determine a new size.
                    GroceryItem* new_grocerylist = new GroceryItem[max_items];		// Allocate a new array.
                    cout << "Array being resized to " << max_items << " allocated spots"<<endl;
                    for (int i = 0; i < current_item; i++)	// Copy each entry into
                    {
                        new_grocerylist[i] = groceryList[i];        // the new array.
                    }
                    delete [] groceryList;			// Remove the old array
                    groceryList = new_grocerylist;			// Point old name to new array.
                }

                cout << "\nType the name of the name of the item, followed by RETURN or ENTER: ";
                cin.getline(namex, 30);

                cout << "\nType the price, followed by RETURN or ENTER: ";
                cin >> pricex;

                groceryList[current_item].Set_name(namex);
                groceryList[current_item].Set_price(pricex);

                current_item++;

                break;
            case 'R':
                cout << "\tType the item to be looked up, followed by <Enter>: ";
                cin.getline(namex,30);


                for (int i = 0; i < current_item; i++) {    // Look at each entry.
                    if (strcmp(groceryList[i].GetName(), namex) == 0) {
                        itemIndex = i;        // If found, return position and exit.
                        //break;
                    }
                }
                if (itemIndex != -1){
                    groceryList[itemIndex] = groceryList[current_item - 1];
                    current_item--;
                    cout << "Item removed from inventory. " <<endl;
                }else{
                    cout << "Item not found in inventory. " <<endl;
                }
                break;
            case 'L':
                if (current_item > 0 )
                {
                    for(int i = 0; i < current_item; i++)
                    {
                        cout << groceryList[i] << endl;
                    }
                }else {
                    cout << "Inventory is empty."<<endl;
                }
                break;
            case 'M':
                ShowMenu();
                break;
            case 'C':
                double subtotal = 0;
                for(int i = 0; i < current_item; i++)
                {
                    cout << "Item " << (i + 1 ) << ": " << groceryList[i].GetName() << " \nPrice: $" << groceryList[i].Get_price() << endl;
                    subtotal += groceryList[i].Get_price();
                }

                double salesTaxRate = 0.07;
                double total = subtotal + (subtotal * salesTaxRate);

                cout << "Subtotal: $" << subtotal <<endl;
                cout << "Total plus 7% sales tax: $" <<total;
                break;
        }
    }while (command != 'C');
    return 0;
}