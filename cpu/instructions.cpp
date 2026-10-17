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
        printf("MVI B, %02x", (unsigned char)buffer[pc + 1]);
        opbytes = 2;
        break;
    case 0x07:
        printf("RLC");
        break;
    case 0x08:
        printf("Undocumented NOP");
        break;
    case 0x09:
        printf("DAD B");
        break;
    case 0x0A:
        printf("LDAX B");
        break;
    case 0x0B:
        printf("DCX B");
        break;
    case 0x0C:
        printf("INR C");
        break;
    case 0x0D:
        printf("DCR C");
        break;
    case 0x0E:
        printf("MVI C, %02x", (unsigned char)buffer[pc + 1]);
        opbytes = 2;
        break;
    case 0x0F:
        printf("RRC");
        break;
    default:
        printf("Unknown instruction");
        break;
    }
    printf("\n");
    return opbytes;
}
