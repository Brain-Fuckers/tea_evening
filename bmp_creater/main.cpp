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
   //char    T1,T2;
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
     /*
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
   */
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
 } BITMAPINFOHEADER, *PBITMAPINFOHEADER;



     typedef struct tagBITMAPV5HEADER{
      DWORD         bV5Size;
      LONG          bV5Width;
      LONG          bV5Height;
      WORD          bV5Planes;
      WORD          bV5BitCount;
      DWORD         bV5Compression;
      DWORD         bV5SizeImage;
      LONG          bV5XPelsPerMeter;
      LONG          bV5YPelsPerMeter;
      DWORD         bV5ClrUsed;
      DWORD         bV5ClrImportant;

      DWORD         bV5RedMask;
      DWORD         bV5GreenMask;
      DWORD         bV5BlueMask;
      DWORD         bV5AlphaMask;
      DWORD         bV5CSType;
//      CIEXYZTRIPLE  bV5Endpoints;
      DWORD         bV5GammaRed;
      DWORD         bV5GammaGreen;
      DWORD         bV5GammaBlue;
      DWORD         bV5Intent;
      DWORD         bV5ProfileData;
      DWORD         bV5ProfileSize;
      DWORD         bV5Reserved;
    } BITMAPV5HEADER, *PBITMAPV5HEADER;



int main()
{

    cout << "sizeof WORD " << sizeof(WORD) << endl;
    cout << "sizeof DWORD " << sizeof(DWORD) << endl;
    cout << "sizeof LONG " << sizeof(LONG) << endl;

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    cout << "sizeof bfh " << sizeof(bfh) << endl;
    cout << "sizeof bih " << sizeof(bih) << endl;
    char Palette[1024];

    int px = 36;
    int py = 35;

    memset (Palette, 0, 1024);
    memset (&bfh, 0, sizeof(bfh));
    memset (&bih, 0, sizeof(bih));

    bfh.bfType = 0x4D42;
    //bfh.T1 = 'B';
    //bfh.T2 = 'M';
    bfh.bfOffBits = 14 + sizeof(bih);// + 1024;
    bfh.bfSize = bfh.bfOffBits + 3 * px * py;
        cout << "file size " << bfh.bfSize << endl;

    bih.biSize = sizeof(bih);
    bih.biWidth = px;
    bih.biHeight = py;
    bih.biPlanes = 1;
    bih.biBitCount = 24;
    bih.biCompression = 0;
    bih.biSizeImage =  14+40+(3*36*35);
    bih.biXPelsPerMeter = 0;
    bih.biYPelsPerMeter = 0;
    bih.biClrUsed = 0;
    bih.biClrImportant = 0;



    FILE *f = fopen( "test.bmp", "wb" );
	if( !f ) return -1;
	size_t res;

    res = fwrite(&bfh, 14, 1, f);
    cout << "res 1 " << res << endl;
    res = fwrite(&bih, sizeof(bih), 1, f);
    cout << "res 2 " << res << endl;

    //char *h = (char) bfh;
    //printf(h);
    unsigned char buf[px*3][py];


    for (int i = 0; i < py; i++)
    {
        for (int j = 0; j < px*3; j++)
        {
            buf[j][i] = 100;
        }
    }
    cout << "size of buf " << sizeof(buf) << " ,and must be 3780" << endl;
    res = fwrite(buf,sizeof(buf),1,f);

    fclose(f);

    cout << "Hello world!" << endl;
    return 0;
}
