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

int Pop_Size, Num; // ������ ���������, ��������
double �utOff_Threshold, Pro_Mut, Pro_Cros; // ����� ���������, ����������� �������, ����������� �����������
float* SrPoints = new float[1000]; // ������, ���������� ������� �������� � ������ ���������
float* MinPoints = new float[1000]; // ������, ���������� ����������� �������� � ������ ���������
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


// ������������ �������� ��� �������������� �����������

class individual //����� "�����", ���������� �������� ��������������� ��� � �������� ���������������
{
public:
    double X, fitness; // X - ���������, fitness- �������� ���������������
    individual()
    {
        X = (rand() % 1000) * 0.1 - (rand() % 1000) * 0.1;// ��������� ���������� ����
    };
    ~individual() // ����������
    {

    };
};

class Population //����� "���������",���������� ������ �������� ������ "�����"
{
    int size;
    individual* Array;
public:

    Population(int n) // ����������� � ���������� n
    {
        size = n;
        Array = new individual[size];
    }

    individual& operator[](int n) // ���������� ��������� ��������������
    {                             // ��� ������� � ��������� ����� ������
        return Array[n];
    }
    ~Population() // ����������
    {
        delete[] Array;
    }
};
void Clear() // ��� ���������� ������ ���������, �� ��������������
{
    for (int i = 0; i < 1000; i++) {
        SrPoints[i] = 0;
        MinPoints[i] = 99999;
    }
    k = 0;
}

class GeneticAlgorithm // ����������� ����� ��� �������������� �����������
{
    int size= Pop_Size;; //��������� ������ ���������
    int sizeN= size;; //������ ���������, ������� ����� ���������� �� ����� ������ ���������
    Population A= Population(size);; //������������ ���������
public:

    individual GenAlgorithm()
    {
        for (int i = 0; i < Num; i++) // ���������� ��������
        {
            Assessment(); //�����, ����������� ������� ����������������� � ���������� �� �������� ��������� ������� 
            Grafic(); // ��� �������
            TruncSelection(); //�����, ��������� �������� �������������� ����� ������
            Crossbreeding(); //�����, ������� ��������� ����������� ������
            Mutation(); //�����, ���������� �� �������

            if (fabs(A[0].fitness - A[sizeN - 1].fitness) <= 0.001) break; // �������� �� ����������� ���������
        }
        return A[0];
    }

    ~GeneticAlgorithm()
    {

    }

    double func(double x)// ���������� �������� ������� �� ��������� ���������
    {
        return x * x + 4; // ��������� �������
    }

    void Grafic()// ���������� ������������ �������� � �������� �������� ������� �� ���������
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
        double l = �utOff_Threshold / 100; //����� ���������
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
        double p = Pro_Cros / 100; //����������� �����������
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
        double mut = Pro_Mut / 100; //����������� �������
        for (int i = 0; i < sizeN; i++)
        {
            if (mut > rand() % 100 * 0.01)
            {
                A[i].X += (rand() % 50) * 0.01 - (rand() % 50) * 0.01;
            }
        }
    }
};


// ������������ �������� ��� ������������� �����������

class RealIndividual
{
    int xmin = -10;
    int xmax = 10;
public:
    double X, fitness; // X - ���������, fitness- �������� ���������������
    bool* string;
    int size = 10;//�����������
    RealIndividual()
    {
        string = new bool[size];
        for (int i = 0; i < size; i++)
        {
            string[i] = rand() % 2; // ��������� ���������� ����
        }
    };

