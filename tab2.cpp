#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void losuj(double T[][8], int w);
void wypisz(double T[][8], int w);
double suma(double T[][8], int w);
void maks(double T[][8], double tab[]);
void zamiana(double T[][8], int a, int b);
void ile(double T[][8], double a, double b, double D[], int *pom);
void macierz(double T[][8], double tab[][8]);
int main()
{
    char c = 't';

    while(c == 't' || c == 'T')
    {
        srand(time(NULL));
    
    double A[8][8];
    double B[5][8];
    double C[8];

    losuj(A,8);
    losuj(B,5);

    cout<<"A = "<<endl;
    wypisz(A,8);
    cout<<"\n\nB = \n";
    wypisz(B,5);

    cout<<"\n\n";
    cout<<"suma pod przekatna = "<<suma(A, 8)<<endl<<endl;

    maks(A,C);
    cout<<"max = ";
    for(int i = 0; i<8;i++) cout<<C[i]<<" ";

    cout<<"\n\n";

    int i1,i2;

    cout<<"podaj indeksy do zamiany: ";
    cin>>i1;
    cin>>i2;
    zamiana(B,i1,i2);
    cout<<"B = \n";
    wypisz(B,5);
    
    
    double *D = new double[100];
    double a,b;
    int pom = 0;

    cout<<"podaj przedzial:\na = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;
    ile(A,a,b,D, &pom);

    cout<<"\nW tablicy A wystepuje "<<pom<<" elementow z przedzialu (a,b)"<<endl;
    cout<<"D = ";
    for(int i = 0; i<pom; i++) cout<<D[i]<<" ";
    
    cout<<"\n\n";

    double MT[8][8];

    macierz(A,MT);

    cout<<"macierz A transponowana = "<<endl;
    wypisz(MT,8);



    cout<<"\n\n";
    cout<<"czy chcesz kontynuowac T/N: ";
    cin>>c;

    }

    system("pause");
}

void losuj(double T[][8], int w)
{
    for(int i = 0; i<w;i++)
    {
        for(int j = 0; j<8; j++)
        {
            T[i][j] = (double)rand()*(4.5-(-1.0)) / (double)RAND_MAX-(-1.0);
        }
    }
}
void wypisz(double T[][8], int w)
{
    for(int i = 0; i<w;i++)
    {
        for(int j = 0; j<8;j++)
        {
            cout<<setprecision(4);
            cout<<setw(8);
            cout<<T[i][j]<<"  ";
        }
        
        cout<<"\n";
    }
}
double suma(double T[][8], int w)
{
    double wynik = 0.0;

    for(int i = 1; i<w; i++)
    {
        for(int j = 0; j<i;j++)
        {
            wynik+=(double)T[i][j];
        }
        
    }

    return (double)wynik;
}
void maks(double T[][8], double tab[])
{
    double max;
    
    for(int i = 0; i<8; i++)
    {
        max = T[i][0];
        for(int j = 0; j<8;j++)
        {
            if(max<T[i][j]) max = T[i][j];
        }
        tab[i] = max;
    }
}
void zamiana(double T[][8], int a, int b)
{
    double pom[8];

    for(int i = 0; i<8;i++)
    {
        pom[i] = T[a-1][i];
    }

    for(int i = 0; i<8;i++)
    {
        T[a-1][i] = T[b-1][i];
        T[b-1][i] = pom[i]; 
    }
}
void ile(double T[][8], double a, double b, double D[], int *pom)
{
    
    for(int i = 0; i<8;i++)
    {
        for(int j = 0; j<8;j++)
        {
            if((T[i][j] >a) && (T[i][j] <b))
            {
                D[*pom] = T[i][j];
                *pom = *pom + 1;
            }
        }
    }
    
    
}
void macierz(double T[][8], double tab[][8])
{
    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            tab[i][j] = T[j][i];
        }
    }
}
