#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
   struct Diputado{
    char Codigo_Diputado[5];
    char Apellido[50];
    char nombre[50];
    int Cod_Partido;
    int Cod_Prov;
    int Fin_Man;
    bool Estado=true;
    };
   struct Diputado_Proyect{
    char Codigo_Diputado[5];
    char Apellido[50];
    char nombre[50];
    int Cod_Partido;
    int Cod_Prov;
    int Fin_Man;
    int canProyect;
    };
   struct Fecha{
  int dia, mes, anio;
   };
    struct proyecto{
   int Cod_Proyecto;
   char Nombre[150];
   char Codigo_Diputado[5];
   Fecha Fec;
   bool Estado=true;
   };
    struct sesion{
    int Cod_ses;
    Fecha Fec;
    int Cod_Proyecto;
    int VAfirmativos;
    int VNegativos;
    int Cant_absten;
    };
#endif // STRUCTS_H_INCLUDED
