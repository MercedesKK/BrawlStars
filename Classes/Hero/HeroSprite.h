//2150266 ʱ����

#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Hero/BulletSprite.h"

#include <functional>
#include <vector>
#include <string>
#include <map>

#define DEPRECATED_ACCESS private
#define SELECTOR_ACCESS public

class Bullet;

/**
* @class Hero
* @brief Hero is the base class of the heroes in Brawl Stars
*/
class Hero :public cocos2d::Sprite {
public:
	/**
	* @enum Level
	* @brief Level can describe an attribute of the hero
	*/
	enum class Level :char {
		ZERO = 0,
		EXTREME_LOW = 1,
		LOW = 2,
		MEDIUM = 3,
		HIGH = 4,
		EXTREME_HIGH = 5
	};

	/// @name Listener Set-ups
	/// @{

	/**
	* @fn setContactListener
	* @brief choose whether to allow physics contact. The function is disabled by default
	*/
	void setContactListener(bool contactState) noexcept;

	/// @}
	/// end of Listener Set-ups

	/// @name Attribute Manipulators
	/// @{

	float getMoveSpeed()   const noexcept { return static_cast<float>(_moveSpeed); }
	double getEnergy()     const noexcept { return _energy; }
	int getShotRange()     const noexcept { return 75 * static_cast<int>(_shotRange); }
	int getHitPoint()      const noexcept { return _hitPoint; }
	int getSkillHitPoint() const noexcept { return _skillHitPoint; }
	int getHP()            const noexcept { return _healthPoint; }
	int getDiamond()       const noexcept { return _diamond; }
	bool alive()           const noexcept { return _alive; }
	bool skillStatus()     const noexcept { return _energy == _maxEnergy; }

	/**
	* @fn addHP
	* @brief modify the health point and update the health strip
	* @param increasePoint: the hp increasement point
	* @return the HP after increasing
	* @return the health point
	* @exception out_of_range the increasement point is negative
	*/
	int addHP(const int increasePoint);

	/**
	* @fn deductHP
	* @brief modify the health point and update the health strip
	* @param deductPoint: the hp deduction point
	* @return the health point
	* @exception out_of_range the deduction point is negative
	*/
	int deductHP(const int deductPoint);

	int setHP(const int HP) = delete;

	/**
	* @fn addEnergy
	* @brief modify the energy point and update the energy strip
	* @param increasePoint: the energy increasement point
	* @return the energy point
	* @exception out_of_range the increasement point is negative
	*/
	int addEnergy(const int increasePoint);

	/**
	* @fn deductEnergy
	* @brief modify the energy point and update the energy strip
	* @param deductPoint: the energy deduction point
	* @return the energy point
	* @exception out_of_range the deduction point is negative
	*/
	int deductEnergy(const int deductPoint);

	/**
	* @fn setEnergy
	* @brief modify the energy point and update the energy strip
	* @param energy: the energy point
	* @return the energy point
	* @exception out_of_range the input is negative or larger than max energy
	*/
	int setEnergy(const int energy);

	/**
	* @fn addDiamond
	* @brief modify the attributes and update the diamond number
	* @param increasePoint: the diamond increasement point
	* @return the number of diamond
	* @exception out_of_range the increasement point is negative
	*/
	int addDiamond(const int increasePoint);

	/**
	* @fn deductDiamond
	* @brief modify the attributes and update the diamond number
	* @param deductPoint: the diamond deduction point
	* @return the number of diamond
	* @exception out_of_range the deduction point is negative
	*/
	int deductDiamond(const int deductPoint);

	/**
	* @fn setDiamond
	* @brief modify the attributes and update the diamond number
	* @param diamond: the diamond number
	* @return the number of diamond
	* @exception out_of_range the input is negative
	*/
	int setDiamond(const int diamond);

	/// @}
	/// end of Attribute Manipulators
	
	/// @name Hero Manipulators
	/// @{
	
	void setAlive(bool alive);
	
	/**
	* @fn attack
	* @brief attack toward the target
	*/
	bool attack(cocos2d::Point target);

	/**
	* @fn prepareSkillRelease
	* @brief update the energy strip to prepare releasing skill
	* @return whether skill is charged ( energy == maxEnergy )
	*/
	bool prepareSkillRelease();

