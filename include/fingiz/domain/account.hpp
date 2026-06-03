#include <string>

namespace fingiz::domain {

enum class WalletType { cash, bank, credit_card, food_voucher };

class Account {
public:
    Account(int id, std::string name, WalletType type) : id(id), name(std::move(name)), type(type), balance(0) {}

private:
    int id;
    std::string name;
    WalletType type;
    long long balance;
};

};  // namespace fingiz::domain
