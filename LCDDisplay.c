sbit LCD_RS at RB0_bit;
sbit LCD_EN at RB1_bit;
sbit LCD_D4 at RB4_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D7 at RB7_bit;
sbit LCD_RS_Direction at TRISB0_bit;
sbit LCD_EN_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB7_bit;
// End LCD module connections
char txt1[] = "mikroElektronika";
char txt2[] = "EasyPIC6";
char txt3[] = "Lcd4bit";
char txt4[] = "example";
char i; // Loop variable
void Move_Delay() {
Delay_ms(500);}
void main(){
TRISA = 0xFF; // Set PORTA as inputs
TRISB = 0x00; // Set PORTB as outputs
PORTB = 0x00; // Clear PORTB
// Important: Power-up delay for LCD
Delay_ms(200);
// Configure ADC and comparators
ADCON1 = 0x06; // Set all PORTB pins as digital I/O
// Initialize LCD
Lcd_Init(); // Initialize LCD
Delay_ms(50); // Extra delay after init
// Clear display and turn cursor off
Lcd_Cmd(_LCD_CLEAR); // Clear display
Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor off
// Display initial static text
Lcd_Out(1,1,txt1); // Write text in first row
Lcd_Out(2,1,txt2); // Write text in second row
Delay_ms(3000); // Show static text for 3 seconds
// Clear display for moving text demo
Lcd_Cmd(_LCD_CLEAR);
Lcd_Out(1,6,txt3); // Write text in first row
Lcd_Out(2,6,txt4); // Write text in second row
Delay_ms(2000);
Lcd_Cmd(_LCD_CLEAR);
Lcd_Out(1,1,txt1);
Lcd_Out(2,5,txt2);
Delay_ms(2000);
// Moving text to the right
for(i=0; i<4; i++) {
Lcd_Cmd(_LCD_SHIFT_RIGHT);
Move_Delay(); }
// Continuous moving text
while(1) { // Endless loop
for(i=0; i<12; i++) { // Move text to the left 12 times
Lcd_Cmd(_LCD_SHIFT_LEFT);
Move_Delay(); }
for(i=0; i<12; i++) { // Move text to the right 12 times
Lcd_Cmd(_LCD_SHIFT_RIGHT);
Move_Delay();}}}