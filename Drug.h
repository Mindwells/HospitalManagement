#ifndef _DRUG_H_
#define _DRUG_H_

#include "header.h"

class Drug {
private:
	string id;		// 药品id
	string name;	// 药品名称
	string type;	// 药品类型
	double price;	// 价格
	string text;	// 说明书

public:
	Drug(){}
};

#endif