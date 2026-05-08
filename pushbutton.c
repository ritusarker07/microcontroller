// 7-Segment code for PIC + mikroC

char arr[] = {0x40,0x79,0x24,0x30,0x19,
              0x12,0x02,0x78,0x00,0x10};

unsigned short left, right;
int count = 0;

void main() {

    ADCON1 = 0x06;     // All digital I/O

    TRISB = 0x00;      // PORTB output (7-segment data)
    TRISC = 0x00;      // PORTC output (digit select)
    TRISD = 0xFF;      // PORTD input (buttons)

    PORTB = 0x00;
    PORTC = 0x00;
    PORTD = 0x00;

    while(1) {

        // Increment button
        if(PORTD.F0 == 1) {

            Delay_ms(30);   // Debounce

            if(PORTD.F0 == 1) {

                count++;

                if(count > 99)
                    count = 0;

                while(PORTD.F0 == 1);
            }
        }

        // Decrement button
        if(PORTD.F1 == 1) {

            Delay_ms(30);

            if(PORTD.F1 == 1) {

                if(count > 0)
                    count--;

                while(PORTD.F1 == 1);
            }
        }

        // Reset button
        if(PORTD.F2 == 1) {

            Delay_ms(30);

            if(PORTD.F2 == 1) {

                count = 0;

                while(PORTD.F2 == 1);
            }
        }

        // Separate digits
        left  = count / 10;
        right = count % 10;

        // Left digit display
        PORTC.F0 = 1;
        PORTC.F1 = 0;

        PORTB = arr[left];

        Delay_ms(5);

        // Right digit display
        PORTC.F0 = 0;
        PORTC.F1 = 1;

        PORTB = arr[right];

        Delay_ms(5);

        PORTC.F1 = 0;
    }
}