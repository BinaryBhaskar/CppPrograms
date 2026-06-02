// Write a program for an inventory of product in store using appropriate data type conversion functions.

#include <iostream>
#include <string>

class Product {
private:
    std::string name;
    int quantity;
public:
    Product(std::string n = "", int q = 0) : name(n), quantity(q) {}
    operator std::string() const {
        return name; // Convert Product object to string (product name)
    }
    operator int() const {
        return quantity; // Convert Product object to integer (quantity)
    }
    Product operator=(const std::string& newName) {
        name = newName; // Assign new name to the product
        return *this; // Return the current object
    }
    Product operator=(int newQuantity) {
        quantity = newQuantity; // Assign new quantity to the product
        return *this; // Return the current object
    }
    void display() const {
        std::cout << "Product Name: " << name << ", Quantity: " << quantity << std::endl;
    }
};

int main() {
    Product product1("Laptop", 10); // Create a product with name "Laptop" and quantity 10
    std::cout << "Product 1: ";
    product1.display();

    std::string productName = product1; // Convert Product object to string (product name)
    int productQuantity = product1; // Convert Product object to integer (quantity)

    std::cout << "Product Name: " << productName << std::endl;
    std::cout << "Product Quantity: " << productQuantity << std::endl;

    Product product2;
    product2 = "Smartphone"; // Assign new name to the product using overloaded assignment operator
    product2 = 20; // Assign new quantity to the product using overloaded assignment operator

    std::cout << "Product 2: ";
    product2.display();

    return 0;
}
