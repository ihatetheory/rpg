#include "stat_well.h"

StatWell::StatWell(welltype value) {
    set(value);
}

StatWell::~StatWell() {}

StatWell::StatWell(welltype current, welltype max) {
    // Setting current and max to max input value
    set(max);
    // Setting current to its input value if it is less than max
    if (current < max) {
        current_ = current;
    }
}

void StatWell::reduceCurrent(welltype value) {
    // If current value is smaller or equal to the input value
    // then set current to zero
    if (current_ <= value) {
        current_ = 0u;
        return;
    }
    // Update current value
    current_ -= value;
}

void StatWell::increaseCurrent(welltype value) {
    // Update current value
    current_ += value;
    // If updated current value is greater than max value
    // then set current to max
    if (current_ > max_) {
        current_ = max_;
    }
}

void StatWell::setCurrent(welltype value) {
    // If the new value is negative set current to zero
    if (value < 0u) {
        current_ = 0u;
        return;
    }
    // Set current value
    current_ = value;
    // If new current value is greater than max value
    // then set current to max
    if (current_ > max_) {
        current_ = max_;
    }
}

const welltype StatWell::getCurrent() const {
    return current_;
}

void StatWell::reduceMax(welltype value) {
    // If max value is smaller or equal to the input value plus one
    // then set max to zero
    if (max_ <= value + 1u) {
        max_ = 1u;
        return;
    }
    max_ -= value;
}

void StatWell::increaseMax(welltype value) {
    max_ += value;
}

void StatWell::setMax(welltype value) {
    // If the new value is less then one set max to one
    if (value < 1u) {
        max_ = 1u;
        return;
    }
    max_ = value;
    // If new max value is smaller than current value
    // then set current to max
    if (max_ < current_) {
        current_ = max_;
    }
};

const welltype StatWell::getMax() const {
    return max_;
}

void StatWell::set(welltype value) {
    // If the new value is less then one set both values to one
    if (value <= 1u) {
        current_ = max_ = 1u;
        return;
    }
    current_ = max_ = value;
};