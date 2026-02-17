#include <cstdint>
/// @brief enum to represent the lane id
enum class LaneId : std::uint8_t
{
    Left,
    Center,
    Right,
    Unknown
};