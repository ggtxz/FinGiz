#pragma once

#include <chrono>
#include <string>

#include "fingiz/domain/types.hpp"

namespace fingiz::domain {

struct TransactionData {
    std::string description;
    Category category;
};

class Transaction {
public:
    Transaction(int id, TransactionType type, TransactionData data, long long amount, int accountId)
        : id(id),
          type(type),
          description(std::move(data.description)),
          amount(amount),
          date(std::chrono::system_clock::now()),
          accountId(accountId) {};
    int getId() const { return id; };
    TransactionType getType() const { return type; };
    std::string getDescription() const { return description; };
    long long getAmount() const { return amount; };
    std::chrono::system_clock::time_point getDate() const { return date; };
    Category getCategory() const { return category; };
    int getAccount() const { return accountId; };

private:
    int id;
    TransactionType type;
    std::string description;
    long long amount;
    std::chrono::system_clock::time_point date;
    Category category;
    int accountId;
};

};  // namespace fingiz::domain
