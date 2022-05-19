//2150266 ʱ����

#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Hero/BulletSprite.h"
#include <functional>
#include <vector>
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
	* @fn setKeyboardListener
	* @brief choose whether to use the keyboard to move hero. The function is disabled by default
	*/
	void setKeyboardListener(bool keyboardState) noexcept;

	/**
	* @fn setTouchListener
	* @brief choose whether to use the mouse to shot. The function is disabled by default
	*/
	void setTouchListener(bool touchState) noexcept;

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
	int getHitPoint()      const noexcept { return _hitPoint; }
	int getSkillHitPoint() const noexcept { return _skillHitPoint; }
	int getHP()            const noexcept { return _healthPoint; }
	int getEnergy()        const noexcept { return _energy; }
	int getDiamond()       const noexcept { return _diamond; }

	void addDiamond(int num = 1)  noexcept { ++_diamond; }

	/// @}
	/// end of Attribute Manipulators

	/// @name Strip Manipulators
	/// @brief modify the attributes and update the strips
	/// @{

	/**
	* @fn increaseHP
	* @param increasePoint: the hp increasement point
	* @return the HP after increasing
	* @return the health point
	* @exception out_of_range the increasement point is negative
	*/
	int increaseHP(const int increasePoint);

	/**
	* @fn deductHP
	* @param deductPoint: the hp deduction point
	* @return the health point
	* @exception out_of_range the deduction point is negative
	*/
	int deductHP(const int deductPoint);

	int setHP(const int HP) = delete;

	/**
	* @fn increaseEnergy
	* @param increasePoint: the energy increasement point
	* @return the energy point
	* @exception out_of_range the increasement point is negative
	*/
	int increaseEnergy(const int increasePoint);

	/**
	* @fn deductEnergy
	* @param deductPoint: the energy deduction point
	* @return the energy point
	* @exception out_of_range the deduction point is negative
	*/
	int deductEnergy(const int deductPoint);

	/**
	* @fn setEnergy
	* @param energy: the energy point
	* @return the energy point
	* @exception out_of_range the input is negative or larger than max energy
	*/
	int setEnergy(const int energy);

	/// @}
	/// end of Strip Manipulators

SELECTOR_ACCESS:
	/// @name Schedule Selectors
	/// @{

	/**
	* @fn startLoading
	* @brief each bullet is loaded for (2.0 - static_cast<float>(_loadSpeed) * 0.25) seconds
	*/
	void load(float fdelta = 1) noexcept;

	void heal(float fdelta = 1) noexcept;

	/**
	* @fn moveHero
	* @brief used by scheduler to move hero
	*/
	void moveHero(float fdelta = 1) noexcept;

	/// @}
	/// end of Schedule Selectors

protected:
	/**
	* @brief the constructor is used to initialize the constant variables
	* @details derived classes must give the constant parameters, so the default constructor is deleted
	*/
	Hero(const int maxHealthPoint, const int maxAmmo);
	Hero() = delete;

	/** the attributes of a hero */
	const int _maxHealthPoint;
	const int _maxAmmo;
	const double _maxEnergy = 1000;
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
	cocos2d::ui::LoadingBar* _bloodStrip = cocos2d::ui::LoadingBar::create("bloodStrip.png");  ///< the blood strip
	
	/// @name Pure Virtual Functions
	/// @{
	/**
	* @fn attack
	* @brief derived classes need to override the attack function, which will act as the listener callback
	*/
	virtual bool attack(cocos2d::Touch* touch, cocos2d::Event* event) = 0;

	/**
	* @fn superChargedSkill
	* @brief 
	*/
	virtual bool superChargedSkill(cocos2d::Touch* touch, cocos2d::Event* event) = 0;

	/// @}
	/// end of Pure Virtual Functions

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
	void initializeDiamondDisplay(const int diamond = 0) = delete;

	/// @}
	/// end of Initializers in derived classes

private:
	bool _releaseSkill = false;                                     ///< control whether to release skill
	std::map<cocos2d::EventKeyboard::KeyCode, bool> _keyCodeState;  ///< control the state of keys

	/** event listeners */
	cocos2d::EventListenerKeyboard* _keyboardListener;
	cocos2d::EventListenerTouchOneByOne* _touchListener;
	static cocos2d::EventListenerPhysicsContact* _contactListener;

	/** initializer of the event listeners */
	void initializeKeyboardListener();
	void initializeTouchListener();
	void initializeContactListener();

	/** callback functions of the event listeners */
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event*);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event*);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	bool onContactBegin(cocos2d::PhysicsContact& contact);
	void onContactSeperate(cocos2d::PhysicsContact& contact);

DEPRECATED_ACCESS:

};