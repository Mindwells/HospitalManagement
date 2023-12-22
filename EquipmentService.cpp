#include "EquipmentService.h"

vector<Equipment> EquipmentService::getAllEquipments()
{
    return this->equipments;
}

bool EquipmentService::addEquipment()
{
    cout << "��������е��ţ�";
    string id;
    cin >> id;
    if (isExist(id)) {
        cout << "��е����Ѵ��ڣ����������룡" << endl;
        return false;
    }

    cout << "��������е���ƣ�";
    string name;
    cin >> name;

    cout << "�������������ţ�";
    string department;
    cin >> department;

    cout << "�����빺��۸�";
    double price;
    cin >> price;

    cout << "������ԭ���أ�";
    string origin;
    cin >> origin;

    cout << "������˵���飺";
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
    throw out_of_range("û���ҵ�");
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