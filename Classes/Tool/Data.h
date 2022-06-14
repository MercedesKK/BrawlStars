#pragma once
#include "cocos2d.h"
#include"ui/CocosGUI.h"

/**
* @brief ��������
*/
namespace PlistData 
{
//public:

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
	 void addDate(const std::string& id, const std::string&& path);

	/**
	* @brief ��ȡ��������
	*/
	 std::string getDataByType(DataType type);

	/**
	* @brief д������
	*/
	 void WriteDataByType(DataType type,const std::string&);

	/**
	* @brief ��ʼ���û�����
	*/
	 cocos2d::ValueMap& initData(const std::string& id);

	/**
	* @brief �������µ�¼�˻�
	*/
	 void reset();



//private:

	////�����ݵ�map
	//static cocos2d::ValueMap _map;

	////�Ƿ��Ѷ�����
	//static bool _exit;

	////·��
	//static std::string _path;

}
