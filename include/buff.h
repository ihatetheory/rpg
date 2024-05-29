#pragma once

#include "data_type.h"
#include "stats.h"

#include <string>

enum class TARGET {NONE, SELF, FRIEND, ENEMY, NUM_TAR};

/**
 * @brief 
 */
class Buff : public Stats {
public:

    /**
     * @brief Default Buff constructor.
     */
    Buff();

    /**
     * @brief Buff destructor.
     */
    ~Buff();

    /**
     * @brief 
     */
    Buff(Stats stats, duratype duration = 0u, TARGET primary = TARGET::SELF, bool harmful = false);

private:
    std::string name_;
    duratype duration_;
    TARGET target_;
    bool harmful_;
};