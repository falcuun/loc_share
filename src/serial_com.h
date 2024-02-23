#ifndef SERIAL_COM_H_
#define SERIAL_COM_H_

#include <stdint.h>
#include <stdbool.h>
#include <windows.h>

int open_port(const char *port_name, DWORD baud_rate);
int read_from_port();
void close_port();
#endif // SERIAL_COM_H_