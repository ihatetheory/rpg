#pragma once

#include "data_type.h"

#include <array>

/**
 * @brief Stat class to handle charachter stats. Particularyl setter, increase and decrease as they should work around non-negative values.
 * @tparam T 
 */
template <typename T>
class Stat {
public:

    /**
     * @brief Default Stat constructor.
     */
    Stat() : value_(0u) {}

    /**
     * @brief Default Stat destructor.
     */
    ~Stat() {}

    /**
     * @brief Stat constructor setting its value to the input parameter.
     * 
     * @param value with which stat value will be initialized.
     */
    Stat(T value) { set(value); }

    /**
     * @brief Reduce stat by value.
     * 
     * @param value by which to reduce stat.
     */
    void reduce(T value) {
        // If stat value is smaller or equal to the input value
        // then set stat to zero
        if (value_ <= value) {
            value_ = 0u;
            return;
        }
        // Update stat value
        value_ -= value;
    }

    /**
     * @brief Increase stat by value.
     * 
     * @param value by which to increase stat.
     */
    void increase(T value) {
        // Update stat value
        value_ += value;
    }

    /**
     * @brief Setter.
     * 
     * @param value to set the stat value with.
     */
    void set(T value) {
        // If the input is negative set stat to zero
        if (value < 0u) {
            value_ = 0u;
            return;
        }
        // Set stat value
        value_ = value;
    }

    /**
     * @brief Getter.
     * 
     * @return Stat value.
     */
    const T get() const {
        return value_;
    }

private:
    T value_;
};

class BaseStats {
public:

    /**
     * @brief Default BaseStats constructor.
     */
    BaseStats()
     : stamina_(), strength_(), intelect_(), armor_(), resistance_() {}

    /**
     * @brief Default BaseStats destructor.
     */
    ~BaseStats() {}

    /**
     * @brief BaseStats constructor setting base stat values to the input parameter.
     */
    BaseStats(stattype value) {
        stamina_ = strength_ = intelect_ = value;
        armor_ = 0u;
        resistance_ = {0u, 0u, 0u, 0u};
    }

    /**
     * @brief BaseStats constructor setting base stat values to their corresponding input parameters.
     */
    BaseStats(stattype stamina, stattype strength, stattype intelect, stattype armor = 0u, stattype resistance = 0u)
     : stamina_(stamina), strength_(strength), intelect_(intelect),
       armor_(armor), resistance_{resistance, resistance, resistance, resistance} {}

private:
    Stat<stattype> stamina_;
    Stat<stattype> strength_;
    Stat<stattype> intelect_;

    Stat<stattype> armor_;
    // 0 - Fire
    // 1 - Water
    // 2 - Air
    // 3 - Earth
    std::array<Stat<stattype>, 4> resistance_;
};