cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(loc_share VERSION 1.0)

# Specify C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the executable
add_executable(LocShare src/main.c
                    src/gps.c
                    src/gsat_bu353s4.c
                    src/serial_com.c
                    src/NMEA/gpgga.c
                    src/NMEA/gpgsa.c
                    src/NMEA/gpgsv.c
                    src/NMEA/gprmc.c)
