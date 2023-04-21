#include "ConstElementIt.h"

int ConstElementIt::operator!=(const ConstElementIt& it) const
{
	return !(cur == it.cur);
}
int ConstElementIt::operator==(const ConstElementIt& it)const
{
	return cur == it.cur;
}
const Element& ConstElementIt::operator*()
{
	if (cur)
		return *cur;
	throw std::exception("Invalid value");
}
ConstElementIt& ConstElementIt::operator++()
{
	cur = cur->getNext();
	return *this;
}
ConstElementIt ConstElementIt::operator++(int)
{
	ConstElementIt res;
	res.cur = cur;
	cur = cur->getNext();
	return res;
}