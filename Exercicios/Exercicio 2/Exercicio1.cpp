/**
 * @brief Utilização de uma função de swap para trocar valores de dois ponteiros.
 *
 * @author Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
 * @date 08/08/2023
 */

void swap(void**, void**);

int main() {
    void* left = new int[0];
    void* right = new int [0];
    swap(&left, &right);
}

void swap(void** left, void** right) {
    void* temp = *left;
    *left = *right;
    *right = temp;
}