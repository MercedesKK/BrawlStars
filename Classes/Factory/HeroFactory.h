/** @author ʱ���� */

#pragma once

#include "Factory/Factory.h"
#include "Hero/HeroSprite.h"
#include <memory>

typedef Hero* (*HeroCreator)(void);
typedef std::unordered_map<std::string, HeroCreator> HeroFactoryMap;

class HeroFactory :protected Factory
{
public:
	static std::unique_ptr<HeroFactory>& getInstance();

	/** 
	* @fn createWithClassID
	* @brief instantiation
	*/
	Hero* createWithClassID(std::string classID);

	/**
	* @fn getClassIDVec
	* @brief get vector of class ID
	*/
	using Factory::getClassIDVec;
	
	void registerClassCreator(std::string classID, HeroCreator creator);

protected:

private:
	static std::unique_ptr<HeroFactory> _heroFactoryInstance;
	HeroFactoryMap _heroFactoryMap;
};

class HeroRegister
{
public:
	HeroRegister(std::string classID, HeroCreator creator)
	{
		HeroFactory::getInstance()->registerClassCreator(classID, creator);
	}
	HeroRegister() = delete;
};