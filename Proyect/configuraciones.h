#ifndef CONFIGURACIONES_H_INCLUDED
#define CONFIGURACIONES_H_INCLUDED
const char *FILE_BACKUP_DIP="diputados.bkp";
const char *FILE_BACKUP_SES="sesiones.bkp";
const char *FILE_BACKUP_PRO="proyectos.bkp";
void CopiarDip_al_bkp(){
   FILE *Fdip;
   FILE *FdipB;
   Diputado dip;
   Fdip=fopen(FILE_DIPUTADOS,"rb");
   if(Fdip==NULL){
      cout <<"Error Open Diputados"<<endl;
      return;
   }
   FdipB=fopen(FILE_BACKUP_DIP,"wb");
   if(FdipB==NULL){
      cout <<"Error Open Diputados.BKP"<<endl;
      return;
   }
   while(fread(&dip,sizeof(dip),1,Fdip)==1){
    fwrite(&dip,sizeof(dip),1,FdipB);
   }
   fclose(Fdip);
   fclose(FdipB);
}
void CopiarPro_al_bkp(){
   FILE *Fpro;
   FILE *FproB;
   proyecto pro;

   Fpro=fopen(FILE_PROYECTOS,"rb");
   if(Fpro==NULL){
      cout <<"Error Open Proyecto"<<endl;
      return;
   }
   FproB=fopen(FILE_BACKUP_PRO,"wb");
   if(FproB==NULL){
      cout <<"Error Open Proyecto.BKP"<<endl;
      return;
   }
   while(fread(&pro,sizeof(pro),1,Fpro)==1){
    fwrite(&pro,sizeof(pro),1,FproB);
   }
   fclose(Fpro);
   fclose(FproB);
}
void CopiarSes_al_bkp(){
   FILE *Fses;
   FILE *FsesB;
   sesion s;

   Fses=fopen(FILE_SESIONES,"rb");
   if(Fses==NULL){
      cout <<"Error Open Sesiones"<<endl;
      return;
   }
   FsesB=fopen(FILE_BACKUP_SES,"wb");
   if(FsesB==NULL){
      cout <<"Error Open Sesiones.BKP"<<endl;
      return;
   }
   while(fread(&s,sizeof(s),1,Fses)==1){
    fwrite(&s,sizeof(s),1,FsesB);
   }
   fclose(Fses);
   fclose(FsesB);
}
void Restaurar(){
   FILE *Fses;
   FILE *FsesB;
   sesion s;
   FsesB=fopen(FILE_BACKUP_SES,"rb");
   if(FsesB==NULL){
      cout <<"Error Open Sesiones.BKP"<<endl;
      return;
   }
   Fses=fopen(FILE_SESIONES,"wb");
   if(Fses==NULL){
      cout <<"Error Open Sesiones"<<endl;
      return;
   }
   while(fread(&s,sizeof(s),1,FsesB)==1){
    fwrite(&s,sizeof(s),1,Fses);
   }
   fclose(Fses);
   fclose(FsesB);
   //-------------
   FILE *Fpro;
   FILE *FproB;
   proyecto pro;
   FproB=fopen(FILE_BACKUP_PRO,"rb");
   if(FproB==NULL){
      cout <<"Error Open Proyecto.BKP"<<endl;
      return;
   }
   Fpro=fopen(FILE_PROYECTOS,"wb");
   if(Fpro==NULL){
      cout <<"Error Open Proyecto"<<endl;
      return;
   }
   while(fread(&pro,sizeof(pro),1,FproB)==1){
    fwrite(&pro,sizeof(pro),1,Fpro);
   }
   fclose(Fpro);
   fclose(FproB);
   //--------------------
   FILE *Fdip;
   FILE *FdipB;
   Diputado dip;
   FdipB=fopen(FILE_BACKUP_DIP,"rb");
   if(FdipB==NULL){
      cout <<"Error Open Diputados.BKP"<<endl;
      return;
   }
   Fdip=fopen(FILE_DIPUTADOS,"wb");
   if(Fdip==NULL){
      cout <<"Error Open Diputados"<<endl;
      return;
   }
   while(fread(&dip,sizeof(dip),1,FdipB)==1){
    fwrite(&dip,sizeof(dip),1,Fdip);
   }
   fclose(Fdip);
   fclose(FdipB);
}
/*bool CopiaDip_Al_Vec(Diputado *);
bool CopiaPro_Al_Vec(proyecto *);
bool CopiaSes_Al_Vec(sesion *);
bool CopiaPROBK_AL_Vec(proyecto *);
bool CopiaDIPBK_AL_Vec(Diputado *);
bool CopiaSESBK_AL_Vec(sesion *);
bool valdip,valpro,valses;
void BackUp(){
   int cant;
      FILE *p;
      p=fopen(FILE_BACKUP_DIP,"wb");
      if(p==NULL){
         return;
      }
   Diputado dip;
   Diputado *v=NULL;
   cant=CuentaElementoss();
   v=(Diputado *)malloc(cant*sizeof(Diputado));
   if(v==NULL){
      return;
   }
   valdip=CopiaDip_Al_Vec(v);
   fwrite(v,sizeof(Diputado),cant,p); //ver que onda
   fclose(p);
   free(v);
   //----------------------------------------
   FILE *d;
   d=fopen(FILE_BACKUP_PRO,"wb");
   if(p==NULL){
      return;
   }
   proyecto pro;
   proyecto *vec=NULL;
   cant=CuentaElementos();
   vec=(proyecto *)malloc(cant*sizeof(proyecto));
   valpro=CopiaPro_Al_Vec(vec);
   fwrite(v,sizeof(proyecto),cant,d);
   fclose(d);
   free(vec);
   //-----------------------------------------
   FILE *s;
   s=fopen(FILE_BACKUP_SES,"wb");
   if(p==NULL){
      cout <<"error al abrir sesiones.kbp"<<endl;
      return;
   }
   sesion *vecs=NULL;
   cant=CantElementosSe();
   vecs=(sesion *)malloc(cant*sizeof(sesion));
   valses=CopiaSes_Al_Vec(vecs);
   fwrite(vecs,sizeof(sesion),cant,s);
   fclose(s);
   free(vecs);
   if(valdip&&valpro&&valses){
      cout<<"           LA COPIA DE SEGURIDAD SE HA GENERADO CORRECTAMENTE"<<endl<<endl<<endl;
      system("pause");
      borrarPantalla();
   }
}
bool CopiaSes_Al_Vec(sesion *vec){
   FILE *p;
   sesion s;
   int i=0;
   p=fopen(FILE_SESIONES,"rb");
   if(p==NULL){
      cout <<"erroralabrirsesiones"<<endl;
      return false;
   }
   while(fread(&s,sizeof(sesion),1,p)==1){
   vec[i]=s;
   i++;
   }
   fclose(p);
   return true;
}
bool CopiaPro_Al_Vec(proyecto *vec){
   FILE *p;
   int i=0;
   proyecto pro;
   p=fopen(FILE_PROYECTOS,"rb");
   if(p==NULL){
      return false;
   }
   while(fread(&pro,sizeof(proyecto),1,p)==1){
        strcpy(vec[i].Codigo_Diputado,pro.Codigo_Diputado);
        vec[i].Cod_Proyecto=pro.Cod_Proyecto;
        vec[i].Estado=pro.Estado;
        vec[i].Fec.dia=pro.Fec.dia;
        vec[i].Fec.mes=pro.Fec.mes;
        vec[i].Fec.anio=pro.Fec.anio;
        strcpy(vec[i].Nombre,pro.Nombre);
        i++;
   }
   fclose(p);
   return true;
}
bool CopiaDip_Al_Vec(Diputado *vec){
   FILE *p;
   Diputado dip;
   int i=0;
   p=fopen(FILE_DIPUTADOS,"rb");
   if(p==NULL){
      return false;
   }
   while(fread(&dip,sizeof(Diputado),1,p)==1){
      vec[i]=dip;
      i++;

   }
   fclose(p);
   return true;
}
int cantElementosBkpDip(){
   FILE *p;
   long cant;
   Diputado dip;
   p=fopen(FILE_BACKUP_DIP,"rb");
   if(p==NULL){
      cout<<"Error al abrir diputado.bkp"<<endl;
      exit(1);
   }
   fseek(p,0,SEEK_END);
   cant=ftell(p);
   fclose(p);
   return cant/sizeof(dip);
}
int cantElementosBkpPro(){
   FILE *p;
   long cant;
   p=fopen(FILE_BACKUP_PRO,"rb");
   if(p==NULL){
      cout <<"error"<<endl;
      return 0;
   }
   fseek(p,0,SEEK_END);
   cant=ftell(p);
   fclose(p);
   return cant/sizeof(proyecto);
}
int cantElementosBkpSes(){
   FILE *p;
   long cant;
   p=fopen(FILE_BACKUP_SES,"rb");
   if(p==NULL){
      return 0;
   }
    fseek(p,0,SEEK_END);
    cant=ftell(p);
    return cant/sizeof(sesion);
   }
void RestaurarBackUp(){
   FILE *p;
   int cant;
   Diputado *vecd=NULL;
   p=fopen(FILE_DIPUTADOS,"wb");
   cant=cantElementosBkpDip();
   vecd=(Diputado *)malloc(cant*sizeof(Diputado));
   valdip=CopiaDIPBK_AL_Vec(vecd);
   fwrite(vecd,sizeof(Diputado),cant,p);
   fclose(p);
   free(vecd);
   //----------------------------------------
   FILE *d;
   proyecto *vecp=NULL;
   d=fopen(FILE_PROYECTOS,"wb");
   cant=cantElementosBkpPro();
   vecp=(proyecto *)malloc(cant*sizeof(proyecto));
   valpro=CopiaPROBK_AL_Vec(vecp);
   fwrite(vecp,sizeof(proyecto),cant,d);
   fclose(d);
   free(vecp);
   //----------------------------------------
   FILE *s;
   sesion *vecs=NULL;
   s=fopen(FILE_SESIONES,"wb");
   cant=cantElementosBkpSes();
   vecs=(sesion *)malloc(cant*sizeof(sesion));
   valses=CopiaSESBK_AL_Vec(vecs);
   fwrite(vecs,sizeof(sesion),cant,s);
   fclose(s);
   free(vecs);

   if(valdip&&valpro&&valses){
   cout<<"           LA COPIA DE SEGURIDAD SE HA REESTABLECIDO CORRECTAMENTE"<<endl<<endl<<endl;
   system("pause");
   borrarPantalla();
   }
}
bool CopiaSESBK_AL_Vec(sesion *vec){
   FILE *p;
   sesion s;
   int i=0;
   p=fopen(FILE_BACKUP_SES,"rb");
   if(p==NULL){
      cout <<"error al abrir sesiones.bkp"<<endl;
      return false;
   }
   while(fread(&s,sizeof(sesion),1,p)==1){
   vec[i]=s;
   i++;
   }
   fclose(p);
   return true;
}
bool CopiaPROBK_AL_Vec(proyecto *vecp){
   FILE *p;
   int i=0;
   proyecto pro;
   p=fopen(FILE_BACKUP_PRO,"rb");
   if(p==NULL){
      cout <<"ERROR"<<endl;
      return false;
   }
   while(fread(&pro,sizeof(proyecto),1,p)==1){
        vecp[i]=pro;
        i++;
   }
   fclose(p);
   return true;
}
bool CopiaDIPBK_AL_Vec(Diputado *vec){   /// PREGUNTAR SI NO SE PUEDE HACER TANTAS FUNCIONES POR QUE ES TODO SIMILAR Y ES MUCHO CODIGO VER SI SE PUEDE SER MEJOR EL CODIGO Y MAS CORTO
   FILE *p;
   Diputado dip;
   int i=0;
   p=fopen(FILE_BACKUP_DIP,"rb");
   if(p==NULL){
      cout <<"error"<<endl;
      return false;
   }
   while(fread(&dip,sizeof(Diputado),1,p)==1){
      vec[i]=dip;
      i++;
   }
   fclose(p);
   return true;
}
*//*
void mostrar(){
   FILE *p;
   Diputado dip;
   p=fopen(FILE_BACKUP_DIP,"rb");
   while(fread(&dip,sizeof(Diputado),1,p)==1){
      cout <<dip.Apellido<<endl;
      cout <<dip.Codigo_Diputado<<endl;
      cout <<dip.Cod_Partido<<endl;
      cout <<dip.Cod_Prov<<endl;
      cout <<dip.Estado<<endl;
      cout <<dip.Fin_Man<<endl;
      cout <<dip.nombre<<endl;
   }
   fclose(p);
}
*/
void Menu_Configuraciones(){
   int opc;
   while(opc!=0){
   cout <<"           MENU DE CONFIGURACIONES" << endl << "         ---------------------" << endl;
   cout <<"            1)REALIZAR COPIA DE SEGURIDAD"<<endl;
   cout <<"            2)RESTAURAR COPIA DE SEGURIDAD"<<endl;
   cout <<"         --------------------" << endl;
   cout <<"           0) VOLVER AL MENU ANTERIOR" << endl;
   cout <<"           OPCION: ";
   cin >>opc;
   borrarPantalla();
      switch (opc)
      {
      case 1:
         CopiarDip_al_bkp();
         CopiarPro_al_bkp();
         CopiarSes_al_bkp();
         //BackUp();
         break;
      case 2:
         Restaurar();
         //mostrar();
         //RestaurarBackUp();
         break;
      case 0:
         break;
      }
   }
}
#endif // CONFIGURACIONES_H_INCLUDED
