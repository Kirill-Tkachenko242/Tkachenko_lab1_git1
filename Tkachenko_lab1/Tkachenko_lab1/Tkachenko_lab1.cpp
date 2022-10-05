


#include <iostream>
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
    double s;
};

struct Pipe
{
    double lenght;
    double diametr;
    double repair;
};


void DefaultPipe(Pipe& pipe) {
    pipe.lenght = 0;
    pipe.diametr = 0;
    pipe.repair = 0;
}
void DefaultCS(CS& CS) {
    CS.name = "NULL";
    CS.shop = 0;
    CS.shopr = 0;
    CS.ef = 0;
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
    cout << "\tefficiency:" << c.ef;
    cout << "\tstart or stop the shop(0-no, 1-yes):" << c.s << endl;
}



Pipe LoadPipe()
{
    Pipe s;
    ifstream fin;
    fin.open("data.txt", ios::in);
    if (fin.is_open())
    {
        fin >> s.lenght;
        fin >> s.diametr;
        fin >> s.repair;
        fin.close();
    }
    return s;
}
CS LoadCS()
{
    CS c;
    ifstream fin;
    fin.open("data2.txt", ios::in);
    if (fin.is_open())
    {
        fin >> c.name;
        fin >> c.shop;
        fin >> c.shopr;
        fin >> c.ef;
        fin >> c.s;
        fin.close();
    }
    return c;
}


void SavePipe(const Pipe& s)
{
    ofstream fout;
    fout.open("data.txt", ios::out);
    if (fout.is_open())
    {
        fout << s.lenght << endl 
             << s.diametr << endl
             << s.repair << endl;
        fout.close();
    }
}
void SaveCS(const CS& c)
{
    ofstream fout;
    fout.open("data2.txt", ios::out);
    if (fout.is_open())
    {
        fout << c.name << endl
            << c.shop << endl
            << c.shopr << endl
            << c.ef << endl
            << c.s << endl;
        fout.close();
    }
}


void EditPipe(Pipe& s)
{
    if (s.repair == 0) {
        s.repair = 1;
    }
    if (s.repair == 1) {
        s.repair = 0;
    }
    else {
        s.repair = GetCorrectNumber(0, 1);
    }
}


void EditCS(CS& c)
{
    if (c.s == 0) {
        c.s = 1;
    }
    if (c.s == 1) {
        c.s = 0;
    }
    else {
        c.s = GetCorrectNumber(0, 1);
    }

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
    s.repair = GetCorrectNumber(0, 1);
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
    c.shop = GetCorrectNumber(1.0, 10000.0);
    cout << "Repair shops: ";
    c.shopr = GetCorrectNumber(0.0, 1000.0);
    cout << "efficiency: ";
    c.ef = GetCorrectNumber(10.0, 100.0);
    cout << "start or stop the shop: ";
    c.ef = GetCorrectNumber(0, 1);
    return in;
}
int main()
{
    Pipe st;
    CS cs;
    DefaultPipe(st);
    DefaultCS(cs);
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
            SaveCS(cs);
            break;
        }
        case 5:
        {
            st = LoadPipe();
            cs = LoadCS();
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


