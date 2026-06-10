#pragma once
#include "fingiz/domain/account.hpp"
#include "fingiz/domain/transaction.hpp"

namespace fingiz::service {
class FinanceService {
public:
    bool executeIncome(domain::Account& acc, long long amount);
    bool executeExpense(domain::Account& acc, long long amount);
    bool executeTransfer(domain::Account& src, domain::Account& dest, long long amount);
    bool executeLoanGiven(domain::Account& acc, long long amount);
    bool executeLoanPayment(domain::Account& acc, long long amount);

private:
    bool registerTransaction(int id, domain::TransactionType type, std::string description, long long amount);
};
}  // namespace fingiz::service
