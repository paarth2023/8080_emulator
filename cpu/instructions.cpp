#include "instructions.h"
#include <stdio.h>

int InstructionDisassembler(char *buffer, int pc)
{
    int opbytes = 1;
    switch (buffer[pc]) {
    case 0x00:
        printf("NOP instruction");
        break;
    case 0x01:
        printf("LXI %02x,%02x", (unsigned char)buffer[pc + 2],
               (unsigned char)buffer[pc + 2]);
        opbytes = 3;
        break;
    case 0x02:
        printf("STAX");
        break;
    case 0x03:
        printf("INX");
        break;
    case 0x04:
        printf("INR");
        break;
    case 0x05:
        printf("DCR");
        break;
    case 0x06:
        printf("MVI %02x", buffer[pc + 1]);
        break;
    case 0x07:
        printf("RLC");
        break;
    case 0x08:
        printf("NOP");
        break;
    default:
        printf("Unknown instruction");
        break;
    }
    printf("\n");
    return opbytes;
}
