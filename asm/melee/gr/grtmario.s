.include "macros.inc"

.section .text  # 0x80005940 - 0x803B7240

.global func_8021F840
func_8021F840:
/* 8021F840 0021C420  4E 80 00 20 */	blr 
.global lbl_8021F844
lbl_8021F844:
/* 8021F844 0021C424  7C 08 02 A6 */	mflr r0
/* 8021F848 0021C428  3C 60 80 4A */	lis r3, stage_info@ha
/* 8021F84C 0021C42C  90 01 00 04 */	stw r0, 4(r1)
/* 8021F850 0021C430  38 63 E6 C8 */	addi r3, r3, stage_info@l
/* 8021F854 0021C434  38 A3 00 8C */	addi r5, r3, 0x8c
/* 8021F858 0021C438  94 21 FF F8 */	stwu r1, -8(r1)
/* 8021F85C 0021C43C  38 80 00 01 */	li r4, 1
/* 8021F860 0021C440  88 03 00 8C */	lbz r0, 0x8c(r3)
/* 8021F864 0021C444  38 60 00 00 */	li r3, 0
/* 8021F868 0021C448  50 60 1F 38 */	rlwimi r0, r3, 3, 0x1c, 0x1c
/* 8021F86C 0021C44C  98 05 00 00 */	stb r0, 0(r5)
/* 8021F870 0021C450  38 60 00 00 */	li r3, 0
/* 8021F874 0021C454  88 05 00 00 */	lbz r0, 0(r5)
/* 8021F878 0021C458  50 80 17 7A */	rlwimi r0, r4, 2, 0x1d, 0x1d
/* 8021F87C 0021C45C  98 05 00 00 */	stb r0, 0(r5)
/* 8021F880 0021C460  48 00 00 65 */	bl func_8021F8E4
/* 8021F884 0021C464  38 60 00 01 */	li r3, 1
/* 8021F888 0021C468  48 00 00 5D */	bl func_8021F8E4
/* 8021F88C 0021C46C  38 60 00 02 */	li r3, 2
/* 8021F890 0021C470  48 00 00 55 */	bl func_8021F8E4
/* 8021F894 0021C474  4B FA 41 2D */	bl func_801C39C0
/* 8021F898 0021C478  4B FA 43 1D */	bl func_801C3BB4
/* 8021F89C 0021C47C  4B FA 49 75 */	bl func_801C4210
/* 8021F8A0 0021C480  4B FA 4A 0D */	bl func_801C42AC
/* 8021F8A4 0021C484  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8021F8A8 0021C488  38 21 00 08 */	addi r1, r1, 8
/* 8021F8AC 0021C48C  7C 08 03 A6 */	mtlr r0
/* 8021F8B0 0021C490  4E 80 00 20 */	blr 
.global lbl_8021F8B4
lbl_8021F8B4:
/* 8021F8B4 0021C494  4E 80 00 20 */	blr 
.global lbl_8021F8B8
lbl_8021F8B8:
/* 8021F8B8 0021C498  7C 08 02 A6 */	mflr r0
/* 8021F8BC 0021C49C  38 60 00 00 */	li r3, 0
/* 8021F8C0 0021C4A0  90 01 00 04 */	stw r0, 4(r1)
/* 8021F8C4 0021C4A4  94 21 FF F8 */	stwu r1, -8(r1)
/* 8021F8C8 0021C4A8  4B FA B5 3D */	bl func_801CAE04
/* 8021F8CC 0021C4AC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8021F8D0 0021C4B0  38 21 00 08 */	addi r1, r1, 8
/* 8021F8D4 0021C4B4  7C 08 03 A6 */	mtlr r0
/* 8021F8D8 0021C4B8  4E 80 00 20 */	blr 
.global lbl_8021F8DC
lbl_8021F8DC:
/* 8021F8DC 0021C4BC  38 60 00 00 */	li r3, 0
/* 8021F8E0 0021C4C0  4E 80 00 20 */	blr 

