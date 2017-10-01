#ifndef SESIONES_H_INCLUDED
#define SESIONES_H_INCLUDED
const char *FILE_SESIONES = "sesiones.dat";
///-----------------------FUNCIONES-----------------------
bool validarVotos(int);
int ValidarCod_Ses(int);
int ValidarCod_Pro(int);
void ListarSesion(sesion);
sesion devolverSexCod(int);
bool ValidarProyectoXPos(int ,int );
bool EditVotos(sesion,int);
bool ValidarSesPro(int ,int );
void Nuevasesiones(){
    FILE *p;
    sesion s;
    bool v;
    int pos;
    Fecha auxfecha;
    p=fopen(FILE_SESIONES,"ab");
    if(p==NULL){
      return;
      }
    cout <<"Codigo de Proyecto"<<endl;
    cin >> s.Cod_Proyecto;
    pos=ValidarCod_Pro(s.Cod_Proyecto);
    while(pos<0){
    cout <<"Codigo de Proyecto Erroneo, Intente Nuevamente"<<endl;
    cin >> s.Cod_Proyecto;
    pos=ValidarCod_Pro(s.Cod_Proyecto);
    }
    cout<<"Codigo de Sesion  "<<endl;
    cin >> s.Cod_ses;
    bool val;
    val=ValidarSesPro(s.Cod_Proyecto,s.Cod_ses);
    while(val){
    cout << "Yan hay un archivo igual, Intente cambiar"<<endl;
    cout << "Codigo de Proyecto"<<endl;
    cin >> s.Cod_Proyecto;
    pos=ValidarCod_Pro(s.Cod_Proyecto);
    while(pos<0){
    cout <<"Codigo de Proyecto Erroneo, Intente Nuevamente"<<endl;
    cin >> s.Cod_Proyecto;
    pos=ValidarCod_Pro(s.Cod_Proyecto);
    }
    cout<<"Codigo de Sesion  "<<endl;
    cin >> s.Cod_ses;
    val=ValidarSesPro(s.Cod_Proyecto,s.Cod_ses);
      }
    cout <<"Votos Afirmativos"<<endl;
    cin >> s.VAfirmativos;
    v=validarVotos(s.VAfirmativos);
   while(!v){
      cout <<"Los Votos deben ser Mayor o Igual a 0, Intente Nuevamente"<<endl;
      cin >> s.VAfirmativos;
      v=validarVotos(s.VAfirmativos);
   }
    cout <<"Votos Negativos"<<endl;
    cin >> s.VNegativos;
    v=validarVotos(s.VNegativos);
       while(!v){
      cout <<"Los Votos deben ser Mayor o Igual a 0, Intente Nuevamente"<<endl;
      cin >> s.VNegativos;
      v=validarVotos(s.VNegativos);
   }
    cout <<"Cantidad de Abstenciones"<<endl;
    cin >> s.Cant_absten;
        v=validarVotos(s.Cant_absten);
       while(!v){
      cout <<"Las Abstenciones deben ser Mayor o Igual a 0, Intente Nuevamente"<<endl;
      cin >> s.Cant_absten;
      v=validarVotos(s.Cant_absten);
   }
    cout << "Fecha de la Sesion: " << endl;
    cout << "Dia: ";
    cin >> auxfecha.dia;
    cout << "Mes: ";
    cin >> auxfecha.mes;
    cout << "Anio: ";
    cin >> auxfecha.anio;
    while(!(validarFecha(&auxfecha.dia, &auxfecha.mes, &auxfecha.anio))){
        cout << "Fecha erronea, intente nuevamente: ";
        cout << "Fecha de la Sesion: " << endl;
        cout << "Dia: ";
        cin >> auxfecha.dia;
        cout << "Mes: ";
        cin >> auxfecha.mes;
        cout << "Anio: ";
        cin >> auxfecha.anio;
    }
    s.Fec.dia = auxfecha.dia;
    s.Fec.mes = auxfecha.mes;
    s.Fec.anio = auxfecha.anio;
    fwrite(&s,sizeof (sesion),1,p);
    fclose(p);
    borrarPantalla();
    }
bool ValidarSesPro(int Cod_Proyecto,int Cod_ses){
   FILE *p;
   sesion s;
   p=fopen(FILE_SESIONES,"rb");
   if(p==NULL){
      return false;
   }
   while(fread(&s,sizeof(sesion),1,p)==1){
         if(Cod_Proyecto==s.Cod_Proyecto && Cod_ses==s.Cod_ses){
            fclose(p);
            return true;
         }
   }
   fclose(p);
   return false;
    }
bool validarVotos(int voto){
      if(voto<0){
         return false;
      }
      return true;
    }
int ValidarCod_Ses(int cod){
   FILE *p;
   sesion s;
   int pos=0;
   p=fopen(FILE_SESIONES,"rb");
   if(p==NULL){
      return -1;
   }
   while(fread(&s,sizeof(sesion),1,p)==1){
      if(cod==s.Cod_ses){
         return pos;
      }
      pos++;
   }
   fclose(p);
   return -1;
}
int ValidarCod_Pro(int cod){
   FILE *p;
   proyecto pp;
   int pos=0;
   p=fopen(FILE_PROYECTOS,"rb");
      if(p==NULL){
      return -1;
   }
   while(fread(&pp,sizeof(proyecto),1,p)==1){
      if(cod==pp.Cod_Proyecto){
         return pos;
      }
      pos++;
      }
      fclose(p);
      return -1;
   }
