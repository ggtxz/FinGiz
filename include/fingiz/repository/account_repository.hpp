#pragma once

#include <optional>
#include <vector>

#include "fingiz/domain/account.hpp"

namespace fingiz::repository {
class AccountRepository {
public:
    virtual ~AccountRepository() = default;
    virtual void save(const domain::Account& account) = 0;
    virtual std::optional<domain::Account> findById(int id) const = 0;
    virtual std::vector<domain::Account> findAll() const = 0;
    virtual void update(const domain::Account& account) = 0;
    virtual void remove(int id) = 0;
};
}  // namespace fingiz::repository
