#include "fingiz/services/finance_service.hpp"

namespace fingiz::services {

bool FinanceService::executeIncome(domain::Account& acc, long long amount) {
    return acc.deposit(amount);
}
bool FinanceService::executeExpense(domain::Account& acc, long long amount) {
    // criar transfer e chamar o que registra no banco
    return acc.withdraw(amount);
}

bool FinanceService::executeTransfer(domain::Account& src, domain::Account& dest, long long amount) {
    if (src.withdraw(amount)) {
        if (!dest.deposit(amount)) {
            src.deposit(amount);
            return false;
        }
        return true;
    }
    return false;
}
bool FinanceService::executeLoanGiven(domain::Account& acc, long long amount) {
    return acc.withdraw(amount);
}
bool FinanceService::executeLoanPayment(domain::Account& acc, long long amount) {
    return acc.deposit(amount);
}

}  // namespace fingiz::services

// Income, Expense, Transfer, LoanGiven, LoanPayment
