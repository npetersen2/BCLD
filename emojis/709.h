/*  GIMP header image file format (RGB): C:\Users\family\Desktop\LED Matrix\emojis\709.h  */

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
	"'!-?%Q-8!1!\"!!!!!!!!!!!!!1!\"!A!#!A!#!1!\"!!!!!!!!!!!!!1!\"%Q-8'!-?"
	",Q=[9QV]/QB,*15P$1%2%Q)9-29Z13&+13&+-29Z%Q)9$1%2*15P/QB,9QV],Q=["
	"'Q1B8AVV>2'371JQ2RJ6@F3,F7CDI(+PI(+PF7CD@F3,2RJ671JQ>2'38AVV'Q1B"
	"#!%*2QJ841JA6\"JGHW[OK'[[L('`LH$\"LH$\"L('`K'[[HW[O6\"JG41JA2QJ8#!%*"
	"!1!\"(A5F11:4EV;GJ&[[KG'`L74\"LG8#LG8#L74\"KG'`J&[[EV;G11:4(A5F!1!\""
	"!!!!&Q1?8B2VGE?TJU_`KF4\"L&@\"L6H#L6H#L&@\"KF4\"JU_`GE?T8B2V&Q1?!!!!"
	"!A!#-AE_>2G1GD'V?S_/DTWDMF4*M&<%M&<%MF4*DTWD?S_/GD'V>2G1-AE_!A!#"
	"!Q%%2!^5BS7CJ$S_D$_?236-=%&ZPH4/PH4/=%&Z236-D$_?J$S_BS7C2!^5!Q%%"
	"!Q%%32*;E3_MLUP'P'0/>E;!'2-;Q9L.Q9L.'2-;>E;!P'0/LUP'E3_M32*;!Q%%"
	"!A%$0B&,ED7KNV@-QH,3:UNN4%\"/TK$:TK$:4%\"/:UNNQH,3NV@-ED7K0B&,!A%$"
	"!!!!*1MNB$+<O6T/QHH0IHCLS;(4X\\(JX\\(JSK(4HX?IR8L4O6T/B$+<*1MN!!!!"
	"!!!!#Q-.9#2RKV,#R(D38U^D9URIJY3PJ9+N85BC:V2LR8D4KV,#9#2R#Q-.!!!!"
	"!!!!!!!!)1UI@$;3O'8+T)T9@GO$,SMQ-3YSB8#+TIT<O'8+@$;3)1UI!!!!!!!!"
	"!!!!!!!!!!!!*!]K<T3!J6KXR8H7W:4HW*0HR(D6J6KW<T3!*!]K!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!$A91-RA\\8#^J>$W#>$W#8#^J-RA\\$A91!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!\"\"!)%\"A-(\"A-(\"!)%!!!\"!!!!!!!!!!!!!!!!!!!!"
	"";
