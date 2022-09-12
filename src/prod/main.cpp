//
// Created by Kai Renz on 01.06.20.
//

#include "Zugansage.h"

#include <string>
#include <iostream>

using namespace std;
int main(int argc, char** argv) {
    std::locale::global(std::locale("German"));

    Zugansage zugansage;

    const string startBahnhof = "Muenchen Hauptbahnhof";
    const string zielBahnhof = "Berlin Hauptbahnhof";
    const string naechsterHalt = "Erfurt Hauptbahnhof";
    int verspaetung = 3;

    int aktuelleStunde = 13;
    int aktutelleMinute = 37;
;
    int naechsterHaltStunde = 14;
    int naechsterHaltMinute = 3;


    string ansageString;

    bool success = zugansage.generiereAnsage(startBahnhof, zielBahnhof, naechsterHalt, verspaetung,
        aktuelleStunde, aktutelleMinute, naechsterHaltStunde, naechsterHaltMinute, ansageString);

    cout << "Ansage " << ansageString << endl;

    Zugansage _zugansage;

    int _aktuelleStunde = 13;
    int _aktuelleMinute = 15;

    string _ansage;

    bool success1 = zugansage.umgangsprachlich(_aktuelleStunde, _aktuelleMinute, _ansage);

    cout << _ansage;

    return 0;
}
