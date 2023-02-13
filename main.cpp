#include <iostream>
#include <time.h>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;


// zlozonoœæ to n^2
void WypelnijMacierz(int *T[],int a,int x, int y)
{
    //Wypelnienie macierzy liczbami
    for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++)
		{
			//wygenerowanie liczb z zakresu [-9; 9]
			T[i][j]= x+rand() % (y-x+1);
			//wyswietlenie wylosowanej liczby
			 cout<<T[i][j]<<" ";
		}
		cout << endl;
	}
}

void Wypisz(int *T[], int a)
{
    int suma = 0;
    int suma_przekatnych = 0;
    //przekatka macierzy
	for(int i=0; i<a; i++)
    {
        // sprawdzam zeby 2 razy nie brac przekatnych
        if(i == a-i-1)
        {
            // sumuje przekatne
            suma_przekatnych = T[i][i];
        }else{
            suma_przekatnych = T[i][i] + T[i][a-i-1];
        }

        // sumuje liczby w wierszu pomijajac przekatne
        suma = -suma_przekatnych;
        for(int j=0; j<a; j++)
        {
            suma += T[i][j];
        }

        // porownuje sumy i wyswietlam indeks
        if(suma_przekatnych > suma){
            cout << i << endl;
        }
        // zeruje sume
        suma = 0;
    }
}


int main()
{
    srand((unsigned)time (NULL));

    //zmienne
    int **T, n, a, b;

    //przedzial liczb z macierzy
    a=0;
    b=9;

    cout << "podaj wielkosc macierzy kwadratowej(nxn): ";
    cin >> n;

    //Przydzielanie pamieci na tablice dwuwymiarowe(macierz)
    T = new int *[n];
    for(int i=0;i<n;i++)
		T[i] = new int[n];

	WypelnijMacierz(T,n,a,b);
	// obliczanie czasu trwania programu
    auto begin = std::chrono::high_resolution_clock::now();
	Wypisz(T,n);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
	// zwolnienie pamieci
    for(int i=0;i<n;i++)
		delete [] T[i];
    delete []*T;
}
