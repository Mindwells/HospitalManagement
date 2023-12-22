#ifndef _DRUGSERVICE_H_
#define _DRUGSERVICE_H_

#include "header.h"
#include "Drug.h"

class DrugService {
private:
	vector<Drug> drugs;

public:
	vector<Drug> getAllDrugs();
	bool addDrug();
	bool delDrug(string id);
	Drug& getDrug(string id);

	bool isExist(string id);
	void showInfo(vector<Drug> v);
};

#endif