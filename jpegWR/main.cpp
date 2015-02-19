#include <iostream>
//http://habrahabr.ru/post/102521/
//https://ru.wikipedia.org/wiki/JPEG
//http://www.kolpinkurs.ru/stati/jpeg.htm
//https://en.wikipedia.org/wiki/JPEG
//http://www.codenet.ru/progr/alg/jpeg_00.php
using namespace std;

const char FF      = 0xFF; //Start Marker
const char OO      = 0x00; //Zero Byte
const char SOF0    = 0xC0; //Baseline discrete cosine transform(DCT)
const char SOF1    = 0xC1; //Extended sequential DCT
const char SOF2    = 0xC2; //Progressive DCT
const char DHT     = 0xC4; //Define Huffman table(s)
const char SOI     = 0xD8; //Start of image
const char EOI     = 0xD9; //End of image
const char SOS     = 0xDA; //Start of scan
const char DQT     = 0xDB; //Define quantization table(s)

const char RST[7]  = {0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6}; // Restart marker number 0…7
const char DNL     = 0xDC; //Define number of lines
const char DRI     = 0xDD; //Define restart interval
const char COM     = 0xFE; //Comment
const char APP[16] = {0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF}; //Reserved for application segments

const char SOF3    = 0xC3; //Lossless (sequential)
const char SOF5    = 0xC5; //Differential sequential DCT
const char SOF6    = 0xC6; //Differential progressive DCT
const char SOF7    = 0xC7; //Differential lossless (sequential)
const char SOF9    = 0xC9; //Extended sequential DCT
const char SOF10   = 0xCA; //Progressive DCT
const char SOF11   = 0xCB; //Lossless (sequential)
const char SOF13   = 0xCD; //Differential sequential DCT
const char SOF14   = 0xCE; //Differential progressive DCT
const char SOF15   = 0xCF; //Differential lossless (sequential)
const char DAC     = 0xCC; //Define arithmetic coding conditioning(s)
const char DHP     = 0xDE; //Define hierarchical progression
const char EXP     = 0xDF; //Expand reference component(s)
const char TEM     = 0x01; //For temporary private use in arithmetic coding


int main()
{

    cout << "Hello world!" << endl;
    return 0;
}
