


#include <iostream>
#include <vector>
#include <fstream>



using namespace std;






struct Pipe
{
    double lenght;
    double diametr;
    string repair;
};



Pipe InputPipe()
{
    Pipe s;
    cout << "lenght:";
    cin >> s.lenght;
    cout << "diametr: ";
    cin >> s.diametr;
    cout << "repair: ";
    cin >> s.repair;
    return s;
}

void PrintPipe(const Pipe& s)
{
    cout << "lenght: " << s.lenght;
    cout << "\tdiametr: " << s.diametr;
    cout << "\trepair: " << s.repair << endl;
}


Pipe LoadPipe()
{
    ifstream fin;
    fin.open("data.txt", ios::in);
    Pipe s;
    fin >> s.lenght;
    fin >> s.diametr;
    fin >> s.repair;
    fin.close();
    return s;
}

void SavePipe(const Pipe& s)
{
    ofstream fout;
    fout.open("data.txt", 'w');
    fout << s.lenght << endl << s.diametr << endl << s.repair << endl;
    fout.close();
}


void EditPipe(Pipe& s)
{
    s.diametr -= 0.5;
}

int main()
{
    Pipe st = InputPipe();
    PrintPipe(st);
    EditPipe(st);
    SavePipe(st);
    PrintPipe(LoadPipe());
    return 0;
}


