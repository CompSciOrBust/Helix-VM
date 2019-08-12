#include <iostream>
void Execute(uint8_t* OpCode, uint8_t* Reg1, uint8_t* Reg2, uint8_t* Reg3, int* ImmediateValue, uint8_t Ram[1024], int32_t Registers[15], int* IsRunning)
{
    switch(*OpCode)
    {
        //Halt
        case 0:
        printf("Halt!\n");
        *IsRunning = 0;
        break;
        //Add
        case 1:
        printf("Add r%i r%i r%i\n", *Reg1, *Reg2, *Reg3);
        Registers[*Reg3] = Registers[*Reg1] + Registers[*Reg2];
        break;
        //Sub
        case 2:
        printf("Sub r%i r%i r%i\n", *Reg1, *Reg2, *Reg3);
        Registers[*Reg3] = Registers[*Reg1] - Registers[*Reg2];
        break;
        //Loadi
        case 3:
        printf("Loadi #%i r%i\n", *ImmediateValue, *Reg1);
        Registers[*Reg1] = *ImmediateValue;
        break;
        //Loada
        case 4:
        printf("Loada @%i r%i\n", *Reg2, *Reg1);
        Registers[*Reg1] =  (uint32_t)Ram[*Reg2 + 3]<<24;
        Registers[*Reg1] += (uint32_t)Ram[*Reg2 + 2]<<16;
        Registers[*Reg1] += (uint32_t)Ram[*Reg2 + 1]<<8;
        Registers[*Reg1] += (uint32_t)Ram[*Reg2];
        break;
        //Copy register to reg
        case 5:
        printf("Movr r%i r%i\n", *Reg1, *Reg2);
        Registers[*Reg2] = Registers[*Reg1];
        break;
        //Copy to ram
        case 6:
        printf("Mova r%i @%i\n", *Reg1, Ram[*Reg2]);
        Ram[*Reg2 + 0] = (Registers[*Reg1]&0xFF000000)>>24;
        Ram[*Reg2 + 1] = (Registers[*Reg1]&0x00FF0000)>>16;
        Ram[*Reg2 + 2] = (Registers[*Reg1]&0x0000FF00)>>8;
        Ram[*Reg2 + 3] = (Registers[*Reg1]&0x000000FF);
        break;
        //Jump greater
        case 7:
        printf("Jump greater #%i #%i @%i\n", Registers[*Reg2] ,Registers[*Reg3], Registers[*Reg1]);
        if (Registers[*Reg2] > Registers[*Reg3])
        {
            Registers[0] = Registers[*Reg1];
        }
        break;
        //Jump equal
        case 8:
        printf("Jump equal #%i #%i @%i\n", Registers[*Reg2] ,Registers[*Reg3], Registers[*Reg1]);
        if (Registers[*Reg2] = Registers[*Reg3])
        {
            Registers[0] = Registers[*Reg1];
        }
        break;
        //Jump not equal
        case 9:
        printf("Jump not equal #%i #%i @%i\n", Registers[*Reg2] ,Registers[*Reg3], Registers[*Reg1]);
        if (Registers[*Reg2] != Registers[*Reg3])
        {
            Registers[0] = Registers[*Reg1];
        }
        break;
        //Undefined
        default:
        printf("Undefined op code!\n");
        break;
    }
}