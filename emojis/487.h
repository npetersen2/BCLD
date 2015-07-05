/*  GIMP header image file format (RGB): C:\Users\family\Desktop\LED Matrix\emojis\487.h  */

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
	"!!!!!!!!!Q%!$Q5#(1I&'1E&+A]),\"!)'AE&\"1)\"!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!#!-\"2RE.@3U8BD-=C$5?D4EAD4EABD-=:#14'1E&!!!!!!!!!!!!!!!!!!!!"
	"!A%!0\"5+A$!;CTEBE4YFFU1KH5AOI%MPGE9MD4MC;C=6#1-#!!!!!!!!!!!!!!!!"
	"#!-\"<#53A$)<BD9@CDMDCTIBFU1LH5MQH%IPEE%IA$)=-2%)!!!!!!!!!!!!!!!!"
	"'QA$;3)0=CI6DEISZ,C<QJ&ZG6F#DU9PDE-LB4ED?D!;6\"Q/!!!!!!!!!!!!!!!!"
	"+1M%82E)C&-VX<34ZMOR__,(`_X5[=[VQ*:^E&)Z;C547\"M,!!!!!!!!!!!!!!!!"
	"*AI$6BE)GWR.T,_SL+#4\\N\\-].;\\WN((JJC+R;C2;#Q7421(!!!!!!!!!!!!!!!!"
	")!A#4R=(IX.2Y<WAY=SY]./X^.7WZ]_ZY-7OSZZZ:3Y:0QI\"!!!!!!!!!!!!!!!!"
	"'15\"1Q]$E7&\"[<C2^=SIU+_-M:.Q^-WM]]3?P9VH83M8L)\"FKI6KAF^&;U=Q'!Y*"
	"$A)\"/AI#:4=@U+*ZY,+/K9>QMIZXP*>[Z\\;.EG2$7#9<W[;?L(^T(\"),!!!!!!!!"
	"\"A%!-!A$0!]$BVM\\SJVV<%1W6#IEJX^BNYJA4C%12B-9PWK@?TND!!!!!!!!!!!!"
	"!A!!)Q5\",QE#-AM!9TYDL(^8L(^8DG6\"029(,19!22=@U8STG6\"^!!!!!!!!!!!!"
	"!1!!%A)#1BACB5*FJ52MUK;!Z,_9M6N>EUJW7#9Y2RMLX);^L&S0!!!!!!!!!!!!"
	"!1!!2S1ZX9'^]J84XX_UY*S4\\,?>UH+4[)`,W9/]FF&^ZI`+QGKC!!!!!!!!!!!!"
	"\"1)%D%VV_K$>`K8B`+,@\\YX#\\)CV^:P8^:X9Y:$'L';5\\:@1U(7Q!!!!!!!!!!!!"
	"\"A)%D5NV^J<9_:H<_:H<_*D:^Z<8^:@6\\:$/TX_VFF;![)`,V8;U!!!!!!!!!!!!"
	"";
