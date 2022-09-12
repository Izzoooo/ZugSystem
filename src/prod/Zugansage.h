//
// Created by Kai Renz on 01.06.20.
//

#ifndef SE_TERMIN_3_ZUGANSAGE_H
#define SE_TERMIN_3_ZUGANSAGE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Zugansage {

public:
    /*
     * Die Funktion liefert eine Ansage ....
     * Dokumentation gemaeß User-Story und Akzeptanzkriterium
    */

    bool generiereAnsage(const string& startBahnhof,
        const string& zielBahnhof,
        const string& naechsterHalt,
        int verspaetung,
        int aktuelleStunde,
        int aktuelleMinute,
        int naechsterHaltStunde,
        int naechsterHaltMinute,
        string& ansage
    );

    int vorMittag(int aktuelleStunde);

    bool umgangsprachlich(int, int, std::string&);

    string zahlZUwort(int index);


    //int uhrzeitDiff(int aktuell, int ziel);
private:
    vector<string> zahlen{};
    vector<string> umgang{"nach ", "halb ", "vor ", "viertel ", "Punkt "};


};


#endif //SE_TERMIN_3_ZUGANSAGE_H
