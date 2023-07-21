#include "bg.h"

namespace Home {

void  background::drac(char * liste[240]){
    KDColor coul[8]={KDColor::RGB24(0x302c2b),
        KDColor::RGB24(0x585a57),
        KDColor::RGB24(0x878986),
        KDColor::RGB24(0xa7a9a6),
        KDColor::RGB24(0x000000),
        KDColor::RGB24(0x500307),
        KDColor::RGB24(0xffffff),
        KDColor::RGB24(0x7d0004)};
    for(int i=0;i<240;i++){
        for(int j=0;j<320;j++){
            char c=liste[i][j];
            int n = c - 48;
            Ion::Display::pushRectUniform(KDRect(j,i,1,1), coul[n]);
        }
    }
}

int background::b62(char x) {
    int A = 0;
    char t=x;
    if (x >= '0' && x <= '9') {
         A += (x - '0');
    } else if (x >= 'A' && x <= 'Z') {
        A += (x - 'A' + 10);
    } else {
         A += (x  - 'a' + 36);
    }
    return A;
}
int pow(int x,int y){
    int x2=x;
    for(int i=1;i<y;i++){
        x2=x2*x;
    }
    return x2;
}

int b16(char x) {
    int A = 0;
    if (x >= '0' && x <= '9') {
        A += (x - '0');
    } else if (x >= 'A' && x <= 'F') {
        A += (x - 'A' + 10);
    } else if (x >= 'a' && x <= 'f') {
        A += (x - 'a' + 10);
    }
    return A;
}

void background::load_img_lite(char* img, int x, int y, int s) {
    int nb_col=b62(img[0]);
    KDColor col[nb_col];
    int n=0;
    for(int i=0;i<nb_col;i++){
        n=6*i;
        col[i] = KDColor::RGB24(
    b16(img[n+1]) * pow(16, 5) +
    b16(img[n+2]) * pow(16, 4) +
    b16(img[n+3]) * pow(16, 3) +
    b16(img[n+4]) * pow(16, 2) +
    b16(img[n+5]) * 16 +
    b16(img[n+6])
);
    }
    int le = strlen(img);
    int x2 = 0;// n+1 +6*nb color
    n = 1+6*nb_col;
    int chn = 0;
    int L=320/s;
    while (n < le) {
        if (img[n] == '*') {
            chn = b62(img[n+1]) * 62 * 62 + b62(img[n+2]) * 62 + b62(img[n+3]);
            n += 4;
            if(col[b62(img[n])]!=KDColor::RGB24(0xfffff1)){
                Ion::Display::pushRectUniform(KDRect(x + (x2 % L) * s, y + (x2 / L) * s, chn * s, s), col[b62(img[n])]);
            }
            x2 += chn - 1;
        }
        else {
            if(col[b62(img[n])]!=KDColor::RGB24(0xfffff1)){
                Ion::Display::pushRectUniform(KDRect(x + (x2 % L) * s, y + (x2 / L) * s, s, s), col[b62(img[n])]);
            }
            n += 1;
            x2 += 1;
        }
    }
}

}