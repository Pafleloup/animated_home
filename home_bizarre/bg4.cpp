
int b622(char x) {
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

void load_img_lite2(char* img, int x, int y, int s,KDRect rect ) {
    KDColor col[16]={
        KDColor::RGB24(0xffffff),
        KDColor::RGB24(0xa7dcf3),
        KDColor::RGB24(0x669fe5),
        KDColor::RGB24(0x3eb8f2),
        KDColor::RGB24(0x69dff7),
        KDColor::RGB24(0xd2fdfc),
        KDColor::RGB24(0x000000),
        KDColor::RGB24(0xa3fbfc),
        KDColor::RGB24(0xb8fffa),
        KDColor::RGB24(0x47f7f9),
        KDColor::RGB24(0x1f8ff3),
        KDColor::RGB24(0x1063cc),
        KDColor::RGB24(0x2c7af7),
        KDColor::RGB24(0x0f48ca),
        KDColor::RGB24(0x0b2dc2),
        KDColor::RGB24(0x0710b8),
    };
    int le = strlen(img);
    int x2 = 0;
    int n = 0;
    int chn = 0;
    int L=320;
    while (n < le) {
        if (img[n] == '*') {
            chn = b622(img[n+1]) * 62 * 62 + b622(img[n+2]) * 62 + b622(img[n+3]);
            n += 4;
            if ((x2% L<rect.right() || x2% L>rect.left()) && (x2 / L)<rect.bottom() &&(x2 / L)>rect.top() || true){
                Ion::Display::pushRectUniform(KDRect(x + (x2 % L) * s, y + (x2 / L) * s, chn * s, s), col[b622(img[n])]);
            }
            x2 += chn - 1;
        }
        else {
            if ((x2% L<rect.right() || x2% L>rect.left()) && (x2 / L)<rect.bottom() &&(x2 / L)>rect.top() || true){
                Ion::Display::pushRectUniform(KDRect(x + (x2 % L) * s, y + (x2 / L) * s, s, s), col[b622(img[n])]);
            }
            n += 1;
            x2 += 1;
        }
    }
}