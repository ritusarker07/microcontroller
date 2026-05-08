unsigned int adc_value;
char txt[7];

void main() {

    ADCON1 = 0x80;      // AN0 analog, rest digital
    TRISA = 0xFF;       // PORTA input
    TRISC = 0x80;       // RC7 RX, RC6 TX

    ADC_Init();         // ADC initialize
    UART1_Init(9600);   // UART initialize

    Delay_ms(100);

    while(1) {

        adc_value = ADC_Read(0);

        IntToStr(adc_value, txt);

        UART1_Write_Text("ADC Value = ");
        UART1_Write_Text(txt);
        UART1_Write(13);   // CR
        UART1_Write(10);   // LF

        Delay_ms(1000);
    }
}