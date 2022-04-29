#include "MyForm.h"
#include "Math.h"
#include "Windows.h"
#include "stdio.h"
#include <ctime>
#include <iostream>
#include <string>
//#include "IntegerGeneticAlgorithm.cpp"
//#include "RealGeneticAlgorithm.cpp"



using namespace System;
using namespace System::Windows::Forms;

int Pop_Size, Num; // размер популяции, итератор
double СutOff_Threshold, Pro_Mut, Pro_Cros; // порог отсечения, вероятность мутации, вероятность скрещивания
float* SrPoints = new float[1000]; // Массив, содержащий Средние значения в каждом поколении
float* MinPoints = new float[1000]; // Массив, содержащий Минимальные значения в каждом поколении
int k = 0;
std::string s;
double eps;



[STAThreadAttribute]

int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project6::MyForm form;
    Application::Run(% form);

}


// ГЕНЕТИЧЕСКИЙ АЛГОРИТМ ДЛЯ ЦЕЛОЧИСЛЕННОГО КОДИРОВАНИЯ

class individual //Класс "Особь", содержащий случайно сгенерированный ген и значение приспобленности
{
public:
    double X, fitness; // X - Хромосома, fitness- значение приспобленности
    individual()
    {
        X = (rand() % 1000) * 0.1 - (rand() % 1000) * 0.1;// случайная генерациия гена
    };
    ~individual() // Деструктор
    {

    };
};

class Population //Класс "Популяция",содержащий массив объектов класса "Особь"
{
    int size;
    individual* Array;
public:

    Population(int n) // конструктор с параметром n
    {
        size = n;
        Array = new individual[size];
    }

    individual& operator[](int n) // перегрузка оператора индексирования
    {                             // для доступа к элементам через индекс
        return Array[n];
    }
    ~Population() // Деструктор
    {
        delete[] Array;
    }
};
void Clear() // для корректной работы программы, не оптимизировано
{
    for (int i = 0; i < 1000; i++) {
        SrPoints[i] = 0;
        MinPoints[i] = 99999;
    }
    k = 0;
}

class GeneticAlgorithm // управляющий класс для целочисленного кодирования
{
    int size= Pop_Size;; //начальный размер популяции
    int sizeN= size;; //размер популяции, который будет изменяться во время работы программы
    Population A= Population(size);; //Формирование популяции
public:

    individual GenAlgorithm()
    {
        for (int i = 0; i < Num; i++) // Количество итераций
        {
            Assessment(); //Метод, выполняющий рассчет приспособленности и сортировку по значению оценочной функции 
            Grafic(); // для графика
            TruncSelection(); //Метод, благодаря которому осуществляется отбор особей
            Crossbreeding(); //Метод, который реализует скрещивание особей
            Mutation(); //Метод, отвечающий за мутацию

            if (fabs(A[0].fitness - A[sizeN - 1].fitness) <= 0.001) break; // проверка на вырожденную популяцию
        }
        return A[0];
    }

    ~GeneticAlgorithm()
    {

    }

    double func(double x)// возвращает значение функции от заданного аргумента
    {
        return x * x + 4; // оценочная функция
    }

    void Grafic()// нахождение минимального значения и среднего значения функции по итерациям
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
    }

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
        double l = СutOff_Threshold / 100; //порог отсечения
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
        double p = Pro_Cros / 100; //Вероятность скрещивания
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
        double mut = Pro_Mut / 100; //вероятность мутации
        for (int i = 0; i < sizeN; i++)
        {
            if (mut > rand() % 100 * 0.01)
            {
                A[i].X += (rand() % 50) * 0.01 - (rand() % 50) * 0.01;
            }
        }
    }
};


// ГЕНЕТИЧЕСКИЙ АЛГОРИТМ ДЛЯ ВЕЩЕСТВЕННОГО КОДИРОВАНИЯ

