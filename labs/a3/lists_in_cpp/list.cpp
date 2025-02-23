#include "list.h"
int main(){
    List list1, list2, list3;
    list1.append(1);
    list1.append(2);
    list2.append(30);
    list2.append(40);
    list3 = list1;
    list3.append(3);
    list1.append(4);
    List list4 = list3 + list2;
    std::cout << list1 << std::endl;
    std::cout << list3[0] << std::endl;
    std::cout << list4 << std::endl;
    std::cout << "Length of list - " << list4.getSize() << std::endl;
    return 0;
}
