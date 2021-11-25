#include "pch.h"
#include "RouteTest.h"
#include "../TourLibrary/Route.h"
#include "../TourLibrary/Excursion_place.h"
TEST(ROUTE, DefaultConstr)
{
	Route route;
	EXPECT_EQ(1, route.getNumplaces());
}
TEST(ROUTE, Constructor)
{
	Excursion_place* excpl = new Excursion_place("Moscow", "Kremlin", "12:05", 4);
	Route route(1, excpl);
	EXPECT_EQ(1, route.getNumplaces());
	EXPECT_TRUE("Moscow" == excpl->getComm());
	EXPECT_TRUE("Kremlin" == excpl->getObj());
	EXPECT_TRUE("12:05" == excpl->getStart());
	EXPECT_EQ(4, excpl->getDuration());
	delete excpl;
}
TEST(ROUTE, Setters)
{
	Route route;
	route.setNumplaces(2);
	EXPECT_EQ(2, route.getNumplaces());
}
TEST(ROUTE, Exceptions)
{
	Route route;
	EXPECT_ANY_THROW(route.setNumplaces(-1));
	EXPECT_ANY_THROW(route.setNumplaces(-10));
}