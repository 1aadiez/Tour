#include "../TourLibrary/Table.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    Table tab;
    tab.add(0, 1);
    tab.add(1, 1);
    tab.add(1, 2);
    tab.add(1, 3);
    tab.add(1, 4);
    tab.remove(1, 3);
    tab.print();
    try
    {
        tab.find(1, 2);
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what();
    }
    _CrtDumpMemoryLeaks();
    return 0;
}
