#include <gtest/gtest.h>

#include "fingiz/service/finance_service.hpp"

using namespace fingiz::domain;
using namespace fingiz::service;

// montar acc e trans
// chamar
// verificar true/false
// verificar saldo

// testar: sucesso de income e expense
// testar: falha de id diferente, income negativo, expense maior que saldo

TEST(FinanceTest, ShouldIncomeSuccessfully) {
    Account acc(1, "Conta Corrente", WalletType::Bank, 0);
    FinanceService fs;
    bool result = fs.executeIncome(acc, 1000);
    EXPECT_TRUE(result);
    EXPECT_EQ(acc.getBalance(), 1000);
}

TEST(FinanceTest, ShouldIncomeFail) {
    Account acc(1, "Conta Corrente", WalletType::Bank, 0);
    FinanceService fs;
    bool result = fs.executeIncome(acc, -1000);
    EXPECT_FALSE(result);
    EXPECT_EQ(acc.getBalance(), 0);
}

TEST(FinanceTest, ShouldExpenseSuccessfully) {
    Account acc(1, "Conta Corrente", WalletType::Bank, 0);
    FinanceService fs;
    fs.executeIncome(acc, 1000);
    bool result = fs.executeExpense(acc, 100);
    EXPECT_TRUE(result);
    EXPECT_EQ(acc.getBalance(), 900);
}

TEST(FinanceTest, ShouldExpenseFail) {
    Account acc(1, "Conta Corrente", WalletType::Bank, 0);
    FinanceService fs;
    fs.executeIncome(acc, 1000);
    bool result = fs.executeExpense(acc, 10000);
    EXPECT_FALSE(result);
    EXPECT_EQ(acc.getBalance(), 1000);
}

TEST(FinanceTest, ShouldTransferSuccessfully) {
    Account src(1, "Conta Corrente", WalletType::Bank, 0);
    Account dest(2, "Binace", WalletType::Bank, 0);
    FinanceService fs;
    fs.executeIncome(src, 1000);
    bool result = fs.executeTransfer(src, dest, 1000);
    EXPECT_TRUE(result);
    EXPECT_EQ(src.getBalance(), 0);
    EXPECT_EQ(dest.getBalance(), 1000);
}

TEST(FinanceTest, ShouldTransferFailedByNegativeValue) {
    Account src(1, "Conta Corrente", WalletType::Bank, 0);
    Account dest(2, "Binace", WalletType::Bank, 0);
    FinanceService fs;
    fs.executeIncome(src, 1000);
    bool result = fs.executeTransfer(src, dest, -1000);
    EXPECT_FALSE(result);
    EXPECT_EQ(src.getBalance(), 1000);
    EXPECT_EQ(dest.getBalance(), 0);
}

TEST(FinanceTest, ShouldTransferFailedByAmount) {
    Account src(1, "Conta Corrente", WalletType::Bank, 0);
    Account dest(2, "Binace", WalletType::Bank, 0);
    FinanceService fs;
    fs.executeIncome(src, 1000);
    bool result = fs.executeTransfer(src, dest, 10000);
    EXPECT_FALSE(result);
    EXPECT_EQ(src.getBalance(), 1000);
    EXPECT_EQ(dest.getBalance(), 0);
}

TEST(FinanceTest, ShouldLoanGivenSuccessfully) {
    Account acc(1, "Conta Corrente", WalletType::Bank, 0);
    FinanceService fs;
    fs.executeIncome(acc, 1000);
    bool result = fs.executeLoanGiven(acc, 1000);
    EXPECT_TRUE(result);
    EXPECT_EQ(acc.getBalance(), 0);
}

TEST(FinanceTest, ShouldLoanGivenFailByNegativeNumber) {
    Account acc(1, "Conta Corrente", WalletType::Bank, 0);
    FinanceService fs;
    fs.executeIncome(acc, 1000);
    bool result = fs.executeLoanGiven(acc, -1000);
    EXPECT_FALSE(result);
    EXPECT_EQ(acc.getBalance(), 1000);
}

TEST(FinanceTest, ShouldLoanGivenFailByAmount) {
    Account acc(1, "Conta Corrente", WalletType::Bank, 0);
    FinanceService fs;
    fs.executeIncome(acc, 1000);
    bool result = fs.executeLoanGiven(acc, 10000);
    EXPECT_FALSE(result);
    EXPECT_EQ(acc.getBalance(), 1000);
}

TEST(FinanceTest, ShouldLoanPaymentSuccessfully) {
    Account acc(1, "Conta Corrente", WalletType::Bank, 0);
    FinanceService fs;
    bool result = fs.executeLoanPayment(acc, 1000);
    EXPECT_TRUE(result);
    EXPECT_EQ(acc.getBalance(), 1000);
}

TEST(FinanceTest, ShouldLoanPaymentFailByNegativeNumber) {
    Account acc(1, "Conta Corrente", WalletType::Bank, 0);
    FinanceService fs;
    bool result = fs.executeLoanPayment(acc, -1000);
    EXPECT_FALSE(result);
    EXPECT_EQ(acc.getBalance(), 0);
}
