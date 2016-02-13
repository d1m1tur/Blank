#include <windows.h>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout<<argc<<argv[1]<<std::endl;

    char* File;

    File = "./resources/code.jpg";

    SystemParametersInfo( SPI_SETDESKWALLPAPER, 0, (PVOID)argv[1], SPIF_UPDATEINIFILE );

    Sleep(50);
}
