#ifndef SHOESHOP_STRUCT.H
#define SHOESHOP_STRUCT.H
#include <stdbool.h>

struct ShoeShop_Struct // creating struct
{
    int* shelf;
    int size;
};

struct ShoeShop_Struct; //defining the struct
void ShoeShop_Struct(int size, struct ShoeShop_Struct* shop); // constructor
void ShoeShop_Struct_free(struct ShoeShop_Struct* shop); // deconstructor
void add_items(int row,int num, struct ShoeShop_Struct* shop); //method for add items to the shop
int in_stock(int row, struct ShoeShop_Struct* shop); // method for checking stock in a row
int count_items(struct ShoeShop_Struct* shop); // method for checking number of items in the shop
bool clear(int row, struct ShoeShop_Struct* shop); //mehtod for checking if row is empty and emptying row


#endif