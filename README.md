# Лабораторная работа №3

## Задача:
Модифицировать программу из л/р №1 для параллельной работы по технологии MPI и запустить на суперкомпьютере «Сергей Королёв»

## Файлы:
1. Файлы с исходными матрицами - `matrix_NxN.txt`, `matrix_NxN_1.txt`
3. График (Python) - `mpi.ipynb`
4. Умножение матриц и подсчет времени (С++) - `pp3.cpp`

## Отчет о работе на суперкомпьютере:
1) startMPI.pbs - 2 потока

![image](https://github.com/DianaRyz/parallel_programming_3/assets/114705840/7c23eb17-72c0-4b29-863d-cf112fc969de)

2) startMPI_3.pbs - 3 потока

![image](https://github.com/DianaRyz/parallel_programming_3/assets/114705840/94733c6a-2783-4108-9968-238ed1ac915b)

3) startMPI_4.pbs - 4 потока

![image](https://github.com/DianaRyz/parallel_programming_3/assets/114705840/905225f1-b87c-4602-ba61-f1b3ecb55248)

4) startMPI_8.pbs - 8 потоков

![image](https://github.com/DianaRyz/parallel_programming_3/assets/114705840/a7792e6a-10ad-4ce2-964f-bfe85873ccb9)

5) slurm-93946.out - 2 потока

![image](https://github.com/DianaRyz/parallel_programming_3/assets/114705840/a4dee6ca-e772-4d5e-bdea-29edfe5e1038)

6) slurm-93947.out - 3 потока

![image](https://github.com/DianaRyz/parallel_programming_3/assets/114705840/071362e9-715f-4025-a312-9cf95aef338e)

7) slurm-93949.out - 4 потока

![image](https://github.com/DianaRyz/parallel_programming_3/assets/114705840/d2ecb550-5d34-4805-9436-1c81d64cb85c)

8) slurm-93950.out - 8 потоков

![image](https://github.com/DianaRyz/parallel_programming_3/assets/114705840/94f01f86-7ac5-498c-8079-8837f666dccd)

## График:
![image](https://github.com/DianaRyz/parallel_programming_3/assets/114705840/f480862c-880d-4727-9415-a33269383a08)

## Выводы:
MPI позволяет ускорить исследуемую операцию, так как каждый поток работает над своей частью результирующей матрицы, что позволяет эффективнее использовать вычислительные ресурсы и уменьшить время выполнения операции.
