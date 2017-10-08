#ifndef DIPUTADOS_H_INCLUDED
#define DIPUTADOS_H_INCLUDED
const char *FILE_DIPUTADOS = "diputados.dat";
/// FUNCIONES
bool NumPartido(int); // hace que no se pase del 1 al 10 el numero del partido
bool NumProv(int); //hace que no se pase del 1 al 24 el numero de provincia
void Menu_Diputados(); // el menu completo
int buscarArticulo(char [5]); //compara el ingreso de un nuevo diputado compara si esta repetido(te devuelve la posicion en el archivo). caso contrario retorna -1.
bool NuevoDiputado(); // hace el ingreso de todos los campos del struct en el archivo de diputados, haciendo las validaciones necesarias de cada campo.
void ListarDiputados(); // muestra a todos los diputados en el archivo.
bool FinMandato(int); // devuelve true si el mandato es menor a 2017 y false en caso contrario(que es el valido, el que deberia ir).
bool CambiarEstado(Diputado,int); // con la posicion lo busca de nuevo con el fseek y  fwrite, cambia el estado de true a false, y devuelve true si fue posible
void ListarDiputado(Diputado); // recibe el diputado y lo muestra.
bool buscarP(int); // busca en archivo de diputado si existe el numero de partido si es asi devuelve false.
void mostrarPorCodigo(); // muestra a los diputados que va encontrando con un fread y con la funcion "buscarP" los diputados con el numero de partido iguales.
Diputado leerdiputado(int); // se le pasa la posicion de un diputado en el archivo y te devuelve todo el diputado completo.
int CuentaElementoss(); // devuelve la cantidad de elementos que tiene un archivo.
void ordenar_pu(struct Diputado *,int);
void ListarDiputadosXMEM(struct Diputado *,int);
void guardar(int,Diputado);
bool LeerDiputadoss(Diputado *, int);
void CompletarVector(Diputado_Proyect *,int);
int cantProyecto_X_COD(char [5]);
void CompletarProyecto(Diputado_Proyect *,int);
/// Comienzo de Codigo
bool NuevoDiputado(){
    Diputado reg;
    bool par,prov,fin;
    int pos;
    FILE *p;
    p=fopen(FILE_DIPUTADOS,"ab");
    cout << "Codigo Diputado " <<endl;
    cin >> reg.Codigo_Diputado;
    pos=buscarArticulo(reg.Codigo_Diputado);
    while(pos>=0){
    cout << "Codigo Diputado no valido. Ingrese uno valido nuevamente " <<endl;
    cin >> reg.Codigo_Diputado;
    pos=buscarArticulo(reg.Codigo_Diputado);
    }
    cout << "Apellido " <<endl;
    cin.ignore();
    cin.getline(reg.Apellido,50);
    cout << "Nombre " <<endl;
    cin.getline(reg.nombre,50);
    cout << "Codigo Partido Politico " <<endl;
    cin >> reg.Cod_Partido;
    par=NumPartido(reg.Cod_Partido);
    while(par){
        cout << "El Codigo del Partido debe estar entre 1 y 10 , Vuelve a Intentarlo" << endl;
        cout << "Codigo Partido Politico" <<endl;
        cin >> reg.Cod_Partido;
        par=NumPartido(reg.Cod_Partido);
    }
    cout << "Codigo Provincia " <<endl;
    cin >> reg.Cod_Prov;
    prov=NumProv(reg.Cod_Prov);
    while(prov){
        cout << "El Codigo de la Provincia debe estar entre 1 y 24 , Vuelve a Intertarlo" << endl;
        cin >> reg.Cod_Prov;
        prov=NumProv(reg.Cod_Prov);
    }
    cout << "Anio de Finalizacion del Mandato " << endl;
    cin >> reg.Fin_Man;
    fin=FinMandato(reg.Fin_Man);
    while(fin){
        cout << "Anio Erroneo, Ingrese una fecha valida" << endl;
        cin >> reg.Fin_Man;
        fin=FinMandato(reg.Fin_Man);
    }
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    borrarPantalla();
}
bool FinMandato(int aa){
    if(aa<2017){
        return true;
    }
    return false;
}
int buscarArticulo(char cod[5]){
    struct Diputado aux;
    int pos=0;
    FILE *p;
    p=fopen(FILE_DIPUTADOS,"rb");
    if(p==NULL){
        return -1;
    }
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
bool NumPartido(int partido){
    if(partido < 1 || partido > 10){
        return true;
    }
        return false;
}
bool NumProv(int prov){
    if(prov < 1 || prov > 24){
        return true;
    }
        return false;
}
void ListarDiputados(){
    Diputado reg;
    FILE *p;
    p=fopen(FILE_DIPUTADOS,"rb");
    if(p==NULL){
      cout << "Error al abrir el archivo" <<endl;
      return;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
    cout << "---------------------------" << endl;
    cout << "Codigo de Diputado :  "<< reg.Codigo_Diputado << endl;
    cout << "Diputado :  "<<endl;
    cout <<"Nombre :  "<< reg.nombre<<endl;
    cout <<"Apellido : " << reg.Apellido << endl;
    cout <<"Fin De Mandato:  "<<reg.Fin_Man <<endl;
    if(reg.Estado){
        cout << "Estado: Activo" <<endl;
    }else{
        cout << "Estado: No Activo" <<endl;
    }
    }
    fclose(p);
    system("pause");
    borrarPantalla();
}
void ListarDiputado(Diputado reg){
    cout << "---------------------------" << endl;
    cout << "Codigo de Diputado : "<< reg.Codigo_Diputado << endl;
    cout << "Diputado : " << endl;
    cout << "Nombre: " << reg.nombre<<endl;
    cout << "Apellido:  "<<reg.Apellido << endl;
    cout << "Fin de Mandato:  "<<reg.Fin_Man<<endl;
        if(reg.Estado){
        cout << "Estado: Activo" <<endl;
    }else{
        cout << "Estado: No Activo" <<endl;
    }
}
void mostrarPorCodigo(){
 struct Diputado dip;
 FILE *pFile;
 int codigo;
 bool val;
 cout << "CODIGO: " << endl;
 cin >> codigo;
 val=buscarP(codigo);
 while(val){
  cout << "CODIGO de Partido No Valido, Vuelve a Intentar " << endl;
  cin >> codigo;
  val=buscarP(codigo);
 }
 pFile=fopen(FILE_DIPUTADOS,"rb");
     if(pFile==NULL){
      cout << "Error al abrir el archivo" <<endl;
      return;
    }
        while(fread(&dip,sizeof dip,1,pFile)==1){
            if(codigo == dip.Cod_Partido){
                ListarDiputado(dip);
            }
        }
    fclose(pFile);
}
bool buscarP(int cod){
    struct Diputado aux;
    FILE *p;
    p=fopen(FILE_DIPUTADOS,"rb");
    if(p==NULL){
      cout << "Error al abrir archivo diputado"<<endl;
      return true;
    }
        while(fread(&aux,sizeof aux,1,p)==1){
            if(cod==aux.Cod_Partido){
                fclose(p);
                return false;
                }
                fclose(p);
                return true;
        }
        fclose(p);
}
///-----------------------Esto es la modificacion de un Diputado
void modificar(){
    char cod[5];
    int pos;
    cout <<"Numero de diputado a cambiar"<<endl;
    cin >> cod;
    pos=buscarArticulo(cod);
    Diputado reg;
    if(pos>=0){
    Diputado reg;
    reg=leerdiputado(pos);
    ListarDiputado(reg);
    cout << "Nuevo Codigo de Diputado" << endl;
    cin >> reg.Codigo_Diputado;
    cout << "Apellido" <<endl;
    cin >> reg.Apellido;
    cout << "NOMBRE" <<endl;
    cin >> reg.nombre;
    cout << "COD PARTIDO" <<endl;
    cin >> reg.Cod_Partido;
    cout << "COD PROV" <<endl;
    cin >> reg.Cod_Prov;
    cout << "anio"<<endl;
    cin >> reg.Fin_Man;
    guardar(pos,reg);
    }
}
void guardar(int pos,struct Diputado reg){
    if(pos>=0){
    FILE *p;
    p=fopen(FILE_DIPUTADOS,"rb+");
    fseek(p, pos * sizeof(Diputado),SEEK_SET );
    fwrite(&reg, sizeof(Diputado), 1, p);
    fclose(p);
    }
}
Diputado leerdiputado(int pos){
    Diputado reg;
    FILE *p=fopen(FILE_DIPUTADOS,"rb");
    fseek(p,pos*sizeof(Diputado),SEEK_SET);
    fread(&reg, sizeof(Diputado), 1, p);
    fclose(p);
    return reg;
}
void Baja(){
    char cod[5];
    int pos;
    Diputado dip;
    bool val;
    cout << "DIPUTADO A DAR DE BAJA" << endl;
    cin >> cod;
    pos=buscarArticulo(cod);
    if(pos<0){
        cout << "El Diputado no existe" << endl;
        system("pause");
    }else{
    dip=leerdiputado(pos); /// si saco esta funcion para usar la de cambiar estado, me cambia el estado pero no me muestra el nombre del diputado y demas campos PREGUNTAR
    val=CambiarEstado(dip,pos);
    if(val){
        cout <<"Cambiado con Exito "<<endl;
        system("pause");
     }
    }
    borrarPantalla();
  }
bool CambiarEstado(Diputado dip,int pos){ /// preguntar si es necesario buscar otra ves el diputado si  en la funcion de arriba, ya deberia estar encontrado.fijarse como hacer eso, preguntar asi ahorro una funcion
    FILE *p;
    p=fopen(FILE_DIPUTADOS,"rb+");
   if(p==NULL){
    return false;
    }
    fseek(p,sizeof(dip)*pos,SEEK_SET);
    dip.Estado=false;
    fwrite(&dip,sizeof dip,1,p); ///
    fclose(p);
    return true;
}
int CuentaElementoss(){
	Diputado aux;
	FILE *p;
	long tamanioarchivo;
   p=fopen(FILE_DIPUTADOS,"rb");
   if(p==NULL){
     cout <<"Error para abrir diputados"<<endl;
     return 0;
    }
   fseek(p, 0, SEEK_END); // voy al final del archivo para hacer un ftell para ver el tamaño en bytes del archivo, lo que hace el ftell me lee desde el princio hasta donde esta el puntero
   tamanioarchivo=ftell(p);
   fclose(p);
   return tamanioarchivo/sizeof(aux);
}
void OrdenAlfabetico(){
    int cantregis;
    Diputado *vec=NULL;
    cantregis=CuentaElementoss();
    vec=(struct Diputado *)malloc(cantregis*sizeof(Diputado));
    if(vec==NULL){
      return;
    }
    if(LeerDiputadoss(vec,cantregis)==true){ /// si no los leo, no me deja hacer el ordenamiento ya que se copia cuando lo leo en el vector
    ordenar_pu(vec,cantregis);
    ListarDiputadosXMEM(vec,cantregis);
    }
    free(vec);
}
bool LeerDiputadoss(Diputado *v, int tam){
  FILE *p;
  p = fopen(FILE_DIPUTADOS, "rb");
  if (p==NULL){
    return false;
  }
  bool r;
  r=fread(v, sizeof(Diputado), tam, p);
  fclose(p);
  return r;
}
void ListarDiputadosXMEM(struct Diputado *vec,int cantregis){
    for(int i=0;i<cantregis;i++){
    ListarDiputado(vec[i]);
    }
    system("pause");
    borrarPantalla();
}
void ordenar_pu(struct Diputado *vart,int cantregis){
int posmin;
struct Diputado aux;
for(int i=0;i<cantregis-1;i++){ // busca uno menos por que el ultimo no lo ordena
posmin=i;
for(int j=i+1;j<cantregis;j++){// i+1 por que compara con el anterior osea, agarro el primero en el primer for y el segundo lo campara contra el primero
if(strcmp(vart[j].Apellido,vart[posmin].Apellido)<0){ // si pongo menor a 0, es desde la 'A' hasta la 'Z', mayor a 0 es desde la 'Z' a 'A' e igual a 0 es por que son iguales
posmin=j; // y lo cambio si es verdadero
  }
}
aux=vart[i]; // copio el vector en la posicion i (ejemplo el el valor 20) al struct.
vart[i]=vart[posmin]; // copio la posicion minima(el valor 20) en el vector de la posicion i.
vart[posmin]=aux; // y copio el struct al vector.
  }
}
void ordenar_X_Anio(Diputado *vec, int cantregiss){
int posmin;
Diputado aux;
for(int i=0;i<cantregiss-1;i++){
  posmin=i;
  for(int j=i+1;j<cantregiss;j++){
      if(vec[j].Fin_Man<vec[posmin].Fin_Man){
    posmin=j;
      }
    }
  aux=vec[i];
  vec[i]=vec[posmin];
  vec[posmin]=aux;
  }
}
void OrdenXAnioF(){
int cantregis;
Diputado *vec=NULL;
cantregis=CuentaElementoss();
vec=(struct Diputado *)malloc(cantregis*sizeof(Diputado));
if(vec==NULL){
  cout<< "Error"<<endl;
  return;
}
  if(LeerDiputadoss(vec,cantregis)==true){
    ordenar_X_Anio(vec,cantregis);
    ListarDiputadosXMEM(vec,cantregis);
  }
  free(vec);
}
int CuentaElementossxanio(int anio){
   FILE *p;
   Diputado dip;
   int cant=0;
   p=fopen(FILE_DIPUTADOS,"rb");
   if(p==NULL){
      cout <<"error al abrir"<<endl;
      return 0;
   }
   while(fread(&dip,sizeof(Diputado),1,p)==1){
      if(anio==dip.Fin_Man){
         cant++;
      }
   }
   fclose(p);
   return cant;
}
void Finalizacion(){
  int anio,cant;
  Diputado_Proyect pro;
  cout <<"Ingreso de anio a buscar" <<endl;
  cin >> anio;
  Diputado_Proyect *vec=NULL;
  cant=CuentaElementossxanio(anio); // hacerlo por anio de ingreso al vector
  vec=(Diputado_Proyect *)malloc(cant*sizeof(Diputado_Proyect));
  if(vec==NULL){
      cout <<"error al dar memoria al vector"<<endl;
      return;
      }
  CompletarVector(vec,anio);
  CompletarProyecto(vec, cant);
  FILE *p;
  p=fopen("finalizaciones.dat","wb");
  if(p==NULL){
   cout <<"error al abrir finalizaciones en finalizacion()"<<endl;
   return;
  }
  fwrite(vec,sizeof(Diputado_Proyect),cant,p);
  fclose(p);
}
void CompletarVector(Diputado_Proyect *vec,int anio){
  FILE *p;
  Diputado dip;
  int i=0;
  p=fopen(FILE_DIPUTADOS,"rb");
  while(fread(&dip,sizeof(Diputado),1,p)==1){
    if(dip.Fin_Man==anio){
      strcpy(vec[i].Codigo_Diputado,dip.Codigo_Diputado);
      strcpy(vec[i].Apellido,dip.Apellido);
      strcpy(vec[i].nombre,dip.nombre);
      vec[i].Cod_Partido=dip.Cod_Partido;
      vec[i].Cod_Prov=dip.Cod_Prov;
      vec[i].Fin_Man=dip.Fin_Man;
      vec[i].canProyect=0;
      i++;
      }
    }
    fclose(p);
}
void CompletarProyecto(Diputado_Proyect *vec, int cant){
  FILE *p;
  struct proyecto pro;
  p=fopen("proyectos.dat","rb");
  if(p==NULL){
      return;
  }
  for(int i=0;i<cant;i++){ /// le hago un for por que tengo que recorrer de a 1 diputado, y recorrer todo el archivo de proyecto, por eso mismo.
                           /// si lo haria solo con la i=0, me contaria solo 1 diputado en 1 posicion del archivo de proyecto
  while(fread(&pro,sizeof(proyecto),1,p)==1){
      if(strcmp(vec[i].Codigo_Diputado,pro.Codigo_Diputado)==0){
          vec[i].canProyect++;
      }
    }
  }
  fclose(p);
}
// muestra el archivo de finalizacion.dat
void mostrarFina(){
   FILE *p;
   Diputado_Proyect pro;
   p=fopen("finalizaciones.dat","rb");
   if(p==NULL){
      cout <<"error finalizacion"<<endl;
      return;
   }
   while(fread(&pro,sizeof(Diputado_Proyect),1,p)==1){
      cout<<"cod diputado:    "<<pro.Codigo_Diputado<<endl;
      cout<<"nombre:          "<<pro.nombre<<endl;
      cout<<"apellido:        "<<pro.Apellido<<endl;
      cout<<"cantproy :       "<<pro.canProyect<<endl;
      cout<<"cod partido:     "<<pro.Cod_Partido<<endl;
      cout<<"cod prov:        "<<pro.Cod_Prov<<endl;
      cout<<"fin de mandato:  "<<pro.Fin_Man<<endl;

   }
   fclose(p);
   system("pause");
   borrarPantalla();
}
//int SumarProyectos(char [5]);
//void CantidadPRoyectoxDip(){
//   FILE *p;
//   Diputado dip;
//   int cant,pos=0;
//   p=fopen(FILE_DIPUTADOS,"rb+");
//   if(p==NULL){
//      return;
//   }
//   while(fread(&dip,sizeof(Diputado),1,p)==1){
//      cant=SumarProyectos(dip.Codigo_Diputado);
//      dip.CantPro=cant;
//      fseek(p,-(sizeof(Diputado)),SEEK_CUR);
//      fwrite()
//   }
//   fclose(p);
//}
//
//int SumarProyectos(char codigodip[5]){
//   FILE *p;
//   proyecto pro;
//   int cant=0;
//   p=fopen("proyectos.dat","rb");
//   if(p==NULL){
//         cout <<"Error"<<endl;
//      return -1;
//   }
//   while(fread(&pro,sizeof(struct proyecto),1,p)==1){
//      if(strcmp(codigodip,pro.Codigo_Diputado)==0){
//         cant++;
//      }
//   }
//   fclose(p);
//   return cant;
//}
void Menu_Diputados(){
 int opc;
    while(opc!=0){
    cout << "           MENU DIPUTADOS" << endl << "         ---------------------" << endl;
    cout << "           1) NUEVO DIPUTADO" << endl;
    cout << "           2) LISTAR TODOS LOS DIPUTADOS" << endl;
    cout << "           3) LISTAR DIPUTADO POR CODIGO DE PARTIDO" << endl;
    cout << "           4) BAJA A UN DIPUTADO " << endl;
    cout << "           5) MODIFICAR EL CODIGO DE UN DIPUTADO (borrar)" << endl;                                              /// despues borrar el 5
    cout << "           6) LISTAR DIPUTADOS POR ORDEN ALFABETICO" << endl;
    cout << "           7) LISTAR DIPUTADOS POR ANIO DE FINALIZACION" << endl;
    cout << "           8) DIPUTADO POR FINALIZACION DE MANDATO (NUEVO ARCHIVO)" <<endl;
    cout << "         --------------------" << endl;
    cout << "           0) VOLVER AL MENU ANTERIOR" << endl;
    cout << "           OPCION: ";
    cin >> opc;
    borrarPantalla();
        switch(opc){
    case 1:
        NuevoDiputado();
        break;
    case 2:
        ListarDiputados();
        break;
    case 3:
        mostrarPorCodigo();
        break;
    case 4:
        Baja();
        break;
    case 5:
        modificar();/// despues borrar el 5
        break;
    case 6:
        OrdenAlfabetico();
        break;
    case 7:
        OrdenXAnioF();
        break;
    case 8:
        Finalizacion();
        //mostrarFina(); // para mostrar el archivo de finalizacion
      break;
    case 0:
        break;
         default:
         cout <<"No es una opcion valida, Vuelva a intentarlo" <<endl<<endl;
         system("pause");
         borrarPantalla();
        }/// switch case 1
    } /// while case 1
}
#endif // DIPUTADOS_H_INCLUDED
