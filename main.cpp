#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cmath>
// funkcija
const double qq=-1.9;
const double qqq=1.9;
double sixhump(double *x)
{
    double f = (4- 2.1 * x[0] * x[0] + (pow(x[0],4))/3) * x[0] * x[0] + x[0] * x[1] + (-4+4*x[1]*x[1])*(pow(x[1],2));
    return f;
}

using namespace std;

int main()
{
    int q=0;
    cout<<"ar norite for ciklo ar while?(1/2)";
    cin>>q;
    if(q==1)
    {
        cout << "Monte Carlo realizacijos pradzia" << endl;
        cout << "(RANDOM SEARCH METHOD)" << endl;
        // Kintamuju apsirasymas
        double f, x; // Funkcijos reiksmes ir argumentas x
        int n; // Uzedavinio dimensija
        double xSprendinys; // Argumento reiksme
        int fSprendinys; // Uzdavinio sprendinys

        // Vektoriu kurimas, kuriu elementai yra atitiktiniai realus skaiciai

        double virsutinis_rezis, apatinis_rezis, virsutinis_rezis2, apatinis_rezis2; // apsirasome intervalo rezius

        cout << "Iveskite inervalo rerzius x1: ";
        cin >> apatinis_rezis >> virsutinis_rezis;
        cout << "Iveskite inervalo rerzius x2: ";
        cin >> apatinis_rezis2 >> virsutinis_rezis2;
        cout << "Iveskite vektoriaus ilgi: ";
        cin >> n;

        double vektorius[n], funkcija[200];

        for (int j=0; j<100; j++)
        {

        for(int i=0; i<n; i++)
        {
            if (i == 0)
            {
               vektorius[i] = rand() * (virsutinis_rezis - apatinis_rezis) / RAND_MAX + apatinis_rezis;
               cout << "Skaicius = " << vektorius[i] << endl; // pakeiciau
            }
            else
            {
               vektorius[i] = rand() * (virsutinis_rezis2 - apatinis_rezis2) / RAND_MAX + apatinis_rezis2;
               cout << "Skaicius = " << vektorius[i] << endl; // pakeiciau
            }

        }

        cout << "Funkcija = " << sixhump(&vektorius[0]) << endl; // pakeiciau
        cout << "===================================\n"  << endl;
        funkcija[j] = sixhump(&vektorius[0]);
        }

        double min = funkcija[0];
        for (int i=0; i<100; i++)
        {
            if (funkcija[i] < min) min = funkcija[i];
        }
        cout << "MIN: " << min<<endl;
    }
    else
    {
        double ftik=1.03, *funkcija, skaicius[2], top[2];
        funkcija=(double*)malloc(10*sizeof(double));
        int i=0;
      while(abs(ftik-funkcija[i])>0.1)
        {
            
            for(int n=0;n<2;n++)
            skaicius[n] = rand() * (qqq - qq) / RAND_MAX + (qq);
            funkcija[i]=sixhump(skaicius);
            cout<<"\n rand skaicius[0] : "<<skaicius[0]<<" rand skaicius[1] :  "<<skaicius[1]<<"\n funkcija: "<<funkcija[i]<<"\n skaicius: "<<ftik-funkcija[i]<<"\n i: "<<i<<endl;
            i++;

            if(i==10)
            {
                free(funkcija);
                funkcija=(double*)malloc(10*sizeof(double));
                i=0;
               //system("pause");
            }
            
        }
        cout<<"=============================Taskas: "<<"\n rand skaicius[0] : "<<skaicius[0]<<" rand skaicius[1] : "<<skaicius[1]<<"\n funkcija: "<<funkcija[i]<<"\n skaicius: "<<ftik-funkcija[i]<<"\n i: "<<i<<endl;;
        top[0]=funkcija[i];
        system("pause");
        
         
         
         
         while(abs(ftik-funkcija[i])>0.01)
        {
            
            for(int n=0;n<2;n++)
            skaicius[n] = rand() * (qqq - qq) / RAND_MAX + (qq);
            funkcija[i]=sixhump(skaicius);
            cout<<"\n rand skaicius[0] : "<<skaicius[0]<<" rand skaicius[1] :  "<<skaicius[1]<<"\n funkcija: "<<funkcija[i]<<"\n skaicius: "<<ftik-funkcija[i]<<"\n i: "<<i<<endl;
            i++;

            if(i==10)
            {
                free(funkcija);
                funkcija=(double*)malloc(10*sizeof(double));
                i=0;
               //system("pause");
            }
            
        }
        cout<<"=============================Taskas: "<<"\n rand skaicius[0] : "<<skaicius[0]<<" rand skaicius[1] : "<<skaicius[1]<<"\n funkcija: "<<funkcija[i]<<"\n skaicius: "<<ftik-funkcija[i]<<"\n i: "<<i<<endl;;
        top[1]=funkcija[i];
        system("pause");
        
        
        
        
         while(abs(ftik-funkcija[i])>0.001)
        {
            
            for(int n=0;n<2;n++)
            skaicius[n] = rand() * (qqq - qq) / RAND_MAX + (qq);
            funkcija[i]=sixhump(skaicius);
            cout<<"\n rand skaicius[0] : "<<skaicius[0]<<" rand skaicius[1] :  "<<skaicius[1]<<"\n funkcija: "<<funkcija[i]<<"\n skaicius: "<<ftik-funkcija[i]<<"\n i: "<<i<<endl;
            i++;

            if(i==10)
            {
                free(funkcija);
                funkcija=(double*)malloc(10*sizeof(double));
                i=0;
               //system("pause");
            }
            
        }
        cout<<"=============================Taskas: "<<"\n rand skaicius[0] : "<<skaicius[0]<<" rand skaicius[1] : "<<skaicius[1]<<"\n funkcija: "<<funkcija[i]<<"\n skaicius: "<<ftik-funkcija[i]<<"\n i: "<<i<<endl;;
        if ((top[0]!=top[1])&&(top[1]!=funkcija[i]))
        top[2]=funkcija[i];
        system("pause");
        
        
    
    for (int i=0;i<3;i++)
    cout<<"\n min skaicius "<<i+1<<"-as: "<<top[i];
    cout<<endl;
    system("pause");
    return 0;
    }
}
