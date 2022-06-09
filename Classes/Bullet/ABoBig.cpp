//�ž��� 2151396
#include "Bullet/ABoBig.h"
#include "Factory/BulletFactory.h"

//����
namespace {
	BulletRegister registerCreator("ABoBig", BulletCreator(ABoBig::create));
}

ABoBig* ABoBig::create()
{
	return new(std::nothrow)ABoBig();
}

ABoBig::ABoBig()
{
	this->setBulletTecture("BulletResource/ABoBig.png");
}