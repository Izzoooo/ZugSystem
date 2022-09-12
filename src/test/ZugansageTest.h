//
// Created by Kai Renz on 01.06.20.
//

#ifndef SE_TERMIN_3_ZUGANSAGETEST_H
#define SE_TERMIN_3_ZUGANSAGETEST_H

#include <gtest/gtest.h>

#include "../prod/Zugansage.h"

#include<iostream>
#include<sstream>
class ZugansageTest : public ::testing::Test {

protected:
ZugansageTest() = default;

    Zugansage *zugansage;

    virtual void SetUp() {
        zugansage = new Zugansage();
    }


    virtual void TearDown() {
        delete zugansage;
    }

public:


};




#endif
