#ifndef GPS_H_
#define GPS_H_

#include <stdbool.h>

// GPS Struct that holds the coordinates
typedef struct 
{
    double lat;
    double lon;
}gps_t;

// Function that will be used to compare the currently polled location with the cached one. 
bool compare_gps(gps_t gps1, gps_t gps2);

#endif // GPS_H_