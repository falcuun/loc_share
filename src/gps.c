#include "gps.h"

bool compare_gps(gps_t gps1, gps_t gps2)
{
    if (gps1.lat == gps2.lat && gps1.lon == gps2.lon)
    {
        return true;
    }
    return false;
}