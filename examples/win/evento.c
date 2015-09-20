 /*
  *  LnxCOMM is a Serial Port Library
  *  Copyright (C) 2008 2010 Fernando Pujaico Rivera <fernando.pujaico.rivera@gmail.com>
  *
  *  This program is free software; you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
  *  the Free Software Foundation; either version 2, or (at your option)
  *  any later version.
  *
  *  This program is distributed in the hope that it will be useful,
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *  GNU General Public License for more details.
  *
  *  You should have received a copy of the GNU General Public License
  *  along with this program; if not, write to the Free Software
  *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
  *
  */

/** \file
 *  \brief Ejemplo de uso de funciones con eventos.
 *
 *  La definición #define __WINDOWS_COM__  de este ejemplo nos dice que debe ser compilado 
 *  en un S.O. de tipo Microsot Windows.
 */

// gcc -o evento evento.c -lpthread
#define __WINDOWS_COM__
#define ENABLE_SERIAL_PORT_EVENT

#include "com/serial.h"

int numero=0; 
void SERIAL_PORT_EVENT(HANDLE * hPort)
{
    char c;
    Getc_Port(*hPort,&c);
    printf("[%d]=%c\n",numero,c); 
    numero++;
}

int main()
{
    HANDLE fd; 
    DCB OldConf;
    char cad[16]="Enviando Texto\n";
    int n;
    
    fd=Open_Port("COM1");               // Abre el puerto serie.
    
    OldConf=Get_Configure_Port(fd);     // Guardo la configuración del puerto.
    
    Configure_Port(fd,B115200,"8N1");   // Configuro el puerto serie.
    
    IO_Blocking(fd,TRUE);               // Bloqueante por defecto, pero también
                                        // se puede usar:
                                        // IO_Blocking(fd,TRUE); 
    
    n=Write_Port(fd,cad,16);            // Escribo en el puerto serie.
    
    Create_Thread_Port(&fd);            // Creo un hilo y le paso el manejador.

    while(TRUE);
    
    Set_Configure_Port(fd,OldConf);     // Restituyo la antigua configuración 
                                        // del puerto.

    Close_Port(fd);                     // Cierro el puerto serie.
    
    printf("\nPresione ENTER para terminar\n");
    getchar();
    
    return 0;
}

