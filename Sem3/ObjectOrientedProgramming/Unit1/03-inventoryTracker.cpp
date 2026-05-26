// Problem 1: The Inventory Tracker
// Concepts Tested: Static Data Members, Static Member Functions, Scope Resolution Operator, Object Assignment.
// Create a class named Product.
// Private Members: int productID, double price.
// Static Member: A private static integer totalProducts to track the total number of products currently alive in memory.
// Requirements:
// Write a constructor that takes an ID and a price, and increments totalProducts.
// Write a destructor (~Product()) that decrements totalProducts when an object goes out of scope.
// Write a static member function showTotal() using the scope resolution operator outside the class to print the current total count.
// In main(), create three products. Call showTotal(). Then, create a 4th product inside a nested block { } and show how the count changes inside and outside that block.
// Demonstrate object assignment by assigning your first product to your second product (p2 = p1;). Print p2's values to verify they copied successfully.

#include <iostream>

class Product {
    int productID;
    double price;

public:
    static int totalProducts;

    Product(int i, double p): productID(i), price(p) {
        totalProducts++;
    }

    ~Product() {
        totalProducts--;
    }

    static void showTotal();

    void stats() {
        std::cout << "ProductID: " << productID << ", Price: " << price << std::endl;
    }
};

int Product::totalProducts = 0;

void Product::showTotal() {
    std::cout << Product::totalProducts << std::endl;
}

int main() {
    Product p1(1, 10.0);
    Product p2(2, 20.0);
    Product p3(3, 5.0);

    Product::showTotal();

    {
        Product p4(4, 50.0);
        Product::showTotal();
    }
    Product::showTotal();

    p1.stats();
    p2.stats();

    p2 = p1;

    p1.stats();
    p2.stats();

    return 0;
}