void ListarSesiones(){
   FILE *p;
   sesion s;
   p=fopen(FILE_SESIONES,"rb");
   if(p==NULL){
      cout <<"ERROR AL ABRIR SESION"<<endl;
      return;
   }
   while(fread(&s,sizeof(sesion),1,p)==1){
         ListarSesion(s);
      }
   fclose(p);
   system("pause");
   borrarPantalla();
 }
void ListarSesion(sesion s){
   cout << "---------------------------" << endl;
   cout <<"Codigo de Sesion: " <<s.Cod_ses<<endl;
   cout <<"Codigo de Proyecto:  "<<s.Cod_Proyecto<<endl;
   cout <<"Dia:  "<<s.Fec.dia<<endl;
   cout <<"Mes:  "<<s.Fec.mes<<endl;
   cout <<"Anio:  "<<s.Fec.anio<<endl;
   cout <<"Votos Afirmativos:  "<<s.VAfirmativos<<endl;
   cout <<"Votos Negativos:  "<<s.VNegativos<<endl;
   cout <<"Cantidad de Abstenciones:  "<<s.Cant_absten<<endl;
}
int CantElementosSe(){
   FILE *p;
   sesion aux;
   long cant;
   p=fopen(FILE_SESIONES,"rb");
   if(p==NULL){
      exit(1);
   }
   fseek(p,0,SEEK_END);
   cant=ftell(p);
   fclose(p);
   return cant/sizeof(aux);
}
void SesionXCod(){
   int Cod_Ses;
   int proyec;
   int pos;
   bool val;
   sesion s;
   cout <<"Ingresar Codigo de Sesion "<<endl;
   cin >> Cod_Ses;
   pos=ValidarCod_Ses(Cod_Ses);
   if(pos<0){
      cout <<"El Codigo de Sesion No Existe"<<endl;
      return;
   }
   cout <<"Codigo de Proyecto "<<endl;
   cin >> proyec;
   val=ValidarProyectoXPos(proyec,pos);
   if(!val){
      cout <<"Codigo de Proyecto no valido para El Codigo de Sesion"<<endl;
      return;
   }
   s=devolverSexCod(pos);
   ListarSesion(s);
   system("pause");
   borrarPantalla();
}
sesion devolverSexCod(int pos){
   FILE *p;
   sesion s;
   p=fopen(FILE_SESIONES,"rb");
   if(p==NULL){
      exit(1);
   }
   fseek(p,pos*sizeof(sesion),SEEK_SET);
   fread(&s,sizeof(sesion),1,p);
   fclose(p);
   return s;
}
bool ValidarProyectoXPos(int proyec,int pos){
   FILE *p;
   sesion s;
   p=fopen(FILE_SESIONES,"rb");
   if(p==NULL){
      return false;
   }
   fseek(p,pos*sizeof(sesion),SEEK_SET);
   if(proyec==s.Cod_Proyecto){
      fclose(p);
      return true;
   }
   fclose(p);
   return false;
}
void EditSesion(){
   int Cod_Ses;
   int proyec;
   int pos;
   bool val;
   sesion s;
   cout <<"Ingresar Codigo de Sesion "<<endl;
   cin >> Cod_Ses;
   pos=ValidarCod_Ses(Cod_Ses);
   if(pos<0){
      cout <<"El Codigo de Sesion No Existe"<<endl;
      system("pause");
      borrarPantalla();
      return;
   }
   cout <<"Codigo de Proyecto "<<endl;
   cin >> proyec;
   val=ValidarProyectoXPos(proyec,pos);
   if(!val){
      cout <<"Codigo de Proyecto no valido para El Codigo de Sesion"<<endl;
      system("pause");
      borrarPantalla();
      return;
   }
   s=devolverSexCod(pos);
   if(EditVotos(s,pos)){
      cout <<"El Cambio de Votos fue Reemplazado con Exito"<<endl<<endl<<endl<<endl;
   }
   system("pause");
   borrarPantalla();
}
bool EditVotos(sesion s,int pos){
   FILE *p;
   p=fopen(FILE_SESIONES,"rb+");
   if(p==NULL){
      return false;
   }
   fseek(p,pos*sizeof(sesion),SEEK_SET);
   cout <<"Votos Afirmativos"<<endl;
   cin >>s.VAfirmativos;
   cout <<"Votos Negativos"<<endl;
   cin >>s.VNegativos;
   cout <<"Cantidad de Abstenciones"<<endl;
   cin >>s.Cant_absten;
   fwrite(&s,sizeof(sesion),1,p);
   fclose(p);
   return true;
}
Menu_Sesiones(){
   int opc;
   while(opc!=0){
       cout << "           MENU SESIONES" << endl << "         ---------------------" << endl;
       cout << "           1) NUEVA SESION" <<endl;
       cout << "           2) EDITAR SESION" <<endl;
       cout << "           3) LISTAR SESIONES" <<endl;
       cout << "           4) LISTAR SESION POR CODIGO" <<endl;
       cout << "         --------------------" << endl;
       cout << "           0) VOLVER AL MENU ANTERIOR" << endl;
       cout << "           OPCION: ";
       cin >> opc;
       borrarPantalla();
     switch(opc){
     case 1:
        Nuevasesiones();
       break;
     case 2:
        EditSesion();
       break;
     case 3:
        ListarSesiones();
       break;
     case 4:
        SesionXCod();
      break;
       }
     }
   }
#endif // SESIONES_H_INCLUDED
