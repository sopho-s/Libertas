#include "linux/cron.h"
#include "shared/argparser.h"
#include "shared/toolpage.h"

int main(int argc, char *argv[]) {
    DisplayAscii();
    std::cout << std::endl;
    Args args = Args(argc, argv);
    if (args.help) {
        DisplayHelp();
        return 0;
    }
    Cron cron = Cron();
}