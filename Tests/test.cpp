#include "pch.h"
#include "../TourLibrary/Excursion_place.h"
#include "RouteTest.h"
#include "ExcursionTest.h"
TEST(EXC_PLACES, DefaultConstructor)
{
	Excursion_place exc;
	EXPECT_TRUE("" == exc.getComm());
	EXPECT_TRUE("" == exc.getObj());
	EXPECT_TRUE("" == exc.getStart());
	EXPECT_EQ(0, exc.getDuration());
}
TEST(EXC_PLACES, Constructor)
{
	Excursion_place exc("Moscow", "Kremlin", "12:05", 4);
	EXPECT_TRUE("Moscow" == exc.getComm());
	EXPECT_TRUE("Kremlin" == exc.getObj());
	EXPECT_TRUE("12:05" == exc.getStart());
	EXPECT_EQ(4, exc.getDuration());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
