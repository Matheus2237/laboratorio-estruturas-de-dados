#include "SparsedMatrix.h"
#include <stdexcept>

SparsedMatrix::SparsedMatrix(unsigned int rowSize, unsigned int columnSize):
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

SparsedMatrix::~SparsedMatrix() {
    this->clear();
    delete[] rows;
    delete[] columns;
}

void SparsedMatrix::clear() {
    for (unsigned int i = dimensions.row; i >= 1; --i)
        for (unsigned int j = dimensions.column; j >= 1; --j)
            deleteElementQuietly(i, j);
    nonNullableElementsQuantity = 0;
}

bool SparsedMatrix::empty() const {
    return nonNullableElementsQuantity == 0;
}

bool SparsedMatrix::full() const {
    return nonNullableElementsQuantity == dimensions.row * dimensions.column;
}

std::pair<unsigned int, unsigned int> SparsedMatrix::getDimensions() const {
    return std::make_pair(dimensions.row, dimensions.column);
}

void SparsedMatrix::insert(int value, unsigned int row, unsigned int column) {
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

void SparsedMatrix::insertQuietly(int value, unsigned int row, unsigned int column) {
    if (value == 0 || this->full() || !isRequestCompatibleWithDimension(row, column)
            || pointAtPosition(row, column) != nullptr)
        return;
    insertValue(value, row, column);
}

void SparsedMatrix::insertOverlaping(int value, unsigned int row, unsigned int column) {
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

void SparsedMatrix::insertQuietlyOverlaping(int value, unsigned int row, unsigned int column) {
    if (value == 0 || !isRequestCompatibleWithDimension(row, column))
        return;
    MatrixPointer pointer = pointAtPosition(row, column);
    if (pointer != nullptr)
        pointer->entry = value;
    else
        insertValue(value, row, column);
}

void SparsedMatrix::insertValue(int value, unsigned int row, unsigned int column) {
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

bool SparsedMatrix::isRequestCompatibleWithDimension(unsigned int row, unsigned int column) const {
    return row > 0 && row <= dimensions.row && column > 0 && column <= dimensions.column;
}

SparsedMatrix::MatrixPointer SparsedMatrix::pointAtPosition(unsigned int row, unsigned int column) const {
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

SparsedMatrix::MatrixPointer SparsedMatrix::setPointerToPreviousInRow(unsigned int row, unsigned int column) const {
    MatrixPointer previousInRow = rows[row];
    if (previousInRow == nullptr || previousInRow->nextCol == nullptr)
        return previousInRow;
    while (previousInRow->column < column && previousInRow->nextCol != nullptr && previousInRow->nextCol->column < column)
        previousInRow = previousInRow->nextCol;
    return previousInRow;
}

SparsedMatrix::MatrixPointer SparsedMatrix::setPointerToPreviousInColumn(unsigned int row, unsigned int column) const {
    MatrixPointer previousInColumn = columns[column];
    if (previousInColumn == nullptr || previousInColumn->nextRow == nullptr)
        return previousInColumn;
    while (previousInColumn->row < row && previousInColumn->nextRow != nullptr && previousInColumn->nextRow->row < row)
        previousInColumn = previousInColumn->nextRow;
    return previousInColumn;
}

void SparsedMatrix::deleteElement(unsigned int row, unsigned int column) {
    if (!isRequestCompatibleWithDimension(row, column))
        throw std::out_of_range("Posicao indisponivel para remocao!");
    if (this->empty())
        throw std::out_of_range("Matriz vazia!");
    MatrixPointer pointer = pointAtPosition(row, column);
    if (pointer == nullptr)
        throw std::out_of_range("Posicao nao ocupada na matriz!");
    deleteAtPosition(pointer, row, column);
}

void SparsedMatrix::deleteElementQuietly(unsigned int row, unsigned int column) {
    if (!isRequestCompatibleWithDimension(row, column) || this->empty())
        return;
    MatrixPointer pointer = pointAtPosition(row, column);
    if (pointer == nullptr)
        return;
    deleteAtPosition(pointer, row, column);
}

void SparsedMatrix::deleteAtPosition(MatrixPointer& pointer, unsigned int row, unsigned int column) {
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

void SparsedMatrix::replace(int value, unsigned int row, unsigned int column) {
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

void SparsedMatrix::replaceQuietly(int value, unsigned int row, unsigned int column) {
    if (value == 0 || !isRequestCompatibleWithDimension(row, column) || this->empty())
        return;
    MatrixPointer pointer = pointAtPosition(row, column);
    if (pointer == nullptr)
        return;
    pointer->entry = value;
}

int SparsedMatrix::getValue(unsigned int row, unsigned int column) const {
    if (this->empty())
        throw std::out_of_range("Matriz vazia!");
    if (!isRequestCompatibleWithDimension(row, column))
        throw std::out_of_range("Posicao indisponivel para busca!");
    MatrixPointer pointer = pointAtPosition(row, column);
    if (pointer == nullptr)
        throw std::out_of_range("Posicao nao ocupada na matriz!");
    return pointer->entry;
}

int* SparsedMatrix::getRow(unsigned int row) const {
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

int* SparsedMatrix::getColumn(unsigned int column) const {
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

void SparsedMatrix::forEachElement(const std::function<void(int, unsigned int, unsigned int)>& process) {
    for (unsigned int iterableRow = 1; iterableRow <= dimensions.row; ++iterableRow) {
        for (unsigned int iterableColumn = 1; iterableColumn <= dimensions.column; ++iterableColumn) {
            MatrixPointer pointer = pointAtPosition(iterableRow, iterableColumn);
            int value = pointer != nullptr ? pointer->entry : 0;
            process(value, iterableRow, iterableColumn);
        }
    }
}