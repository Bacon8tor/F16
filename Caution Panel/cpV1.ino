#define DCSBIOS_IRQ_SERIAL

#include <DcsBios.h>
#include <FastLED.h>

#define DATA_PIN 2 
#define CP_NUM_LEDS 64



CRGB cp_leds[CP_NUM_LEDS];

//ordered according to panel lights position and corresponding leds num i.e. flcs fault leds (6,7)
int cp_order[8][4][2] = {
{{6,7},{4,5},{2,3},{0,1} },
{{8,9},{10,11},{12,13},{14,15}},
{{22,23},{20,21},{18,19},{16,17}},
{{24,25},{26,27},{28,29},{30,31}},
{{38,39},{36,37},{34,35},{32,33}},
{{40,41},{42,43},{44,45},{46,47}},
{{54,55},{52,53},{50,51},{48,49}},
{{56,57},{58,59},{60,61},{62,63}}
};

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(cp_leds, CP_NUM_LEDS);
 // Serial.begin(9600);
  DcsBios::setup();
  startTest();
  FastLED.setBrightness(150);
}

void loop() {
 DcsBios::loop();
}

//Stuff from DCS BIOS 
void onLightFlcsChange(unsigned int newValue) {
   if( newValue == 1){ lightON(0,0); }
   else { lightOFF(0,0);}
}
DcsBios::IntegerBuffer lightFlcsBuffer(0x4474, 0x0002, 1, onLightFlcsChange);

void onLightEngineFaultChange(unsigned int newValue) {
    if( newValue == 1){ lightON(0,1); }
   else { lightOFF(0,1);}
}
DcsBios::IntegerBuffer lightEngineFaultBuffer(0x446e, 0x1000, 12, onLightEngineFaultChange);

void onLightAvionicsFaultChange(unsigned int newValue) {
    if( newValue == 1){ lightON(0,2); }
   else { lightOFF(0,2);}
}
DcsBios::IntegerBuffer lightAvionicsFaultBuffer(0x446e, 0x2000, 13, onLightAvionicsFaultChange);

void onLightSeatNotChange(unsigned int newValue) {
     if( newValue == 1){ lightON(0,3); }
   else { lightOFF(0,3);}
}
DcsBios::IntegerBuffer lightSeatNotBuffer(0x446e, 0x4000, 14, onLightSeatNotChange);

void onLightElecSysChange(unsigned int newValue) {
 if( newValue == 1){ lightON(1,0); }
   else { lightOFF(1,0);}
 }
DcsBios::IntegerBuffer lightElecSysBuffer(0x446e, 0x8000, 15, onLightElecSysChange);

void onLightSecChange(unsigned int newValue) {
     if( newValue == 1){ lightON(1,1); }
   else { lightOFF(1,1);}
}
DcsBios::IntegerBuffer lightSecBuffer(0x4470, 0x0001, 0, onLightSecChange);

void onLightEquipHotChange(unsigned int newValue) {
     if( newValue == 1){ lightON(1,2); }
   else { lightOFF(1,2);}
}
DcsBios::IntegerBuffer lightEquipHotBuffer(0x4470, 0x0002, 1, onLightEquipHotChange);

void onLightNwsFailChange(unsigned int newValue) {
     if( newValue == 1){ lightON(1,3); }
   else { lightOFF(1,3);}
}
DcsBios::IntegerBuffer lightNwsFailBuffer(0x4470, 0x0004, 2, onLightNwsFailChange);

void onLightProbeHeatChange(unsigned int newValue) {
     if( newValue == 1){ lightON(2,0); }
   else { lightOFF(2,0);}
}
DcsBios::IntegerBuffer lightProbeHeatBuffer(0x4470, 0x0008, 3, onLightProbeHeatChange);

void onLightFuelOilHotChange(unsigned int newValue) {
     if( newValue == 1){ lightON(2,1); }
   else { lightOFF(2,1);}
}
DcsBios::IntegerBuffer lightFuelOilHotBuffer(0x4470, 0x0010, 4, onLightFuelOilHotChange);

void onLightRadarAltChange(unsigned int newValue) {
   if( newValue == 1){ lightON(2,2); }
   else { lightOFF(2,2);}
}
DcsBios::IntegerBuffer lightRadarAltBuffer(0x4470, 0x0020, 5, onLightRadarAltChange);

void onLightAntiSkidChange(unsigned int newValue) {
     if( newValue == 1){ lightON(2,3); }
   else { lightOFF(2,3);}
}
DcsBios::IntegerBuffer lightAntiSkidBuffer(0x4470, 0x0040, 6, onLightAntiSkidChange);

void onLightCadcChange(unsigned int newValue) {
    if( newValue == 1){ lightON(3,0); }
   else { lightOFF(3,0);}
}
DcsBios::IntegerBuffer lightCadcBuffer(0x4470, 0x0080, 7, onLightCadcChange);

