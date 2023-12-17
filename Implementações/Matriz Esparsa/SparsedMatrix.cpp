#include "SparsedMatrix.h"
#include <stdexcept>

template <typename T>
SparsedMatrix<T>::SparsedMatrix(unsigned int rowSize, unsigned int columnSize):
    nonNullableElementsQuantity(0)
{
    if (rowSize <= 0 || columnSize <= 0)
        throw std::bad_alloc();
    dimensions = {rowSize, columnSize};
    this->rows = new MatrixPointer[rowSize+1];
    this->columns = new MatrixPointer[columnSize+1];
    for (int current = 0; current <= rowSize; ++current)
        rows[current] = nullptr;
    for (int current = 0; current <= columnSize; ++current)
        columns[current] = nullptr;
}

template <typename T>
SparsedMatrix<T>::~SparsedMatrix() {
    this->clear();
    delete[] rows;
    delete[] columns;
}

template <typename T>
void SparsedMatrix<T>::clear() {
    for (unsigned int iterableRow = dimensions.row; iterableRow >= 1; --iterableRow) {
        for (unsigned int iterableColumn = dimensions.column; iterableColumn >= 1; --iterableColumn)
            deleteElementQuietly(iterableRow, iterableColumn);
        rows[iterableRow] = nullptr;
    }
    for (unsigned int iterableColumn = dimensions.column; iterableColumn >= 1; --iterableColumn)
        columns[iterableColumn] = nullptr;
    nonNullableElementsQuantity = 0;
}

template <typename T>
bool SparsedMatrix<T>::empty() const {
    return nonNullableElementsQuantity == 0;
}

template <typename T>
bool SparsedMatrix<T>::full() const {
    return nonNullableElementsQuantity == dimensions.row * dimensions.column;
}

template <typename T>
std::pair<unsigned int, unsigned int> SparsedMatrix<T>::getDimensions() const {
    return std::make_pair(dimensions.row, dimensions.column);
}

template <typename T>
void SparsedMatrix<T>::insert(T value, unsigned int row, unsigned int column) {
    if (value == 0)
        throw std::out_of_range("O valor 0 não pode ser inserido na matriz!");
    if (this->full())
        throw std::out_of_range("Matriz cheia!");
    if (!isRequestCompatibleWithDimension(row, column))
        throw std::out_of_range("Posicao indisponivel para insercao!");
    if (pointAtPosition(row, column) != nullptr)
        throw std::out_of_range("Posicao já ocupada!");
    insertValue(value, row, column);
}

template <typename T>
void SparsedMatrix<T>::insertQuietly(T value, unsigned int row, unsigned int column) {
    if (value == 0 || this->full() || !isRequestCompatibleWithDimension(row, column)
            || pointAtPosition(row, column) != nullptr)
        return;
    insertValue(value, row, column);
}

template <typename T>
void SparsedMatrix<T>::insertOverlaping(T value, unsigned int row, unsigned int column) {
    if (value == 0)
        throw std::out_of_range("O valor 0 não pode ser inserido na matriz!");
    if (!isRequestCompatibleWithDimension(row, column))
        throw std::out_of_range("Posicao indisponivel para insercao!");
    MatrixPointer pointer = pointAtPosition(row, column);
    if (pointer != nullptr)
        pointer->entry = value;
    else
        insertValue(value, row, column);
}

template <typename T>
void SparsedMatrix<T>::insertQuietlyOverlaping(T value, unsigned int row, unsigned int column) {
    if (value == 0 || !isRequestCompatibleWithDimension(row, column))
        return;
    MatrixPointer pointer = pointAtPosition(row, column);
    if (pointer != nullptr)
        pointer->entry = value;
    else
        insertValue(value, row, column);
}

template <typename T>
void SparsedMatrix<T>::insertValue(T value, unsigned int row, unsigned int column) {
    MatrixPointer previousInRow = setPointerToPreviousInRow(row, column);
    MatrixPointer previousInColumn = setPointerToPreviousInColumn(row, column);    
    
    MatrixPointer newNode = new MatrixNode;
    newNode->entry = value;
    newNode->row = row;
    newNode->column = column;

    if (previousInRow == nullptr) {
        newNode->nextCol = rows[row];
        rows[row] = newNode;
    } else if (previousInRow->column > column) {
        newNode->nextCol = previousInRow;
        rows[row] = newNode;
    } else {
        newNode->nextCol = previousInRow->nextCol;
        previousInRow->nextCol = newNode;
    }

    if (previousInColumn == nullptr) {
        newNode->nextRow = columns[column];
        columns[column] = newNode;
    } else if (previousInColumn->row > row) {
        newNode->nextRow = previousInColumn;
        columns[column] = newNode;
    } else {
        newNode->nextRow = previousInColumn->nextRow;
        previousInColumn->nextRow = newNode;
    }
    
    this->nonNullableElementsQuantity++;
}

template <typename T>
bool SparsedMatrix<T>::isRequestCompatibleWithDimension(unsigned int row, unsigned int column) const {
    return row > 0 && row <= dimensions.row && column > 0 && column <= dimensions.column;
}

template <typename T>
typename SparsedMatrix<T>::MatrixPointer SparsedMatrix<T>::pointAtPosition(unsigned int row, unsigned int column) const {
    if (columns[column] != nullptr) {
        MatrixPointer iteratingNode = columns[column];
        while (iteratingNode != nullptr && iteratingNode->row <= row) {
            if (iteratingNode->row == row)
                return iteratingNode;
            iteratingNode = iteratingNode->nextRow;
        }
    }
    return nullptr;
}

