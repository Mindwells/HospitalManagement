#include "Drug.h"

ostream& operator<<(ostream& os, const Drug& drug)
{
    os << "ҩƷ��ţ�" << drug.id << endl;
    os << "ҩƷ���ƣ�" << drug.name << endl;
    os << "ҩƷ���ͣ�" << drug.type << endl;
    os << "�۸�" << drug.price << endl;
    os << "˵���飺" << drug.text << endl;

    return os;
}