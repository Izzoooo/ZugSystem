///
// Created by Kai Renz on 01.06.20.
//

#include "Zugansage.h"

/*
int Zugansage::uhrzeitDiff(int aktuell, int ziel){

}
*/

string Zugansage::zahlZUwort(int index)
{

    zahlen.push_back("null"); zahlen.push_back("eine");
    zahlen.push_back("zwei"); zahlen.push_back("drei");
    zahlen.push_back("vier"); zahlen.push_back("fuenf");
    zahlen.push_back("sechs"); zahlen.push_back("sieben");
    zahlen.push_back("acht"); zahlen.push_back("neun");
    zahlen.push_back("zehn"); zahlen.push_back("elf");
    zahlen.push_back("zwoelf"); zahlen.push_back("dreizehn");
    zahlen.push_back("vierzehn"); zahlen.push_back("fuenfzehn");
    zahlen.push_back("sechzehn"); zahlen.push_back("siebzehn");
    zahlen.push_back("achtzehn"); zahlen.push_back("neunzehn");
    zahlen.push_back("zwanzig"); zahlen.push_back("einundzwanzig");
    zahlen.push_back("zweiundzwanzig"); zahlen.push_back("dreiundzwanzig");
    zahlen.push_back("vieundzwanzig"); zahlen.push_back("fuenfundzwanzig");
    zahlen.push_back("sechsundzwanzig"); zahlen.push_back("siebenundzwanzig");
    zahlen.push_back("achtnundzwanzig"); zahlen.push_back("neunundzwanzig");
    zahlen.push_back("dreissig"); zahlen.push_back("einunddreissig");
    zahlen.push_back("zweiunddreissig"); zahlen.push_back("dreiunddreissig");
    zahlen.push_back("vierunddreissig"); zahlen.push_back("fuenfunddreissig");
    zahlen.push_back("sechsunddreissig"); zahlen.push_back("siebenunddreissig");
    zahlen.push_back("achtunddreissig"); zahlen.push_back("neununddreissig");
    zahlen.push_back("viezig"); zahlen.push_back("einundvierzig");
    zahlen.push_back("zweiundvierzig"); zahlen.push_back("dreiundvierzig");
    zahlen.push_back("vierundvierzig"); zahlen.push_back("fuenfundvierzig");
    zahlen.push_back("sechsundvierzig"); zahlen.push_back("siebenundvierzig");
    zahlen.push_back("achtundvierzig"); zahlen.push_back("neunundvierzig");
    zahlen.push_back("fuenfzig"); zahlen.push_back("einundfuenfzig");
    zahlen.push_back("Zweiundfuenfzig"); zahlen.push_back("dreiundfuenfzig");
    zahlen.push_back("vierundfuenfzig"); zahlen.push_back("fuenfundfuenfzig");
    zahlen.push_back("sechsundfuenfzig"); zahlen.push_back("siebenundfuenfzig");
    zahlen.push_back("achtundfuenfzig"); zahlen.push_back("neunundfuenfzig");
    zahlen.push_back("sechzig");

    return zahlen.at(index);
}

//Test für umgangsprachliche Aussagen
bool Zugansage::umgangsprachlich(int aktuelleStunde, int aktuelleMinute, string& ansage)
{
 if(aktuelleMinute == 30)
    {
        ansage += "halb ";
        ansage += zahlZUwort(vorMittag(aktuelleStunde) + 1);
    }

    if(aktuelleMinute == 15)
    {
        ansage += "viertel nach ";
        ansage += zahlZUwort(abs(aktuelleStunde));
        return true;
    }
    if(aktuelleMinute > 35 && aktuelleMinute < 45)
    {
        ansage += "zwanzig vor ";
        if(aktuelleStunde > 12)
        {
            int tmp = aktuelleStunde-12;
            ansage += zahlZUwort(abs(++tmp));
        }
        else
        ansage += zahlZUwort(abs(++aktuelleStunde));
    }
    if(aktuelleMinute >= 41 && aktuelleMinute <= 49)
    {
                ansage += "viertel vor ";
        if(aktuelleStunde > 12)
        {
            int tmp = aktuelleStunde-12;
            ansage += zahlZUwort(abs(++tmp));
        }
        else
        ansage += zahlZUwort(abs(++aktuelleStunde));
    }
    if(aktuelleMinute == 0)
    {
                  ansage += "genau ";
        if(aktuelleStunde > 12)
        {
            int tmp = aktuelleStunde-12;
            ansage += zahlZUwort(abs(tmp));
        }
        else
        ansage += zahlZUwort(abs(aktuelleStunde));
    }
        if(aktuelleMinute > 15 && aktuelleMinute < 25)
    {
                  ansage += "zwanzig nach ";
        if(aktuelleStunde > 12)
        {
            int tmp = aktuelleStunde-12;
            if(tmp == 1 )
            ansage += "eins";
            else
            ansage += zahlZUwort(abs(tmp));
        }
        else 
        {
        if(aktuelleStunde ==1)
        ansage+= "eins";
        else
        ansage += zahlZUwort(abs(aktuelleStunde));
        }
    }
   
}

//Zeit nur als AM (Vor-Mittag) ausgeben. z.B. 17 -> 5 
int Zugansage::vorMittag(int aktuelleStunde)
{
    if(aktuelleStunde > 12)
    {
        int tmp;
        tmp = aktuelleStunde - 12;
        return tmp;   
    }
    else
    return aktuelleStunde;
}

//Reguläre Ansage ohne umgangsprachliche Ausdrücke
bool Zugansage::generiereAnsage(const string& startBahnhof, const string& zielBahnhof,
    const string& naechsterHalt, int verspaetung,
    int aktuelleStunde, int aktuelleMinute,
    int naechsterHaltStunde, int naechsterHaltMinute,
    string& ansage)
{
    ansage = "Willkommen im Zug von ";

    ansage += startBahnhof;
    ansage += " nach ";
    ansage += zielBahnhof;
    ansage += ". ";

//std::string::append -> Erweitert die Zeichenfolge, indem zusätzliche Zeichen am Ende ihres aktuellen Werts angehängt werden.
    ansage += "Die aktuelle Uhrzeit ist ";
    ansage += zahlZUwort(aktuelleStunde); ansage.append(" Uhr und ");
    ansage += zahlZUwort(aktuelleMinute); ansage.append(" Minuten. ");

    ansage += "Den naechsten Halt "; ansage.append(naechsterHalt);
    ansage += " erreichen wir in ";


// Berechnung des Differenz zwischen der aktuellen Uhrzeit und nächsten Haltstellezeit
    int newMinute = (60 - aktuelleMinute + naechsterHaltMinute);
    int newStunde = newMinute / 60;




    if ((newStunde <= 1) && (newMinute > 0)) {
        ansage.append(zahlZUwort(newMinute)); ansage.append(" Minuten");
    }
    else
    {
        ansage.append(zahlZUwort(abs(newStunde))); ansage.append(" Stunde und ");
        ansage.append(zahlZUwort(abs(newMinute))); ansage.append(" Minuten");
    }
 

    //Zeit umrechnung
    ansage += " um "; ansage.append(zahlZUwort(naechsterHaltStunde));
    ansage += " Uhr und "; ansage.append(zahlZUwort(naechsterHaltMinute));
    ansage += " Minuten. "; 

    ansage += "Vielen Dank fuer Ihre Reise mit Fasttrain";


    return true;

}
