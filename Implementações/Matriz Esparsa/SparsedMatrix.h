#ifndef SPARSED_MATRIX_H
#define SPARSED_MATRIX_H
#include <functional>
#include <utility>

class SparsedMatrix {
private:
    struct MatrixNode {
        int entry;
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
    void insert(int value, unsigned int row, unsigned int column);
    void insertQuietly(int value, unsigned int row, unsigned int column);
    void insertOverlaping(int value, unsigned int row, unsigned int column);
    void insertQuietlyOverlaping(int value, unsigned int row, unsigned int column);
    void deleteElement(unsigned int row, unsigned int column);
    void deleteElementQuietly(unsigned int row, unsigned int column);
    void replace(int value, unsigned int row, unsigned int column);
    void replaceQuietly(int value, unsigned int row, unsigned int column);
    int getValue(unsigned int row, unsigned int column) const;
    int* getRow(unsigned int row) const;
    int* getColumn(unsigned int column) const;
    void forEachElement(const std::function<void(int, unsigned int, unsigned int)>& process);

private:
    bool isRequestCompatibleWithDimension(unsigned int row, unsigned int column) const;
    MatrixPointer pointAtPosition(unsigned int row, unsigned int column) const;
    MatrixPointer setPointerToPreviousInRow(unsigned int row, unsigned int column) const;
    MatrixPointer setPointerToPreviousInColumn(unsigned int row, unsigned int column) const;
    void insertValue(int value, unsigned int row, unsigned int column);
    void deleteAtPosition(MatrixPointer& pointer, unsigned int row, unsigned int column);
};

#endif