#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef unsigned short int WORD;
typedef unsigned int DWORD;
typedef int LONG;

#pragma pack(push)
#pragma pack(1)
typedef struct tagBITMAPFILEHEADER
 {
   WORD    bfType;
   DWORD   bfSize;
   DWORD    bfReserved1;
   //WORD    bfReserved2;
   DWORD   bfOffBits;

   //ushort   bfType;
   //uint     bfSize;
   //uint     bfReserved;
   //uint     bfOffBits;
 } BITMAPFILEHEADER, *PBITMAPFILEHEADER;
#pragma pack(pop)

  typedef struct tagBITMAPINFOHEADER
 {
   DWORD  biSize;
   LONG   biWidth;
   LONG   biHeight;
   WORD   biPlanes;
   WORD   biBitCount;
   DWORD  biCompression;
   DWORD  biSizeImage;
   LONG   biXPelsPerMeter;
   LONG   biYPelsPerMeter;
   DWORD  biClrUsed;
   DWORD  biClrImportant;
     /*
    uint  biSize;
    int   biWidth;
    int   biHeight;
    short biPlanes;
    short biBitCount;
    uint  biCompression;
    uint  biSizeImage;
    int   biXPelsPerMeter;
    int   biYPelsPerMeter;
    uint  biClrUsed;
    uint  biClrImportant;
   */
 } BITMAPINFOHEADER, *PBITMAPINFOHEADER;

int createBmpFile(const char *path, int px, int py, unsigned short BitPerPixel, unsigned char *buf)
{
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    memset(&bfh, 0, sizeof(bfh));
    memset(&bih, 0, sizeof(bih));

    int AddByte;
    int BytePerPixel = BitPerPixel/8;
    if      (BitPerPixel == 8 ) {AddByte = (3 * px) % 4;}
    else if (BitPerPixel == 16) {AddByte = (2 * px) % 4;}
    else if (BitPerPixel == 24) {AddByte =      px  % 4;}
    else return -1;

    bfh.bfType    = 0x4D42;
    bfh.bfOffBits = sizeof(bfh) + sizeof(bih);
    bfh.bfSize    = bfh.bfOffBits + //heder
                    (BytePerPixel * px * py) + //data
                    (AddByte * py);   // leveling bttes

    bih.biSize        = sizeof(bih);
    bih.biWidth       = px;
    bih.biHeight      = py;
    bih.biPlanes      = 1;
    bih.biBitCount    = BitPerPixel;
    bih.biCompression = 0; //BI_RGB

    FILE *f = fopen( path, "wb" );
	if( !f ) return -1;
	size_t res;

    res = fwrite(&bfh, sizeof(bfh), 1, f);
    if (res != 1) return -1;
    res = fwrite(&bih, sizeof(bih), 1, f);
    if (res != 1) return -1;

    for (int i = 0; i < py; i++)
    {
        fwrite(buf, px * BytePerPixel, 1, f);
        buf+=px * BytePerPixel;
        for (int j; j < AddByte; j)
            fputc(0,f);
    }
    fclose(f);

    return bfh.bfSize;
}

unsigned char *getRundBufRGB(int arrSize)
{
    unsigned char *buf = new unsigned char[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        buf[i] = (unsigned char)(rand()*(200./RAND_MAX));
    }
    return buf;
}

unsigned char *getRundBufBW24(int arrSize)
{
    unsigned char *buf = new unsigned char[arrSize];
    for (int i = 0; i < arrSize;)
    {
        unsigned char _cllor = (unsigned char)(rand()*(200./RAND_MAX));
        buf[i++] = _cllor;
        buf[i++] = _cllor;
        buf[i++] = _cllor;
    }
    return buf;
}

unsigned char *getMandelbrotBuf(int x, int y, int BytePerPixel)
{
    return 0;
}

int main()
{

    unsigned char *buf1;
    buf1 = new unsigned char[3*100 * 100];
    int iii = 0;
    for (int i = 0; i < 100*100*3; i++)
    {
        buf1[iii] = (unsigned char)(rand()*(200./RAND_MAX));
        iii++;
    }


    unsigned char *buf = getRundBufBW24(30000);

    cout << createBmpFile("fun1.bmp", 100, 100, 24, buf) << endl;

    delete []buf1;
    delete []buf;
    cout << "Hello world!" << endl;
    return 0;
}
