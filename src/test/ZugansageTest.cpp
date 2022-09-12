//
// Created by Kai Renz on 01.06.20.
//

#include "ZugansageTest.h"
#include <string>
using namespace std;



TEST_F(ZugansageTest, testAnsage_Akzeptanzkriterium_1) {

    string startBahnhof = "Muenchen Hauptbahnhof";
    string zielBahnhof = "Berlin Hauptbahnhof";
    string naechsterHalt = "Erfurt Hauptbahnhof";
    int verspaetung = 3;

    int aktuelleStunde = 13;
    int aktuelleMinute = 37;

    int naechsterHaltStunde = 14;
    int naechsterHaltMinute = 3;

    string ansage;

    bool success = zugansage->generiereAnsage(startBahnhof, zielBahnhof, naechsterHalt, verspaetung,
        aktuelleStunde, aktuelleMinute, naechsterHaltStunde, naechsterHaltMinute, ansage);


    ASSERT_TRUE(success);

    ASSERT_STREQ("Willkommen im Zug von Muenchen Hauptbahnhof nach Berlin Hauptbahnhof. "
        "Die aktuelle Uhrzeit ist dreizehn Uhr und siebenunddreissig Minuten. "
        "Den naechsten Halt Erfurt Hauptbahnhof erreichen wir in sechsundzwanzig Minuten um "
        "vierzehn Uhr und drei Minuten. Vielen Dank fuer Ihre Reise mit Fasttrain", ansage.c_str());
}

TEST_F(ZugansageTest, testAnsage_Akzeptanzkriterium_2) {
    int aktuelleStunde = 17;
    int aktuelleMinute = 15;

    string ansage;

    bool success1 = zugansage->umgangsprachlich(aktuelleStunde, aktuelleMinute, ansage);

    ASSERT_TRUE(success1);

    ASSERT_STREQ("viertel nach siebzehn",ansage.c_str());

    ansage.clear();
    aktuelleStunde = 15;
    aktuelleMinute = 38;

     

    success1 = zugansage->umgangsprachlich(aktuelleStunde, aktuelleMinute, ansage);

    ASSERT_TRUE(success1);

    ASSERT_STREQ("zwanzig vor vier",ansage.c_str());


    ansage.clear();
    aktuelleStunde = 12;
    aktuelleMinute = 45;

     

    success1 = zugansage->umgangsprachlich(aktuelleStunde, aktuelleMinute, ansage);

    ASSERT_TRUE(success1);

    ASSERT_STREQ("viertel vor dreizehn",ansage.c_str());


    ansage.clear();
    aktuelleStunde = 19;
    aktuelleMinute = 0;

     

    success1 = zugansage->umgangsprachlich(aktuelleStunde, aktuelleMinute, ansage);

    ASSERT_TRUE(success1);

    ASSERT_STREQ("genau sieben",ansage.c_str());

    ansage.clear();
    aktuelleStunde = 13;
    aktuelleMinute = 20;

     

    success1 = zugansage->umgangsprachlich(aktuelleStunde, aktuelleMinute, ansage);

    ASSERT_TRUE(success1);

    ASSERT_STREQ("zwanzig nach eins",ansage.c_str());

    ansage.clear();
    aktuelleStunde = 18;
    aktuelleMinute = 30;

     

    success1 = zugansage->umgangsprachlich(aktuelleStunde, aktuelleMinute, ansage);

    ASSERT_TRUE(success1);

    ASSERT_STREQ("halb sieben",ansage.c_str());
}
