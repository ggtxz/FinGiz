#include <gtest/gtest.h>

#include "fingiz/domain/account.hpp"
#include "fingiz/domain/types.hpp"

using namespace fingiz::domain;

TEST(AccountTest, ShouldDepositSuccessfully) {
    Account acc(1, "Conta Corrente", WalletType::Bank, 0);
    bool result = acc.deposit(10000);
    EXPECT_TRUE(result);
    EXPECT_EQ(acc.getBalance(), 10000);
}

TEST(AccountTest, ShouldDepositFailed) {
    Account acc(1, "Conta Corrente", WalletType::Bank, 0);
    bool result = acc.deposit(-10000);
    EXPECT_FALSE(result);
    EXPECT_EQ(acc.getBalance(), 0);
}

TEST(AccountTest, ShouldWithDrawSuccessfully) {
    Account acc(1, "Conta Corrente", WalletType::Bank, 0);
    acc.deposit(10000);
    bool result = acc.withdraw(10000);
    EXPECT_TRUE(result);
    EXPECT_EQ(acc.getBalance(), 0);
}

TEST(AccountTest, ShouldWithdrawFailed) {
    Account acc(1, "Conta Corrente", WalletType::Bank, 0);
    bool result = acc.withdraw(-10000);
    EXPECT_FALSE(result);
    EXPECT_EQ(acc.getBalance(), 0);
}

TEST(AccountTest, ShouldWithdrawFailedByInsuficientBalance) {
    Account acc(1, "Conta Corrente", WalletType::Bank, 0);
    acc.deposit(5000);
    bool result = acc.withdraw(10000);
    EXPECT_FALSE(result);
    EXPECT_EQ(acc.getBalance(), 5000);
}
