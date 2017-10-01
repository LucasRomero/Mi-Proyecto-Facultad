#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "structs.h"
#include "fecha.h"
#include "mesages.h"
#include "diputados.h"
#include "proyect.h"
#include "ingresos.h"
#include "sesiones.h"
#include "configuraciones.h"
int main()
{
    int opc;
    while(true)
    {
        cout << "           MENU PRINCIPAL" << endl << "         ---------------------" << endl;
        cout << "           1) DIPUTADOS" << endl;
        cout << "           2) PROYECTOS" << endl;
        cout << "           3) SESIONES" << endl;
        cout << "           4) REPORTES" << endl;
        cout << "           5) CONFIGURACION" << endl;
        cout << "         --------------------" << endl;
        cout << "           0) SALIR" << endl << endl;
        cout << "           OPCION: ";
        cin >> opc;
        borrarPantalla();
        switch(opc)
        {
        case 1:
            Menu_Diputados();
            break;
        case 2:
            Menu_Proyectos();
            break;
        case 3:
            Menu_Sesiones();
            break;
        case 4:
            break;
        case 5:
            Menu_Configuraciones();
            break;
        case 0:
            if(confirmaSalir())
            {
                return 0;
            }
            break;
        default:
            cout << "Opcion No Valida, Vuelve a Intertarlo" << endl<< endl<< endl;
            system("pause");
            borrarPantalla();
            break;
        }/// switch principal

    }/// while

    return 0;
}