.global func_8021F8E4
func_8021F8E4:
/* 8021F8E4 0021C4C4  7C 08 02 A6 */	mflr r0
/* 8021F8E8 0021C4C8  90 01 00 04 */	stw r0, 4(r1)
/* 8021F8EC 0021C4CC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8021F8F0 0021C4D0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8021F8F4 0021C4D4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8021F8F8 0021C4D8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8021F8FC 0021C4DC  93 81 00 10 */	stw r28, 0x10(r1)
/* 8021F900 0021C4E0  3B 83 00 00 */	addi r28, r3, 0
/* 8021F904 0021C4E4  1C 1C 00 14 */	mulli r0, r28, 0x14
/* 8021F908 0021C4E8  3C 60 80 3F */	lis r3, lbl_803E8548@ha
/* 8021F90C 0021C4EC  3B E3 85 48 */	addi r31, r3, lbl_803E8548@l
/* 8021F910 0021C4F0  38 7C 00 00 */	addi r3, r28, 0
/* 8021F914 0021C4F4  7F BF 02 14 */	add r29, r31, r0
/* 8021F918 0021C4F8  4B FA 1B B9 */	bl func_801C14D0
/* 8021F91C 0021C4FC  7C 7E 1B 79 */	or. r30, r3, r3
/* 8021F920 0021C500  41 82 00 70 */	beq lbl_8021F990
/* 8021F924 0021C504  83 FE 00 2C */	lwz r31, 0x2c(r30)
/* 8021F928 0021C508  38 00 00 00 */	li r0, 0
/* 8021F92C 0021C50C  3C 60 80 1C */	lis r3, func_801C5DB0@ha
/* 8021F930 0021C510  90 1F 00 08 */	stw r0, 8(r31)
/* 8021F934 0021C514  38 83 5D B0 */	addi r4, r3, func_801C5DB0@l
/* 8021F938 0021C518  38 7E 00 00 */	addi r3, r30, 0
/* 8021F93C 0021C51C  90 1F 00 0C */	stw r0, 0xc(r31)
/* 8021F940 0021C520  38 A0 00 03 */	li r5, 3
/* 8021F944 0021C524  38 C0 00 00 */	li r6, 0
/* 8021F948 0021C528  48 17 0D 55 */	bl GObj_SetupGXLink
/* 8021F94C 0021C52C  80 1D 00 0C */	lwz r0, 0xc(r29)
/* 8021F950 0021C530  28 00 00 00 */	cmplwi r0, 0
/* 8021F954 0021C534  41 82 00 08 */	beq lbl_8021F95C
/* 8021F958 0021C538  90 1F 00 1C */	stw r0, 0x1c(r31)
lbl_8021F95C:
/* 8021F95C 0021C53C  81 9D 00 00 */	lwz r12, 0(r29)
/* 8021F960 0021C540  28 0C 00 00 */	cmplwi r12, 0
/* 8021F964 0021C544  41 82 00 10 */	beq lbl_8021F974
/* 8021F968 0021C548  7D 88 03 A6 */	mtlr r12
/* 8021F96C 0021C54C  38 7E 00 00 */	addi r3, r30, 0
/* 8021F970 0021C550  4E 80 00 21 */	blrl 
lbl_8021F974:
/* 8021F974 0021C554  80 9D 00 08 */	lwz r4, 8(r29)
/* 8021F978 0021C558  28 04 00 00 */	cmplwi r4, 0
/* 8021F97C 0021C55C  41 82 00 2C */	beq lbl_8021F9A8
/* 8021F980 0021C560  38 7E 00 00 */	addi r3, r30, 0
/* 8021F984 0021C564  38 A0 00 04 */	li r5, 4
/* 8021F988 0021C568  48 17 03 CD */	bl func_8038FD54
/* 8021F98C 0021C56C  48 00 00 1C */	b lbl_8021F9A8
lbl_8021F990:
/* 8021F990 0021C570  38 DC 00 00 */	addi r6, r28, 0
/* 8021F994 0021C574  4C C6 31 82 */	crclr 6
/* 8021F998 0021C578  38 7F 00 90 */	addi r3, r31, 0x90
/* 8021F99C 0021C57C  38 9F 00 B4 */	addi r4, r31, 0xb4
/* 8021F9A0 0021C580  38 A0 00 CD */	li r5, 0xcd
/* 8021F9A4 0021C584  48 12 5D 05 */	bl OSReport
lbl_8021F9A8:
/* 8021F9A8 0021C588  7F C3 F3 78 */	mr r3, r30
/* 8021F9AC 0021C58C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8021F9B0 0021C590  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8021F9B4 0021C594  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8021F9B8 0021C598  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8021F9BC 0021C59C  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8021F9C0 0021C5A0  38 21 00 20 */	addi r1, r1, 0x20
/* 8021F9C4 0021C5A4  7C 08 03 A6 */	mtlr r0
/* 8021F9C8 0021C5A8  4E 80 00 20 */	blr 
.global lbl_8021F9CC
lbl_8021F9CC:
/* 8021F9CC 0021C5AC  7C 08 02 A6 */	mflr r0
/* 8021F9D0 0021C5B0  38 A0 00 00 */	li r5, 0
/* 8021F9D4 0021C5B4  90 01 00 04 */	stw r0, 4(r1)
/* 8021F9D8 0021C5B8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8021F9DC 0021C5BC  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 8021F9E0 0021C5C0  80 84 00 14 */	lwz r4, 0x14(r4)
/* 8021F9E4 0021C5C4  4B FA 87 55 */	bl func_801C8138
/* 8021F9E8 0021C5C8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8021F9EC 0021C5CC  38 21 00 08 */	addi r1, r1, 8
/* 8021F9F0 0021C5D0  7C 08 03 A6 */	mtlr r0
/* 8021F9F4 0021C5D4  4E 80 00 20 */	blr 
.global lbl_8021F9F8
lbl_8021F9F8:
/* 8021F9F8 0021C5D8  38 60 00 00 */	li r3, 0
/* 8021F9FC 0021C5DC  4E 80 00 20 */	blr 
.global lbl_8021FA00
lbl_8021FA00:
/* 8021FA00 0021C5E0  4E 80 00 20 */	blr 
.global lbl_8021FA04
lbl_8021FA04:
/* 8021FA04 0021C5E4  4E 80 00 20 */	blr 
lbl_8021FA08:
/* 8021FA08 0021C5E8  7C 08 02 A6 */	mflr r0
/* 8021FA0C 0021C5EC  3C 80 80 22 */	lis r4, lbl_8021FB50@ha
/* 8021FA10 0021C5F0  90 01 00 04 */	stw r0, 4(r1)
/* 8021FA14 0021C5F4  38 A4 FB 50 */	addi r5, r4, lbl_8021FB50@l
/* 8021FA18 0021C5F8  38 80 00 06 */	li r4, 6
/* 8021FA1C 0021C5FC  94 21 FF F8 */	stwu r1, -8(r1)
/* 8021FA20 0021C600  4B EA 0D D9 */	bl func_800C07F8
/* 8021FA24 0021C604  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8021FA28 0021C608  38 21 00 08 */	addi r1, r1, 8
/* 8021FA2C 0021C60C  7C 08 03 A6 */	mtlr r0
/* 8021FA30 0021C610  4E 80 00 20 */	blr 
.global lbl_8021FA34
lbl_8021FA34:
/* 8021FA34 0021C614  7C 08 02 A6 */	mflr r0
/* 8021FA38 0021C618  90 01 00 04 */	stw r0, 4(r1)
/* 8021FA3C 0021C61C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8021FA40 0021C620  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8021FA44 0021C624  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8021FA48 0021C628  7C 7E 1B 78 */	mr r30, r3
/* 8021FA4C 0021C62C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8021FA50 0021C630  80 63 00 28 */	lwz r3, 0x28(r3)
/* 8021FA54 0021C634  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 8021FA58 0021C638  4B FA 34 79 */	bl func_801C2ED0
/* 8021FA5C 0021C63C  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 8021FA60 0021C640  38 7E 00 00 */	addi r3, r30, 0
/* 8021FA64 0021C644  38 A0 00 00 */	li r5, 0
/* 8021FA68 0021C648  4B FA 86 D1 */	bl func_801C8138
/* 8021FA6C 0021C64C  3C 60 80 22 */	lis r3, lbl_8021FA08@ha
/* 8021FA70 0021C650  38 83 FA 08 */	addi r4, r3, lbl_8021FA08@l
/* 8021FA74 0021C654  38 7E 00 00 */	addi r3, r30, 0
/* 8021FA78 0021C658  4B FA 16 41 */	bl func_801C10B8
/* 8021FA7C 0021C65C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8021FA80 0021C660  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8021FA84 0021C664  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8021FA88 0021C668  38 21 00 20 */	addi r1, r1, 0x20
/* 8021FA8C 0021C66C  7C 08 03 A6 */	mtlr r0
/* 8021FA90 0021C670  4E 80 00 20 */	blr 
.global lbl_8021FA94
lbl_8021FA94:
/* 8021FA94 0021C674  38 60 00 00 */	li r3, 0
/* 8021FA98 0021C678  4E 80 00 20 */	blr 
.global lbl_8021FA9C
lbl_8021FA9C:
/* 8021FA9C 0021C67C  7C 08 02 A6 */	mflr r0
/* 8021FAA0 0021C680  90 01 00 04 */	stw r0, 4(r1)
/* 8021FAA4 0021C684  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8021FAA8 0021C688  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8021FAAC 0021C68C  7C 7F 1B 78 */	mr r31, r3
/* 8021FAB0 0021C690  4B DF 1B 45 */	bl func_800115F4
/* 8021FAB4 0021C694  7F E3 FB 78 */	mr r3, r31
/* 8021FAB8 0021C698  4B FA 35 29 */	bl func_801C2FE0
/* 8021FABC 0021C69C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8021FAC0 0021C6A0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8021FAC4 0021C6A4  38 21 00 18 */	addi r1, r1, 0x18
/* 8021FAC8 0021C6A8  7C 08 03 A6 */	mtlr r0
/* 8021FACC 0021C6AC  4E 80 00 20 */	blr 
.global lbl_8021FAD0
lbl_8021FAD0:
/* 8021FAD0 0021C6B0  4E 80 00 20 */	blr 
.global lbl_8021FAD4
lbl_8021FAD4:
/* 8021FAD4 0021C6B4  7C 08 02 A6 */	mflr r0
/* 8021FAD8 0021C6B8  90 01 00 04 */	stw r0, 4(r1)
/* 8021FADC 0021C6BC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8021FAE0 0021C6C0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8021FAE4 0021C6C4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8021FAE8 0021C6C8  7C 7E 1B 78 */	mr r30, r3
/* 8021FAEC 0021C6CC  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8021FAF0 0021C6D0  80 63 00 28 */	lwz r3, 0x28(r3)
/* 8021FAF4 0021C6D4  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 8021FAF8 0021C6D8  4B FA 33 D9 */	bl func_801C2ED0
/* 8021FAFC 0021C6DC  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 8021FB00 0021C6E0  38 7E 00 00 */	addi r3, r30, 0
/* 8021FB04 0021C6E4  38 A0 00 00 */	li r5, 0
/* 8021FB08 0021C6E8  4B FA 86 31 */	bl func_801C8138
/* 8021FB0C 0021C6EC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8021FB10 0021C6F0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8021FB14 0021C6F4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8021FB18 0021C6F8  38 21 00 20 */	addi r1, r1, 0x20
/* 8021FB1C 0021C6FC  7C 08 03 A6 */	mtlr r0
/* 8021FB20 0021C700  4E 80 00 20 */	blr 
.global lbl_8021FB24
lbl_8021FB24:
/* 8021FB24 0021C704  38 60 00 00 */	li r3, 0
/* 8021FB28 0021C708  4E 80 00 20 */	blr 
.global lbl_8021FB2C
lbl_8021FB2C:
/* 8021FB2C 0021C70C  7C 08 02 A6 */	mflr r0
/* 8021FB30 0021C710  90 01 00 04 */	stw r0, 4(r1)
/* 8021FB34 0021C714  94 21 FF F8 */	stwu r1, -8(r1)
/* 8021FB38 0021C718  4B FA 34 A9 */	bl func_801C2FE0
/* 8021FB3C 0021C71C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8021FB40 0021C720  38 21 00 08 */	addi r1, r1, 8
/* 8021FB44 0021C724  7C 08 03 A6 */	mtlr r0
/* 8021FB48 0021C728  4E 80 00 20 */	blr 
.global lbl_8021FB4C
lbl_8021FB4C:
/* 8021FB4C 0021C72C  4E 80 00 20 */	blr 
lbl_8021FB50:
/* 8021FB50 0021C730  7C 08 02 A6 */	mflr r0
/* 8021FB54 0021C734  90 01 00 04 */	stw r0, 4(r1)
/* 8021FB58 0021C738  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8021FB5C 0021C73C  DB E1 00 38 */	stfd f31, 0x38(r1)
/* 8021FB60 0021C740  93 E1 00 34 */	stw r31, 0x34(r1)
/* 8021FB64 0021C744  7C 9F 23 78 */	mr r31, r4
/* 8021FB68 0021C748  4B FA 09 31 */	bl func_801C0498
/* 8021FB6C 0021C74C  C0 02 C2 D0 */	lfs f0, lbl_804DBCB0@sda21(r2)
/* 8021FB70 0021C750  38 7F 00 00 */	addi r3, r31, 0
/* 8021FB74 0021C754  38 81 00 20 */	addi r4, r1, 0x20
/* 8021FB78 0021C758  EF E0 00 72 */	fmuls f31, f0, f1
/* 8021FB7C 0021C75C  4B E6 6A C9 */	bl func_80086644
/* 8021FB80 0021C760  38 7F 00 00 */	addi r3, r31, 0
/* 8021FB84 0021C764  38 81 00 14 */	addi r4, r1, 0x14
/* 8021FB88 0021C768  4B E6 6A FD */	bl func_80086684
/* 8021FB8C 0021C76C  C0 01 00 24 */	lfs f0, 0x24(r1)
/* 8021FB90 0021C770  FC 00 F8 40 */	fcmpo cr0, f0, f31
/* 8021FB94 0021C774  40 80 00 38 */	bge lbl_8021FBCC
/* 8021FB98 0021C778  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 8021FB9C 0021C77C  FC 00 F8 40 */	fcmpo cr0, f0, f31
/* 8021FBA0 0021C780  40 81 00 2C */	ble lbl_8021FBCC
/* 8021FBA4 0021C784  7F E3 FB 78 */	mr r3, r31
/* 8021FBA8 0021C788  4B E6 6F D9 */	bl func_80086B80
/* 8021FBAC 0021C78C  C0 02 C2 D4 */	lfs f0, lbl_804DBCB4@sda21(r2)
/* 8021FBB0 0021C790  38 61 00 20 */	addi r3, r1, 0x20
/* 8021FBB4 0021C794  EC 21 00 24 */	fdivs f1, f1, f0
/* 8021FBB8 0021C798  D3 E1 00 24 */	stfs f31, 0x24(r1)
/* 8021FBBC 0021C79C  48 00 00 2D */	bl func_8021FBE8
/* 8021FBC0 0021C7A0  3C 60 00 07 */	lis r3, 0x00077A10@ha
/* 8021FBC4 0021C7A4  38 63 7A 10 */	addi r3, r3, 0x00077A10@l
/* 8021FBC8 0021C7A8  4B FA 58 25 */	bl func_801C53EC
lbl_8021FBCC:
/* 8021FBCC 0021C7AC  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8021FBD0 0021C7B0  38 60 00 00 */	li r3, 0
/* 8021FBD4 0021C7B4  CB E1 00 38 */	lfd f31, 0x38(r1)
/* 8021FBD8 0021C7B8  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 8021FBDC 0021C7BC  38 21 00 40 */	addi r1, r1, 0x40
/* 8021FBE0 0021C7C0  7C 08 03 A6 */	mtlr r0
/* 8021FBE4 0021C7C4  4E 80 00 20 */	blr 

