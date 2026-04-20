#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
private:
    int id;
    std::string name;
    double price;
    int stock;

public:
    Product(int id, const std::string& name, double price, int stock)
        : id(id), name(name), price(price), stock(stock) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }

    void setStock(int newStock) { stock = newStock; }
    void decreaseStock(int quantity) { stock -= quantity; }
    void increaseStock(int quantity) { stock += quantity; }

    void display() const {
        std::cout << "ID: " << id << " | Nama: " << name 
                  << " | Harga: Rp " << price << " | Stok: " << stock << std::endl;
    }
};

#endif
