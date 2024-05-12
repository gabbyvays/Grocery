#include "Grocery.h"
#include <iostream>
#include <iomanip>
using namespace std;

GroceryItem::GroceryItem()
//initializing the member data
{
    price = 0;
    name[0]='\0';

}

void GroceryItem::Set_price(double amount)
{
    price = amount;
}
double GroceryItem::Get_price() const
{
    return price;
}

void GroceryItem::Set_name(const char item[30])
{
    int i;
    for (i = 0; i < 29 && item[i] != '\0'; i++) {
        name[i] = item[i];
    }
    name[i] = '\0';
}

const char* GroceryItem::GetName() const
{
    return name;
}

ostream& operator<<(ostream& os, const GroceryItem& g)
{
        os << "Item name: " << g.name <<fixed << setprecision(2)<<  "\nPrice: $" << g.price << endl;
    return os;
}


