#ifndef _DOCTOR_H_
#define _DOCTOR_H_

#include "header.h"

class Doctor {
	friend class DoctorService;
private:
	string id;			// 工号
	string name;		// 姓名
	int age;			// 年龄
	int sex;			// 性别
	string address;		// 家庭地址
	string department;	// 所属部门

public:
	Doctor(){}
	Doctor(string id, string name, int age, int sex, string address, string department) :
		id(id), name(name), age(age), sex(sex), address(address), department(department) {}
};

#endif 
