#include <iostream>

void Init(uint8_t Ram[1024])
{
	//Load the file exe.bin in to the 1MB ram buffer. Thanks to XorTroll for helpiping me get this working on Horizon OS
	FILE *f = fopen("sdmc:/exe.bin", "rb");
	if(f)
	{
    fseek(f, 0, SEEK_END);
    size_t file_size = ftell(f);
    rewind(f);
    fread(Ram, 1, file_size, f);
    fclose(f);
	}
}