	/**
	* @fn releaseSkill
	* @brief release the skill toward the target
	*/
	bool releaseSkill(cocos2d::Point target);

	/**
	* @fn moveStep
	* @brief a single step of moving hero toward the target
	*/
	void moveStep(cocos2d::Point target);

	/// @}
	/// end of Hero Manipulators

SELECTOR_ACCESS:
	/// @name Schedule Selectors
	/// @{

	/**
	* @fn startLoading
	* @brief each bullet is loaded for (2.0 - static_cast<float>(_loadSpeed) * 0.25) seconds
	*/
	void load(float fdelta = 1) noexcept;

	/**
	* @fn heal
	* @brief the function will use itself as a schedule selector to heal the hero automatically
	*/
	void heal(float fdelta = 1) noexcept;

	/// @}
	/// end of Schedule Selectors

protected:
	/**
	* @brief the constructor is used to initialize the constant variables
	* @details derived classes must give the constant parameters, so the default constructor is deleted
	*/
	Hero(const int originalHP, const int maxAmmo);
	Hero() = delete;
	virtual ~Hero() = default;

	/** the attributes of a hero */
	const int _maxAmmo;
	const double _maxEnergy = 1000;
	const int _originalHP;
	int _maxHealthPoint;
	int _healthPoint;
	int _hitPoint;
	int _skillHitPoint;
	int _ammo;
	double _energy = 0;
	int _diamond = 0;
	Level _shotRange;
	Level _moveSpeed;
	Level _loadSpeed;
	std::vector<cocos2d::Sprite*> _ammoStrip;
	cocos2d::ui::LoadingBar* _energyStrip = cocos2d::ui::LoadingBar::create("energyStrip.png");  ///< the energy strip
	cocos2d::ui::LoadingBar* _bloodStrip = cocos2d::ui::LoadingBar::create("bloodStrip.png");    ///< the blood strip
	cocos2d::Sprite* heroDiamond = cocos2d::Sprite::create("diamond.png");                       ///< the diamond to be displayed
	cocos2d::Label* diamondNum;                                                                  ///< the number of diamonds
	
	/// @name Virtual Functions
	/// @{
	
	/**
	* @fn attack
	* @brief the animation of attack
	* @details derived classes need to override the function, which will act as a listener callback
	*/
	virtual bool attackAnimation(cocos2d::Point) = 0;

	/**
	* @fn superChargedSkill
	* @brief the animation of super charged skill
	* @details derived classes need to override the function, which will act as a listener callback
	*/
	virtual bool skillAnimation(cocos2d::Point) = 0;

	/**
	* @fn updateAttributesWithDiamond
	* @brief the default update strategy, which can be overrided
	*/
	virtual void updateAttributesWithDiamond();

	/// @}
	/// end of Virtual Functions

	/// @name Initializers in derived classes
	/// @warning the function should be used after the set of hero's texture
	/// @{
	
	/**
	* @fn initializeHeroPhysics
	* @brief initialize the physics body of hero
	*/
	void initializeHeroPhysics();

	/** 
	* @fn initializeBloodStrip
	* @brief draw the blood strip
	* @deprecated show the health point on the strip
	*/
	void initializeBloodStrip();

	/**
	* @fn initializeAmmoStrip
	* @brief initialize the ammo strip with the max ammo
	*/
	void initializeAmmoStrip(const int maxAmmo);

	/**
	* @fn initializeEnergyStrip
	* @brief add the energy strip to the hero
	*/
	void initializeEnergyStrip();

	/**
	* @fn initializeDiamondDisplay
	* @brief display the number of diamonds
	*/
	void initializeDiamondDisplay(const int diamond = 0);

	/// @}
	/// end of Initializers in derived classes

private:
	bool _alive = true;                                             ///< mark whether the hero is alive

	/** event listeners */
	static cocos2d::EventListenerPhysicsContact* _contactListener;

	/** initializer of the event listeners */
	void initializeContactListener();

	/** callback functions of the event listeners */
	bool onContactBegin(cocos2d::PhysicsContact& contact);
	void onContactSeperate(cocos2d::PhysicsContact& contact);

DEPRECATED_ACCESS:

};