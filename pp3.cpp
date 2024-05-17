#include <iostream>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    const char* path_1 = "matrix_500x500.txt";
    const char* path_2 = "matrix_500x500_1.txt";

    double start, stop;
    int rows;
    int N = 500;  
    int rank, numprocs;

    if (argc > 1) {
        path_1 = argv[1];
        path_2 = argv[2];
        N = atoi(argv[3]);
    }

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    rows = N / numprocs;
    int extra = N % numprocs;

    int* matrixA = nullptr;
    int* matrixB = (int*)malloc(sizeof(int) * N * N);
    int* buffer = (int*)malloc(sizeof(int) * N * rows);
    int* result = nullptr;

    if (rank == 0) {
        matrixA = (int*)malloc(sizeof(int) * N * N);
        result = (int*)malloc(sizeof(int) * N * N);

        ifstream fin;
        fin.open(path_1);
        if (fin.is_open()) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    fin >> matrixA[i * N + j];
                }
            }
        }
        fin.close();

        fin.open(path_2);
        if (fin.is_open()) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    fin >> matrixB[i * N + j];
                }
            }
        }
        fin.close();

        start = MPI_Wtime();
    }

    MPI_Bcast(matrixB, N * N, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Scatter(matrixA, rows * N, MPI_INT, buffer, rows * N, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0 && extra > 0) {
        for (int i = numprocs * rows; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result[i * N + j] = 0;
                for (int k = 0; k < N; k++) {
                    result[i * N + j] += matrixA[i * N + k] * matrixB[k * N + j];
                }
            }
        }
    }

    int* matrixC = (int*)malloc(sizeof(int) * rows * N);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < N; ++j) {
            matrixC[i * N + j] = 0;
            for (int k = 0; k < N; k++) {
                matrixC[i * N + j] += buffer[i * N + k] * matrixB[k * N + j];
            }
        }
    }

    MPI_Gather(matrixC, rows * N, MPI_INT, result, rows * N, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        stop = MPI_Wtime();
        cout << "Размер матрицы: " << N << "x" << N << endl;
        cout << "Время выполнения: " << (stop - start) << " секунд" << endl;

        free(matrixA);
        free(result);
    }

    free(matrixB);
    free(buffer);
    free(matrixC);

    MPI_Finalize();

    return 0;
}