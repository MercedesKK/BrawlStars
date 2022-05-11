#pragma once
#include "Item.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Const/Const.h"
#include "Tool/DiamondBuff.h"

/**
* @author:�ž���
* @ʵ�ֱ�����
*/
class TreasureBox : public Item
{
public:
	CREATE_FUNC(TreasureBox);

	/**
	* @��ʼ�����򿪱���
	*/
	bool virtual init() override;
	void openBox();


	/**
	* @fn createBox
	* @brief ��������
	*/
	TreasureBox* createBox();

	cocos2d::Vec2 getBoxPos() {return _boxPos;};
	void setBoxPos(cocos2d::Vec2 position) = delete;//������㶯

	TreasureBox(const int& maxBoxHealthPoint = kmaxBoxHealthPoint) :_maxHealthPoint(maxBoxHealthPoint) {_healthPoint = _maxHealthPoint;};

	/**
	* @fn initialzeBloodStrip
	* @brief ��ʼ��Ѫ��
	*/
	void initialzeBloodStrip(const int maxBoxHealthPoint);

	/**
	* @fn deductHP
	* @brief ����Ѫ��
	*/
	int deductHP(int deductPoint);

	int getHP() const noexcept { return _healthPoint; }
protected:
	//����λ��
	cocos2d::Vec2 _boxPos;

    //Ѫ��
	const int _maxHealthPoint;
	int _healthPoint;

private:
	cocos2d::ui::LoadingBar* _bloodStrip = cocos2d::ui::LoadingBar::create(Path::kbloodStrip);  ///< the blood strip
};