.global func_8021FBE8
func_8021FBE8:
/* 8021FBE8 0021C7C8  7C 08 02 A6 */	mflr r0
/* 8021FBEC 0021C7CC  38 A3 00 00 */	addi r5, r3, 0
/* 8021FBF0 0021C7D0  90 01 00 04 */	stw r0, 4(r1)
/* 8021FBF4 0021C7D4  38 60 75 30 */	li r3, 0x7530
/* 8021FBF8 0021C7D8  38 80 00 1E */	li r4, 0x1e
/* 8021FBFC 0021C7DC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8021FC00 0021C7E0  DB E1 00 10 */	stfd f31, 0x10(r1)
/* 8021FC04 0021C7E4  FF E0 08 90 */	fmr f31, f1
/* 8021FC08 0021C7E8  4B FA 9A F1 */	bl func_801C96F8
/* 8021FC0C 0021C7EC  28 03 00 00 */	cmplwi r3, 0
/* 8021FC10 0021C7F0  41 82 00 2C */	beq lbl_8021FC3C
/* 8021FC14 0021C7F4  80 63 00 54 */	lwz r3, 0x54(r3)
/* 8021FC18 0021C7F8  C0 03 00 24 */	lfs f0, 0x24(r3)
/* 8021FC1C 0021C7FC  EC 00 07 F2 */	fmuls f0, f0, f31
/* 8021FC20 0021C800  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8021FC24 0021C804  C0 03 00 28 */	lfs f0, 0x28(r3)
/* 8021FC28 0021C808  EC 00 07 F2 */	fmuls f0, f0, f31
/* 8021FC2C 0021C80C  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8021FC30 0021C810  C0 03 00 2C */	lfs f0, 0x2c(r3)
/* 8021FC34 0021C814  EC 00 07 F2 */	fmuls f0, f0, f31
/* 8021FC38 0021C818  D0 03 00 2C */	stfs f0, 0x2c(r3)
lbl_8021FC3C:
/* 8021FC3C 0021C81C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8021FC40 0021C820  CB E1 00 10 */	lfd f31, 0x10(r1)
/* 8021FC44 0021C824  38 21 00 18 */	addi r1, r1, 0x18
/* 8021FC48 0021C828  7C 08 03 A6 */	mtlr r0
/* 8021FC4C 0021C82C  4E 80 00 20 */	blr 
.global lbl_8021FC50
lbl_8021FC50:
/* 8021FC50 0021C830  38 60 00 00 */	li r3, 0
/* 8021FC54 0021C834  4E 80 00 20 */	blr 
.global lbl_8021FC58
lbl_8021FC58:
/* 8021FC58 0021C838  38 60 00 01 */	li r3, 1
/* 8021FC5C 0021C83C  4E 80 00 20 */	blr 


