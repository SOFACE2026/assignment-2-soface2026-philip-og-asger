#include "ShoeShop_Struct.h"
#include <stdbool.h>

void ShoeShop_Struct(int size, struct ShoeShop_Struct* shop){ // cunstructor
    shop->shelf = (int*)calloc(size, sizeof(int)); // making shelf array of size size and setting everythin to 0 
    shop->size = size; // making size size
}

void ShoeShop_Struct_free(struct ShoeShop_Struct* shop){ // decinstructor 
    free(shop);
}

void add_items(int row, int num, struct ShoeShop_Struct* shop){ // adding number of shoes to a row int he shop
    shop->shelf[row] += num;
}

int in_stock(int row, struct ShoeShop_Struct* shop){ // returning the number of shoes on a shelf, returning 0 if shelf has 0 or less shoes
    return shop->shelf[row]>0;
}

int count_items(struct ShoeShop_Struct* shop){ // counting number of shoes in the shop
    int sum = 0; //variable for the sum of shoes
    for(int i=0; i<shop->size; i++){ // loop adding number of shoes in each row to the sum
        sum += shop->shelf[i];
    }
    return sum;
}

bool clear(int row, struct ShoeShop_Struct* shop){ //checking if a row is empty and making the row empty and returning if its empty
    bool rem = shop->shelf[row]>0; // making variable checking if row is empty 
    shop->shelf[row]=0; // making row equal to 0
    return rem;
}
