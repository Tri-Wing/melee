#include <dolphin/types.h>
#include <MSL/math.h>

f32 cos__Ff(f32);
f32 sin__Ff(f32);
f32 cosf(f32);
f32 sinf(f32);

f32 tanf(f32 x)
{
    return sin__Ff(x) / cos__Ff(x);
}

f32 cos__Ff(f32 x)
{
    return cosf(x);
}

f32 sin__Ff(f32 x)
{
    return sinf(x);
}

const float tmp_float[] = {0.25F, 0.023239374F, 0.00000017055572F, 1.867365e-11F};

int lbl_80400770[] = {0x7FFFFFFF};
int lbl_80400774[] = {0x7F800000};

float __four_over_pi_m1[4] = {};

const float __two_over_pi = 0.63661975F;
const float lbl_804DE19C = 0.5F;
const float __SQRT_FLT_EPSILON__ = 3.4526698300e-4F;

const double lbl_804DE1A8 = 4503601774854144.0L;

extern const float __sincos_poly[];
extern const float __sincos_on_quadrant[];

#ifdef NON_MATCHING


float cosf(float x) {
    float z = __two_over_pi * x;

    //note we multiply n by 2 below because the polynomial we are using is for [o,pi/4]. n is the nearest multiple
    // of pi/2 not pi/4.
    //  frac_part is the remainder(mod(pi/4))
    // i.e. the actual arg that will be evaluated is frac_part*(pi/4)
    // note: since n is signed n<<1 may pad rightmost bit w/a one.
    int n = (__HI(x) & 0x80000000) ? (int)(z - .5f) : (int)(z + .5f);

    const float frac_part = ((((x - (float)(n * 2)) + __four_over_pi_m1[0] * x) + __four_over_pi_m1[1] * x) +
        __four_over_pi_m1[2] * x) + __four_over_pi_m1[3] * x
    /*) +
    													__four_over_pi_m1[4]*x  */
    ;

    float xsq;
    n &= 0x00000003;

    if (fabsf__Ff(frac_part) < __SQRT_FLT_EPSILON__) {
        n <<= 1; //index into __sincos_on_quadrant array
        return __sincos_on_quadrant[n + 1] - (__sincos_on_quadrant[n] * frac_part);
    }

    //use identity cos(x)=cos(n*pi/4 + frac_part)=cos(n*pi/4)cos(frac_part)- sin(n*pi/4)sin(frac_part)
    xsq = frac_part * frac_part;
    if (n & 0x00000001) // we are at a multiple of pi/2 thus cos(n*pi/4)= 0
    {
        n <<= 1; //index into __sincos_on_quadrant array 
        z = -((((__sincos_poly[1] * xsq + __sincos_poly[3]) * xsq + __sincos_poly[5]) * xsq + __sincos_poly[7]) * xsq + __sincos_poly[9]) * frac_part;
        return z * __sincos_on_quadrant[n];
    }

    n <<= 1; //index into __sincos_on_quadrant array
    // if here we are near a multiple of pi so sin(n*pi/4) =0

    z = (((__sincos_poly[0] * xsq + __sincos_poly[2]) * xsq + __sincos_poly[4]) * xsq + __sincos_poly[6]) * xsq + __sincos_poly[8];
    return z * __sincos_on_quadrant[n + 1]; // sin(frac_part)*cos(n*pi/4);  note: n*pi/4 is a multiple of pi/2(not pi)
}

#else