.section .data
    .balign 8
.global lbl_803E8548
lbl_803E8548:
	.4byte lbl_8021F9CC
	.4byte lbl_8021F9F8
	.4byte lbl_8021FA00
	.4byte lbl_8021FA04
    .4byte NULL
	.4byte lbl_8021FAD4
	.4byte lbl_8021FB24
	.4byte lbl_8021FB2C
	.4byte lbl_8021FB4C
    .4byte NULL
	.4byte lbl_8021FA34
	.4byte lbl_8021FA94
	.4byte lbl_8021FA9C
	.4byte lbl_8021FAD0
    .4byte 0xC0000000
    .4byte NULL
    .4byte NULL
    .4byte NULL
    .4byte NULL
    .4byte NULL
.global lbl_803E8598
lbl_803E8598:
    .4byte 0x2F477254
    .4byte 0x4D722E64
    .4byte 0x61740000
.global lbl_803E85A4
lbl_803E85A4:
    .4byte 0x00000028
    .4byte lbl_803E8548
    .4byte lbl_803E8598
	.4byte lbl_8021F844
	.4byte func_8021F840
	.4byte lbl_8021F8B4
	.4byte lbl_8021F8B8
	.4byte lbl_8021F8DC
	.4byte lbl_8021FC50
	.4byte lbl_8021FC58
    .4byte 0x00000001
    .4byte NULL
    .4byte NULL
    .4byte 0x25733A25
    .4byte 0x643A2063
    .4byte 0x6F756C64
    .4byte 0x6E207420
    .4byte 0x67657420
    .4byte 0x676F626A
    .4byte 0x2869643D
    .4byte 0x2564290A
    .4byte NULL
    .4byte 0x6772746D
    .4byte 0x6172696F
    .4byte 0x2E630000


.section .sdata2
    .balign 8
.global lbl_804DBCB0
lbl_804DBCB0:
	.4byte 0xC2F00000
.global lbl_804DBCB4
lbl_804DBCB4:
	.4byte 0x41200000
