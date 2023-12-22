#ifndef _EQUIPMENTSERVICE_H_
#define _EQUIPMENTSERVICE_H_

#include "header.h"
#include "Equipment.h"

class EquipmentService {
public:
	vector<Equipment> equipments;

private:
	vector<Equipment> getAllEquipments();
	bool addEquipment();
	bool delEquipment(string id);
	Equipment& getEquipment(string id);

	bool isExist(string id);
	void showInfo(vector<Equipment> v);
};

#endif