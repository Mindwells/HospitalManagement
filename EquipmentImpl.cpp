#include "Equipment.h"

ostream& operator<<(ostream& os, const Equipment& equipment)
{
    os << "��е���: " << equipment.id << endl;
    os << "��е����: " << equipment.name << endl;
    os << "��������: " << equipment.department << endl;
    os << "����۸�: " << equipment.price << endl;
    os << "ԭ����: " << equipment.origin << endl;
    os << "˵����: " << equipment.text << endl;

    return os;
}