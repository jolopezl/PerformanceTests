# Performance of Digit Index classes

This is a simple test to measure the disk size (on a TTree) for the design of the TRD Digit data structure.

* Option A: Bitfield
```
unsigned int mDetector : 10; // 10 TRD detector number, 0-539
unsigned int mRow : 4;       // 4 pad row, 0-15
unsigned int mPad : 8;       // 8 pad within pad row, 0-14
```

* Option B: Usual integers
```
std::uint16_t mDetector; // 10 TRD detector number, 0-539
std::uint8_t mRow;       // 4 pad row, 0-15
std::uint8_t mPad;       // 8 pad within pad row, 0-14
```

The data structures are as C++ classes in the file `DataIndex.h`. Create the dictionaries in ROOT:
```
root [0] .L DigitIndex.cxx++
```

The macro `test.C` creates a ROOT tree with two branches, one for each of the data structure candidates, and fills them with one member per detector to account for more than one element.

Running `test.C` as a standard ROOT macro provides the following output:

```
$> root -l -q test.C 

Processing test.C...
******************************************************************************
*Tree    :t         : A Tree                                                 *
*Entries :      540 : Total =           13993 bytes  File  Size =       3194 *
*        :          : Tree compression factor =   4.16                       *
******************************************************************************
*Branch  :DigitIndexBitField                                                 *
*Entries :      540 : BranchElement (see below)                              *
*............................................................................*
*Br    0 :mDetector : UInt_t                                                 *
*Entries :      540 : Total  Size=       2746 bytes  File Size  =        877 *
*Baskets :        1 : Basket Size=      32000 bytes  Compression=   2.55     *
*............................................................................*
*Br    1 :mRow      : UInt_t                                                 *
*Entries :      540 : Total  Size=       2721 bytes  File Size  =        119 *
*Baskets :        1 : Basket Size=      32000 bytes  Compression=  18.72     *
*............................................................................*
*Br    2 :mPad      : UInt_t                                                 *
*Entries :      540 : Total  Size=       2721 bytes  File Size  =        119 *
*Baskets :        1 : Basket Size=      32000 bytes  Compression=  18.72     *
*............................................................................*
*Branch  :DigitIndexUInt                                                     *
*Entries :      540 : BranchElement (see below)                              *
*............................................................................*
*Br    3 :mDetector : UShort_t                                               *
*Entries :      540 : Total  Size=       1666 bytes  File Size  =        877 *
*Baskets :        1 : Basket Size=      32000 bytes  Compression=   1.31     *
*............................................................................*
*Br    4 :mRow      : UChar_t                                                *
*Entries :      540 : Total  Size=       1101 bytes  File Size  =         93 *
*Baskets :        1 : Basket Size=      32000 bytes  Compression=   6.54     *
*............................................................................*
*Br    5 :mPad      : UChar_t                                                *
*Entries :      540 : Total  Size=       1101 bytes  File Size  =         93 *
*Baskets :        1 : Basket Size=      32000 bytes  Compression=   6.54     *
*............................................................................*
```