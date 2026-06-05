#include <string>

namespace fingiz::domain {

enum class WalletType { Cash, Bank, CreditCard, FoodVoucher };

class Account {
public:
    Account(int id, std::string name, WalletType type) : id(id), name(std::move(name)), type(type), balance(0) {}
    std::string getName() const { return name; }
    WalletType getType() const { return type; }
    long long getBalance() const { return balance; }
    bool deposit(long long amount);
    bool withdraw(long long amount);

private:
    int id;
    std::string name;
    WalletType type;
    long long balance;  // cents
};

};  // namespace fingiz::domain
