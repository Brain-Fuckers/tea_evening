#include <iostream>
//http://habrahabr.ru/post/102521/
//https://ru.wikipedia.org/wiki/JPEG
//http://www.kolpinkurs.ru/stati/jpeg.htmcd
//https://en.wikipedia.org/wiki/JPEG
using namespace std;

const char FF   = 0xFF; //Start Marker
const char OO   = 0x00; //Zero Byte
const char SOF0 = 0xC0; //Baseline discrete cosine transform(DCT)
const char SOF1 = 0xC1; //Extended sequential DCT
const char SOF2 = 0xC2; //Progressive DCT
const char DHT  = 0xC4; //Define Huffman table(s)
const char SOI  = 0xD8; //Start of image
const char EOI  = 0xD9; //End of image
const char SOS  = 0xDA; //Start of scan
const char DQT  = 0xDB; //Define quantization table(s)


int main()
{

    cout << "Hello world!" << endl;
    return 0;
}
