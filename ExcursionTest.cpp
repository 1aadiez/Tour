#include "pch.h"
#include "ExcursionTest.h"
#include "../TourLibrary/Excursion.h"
#include "../TourLibrary/Onedayexcursion.h"
#include "../TourLibrary/Manydayexcursion.h"

TEST(ONEDAYEXCURSION, DefaultConstr)
{
	Onedayexcursion one;
	EXPECT_EQ(1, one.getDays());
	EXPECT_EQ(0, one.getSold());
	EXPECT_EQ(0, one.getDate().day);
	EXPECT_EQ(0, one.getDate().month);
	EXPECT_EQ(0, one.getDate().year);
}
TEST(ONEDAYEXCURSION, Constructors)
{
	Excursion_place* excpl = new Excursion_place("Moscow", "Kremlin", "12:05", 4);
	Route route(1, excpl);
	Date date{ 11,12,2021 };
	Onedayexcursion one("Walking", date, 213.00, 10, 8, route);
	EXPECT_EQ(date.day, one.getDate().day);
	EXPECT_EQ(date.month, one.getDate().month);
	EXPECT_EQ(date.year, one.getDate().year);
	EXPECT_EQ(8, one.getSold());
	EXPECT_EQ(1, one.getManyRoute()->getNumplaces());
	EXPECT_TRUE("Moscow" == one.getManyRoute()->getExcplaces()->getComm());
	EXPECT_TRUE("Kremlin" == one.getManyRoute()->getExcplaces()->getObj());
	EXPECT_TRUE("12:05" == one.getManyRoute()->getExcplaces()->getStart());
	EXPECT_EQ(4, one.getManyRoute()->getExcplaces()->getDuration());
	delete excpl;
}
TEST(ONEDAYEXCURSION, Setter)
{
	Excursion_place* excpl = new Excursion_place("Moscow", "Kremlin", "12:05", 4);
	Route route(1, excpl);
	Date date{ 11,12,2021 };
	Onedayexcursion one("Walking", date, 213.00, 10, 8, route);
	one.setSold(9);
	EXPECT_EQ(9, one.getSold());
	EXPECT_ANY_THROW(one.setSold(-1));
	EXPECT_ANY_THROW(one.setSold(11));
}
TEST(MANYDAYEXCURSION, DefaultConstr)
{
	Manydayexcursion mexc;
	EXPECT_EQ(0, mexc.getDays());
	EXPECT_TRUE(nullptr == mexc.getManyRoute());
	EXPECT_EQ(0, mexc.getDate().day);
	EXPECT_EQ(0, mexc.getDate().month);
	EXPECT_EQ(0, mexc.getDate().year);
}
TEST(MANYDAYEXCURSION, Constructor)
{
	//Excursion place with 2 places
	Excursion_place firstplace("Moscow", "Kremlin", "12:45", 4);
	Excursion_place second("Tver", "Museum", "19:00", 2);
	Excursion_place* excpl = new Excursion_place[2];
	excpl[0] = firstplace; excpl[1] = second;
	//Excursion place with 1 place
	Excursion_place* exc = new Excursion_place;
	exc[0] = firstplace;
	//
	Route* route = new Route[2];
	Route firstday(2, excpl);
	Route secondday(1, exc);
	route[0] = firstday;
	route[1] = secondday;
	Date date{ 12,11,2021 };
	Manydayexcursion mexc("Kew", date, 213.00, 11, 9, 2, route);
	//Manydayexcursion days/sold places
	EXPECT_EQ(2, mexc.getDays());
	EXPECT_EQ(9, mexc.getSold());
	// Route[0] Excpl[0]
	EXPECT_TRUE("Moscow"== mexc.getManyRoute()[0].getExcplaces()[0].getComm());
	EXPECT_TRUE("Kremlin" == mexc.getManyRoute()[0].getExcplaces()[0].getObj());
	EXPECT_TRUE("12:45" == mexc.getManyRoute()[0].getExcplaces()[0].getStart());
	EXPECT_EQ(4, mexc.getManyRoute()[0].getExcplaces()[0].getDuration());
	//Route[0] Excpl[1]
	EXPECT_TRUE("Tver" == mexc.getManyRoute()[0].getExcplaces()[1].getComm());
	EXPECT_TRUE("Museum" == mexc.getManyRoute()[0].getExcplaces()[1].getObj());
	EXPECT_TRUE("19:00" == mexc.getManyRoute()[0].getExcplaces()[1].getStart());
	EXPECT_EQ(2, mexc.getManyRoute()[0].getExcplaces()[1].getDuration());
	// Route[1] Excpl[0]
	EXPECT_TRUE("Moscow" == mexc.getManyRoute()[1].getExcplaces()[0].getComm());
	EXPECT_TRUE("Kremlin" == mexc.getManyRoute()[1].getExcplaces()[0].getObj());
	EXPECT_TRUE("12:45" == mexc.getManyRoute()[1].getExcplaces()[0].getStart());
	EXPECT_EQ(4, mexc.getManyRoute()[1].getExcplaces()[0].getDuration());
	delete[] route;
	delete[] excpl;
	delete exc;
}