// Practice Problem 17: E-Commerce Shopping Cart (Object Composition & Relationships)
// Concepts Tested: Composition ("Has-A" Relationship), Dynamic Array of Object Pointers, Pointer Management.
//
// Description:
// Design an E-Commerce system using object composition where a `ShoppingCart` contains multiple `Product` objects.
//
// Requirements:
// 1. Class 'Product':
//    - Private Members: int productID, std::string name, double price
//    - Constructor: Product(int id, std::string n, double p)
//    - Getters: double getPrice() const, std::string getName() const, int getID() const
//    - void display() const
// 2. Class 'ShoppingCart':
//    - Private Members:
//        * Product* items[10] (Array of Product pointers, max 10 items)
//        * int itemCount
//    - Constructor: ShoppingCart() (Initializes itemCount = 0, pointers to nullptr).
//    - Destructor: ~ShoppingCart() (Does NOT delete external product pointers if passed by reference, or deletes them if owned — clarify ownership strategy).
//    - Public Functions:
//        * bool addProduct(Product* prod): Adds product pointer to items array if itemCount < 10.
//        * bool removeProduct(int productID): Removes product matching ID by shifting array elements.
//        * double calculateTotal() const: Returns sum of prices of all products in cart.
//        * void printInvoice() const: Displays itemized bill with item names, prices, and grand total.
// 3. In main():
//    - Instantiate 3 Product objects (e.g. Laptop $999.99, Mouse $25.50, Keyboard $45.00).
//    - Add them to ShoppingCart.
//    - Display cart invoice and total cost.
//    - Remove one product, re-display cart invoice to verify update.

#include <iostream>
#include <string>

// TODO: Define Product and ShoppingCart classes here

int main() {
    // TODO: Write code testing object composition and shopping cart operations

    return 0;
}
