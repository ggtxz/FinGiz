#pragma once

#include <stdexcept>

#include "fingiz/domain/account.hpp"
#include "fingiz/domain/transaction.hpp"

namespace fingiz::services {
class FinanceService {
public:
    bool addTransaction(domain::Account& account, const domain::Transaction& transaction);
};
}  // namespace fingiz::services
