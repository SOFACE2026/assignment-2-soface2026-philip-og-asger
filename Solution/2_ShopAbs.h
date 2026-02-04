#ifndef SHOPABS_H
#define SHOPABS_H

#include <stdbool.h>

// creating the abstract struct for a shop
typedef struct Shop Shop;
struct Shop {
    // creating the function pointers for the shop
    void (*add_items)(void* self, int row, int num);
    int  (*in_stock)(void* self, int row);
    int  (*count_items)(void* self);
    bool (*clear)(void* self, int row);
};

//creating the struct for a shoeshop, which has the same fuction pointers as the abstract struct shop
typedef struct {
    // matches the order of the shop above
    void (*add_items)(void* self, int row, int num);
    int  (*in_stock)(void* self, int row);
    int  (*count_items)(void* self);
    bool (*clear)(void* self, int row);
    // The variables only avaible for a shoe shop
    int* shelf;
    int size;
} ShoeShop;

// Constructor and Destructor
ShoeShop* ShoeShop_create(int size);
void ShoeShop_destroy(ShoeShop* shop);

#endif