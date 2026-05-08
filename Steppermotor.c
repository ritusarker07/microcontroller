void main(){
TRISD = 0b0000000;
PORTD = 0b1111111;
do{
PORTD = 0b00000011;
Delay_ms(500);
PORTD = 0b00000110;
Delay_ms(500);
PORTD = 0b00001100;
Delay_ms(500);
PORTD = 0b00001001;
Delay_ms(500);
}while(1);}