#pragma once

#include "data_type.h"

/**
 * @brief StatWell class to handle charachter stats that follow well-pattern, i.e have current, maximum and never go negative.
 */
class StatWell {
public:

    /**
     * @brief Default StatWell constructor setting both current and max to the input parameter.
     * 
     * @param value with which both current and max will be initialized. Has a default value of '1u'.
     */
    StatWell(welltype value = 1u);

    /**
     * @brief StatWell destructor.
     */
    ~StatWell();

    /**
     * @brief StatWell constructor setting both current and max to corresponding input parameter.
     * 
     * @param current value with which current will be initialized.
     * @param max value with which max will be initialized.
     */
    StatWell(welltype current, welltype max);

    /**
     * @brief Reduce current by value.
     * 
     * @param value by which to reduce current.
     */
    void reduceCurrent(welltype value);

    /**
     * @brief Increase current by value.
     * 
     * @param value by which to increase current.
     */
    void increaseCurrent(welltype value);

    /**
     * @brief Setter for current value.
     * 
     * @param value to set the current value with.
     */
    void setCurrent(welltype value);

    /**
     * @brief Getter for current value.
     * 
     * @return Current value.
     */
    const welltype getCurrent() const;

    /**
     * @brief Reduce max by value.
     * 
     * @param value by which to reduce max.
     */
    void reduceMax(welltype value);

    /**
     * @brief Increase max by value.
     * 
     * @param value by which to increase max.
     */
    void increaseMax(welltype value);

    /**
     * @brief Setter for max value.
     * 
     * @param value to set the max value with.
     */
    void setMax(welltype value);

    /**
     * @brief Getter for max value.
     * 
     * @return Max value.
     */
    const welltype getMax() const;

    /**
     * @brief Setter for both current and max value.
     * 
     * @param value used to set both current and max.
     */
    void set(welltype value);

private:
    welltype current_;
    welltype max_;
};