#include "Math.h"
#include <ctime>
#include <iostream>
#include "MyForm.h"
//float* SrPoints = new float[1000];
//float* MinPoints = new float[1000];
//int k = 1;
//int popsize=1000, numiter=20;
//double �utOff_threshold=50, Pro_mut=50, Pro_cros=90;


class individual //����� "�����", ���������� ������ �����
{
public:
    double X, fitness; // X - ���������, fitness- �������� ���������������
    individual()
    {
        X = (rand() % 1000) * 0.01 - (rand() % 1000) * 0.01;// ��������� ���������� ����
    };

};

class Population //����� "���������",���������� ������ �������� ������ "�����"
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

    individual& operator[](int n) // ���������� ��������� ��������������
    {                             // ��� ������� � ��������� ����� ������
        return Array[n];
    }

};

class GeneticAlgorithm // ����������� ����� ��� �������������� �����������
{
    int size; //��������� ������ ���������
    int sizeN; //������ ���������, ������� ����� ���������� �� ����� ������ ���������
    Population A; //������������ ���������
public:
    int numiter;
    double �utOff_threshold, Pro_mut, Pro_cros;
    GeneticAlgorithm(int n)
    {
        size = n;
        int sizeN = size;
        Population A(n);
    }


    individual GenAlgorithm()
    {
        for (int i = 0; i < numiter; i++) // ���������� ��������
        {
            Assessment(); //�����, ����������� ������� ����������������� � ���������� �� �������� ��������� ������� 
            //Grafic(); // ��� �������
            TruncSelection(); //�����, ��������� �������� �������������� ����� ������
            Crossbreeding(); //�����, ������� ��������� ����������� ������
            Mutation(); //�����, ���������� �� �������

            if (fabs(A[0].fitness - A[sizeN - 1].fitness) <= 0.001) break; // �������� �� ����������� ���������
        }
        return A[0];
    }

    double func(double x)// ���������� �������� ������� �� ��������� ���������
    {
        return x * x + 4; // ��������� �������
    }

    /*void Grafic()// ���������� ������������ �������� � �������� �������� ������� �� ���������
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
        for (int i = 0; i < sizeN; i++) // ������� ��������� �������(���������������)
            A[i].fitness = func(A[i].X);
        for (h = 1; h <= sizeN / 9; h = h * 3 + 1); //���������� ����� (������ � ����� ������������� ������)
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

    void TruncSelection()// �������� ���������
    {
        double l =  �utOff_threshold / 100; //����� ���������
        for (int i = size - 1; i > (l * size); i--) //������� �������� ��������������� �����
        {
            A[i].X = NULL;
            A[i].fitness = NULL;
            sizeN--;
        }
    }

    void Crossbreeding() // �����, �������������� �������������� ������������
    {
        int Size = sizeN;
        double p = Pro_cros / 100; //����������� �����������
        while (sizeN < size) //���� ����� �� ��� ���, ���� ����� ������ �� �������� � ��������������� ����������
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
        double mut = Pro_mut / 100; //����������� �������
        for (int i = 0; i < sizeN; i++)
        {
            if (mut > rand() % 100 * 0.01)
            {
                A[i].X += (rand() % 50) * 0.01 - (rand() % 50) * 0.01;
            }
        }
    }
};