class RealIndividual
{
    int xmin = -10;
    int xmax = 10;
public:
    double X, fitness; // X - Хромосома, fitness- значение приспобленности
    bool* string;
    int size = 10;//разрядность
    RealIndividual()
    {
        string = new bool[size];
        for (int i = 0; i < size; i++)
        {
            string[i] = rand() % 2; // случайная генерациия гена
        }
    };

    void decode() //метод декодирования decode, 
    {             //для перевода закодированного двоичного значения гена в дробное;
        double value = 0.0; double discharge = 1;
        for (int j = size - 1; j >= 0; j--)
        {
            if (string[j]) value = value + discharge;
            discharge = discharge * 2;
        }
        X = xmin + (xmax - xmin) * value / (discharge - 1);
        fitness = X * X + 4;
    };
};

class RealPopulation //Класс "Популяция",содержащий массив объектов класса "Особь"
{
    int size;
    RealIndividual* Array;
public:
    RealPopulation(int n)
    {
        size = n;
        Array = new RealIndividual[size];
    }

    RealIndividual& operator[](int n)// перегрузка оператора индексирования
    {                             // для доступа к элементам через индекс
        return Array[n];
    }
};


class RealGeneticAlgorithm
{
    int size = Pop_Size;
    int sizeN = size; //размер популяции, который будет изменяться во время работы программы
    RealPopulation A = RealPopulation(size); //формирование популяции
public:


    RealIndividual Algorithm() //Основной алгоритм
    {
        int i;
        for (i = 0; i < Num; i++) // Количество итераций
        {

            RealCrossing(); //Метод, который реализует скрещивание особей  
            Grafic(); // для графика
            RealMutation(); //Метод, отвечающий за мутацию
            RealAssessment(); //Метод, выполняющий рассчет приспособленности и сортировку по значению оценочной функции 
            RealTruncSelection(); //Метод, осуществляющий отбор особей

            if (abs(A[0].fitness - A[sizeN].fitness) <= 0.001) break; // проверка на вырожденную популяцию
        }
        return A[0];
    }

    double func(double x) // возвращает значение функции от заданного аргумента
    {
        return x * x + 4;
    }

    void Grafic()// нахождение минимального значения и среднего значения функции по итерациям
    {
        float sum = 0;
        float min = 99999;
        for (int i = 0; i < sizeN; i++)
        {
            sum += func(A[i].X);
            if (min > func(A[i].X)) min = func(A[i].X);
            s = A[i].X;
        }
        sum = sum / sizeN;
        SrPoints[k] = sum;
        MinPoints[k] = min;
        k++;
    }

    void RealAssessment()
    {
        int h;
        for (int i = 0; i < sizeN; i++)
            A[i].fitness = func(A[i].X);  // рассчет оценочной функции(приспобленности)
        for (h = 1; h <= sizeN / 9; h = h * 3 + 1); //сортировка Шелла
        while (h >= 1)
        {
            for (int i = h; i < sizeN; i++)
                for (int j = i - h; j >= 0 && A[j].fitness > A[j + h].fitness; j -= h)
                {
                    RealIndividual temp = A[j];
                    A[j] = A[j + h];
                    A[j + h] = temp;
                }
            h = (h - 1) / 3;
        }
    }

    void RealTruncSelection()
    {
        double l = СutOff_Threshold / 100; //порог отсечения
        for (int i = size - 1; i > (l * size); i--) //удаляет наименее приспособленные особи
        {
            for (int j = 0; j < 10; j++)
            {
                A[i].string[j] = 0;
            }
            A[i].decode();
            sizeN--;
        }
    }

    void RealCrossing() // Скрещивание особей с помощью 1 - точечного кроссинговера
    {
        int R = rand() % (10 - 2) + 1;// случайная точка разрыва
        double p = Pro_Cros / 100; //Вероятность скрещивания
        int Size = sizeN; //Для формирования потомков
        while (sizeN < size) //Восстанавливаем количество потомков
        {
            int i = (int)(rand() % Size);
            int j = (int)(rand() % Size);
            if (p > (rand() % 100) * 0.01) // вероятность скрещивания
            {
                for (int r = 0; r < R; r++) // гены до 1 точки разрыва
                {
                    A[sizeN].string[r] = A[i].string[r];
                }
                for (int t = R; t < 10; t++) // гены после 1 точки разрыва
                {
                    A[sizeN].string[t] = A[j].string[t];
                }
                A[sizeN].decode();
                sizeN++;
            }
        }
    };

