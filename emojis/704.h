/*  GIMP header image file format (RGB): C:\Users\family\Desktop\LED Matrix\emojis\704.h  */

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
	"!!!!!!!!!!!!#Q1!0#%#@5Y2NXMNVJ1_VJ1_NXMN@5Y20#%##Q1!!!!!!!!!!!!!"
	"!!!!!!!!,\"5!D&=1V*R'\\];$^.;>_>[J_>[J^.;>\\];$V*R'D&=1,\"5!!!!!!!!!"
	"!!!!,\"5!J'I7\\<BA`_#B`_SW``'^`_S\\`_S\\``'^`_SW`_#B\\<BAJ'I7,\"5!!!!!"
	"$!5!D6=-\\<61`^_3^>WCY=C-Z-O/`_?F`_?FZ-O/Y=C-^>WC`^_3\\<61D6=-$!5!"
	"0#)&V:1G`N*Q`_32ZM.TOZ.*Q:J0`N[+`N[+Q:J0OZ.*ZM.T`_32`N*QV:1G0#)&"
	"@V!/\\\\-]`^*C`^NRYL64M8UINI5N`.2I`.2INI5NM8UIYL64`^NR`^*C\\\\-]@V!/"
	"NXE:^<U\\`^\"0`^.5Z,-`NY-EP9IG`=R'`=R'P9IGNY-EZ,-``^25`^\"0^<U\\NXE:"
	"VZ!A_L]Y`]M_`]U_\\<MXT*YMU+)O`]Q^`]Q^U+)OT*UM\\<QX`]Y_`]M__L]YVZ!A"
	"VY]?_LYS`-5V_=-T_]=S`=YV`^!V`]]U`]]U`]]V`=UV_]9T_M-T`-5V_LYRVY]?"
	"O(I8^]9LPYA9K(ITP*:*T+1^V+QXW+]TW+]TV+MXT+-_O:&)KHIRR9Y:^]-LO(E8"
	"@V)0]<QGU*U8G(F\"F):[M[G7S,WKW-SXV]SWS,SIMKC5E)\"UGXI^W;59]<EF@V)0"
	"031'W*UA^M5FP*=QGH6&K)2=KY^ML:.TL:.UL)^KJI*:GH:$Q*MP_MAFW*Q@031'"
	"$!9!DFY2]\\YI[]!FR:19M(13KX!2JWY2JWY2KX!2LX12S*A:\\M)G]\\QHDFU2$!9!"
	"!!!!,2A$J8-7^--I]-AIV;=AUZQ>V*M>V*Q>UZM>V[AB]=AJ^-)HJ8-7,2A$!!!!"
	"!!!!!!!!,2A$DW!3WK9B]-9IY]!HX\\AGX\\AGZ=%I]-5IWK5BDW!3,2E$!!!!!!!!"
	"!!!!!!!!!!!!$!5!039(A6A2OY5:X;%@X;%@OY5:A6A2039($!9!!!!!!!!!!!!!"
	"";
