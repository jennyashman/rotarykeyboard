#include "mbed.h"
#include "USBKeyboard.h"

AnalogIn potentiometer(A0);
PwmOut led(LED1);
char str[10];
DigitalIn selectButton(D2);
DigitalIn spaceButton(D3);
DigitalIn deleteButton(D4);

Serial pc(USBTX, USBRX);
USBKeyboard keyboard;

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main() 
{
    selectButton.mode(PullUp);
    spaceButton.mode(PullUp);
    deleteButton.mode(PullUp);
    led.period(0.001);
    while(1) 
    {
        led=(float)(potentiometer);
        float val = map(potentiometer, 0.00,1.00,0.00,2000.00);
        sprintf(str, "%d \n", (int)val);
        
        pc.printf(str);
        
        if (spaceButton)
        {
            keyboard.keyCode(' ', 0);
            wait(0.50);
        }
        
        if (deleteButton)
        {
            keyboard.keyCode('H', 1);
            wait(0.50);
        }
        
        if (selectButton)
        {
            if(val>24&&val<29)
            {
                pc.printf("A");
                keyboard.keyCode('a', 0);  
            }
            if(val>30&&val<35)
            {
                pc.printf("B");
                keyboard.keyCode('b', 0);
            }
             if(val>36&val<41)
            {
                pc.printf("C");
                keyboard.keyCode('c', 0);
            }
             if(val>42&&val<47)
            {
                pc.printf("D");
                keyboard.keyCode('d', 0);
            }
             if(val>48&&val<53)
            {
                pc.printf("E");
                keyboard.keyCode('e', 0);
            }
             if(val>53&&val<58)
            {
                pc.printf("F");
                keyboard.keyCode('f', 0);
            }
             if(val>58&&val<66)
            {
                pc.printf("G");
                keyboard.keyCode('g', 0);
            }
             if(val>66&&val<71)
            {
                pc.printf("H");
                keyboard.keyCode('h', 0);
            }
             if(val>71&&val<77)
            {
                pc.printf("I");
                keyboard.keyCode('i', 0);
            }
             if(val>77&&val<83)
            {
                pc.printf("J");
                keyboard.keyCode('j', 0);
            }
             if(val>83&&val<90)
            {
                pc.printf("K");
                keyboard.keyCode('k', 0);
            }
             if(val>90&&val<95)
            {
                pc.printf("L");
                keyboard.keyCode('l', 0);
            }
             if(val>95&&val<100)
            {
                pc.printf("M");
                keyboard.keyCode('m', 0);
            }
             if(val>100&&val<107)
            {
                pc.printf("N");
                keyboard.keyCode('n', 0);
            }
             if(val>107&&val<113)
            {
                pc.printf("O");
                keyboard.keyCode('o', 0);
            }
             if(val>113&&val<120)
            {
                pc.printf("P");
                keyboard.keyCode('p', 0);
            }
             if(val>120&&val<126)
            {
                pc.printf("Q");
                keyboard.keyCode('q', 0);
            }
             if(val>126&&val<132)
            {
                pc.printf("R");
                keyboard.keyCode('r', 0);
            }
             if(val>132&&val<138)
            {
                pc.printf("S");
                keyboard.keyCode('s', 0);
            }
             if(val>138&&val<145)
            {
                pc.printf("T");
                keyboard.keyCode('t', 0);
            }
             if(val>145&&val<150)
            {
                pc.printf("U");
                keyboard.keyCode('u', 0);
            }
             if(val>150&&val<157)
            {
                pc.printf("V");
                keyboard.keyCode('v', 0);
            } 
            if(val>157&&val<163)
            {
                pc.printf("W");
                keyboard.keyCode('w', 0);
            }
             if(val>163&&val<168)
            {
                pc.printf("X");
                keyboard.keyCode('x', 0);
            }
             if(val>168&&val<174)
            {
                pc.printf("Y");
                keyboard.keyCode('y', 0);
            }
             if(val>174&&val<179)
            {
                pc.printf("Z");
                keyboard.keyCode('z', 0);
            }
               }     
            wait(0.30);
        }
}