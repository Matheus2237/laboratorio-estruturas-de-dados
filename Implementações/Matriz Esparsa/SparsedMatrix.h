#ifndef SPARSED_MATRIX_H
#define SPARSED_MATRIX_H
#include <functional>
#include <utility>

template <typename T>
class SparsedMatrix {

    static_assert(std::is_arithmetic<T>::value && !std::is_same<T, bool>::value && !std::is_same<T, char>::value, "Classe aceita apenas tipos numericos");

private:
    struct MatrixNode {
        T entry;
        unsigned int row;
        unsigned int column;
        MatrixNode* nextRow;
        MatrixNode* nextCol;
    };
    typedef MatrixNode* MatrixPointer;
    struct Dimensions {
        unsigned int row;
        unsigned int column;
    };
    
    MatrixPointer* rows;
    MatrixPointer* columns;
    Dimensions dimensions;
    int nonNullableElementsQuantity;

public:
    SparsedMatrix(unsigned int rowSize, unsigned int columnSize);
    ~SparsedMatrix();
    void clear();
    bool empty() const;
    bool full() const;
    std::pair<unsigned int, unsigned int> getDimensions() const;
    void insert(T value, unsigned int row, unsigned int column);
    void insertQuietly(T value, unsigned int row, unsigned int column);
    void insertOverlaping(T value, unsigned int row, unsigned int column);
    void insertQuietlyOverlaping(T value, unsigned int row, unsigned int column);
    void deleteElement(unsigned int row, unsigned int column);
    void deleteElementQuietly(unsigned int row, unsigned int column);
    void replace(T value, unsigned int row, unsigned int column);
    void replaceQuietly(T value, unsigned int row, unsigned int column);
    T getValue(unsigned int row, unsigned int column) const;
    T* getRow(unsigned int row) const;
    T* getColumn(unsigned int column) const;
    void forEachElement(const std::function<void(T, unsigned int, unsigned int)>& process);

private:
    bool isRequestCompatibleWithDimension(unsigned int row, unsigned int column) const;
    MatrixPointer pointAtPosition(unsigned int row, unsigned int column) const;
    MatrixPointer setPointerToPreviousInRow(unsigned int row, unsigned int column) const;
    MatrixPointer setPointerToPreviousInColumn(unsigned int row, unsigned int column) const;
    void insertValue(T value, unsigned int row, unsigned int column);
    void deleteAtPosition(MatrixPointer& pointer, unsigned int row, unsigned int column);
};

#include "SparsedMatrix.cpp"

#endif