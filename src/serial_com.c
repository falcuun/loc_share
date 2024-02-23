#include "serial_com.h"
#include <stdio.h>

static HANDLE hSerial;

int open_port(const char *port_name, DWORD baud_rate)
{
    // Open the serial port
    hSerial = CreateFile(port_name, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (hSerial == INVALID_HANDLE_VALUE)
    {
        printf("Error opening serial port\n");
        return 1;
    }

    DCB dcbSerialParams = {0};
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams))
    {
        printf("Error getting device state\n");
        CloseHandle(hSerial);
        return 1;
    }
    if (baud_rate != CBR_4800)
    {
        printf("Incorrect Baud rate for this device");
        return 1;
    }

    dcbSerialParams.BaudRate = baud_rate;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(hSerial, &dcbSerialParams))
    {
        printf("Error setting device parameters\n");
        CloseHandle(hSerial);
        return 1;
    }
    return 0;
}

int read_from_port()
{
    // Read data from serial port
    DWORD bytesRead;
    char readBuffer[1024];
    DWORD totalBytesRead = 0;
    memset(readBuffer, 0, sizeof(readBuffer));

    // Continuously read data until you receive your delimiter or reach buffer capacity
    while (1)
    {
        DWORD bytesToRead = sizeof(readBuffer) - totalBytesRead - 1; // Leave space for null terminator
        if (!ReadFile(hSerial, readBuffer + totalBytesRead, bytesToRead, &bytesRead, NULL) || bytesRead == 0)
        {
            // Handle error or no more data to read
            break;
        }
        totalBytesRead += bytesRead;
        // Check for end-of-message delimiter here, and break if found
        // For example, if your data ends with a newline character, check if readBuffer contains '\n'
    }

    readBuffer[totalBytesRead] = '\0'; // Null-terminate the string
    printf("Read %d bytes: %s\n", totalBytesRead, readBuffer);
    return 0;
}

void close_port()
{
    // Close serial port
    CloseHandle(hSerial);
}