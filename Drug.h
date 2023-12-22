#ifndef _DRUG_H_
#define _DRUG_H_

#include "header.h"

class Drug {
	friend class DrugService;
	friend ostream& operator<<(ostream& os, const Drug& drug);
private:
	string id;		// ҩƷid
	string name;	// ҩƷ����
	string type;	// ҩƷ����
	double price;	// �۸�
	string text;	// ˵����

public:
	Drug(){}
	Drug(string id, string name, string type, double price, string text) :
		id(id), name(name), type(type), price(price), text(text) {}
};

#endif