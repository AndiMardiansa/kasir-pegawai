#ifndef CART_H
#define CART_H

#include "Product.h"
#include <vector>
#include <iostream>
#include <iomanip>

struct CartItem {
    Product product;
    int quantity;

    CartItem(const Product& p, int q) : product(p), quantity(q) {}

    double getSubtotal() const {
        return product.getPrice() * quantity;
    }
};

class Cart {
private:
    std::vector<CartItem> items;

public:
    void addItem(const Product& product, int quantity) {
        for (auto& item : items) {
            if (item.product.getId() == product.getId()) {
                item.quantity += quantity;
                return;
            }
        }
        items.push_back(CartItem(product, quantity));
    }

    void removeItem(int productId) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->product.getId() == productId) {
                items.erase(it);
                return;
            }
        }
    }

    void clear() {
        items.clear();
    }

    double getTotalAmount() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.getSubtotal();
        }
        return total;
    }

    int getItemCount() const {
        return items.size();
    }

    void display() const {
        if (items.empty()) {
            std::cout << "Keranjang masih kosong!\n";
            return;
        }

        std::cout << "\n========== KERANJANG BELANJA ==========\n";
        std::cout << std::left << std::setw(5) << "No" 
                  << std::setw(20) << "Produk"
                  << std::setw(10) << "Harga"
                  << std::setw(8) << "Qty"
                  << std::setw(15) << "Subtotal" << std::endl;
        std::cout << std::string(58, '-') << std::endl;

        int no = 1;
        for (const auto& item : items) {
            std::cout << std::left << std::setw(5) << no++
                      << std::setw(20) << item.product.getName()
                      << std::setw(10) << "Rp " + std::to_string((int)item.product.getPrice())
                      << std::setw(8) << item.quantity
                      << std::setw(15) << "Rp " + std::to_string((int)item.getSubtotal())
                      << std::endl;
        }
        std::cout << std::string(58, '-') << std::endl;
        std::cout << std::right << std::setw(53) << "Total: Rp " << getTotalAmount() << std::endl;
        std::cout << std::string(58, '=') << std::endl;
    }

    std::vector<CartItem>& getItems() {
        return items;
    }
};

#endif
