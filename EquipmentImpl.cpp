#include "Equipment.h"

ostream& operator<<(ostream& os, const Equipment& equipment)
{
    os << "器械编号: " << equipment.id << endl;
    os << "器械名称: " << equipment.name << endl;
    os << "所属部门: " << equipment.department << endl;
    os << "购买价格: " << equipment.price << endl;
    os << "原产地: " << equipment.origin << endl;
    os << "说明书: " << equipment.text << endl;

    return os;
}