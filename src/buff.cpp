#include "buff.h"

Buff::Buff()
 : Stats(), duration_(1u), target_(TARGET::SELF), harmful_(false) {}

Buff::~Buff() {}

Buff::Buff(Stats stats, duratype duration, TARGET primary, bool harmful)
 : Stats(stats), duration_(duration), target_(primary), harmful_(harmful) {}