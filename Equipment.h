#ifndef _EQUIPMENT_H_
#define	_EQUIPMENT_H_

#include "header.h"

class Equipment {
private:
	string id;			// 器械编号
	string name;		// 器械名称
	string department;	// 所属部门
	double price;		// 购买价格
	string origin;		// 原产地
	string text;		// 说明书
public:
	Equipment(){}
};

#endif 
