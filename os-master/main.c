// note this example will always write to the top
// line of the screen

//void main( int colour, const char *string )
void main()
{
    int i = 0;
    volatile char *video = (volatile char*)0xB8000;
    
    //while( *string != 0 )
    while (i < 1000)
    {
        //*video++ = *string++;
        //*video++ = colour;
        *video++ = 0x7169 + i + 148; // Hi
        i++;
    }
}

// wrzuć komendą sudo cp mytestos.bin /boot/
// fragment z grub.cfg
// to jest pod loaderami windowsa,linuxa itd, pod koniec pliku
/*
# my os test START
menuentry "My Test OS" {
  multiboot /boot/mytestos.bin
}
8/
