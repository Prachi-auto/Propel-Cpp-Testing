#ifndef OBJECT_LIST_HPP
#define OBJECT_LIST_HPP

#include "ADAS/Object.hpp"
#include "ADAS/Constants.hpp"
#include <array>

using ObjectList = std::array<Object, ObjectSelectionConstants::m_number_of_objects>;

#endif
