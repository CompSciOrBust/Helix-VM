#include <iostream>

//Takes the interger provided by the fetch function and isolates the bytes for each opperand.
void Decode(uint32_t Instruction, uint8_t* OpCode, uint8_t* Reg1, uint8_t* Reg2, uint8_t* Reg3, int* ImmediateValue)
{
    *OpCode =    (Instruction&0xFF000000)>>24;
    *Reg1 =      (Instruction&0x00FF0000)>>16;
    *Reg2 =      (Instruction&0x0000FF00)>>8;
    *Reg3 =      (Instruction&0x000000FF);
    *ImmediateValue = (Instruction&0x0000FFFF);
}