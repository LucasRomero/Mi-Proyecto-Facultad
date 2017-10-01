#ifndef PROYECT_H_INCLUDED
#define PROYECT_H_INCLUDED
const char *FILE_PROYECTOS = "proyectos.dat";
void Menu_Proyectos();  /// el menu del proyecto, donde esta el switch con los CASE.
bool NuevoProyecto();   /// esto te pide todos los campos del struc proyecto y valida 1 por 1 los campos
int Val_COD_D(char [5]);/// busca en el struc proyecto los DIPUTADOS que tienen proyectos INICADOS,pasandole un char para que lo compare y devuelve la posicion del mismo.
void ListaProyectos();  /// Lista todos los proyectos que hay en el archivo "proyectos.dat".
Diputado Devolverxposdip(int); ///me busca en diputados, la posicion del mismo,pasandole la posicion antes buscada y me devuelve el diputado de la posicion que busco
int CuentaElementos(); /// cuenta los elementos que tiene el archivo, este caso los proyectos que hay.
bool NuevoProyecto(){
    proyecto reg;
    Diputado dip;
    FILE *p;
    int pos;
    Fecha auxfecha;
    p=fopen(FILE_PROYECTOS,"ab");
    reg.Cod_Proyecto=CuentaElementos()+1; /// aumentar en 1
    cout <<"Nombre del Proyecto" <<endl;
    cin.ignore();
    cin.getline(reg.Nombre,150);
    cout << "Codigo de Diputado" << endl;
    //cin.ignore();
    cin >> reg.Codigo_Diputado;
    pos=buscarArticulo(reg.Codigo_Diputado);
    while(pos<0){
    cout << "Codigo de Diputado Erroneo, Intentalo nuevamente" <<endl;
    cin >> reg.Codigo_Diputado;
    pos=buscarArticulo(reg.Codigo_Diputado);
    }
    dip=leerdiputado(pos);
    if(dip.Estado==false){
      cout << endl;
      cout <<"diputado No Activo. Comienze de nuevo "<<endl<<endl;
      system("pause");
      borrarPantalla();
      return 0;
    }
    cout << "Fecha del Proyecto: " << endl;
    cout << "Dia: ";
    cin >> auxfecha.dia;
    cout << "Mes: ";
    cin >> auxfecha.mes;
    cout << "Anio: ";
    cin >> auxfecha.anio;
    while((validarFecha(&auxfecha.dia, &auxfecha.mes, &auxfecha.anio))==false){
        cout << "Fecha erronea, intente nuevamente: ";
        cout << "Fecha del Proyecto: " << endl;
        cout << "Dia: ";
        cin >> auxfecha.dia;
        cout << "Mes: ";
        cin >> auxfecha.mes;
        cout << "Anio: ";
        cin >> auxfecha.anio;
    }
    reg.Fec.dia = auxfecha.dia;
    reg.Fec.mes = auxfecha.mes;
    reg.Fec.anio = auxfecha.anio;
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    borrarPantalla();
}
int Val_COD_D(char cod[5]){
    struct proyecto aux;
    FILE *p;
    int pos=0;
    p=fopen(FILE_PROYECTOS,"rb");
        while(fread(&aux,sizeof aux,1,p)==1){
            if(strcmp(cod,aux.Codigo_Diputado)==0){
                fclose(p);
                return pos;
                }
                pos++;
        }
        fclose(p);
        return -1;
}
void ListaProyectos(){
    proyecto reg;
    FILE *p;
    p=fopen(FILE_PROYECTOS,"rb");
    while(fread(&reg,sizeof reg,1,p)==1){
    cout << "----------------------------------" << endl;
    cout << "Codigo de Diputado " << reg.Codigo_Diputado << endl;
    cout << "Codigo de Proyecto  "<< reg.Cod_Proyecto << endl;
    cout << "Nombre  " << reg.Nombre<< endl;
    cout << "Fecha del la Presentacion del proyecto  " << endl;
    cout << "Dia  " <<reg.Fec.dia << endl;
    cout <<"Mes:  "<< reg.Fec.mes << endl;
    cout <<"Anio:  "<< reg.Fec.anio << endl;
    }
    pclose(p);
    system("pause");
    borrarPantalla();
}
void ListarProyectos(Diputado reg1){
struct proyecto dip;
FILE *p;
p=fopen(FILE_PROYECTOS,"rb");
        while(fread(&dip,sizeof dip,1,p)==1){
                if(strcmp(reg1.Codigo_Diputado,dip.Codigo_Diputado)==0){
    cout << "---------------------------" << endl;
    cout << "Codigo de Diputado :  "<< dip.Codigo_Diputado << endl;
    cout << "Codigo del Proyecto:  "<< dip.Cod_Proyecto<<endl;
    cout << "Nombre del proyecto:  "<< dip.Nombre<<endl;
    cout << "Fecha del Proyecto: Dia "<< dip.Fec.dia<<endl;
    cout << "Fecha del Proyecto: Mes "<< dip.Fec.mes<<endl;
    cout << "Fecha del Proyecto: Anio "<< dip.Fec.anio<<endl;
    cout << "Nombre del Diputado :  " <<reg1.nombre<< endl;
    cout << "Apellido del Diputado:  "<<reg1.Apellido<< endl;
    }
}
fclose(p);
}
void mostrarXCodigo(){
 struct proyecto dip;
 struct Diputado reg;
 FILE *p;
 int pos,pos1;
 char codigo[5];
 cout << "CODIGO de Diputado Solicitado: " << endl;
 cin >> codigo;
 pos=Val_COD_D(codigo);
    if(pos<0){
cout << "CODIGO de Diputado Solicitado Erroneo, No tiene proyectos Iniciados " << endl;
system("pause");
return;
    }
pos1=buscarArticulo(codigo);
reg=Devolverxposdip(pos1);
ListarProyectos(reg);
    cout << endl<<endl;
    system("pause");
    borrarPantalla();
}
Diputado Devolverxposdip(int pos1){
    FILE *p;
    struct Diputado reg;
    p=fopen(FILE_DIPUTADOS,"rb");
    if(p==NULL){
        cout<<"ERROR";
        system("pause");
    }
    fseek(p,pos1*sizeof(Diputado),SEEK_SET);
    fread(&reg,sizeof(Diputado),1,p);
    fclose(p);
    return reg;
}
int CuentaElementos(){
	proyecto aux;
	FILE *p;
	long tamanioarchivo;
    p=fopen(FILE_PROYECTOS,"rb");
    if(p==NULL){
        cout << "Error para abrir proyecto"<< endl;
        return 0;
    }
    fseek(p, 0, SEEK_END); /// voy al final del archivo para hacer un ftell para ver el tamanio en bytes del archivo, lo que hace el ftell me lee desde el princio hasta donde esta el puntero
    tamanioarchivo=ftell(p);
    return tamanioarchivo/sizeof(aux) ;
    fclose(p);
}
void Menu_Proyectos(){
    int opc;
        while(opc!=0){
    cout << "           MENU PROYECTOS" << endl << "         ---------------------" << endl;
    cout << "           1) NUEVO PROYECTO DE LEY" << endl;
    cout << "           2) LISTAR TODOS LOS PROYECTOS DE LEY" << endl;
    cout << "           3) LISTAR TODOS LOS PROYECTOS DE LEY POR CODIGO DE DIPUTADO" << endl;
    cout << "         --------------------" << endl;
    cout << "           0) VOLVER AL MENU ANTERIOR" << endl;
    cout << "           OPCION: ";
    cin >> opc;
    borrarPantalla();
        switch(opc){
    case 1:
        NuevoProyecto();
        break;
    case 2:
        ListaProyectos();
        break;
    case 3:
        mostrarXCodigo();
        break;
    case 0:

        break;
        }
    }
}
#endif // PROYECT_H_INCLUDED
