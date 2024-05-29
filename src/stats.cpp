#include "stats.h"

template <class T>
StatBlock<T>::~StatBlock() {}

template <class T>
StatBlock<T>::StatBlock(T vtsize, stattype value) {
    size = static_cast<unsigned short>(vtsize);
    statblock.reserve(size);
    for (auto i(0); i < size; ++i) {
        statblock.push_back(value);
    }
}

template <class T>
StatBlock<T>& StatBlock<T>::operator+=(const StatBlock<T>& rhs) {
    if (rhs.size == this->size) {
        for (auto i(0); i < this->size; ++i) {
            this->statblock[i] += rhs.statblock[i];
        }
    }
    return *this;
}

template <class T>
StatBlock<T>& StatBlock<T>::operator-=(const StatBlock<T>& rhs) {
    if (rhs.size == this->size) {
        for (auto i(0); i < this->size; ++i) {
            this->statblock[i] -= rhs.statblock[i];
        }
    }
    return *this;
}

template <class T>
StatBlock<T>& StatBlock<T>::operator=(const StatBlock<T>& rhs) {
    if (rhs.size == this->size) {
        for (auto i(0); i < this->size; ++i) {
            this->statblock[i] = rhs.statblock[i];
        }
    }
    return *this;
}

Stats::Stats(stattype value)
 : corestats_(CORESTATS::NUM_STATS, value),
   armorstats_(ARMORSTATS::NUM_STATS, value),
   resistancestats_(RESISTATS::NUM_STATS, value) {}

Stats::~Stats() {}

Stats::Stats(stattype core, stattype armor, stattype resi)
: corestats_(CORESTATS::NUM_STATS, core),
  armorstats_(ARMORSTATS::NUM_STATS, armor),
  resistancestats_(RESISTATS::NUM_STATS, resi) {}

void Stats::setCoreStats(stattype value) {
    for (auto &stat: corestats_.statblock) {
        stat = value;
    }
}

void Stats::setCoreStats(const std::vector<stattype> values) {
    if (values.size() != corestats_.size) {
        return;
    }
    for (auto i(0); i < corestats_.size; ++i) {
        corestats_.statblock[i] = values[i];
    }
}

const std::vector<stattype> Stats::getCoreStats() const {
    return corestats_.statblock;
}

void Stats::setArmorStats(stattype value) {
    for (auto &stat: armorstats_.statblock) {
        stat = value;
    }
}

void Stats::setArmorStats(const std::vector<stattype> values) {
    if (values.size() != armorstats_.size) {
        return;
    }
    for (auto i(0); i < armorstats_.size; ++i) {
        armorstats_.statblock[i] = values[i];
    }
}

const std::vector<stattype> Stats::getArmorStats() const {
    return armorstats_.statblock;
}

void Stats::setResistanceStats(stattype value) {
    for (auto &stat: resistancestats_.statblock) {
        stat = value;
    }
}

void Stats::setResistanceStats(const std::vector<stattype> values) {
    if (values.size() != resistancestats_.size) {
        return;
    }
    for (auto i(0); i < resistancestats_.size; ++i) {
        resistancestats_.statblock[i] = values[i];
    }
}

const std::vector<stattype> Stats::getResistanceStats() const {
    return resistancestats_.statblock;
}

void Stats::setStat(CORESTATS stat, stattype value) {
    corestats_.statblock[static_cast<unsigned short>(stat)] = value;
}

void Stats::setStat(ARMORSTATS stat, stattype value) {
    armorstats_.statblock[static_cast<unsigned short>(stat)] = value;
}

void Stats::setStat(RESISTATS stat, stattype value) {
    resistancestats_.statblock[static_cast<unsigned short>(stat)] = value;
}

const stattype Stats::getStat(CORESTATS stat) const {
    return corestats_.statblock[static_cast<unsigned short>(stat)];
}

const stattype Stats::getStat(ARMORSTATS stat) const {
    return armorstats_.statblock[static_cast<unsigned short>(stat)];
}

const stattype Stats::getStat(RESISTATS stat) const {
    return resistancestats_.statblock[static_cast<unsigned short>(stat)];
}