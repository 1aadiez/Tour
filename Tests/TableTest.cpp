#include "pch.h"
#include "TableTest.h"
TEST(TABLE, Find)
{
	Date date{ 1,1,2021 };
	Table tab(5);
	Onedayexcursion* exc=new Onedayexcursion;
	tab.add(1, date, nullptr);
	Element al = tab.find(1, date);
	EXPECT_EQ(1, al.getKey());
	EXPECT_TRUE(date == al.getRelease());
}
TEST(TABLE, FindException)
{
	Table tab(3);
	Date date{ 1,1,2021 };
	tab.add(2, date, nullptr);
	EXPECT_ANY_THROW(tab.find(3, date));
}
TEST(TABLE, Remove)
{
	Date date{ 1,1,2021 };
	Table tab;
	tab.add(1, date, nullptr);
	tab.remove(1, date);
	EXPECT_ANY_THROW(tab.find(1, date));
}