#include "EquipmentService.h"

vector<Equipment> EquipmentService::getAllEquipments()
{
    return this->equipments;
}

bool EquipmentService::addEquipment()
{
    cout << "请输入器械编号：";
    string id;
    cin >> id;
    if (isExist(id)) {
        cout << "器械编号已存在，请重新输入！" << endl;
        return false;
    }

    cout << "请输入器械名称：";
    string name;
    cin >> name;

    cout << "请输入所属部门：";
    string department;
    cin >> department;

    cout << "请输入购买价格：";
    double price;
    cin >> price;

    cout << "请输入原产地：";
    string origin;
    cin >> origin;

    cout << "请输入说明书：";
    string text;
    cin >> text;

    Equipment newEquipment(id, name, department, price, origin, text);
    this->equipments.push_back(newEquipment);

    return true;
}

bool EquipmentService::delEquipment(string id)
{
    for (auto it = equipments.begin(); it != equipments.end(); it++) {
        if (it->id == id) {
            equipments.erase(it);
            return true;
        }
    }
    return false;
}

Equipment& EquipmentService::getEquipment(string id)
{
    for (auto it = equipments.begin(); it != equipments.end(); it++) {
        if (it->id == id) {
            return *it;
        }
    }
    throw out_of_range("没有找到");
}

bool EquipmentService::isExist(string id)
{
    for (Equipment equipment : equipments) {
        if (equipment.id == id) {
            return true;
        }
    }
    return false;
}

void EquipmentService::showInfo(vector<Equipment> v)
{
    for (const auto& equipment : v) {
        cout << equipment;
        cout << "------------------------" << endl;
    }
}