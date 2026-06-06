#include "fingiz/services/finance_service.hpp"

namespace fingiz::services {
bool FinanceService::addTransaction(domain::Account& account, const domain::Transaction& transaction) {
    if (account.getId() != transaction.getAccount()) {
        throw std::invalid_argument("A transação não pertence a conta");
    }
    switch (transaction.getType()) {
        case fingiz::domain::TransactionType::Income:
            return account.deposit(transaction.getAmount());
        case fingiz::domain::TransactionType::Expense:
            return account.withdraw(transaction.getAmount());
        case fingiz::domain::TransactionType::Transfer:
            return false;
        case fingiz::domain::TransactionType::LoanGiven:
            return false;
        case fingiz::domain::TransactionType::LoanPayment:
            return false;
        default:
            return false;
    }
};
}  // namespace fingiz::services

// Income, Expense, Transfer, LoanGiven, LoanPayment
