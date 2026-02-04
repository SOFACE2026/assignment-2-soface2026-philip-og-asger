#include <stdio.h>
#include <stdlib.h>
#include "2_ShopAbs.h"

// implementation of the functions from the abstract struct shop



void ShoeShop_add_items(void* self, int row, int num) { // adds items for to the shop
    ShoeShop* shop = (ShoeShop*)self; // casting the void pointer to a ShoeShop pointer
    if (row < shop->size) { // checks if the row is in the shelf array
        shop->shelf[row] += num;
    }
}

int ShoeShop_in_stock(void* self, int row) { // cheks if there is a somthing in the row and returns number of items the row
    ShoeShop* shop = (ShoeShop*)self;
    if (row < shop->size) {// checks if the row is in the shelf array
        return shop->shelf[row] > 0;
    }
    return 0;
}

int ShoeShop_count_items(void* self) { // counts items in the shop and returns number of items
    ShoeShop* shop = (ShoeShop*)self;
    int tot = 0; // variable for keeping track of items
    for (int k = 0; k < shop->size; k++) { // loop that adds number of items in each row
        tot += shop->shelf[k];
    }
    return tot;
}

bool ShoeShop_clear(void* self, int row) {// clears a row in the shop and return if something was removed
    ShoeShop* shop = (ShoeShop*)self;
    if (row >= shop->size) return false;
    bool rem = shop->shelf[row] > 0;
    shop->shelf[row] = 0;
    return rem;
}

// Constructor
ShoeShop* ShoeShop_create(int size) {
    ShoeShop* shop = (ShoeShop*)malloc(sizeof(ShoeShop));
    
    if (shop != NULL) {
        // initializing data
        shop->size = size;
        shop->shelf = (int*)calloc(size, sizeof(int));
        // initializing function pointers. This tells the struct which functions to use
        shop->add_items = ShoeShop_add_items;
        shop->in_stock  = ShoeShop_in_stock;
        shop->count_items = ShoeShop_count_items;
        shop->clear     = ShoeShop_clear;
    }
    
    return shop;
}

//The destroying Destructor 
void ShoeShop_destroy(ShoeShop* shop) {
    if (shop != NULL) {
        free(shop->shelf);
        free(shop);
    }
}