    void RealMutation()// битовая мутация
    {
        double mut = Pro_Mut / 100; //вероятность мутации
        for (int i = 0; i < sizeN; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (mut > rand() % 100 * 0.01)
                {
                    A[i].string[j] = !A[i].string[j];
                }
            }
            A[i].decode();
        }
    };

};

System::Void Project6::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}




System::Void Project6::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    Pop_Size = System::Convert::ToInt32(Project6::MyForm::numericUpDown->Value);// число особей
    СutOff_Threshold = System::Convert::ToInt32(trackBar1->Value); // порог отсечения
    Pro_Mut = System::Convert::ToInt32(trackBar2->Value); // вероятность мутации
    Pro_Cros = System::Convert::ToInt32(trackBar3->Value); // вероятность скрещивания 
    Num =  System::Convert::ToInt32(Project6::MyForm::numericUpDown1->Value); // число итераций
	if (radioButton1->Checked)
	{
       srand(time(0));
       Clear();
       GeneticAlgorithm GA;
       individual result = GA.GenAlgorithm();
       label15->Text = System::Convert::ToString(result.X);
       label16->Text = System::Convert::ToString(result.fitness);

	}
    if (radioButton2->Checked)
    {

        srand(time(0));
        Clear();
        RealGeneticAlgorithm RGA;
        RealIndividual result = RGA.Algorithm();
        label15->Text = System::Convert::ToString(result.X);
        label16->Text = System::Convert::ToString(result.fitness);
    }
}


System::Void Project6::MyForm::trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    label6->Text = System::Convert::ToString(trackBar2->Value)+" %";
}

System::Void Project6::MyForm::trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    label7->Text = System::Convert::ToString(trackBar1->Value) + " %";
}

System::Void Project6::MyForm::trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    label12->Text = System::Convert::ToString(trackBar3->Value) + " %";
}

System::Void Project6::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    int i = 0;
    // Значения при первых итерациях слишком маленькие, что вызывает ошибку при рисовании графика
    if (radioButton1->Checked)
    {
        a = 2;
        x = a;
    }
    if (radioButton2->Checked)
    {
        a = 2;
        x = a;
        i = 1;
    }
    b = System::Convert::ToInt32(Project6::MyForm::numericUpDown1->Value);
    h = 1;
    this->chart1->Series[0]->Points->Clear();
    this->chart1->Series[1]->Points->Clear();  
    while (x <= b)
    {
        y = round(SrPoints[i] * 100) / 100;
        y1 = round(MinPoints[i] * 100) / 100;
        this->chart1->Refresh();
        this->chart1->Series[0]->Points->AddXY(x, y);
        this->chart1->ChartAreas[0]->AxisY->Maximum = System::Convert::ToInt32(Project6::MyForm::textBox1->Text);
        this->chart1->ChartAreas[0]->AxisY->Minimum = System::Convert::ToInt32(Project6::MyForm::textBox2->Text);

        this->chart1->Series[1]->Points->AddXY(x, y1);
        x += h;
        i++;
    }

    return System::Void();
}

System::Void Project6::MyForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("В данной программе был реализован генетический алгоритм для нахождения минимума функции x^2+4", "'-'");
    return System::Void();
}





System::Void Project6::MyForm::обновитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->chart1->Series[0]->Points->Clear();
    this->chart1->Series[1]->Points->Clear();
}

System::Void Project6::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Created by Xorogaz and ArchangeLL", "'-'");
    Application::Exit();//Выход из приложения
}

float Project6::MyForm::func(float x)
{
    float ret;
    ret = x*x+4; // функция, для которой строится график
    return ret;
}



