#include <NeoPixelBus.h>

const uint16_t PixelCount = 19; // this example assumes 4 pixels, making it smaller will cause a failure
const uint8_t PixelPin = 8;  // make sure to set this to the correct pin, ignored for Esp8266

#define colorSaturation 50

// three element pixels, in different order and speeds
// NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);
//NeoPixelBus<NeoRgbFeature, Neo400KbpsMethod> strip(PixelCount, PixelPin);

// For Esp8266, the Pin is omitted and it uses GPIO3 due to DMA hardware use.  
// There are other Esp8266 alternative methods that provide more pin options, but also have
// other side effects.
// For details see wiki linked here https://github.com/Makuna/NeoPixelBus/wiki/ESP8266-NeoMethods.

// You can also use one of these for Esp8266, 
// each having their own restrictions.
//
// These two are the same as above as the DMA method is the default.
// NOTE: These will ignore the PIN and use GPI03 pin.
NeoPixelBus<NeoGrbFeature, NeoEsp8266Dma800KbpsMethod> strip(PixelCount, PixelPin);
//NeoPixelBus<NeoRgbFeature, NeoEsp8266Dma400KbpsMethod> strip(PixelCount, PixelPin);

// Uart method is good for the Esp-01 or other pin restricted modules.
// for details see wiki linked here https://github.com/Makuna/NeoPixelBus/wiki/ESP8266-NeoMethods.
// NOTE: These will ignore the PIN and use GPI02 pin.
//NeoPixelBus<NeoGrbFeature, NeoEsp8266Uart1800KbpsMethod> strip(PixelCount, PixelPin);
//NeoPixelBus<NeoRgbFeature, NeoEsp8266Uart1400KbpsMethod> strip(PixelCount, PixelPin);

// The bitbang method is really only good if you are not using WiFi features of the ESP.
// It works with all but pin 16.
// NeoPixelBus<NeoGrbFeature, NeoEsp8266BitBang800KbpsMethod> strip(PixelCount, PixelPin);
//NeoPixelBus<NeoRgbFeature, NeoEsp8266BitBang400KbpsMethod> strip(PixelCount, PixelPin);

// four element pixels, RGBW
//NeoPixelBus<NeoRgbwFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0);

HslColor hslRed(red);
HslColor hslGreen(green);
HslColor hslBlue(blue);
HslColor hslWhite(white);
HslColor hslBlack(black);

void one(RgbColor color){
    strip.SetPixelColor(16, color);
}
void two(RgbColor color){
    strip.SetPixelColor(17, color);
}
void three(RgbColor color){
    strip.SetPixelColor(18, color);
}
void four(RgbColor color){
    strip.SetPixelColor(7, color);
}
void five(RgbColor color){
    strip.SetPixelColor(8, color);
}
void six(RgbColor color){
    strip.SetPixelColor(9, color);
}
void seven(RgbColor color){
    strip.SetPixelColor(10, color);
}
void eight(RgbColor color){
    strip.SetPixelColor(11, color);
}
void nine(RgbColor color){
    strip.SetPixelColor(12, color);
}
void ten(RgbColor color){
    strip.SetPixelColor(13, color);
}
void eleven(RgbColor color){
    strip.SetPixelColor(14, color);
}
void tvelve(RgbColor color){
    strip.SetPixelColor(15, color);
}
void clearNumbers(){
    for (int i = 7; i < 19; i++)
    {
        strip.SetPixelColor(i, black);
    }
}

void clearSecs(){
    for (int i = 0; i < 7; i++)
    {
        strip.SetPixelColor(i, black);
    }
}

void waitingForWifi(){
    for (int i = 7; i < 19; i++)
    {
        strip.SetPixelColor(i, black);
    }
}
