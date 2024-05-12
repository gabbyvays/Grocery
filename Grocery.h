//--------------- Grocery.h ---------------
//Gabrielle Vays

#include <iostream>
#include <iomanip>
using namespace std;


class GroceryItem
{
public:
    GroceryItem();//constructor
    void Set_price(double amount);//set the price
    double Get_price() const;//get the amount of money the grocery item costs
    void Set_name(const char item[30]);//Set the grocery item
    const char* GetName() const;
    friend ostream& operator<<(ostream& os, const GroceryItem& g);

private:
    double price;
    char name[30];

};