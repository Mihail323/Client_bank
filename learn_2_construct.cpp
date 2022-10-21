
#include <iostream>
#include <cmath>
#include <windows.h>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;
class Client_bank
{
private:
    string Name;
    double money;
    double rate;
    int time;
public:
    void set(double m = 0, double r= 0, int t = 0)
    {
        money = m;
        rate = r;
        time = t;
    }
    void setName(string N)
    {
        Name = N;
    }
    double result()
    {
        return money * pow((1 + rate / 100), time);
    }
    void show() 
    {
        cout << "Информация по вкладчику:" << endl;
        cout << "Имя: " << Name << endl;
        cout << "Сумма вклада: " << money << " руб" << endl;
        cout << "Ставка: " << rate << " руб" << endl;
        cout << "Срок вклада: " << time << " лет" << endl;
        cout << "Итоговая сумма депозита: " << result() << " руб" << "\n" << endl;
    }
    Client_bank(string N) {
        setName(N);
        set();
        show();
    }
    Client_bank(string N, double m, double r, int t) {
        setName(N);
        set(m, r, t);
        show();
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Client_bank Ivanov("Иванов");
    Client_bank Petrov("Петров", 10000, 6, 6);
    system("pause");
    return 0;
}
