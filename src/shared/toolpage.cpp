#include "toolpage.h"

void DisplayHelp() {
    std::cout << "Libertas is a tool to escalate privileges and give a shell by any means it finds" << std::endl;
    std::cout << std::endl;
    std::cout << "-c [COMMAND]                  Instead of giving a shell at elevated privileges, Libertas will instead execute this command" << std::endl;
    std::cout << "-h                            Displays help" << std::endl;
    std::cout << "-ne                           Makes libertas not execute and will display if the system is vulnerable (not always garanteed) to a privilege escalation method" << std::endl;
}
void DisplayAscii() {
    std::cout << "ooooo        ooooo oooooooooo.  oooooooooooo ooooooooo.   ooooooooooooo       .o.        .oooooo..o " << std::endl;
    std::cout << "`888'        `888' `888'   `Y8b `888'     `8 `888   `Y88. 8'   888   `8      .888.      d8P'    `Y8 " << std::endl;
    std::cout << " 888          888   888     888  888          888   .d88'      888          .8\"888.     Y88bo.      " << std::endl;
    std::cout << " 888          888   888oooo888'  888oooo8     888ooo88P'       888         .8' `888.     `\"Y8888o.  " << std::endl;
    std::cout << " 888          888   888    `88b  888    \"     888`88b.         888        .88ooo8888.        `\"Y88b " << std::endl;
    std::cout << " 888       o  888   888    .88P  888       o  888  `88b.       888       .8'     `888.  oo     .d8P " << std::endl;
    std::cout << "o888ooooood8 o888o o888bood8P'  o888ooooood8 o888o  o888o     o888o     o88o     o8888o 8""88888P'  " << std::endl;                                                                                    
}

void DisplayError(std::string error) {
    std::cout << "[-] " << error << std::endl;
}

void DisplayInfo(std::string info) {
    std::cout << "[+] " << info << std::endl;
}

void DisplayImportant(std::string info) {
    std::cout << "[*] " << info << std::endl;
}