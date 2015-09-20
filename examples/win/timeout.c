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
 *  \brief Ejemplo de uso de funciones con Time-Out.
 *
 *  La definición #define __WINDOWS_COM__  de este ejemplo nos dice que debe ser compilado 
 *  en un S.O. de tipo Microsot Windows.
 */

// gcc -o timeout timeout.c
#define __WINDOWS_COM__

#include "com/serial.h"

int main()
{
    HANDLE fd; 
    DCB OldConf;
    char cad[16]="X";
    int n,TIME=2,i;

    fd=Open_Port("COM1");               // Abre el puerto serie.

    OldConf=Get_Configure_Port(fd);     // Guardo la configuración del puerto.

    Configure_Port(fd,B19200,"8N1");    // Configuro el puerto serie.

    Set_Time(fd,TIME);                  // Time-Out entre caracteres es TIME*0.1.

    n=Write_Port(fd,cad,1);             // Escribo en el puerto serie.

    n=Gets_Port(fd,cad,16);             // Leo el puerto serie.
    printf("%s",cad);                   // Muestro la cadena.

    Set_Configure_Port(fd,OldConf);     // Restituyo la antigua configuración 
                                        // del puerto.
    Close_Port(fd);                     // Cierro el puerto serie.

    printf("\nPresione ENTER para terminar\n");
    getchar();

    return 0;
}