template <typename T>
typename SparsedMatrix<T>::MatrixPointer SparsedMatrix<T>::setPointerToPreviousInRow(unsigned int row, unsigned int column) const {
    MatrixPointer previousInRow = rows[row];
    if (previousInRow == nullptr || previousInRow->nextCol == nullptr)
        return previousInRow;
    while (previousInRow->column < column && previousInRow->nextCol != nullptr && previousInRow->nextCol->column < column)
        previousInRow = previousInRow->nextCol;
    return previousInRow;
}

template <typename T>
typename SparsedMatrix<T>::MatrixPointer SparsedMatrix<T>::setPointerToPreviousInColumn(unsigned int row, unsigned int column) const {
    MatrixPointer previousInColumn = columns[column];
    if (previousInColumn == nullptr || previousInColumn->nextRow == nullptr)
        return previousInColumn;
    while (previousInColumn->row < row && previousInColumn->nextRow != nullptr && previousInColumn->nextRow->row < row)
        previousInColumn = previousInColumn->nextRow;
    return previousInColumn;
}

template <typename T>
void SparsedMatrix<T>::deleteElement(unsigned int row, unsigned int column) {
    if (!isRequestCompatibleWithDimension(row, column))
        throw std::out_of_range("Posicao indisponivel para remocao!");
    if (this->empty())
        throw std::out_of_range("Matriz vazia!");
    MatrixPointer pointer = pointAtPosition(row, column);
    if (pointer == nullptr)
        throw std::out_of_range("Posicao nao ocupada na matriz!");
    deleteAtPosition(pointer, row, column);
}

template <typename T>
void SparsedMatrix<T>::deleteElementQuietly(unsigned int row, unsigned int column) {
    if (!isRequestCompatibleWithDimension(row, column) || this->empty())
        return;
    MatrixPointer pointer = pointAtPosition(row, column);
    if (pointer == nullptr)
        return;
    deleteAtPosition(pointer, row, column);
}

template <typename T>
void SparsedMatrix<T>::deleteAtPosition(typename SparsedMatrix<T>::MatrixPointer& pointer, unsigned int row, unsigned int column) {
    MatrixPointer previousInRow = setPointerToPreviousInRow(row, column);
    if (pointer->column == rows[row]->column)
        rows[row] = pointer->nextCol;
    else
        previousInRow->nextCol = pointer->nextCol;

    MatrixPointer previousInColumn = setPointerToPreviousInColumn(row, column);
    if (pointer->row == columns[column]->row)
        columns[column] = pointer->nextRow;
    else
        previousInColumn->nextRow = pointer->nextRow;
    
    delete pointer;
    this->nonNullableElementsQuantity--;
}

template <typename T>
void SparsedMatrix<T>::replace(T value, unsigned int row, unsigned int column) {
    if (value == 0)
        throw std::out_of_range("O valor 0 não pode ser inserido na matriz!");
    if (this->empty())
        throw std::out_of_range("Matriz vazia!");
    if (!isRequestCompatibleWithDimension(row, column))
        throw std::out_of_range("Posicao indisponivel para insercao!");
    MatrixPointer pointer = pointAtPosition(row, column);
    if (pointer == nullptr)
        throw std::out_of_range("Posicao vazia!");
    pointer->entry = value;
}

template <typename T>
void SparsedMatrix<T>::replaceQuietly(T value, unsigned int row, unsigned int column) {
    if (value == 0 || !isRequestCompatibleWithDimension(row, column) || this->empty())
        return;
    MatrixPointer pointer = pointAtPosition(row, column);
    if (pointer == nullptr)
        return;
    pointer->entry = value;
}

template <typename T>
T SparsedMatrix<T>::getValue(unsigned int row, unsigned int column) const {
    if (this->empty())
        throw std::out_of_range("Matriz vazia!");
    if (!isRequestCompatibleWithDimension(row, column))
        throw std::out_of_range("Posicao indisponivel para busca!");
    MatrixPointer pointer = pointAtPosition(row, column);
    if (pointer == nullptr)
        throw std::out_of_range("Posicao nao ocupada na matriz!");
    return pointer->entry;
}

template <typename T>
T* SparsedMatrix<T>::getRow(unsigned int row) const {
    if (this->empty())
        throw std::out_of_range("Matriz vazia!");
    if (row < 1 || row > dimensions.row)
        throw std::out_of_range("Linha indisponivel para busca!");
    int* requestedRow = new int[dimensions.column];
    for (unsigned int iterableColumn = 0; iterableColumn < dimensions.column; ++iterableColumn) {
        MatrixPointer element = pointAtPosition(row, iterableColumn + 1);
        requestedRow[iterableColumn] = element == nullptr ? 0 : element->entry;
    }
    return requestedRow;
}

template <typename T>
T* SparsedMatrix<T>::getColumn(unsigned int column) const {
    if (this->empty())
        throw std::out_of_range("Matriz vazia!");
    if (column < 1 || column > dimensions.column)
        throw std::out_of_range("Coluna indisponivel para busca!");
    int* requestedColumn = new int[dimensions.column];
    for (unsigned int iterableRow = 0; iterableRow < dimensions.row; ++iterableRow) {
        MatrixPointer element = pointAtPosition(iterableRow + 1, column);
        requestedColumn[iterableRow] = element == nullptr ? 0 : element->entry;
    }
    return requestedColumn;
}

template <typename T>
void SparsedMatrix<T>::forEachElement(const std::function<void(T, unsigned int, unsigned int)>& process) {
    for (unsigned int iterableRow = 1; iterableRow <= dimensions.row; ++iterableRow) {
        for (unsigned int iterableColumn = 1; iterableColumn <= dimensions.column; ++iterableColumn) {
            MatrixPointer pointer = pointAtPosition(iterableRow, iterableColumn);
            T value = pointer != nullptr ? pointer->entry : 0;
            process(value, iterableRow, iterableColumn);
        }
    }
}