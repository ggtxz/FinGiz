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
    FinanceService fs;
    bool result = fs.executeIncome(acc, 1000);
    EXPECT_TRUE(result);
    EXPECT_EQ(acc.getBalance(), 1000);
}

TEST(FinanceTest, ShouldAddTransactionExpenseSuccessfully) {
    Account acc(1, "Conta Corrente", WalletType::Bank);
    FinanceService fs;
    fs.executeIncome(acc, 1000);
    bool result = fs.executeExpense(acc, 100);
    EXPECT_TRUE(result);
    EXPECT_EQ(acc.getBalance(), 900);
}

TEST(FinanceTest, ShouldAddTransactionIncomeFail) {
    Account acc(1, "Conta Corrente", WalletType::Bank);
    FinanceService fs;
    bool result = fs.executeIncome(acc, -1000);
    EXPECT_FALSE(result);
    EXPECT_EQ(acc.getBalance(), 0);
}

TEST(FinanceTest, ShouldAddTransactionExpenseFail) {
    Account acc(1, "Conta Corrente", WalletType::Bank);
    FinanceService fs;
    fs.executeIncome(acc, 1000);
    bool result = fs.executeExpense(acc, 10000);
    EXPECT_FALSE(result);
    EXPECT_EQ(acc.getBalance(), 1000);
}
