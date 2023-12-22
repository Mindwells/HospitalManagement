#ifndef _DRUG_H_
#define _DRUG_H_

#include "header.h"

class Drug {
	friend class DrugService;
	friend ostream& operator<<(ostream& os, const Drug& drug);
private:
	string id;		// 药品id
	string name;	// 药品名称
	string type;	// 药品类型
	double price;	// 价格
	string text;	// 说明书

public:
	Drug(){}
	Drug(string id, string name, string type, double price, string text) :
		id(id), name(name), type(type), price(price), text(text) {}
};

#endif