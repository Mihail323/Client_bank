
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

    double findValue(double m, double r, int t)
    {
        return m * pow((1 + r / 100), t);
    }
    double result()
    {
        return findValue(money, rate, time);
    }
    double result(double m, int t)
    {
        double m1, m2;
        m1 = findValue(money, rate, time);
        if (t > time)
        {
            return m1;
        }
        else
        {
            m2= findValue(m, rate, time-t);
            return m1 + m2;
        }
    }
    void showTable(bool style=false)
    {
        cout << "| Name\t\t|" << " Sum\t|"<<" Time\t|";
        if (style)
        {
            cout << " ADSum\t|" << " Time\t|";
        }
        cout << " Rate\t|" << " Total sum\t|" << endl;
    }
    void showData()
    {
        cout << "| " << Name << "\t|";
        cout << " " << money << "\t|";
        cout << " " << time << "\t|";
        cout << " " << rate << "\t|";
        cout << " " << result() << "\t|\n" << endl;
    }
    void showData(double m, int t)
    {
        cout << "| " << Name << "\t|";
        cout << " " << money << "\t|";
        cout << " " << time << "\t|";
        cout << " " << m << "\t|";
        cout << " " << time-t << "\t|";
        cout << " " << rate << "\t|";
        cout << " " << result(m, t) << "\t|\n" << endl;
    }
    
public:
    void setAll(string N,double m, double r, int t)
    {
        Name = N;
        money = m;
        rate = r;
        time = t;
    }
    void setAll(string N)
    {
        setAll(N, 100, 13, 3);
    }
    void show(double m,int t) 
    {
        showTable(true);
        showData(m, t);
    }
    void show(double m)
    {
        show(m, 1);
    }
    void show()
    {
        showTable();
        showData();
    }
    Client_bank(string N) 
    {
        setAll(N);
        show();
    }
    Client_bank(string N, double m, double r, int t) 
    {
        setAll(N, m, r, t);
        show();
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Client_bank Ivanov("Иванов И.И.");
    Ivanov.show(30, 2);
    Ivanov.show(29);
    Client_bank Petrov("Петров П.П.", 90, 18, 4);
    Petrov.setAll("Сидоров С.С.");
    Petrov.show();
    Petrov.show(50,5);
    system("pause");
    return 0;
}
        