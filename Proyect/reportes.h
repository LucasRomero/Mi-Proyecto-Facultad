#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED
void buscarCodProyecto(int );
void listardiputadoss(Diputado );
void listarproyecto(int);
bool buscarproyecto1(char *cod);
bool buscarSesion(int proy);
void PuntoAk(){
   FILE *p;
   Diputado dip;
   bool val;
   p=fopen(FILE_DIPUTADOS,"rb");
   if(p==NULL){
      cout <<"Error al abrir el archivo sesiones"<<endl;
      return;
   }
   while(fread(&dip,sizeof(Diputado),1,p)==1){
      val=buscarproyecto1(dip.Codigo_Diputado);
      if(val==true){
         ListarDiputado(dip);
         system("pause");
      }
   }
            borrarPantalla();
   fclose(p);
}
bool buscarproyecto1(char *cod){
   FILE *p;
   proyecto pro;
   bool val;
   p=fopen(FILE_PROYECTOS,"rb");
   if(p==NULL){
      cout <<"Error al abrir el archivo proyecto"<<endl;
      return false;
   }
   while(fread(&pro,sizeof(proyecto),1,p)==1){
         if(strcmp(pro.Codigo_Diputado,cod)==0){
               val=buscarSesion(pro.Cod_Proyecto);
               if(val==true){
                  fclose(p);
                  return true;
               }
         }
   }
   fclose(p);
   return false;
}
bool buscarSesion(int proy){
   FILE *p;
   sesion s;
   p=fopen(FILE_SESIONES,"rb");
   if(p==NULL){
      cout <<"Error al abrir el archivo sesiones"<<endl;
      return false;
   }
   while(fread(&s,sizeof(sesion),1,p)==1){
      if(s.Cod_Proyecto==proy){
      if(s.Fec.anio==2017){
         if(s.Fec.mes==9){
            fclose(p);
             return true;
         }
      }
    }
   }
   fclose(p);
   return false;
}
void PuntoB(){
   mostrarXCodigo();
}
void PuntoC(){
   FILE *p;
   sesion s;
   int sum;
   float total;
   p=fopen(FILE_SESIONES,"rb");
   if(p==NULL){
      cout <<"No se pudo abrir el archivo sesion 3"<<endl;
      return;
   }
   while(fread(&s,sizeof(sesion),1,p)==1){
         sum=s.VAfirmativos+s.VNegativos+s.Cant_absten;
         total=(float(s.VAfirmativos/sum))*100;
         if(total<25){
            listarproyecto(s.Cod_Proyecto);
         }
   }
   fclose(p);
}
void listarproyecto(int codpro){
   FILE *p;
   proyecto reg;
   p=fopen(FILE_PROYECTOS,"rb");
      if(p==NULL){
      cout <<"No se pudo abrir el archivo proyecto 3"<<endl;
      return;
   }
   while(fread(&reg,sizeof(proyecto),1,p)==1){
      if(reg.Cod_Proyecto==codpro){
    cout << "----------------------------------" << endl;
    cout << "Codigo de Diputado " << reg.Codigo_Diputado << endl;
    cout << "Codigo de Proyecto  "<< reg.Cod_Proyecto << endl;
    cout << "Nombre  " << reg.Nombre<< endl;
    cout << "Fecha del la Presentacion del proyecto  " << endl;
    cout << "Dia  " <<reg.Fec.dia << endl;
    cout <<"Mes:  "<< reg.Fec.mes << endl;
    cout <<"Anio:  "<< reg.Fec.anio << endl;
    if(reg.Estado){
      cout <<"Estado:  Activo"<<endl;
    }else{
    cout <<"Estado:  No Activo"<<endl;
    }
      }
   }
}
void Menu_Reportes(){
   int opc;
   while(opc!=0){
   cout <<"           MENU DE REPORTES" << endl << "         ---------------------" << endl;
   cout <<"            1) PUNTO A"<<endl;
   cout <<"            2) PUNTO B"<<endl;
   cout <<"            2) PUNTO C"<<endl;
   cout <<"         --------------------" << endl;
   cout <<"           0) VOLVER AL MENU ANTERIOR" << endl;
   cout <<"           OPCION: ";
   cin >>opc;
   borrarPantalla();
      switch (opc)
      {
      case 1:
         //PuntoA();
         PuntoAk();
         break;
      case 2:
         PuntoB();
         break;
      case 3:
         PuntoC();
         break;
      case 0:
         break;
      default:
         cout <<"No es una opcion valida, Vuelva a intentarlo" <<endl<<endl;
         system("pause");
         borrarPantalla();
      }
   }
}
#endif // REPORTES_H_INCLUDED