void onLightInletIcingChange(unsigned int newValue) {
   if( newValue == 1){ lightON(3,1); }
   else { lightOFF(3,1);}
}
DcsBios::IntegerBuffer lightInletIcingBuffer(0x4470, 0x0100, 8, onLightInletIcingChange);

void onLightIffChange(unsigned int newValue) {
    if( newValue == 1){ lightON(3,2); }
   else { lightOFF(3,2);}
}
DcsBios::IntegerBuffer lightIffBuffer(0x4470, 0x0200, 9, onLightIffChange);

void onLightHookChange(unsigned int newValue) {
     if( newValue == 1){ lightON(3,3); }
   else { lightOFF(3,3);}
}
DcsBios::IntegerBuffer lightHookBuffer(0x4470, 0x0400, 10, onLightHookChange);

void onLightStoresConfigChange(unsigned int newValue) {
   if( newValue == 1){ lightON(4,0); }
   else { lightOFF(4,0);}
}
DcsBios::IntegerBuffer lightStoresConfigBuffer(0x4470, 0x0800, 11, onLightStoresConfigChange);

void onLightOverheatChange(unsigned int newValue) {
   if( newValue == 1){ lightON(4,1); }
   else { lightOFF(4,1);}
}
DcsBios::IntegerBuffer lightOverheatBuffer(0x4470, 0x1000, 12, onLightOverheatChange);

void onLightNuclearChange(unsigned int newValue) {
     if( newValue == 1){ lightON(4,2); }
   else { lightOFF(4,2);}
}
DcsBios::IntegerBuffer lightNuclearBuffer(0x4470, 0x2000, 13, onLightNuclearChange);

void onLightOxyLowChange(unsigned int newValue) {
     if( newValue == 1){ lightON(4,3); }
   else { lightOFF(4,3);}
}
DcsBios::IntegerBuffer lightOxyLowBuffer(0x4474, 0x0020, 5, onLightOxyLowChange);

void onLightAtfNotChange(unsigned int newValue) {
   if( newValue == 1){ lightON(5,0); }
   else { lightOFF(5,0);}
}
DcsBios::IntegerBuffer lightAtfNotBuffer(0x4470, 0x8000, 15, onLightAtfNotChange);

void onLightEecChange(unsigned int newValue) {
    if( newValue == 1){ lightON(5,1); }
   else { lightOFF(5,1);}
}
DcsBios::IntegerBuffer lightEecBuffer(0x4472, 0x0001, 0, onLightEecChange);

void onLightCabinPressChange(unsigned int newValue) {
   if( newValue == 1){ lightON(5,3); }
   else { lightOFF(5,3);}
}
DcsBios::IntegerBuffer lightCabinPressBuffer(0x4472, 0x0004, 2, onLightCabinPressChange);

void onLightFwdFuelLowChange(unsigned int newValue) {
    if( newValue == 1){ lightON(6,0); }
   else { lightOFF(6,0);}
}
DcsBios::IntegerBuffer lightFwdFuelLowBuffer(0x4472, 0x0008, 3, onLightFwdFuelLowChange);

void onLightBucChange(unsigned int newValue) {
   if( newValue == 1){ lightON(6,1); }
   else { lightOFF(6,1);}
}
DcsBios::IntegerBuffer lightBucBuffer(0x4472, 0x0010, 4, onLightBucChange);

void onLightAftFuelLowChange(unsigned int newValue) {
     if( newValue == 1){ lightON(7,0); }
   else { lightOFF(7,0);}
}
DcsBios::IntegerBuffer lightAftFuelLowBuffer(0x4472, 0x0080, 7, onLightAftFuelLowChange);


//Commands to turn leds on and off
void lightON(int i,int j){
  cp_leds[cp_order[i][j][0]] = CRGB::Orange;
  cp_leds[cp_order[i][j][1]] = CRGB::Orange;
  FastLED.show();
}

void lightOFF(int i,int j){
  cp_leds[cp_order[i][j][0]] = CRGB::Black;
  cp_leds[cp_order[i][j][1]] = CRGB::Black;
  FastLED.show();
}

void startTest(){
  for(int i = 0; i <= 7;i++){
    for(int k = 0; k <= 3;k++){
     // String j = String(cp_order[i][k][0]) + " " +  String(cp_order[i][k][1]);
     // Serial.println(j);
     cp_leds[cp_order[i][k][0]] = CRGB::Green;
     cp_leds[cp_order[i][k][1]] = CRGB::Green;
      FastLED.show();
      delay(50);
    }
 }
 for(int i = 0; i <= 7;i++){
    for(int k = 0; k <= 3;k++){
     // String j = String(cp_order[i][k][0]) + " " +  String(cp_order[i][k][1]);
     // Serial.println(j);
     cp_leds[cp_order[i][k][0]] = CRGB::Black;
     cp_leds[cp_order[i][k][1]] = CRGB::Black;
      FastLED.show();
      delay(50);
    }
 }
 
}
