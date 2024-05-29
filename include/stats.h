#pragma once

#include "data_type.h"

#include <vector>

enum class CORESTATS  {STAMINA, STRENGTH, INTELECT, LUCK, NUM_STATS};
enum class ARMORSTATS {PIERCE, SLASH, SLAM, SLAP, NUM_STATS};
enum class RESISTATS  {FIRE, WATER, AIR, EARTH, NUM_STATS};

/**
 * @brief Templated StatBlock class that will take care of stats. Used for base stats, armor as well as element resistance organisation.
 */
template <class T>
class StatBlock {
public:

    /**
     * @brief size public variable to hold size of the stats container.
    */
    unsigned short size;

    /**
     * @brief statblock public variable to hold the stats, i.e. container.
    */
    std::vector<stattype> statblock;

    /**
     * @brief Default StatBlock constructor has been deleted to prevent empty initialization.
     * See StatBlock(T size, stattype value) as how to do init.
     */
    StatBlock() = delete;

    /**
     * @brief StatBlock destructor.
     */
    // virtual ~StatBlock() = 0;
    ~StatBlock();

    /**
     * @brief StatBlock constructor with input parameters to define the stat container.
     * 
     * @param vtsize used to reserve containers space, usually filled with STATENUM::NUM_STATS.
     * @param value is a initial value stat values are set to.
     */
    StatBlock(T vtsize, stattype value = 0u);

    /**
     * @brief += operator reloaded
     * 
     * @param rhs a right hand side StatBlock to the operator
     */
    StatBlock<T>& operator+=(const StatBlock& rhs);

    /**
     * @brief -= operator reloaded
     * 
     * @param rhs a right hand side StatBlock to the operator
     */
    StatBlock<T>& operator-=(const StatBlock& rhs);

    /**
     * @brief = operator reloaded
     * 
     * @param rhs a right hand side StatBlock to the operator
     */
    StatBlock<T>& operator=(const StatBlock<T>& rhs);
};

/**
 * @brief Stats class to hold core, armor and resistance stats.
 */
class Stats {
public:

    /**
     * @brief Default Stats constructor with one optional parameter.
     * 
     * @param value optional parameter to set all the stats to, takes '0u' value by default.
     */
    Stats(stattype value = 0u);

    /**
     * @brief Stats destructor.
     */
    ~Stats();

    /**
     * @brief Stats constructor with three input parameters to initialize different statblocks separately.
     * 
     * @param core value to initialize core statblock values with.
     * @param armor value to initialize armor statblock values with.
     * @param resi value to initialize resistance statblock values with.
     */
    Stats(stattype core, stattype armor, stattype resi);

    /**
     * @brief Setter for core stats with shared value.
     * 
     * @param value to set core stats to.
     */
    void setCoreStats(stattype value);

    /**
     * @brief
     * 
     * @param
     */
    void setCoreStats(const std::vector<stattype> values);

    /**
     * @brief Core stats getter.
     * 
     * @return corestats statblock as a constant vector of stattype.
     */
    const std::vector<stattype> getCoreStats() const;

    /**
     * @brief
     * 
     * @param
     */
    void setArmorStats(stattype value);

    /**
     * @brief
     * 
     * @param
     */
    void setArmorStats(const std::vector<stattype> values);

    /**
     * @brief Armor stats getter.
     * 
     * @return armorstats statblock as a constant vector of stattype.
     */
    const std::vector<stattype> getArmorStats() const;

    /**
     * @brief
     * 
     * @param
     */
    void setResistanceStats(stattype value);

    /**
     * @brief
     * 
     * @param
     */
    void setResistanceStats(const std::vector<stattype> values);

    /**
     * @brief Resistance stats getter.
     * 
     * @return resistancestats statblock as a constant vector of stattype.
     */
    const std::vector<stattype> getResistanceStats() const;

    /**
     * @brief
     * 
     * @param
     * @param
     */
    void setStat(CORESTATS stat, stattype value);

    /**
     * @brief
     * 
     * @param
     * @param
     */
    void setStat(ARMORSTATS stat, stattype value);

    /**
     * @brief
     * 
     * @param
     * @param
     */
    void setStat(RESISTATS stat, stattype value);

    /**
     * @brief Core stat getter.
     * 
     * @param stat from CORESTATS.
     * 
     * @return corestats stat value.
     */
    const stattype getStat(CORESTATS stat) const;

    /**
     * @brief Armor stat getter.
     * 
     * @param stat from ARMORSTATS.
     * 
     * @return armorstats stat value.
     */
    const stattype getStat(ARMORSTATS stat) const;

    /**
     * @brief Resistance stat getter.
     * 
     * @param stat from RESISTATS.
     * 
     * @return resistancestats stat value.
     */
    const stattype getStat(RESISTATS stat) const;

private:
    StatBlock<CORESTATS> corestats_;
    StatBlock<ARMORSTATS> armorstats_;
    StatBlock<RESISTATS> resistancestats_;
};