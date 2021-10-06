/* ========================================
 *
 * Gracias a Federico Vivaldi por su tutorial, su link: 
 * https://www.hackster.io/federico-vivaldi/oled-display-with-psoc5-714e24
 *
 *
 * Gracias a NRDaza por esta libreria, su link: 
 * https://github.com/NRDaza/Oled-Psoc5/tree/master/OLED.cydsn
 *
 * Gracias a AQUILES VAESA, su video fue la motivación a realizar este proyecto:
 * https://www.youtube.com/watch?v=ijmjDXAONzY
 *
 * ========================================
*/
#include <project.h>
#include <stdlib.h>
#include <stdio.h>

#include "ssd1306.h"

#define DISPLAY_ADDRESS 0x3C // 011110+SA0+RW - 0x3C or 0x3D

int main(){

   I2COLED_Start();
   Opamp_Start();

   ADC_Start();

   int32 entero,voltaje;
   float32 ADC;
   char str[16];
   CyGlobalIntEnable;

   float graficaVoltaje = 0;

   int x[128]; //buffer de la grafica 
   int y[128]; //buffer secundario de la grafica 

   display_init(DISPLAY_ADDRESS);
   gfx_setRotation(0);  // se escoje la orientacion del display puede ser 0 o 2
   gfx_setTextColor(WHITE);
   gfx_setTextSize(1);  // ajusta el tamaño de texto en el minimo valor

  //llenamos las matrices con un valor fuera del rango de medicion >1023
   for(int i=127;i>=0;i--)   
    {
    x[i]=9999;
    }
   for(int i=127;i>=0;i--)
    {
    y[i]=9999;
    }

    
    for(;;){
        display_clear();
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        entero = ADC_GetResult32();
        ADC_StopConvert();
        voltaje = ADC_CountsTo_mVolts(entero);
        ADC = (voltaje / 1.00);
        sprintf(str,"%.2f",ADC);
        
        //dibuja escala
        gfx_setCursor(0, 0); 
        gfx_print(("5V")); 
        gfx_setCursor(0, 11);   
        gfx_print(("4V"));
        gfx_setCursor(0, 22); 
        gfx_print(("3V"));
        gfx_setCursor(0, 32);  
        gfx_print(("2V"));      
        gfx_setCursor(0, 43); 
        gfx_print(("1V")); 

        gfx_drawLine(15, 0, 25, 0, WHITE);
        gfx_drawLine(15, 11, 25, 11, WHITE);
        gfx_drawLine(15, 22, 25, 22, WHITE);
        gfx_drawLine(15, 32, 25, 32, WHITE);
        gfx_drawLine(15, 43, 25, 43, WHITE);
        //dibuja eje X y Y 
        gfx_drawLine(0, 53, 127, 53, WHITE);
        gfx_drawLine(25, 53, 25, 0, WHITE);
 
        graficaVoltaje= 53 - 53*entero/1023;
       
        x[127]=graficaVoltaje; //asigna el valor escalado a el ultimo dato de la matriz
  
        for(int i=127;i>=25;i--)
        { 
            gfx_drawPixel(i, x[i], WHITE); //dibuja punto a punto el contenido de x
            y[i-1]=x[i]; //guarda la informacion desplazada una posicion temporalmente en y
        }
        //imprime el voltaje en texto  
        gfx_setCursor(25, 57); 
        gfx_print(str);
        gfx_print((" v    "));

        for(int i=127;i>=0;i--)
                {
                x[i]=y[i]; //envia los datos desplazados de vuelta a la variable x
                }
        CyDelay(10);
        display_update();
    }
}

/* [] END OF FILE */
