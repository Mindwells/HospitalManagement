#include "DrugService.h"

vector<Drug> DrugService::getAllDrugs()
{
    return this->drugs;
}

bool DrugService::addDrug()
{
    cout << "请输入药品编号：";
    string id;
    cin >> id;
    if (isExist(id)) {
        cout << "药品编号已存在，请重新输入！" << endl;
        return false;
    }

    cout << "请输入药品名称：";
    string name;
    cin >> name;

    cout << "请输入药品类型：";
    string type;
    cin >> type;

    cout << "请输入价格：";
    double price;
    cin >> price;

    cout << "请输入说明书：";
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
    throw out_of_range("没有找到");
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