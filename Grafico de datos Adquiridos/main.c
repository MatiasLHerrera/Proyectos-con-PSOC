/* ========================================
 *
 * Gracias a Federico Vivaldi por su tutorial, su link: 
 * https://www.hackster.io/federico-vivaldi/oled-display-with-psoc5-714e24
 *
 *
 * Gracias a NRDaza por esta libreria, su link: 
 * https://github.com/NRDaza/Oled-Psoc5/tree/master/OLED.cydsn
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

    display_init(DISPLAY_ADDRESS);

    
    for(;;){
        display_clear();
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        entero = ADC_GetResult32();
        ADC_StopConvert();
        voltaje = ADC_CountsTo_mVolts(entero);
        ADC = (voltaje / 1.00);
        sprintf(str,"%.2f",ADC);

        // line printing
        gfx_setTextSize(1);
        gfx_setTextColor(WHITE);
        gfx_setCursor(0,0);
        gfx_println("El valor del ADC es");
        gfx_println(str);
        CyDelay(10);
        display_update();
    
    }
}

/* [] END OF FILE */
