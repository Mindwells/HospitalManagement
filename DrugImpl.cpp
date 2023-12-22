#include "Drug.h"

ostream& operator<<(ostream& os, const Drug& drug)
{
    os << "药品编号：" << drug.id << endl;
    os << "药品名称：" << drug.name << endl;
    os << "药品类型：" << drug.type << endl;
    os << "价格：" << drug.price << endl;
    os << "说明书：" << drug.text << endl;

    return os;
}