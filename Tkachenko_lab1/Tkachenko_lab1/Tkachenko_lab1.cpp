


#include <iostream>
#include <vector>
#include <fstream>



using namespace std;






template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while ((cin >> x).fail() || x<min || x>max)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "Enter number(" << min << "-" << max << "):";
    }
    return x;
}



struct CS
{
    string name;
    double shop;
    double shopr;
    double ef;
};

struct Pipe
{
    double lenght;
    double diametr;
    string repair;
};


bool IsLenghtCorrect(double d)
{
    return d >= 2 && d <= 10000;
}
bool IsDiametrCorrect(double d)
{
    return d >= 2 && d <= 1000;
}

Pipe InputPipe()
{
    Pipe s;
    do
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "lenght:";
        cin >> s.lenght;
    }while (cin.fail() || !IsLenghtCorrect(s.lenght));
    do
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "diametr: ";
        cin >> s.diametr;
    }while (cin.fail() || !IsDiametrCorrect(s.diametr));
    cout << "repair: ";
    cin >> s.repair;
    return s;
}

CS InputCS()
{
    CS c;
    cout << "Name: ";
    cin >> c.name;
    do
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "Shops:";
        cin >> c.shop;
    } while (cin.fail() || !IsLenghtCorrect(c.shop));
    do
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "Repair shops: ";
        cin >> c.shopr;
    } while (cin.fail() || !IsDiametrCorrect(c.shopr));
    do
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "efficiency: ";
        cin >> c.ef;
    } while (cin.fail() || !IsDiametrCorrect(c.ef));
    return c;
}

void PrintPipe(const Pipe& s)
{
    cout << "lenght: " << s.lenght;
    cout << "\tdiametr: " << s.diametr;
    cout << "\trepair: " << s.repair << endl;
}
void PrintCS(const CS& c)
{
    cout << "Name: " << c.name;
    cout << "\tShops: " << c.shop;
    cout << "\tRepair shops: " << c.shopr;
    cout << "\tefficiency:" << c.ef << endl;

}



Pipe LoadPipe()
{
    Pipe s;
    ifstream fin;
    fin.open("data.txt", 'r');
    if (fin.is_open())
    {
        fin >> s.lenght;
        fin >> s.diametr;
        fin >> s.repair;
        fin.close();
    }
    return s;
}


void SavePipe(const Pipe& s)
{
    ofstream fout;
    fout.open("data.txt", 'w');
    if (fout.is_open())
    {
        fout << s.lenght << endl 
             << s.diametr << endl
             << s.repair << endl;
        fout.close();
    }
}


void EditPipe(Pipe& s)
{
    s.diametr -= 0.5;
    s.diametr = IsDiametrCorrect(s.diametr) ? s.diametr:2;
}


void EditCS(CS& c)
{
    c.shop += 1;
    c.shop = IsDiametrCorrect(c.shop) ? c.shop : 2;

}

void PrintMenu()
{
    cout << "1.Input pipe" << endl
        << "2.Input CS" << endl
        << "3.Print" << endl
        << "4.Save to file" << endl
        << "5.Load from file" << endl
        << "6. Edit pipe" << endl
        << "7. Edit CS" << endl
        << "0. Exit" << endl
        << "Choose action:";
}

ostream& operator << (ostream& out,const Pipe& s)
{
    out << "lenght: " << s.lenght
        << "\tdiametr: " << s.diametr
        << "\trepair: " << s.repair << endl;
    return out;
}
istream& operator >> (istream& in, Pipe& s)
{
    cout << "lenght:";
    s.lenght = GetCorrectNumber(2.0, 10000.0);
    cout << "diametr:";
    s.diametr = GetCorrectNumber(2.0, 1000.0);
    cout << "repair: ";
    in >> s.repair;
    return in;
}

ostream& operator << (ostream& out, const CS& c)
{
    out << "Name: " << c.name
        << "\tShops: " << c.shop
        << "\tRepair shops: " << c.shopr
        << "\tefficiency:" << c.ef << endl;
    return out;
}
istream& operator >> (istream& in, CS& c)
{
    cout << "Name: ";
    in >> c.name;
    cout << "Shops: ";
    c.shop = GetCorrectNumber(2.0, 10000.0);
    cout << "Repair shops: ";
    c.shopr = GetCorrectNumber(2.0, 1000.0);
    cout << "efficiency: ";
    c.ef = GetCorrectNumber(2.0, 1000.0);
    return in;
}
int main()
{
    Pipe st;
    CS cs;
    while (1)
    {
        PrintMenu();
        
        switch (GetCorrectNumber(0,7))
        {
        case 1:
        {
            cin >> st;
            break;
        }
        case 2:
        {
            cin >> cs;
            break;
        }
        case 3:
        {
            cout << st << endl;
            cout << cs << endl;
            break;
        }
        case 4:
        {
            SavePipe(st);
            break;
        }
        case 5:
        {
            st = LoadPipe();
            break;
        }
        case 6:
        {
            EditPipe(st);
            break;
        }
        case 7:
        {
            EditCS(cs);
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            cout << "Wrong action" << endl;
        }
        }
    }
    return 0;
}


