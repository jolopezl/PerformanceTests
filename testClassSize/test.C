#include "DigitIndex.h"

void test()
{
    // check to see if the event class is in the dictionary
    // if it is not load the definition in libEvent.so
    if (!TClassTable::GetDict("DigitIndexBitField") ||
        !TClassTable::GetDict("DigitIndexUInt"))
    {
        gSystem->Load("DigitIndex_cxx.so");
    }

    // create a Tree file tree4.root
    TFile f("tree.root", "RECREATE");

    // create a ROOT Tree
    TTree t("t", "A Tree");

    // create a pointer to an object
    DigitIndexBitField *digitIndex_BF = new DigitIndexBitField();
    DigitIndexUInt *digitIndex_UInt = new DigitIndexUInt();

    // create two branches
    t.Branch("DigitIndexBitField", "DigitIndexBitField", &digitIndex_BF);
    t.Branch("DigitIndexUInt", "DigitIndexUInt", &digitIndex_UInt);

    const int row = 15;
    const int pad = 14;

    // Write at least one event per detector
    for (int det = 0; det < 540; ++det)
    {
        // Write to bit field
        digitIndex_BF->setDetector(det);
        digitIndex_BF->setRow(row);
        digitIndex_BF->setPad(pad);

        // Write to integers
        digitIndex_UInt->setDetector(det);
        digitIndex_UInt->setRow(row);
        digitIndex_UInt->setPad(pad);

        t.Fill();
    }

    f.Write();
    t.Print();
}
