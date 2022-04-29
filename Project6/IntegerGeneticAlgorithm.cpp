#include "Math.h"
#include <ctime>
#include <iostream>
#include "MyForm.h"
//float* SrPoints = new float[1000];
//float* MinPoints = new float[1000];
//int k = 1;
//int popsize=1000, numiter=20;
//double СutOff_threshold=50, Pro_mut=50, Pro_cros=90;


class individual //Класс "Особь", содержащий массив генов
{
public:
    double X, fitness; // X - Хромосома, fitness- значение приспобленности
    individual()
    {
        X = (rand() % 1000) * 0.01 - (rand() % 1000) * 0.01;// случайная генерациия гена
    };

};

class Population //Класс "Популяция",содержащий массив объектов класса "Особь"
{
    int size;
    individual* Array;
public:
    Population()
    {
        size = 1000;
        Array = new individual[size];
    }
    Population(int n)
    {
        size = n;
        Array = new individual[size];
    }

    individual& operator[](int n) // перегрузка оператора индексирования
    {                             // для доступа к элементам через индекс
        return Array[n];
    }

};

class GeneticAlgorithm // управляющий класс для целочисленного кодирования
{
    int size; //начальный размер популяции
    int sizeN; //размер популяции, который будет изменяться во время работы программы
    Population A; //Формирование популяции
public:
    int numiter;
    double СutOff_threshold, Pro_mut, Pro_cros;
    GeneticAlgorithm(int n)
    {
        size = n;
        int sizeN = size;
        Population A(n);
    }


    individual GenAlgorithm()
    {
        for (int i = 0; i < numiter; i++) // Количество итераций
        {
            Assessment(); //Метод, выполняющий рассчет приспособленности и сортировку по значению оценочной функции 
            //Grafic(); // для графика
            TruncSelection(); //Метод, благодаря которому осуществляется отбор особей
            Crossbreeding(); //Метод, который реализует скрещивание особей
            Mutation(); //Метод, отвечающий за мутацию

            if (fabs(A[0].fitness - A[sizeN - 1].fitness) <= 0.001) break; // проверка на вырожденную популяцию
        }
        return A[0];
    }

    double func(double x)// возвращает значение функции от заданного аргумента
    {
        return x * x + 4; // оценочная функция
    }

    /*void Grafic()// нахождение минимального значения и среднего значения функции по итерациям
    {
        float sum = 0;
        float min = 99999;
        for (int i = 0; i < sizeN; i++)
        {
            sum += func(A[i].X);
            if (min > func(A[i].X)) min = func(A[i].X);
        }
        sum = sum / sizeN;
        SrPoints[k] = sum;
        MinPoints[k] = min;
        k++;
    }*/

    void Assessment()
    {
        int h;
        for (int i = 0; i < sizeN; i++) // рассчет оценочной функции(приспобленности)
            A[i].fitness = func(A[i].X);
        for (h = 1; h <= sizeN / 9; h = h * 3 + 1); //сортировка Шелла (Индекс у более приспобленных меньше)
        while (h >= 1)
        {
            for (int i = h; i < sizeN; i++)
                for (int j = i - h; (j >= 0) && (A[j].fitness > A[j + h].fitness); j -= h)
                {
                    individual temp = A[j];
                    A[j] = A[j + h];
                    A[j + h] = temp;
                }
            h = (h - 1) / 3;
        }
    }

    void TruncSelection()// селекция усечением
    {
        double l =  СutOff_threshold / 100; //порог отсечения
        for (int i = size - 1; i > (l * size); i--) //удаляем наименее приспособленные особи
        {
            A[i].X = NULL;
            A[i].fitness = NULL;
            sizeN--;
        }
    }

    void Crossbreeding() // Метод, осуществляющий арифметический кроссинговер
    {
        int Size = sizeN;
        double p = Pro_cros / 100; //Вероятность скрещивания
        while (sizeN < size) //цикл будет до тех пор, пока число особей не вернется к первоначальному количеству
        {
            int i = (int)(rand() % Size);
            int j = (int)(rand() % Size);
            double L = rand() % 100 * 0.01;
            if (p > (rand() % 100) * 0.01)
            {
                A[sizeN++].X = L * A[i].X + (1 - L) * A[j].X;
            }
        }
        sizeN--;
    }

    void Mutation()
    {
        double mut = Pro_mut / 100; //вероятность мутации
        for (int i = 0; i < sizeN; i++)
        {
            if (mut > rand() % 100 * 0.01)
            {
                A[i].X += (rand() % 50) * 0.01 - (rand() % 50) * 0.01;
            }
        }
    }
};