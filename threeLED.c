void main(){
 TRISB = 0x00;   //set as output
 portb = 0x00;   //initially 0
 while(1){
 //red light
 portb.f0 = portb.f3 = portb.f6 = 1;
 delay_ms(1000);
 portb.f0 = portb.f3 = portb.f6 = 0;
 delay_ms(1000);

 //green light
 /*portb.f3 = 1;
 delay_ms(1000);
 portb.f3 = 0;
 delay_ms(1000);

 //yellow light
 portb.f6 = 1;
 delay_ms(1000);
 portb.f6 = 0;
 delay_ms(1000); */
 }
 }