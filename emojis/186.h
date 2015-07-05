/*  GIMP header image file format (RGB): C:\Users\family\Desktop\LED Matrix\186.h  */

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
	"!!!!!!!!!!!!!!!!!!!\"\"!A*#B18%C5K%S1F#\")4\"!=%!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!QI//%^$=+#-@M+WC-SIEM_,7L#9/8^N)DYD#!M#!!!!!!!!!!!!"
	"!!!!!!!!%B9-C[\"AS/+;X`#BY`+>H?4!8N85GN[08M#G)Z#A0WIR!!53!!!!!!!!"
	"!!!!!AA-29+1Q._M\\0;W\\PCU\\`G;TO_5O_C#W0*4I^ZE2,#@!X'[!4NX!1-'!!!!"
	"!!!!(5\"09](CH?(F]PK\\\\PGN[`G-XP2SROVPI^VD-<SZ![08!(T'!&GI!2MV!!!!"
	"!Q=*/I/A;M`L@>XPT/_Y\\0C,WP*WNO>PM?*9)\\@%!+@E!*P7!(P#!&_K!$:I!!)&"
	"\"1U22[`78.$N6^<S6^4HK_72HO'&,L\\-+<7]$;H1!*P7!)T,!(+Y!&[E\"%J^!!9*"
	"#2=?/KH72=PM/]\\P+=@N,M,88=7<FN&;(KT$\"JH-\"9\\&!(C^!'CM!&C=$EVI!AI."
	"\"R1<+JT3,\\XH*-0M&\\PH#\\(C!+<@!*L;/[;35+W':[RD'H?5!6_?!&+1!T^J!!A."
	"!AE.(9<$(+4>&<,C#KX@![0:!*D4!)\\-\"Y?]FM%LH<Y4D\\15/HJ;$F.S!$6@!!1'"
	"!11'$F+\"$I4.#9`2!J(2!)P-!),&!(?\\#X+FB;U?C+U8@;)7<Z18*F:$!#%^!!)$"
	"!!!!\"\"YU\"W?T!H'_!(/^!(+Z!'WR!'7I!6_?+W^F=:A==*155H)<\"460!!U9!!!!"
	"!!!!!1%!!D.B!&OG!'/L!'/I!'#D!&O<!&;4''\"R99=>58%9!$28!\"QP!!!\"!!!!"
	"!!!!!!!!!1%\"!3V7!%O+!&'2!&'/!%[(!5J]*6J./FQF\"$&,!\"IN!!%\"!!!!!!!!"
	"!!!!!!!!!!!!!A%!\"\"1C\"3F(!D:?!4BA!4::%45X#3%K!QU7!A%\"!!!!!!!!!!!!"
	"!!!!!!!!!!!!!1!!!1!!!A)$!A1'!A5(!A5(!A1&!A)#!1!!!1!!!!!!!!!!!!!!"
	"";