#pragma push
asm float cosf(float)
{ // clang-format off
    nofralloc
/* 80326240 00322E20  7C 08 02 A6 */	mflr r0
/* 80326244 00322E24  3C 60 80 40 */	lis r3, __four_over_pi_m1@ha
/* 80326248 00322E28  90 01 00 04 */	stw r0, 4(r1)
/* 8032624C 00322E2C  38 63 07 78 */	addi r3, r3, __four_over_pi_m1@l
/* 80326250 00322E30  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80326254 00322E34  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 80326258 00322E38  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8032625C 00322E3C  D0 21 00 08 */	stfs f1, 8(r1)
/* 80326260 00322E40  C0 02 E7 B8 */	lfs f0, __two_over_pi(r2)
/* 80326264 00322E44  80 01 00 08 */	lwz r0, 8(r1)
/* 80326268 00322E48  C0 C1 00 08 */	lfs f6, 8(r1)
/* 8032626C 00322E4C  54 00 00 01 */	rlwinm. r0, r0, 0, 0, 0
/* 80326270 00322E50  EC 20 01 B2 */	fmuls f1, f0, f6
/* 80326274 00322E54  41 82 00 1C */	beq lbl_80326290
/* 80326278 00322E58  C0 02 E7 BC */	lfs f0, lbl_804DE19C(r2)
/* 8032627C 00322E5C  EC 01 00 28 */	fsubs f0, f1, f0
/* 80326280 00322E60  FC 00 00 1E */	fctiwz f0, f0
/* 80326284 00322E64  D8 01 00 10 */	stfd f0, 0x10(r1)
/* 80326288 00322E68  80 81 00 14 */	lwz r4, 0x14(r1)
/* 8032628C 00322E6C  48 00 00 18 */	b lbl_803262A4
lbl_80326290:
/* 80326290 00322E70  C0 02 E7 BC */	lfs f0, lbl_804DE19C(r2)
/* 80326294 00322E74  EC 00 08 2A */	fadds f0, f0, f1
/* 80326298 00322E78  FC 00 00 1E */	fctiwz f0, f0
/* 8032629C 00322E7C  D8 01 00 10 */	stfd f0, 0x10(r1)
/* 803262A0 00322E80  80 81 00 14 */	lwz r4, 0x14(r1)
lbl_803262A4:
/* 803262A4 00322E84  54 80 08 3C */	slwi r0, r4, 1
/* 803262A8 00322E88  C8 22 E7 C8 */	lfd f1, lbl_804DE1A8(r2)
/* 803262AC 00322E8C  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 803262B0 00322E90  C0 43 00 00 */	lfs f2, 0(r3)
/* 803262B4 00322E94  90 01 00 14 */	stw r0, 0x14(r1)
/* 803262B8 00322E98  3C 00 43 30 */	lis r0, 0x4330
/* 803262BC 00322E9C  C0 63 00 04 */	lfs f3, 4(r3)
/* 803262C0 00322EA0  54 9F 07 BE */	clrlwi r31, r4, 0x1e
/* 803262C4 00322EA4  90 01 00 10 */	stw r0, 0x10(r1)
/* 803262C8 00322EA8  C0 83 00 08 */	lfs f4, 8(r3)
/* 803262CC 00322EAC  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 803262D0 00322EB0  C0 A3 00 0C */	lfs f5, 0xc(r3)
/* 803262D4 00322EB4  EC 00 08 28 */	fsubs f0, f0, f1
/* 803262D8 00322EB8  EC 06 00 28 */	fsubs f0, f6, f0
/* 803262DC 00322EBC  EC 02 01 BA */	fmadds f0, f2, f6, f0
/* 803262E0 00322EC0  EC 03 01 BA */	fmadds f0, f3, f6, f0
/* 803262E4 00322EC4  EC 04 01 BA */	fmadds f0, f4, f6, f0
/* 803262E8 00322EC8  EF E5 01 BA */	fmadds f31, f5, f6, f0
/* 803262EC 00322ECC  FC 20 F8 90 */	fmr f1, f31
/* 803262F0 00322ED0  4B FF FE C5 */	bl fabsf__Ff
/* 803262F4 00322ED4  C0 02 E7 C0 */	lfs f0, __SQRT_FLT_EPSILON__(r2)
/* 803262F8 00322ED8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 803262FC 00322EDC  40 80 00 24 */	bge lbl_80326320
/* 80326300 00322EE0  3C 60 80 3C */	lis r3, __sincos_on_quadrant@ha
/* 80326304 00322EE4  57 E4 18 38 */	slwi r4, r31, 3
/* 80326308 00322EE8  38 03 93 58 */	addi r0, r3, __sincos_on_quadrant@l
/* 8032630C 00322EEC  7C 60 22 14 */	add r3, r0, r4
/* 80326310 00322EF0  C0 23 00 00 */	lfs f1, 0(r3)
/* 80326314 00322EF4  C0 03 00 04 */	lfs f0, 4(r3)
/* 80326318 00322EF8  EC 3F 00 7C */	fnmsubs f1, f31, f1, f0
/* 8032631C 00322EFC  48 00 00 A0 */	b lbl_803263BC
lbl_80326320:
/* 80326320 00322F00  57 E0 07 FF */	clrlwi. r0, r31, 0x1f
/* 80326324 00322F04  EC 9F 07 F2 */	fmuls f4, f31, f31
/* 80326328 00322F08  41 82 00 50 */	beq lbl_80326378
/* 8032632C 00322F0C  3C 60 80 3C */	lis r3, __sincos_poly@ha
/* 80326330 00322F10  38 83 93 78 */	addi r4, r3, __sincos_poly@l
/* 80326334 00322F14  C0 44 00 04 */	lfs f2, 4(r4)
/* 80326338 00322F18  3C 60 80 3C */	lis r3, __sincos_on_quadrant@ha
/* 8032633C 00322F1C  C0 24 00 0C */	lfs f1, 0xc(r4)
/* 80326340 00322F20  38 03 93 58 */	addi r0, r3, __sincos_on_quadrant@l
/* 80326344 00322F24  C0 04 00 14 */	lfs f0, 0x14(r4)
/* 80326348 00322F28  EC 62 09 3A */	fmadds f3, f2, f4, f1
/* 8032634C 00322F2C  C0 44 00 1C */	lfs f2, 0x1c(r4)
/* 80326350 00322F30  C0 24 00 24 */	lfs f1, 0x24(r4)
/* 80326354 00322F34  57 E4 18 38 */	slwi r4, r31, 3
/* 80326358 00322F38  7C 60 22 14 */	add r3, r0, r4
/* 8032635C 00322F3C  EC 64 00 FA */	fmadds f3, f4, f3, f0
/* 80326360 00322F40  C0 03 00 00 */	lfs f0, 0(r3)
/* 80326364 00322F44  EC 44 10 FA */	fmadds f2, f4, f3, f2
/* 80326368 00322F48  EC 24 08 BE */	fnmadds f1, f4, f2, f1
/* 8032636C 00322F4C  EC 3F 00 72 */	fmuls f1, f31, f1
/* 80326370 00322F50  EC 21 00 32 */	fmuls f1, f1, f0
/* 80326374 00322F54  48 00 00 48 */	b lbl_803263BC
lbl_80326378:
/* 80326378 00322F58  3C 60 80 3C */	lis r3, __sincos_poly@ha
/* 8032637C 00322F5C  38 83 93 78 */	addi r4, r3, __sincos_poly@l
/* 80326380 00322F60  C0 44 00 00 */	lfs f2, 0(r4)
/* 80326384 00322F64  3C 60 80 3C */	lis r3, __sincos_on_quadrant@ha
/* 80326388 00322F68  C0 24 00 08 */	lfs f1, 8(r4)
/* 8032638C 00322F6C  38 63 93 58 */	addi r3, r3, __sincos_on_quadrant@l
/* 80326390 00322F70  57 E0 18 38 */	slwi r0, r31, 3
/* 80326394 00322F74  EC 62 09 3A */	fmadds f3, f2, f4, f1
/* 80326398 00322F78  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8032639C 00322F7C  C0 44 00 18 */	lfs f2, 0x18(r4)
/* 803263A0 00322F80  7C 63 02 14 */	add r3, r3, r0
/* 803263A4 00322F84  C0 24 00 20 */	lfs f1, 0x20(r4)
/* 803263A8 00322F88  EC 64 00 FA */	fmadds f3, f4, f3, f0
/* 803263AC 00322F8C  C0 03 00 04 */	lfs f0, 4(r3)
/* 803263B0 00322F90  EC 44 10 FA */	fmadds f2, f4, f3, f2
/* 803263B4 00322F94  EC 24 08 BA */	fmadds f1, f4, f2, f1
/* 803263B8 00322F98  EC 21 00 32 */	fmuls f1, f1, f0
lbl_803263BC:
/* 803263BC 00322F9C  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 803263C0 00322FA0  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 803263C4 00322FA4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 803263C8 00322FA8  7C 08 03 A6 */	mtlr r0
/* 803263CC 00322FAC  38 21 00 28 */	addi r1, r1, 0x28
/* 803263D0 00322FB0  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#endif

#ifdef NON_MATCHING

float sinf(float x) {
    float z = __two_over_pi * x;
    //note we multiply n by 2 below because the polynomial we are using is for [o,pi/4]. n is the nearest multiple
    // of pi/2 not pi/4.
    //  frac_part is the remainder(mod(pi/4))
    // i.e. the actual arg that will be evaluated is frac_part*(pi/4)
    // note: since n is signed n<<1 may pad rightmost bit w/a one.
    int n = (__HI(x) & 0x80000000) ? (int)(z - .5f) : (int)(z + .5f);

    const float frac_part = ((((x - (float)(n * 2)) + __four_over_pi_m1[0] * x) + __four_over_pi_m1[1] * x) +
        __four_over_pi_m1[2] * x) + __four_over_pi_m1[3] * x
    /*) +
      	                                               __four_over_pi_m1[4]*x  */
    ;

    float xsq;

    //assumes 2's complement integer storage for negative numbers.
    n &= 0x00000003;

    if (fabsf__Ff(frac_part) < __SQRT_FLT_EPSILON__) {
        n <<= 1; //index into __sincos_on_quadrant array
        return __sincos_on_quadrant[n] + (__sincos_on_quadrant[n + 1] * frac_part * __sincos_poly[9]);
    }

    xsq = frac_part * frac_part;
    if (n & 0x00000001) // we are at a multiple of pi/2 thus cos(n*pi/4)= 0
    {

        n <<= 1; //index into __sincos_on_quadrant array
        z = (((__sincos_poly[0] * xsq + __sincos_poly[2]) * xsq + __sincos_poly[4]) * xsq + __sincos_poly[6]) * xsq +
            __sincos_poly[8];

        return z * __sincos_on_quadrant[n]; // sin(frac_part)*cos(n*pi/4);  note: n*pi/4 is a multiple of pi/2(not pi)
        //return z;// sin(frac_part)*cos(n*pi/4);  note: n*pi/4 is a multiple of pi/2(not pi)
    }

    // if here we are near a multiple of pi so sin(n*pi/4) =0
    n <<= 1; //index into __sincos_on_quadrant array

    z = ((((__sincos_poly[1] * xsq + __sincos_poly[3]) * xsq + __sincos_poly[5]) * xsq + __sincos_poly[7]) * xsq + __sincos_poly[9]) * frac_part;
    //return z;// sin(frac_part)*cos(n*pi/4);  note: n*pi/4 is a multiple of pi/2(not pi)

    return z * __sincos_on_quadrant[n + 1]; // sin(frac_part)*cos(n*pi/4);  note: n*pi/4 is a multiple of pi/2(not pi)
}

