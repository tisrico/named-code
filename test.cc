
#include "nc.h"
#include <iostream>
#include <assert.h>

#define XCODE 1
#define YCODE 2
#define ZCODE 3
#define MCODE 4
#define NCODE 16

enum enum_code {ec_x=1, ec_y=2, ec_z =3, ec_m=4, ec_n=5};

#define ListCode1(expresser) \
    expresser(XCODE) \
    expresser(YCODE) \
    expresser(ZCODE) \
    expresser(MCODE) \
    expresser(NCODE)


#define ListCode3(expresser) \
    expresser(ec_x) \
    expresser(ec_y) \
    expresser(ec_z) \
    expresser(ec_m) \
    expresser(ec_n)

#define ListCode2 ListCode1
#define ListCode4 ListCode3

DNICODE(Code1);
DBWNICODE(Code2);

DNCODE(Code3, enum_code);
DBWNCODE(Code4, enum_code);

int main(void) {

	assert(GetCode1Name(XCODE) == "XCODE");
	assert(GetCode1Name(YCODE) == "YCODE");
	assert(GetCode1Name(ZCODE) == "ZCODE");
	assert(GetCode1Name(MCODE) == "MCODE");
	assert(GetCode1Name(NCODE) == "NCODE");

	assert(GetCode1Id("XCODE") == XCODE);
	assert(GetCode1Id("YCODE") == YCODE);
	assert(GetCode1Id("ZCODE") == ZCODE);
	assert(GetCode1Id("MCODE") == MCODE);
	assert(GetCode1Id("NCODE") == NCODE);

	assert(GetCode2Name(XCODE) == "XCODE");
	assert(GetCode2Name(YCODE) == "YCODE");
	assert(GetCode2Name(ZCODE) == "XCODE|YCODE");
	assert(GetCode2Name(MCODE) == "MCODE");
	assert(GetCode2Name(NCODE) == "NCODE");

	assert(GetCode2Id("XCODE") == XCODE);
	assert(GetCode2Id("YCODE") == YCODE);
	assert(GetCode2Id("ZCODE") == ZCODE);
	assert(GetCode2Id("MCODE") == MCODE);
	assert(GetCode2Id("NCODE") == NCODE);

	assert(GetCode2Id("XCODE|YCODE") == (XCODE|YCODE));
	assert(GetCode2Id("YCODE|XCODE") == (XCODE|YCODE));
	assert(GetCode2Id("YCODE|XCODE|ZCODE") == (XCODE|YCODE|ZCODE));
	assert(GetCode2Id("YCODE|XCODE|ZCODE|MCODE") == (XCODE|YCODE|ZCODE|MCODE));
	assert(GetCode2Id("NCODE|XCODE|ZCODE|MCODE|YCODE") == (XCODE|YCODE|ZCODE|MCODE|NCODE));

	assert(GetCode3Name(ec_x) == "ec_x");
	assert(GetCode3Name(ec_y) == "ec_y");
	assert(GetCode3Name(ec_z) == "ec_z");
	assert(GetCode3Name(ec_m) == "ec_m");
	assert(GetCode3Name(ec_n) == "ec_n");

	assert(GetCode3Id("ec_x") == ec_x);
	assert(GetCode3Id("ec_y") == ec_y);
	assert(GetCode3Id("ec_z") == ec_z);
	assert(GetCode3Id("ec_m") == ec_m);
	assert(GetCode3Id("ec_n") == ec_n);

	assert(GetCode4Name(ec_x) == "ec_x");
	assert(GetCode4Name(ec_y) == "ec_y");
	assert(GetCode4Name(ec_z) == "ec_x|ec_y");
	assert(GetCode4Name(ec_m) == "ec_m");
	assert(GetCode4Name(ec_n) == "ec_x|ec_m");

	assert(GetCode4Id("ec_x") == ec_x);
	assert(GetCode4Id("ec_y") == ec_y);
	assert(GetCode4Id("ec_z") == ec_z);
	assert(GetCode4Id("ec_m") == ec_m);
	assert(GetCode4Id("ec_n") == ec_n);	

	assert(GetCode4Id("ec_x|ec_m") == ec_n);	
	assert(GetCode4Id("ec_x|ec_y") == ec_z);	

	std::cout << "all good." << std::endl;
	return 0;
}
