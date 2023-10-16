#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> createMatrix(double x, double y)
{
    vector<double> matrix;
    matrix.push_back(x);
    matrix.push_back(y);
    return matrix;
}
void displyMatrix(vector<double> &ptr)
{
    cout << "X - " << ptr[0] << " Y - " << ptr[1] << endl;
}
vector<double> addMatrix(vector<double> &ptrMtrx, vector<double> &ptrMtrx2)
{
    vector<double> rez;
    for (int i = 0; i < ptrMtrx.size(); i++)
    {
        rez.push_back(ptrMtrx[i] + ptrMtrx2[i]);
    }
    return rez;
}
vector<double> subMatrix(vector<double> &ptrMtrx, vector<double> &ptrMtrx2)
{
    vector<double> rez;
    for (int i = 0; i < ptrMtrx.size(); i++)
    {
        rez.push_back(ptrMtrx[i] - ptrMtrx2[i]);
    }
    return rez;
}
vector<double> scaleMatrix(vector<double> &ptrMtrx, int sParam)
{
    vector<double> rez;
    for (int i = 0; i < ptrMtrx.size(); i++)
    {
        rez.push_back(ptrMtrx[i] * sParam);
    }
    return rez;
}
double lengthMatrix(vector<double> &ptrMtrx)
{
    double rez;
    rez = sqrt(pow(ptrMtrx[0], 2) + pow(ptrMtrx[1], 2));
    return rez;
}
vector<double> normMatrix(vector<double> &ptrMtrx)
{
    double length = lengthMatrix(ptrMtrx);
    vector<double> rez;
    for (int i = 0; i < ptrMtrx.size(); i++)
    {
        rez.push_back(ptrMtrx[i] * length);
    }
    return rez;
}

int main()
{
    double x;
    double y;

    vector<double> mtrx;
    vector<double> &ptrMtrx = mtrx;
    cout << "Задайте координаты двухмерного вектора числами с плавающей точкой x и y: ";
    cin >> x >> y;

    mtrx = createMatrix(x, y);
    cout << "Вектор - ";
    displyMatrix(mtrx);

    int choice;
    cout << "Выбор операции над двумерным вектором" << endl;
    vector<double> add;
    vector<double> subtract;
    vector<double> scale;
    double length;
    vector<double> normalize;

    while (true)
    {
        cout << "1-сложение двух векторов, 2-вычитание двух векторов, \n3 - умножение вектора на скаляр, 4 - нахождение длины вектора, 5 - нормализация вектора, 0 - выход" << endl;
        cin >> choice;
        if (choice == 1)
        {
            double x2;
            double y2;
            vector<double> mtrx2;
            vector<double> &ptrMtrx2 = mtrx2;
            cout << "Задайте координаты двухмерного вектора числами с плавающей точкой x и y для сложения: ";
            cin >> x2 >> y2;
            mtrx2 = createMatrix(x2, y2);
            add = addMatrix(ptrMtrx, ptrMtrx2);
            cout << "Результат сложения " << endl;
            displyMatrix(add);
        }
        else if (choice == 2)
        {
            double x2;
            double y2;
            vector<double> mtrx3;
            vector<double> &ptrMtrx3 = mtrx3;
            cout << "Задайте координаты двухмерного вектора числами с плавающей точкой x и y для вычетания: ";
            cin >> x2 >> y2;
            mtrx3 = createMatrix(x2, y2);

            subtract = subMatrix(ptrMtrx, ptrMtrx3);
            cout << "Результат вычитания " << endl;
            displyMatrix(subtract);
        }
        else if (choice == 3)
        {
            int scaleParam;
            cout << "Введите значение скаляра ->";
            cin >> scaleParam;
            scale = scaleMatrix(ptrMtrx, scaleParam);
            cout << "Результат умножения на скаляр " << endl;
            displyMatrix(scale);
        }
        else if (choice == 4)
        {
            length = lengthMatrix(ptrMtrx);
            cout << "Результат определения длины " << length << endl;
        }
        else if (choice == 5)
        {
            normalize = normMatrix(ptrMtrx);
            cout << "Результат нормализации " << endl;
            displyMatrix(normalize);
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "Введено не предусмотренное программой значение. Повторите ввод.";
        }
    }
}
