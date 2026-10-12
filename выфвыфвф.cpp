
#include <iostream>
#include <string>
using namespace std;

class Reservoir
{
private:
    string nazvanie;
    double shirina, dlina, glubina;
    string tip;

public:
    static int Count;

    Reservoir()
    {
        nazvanie = "Net";
        shirina = 0;
        dlina = 0;
        glubina = 0;
        tip = "Net";
        Count++;
    }

    Reservoir(string n, double sh, double d, double g, string t)
    {
        nazvanie = n;
        shirina = sh;
        dlina = d;
        glubina = g;
        tip = t;
        Count++;
    }

    double ploshad()
    {
        return shirina * dlina;
    }

    double obem()
    {
        return shirina * dlina * glubina;
    }

    void sravnit(Reservoir v)
    {
        if (tip != v.tip)
            cout << "Raznye tipy!" << endl;
        else if (ploshad() > v.ploshad())
            cout << nazvanie << " bolshe." << endl;
        else if (ploshad() < v.ploshad())
            cout << v.nazvanie << " bolshe." << endl;
        else
            cout << "Ploshadi ravny." << endl;
    }

    void pokazat()
    {
        cout << "Nazvanie: " << nazvanie << endl;
        cout << "Tip: " << tip << endl;
        cout << "Ploshad: " << ploshad() << " m2" << endl;
        cout << "Obem: " << obem() << " m3" << endl;
    }
};

int Reservoir::Count = 0;

int main()
{
    setlocale(LC_ALL, "Russian");

    Reservoir v1, v2;
    int vybor;

    do
    {
        cout << "\n1. Sozdat vodoem 1" << endl;
        cout << "2. Sozdat vodoem 2" << endl;
        cout << "3. Pokazat vodoem 1" << endl;
        cout << "4. Pokazat vodoem 2" << endl;
        cout << "5. Sravnit ploshadi" << endl;
        cout << "6. Kolichestvo obektov" << endl;
        cout << "0. Vyhod" << endl;
        cin >> vybor;

        if (vybor == 1 || vybor == 2)
        {
            string n, t;
            double sh, d, g;

            cout << "Nazvanie: ";
            cin >> n;
            cout << "Tip: ";
            cin >> t;
            cout << "Shirina: ";
            cin >> sh;
            cout << "Dlina: ";
            cin >> d;
            cout << "Glubina: ";
            cin >> g;

            if (sh <= 0 || d <= 0 || g <= 0)
                cout << "Oshibka razmerov!" << endl;
            else if (vybor == 1)
                v1 = Reservoir(n, sh, d, g, t);
            else
                v2 = Reservoir(n, sh, d, g, t);
        }
        else if (vybor == 3)
            v1.pokazat();
        else if (vybor == 4)
            v2.pokazat();
        else if (vybor == 5)
            v1.sravnit(v2);
        else if (vybor == 6)
            cout << "Kolichestvo: " << Reservoir::Count << endl;

    } while (vybor != 0);

    return 0;
}
