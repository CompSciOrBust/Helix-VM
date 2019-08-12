#include <iostream>

//Gets the next instruction from the 1MB ram buffer and returns for decoding
uint32_t Fetch(uint8_t Ram[1024], int32_t Registers[15])
{
    //Encodes as little endian
    uint32_t Instruction = 0;
    Instruction =  (uint32_t)Ram[Registers[0]*4 + 3]<<24;
    Instruction += (uint32_t)Ram[Registers[0]*4 + 2]<<16;
    Instruction += (uint32_t)Ram[Registers[0]*4 + 1]<<8;
    Instruction += (uint32_t)Ram[Registers[0]*4];
    Registers[0]++;
    return Instruction;
}