    void decode() //����� ������������� decode, 
    {             //��� �������� ��������������� ��������� �������� ���� � �������;
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

class RealPopulation //����� "���������",���������� ������ �������� ������ "�����"
{
    int size;
    RealIndividual* Array;
public:
    RealPopulation(int n)
    {
        size = n;
        Array = new RealIndividual[size];
    }

    RealIndividual& operator[](int n)// ���������� ��������� ��������������
    {                             // ��� ������� � ��������� ����� ������
        return Array[n];
    }
};


class RealGeneticAlgorithm
{
    int size = Pop_Size;
    int sizeN = size; //������ ���������, ������� ����� ���������� �� ����� ������ ���������
    RealPopulation A = RealPopulation(size); //������������ ���������
public:


    RealIndividual Algorithm() //�������� ��������
    {
        int i;
        for (i = 0; i < Num; i++) // ���������� ��������
        {

            RealCrossing(); //�����, ������� ��������� ����������� ������  
            Grafic(); // ��� �������
            RealMutation(); //�����, ���������� �� �������
            RealAssessment(); //�����, ����������� ������� ����������������� � ���������� �� �������� ��������� ������� 
            RealTruncSelection(); //�����, �������������� ����� ������

            if (abs(A[0].fitness - A[sizeN].fitness) <= 0.001) break; // �������� �� ����������� ���������
        }
        return A[0];
    }

    double func(double x) // ���������� �������� ������� �� ��������� ���������
    {
        return x * x + 4;
    }

    void Grafic()// ���������� ������������ �������� � �������� �������� ������� �� ���������
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
            A[i].fitness = func(A[i].X);  // ������� ��������� �������(���������������)
        for (h = 1; h <= sizeN / 9; h = h * 3 + 1); //���������� �����
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
        double l = �utOff_Threshold / 100; //����� ���������
        for (int i = size - 1; i > (l * size); i--) //������� �������� ��������������� �����
        {
            for (int j = 0; j < 10; j++)
            {
                A[i].string[j] = 0;
            }
            A[i].decode();
            sizeN--;
        }
    }

    void RealCrossing() // ����������� ������ � ������� 1 - ��������� �������������
    {
        int R = rand() % (10 - 2) + 1;// ��������� ����� �������
        double p = Pro_Cros / 100; //����������� �����������
        int Size = sizeN; //��� ������������ ��������
        while (sizeN < size) //��������������� ���������� ��������
        {
            int i = (int)(rand() % Size);
            int j = (int)(rand() % Size);
            if (p > (rand() % 100) * 0.01) // ����������� �����������
            {
                for (int r = 0; r < R; r++) // ���� �� 1 ����� �������
                {
                    A[sizeN].string[r] = A[i].string[r];
                }
                for (int t = R; t < 10; t++) // ���� ����� 1 ����� �������
                {
                    A[sizeN].string[t] = A[j].string[t];
                }
                A[sizeN].decode();
                sizeN++;
            }
        }
    };

    void RealMutation()// ������� �������
    {
        double mut = Pro_Mut / 100; //����������� �������
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
    Pop_Size = System::Convert::ToInt32(Project6::MyForm::numericUpDown->Value);// ����� ������
    �utOff_Threshold = System::Convert::ToInt32(trackBar1->Value); // ����� ���������
    Pro_Mut = System::Convert::ToInt32(trackBar2->Value); // ����������� �������
    Pro_Cros = System::Convert::ToInt32(trackBar3->Value); // ����������� ����������� 
    Num =  System::Convert::ToInt32(Project6::MyForm::numericUpDown1->Value); // ����� ��������
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
    // �������� ��� ������ ��������� ������� ���������, ��� �������� ������ ��� ��������� �������
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

System::Void Project6::MyForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("� ������ ��������� ��� ���������� ������������ �������� ��� ���������� �������� ������� x^2+4", "'-'");
    return System::Void();
}





System::Void Project6::MyForm::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->chart1->Series[0]->Points->Clear();
    this->chart1->Series[1]->Points->Clear();
}

System::Void Project6::MyForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Created by Xorogaz and ArchangeLL", "'-'");
    Application::Exit();//����� �� ����������
}

float Project6::MyForm::func(float x)
{
    float ret;
    ret = x*x+4; // �������, ��� ������� �������� ������
    return ret;
}



