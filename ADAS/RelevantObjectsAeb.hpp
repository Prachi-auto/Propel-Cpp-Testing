
#ifndef RELEVANT_OBJECTS_AEB_HPP
#define RELEVANT_OBJECTS_AEB_HPP

#include "ADAS/RelevantObjectsCommon.hpp"

class RelevantObjectsAeb : public RelevantObjectsCommon
{
public:
    explicit RelevantObjectsAeb(float max_longitudinal_range_meters);
};

#endif
