#pragma once

namespace fingiz::domain {

enum class TransactionType { Income, Expense, Transfer, LoanGiven, LoanPayment };
enum class Category { Food, Transport, Entertainment, Salary, Health, Housing, Education, Subscription };
enum class WalletType { Cash, Bank, CreditCard, FoodVoucher };
}  // namespace fingiz::domain
