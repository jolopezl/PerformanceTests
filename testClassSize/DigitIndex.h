#ifndef ROOT_Event
#define ROOT_Event

class DigitIndexUInt
{
public:
    DigitIndexUInt() = default;
    ~DigitIndexUInt() = default;
    DigitIndexUInt(const int det, const int row, const int pad)
        : mDetector(det), mRow(row), mPad(pad) {}
    DigitIndexUInt(const DigitIndexUInt &) = default;
    // Modifiers
    void setDetector(int det) { mDetector = det; }
    void setRow(int row) { mRow = row; }
    void setPad(int pad) { mPad = pad; }
    // Get methods
    int getDetector() const { return mDetector; }
    int getRow() const { return mRow; }
    int getPad() const { return mPad; }

private:
    std::uint16_t mDetector; // 10 TRD detector number, 0-539
    std::uint8_t mRow;       // 4 pad row, 0-15
    std::uint8_t mPad;       // 8 pad within pad row, 0-14

    ClassDef(DigitIndexUInt, 1)
};

class DigitIndexBitField
{
public:
    DigitIndexBitField() = default;
    ~DigitIndexBitField() = default;
    DigitIndexBitField(const int det, const int row, const int pad)
        : mDetector(det), mRow(row), mPad(pad) {}
    DigitIndexBitField(const DigitIndexBitField &) = default;
    // Modifiers
    void setDetector(int det) { mDetector = det; }
    void setRow(int row) { mRow = row; }
    void setPad(int pad) { mPad = pad; }
    // Get methods
    int getDetector() const { return mDetector; }
    int getRow() const { return mRow; }
    int getPad() const { return mPad; }

private:
    unsigned int mDetector : 10; // 10 TRD detector number, 0-539
    unsigned int mRow : 4;       // 4 pad row, 0-15
    unsigned int mPad : 8;       // 8 pad within pad row, 0-14.q

    ClassDef(DigitIndexBitField, 1)
};

#endif