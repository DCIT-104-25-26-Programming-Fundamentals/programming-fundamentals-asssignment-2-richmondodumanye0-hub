// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Helper function to print a matrix in a neat grid[cite: 3]
void printMatrix(const int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to read matrix inputs[cite: 3]
void readMatrix(int matrix[10][10], int rows, int cols, string name = "Matrix") {
    cout << "Enter elements for " << name << ":" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// PART A: Transpose a Matrix[cite: 3]
void transposeMatrix() {
    int rows, cols;
    int matrix[10][10], transposed[10][10];

    cout << "\n--- PART A: Transpose Matrix ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, cols, rows);
}

// PART B: Add Two Matrices[cite: 3]
void addMatrices() {
    int rows, cols;
    int matA[10][10], matB[10][10], sum[10][10];

    cout << "\n--- PART B: Add Two Matrices ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matA, rows, cols, "Matrix A");
    readMatrix(matB, rows, cols, "Matrix B");

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum[i][j] = matA[i][j] + matB[i][j];
        }
    }

    cout << "\nSum of Matrices:" << endl;
    printMatrix(sum, rows, cols);
}

// PART C: Multiply Two Matrices[cite: 3]
void multiplyMatrices() {
    int rA, cA, rB, cB;
    int matA[10][10], matB[10][10], product[10][10] = {0};

    cout << "\n--- PART C: Multiply Two Matrices ---" << endl;
    cout << "Enter number of rows for Matrix A: ";
    cin >> rA;
    cout << "Enter number of columns for Matrix A: ";
    cin >> cA;

    cout << "Enter number of rows for Matrix B: ";
    cin >> rB;
    cout << "Enter number of columns for Matrix B: ";
    cin >> cB;

    if (cA != rB) {
        cout << "Error: Columns of Matrix A must equal rows of Matrix B for multiplication." << endl;
        return;
    }

    readMatrix(matA, rA, cA, "Matrix A");
    readMatrix(matB, rB, cB, "Matrix B");

    for (int i = 0; i < rA; ++i) {
        for (int j = 0; j < cB; ++j) {
            product[i][j] = 0;
            for (int k = 0; k < cA; ++k) {
                product[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    cout << "\nProduct Matrix (A x B):" << endl;
    printMatrix(product, rA, cB);
}

int main() {
    transposeMatrix();
    addMatrices();
    multiplyMatrices();
    return 0;
}
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

