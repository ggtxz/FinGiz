#pragma once
#include "fingiz/domain/account.hpp"
#include "fingiz/domain/transaction.hpp"

namespace fingiz::services {
class FinanceService {
public:
    bool executeIncome(domain::Account& acc, long long amount);
    bool executeExpense(domain::Account& acc, long long amount);
    // bool executeTransfer(domain::Account& src, domain::Account& dest, long long amount);
    // bool executeLoanGiven(domain::Account& acc, long long amount);
    // bool executeLoanPayment(domain::Account& acc, long long amount);
};
}  // namespace fingiz::services
