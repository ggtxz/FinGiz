#include <gtest/gtest.h>

#include "fingiz/services/finance_service.hpp"

using namespace fingiz::domain;
using namespace fingiz::services;

// montar acc e trans
// chamar add
// verificar true/false
// verificar saldo

// testar: sucesso de income e expense
// testar: falha de id diferente, income negativo, expense maior que saldo

TEST(FinanceTest, ShouldAddTransactionIncomeSuccessfully) {
    Account acc(1, "Conta Corrente", WalletType::Bank);
    Transaction trn(1, TransactionType::Income, "Teste", 1000, std::chrono::system_clock::now(), Category::Salary, 1);
    FinanceService fs;
    bool result = fs.addTransaction(acc, trn);
    EXPECT_TRUE(result);
    EXPECT_EQ(acc.getBalance(), 1000);
}

TEST(FinanceTest, ShouldAddTransactionExpenseSuccessfully) {
    Account acc(1, "Conta Corrente", WalletType::Bank);
    Transaction trnIncome(1, TransactionType::Income, "Teste", 1000, std::chrono::system_clock::now(), Category::Salary,
                          1);
    Transaction trnExpense(2, TransactionType::Expense, "Teste", 100, std::chrono::system_clock::now(),
                           Category::Salary, 1);
    FinanceService fs;
    fs.addTransaction(acc, trnIncome);
    bool result = fs.addTransaction(acc, trnExpense);
    EXPECT_TRUE(result);
    EXPECT_EQ(acc.getBalance(), 900);
}

TEST(FinanceTest, ShouldAddTransactionIdFail) {
    Account acc(1, "Conta Corrente", WalletType::Bank);
    Transaction trn(1, TransactionType::Income, "Teste", 1000, std::chrono::system_clock::now(), Category::Salary, 2);
    FinanceService fs;
    EXPECT_THROW(fs.addTransaction(acc, trn), std::invalid_argument);
}

TEST(FinanceTest, ShouldAddTransactionIncomeFail) {
    Account acc(1, "Conta Corrente", WalletType::Bank);
    Transaction trn(1, TransactionType::Income, "Teste", -1000, std::chrono::system_clock::now(), Category::Salary, 1);
    FinanceService fs;
    bool result = fs.addTransaction(acc, trn);
    EXPECT_FALSE(result);
    EXPECT_EQ(acc.getBalance(), 0);
}

TEST(FinanceTest, ShouldAddTransactionExpenseFail) {
    Account acc(1, "Conta Corrente", WalletType::Bank);
    Transaction trnIncome(1, TransactionType::Income, "Teste", 1000, std::chrono::system_clock::now(), Category::Salary,
                          1);
    Transaction trnExpense(2, TransactionType::Expense, "Teste", 10000, std::chrono::system_clock::now(),
                           Category::Salary, 1);
    FinanceService fs;
    fs.addTransaction(acc, trnIncome);
    bool result = fs.addTransaction(acc, trnExpense);
    EXPECT_FALSE(result);
    EXPECT_EQ(acc.getBalance(), 1000);
}
