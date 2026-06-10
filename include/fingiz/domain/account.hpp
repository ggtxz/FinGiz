#pragma once

#include <string>

#include "fingiz/domain/types.hpp"

namespace fingiz::domain {

class Account {
public:
    Account(int id, std::string name, WalletType type, long long balance)
        : id(id), name(std::move(name)), type(type), balance(balance) {};
    int getId() const { return id; };
    std::string getName() const { return name; };
    WalletType getType() const { return type; };
    long long getBalance() const { return balance; };
    bool deposit(long long amount);
    bool withdraw(long long amount);

private:
    int id;
    std::string name;
    WalletType type;
    long long balance;  // cents
};

};  // namespace fingiz::domain
