void main() {
              TRISB =0x00 ; // set portb as output
portb =0x00 ; //initialize portb as off
while (1)
{
portb.f0=1;
delay_ms(1000);
portb.f0=0;
delay_ms(1000);
}
}