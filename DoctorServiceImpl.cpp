#include "DoctorService.h"

vector<Doctor> DoctorService::getAllDoctor()
{
	return this->doctors;
}

bool DoctorService::addDoctor()
{
	cout << "请输入工号：";
	string id = "";
	while (true) {
		cin >> id;
		if (!isExist(id)) {
			cout << "工号已存在，请重新输入！" << endl;
		}
		else {
			break;
		}
	}

	cout << "请输入姓名：";
	string name = "";
	cin >> name;
	
	cout << "请输入年龄：";
	int age = 0;
	cin >> age;

	cout << "请输入性别：" << endl;
	cout << "0-男" << endl;
	cout << "1-女" << endl;
	int sex = 0;
	while (true) {
		cin >> sex;
		if (sex != 0 && sex != 1) {
			cout << "输入有误，请按提示输入！" << endl;
		}
		else {
			break;
		}
	}

	cout << "请输入家庭地址：";
	string address = "";
	cin >> address;

	cout << "请输入所属部门：";
	string department = "";
	cin >> department;

	Doctor* doctor = new Doctor(id, name, age, sex, address, department);
	this->doctors.push_back(*doctor);

	return true;
}

bool DoctorService::delDoctor(string id)
{
	for (auto it = doctors.begin(); it != doctors.end(); it++) {
		if (it->id == id) {
			doctors.erase(it);
			return true;
		}
	}

	// 没找到
	return false;
}

void DoctorService::changeDoctorInfo(string id)
{
	Doctor* changeDoctor = new Doctor();
	try {
		// 处理找到医生的情况
		*changeDoctor = findDoctorById(id);
	}
	catch (const exception e) {
		// 输出错误信息或者进行其他逻辑处理
		cout << "发生异常：" << e.what() << endl;
		return;
	}

    bool exit = false;
    while (!exit) {
        cout << "请选择要修改的信息：" << endl;
        cout << "1. 姓名" << endl;
        cout << "2. 年龄" << endl;
        cout << "3. 性别" << endl;
        cout << "4. 地址" << endl;
        cout << "5. 部门" << endl;
        cout << "6. 退出" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "请输入新的姓名：";
                cin >> changeDoctor->name;
                break;
            case 2:
                cout << "请输入新的年龄：";
                cin >> changeDoctor->age;
                break;
            case 3:
                cout << "请输入新的性别（0表示男，1表示女）：";
                cin >> changeDoctor->sex;
                break;
            case 4:
                cout << "请输入新的地址：";
                cin >> changeDoctor->address;
                break;
            case 5:
                cout << "请输入新的部门：";
                cin >> changeDoctor->department;
                break;
            case 6:
                exit = true;  // 退出循环
                break;
            default:
                cout << "无效选项，请重新输入" << endl;
                break;
        }
		if(choice<=5&&choice>=1)
			updateDoctor(*changeDoctor);
    }
}

// 更新时，默认原工号和现工号是相同的
bool DoctorService::updateDoctor(Doctor& doctor)
{
	/*for (auto it = doctors.begin(); it != doctors.end(); it++) {
		if (it->id == doctor.id) {
			*it = doctor;
		}
	}*/

	try {
		// 处理找到医生的情况
		Doctor& foundDoctor = findDoctorById(doctor.id);
		foundDoctor = doctor;
	}
	catch (const exception e) {
		// 输出错误信息或者进行其他逻辑处理
		cout << "发生异常：" << e.what() << endl;
		return false;
	}
	
	return true;
}

vector<Doctor> DoctorService::findDoctorsByName(string name)
{
	vector<Doctor> findDoctors;
	for (auto it = doctors.begin(); it != doctors.end(); it++) {
		if (it->name == name)
			findDoctors.push_back(*it);
	}

	return findDoctors;
}

Doctor& DoctorService::findDoctorById(string id)
{
	for (auto it = doctors.begin(); it != doctors.end(); it++) {
		if (it->id == id)
			return *it;
	}

	// 没找到，抛出异常
	throw out_of_range("没有找到");
}

vector<Doctor> DoctorService::sortById()
{
	vector<Doctor> doctorsSortById = doctors;
	
	sort(doctorsSortById.begin(), doctorsSortById.end(), [](const Doctor& a, const Doctor& b) {
		return a.id < b.id;		// 按照医生id进行升序排序
	});

	return doctorsSortById;
}

bool DoctorService::isExist(string id)
{
	for (Doctor doctor : doctors) {
		if (doctor.id == id)
			return false;
	}

	return true;
}

void DoctorService::showInfo(vector<Doctor> v)
{
	for (const auto& doctor : v) {
		cout << doctor;
		cout << "------------------------" << endl;
	}
}