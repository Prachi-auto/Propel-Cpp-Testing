#ifndef RELEVANT_OBJECTS_ACC_HPP
#define RELEVANT_OBJECTS_ACC_HPP

#include "ADAS/RelevantObjectsCommon.hpp"
#include <optional>

class RelevantObjectsAcc : public RelevantObjectsCommon
{
public:
    explicit RelevantObjectsAcc(float max_longitudinal_range_meters);
};

#endif
