/*  GIMP header image file format (RGB): C:\Users\family\Desktop\LED Matrix\emojis\435.h  */

static unsigned int width = 16;
static unsigned int height = 16;

/*  Call this macro repeatedly.  After each use, the pixel data can be extracted  */

#define HEADER_PIXEL(data,pixel) {\
pixel[0] = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4)); \
pixel[1] = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2)); \
pixel[2] = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33))); \
data += 4; \
}
static char *header_data =
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!#AA'$1I)!Q)\"!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!IY*IR;C,6U9Y!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!&AY*X,O<\\.KYR;?+(251!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!(21/X,O>[^KYUL37,#%:!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!(B51X,W?\\.?VRK+#)B=0!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!8EI]ZM7G[]7EH(*5#A5#!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!(\"92RKC,\\^#R[M?G@VV%!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!1%\"H)*M\\N3T\\^+TZLW;LY2FK:.^R+O0NZK!=FF($1E'!!!!"
	"!1%!6E1WWLC:V\\'3N:2Y\\N/U\\^7V\\=GJV[\"ZXL+/\\>+R\\.+R\\=WMW+O)/CE>!!!!"
	"#1=&K)NR\\^KY].CX].7V\\^CX\\M[PYL32QY>>V[S(W[W(WKO&V[6`QINF/#5:!!!!"
	"$!I)QK'%\\^GY\\NGX\\^KY\\^;V\\=KKX;O&V*^X]>;X\\N7U\\^'Q[]?GWKO(5DEJ!!!!"
	"$1I)SK;)].GY\\^?W\\N#R\\^+S[M7EXKS(R)2:X+W)VK2_U*RVS:*LJ8*0)\"1.!!!!"
	"$!E(Q:N_].7W\\M[PZ\\W<\\MOL[='AX;O'QY.:ZL[=[]KJ[=;EZ,O:MY:E(\"),!!!!"
	"#!5%G8:<[M3D[=#?U:>OX;[+Z<C6X[S(SYRAP8V2V:^XTZBRR9NDA61W!A%!!!!!"
	"!1!!-#%8AFZ&D'.(<%-J5DAF@FA_H7J*JWR&GW-^E7R1D'N4@V^(/SA=!!!!!!!!"
	"!!!!!1!!\"1-#\"A1#\"!)\"!1!!\"1-##15$#Q9%#A9$\"A1#\"1-#\"!-\"!1!!!!!!!!!!"
	"";
