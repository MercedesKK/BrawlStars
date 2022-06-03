#pragma once
#include "cocos2d.h"
#include"ui/CocosGUI.h"

/**
* @brief ��������
*/
class PlistData 
{
public:

	/**
	* @brief ��������
	*/
	enum class DataType
	{
		ID,
		Profile,
		Name,
		Cups,
		Money,
		Figure,
		Log,
	};

	/**
	* @brief ����û�����By ID
	*/
	static void addDate(const std::string& id, const std::string&& path);

	/**
	* @brief ��ȡ��������
	*/
	static std::string getDataByType(DataType type);

	/**
	* @brief д������
	*/
	static void WriteDataByType(DataType type,const std::string&);

	/**
	* @brief ��ʼ���û�����
	*/
	static cocos2d::ValueMap& initData(const std::string& id);

private:

	//�����ݵ�map
	static cocos2d::ValueMap _map;

	//�Ƿ��Ѷ�����
	static bool _exit;

	//·��
	static std::string _path;

};
