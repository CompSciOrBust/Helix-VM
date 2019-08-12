#include <iostream>
#include <switch.h>
#include <fstream>
#include "VM_Init.h"
#include "VM_CPU_Fetch.h"
#include "VM_CPU_Decode.h"
#include "VM_CPU_Execute.h"
using namespace std;

//vars
int IsRunning = 1;

//Registers
#define REG_COUNT 15
int32_t Registers[REG_COUNT] = {};
/*
Register 0 is PC
Register 1 is reserved for flags
*/

//Opperands
uint8_t OpCode = 0;
uint8_t Reg1 = 0;
uint8_t Reg2 = 0;
uint8_t Reg3 = 0;
int ImmediateValue = 0;

//1 MB of ram
uint8_t Ram[1024] = {};

//Prints the register values to the console.
void ShowResult()
{
    for(int Reg = 0; Reg < REG_COUNT; Reg++)
    {
        printf("r%i = #%i\n", Reg, Registers[Reg]);
    }
}

void Run()
{
	//While runnign run the fetch decode execute cycle
    while(IsRunning)
    {
        int Instruction = Fetch(Ram, Registers);
        Decode(Instruction, &OpCode, &Reg1, &Reg2, &Reg3, &ImmediateValue);
        Execute(&OpCode, &Reg1, &Reg2, &Reg3, &ImmediateValue, Ram, Registers, &IsRunning);
		consoleUpdate(NULL); //Needed on switch to updte the console ouput
    }
	//Output the result of all registers once execution halts
    ShowResult();
}

int main()
{
	consoleInit(NULL); //Init the Switch's console
	printf("\033[0;32mHBH_NX Virtual machine\033[0m\n");
	Init(Ram);
    Run();
	consoleUpdate(NULL);
	//Wait for exit
	while(true)
	{
		u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
		hidScanInput();
		if(kDown & KEY_PLUS)
		{
			break;
		}
	}
	consoleExit(NULL);//Free up system resources before exiting
	return 0;
}