#ifndef _DRUGSERVICE_H_
#define _DRUGSERVICE_H_

#include "header.h"
#include "entityHeader.h"

class DrugService {
private:
	vector<Drug> drugs;

public:
	vector<Drug> getAllDrugs();
	bool delDrug(string id);
	bool addDrug(Drug drug);
	Drug getDrug(string id);
	bool updateDrug(Drug drug);
};

#endif