#ifndef MENSAJES_H_INCLUDED
#define MENSAJES_H_INCLUDED
const int ESPANIOL = 0;
const int INGLES = 1;
const int IDIOMA = ESPANIOL;
enum Mensajes
{
    MSJ_CONFIRMA_SALIR,
    MSJ_CONFIRMA_ELIMINAR,
    MSJ_ERROR_ABRIR_ARCHIVO,
    MSJ_ERROR_NROCUENTA,
    MSJ_ERROR_CUENTAREPETIDA,
    MSJ_ERROR_TIPOCUENTA,
    MSJ_EXITO_CUENTA_AGREGADA,
    MSJ_EXITO_CUENTA_ELIMINADA,
    MSJ_EXITO_CUENTA_MODIFICADA,
    MSJ_ERROR_CUENTA_NOAGREGADA,
    MSJ_ERROR_CUENTA_NOEXISTE,
    MSJ_ERROR_TIPOMOVIMENTO,
    MSJ_ERROR_IMPORTE_INCORRECTO,
    MSJ_ERROR_SALDO_DEUDOR,
    MSJ_ERROR_MOVIMIENTO_NOEXISTE,
    MSJ_EXITO_MOVIMIENTO_AGREGADO,
    MSJ_ERROR_MOVIMIENTO_NOAGREGADO
};
const char msjs[2][50][100] =
{
    {
        "ESTA SEGURO QUE DESEA SALIR (S/N)?",
        "ESTÁ SEGURO QUE DESEA ELIMINAR (S/N)",
        "ERROR AL ABRIR EL ARCHIVO",
        "EL NÚMERO DE CUENTA NO PUEDE SER POSITIVO",
        "EL NÚMERO DE CUENTA NO PUEDE REPETIRSE",
        "EL TIPO DE CUENTA ES INCORRECTO",
        "LA CUENTA HA SIDO AGREGADA",
        "LA CUENTA HA SIDO ELIMINADA",
        "LA CUENTA HA SIDO MODIFICADA",
        "LA CUENTA NO HA SIDO AGREGADA",
        "LA CUENTA NO EXISTE",
        "EL TIPO DE MOVIMIENTO NO ES CORRECTO",
        "EL IMPORTE DEL MOVIMIENTO NO ES CORRECTO",
        "EL SALDO RESULTANTE NO ES CORRECTO",
        "EL MOVIMIENTO HA SIDO AGREGADO",
        "EL MOVIMIENTO NO HA SIDO AGREGADA"
    },
    {
        "ARE YOU SURE YOU WANT TO EXIT (Y/N)?",
        "ARE YOU SURE YOU WANT TO DELETE THIS RECORD (Y/N)",
        "ERROR WHILE TRYING TO OPEN THE FILE",
        "ACCOUNT NUMBER CANT BE A NEGATIVE NUMBER",
        "ACCOUNT NUMBER MUST BE UNIQUE",
        "ACCOUT TYPE IS INCORRECT",
        "THE ACCOUNT HAS BEEN CREATED SUCCESFULLY",
        "THE ACCOUNT HAS BEEN DELETED SUCCESFULLY",
        "THE ACCOUNT HAS BEEN UPDATED SUCCESFULLY",
        "THE ACCOUNT COULDNT BE CREATED SUCCESFULLY",
        "THE ACCOUNT DOESNT EXIST",
        "TRANSACTION TYPE IS INCORRECT",
        "TRANSACTION AMOUNT IS INCORRECT",
        "THE RESULTING BALANCE IS INCORRECT",
        "TRANSACTION NUMBER DOESNT EXIST",
        "THE TRANSACTION HAS BEEN CREATED SUCCESFULLY",
        "THE ACCOUNT COULDNT BE CREATED SUCCESFULLY"
    }
};
void borrarPantalla()
{
#ifdef __unix__
    system("clear");
#elif defined(_WIN32) || defined(WIN32)
    system("cls");
#endif
}
void pausa()
{
#ifdef __unix__
    cin.get();
    cin.get();
#elif defined(_WIN32) || defined(WIN32)
    system("pause >nul");
#endif
}
void mensaje(int idmensaje)
{
    cout << endl << msjs[IDIOMA][idmensaje];
}
bool confirmaSalir()
{
    char val;
    mensaje(MSJ_CONFIRMA_SALIR);
    cout << endl;
    cin >> val;
    if (val == 'S' or val == 's' or val == 'Y' or val == 'y')
        return true;
    else
        return false;
}
bool confirmaEliminar()
{
    char val;
    mensaje(MSJ_CONFIRMA_ELIMINAR);
    cin >> val;
    if (val == 'S' or val == 's' or val == 'Y' or val == 'y')
        return true;
    else
        return false;
}
#endif // MENSAJES_H_INCLUDED
