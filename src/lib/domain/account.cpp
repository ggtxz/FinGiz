#include "fingiz/domain/account.hpp"

namespace fingiz::domain {

bool Account::deposit(long long amount) {
    if (amount < 0) {
        return false;  // Cannot deposit a negative amount
    }
    balance += amount;
    return true;
}

bool Account::withdraw(long long amount) {
    if (amount < 0) {
        return false;  // Cannot withdraw a negative amount
    }
    if (amount > balance) {
        return false;  // Cannot withdraw more than the current balance
    }
    balance -= amount;
    return true;
}
}  // namespace fingiz::domain
