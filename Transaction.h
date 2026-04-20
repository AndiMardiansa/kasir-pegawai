#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <string>
#include "Cart.h"

class Transaction {
private:
    int transactionId;
    std::string date;
    std::string time;
    double totalAmount;
    double paymentAmount;
    double change;
    std::vector<CartItem> items;

public:
    Transaction(int id, double total, double payment, const std::vector<CartItem>& cartItems)
        : transactionId(id), totalAmount(total), paymentAmount(payment), items(cartItems) {
        change = payment - total;
        setDateTime();
    }

    void setDateTime() {
        time_t now = ::time(0);
        struct tm* timeinfo = localtime(&now);
        
        char dateStr[20];
        strftime(dateStr, sizeof(dateStr), "%d/%m/%Y", timeinfo);
        date = dateStr;

        char timeStr[20];
        strftime(timeStr, sizeof(timeStr), "%H:%M:%S", timeinfo);
        time = timeStr;
    }

    int getTransactionId() const { return transactionId; }
    double getTotalAmount() const { return totalAmount; }
    double getPayment() const { return paymentAmount; }
    double getChange() const { return change; }

    void printReceipt() const {
        std::cout << "\n";
        std::cout << std::string(50, '=') << std::endl;
        std::cout << std::setw(35) << "STRUK PEMBELIAN" << std::endl;
        std::cout << std::string(50, '=') << std::endl;
        
        std::cout << "No. Transaksi: " << transactionId << std::endl;
        std::cout << "Tanggal: " << date << " Jam: " << time << std::endl;
        std::cout << std::string(50, '-') << std::endl;

        std::cout << std::left << std::setw(20) << "Item" 
                  << std::setw(10) << "Qty"
                  << std::setw(20) << "Subtotal" << std::endl;
        std::cout << std::string(50, '-') << std::endl;

        for (const auto& item : items) {
            std::cout << std::left << std::setw(20) << item.product.getName()
                      << std::setw(10) << item.quantity
                      << std::setw(20) << "Rp " + std::to_string((int)item.getSubtotal())
                      << std::endl;
        }

        std::cout << std::string(50, '-') << std::endl;
        std::cout << std::right << std::setw(30) << "Total:" 
                  << std::setw(20) << "Rp " << totalAmount << std::endl;
        std::cout << std::right << std::setw(30) << "Pembayaran:" 
                  << std::setw(20) << "Rp " << paymentAmount << std::endl;
        std::cout << std::right << std::setw(30) << "Kembalian:" 
                  << std::setw(20) << "Rp " << change << std::endl;
        std::cout << std::string(50, '=') << std::endl;
        std::cout << std::setw(35) << "Terima Kasih!" << std::endl;
        std::cout << std::string(50, '=') << std::endl << std::endl;
    }
};

#endif
