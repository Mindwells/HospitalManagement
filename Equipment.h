#ifndef _EQUIPMENT_H_
#define	_EQUIPMENT_H_

#include "header.h"

class Equipment {
	friend class EquipmentService;
	friend ostream& operator<<(ostream& os, const Equipment& equipment);
private:
	string id;			// ��е���
	string name;		// ��е����
	string department;	// ��������
	double price;		// ����۸�
	string origin;		// ԭ����
	string text;		// ˵����
public:
	Equipment(){}
	Equipment(string id, string name, string department, double price, string origin, string text) :
		id(id), name(name), department(department), price(price), origin(origin), text(text) {}
};

#endif 
