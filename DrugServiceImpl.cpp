#include "DrugService.h"

vector<Drug> DrugService::getAllDrugs()
{
    return this->drugs;
}

bool DrugService::addDrug()
{
    cout << "������ҩƷ��ţ�";
    string id;
    cin >> id;
    if (isExist(id)) {
        cout << "ҩƷ����Ѵ��ڣ����������룡" << endl;
        return false;
    }

    cout << "������ҩƷ���ƣ�";
    string name;
    cin >> name;

    cout << "������ҩƷ���ͣ�";
    string type;
    cin >> type;

    cout << "������۸�";
    double price;
    cin >> price;

    cout << "������˵���飺";
    string text;
    cin >> text;

    Drug drug(id, name, type, price, text);
    this->drugs.push_back(drug);

    return true;
}

bool DrugService::delDrug(string id)
{
    for (auto it = drugs.begin(); it != drugs.end(); it++) {
        if (it->id == id) {
            drugs.erase(it);
            return true;
        }
    }
    return false;
}

Drug& DrugService::getDrug(string id)
{
    for (auto it = drugs.begin(); it != drugs.end(); it++) {
        if (it->id == id) {
            return *it;
        }
    }
    throw out_of_range("û���ҵ�");
}

bool DrugService::isExist(string id)
{
    for (Drug drug : drugs) {
        if (drug.id == id) {
            return true;
        }
    }
    return false;
}

void DrugService::showInfo(vector<Drug> v)
{
    for (const auto& drug : v) {
        cout << drug;
        cout << "------------------------" << endl;
    }
}