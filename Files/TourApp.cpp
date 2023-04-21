#include "../TourLibrary/Table.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

/*#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define new new
#endif*/
int main()
{
    Excursion_place* place = new Excursion_place("2","1","2",1);
    //delete place;
    //Table* tabl = new Table;
    
    //delete tabl;
    
    
    //Route rock(1, place);
    //Onedayexcursion* lol = new Onedayexcursion("1","1",1,1,1,rock);
    //lol->setDate("1"); lol->setSold(1); lol->setRoute(rock);
    // ("1", "1", 1, 1, 1, rock);
    
    Route* rouk = new Route(1,place);
   
    //rouk->setNumplaces(2);
    //rouk->setExcpl(place);
    //Manydayexcursion* mow = new Manydayexcursion(2,rouk);
    //mow->setDate("1"); mow->setDays(2); mow->setRoute(rouk);
   //lol;//dynamic_cast<Onedayexcursion*>(lol);//= dynamic_cast<Manydayexcursion*>(mow);//lol;
   // std::cout<<omega->getManyRoute()[0].getNumplaces();
    //Onedayexcursion* k = dynamic_cast<Onedayexcursion*>(omega);
    //std::cout << k->getRoute().getExcplaces()->getStart();
    //std::cout<< omega->getRoute().getExcplaces()->getStart();
    Onedayexcursion* lol = new Onedayexcursion(rouk[0]);
    std::cout << std::endl;
    Manydayexcursion* exc =new Manydayexcursion(2,rouk);
    //tabl->add(0, date, omega);
    Table* tab=new Table(5);
    Date date{ 1,1,1 };
    Date date2{ 2,2,2021 };
    Date date3{ 0,0,0 };
    Excursion* omega = lol;//new Manydayexcursion(2, rouk);
    tab->add(0, date, exc);
    tab->add(1, date2, omega);
    tab->add(1, date3, lol);
   // tab.add(1, 3);
    tab->add(1, date, omega);
   // tab.remove(1, date);
   
    //tab.add(1, date, omega);
    tab->print();
    //delete place;
    //delete rouk;
    try
    {
        tab->find(1, date);
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what();
    }    
    delete tab;
    _CrtDumpMemoryLeaks();
    return 0;
}
