/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int fila = 0, columna = 0;
char dato;

CY_ISR(interruptRX) //Genero la rutina de interrupcion de RX de la UART
{
    dato = UART_GetChar();
    columna = columna + 1;
    if(columna == 16)
    {
        fila = 1;
        columna = 0;
    }
    LCD_Position(fila, columna);
    LCD_PutChar(dato);
}

int main(void)
{
    Clock_1_Start();
    LCD_Start();
    PWM_Start();
    RXisr_StartEx(interruptRX);
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start();
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
