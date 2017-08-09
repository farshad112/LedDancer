#include <LedDancer.h>

// PORT defines
//#define ENABLE_AUTO_LED_ANIMATION   // comment this line to turn offf automatic mode switching
#define MAX_NUM_OF_MODE             9
#define ANIMATION_SPEED_IN_MS       700

#define PORTB_OUTPUT                0x00
#define PORTC_INPUT                 0xFF

// LED ANIMATION Mode Defines
#define RESET_ALL_LED               0x0
#define BLINK_ALL_LED_AT_A_TIME     0x1
#define MOVE_TWO_LED_LEFT_TO_RIGHT  0x2
#define MOVE_ONE_LED_LEFT_TO_RIGHT  0x3
#define MOVE_TWO_LED_RIGHT_TO_LEFT  0x4
#define MOVE_ONE_LED_RIGHT_TO_LEFT  0x5
#define BLINK_ONLY_EVEN_LED         0x6
#define BLINK_ONLY_ODD_LED          0x7
#define TOGGLE_EVEN_AND_ODD_LED     0x8

// Function Prototypes
void port_b_led_animation(char mode); 
char get_port_c_input_val();

void main()
{
   // local variable
   #IFDEF ENABLE_AUTO_LED_ANIMATION
      char mode_num = 0;
   #ENDIF   
   
   SET_TRIS_B(PORTB_OUTPUT);  // Declare PORT B as output
   SET_TRIS_C(PORTC_INPUT);  // Declare PORT C as input
   
   while(TRUE)
   {
      #IFDEF ENABLE_AUTO_LED_ANIMATION
         for (mode_num=0; mode_num < MAX_NUM_OF_MODE; mode_num++) {
            port_b_led_animation(mode_num);
         }
      #ELSE
         port_b_led_animation(get_port_c_input_val());
      #ENDIF   
   }

}

void port_b_led_animation(char mode)
{
   // local variables
   char i;
   char led_val;
   
   if (mode == RESET_ALL_LED){
      output_b(0x00);
      delay_ms(ANIMATION_SPEED_IN_MS);
   }
   else if(mode == BLINK_ALL_LED_AT_A_TIME){
      output_b(0xFF);
      delay_ms(ANIMATION_SPEED_IN_MS);
   }
   else if(mode == MOVE_TWO_LED_LEFT_TO_RIGHT) {
      led_val = 0xC0;    // 8'b1100_0000
      for(i=0; i<8;i=i+2) {
         output_b(led_val);
         delay_ms(ANIMATION_SPEED_IN_MS);
         led_val /= 4;
      }
   }
   else if(mode == MOVE_ONE_LED_LEFT_TO_RIGHT) {
      led_val = 0x80;    // 8'b1000_0000
      for(i=0; i<8;i=i+1) {
         output_b(led_val);
         delay_ms(ANIMATION_SPEED_IN_MS);
         led_val /= 2;
      }
   }
   else if(mode == MOVE_TWO_LED_RIGHT_TO_LEFT){
      led_val = 0x03;    // 8'b0000_0011
      for(i=0; i<8;i=i+2) {
         output_b(led_val);
         delay_ms(ANIMATION_SPEED_IN_MS);
         led_val *= 4;
      }
   }
   else if(mode == MOVE_ONE_LED_RIGHT_TO_LEFT){
      led_val = 0x01;    // 8'b0000_0001
      for(i=0; i<8;i=i+1) {
         output_b(led_val);
         delay_ms(ANIMATION_SPEED_IN_MS);
         led_val *= 2;
      }
   }
   else if(mode == BLINK_ONLY_EVEN_LED) {
      led_val = 0xAA;      // 8'b1010_1010
      output_b(led_val);
      delay_ms(ANIMATION_SPEED_IN_MS);
   }
   else if(mode == BLINK_ONLY_ODD_LED) {
      led_val = 0x55;      // 8'b0101_0101
      output_b(led_val);
      delay_ms(ANIMATION_SPEED_IN_MS);
   }
   else if(mode == TOGGLE_EVEN_AND_ODD_LED) {
      led_val = 0xAA;      // 8'b1010_1010
      output_b(led_val);
      delay_ms(ANIMATION_SPEED_IN_MS);
      led_val = 0x55;      // 8'b0101_0101
      output_b(led_val);
      delay_ms(ANIMATION_SPEED_IN_MS);
   }
   else {
      for(i=0;i<8;i++) {
         output_b(0x00);
         delay_ms(ANIMATION_SPEED_IN_MS);
         output_b(0xFF);
         delay_ms(ANIMATION_SPEED_IN_MS);
      }   
      led_val = 0xC0;    // 8'b1100_0000
      for(i=0; i<8;i=i+2) {
         output_b(led_val);
         delay_ms(ANIMATION_SPEED_IN_MS);
         led_val /= 4;
      }
      led_val = 0x80;    // 8'b1000_0000
      for(i=0; i<8;i=i+1) {
         output_b(led_val);
         delay_ms(ANIMATION_SPEED_IN_MS);
         led_val /= 2;
      }
      led_val = 0x03;    // 8'b0000_0011
      for(i=0; i<8;i=i+2) {
         output_b(led_val);
         delay_ms(ANIMATION_SPEED_IN_MS);
         led_val *= 4;
      }
      led_val = 0x01;    // 8'b0000_0001
      for(i=0; i<8;i=i+1) {
         output_b(led_val);
         delay_ms(ANIMATION_SPEED_IN_MS);
         led_val *= 2;
      }
   }
}

char get_port_c_input_val(){
   return input_c();   
}