#else

#pragma push
asm float sinf(float)
{ // clang-format off
    nofralloc
/* 803263D4 00322FB4  7C 08 02 A6 */	mflr r0
/* 803263D8 00322FB8  3C 60 80 40 */	lis r3, __four_over_pi_m1@ha
/* 803263DC 00322FBC  90 01 00 04 */	stw r0, 4(r1)
/* 803263E0 00322FC0  38 63 07 78 */	addi r3, r3, __four_over_pi_m1@l
/* 803263E4 00322FC4  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 803263E8 00322FC8  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 803263EC 00322FCC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 803263F0 00322FD0  D0 21 00 08 */	stfs f1, 8(r1)
/* 803263F4 00322FD4  C0 02 E7 B8 */	lfs f0, __two_over_pi(r2)
/* 803263F8 00322FD8  80 01 00 08 */	lwz r0, 8(r1)
/* 803263FC 00322FDC  C0 C1 00 08 */	lfs f6, 8(r1)
/* 80326400 00322FE0  54 00 00 01 */	rlwinm. r0, r0, 0, 0, 0
/* 80326404 00322FE4  EC 20 01 B2 */	fmuls f1, f0, f6
/* 80326408 00322FE8  41 82 00 1C */	beq lbl_80326424
/* 8032640C 00322FEC  C0 02 E7 BC */	lfs f0, lbl_804DE19C(r2)
/* 80326410 00322FF0  EC 01 00 28 */	fsubs f0, f1, f0
/* 80326414 00322FF4  FC 00 00 1E */	fctiwz f0, f0
/* 80326418 00322FF8  D8 01 00 10 */	stfd f0, 0x10(r1)
/* 8032641C 00322FFC  80 81 00 14 */	lwz r4, 0x14(r1)
/* 80326420 00323000  48 00 00 18 */	b lbl_80326438
lbl_80326424:
/* 80326424 00323004  C0 02 E7 BC */	lfs f0, lbl_804DE19C(r2)
/* 80326428 00323008  EC 00 08 2A */	fadds f0, f0, f1
/* 8032642C 0032300C  FC 00 00 1E */	fctiwz f0, f0
/* 80326430 00323010  D8 01 00 10 */	stfd f0, 0x10(r1)
/* 80326434 00323014  80 81 00 14 */	lwz r4, 0x14(r1)
lbl_80326438:
/* 80326438 00323018  54 80 08 3C */	slwi r0, r4, 1
/* 8032643C 0032301C  C8 22 E7 C8 */	lfd f1, lbl_804DE1A8(r2)
/* 80326440 00323020  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 80326444 00323024  C0 43 00 00 */	lfs f2, 0(r3)
/* 80326448 00323028  90 01 00 14 */	stw r0, 0x14(r1)
/* 8032644C 0032302C  3C 00 43 30 */	lis r0, 0x4330
/* 80326450 00323030  C0 63 00 04 */	lfs f3, 4(r3)
/* 80326454 00323034  54 9F 07 BE */	clrlwi r31, r4, 0x1e
/* 80326458 00323038  90 01 00 10 */	stw r0, 0x10(r1)
/* 8032645C 0032303C  C0 83 00 08 */	lfs f4, 8(r3)
/* 80326460 00323040  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 80326464 00323044  C0 A3 00 0C */	lfs f5, 0xc(r3)
/* 80326468 00323048  EC 00 08 28 */	fsubs f0, f0, f1
/* 8032646C 0032304C  EC 06 00 28 */	fsubs f0, f6, f0
/* 80326470 00323050  EC 02 01 BA */	fmadds f0, f2, f6, f0
/* 80326474 00323054  EC 03 01 BA */	fmadds f0, f3, f6, f0
/* 80326478 00323058  EC 04 01 BA */	fmadds f0, f4, f6, f0
/* 8032647C 0032305C  EF E5 01 BA */	fmadds f31, f5, f6, f0
/* 80326480 00323060  FC 20 F8 90 */	fmr f1, f31
/* 80326484 00323064  4B FF FD 31 */	bl fabsf__Ff
/* 80326488 00323068  C0 02 E7 C0 */	lfs f0, __SQRT_FLT_EPSILON__(r2)
/* 8032648C 0032306C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80326490 00323070  40 80 00 34 */	bge lbl_803264C4
/* 80326494 00323074  3C 60 80 3C */	lis r3, __sincos_on_quadrant@ha
/* 80326498 00323078  57 E4 18 38 */	slwi r4, r31, 3
/* 8032649C 0032307C  38 03 93 58 */	addi r0, r3, __sincos_on_quadrant@l
/* 803264A0 00323080  7C 60 22 14 */	add r3, r0, r4
/* 803264A4 00323084  C0 23 00 04 */	lfs f1, 4(r3)
/* 803264A8 00323088  3C 80 80 3C */	lis r4, __sincos_poly@ha
/* 803264AC 0032308C  38 84 93 78 */	addi r4, r4, __sincos_poly@l
/* 803264B0 00323090  C0 03 00 00 */	lfs f0, 0(r3)
/* 803264B4 00323094  EC 3F 00 72 */	fmuls f1, f31, f1
/* 803264B8 00323098  C0 44 00 24 */	lfs f2, 0x24(r4)
/* 803264BC 0032309C  EC 22 00 7A */	fmadds f1, f2, f1, f0
/* 803264C0 003230A0  48 00 00 A0 */	b lbl_80326560
lbl_803264C4:
/* 803264C4 003230A4  57 E0 07 FF */	clrlwi. r0, r31, 0x1f
/* 803264C8 003230A8  EC 9F 07 F2 */	fmuls f4, f31, f31
/* 803264CC 003230AC  41 82 00 4C */	beq lbl_80326518
/* 803264D0 003230B0  3C 60 80 3C */	lis r3, __sincos_poly@ha
/* 803264D4 003230B4  38 83 93 78 */	addi r4, r3, __sincos_poly@l
/* 803264D8 003230B8  C0 44 00 00 */	lfs f2, 0(r4)
/* 803264DC 003230BC  3C 60 80 3C */	lis r3, __sincos_on_quadrant@ha
/* 803264E0 003230C0  C0 24 00 08 */	lfs f1, 8(r4)
/* 803264E4 003230C4  38 03 93 58 */	addi r0, r3, __sincos_on_quadrant@l
/* 803264E8 003230C8  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 803264EC 003230CC  EC 62 09 3A */	fmadds f3, f2, f4, f1
/* 803264F0 003230D0  C0 44 00 18 */	lfs f2, 0x18(r4)
/* 803264F4 003230D4  C0 24 00 20 */	lfs f1, 0x20(r4)
/* 803264F8 003230D8  57 E4 18 38 */	slwi r4, r31, 3
/* 803264FC 003230DC  7C 60 22 14 */	add r3, r0, r4
/* 80326500 003230E0  EC 64 00 FA */	fmadds f3, f4, f3, f0
/* 80326504 003230E4  C0 03 00 00 */	lfs f0, 0(r3)
/* 80326508 003230E8  EC 44 10 FA */	fmadds f2, f4, f3, f2
/* 8032650C 003230EC  EC 24 08 BA */	fmadds f1, f4, f2, f1
/* 80326510 003230F0  EC 21 00 32 */	fmuls f1, f1, f0
/* 80326514 003230F4  48 00 00 4C */	b lbl_80326560
lbl_80326518:
/* 80326518 003230F8  3C 60 80 3C */	lis r3, __sincos_poly@ha
/* 8032651C 003230FC  38 83 93 78 */	addi r4, r3, __sincos_poly@l
/* 80326520 00323100  C0 44 00 04 */	lfs f2, 4(r4)
/* 80326524 00323104  3C 60 80 3C */	lis r3, __sincos_on_quadrant@ha
/* 80326528 00323108  C0 24 00 0C */	lfs f1, 0xc(r4)
/* 8032652C 0032310C  38 63 93 58 */	addi r3, r3, __sincos_on_quadrant@l
/* 80326530 00323110  57 E0 18 38 */	slwi r0, r31, 3
/* 80326534 00323114  EC 62 09 3A */	fmadds f3, f2, f4, f1
/* 80326538 00323118  C0 04 00 14 */	lfs f0, 0x14(r4)
/* 8032653C 0032311C  C0 44 00 1C */	lfs f2, 0x1c(r4)
/* 80326540 00323120  7C 63 02 14 */	add r3, r3, r0
/* 80326544 00323124  C0 24 00 24 */	lfs f1, 0x24(r4)
/* 80326548 00323128  EC 64 00 FA */	fmadds f3, f4, f3, f0
/* 8032654C 0032312C  C0 03 00 04 */	lfs f0, 4(r3)
/* 80326550 00323130  EC 44 10 FA */	fmadds f2, f4, f3, f2
/* 80326554 00323134  EC 24 08 BA */	fmadds f1, f4, f2, f1
/* 80326558 00323138  EC 3F 00 72 */	fmuls f1, f31, f1
/* 8032655C 0032313C  EC 21 00 32 */	fmuls f1, f1, f0
lbl_80326560:
/* 80326560 00323140  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80326564 00323144  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 80326568 00323148  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8032656C 0032314C  7C 08 03 A6 */	mtlr r0
/* 80326570 00323150  38 21 00 28 */	addi r1, r1, 0x28
/* 80326574 00323154  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#endif

#ifdef NON_MATCHING

void __sinit_trigf_c() {
    __four_over_pi_m1[0] = tmp_float[0];
    __four_over_pi_m1[1] = tmp_float[1];
    __four_over_pi_m1[2] = tmp_float[2];
    __four_over_pi_m1[3] = tmp_float[3];
}

#else

#pragma push
asm void __sinit_trigf_c()
{ // clang-format off
    nofralloc
/* 80326578 00323158  3C 60 80 3C */	lis r3, tmp_float@ha
/* 8032657C 0032315C  38 83 8F 40 */	addi r4, r3, tmp_float@l
/* 80326580 00323160  C0 04 00 00 */	lfs f0, 0(r4)
/* 80326584 00323164  3C 60 80 40 */	lis r3, __four_over_pi_m1@ha
/* 80326588 00323168  D4 03 07 78 */	stfsu f0, __four_over_pi_m1@l(r3)
/* 8032658C 0032316C  C0 04 00 04 */	lfs f0, 4(r4)
/* 80326590 00323170  D0 03 00 04 */	stfs f0, 4(r3)
/* 80326594 00323174  C0 04 00 08 */	lfs f0, 8(r4)
/* 80326598 00323178  D0 03 00 08 */	stfs f0, 8(r3)
/* 8032659C 0032317C  C0 04 00 0C */	lfs f0, 0xc(r4)
/* 803265A0 00323180  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 803265A4 00323184  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#endif
