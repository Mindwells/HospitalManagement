#ifndef _EQUIPMENTSERVICE_H_
#define _EQUIPMENTSERVICE_H_

#include "header.h"
#include "Equipment.h"

class EquipmentService {
public:
	vector<Equipment> equipments;

private:
	vector<Equipment> getAllEquipments();
	bool delEquipment(string id);
	bool addEquipment(Equipment equipment);
	Equipment getEquipment(string id);
	bool updateEquipment(Equipment equipment);
};

#endif