//
// Created by Chen Zhao on 7/2/20.
//
// header guards prevent you from including a file again, which is illegal in c++ since you can only define these stuff once
#ifndef CPP_PRIMER_SALES_DATA_H
#define CPP_PRIMER_SALES_DATA_H
#include <string>
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif //CPP_PRIMER_SALES_DATA_H

