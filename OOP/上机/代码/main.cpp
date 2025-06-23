#include "config.h"
#include "system.h"
#include "user.h"
#include "goods.h"
#include "functions.h"
#include "shoppinglist.h"

int main()
{
    Config config = Config("./config.ini");
    System system = System(config);
    system.run("Welcome to shopping system! Enter \"help\" for more information.");
    return 0;
}