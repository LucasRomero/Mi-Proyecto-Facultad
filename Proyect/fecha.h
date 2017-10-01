#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
void mostrarFecha(); /// muestra la fecha (que no ulitizo en ningun lado)
bool esBisiesto(int); /// pregunta si es bisiesto el anio
bool validarFecha(int *,int *,int *); /// pregunta si los dias meses y anios estan bien y no son cualquier cosa
void mostrarFecha(Fecha f){
  cout << f.dia << "/" << f.mes << "/" << f.anio;
}
bool esBisiesto(int anio){
    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0){
            return true;
    }
    return false;
}
bool validarFecha(int *dia,int *mes,int *anio){
    int meses[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(*anio < 2017){
        return false;
    }
    if(esBisiesto(*anio)){
        meses[1] = 29;
    }
    if(*dia > meses[*mes-1]){
        return false;
    }
    if(*mes<1 || *mes>12){
      return false;
    }
    return true;
}
#endif // FECHA_H_INCLUDED
