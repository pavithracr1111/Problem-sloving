#include <stdio.h>
#include <stdint.h>

// Fixed macros
#define HEADER 0xAA
#define FOOTER 0x55
#define DEVICE_ID 0x01

// Global variable to store decoded data
uint8_t decodedData[100] = {0};

// Bit masks and shifts
#define HEADER_SHIFT 56
#define SIZE_SHIFT 48
#define DEVICE_ID_SHIFT 40
#define LENGTH_SHIFT 32
#define ORDER_SHIFT 24
#define DATA_SHIFT 16
#define FOOTER_SHIFT 0

#define HEADER_MASK 0xFF
#define SIZE_MASK 0xFF
#define DEVICE_ID_MASK 0xFF
#define LENGTH_MASK 0xFF
#define ORDER_MASK 0xFF
#define DATA_MASK 0xFF
#define FOOTER_MASK 0xFF

// Function prototype
int decodePacket(uint64_t packets[], size_t packetCount, uint8_t deviceId);

// Provided function to print decoded data
void printDecodedData()
{
    printf("Decoded Data: ");
    for (int i = 0; i < 100; i++)
    {
        if (decodedData[i] != 0)
        {
            printf("%c", decodedData[i]);
        }
    }
    printf("\n");
}

// Main function (provided for testing)
int main()
{
    uint64_t packets[] = {
        0xAA090109056F0055,
        0xAA090109066F0055,
        0xAA09010901680055,
        0xAA09010907770055,
        0xAA090109086F0055,
        0xAA09010909720055,
        0xAA090109036C0055,
        0xAA0901090A6C0055,
        0xAA09010902650055,
        0xAA090109046C0055};

    size_t packetCount = sizeof(packets) / sizeof(packets[0]);

    if (decodePacket(packets, packetCount, DEVICE_ID) == 0)
    {
        printDecodedData();
    }
    else
    {
        printf("Failed to decode packets.\n");
    }

    return 0;
}

// Your implementation of decodePacket() goes here
int decodePacket(uint64_t packets[], size_t packetCount, uint8_t deviceId)
{
    // TODO: Implement this function
    for (int i = 0; i < packetCount; i++)
    {

        uint8_t header = (packets[i] >> HEADER_SHIFT) & HEADER_MASK;          // 0xAA
        uint8_t footer = (packets[i] >> FOOTER_SHIFT) & FOOTER_MASK;          // 0x55
        uint8_t device_id = (packets[i] >> DEVICE_ID_SHIFT) & DEVICE_ID_MASK; // 0x01

        uint8_t order = (packets[i] >> ORDER_SHIFT) & ORDER_MASK;
        uint8_t data = (packets[i] >> DATA_SHIFT) & DATA_MASK;

        if (header == HEADER && footer == FOOTER && device_id == deviceId)
        {
            decodedData[order] = data;
            break;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}
