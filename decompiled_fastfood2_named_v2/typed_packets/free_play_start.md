# Function batch packet

## `Screen_FreePlaySetup` — `0x472da0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x472da0.c`
- Callers: `GameLoop_DispatchScreens` (0x4052c0)
- Callees: `Gadget_SetButtonColors` (0x52f750), `Gadget_SetButtonTextLayout` (0x52f7a0), `UI_AddImage` (0x52f5b0), `UI_AddSprite` (0x531850), `UI_AddText` (0x52f850), `UI_AddTextButton` (0x52f690), `UI_CreateBitmapGadget` (0x531c60), `UI_CreateSlider` (0x52fc00), `UI_FindWindowByID` (0x528040), `Window_CreatePictureWindow` (0x523c90), `Window_GadgetNotify_Slider_SetGradientColors` (0x52fcc0), `Window_GadgetNotify_Text_SetLayout` (0x52f9d0), `Window_GadgetNotify_Text_SetTextColor` (0x52f910)

- Signature: `{'call_site': '0x405478', 'confidence': 'derived from call site and prologue', 'recovered': 'void *__cdecl Screen_FreePlaySetup(int *state_out)', 'return': 'screen pointer in EAX'}`
- Dispatch: `callback_registration` None -> ['0x4cc640']
- Unresolved questions: The callback at 0x4cc640 has no named procedure in the Ghidra export; its body is recovered from bounded disassembly.

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

00472da0 <.text+0x71da0>:
  472da0:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  472da6:	83 ec 10             	sub    esp,0x10
  472da9:	56                   	push   esi
  472daa:	68 40 c6 4c 00       	push   0x4cc640
  472daf:	68 08 74 56 00       	push   0x567408
  472db4:	e8 d7 0e 0b 00       	call   0x523c90
  472db9:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  472dbd:	6a 00                	push   0x0
  472dbf:	50                   	push   eax
  472dc0:	89 01                	mov    DWORD PTR [ecx],eax
  472dc2:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  472dc8:	e8 73 52 0b 00       	call   0x528040
  472dcd:	8b f0                	mov    esi,eax
  472dcf:	85 f6                	test   esi,esi
  472dd1:	75 05                	jne    0x472dd8
  472dd3:	5e                   	pop    esi
  472dd4:	83 c4 10             	add    esp,0x10
  472dd7:	c3                   	ret
  472dd8:	6a 00                	push   0x0
  472dda:	6a 00                	push   0x0
  472ddc:	68 10 46 56 00       	push   0x564610
  472de1:	68 ca 01 00 00       	push   0x1ca
  472de6:	6a 7a                	push   0x7a
  472de8:	68 fa 03 00 00       	push   0x3fa
  472ded:	8b ce                	mov    ecx,esi
  472def:	e8 bc c7 0b 00       	call   0x52f5b0
  472df4:	6a 00                	push   0x0
  472df6:	6a 00                	push   0x0
  472df8:	68 fc 45 56 00       	push   0x5645fc
  472dfd:	68 ca 01 00 00       	push   0x1ca
  472e02:	68 9f 00 00 00       	push   0x9f
  472e07:	68 fb 03 00 00       	push   0x3fb
  472e0c:	8b ce                	mov    ecx,esi
  472e0e:	e8 9d c7 0b 00       	call   0x52f5b0
  472e13:	8b 15 20 1e 58 00    	mov    edx,DWORD PTR ds:0x581e20
  472e19:	8b ce                	mov    ecx,esi
  472e1b:	52                   	push   edx
  472e1c:	68 a8 3e 56 00       	push   0x563ea8
  472e21:	68 a9 01 00 00       	push   0x1a9
  472e26:	68 61 02 00 00       	push   0x261
  472e2b:	68 06 04 00 00       	push   0x406
  472e30:	e8 1b ca 0b 00       	call   0x52f850
  472e35:	85 c0                	test   eax,eax
  472e37:	74 25                	je     0x472e5e
  472e39:	6a 00                	push   0x0
  472e3b:	68 06 04 00 00       	push   0x406
  472e40:	8b ce                	mov    ecx,esi
  472e42:	e8 c9 ca 0b 00       	call   0x52f910
  472e47:	6a 00                	push   0x0
  472e49:	6a 00                	push   0x0
  472e4b:	68 b4 00 00 00       	push   0xb4
  472e50:	6a 02                	push   0x2
  472e52:	68 06 04 00 00       	push   0x406
  472e57:	8b ce                	mov    ecx,esi
  472e59:	e8 72 cb 0b 00       	call   0x52f9d0
  472e5e:	6a 00                	push   0x0
  472e60:	6a 00                	push   0x0
  472e62:	68 d0 42 56 00       	push   0x5642d0
  472e67:	68 af 00 00 00       	push   0xaf
  472e6c:	68 cd 01 00 00       	push   0x1cd
  472e71:	68 69 02 00 00       	push   0x269
  472e76:	68 07 04 00 00       	push   0x407
  472e7b:	8b ce                	mov    ecx,esi
  472e7d:	e8 7e cd 0b 00       	call   0x52fc00
  472e82:	85 c0                	test   eax,eax
  472e84:	74 31                	je     0x472eb7
  472e86:	8d 44 24 04          	lea    eax,[esp+0x4]
  472e8a:	8b ce                	mov    ecx,esi
  472e8c:	50                   	push   eax
  472e8d:	68 07 04 00 00       	push   0x407
  472e92:	c7 44 24 0c 00 aa 00 	mov    DWORD PTR [esp+0xc],0xaa00
  472e99:	00 
  472e9a:	c7 44 24 10 ff ff 00 	mov    DWORD PTR [esp+0x10],0xffff
  472ea1:	00 
  472ea2:	c7 44 24 14 ff 00 00 	mov    DWORD PTR [esp+0x14],0xff
  472ea9:	00 
  472eaa:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  472eb1:	00 
  472eb2:	e8 09 ce 0b 00       	call   0x52fcc0
  472eb7:	8b 0d b8 2b 58 00    	mov    ecx,DWORD PTR ds:0x582bb8
  472ebd:	51                   	push   ecx
  472ebe:	68 64 3e 56 00       	push   0x563e64
  472ec3:	68 de 01 00 00       	push   0x1de
  472ec8:	68 61 02 00 00       	push   0x261
  472ecd:	68 08 04 00 00       	push   0x408
  472ed2:	8b ce                	mov    ecx,esi
  472ed4:	e8 77 c9 0b 00       	call   0x52f850
  472ed9:	85 c0                	test   eax,eax
  472edb:	74 25                	je     0x472f02
  472edd:	6a 00                	push   0x0
  472edf:	68 08 04 00 00       	push   0x408
  472ee4:	8b ce                	mov    ecx,esi
  472ee6:	e8 25 ca 0b 00       	call   0x52f910
  472eeb:	6a 00                	push   0x0
  472eed:	6a 00                	push   0x0
  472eef:	68 b4 00 00 00       	push   0xb4
  472ef4:	6a 02                	push   0x2
  472ef6:	68 08 04 00 00       	push   0x408
  472efb:	8b ce                	mov    ecx,esi
  472efd:	e8 ce ca 0b 00       	call   0x52f9d0
  472f02:	8b 15 b8 15 58 00    	mov    edx,DWORD PTR ds:0x5815b8
  472f08:	8b ce                	mov    ecx,esi
  472f0a:	52                   	push   edx
  472f0b:	68 a8 3e 56 00       	push   0x563ea8
  472f10:	6a 05                	push   0x5
  472f12:	6a 0d                	push   0xd
  472f14:	68 20 04 00 00       	push   0x420
  472f19:	e8 32 c9 0b 00       	call   0x52f850
  472f1e:	85 c0                	test   eax,eax
  472f20:	74 25                	je     0x472f47
  472f22:	6a 00                	push   0x0
  472f24:	68 20 04 00 00       	push   0x420
  472f29:	8b ce                	mov    ecx,esi
  472f2b:	e8 e0 c9 0b 00       	call   0x52f910
  472f30:	6a 00                	push   0x0
  472f32:	6a 00                	push   0x0
  472f34:	68 30 02 00 00       	push   0x230
  472f39:	6a 02                	push   0x2
  472f3b:	68 20 04 00 00       	push   0x420
  472f40:	8b ce                	mov    ecx,esi
  472f42:	e8 89 ca 0b 00       	call   0x52f9d0
  472f47:	a1 50 2e 58 00       	mov    eax,ds:0x582e50
  472f4c:	8b ce                	mov    ecx,esi
  472f4e:	50                   	push   eax
  472f4f:	68 a8 3e 56 00       	push   0x563ea8
  472f54:	6a 05                	push   0x5
  472f56:	68 60 02 00 00       	push   0x260
  472f5b:	68 22 04 00 00       	push   0x422
  472f60:	e8 eb c8 0b 00       	call   0x52f850
  472f65:	85 c0                	test   eax,eax
  472f67:	74 25                	je     0x472f8e
  472f69:	6a 00                	push   0x0
  472f6b:	68 22 04 00 00       	push   0x422
  472f70:	8b ce                	mov    ecx,esi
  472f72:	e8 99 c9 0b 00       	call   0x52f910
  472f77:	6a 00                	push   0x0
  472f79:	6a 00                	push   0x0
  472f7b:	68 b4 00 00 00       	push   0xb4
  472f80:	6a 02                	push   0x2
  472f82:	68 22 04 00 00       	push   0x422
  472f87:	8b ce                	mov    ecx,esi
  472f89:	e8 42 ca 0b 00       	call   0x52f9d0
  472f8e:	68 b8 72 56 00       	push   0x5672b8
  472f93:	68 98 3e 56 00       	push   0x563e98
  472f98:	68 fe 01 00 00       	push   0x1fe
  472f9d:	68 e0 00 00 00       	push   0xe0
  472fa2:	68 29 04 00 00       	push   0x429
  472fa7:	8b ce                	mov    ecx,esi
  472fa9:	e8 a2 c8 0b 00       	call   0x52f850
  472fae:	85 c0                	test   eax,eax
  472fb0:	74 25                	je     0x472fd7
  472fb2:	6a 00                	push   0x0
  472fb4:	68 29 04 00 00       	push   0x429
  472fb9:	8b ce                	mov    ecx,esi
  472fbb:	e8 50 c9 0b 00       	call   0x52f910
  472fc0:	6a 00                	push   0x0
  472fc2:	6a 50                	push   0x50
  472fc4:	68 59 01 00 00       	push   0x159
  472fc9:	6a 00                	push   0x0
  472fcb:	68 29 04 00 00       	push   0x429
  472fd0:	8b ce                	mov    ecx,esi
  472fd2:	e8 f9 c9 0b 00       	call   0x52f9d0
  472fd7:	6a 00                	push   0x0
  472fd9:	6a 00                	push   0x0
  472fdb:	68 fc 45 56 00       	push   0x5645fc
  472fe0:	68 dd 01 00 00       	push   0x1dd
  472fe5:	68 9f 00 00 00       	push   0x9f
  472fea:	68 31 04 00 00       	push   0x431
  472fef:	8b ce                	mov    ecx,esi
  472ff1:	e8 ba c5 0b 00       	call   0x52f5b0
  472ff6:	6a 00                	push   0x0
  472ff8:	6a 00                	push   0x0
  472ffa:	68 10 46 56 00       	push   0x564610
  472fff:	68 dd 01 00 00       	push   0x1dd
  473004:	6a 7a                	push   0x7a
  473006:	68 32 04 00 00       	push   0x432
  47300b:	8b ce                	mov    ecx,esi
  47300d:	e8 9e c5 0b 00       	call   0x52f5b0
  473012:	8b 0d 20 1a 58 00    	mov    ecx,DWORD PTR ds:0x581a20
  473018:	51                   	push   ecx
  473019:	68 a8 3e 56 00       	push   0x563ea8
  47301e:	68 a9 01 00 00       	push   0x1a9
  473023:	68 81 01 00 00       	push   0x181
  473028:	68 33 04 00 00       	push   0x433
  47302d:	8b ce                	mov    ecx,esi
  47302f:	e8 1c c8 0b 00       	call   0x52f850
  473034:	85 c0                	test   eax,eax
  473036:	74 25                	je     0x47305d
  473038:	6a 00                	push   0x0
  47303a:	68 33 04 00 00       	push   0x433
  47303f:	8b ce                	mov    ecx,esi
  473041:	e8 ca c8 0b 00       	call   0x52f910
  473046:	6a 00                	push   0x0
  473048:	6a 00                	push   0x0
  47304a:	68 b4 00 00 00       	push   0xb4
  47304f:	6a 02                	push   0x2
  473051:	68 33 04 00 00       	push   0x433
  473056:	8b ce                	mov    ecx,esi
  473058:	e8 73 c9 0b 00       	call   0x52f9d0
  47305d:	6a 00                	push   0x0
  47305f:	6a 00                	push   0x0
  473061:	68 d0 42 56 00       	push   0x5642d0
  473066:	68 af 00 00 00       	push   0xaf
  47306b:	68 cd 01 00 00       	push   0x1cd
  473070:	68 89 01 00 00       	push   0x189
  473075:	68 34 04 00 00       	push   0x434
  47307a:	8b ce                	mov    ecx,esi
  47307c:	e8 7f cb 0b 00       	call   0x52fc00
  473081:	85 c0                	test   eax,eax
  473083:	74 31                	je     0x4730b6
  473085:	8d 54 24 04          	lea    edx,[esp+0x4]
  473089:	8b ce                	mov    ecx,esi
  47308b:	52                   	push   edx
  47308c:	68 34 04 00 00       	push   0x434
  473091:	c7 44 24 0c ff 00 00 	mov    DWORD PTR [esp+0xc],0xff
  473098:	00 
  473099:	c7 44 24 10 ff ff 00 	mov    DWORD PTR [esp+0x10],0xffff
  4730a0:	00 
  4730a1:	c7 44 24 14 00 aa 00 	mov    DWORD PTR [esp+0x14],0xaa00
  4730a8:	00 
  4730a9:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  4730b0:	00 
  4730b1:	e8 0a cc 0b 00       	call   0x52fcc0
  4730b6:	a1 e8 26 58 00       	mov    eax,ds:0x5826e8
  4730bb:	8b ce                	mov    ecx,esi
  4730bd:	50                   	push   eax
  4730be:	68 64 3e 56 00       	push   0x563e64
  4730c3:	68 de 01 00 00       	push   0x1de
  4730c8:	68 81 01 00 00       	push   0x181
  4730cd:	68 35 04 00 00       	push   0x435
  4730d2:	e8 79 c7 0b 00       	call   0x52f850
  4730d7:	85 c0                	test   eax,eax
  4730d9:	74 25                	je     0x473100
  4730db:	6a 00                	push   0x0
  4730dd:	68 35 04 00 00       	push   0x435
  4730e2:	8b ce                	mov    ecx,esi
  4730e4:	e8 27 c8 0b 00       	call   0x52f910
  4730e9:	6a 00                	push   0x0
  4730eb:	6a 00                	push   0x0
  4730ed:	68 b4 00 00 00       	push   0xb4
  4730f2:	6a 02                	push   0x2
  4730f4:	68 35 04 00 00       	push   0x435
  4730f9:	8b ce                	mov    ecx,esi
  4730fb:	e8 d0 c8 0b 00       	call   0x52f9d0
  473100:	8b 0d ac 0b 58 00    	mov    ecx,DWORD PTR ds:0x580bac
  473106:	51                   	push   ecx
  473107:	68 a8 3e 56 00       	push   0x563ea8
  47310c:	68 a9 01 00 00       	push   0x1a9
  473111:	68 c3 00 00 00       	push   0xc3
  473116:	68 36 04 00 00       	push   0x436
  47311b:	8b ce                	mov    ecx,esi
  47311d:	e8 2e c7 0b 00       	call   0x52f850
  473122:	85 c0                	test   eax,eax
  473124:	74 25                	je     0x47314b
  473126:	6a 00                	push   0x0
  473128:	68 36 04 00 00       	push   0x436
  47312d:	8b ce                	mov    ecx,esi
  47312f:	e8 dc c7 0b 00       	call   0x52f910
  473134:	6a 00                	push   0x0
  473136:	6a 00                	push   0x0
  473138:	68 b4 00 00 00       	push   0xb4
  47313d:	6a 02                	push   0x2
  47313f:	68 36 04 00 00       	push   0x436
  473144:	8b ce                	mov    ecx,esi
  473146:	e8 85 c8 0b 00       	call   0x52f9d0
  47314b:	6a 00                	push   0x0
  47314d:	6a 00                	push   0x0
  47314f:	68 d0 42 56 00       	push   0x5642d0
  473154:	68 af 00 00 00       	push   0xaf
  473159:	68 cd 01 00 00       	push   0x1cd
  47315e:	68 cb 00 00 00       	push   0xcb
  473163:	68 37 04 00 00       	push   0x437
  473168:	8b ce                	mov    ecx,esi
  47316a:	e8 91 ca 0b 00       	call   0x52fc00
  47316f:	85 c0                	test   eax,eax
  473171:	74 31                	je     0x4731a4
  473173:	8d 54 24 04          	lea    edx,[esp+0x4]
  473177:	8b ce                	mov    ecx,esi
  473179:	52                   	push   edx
  47317a:	68 37 04 00 00       	push   0x437
  47317f:	c7 44 24 0c 00 aa 00 	mov    DWORD PTR [esp+0xc],0xaa00
  473186:	00 
  473187:	c7 44 24 10 ff ff 00 	mov    DWORD PTR [esp+0x10],0xffff
  47318e:	00 
  47318f:	c7 44 24 14 ff 00 00 	mov    DWORD PTR [esp+0x14],0xff
  473196:	00 
  473197:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  47319e:	00 
  47319f:	e8 1c cb 0b 00       	call   0x52fcc0
  4731a4:	a1 e8 2b 58 00       	mov    eax,ds:0x582be8
  4731a9:	8b ce                	mov    ecx,esi
  4731ab:	50                   	push   eax
  4731ac:	68 64 3e 56 00       	push   0x563e64
  4731b1:	68 de 01 00 00       	push   0x1de
  4731b6:	68 c3 00 00 00       	push   0xc3
  4731bb:	68 38 04 00 00       	push   0x438
  4731c0:	e8 8b c6 0b 00       	call   0x52f850
  4731c5:	85 c0                	test   eax,eax
  4731c7:	74 25                	je     0x4731ee
  4731c9:	6a 00                	push   0x0
  4731cb:	68 38 04 00 00       	push   0x438
  4731d0:	8b ce                	mov    ecx,esi
  4731d2:	e8 39 c7 0b 00       	call   0x52f910
  4731d7:	6a 00                	push   0x0
  4731d9:	6a 00                	push   0x0
  4731db:	68 b4 00 00 00       	push   0xb4
  4731e0:	6a 02                	push   0x2
  4731e2:	68 38 04 00 00       	push   0x438
  4731e7:	8b ce                	mov    ecx,esi
  4731e9:	e8 e2 c7 0b 00       	call   0x52f9d0
  4731ee:	8b 0d 44 1a 58 00    	mov    ecx,DWORD PTR ds:0x581a44
  4731f4:	51                   	push   ecx
  4731f5:	68 88 47 56 00       	push   0x564788
  4731fa:	68 a3 01 00 00       	push   0x1a3
  4731ff:	6a 32                	push   0x32
  473201:	68 39 04 00 00       	push   0x439
  473206:	8b ce                	mov    ecx,esi
  473208:	e8 43 c6 0b 00       	call   0x52f850
  47320d:	85 c0                	test   eax,eax
  47320f:	74 25                	je     0x473236
  473211:	6a 00                	push   0x0
  473213:	68 39 04 00 00       	push   0x439
  473218:	8b ce                	mov    ecx,esi
  47321a:	e8 f1 c6 0b 00       	call   0x52f910
  47321f:	6a 00                	push   0x0
  473221:	6a 00                	push   0x0
  473223:	68 8c 00 00 00       	push   0x8c
  473228:	6a 00                	push   0x0
  47322a:	68 39 04 00 00       	push   0x439
  47322f:	8b ce                	mov    ecx,esi
  473231:	e8 9a c7 0b 00       	call   0x52f9d0
  473236:	8b 15 e8 1b 58 00    	mov    edx,DWORD PTR ds:0x581be8
  47323c:	8b ce                	mov    ecx,esi
  47323e:	52                   	push   edx
  47323f:	68 88 47 56 00       	push   0x564788
  473244:	68 b7 01 00 00       	push   0x1b7
  473249:	6a 32                	push   0x32
  47324b:	68 3a 04 00 00       	push   0x43a
  473250:	e8 fb c5 0b 00       	call   0x52f850
  473255:	85 c0                	test   eax,eax
  473257:	74 25                	je     0x47327e
  473259:	6a 00                	push   0x0
  47325b:	68 3a 04 00 00       	push   0x43a
  473260:	8b ce                	mov    ecx,esi
  473262:	e8 a9 c6 0b 00       	call   0x52f910
  473267:	6a 00                	push   0x0
  473269:	6a 00                	push   0x0
  47326b:	68 8c 00 00 00       	push   0x8c
  473270:	6a 00                	push   0x0
  473272:	68 3a 04 00 00       	push   0x43a
  473277:	8b ce                	mov    ecx,esi
  473279:	e8 52 c7 0b 00       	call   0x52f9d0
  47327e:	a1 fc 25 58 00       	mov    eax,ds:0x5825fc
  473283:	8b ce                	mov    ecx,esi
  473285:	50                   	push   eax
  473286:	68 88 47 56 00       	push   0x564788
  47328b:	68 cb 01 00 00       	push   0x1cb
  473290:	6a 32                	push   0x32
  473292:	68 3b 04 00 00       	push   0x43b
  473297:	e8 b4 c5 0b 00       	call   0x52f850
  47329c:	85 c0                	test   eax,eax
  47329e:	74 22                	je     0x4732c2
  4732a0:	6a 00                	push   0x0
  4732a2:	68 3b 04 00 00       	push   0x43b
  4732a7:	8b ce                	mov    ecx,esi
  4732a9:	e8 62 c6 0b 00       	call   0x52f910
  4732ae:	6a 00                	push   0x0
  4732b0:	6a 00                	push   0x0
  4732b2:	6a 4c                	push   0x4c
  4732b4:	6a 00                	push   0x0
  4732b6:	68 3b 04 00 00       	push   0x43b
  4732bb:	8b ce                	mov    ecx,esi
  4732bd:	e8 0e c7 0b 00       	call   0x52f9d0
  4732c2:	8b 0d f0 1b 58 00    	mov    ecx,DWORD PTR ds:0x581bf0
  4732c8:	51                   	push   ecx
  4732c9:	68 88 47 56 00       	push   0x564788
  4732ce:	68 df 01 00 00       	push   0x1df
  4732d3:	6a 32                	push   0x32
  4732d5:	68 3c 04 00 00       	push   0x43c
  4732da:	8b ce                	mov    ecx,esi
  4732dc:	e8 6f c5 0b 00       	call   0x52f850
  4732e1:	85 c0                	test   eax,eax
  4732e3:	74 22                	je     0x473307
  4732e5:	6a 00                	push   0x0
  4732e7:	68 3c 04 00 00       	push   0x43c
  4732ec:	8b ce                	mov    ecx,esi
  4732ee:	e8 1d c6 0b 00       	call   0x52f910
  4732f3:	6a 00                	push   0x0
  4732f5:	6a 00                	push   0x0
  4732f7:	6a 4c                	push   0x4c
  4732f9:	6a 00                	push   0x0
  4732fb:	68 3c 04 00 00       	push   0x43c
  473300:	8b ce                	mov    ecx,esi
  473302:	e8 c9 c6 0b 00       	call   0x52f9d0
  473307:	68 04 74 56 00       	push   0x567404
  47330c:	68 88 47 56 00       	push   0x564788
  473311:	68 df 01 00 00       	push   0x1df
  473316:	68 91 00 00 00       	push   0x91
  47331b:	68 3d 04 00 00       	push   0x43d
  473320:	8b ce                	mov    ecx,esi
  473322:	e8 29 c5 0b 00       	call   0x52f850
  473327:	85 c0                	test   eax,eax
  473329:	74 22                	je     0x47334d
  47332b:	6a 00                	push   0x0
  47332d:	68 3d 04 00 00       	push   0x43d
  473332:	8b ce                	mov    ecx,esi
  473334:	e8 d7 c5 0b 00       	call   0x52f910
  473339:	6a 00                	push   0x0
  47333b:	6a 00                	push   0x0
  47333d:	6a 0f                	push   0xf
  47333f:	6a 02                	push   0x2
  473341:	68 3d 04 00 00       	push   0x43d
  473346:	8b ce                	mov    ecx,esi
  473348:	e8 83 c6 0b 00       	call   0x52f9d0
  47334d:	68 38 45 56 00       	push   0x564538
  473352:	68 88 47 56 00       	push   0x564788
  473357:	68 cb 01 00 00       	push   0x1cb
  47335c:	68 91 00 00 00       	push   0x91
  473361:	68 3e 04 00 00       	push   0x43e
  473366:	8b ce                	mov    ecx,esi
  473368:	e8 e3 c4 0b 00       	call   0x52f850
  47336d:	85 c0                	test   eax,eax
  47336f:	74 22                	je     0x473393
  473371:	6a 00                	push   0x0
  473373:	68 3e 04 00 00       	push   0x43e
  473378:	8b ce                	mov    ecx,esi
  47337a:	e8 91 c5 0b 00       	call   0x52f910
  47337f:	6a 00                	push   0x0
  473381:	6a 00                	push   0x0
  473383:	6a 0f                	push   0xf
  473385:	6a 02                	push   0x2
  473387:	68 3e 04 00 00       	push   0x43e
  47338c:	8b ce                	mov    ecx,esi
  47338e:	e8 3d c6 0b 00       	call   0x52f9d0
  473393:	68 78 71 56 00       	push   0x567178
  473398:	68 a8 3e 56 00       	push   0x563ea8
  47339d:	6a 2c                	push   0x2c
  47339f:	6a 7c                	push   0x7c
  4733a1:	68 3f 04 00 00       	push   0x43f
  4733a6:	8b ce                	mov    ecx,esi
  4733a8:	e8 a3 c4 0b 00       	call   0x52f850
  4733ad:	85 c0                	test   eax,eax
  4733af:	74 25                	je     0x4733d6
  4733b1:	6a 00                	push   0x0
  4733b3:	68 3f 04 00 00       	push   0x43f
  4733b8:	8b ce                	mov    ecx,esi
  4733ba:	e8 51 c5 0b 00       	call   0x52f910
  4733bf:	6a 00                	push   0x0
  4733c1:	6a 00                	push   0x0
  4733c3:	68 aa 00 00 00       	push   0xaa
  4733c8:	6a 02                	push   0x2
  4733ca:	68 3f 04 00 00       	push   0x43f
  4733cf:	8b ce                	mov    ecx,esi
  4733d1:	e8 fa c5 0b 00       	call   0x52f9d0
  4733d6:	68 c4 4a 56 00       	push   0x564ac4
  4733db:	68 88 47 56 00       	push   0x564788
  4733e0:	6a 48                	push   0x48
  4733e2:	6a 7c                	push   0x7c
  4733e4:	68 40 04 00 00       	push   0x440
  4733e9:	8b ce                	mov    ecx,esi
  4733eb:	e8 60 c4 0b 00       	call   0x52f850
  4733f0:	85 c0                	test   eax,eax
  4733f2:	74 25                	je     0x473419
  4733f4:	6a 00                	push   0x0
  4733f6:	68 40 04 00 00       	push   0x440
  4733fb:	8b ce                	mov    ecx,esi
  4733fd:	e8 0e c5 0b 00       	call   0x52f910
  473402:	6a 00                	push   0x0
  473404:	6a 00                	push   0x0
  473406:	68 aa 00 00 00       	push   0xaa
  47340b:	6a 02                	push   0x2
  47340d:	68 40 04 00 00       	push   0x440
  473412:	8b ce                	mov    ecx,esi
  473414:	e8 b7 c5 0b 00       	call   0x52f9d0
  473419:	68 78 71 56 00       	push   0x567178
  47341e:	68 a8 3e 56 00       	push   0x563ea8
  473423:	6a 68                	push   0x68
  473425:	6a 7c                	push   0x7c
  473427:	68 41 04 00 00       	push   0x441
  47342c:	8b ce                	mov    ecx,esi
  47342e:	e8 1d c4 0b 00       	call   0x52f850
  473433:	85 c0                	test   eax,eax
  473435:	74 25                	je     0x47345c
  473437:	6a 00                	push   0x0
  473439:	68 41 04 00 00       	push   0x441
  47343e:	8b ce                	mov    ecx,esi
  473440:	e8 cb c4 0b 00       	call   0x52f910
  473445:	6a 00                	push   0x0
  473447:	6a 00                	push   0x0
  473449:	68 aa 00 00 00       	push   0xaa
  47344e:	6a 02                	push   0x2
  473450:	68 41 04 00 00       	push   0x441
  473455:	8b ce                	mov    ecx,esi
  473457:	e8 74 c5 0b 00       	call   0x52f9d0
  47345c:	68 c4 4a 56 00       	push   0x564ac4
  473461:	68 88 47 56 00       	push   0x564788
  473466:	68 84 00 00 00       	push   0x84
  47346b:	6a 7c                	push   0x7c
  47346d:	68 42 04 00 00       	push   0x442
  473472:	8b ce                	mov    ecx,esi
  473474:	e8 d7 c3 0b 00       	call   0x52f850
  473479:	85 c0                	test   eax,eax
  47347b:	74 25                	je     0x4734a2
  47347d:	6a 00                	push   0x0
  47347f:	68 42 04 00 00       	push   0x442
  473484:	8b ce                	mov    ecx,esi
  473486:	e8 85 c4 0b 00       	call   0x52f910
  47348b:	6a 00                	push   0x0
  47348d:	6a 00                	push   0x0
  47348f:	68 aa 00 00 00       	push   0xaa
  473494:	6a 02                	push   0x2
  473496:	68 42 04 00 00       	push   0x442
  47349b:	8b ce                	mov    ecx,esi
  47349d:	e8 2e c5 0b 00       	call   0x52f9d0
  4734a2:	68 78 71 56 00       	push   0x567178
  4734a7:	68 a8 3e 56 00       	push   0x563ea8
  4734ac:	68 a4 00 00 00       	push   0xa4
  4734b1:	6a 7c                	push   0x7c
  4734b3:	68 43 04 00 00       	push   0x443
  4734b8:	8b ce                	mov    ecx,esi
  4734ba:	e8 91 c3 0b 00       	call   0x52f850
  4734bf:	85 c0                	test   eax,eax
  4734c1:	74 25                	je     0x4734e8
  4734c3:	6a 00                	push   0x0
  4734c5:	68 43 04 00 00       	push   0x443
  4734ca:	8b ce                	mov    ecx,esi
  4734cc:	e8 3f c4 0b 00       	call   0x52f910
  4734d1:	6a 00                	push   0x0
  4734d3:	6a 00                	push   0x0
  4734d5:	68 aa 00 00 00       	push   0xaa
  4734da:	6a 02                	push   0x2
  4734dc:	68 43 04 00 00       	push   0x443
  4734e1:	8b ce                	mov    ecx,esi
  4734e3:	e8 e8 c4 0b 00       	call   0x52f9d0
  4734e8:	68 c4 4a 56 00       	push   0x564ac4
  4734ed:	68 88 47 56 00       	push   0x564788
  4734f2:	68 c0 00 00 00       	push   0xc0
  4734f7:	6a 7c                	push   0x7c
  4734f9:	68 44 04 00 00       	push   0x444
  4734fe:	8b ce                	mov    ecx,esi
  473500:	e8 4b c3 0b 00       	call   0x52f850
  473505:	85 c0                	test   eax,eax
  473507:	74 25                	je     0x47352e
  473509:	6a 00                	push   0x0
  47350b:	68 44 04 00 00       	push   0x444
  473510:	8b ce                	mov    ecx,esi
  473512:	e8 f9 c3 0b 00       	call   0x52f910
  473517:	6a 00                	push   0x0
  473519:	6a 00                	push   0x0
  47351b:	68 aa 00 00 00       	push   0xaa
  473520:	6a 02                	push   0x2
  473522:	68 44 04 00 00       	push   0x444
  473527:	8b ce                	mov    ecx,esi
  473529:	e8 a2 c4 0b 00       	call   0x52f9d0
  47352e:	68 78 71 56 00       	push   0x567178
  473533:	68 a8 3e 56 00       	push   0x563ea8
  473538:	68 e0 00 00 00       	push   0xe0
  47353d:	6a 7c                	push   0x7c
  47353f:	68 45 04 00 00       	push   0x445
  473544:	8b ce                	mov    ecx,esi
  473546:	e8 05 c3 0b 00       	call   0x52f850
  47354b:	85 c0                	test   eax,eax
  47354d:	74 25                	je     0x473574
  47354f:	6a 00                	push   0x0
  473551:	68 45 04 00 00       	push   0x445
  473556:	8b ce                	mov    ecx,esi
  473558:	e8 b3 c3 0b 00       	call   0x52f910
  47355d:	6a 00                	push   0x0
  47355f:	6a 00                	push   0x0
  473561:	68 aa 00 00 00       	push   0xaa
  473566:	6a 02                	push   0x2
  473568:	68 45 04 00 00       	push   0x445
  47356d:	8b ce                	mov    ecx,esi
  47356f:	e8 5c c4 0b 00       	call   0x52f9d0
  473574:	68 c4 4a 56 00       	push   0x564ac4
  473579:	68 88 47 56 00       	push   0x564788
  47357e:	68 fc 00 00 00       	push   0xfc
  473583:	6a 7c                	push   0x7c
  473585:	68 46 04 00 00       	push   0x446
  47358a:	8b ce                	mov    ecx,esi
  47358c:	e8 bf c2 0b 00       	call   0x52f850
  473591:	85 c0                	test   eax,eax
  473593:	74 25                	je     0x4735ba
  473595:	6a 00                	push   0x0
  473597:	68 46 04 00 00       	push   0x446
  47359c:	8b ce                	mov    ecx,esi
  47359e:	e8 6d c3 0b 00       	call   0x52f910
  4735a3:	6a 00                	push   0x0
  4735a5:	6a 00                	push   0x0
  4735a7:	68 aa 00 00 00       	push   0xaa
  4735ac:	6a 02                	push   0x2
  4735ae:	68 46 04 00 00       	push   0x446
  4735b3:	8b ce                	mov    ecx,esi
  4735b5:	e8 16 c4 0b 00       	call   0x52f9d0
  4735ba:	68 78 71 56 00       	push   0x567178
  4735bf:	68 a8 3e 56 00       	push   0x563ea8
  4735c4:	68 1c 01 00 00       	push   0x11c
  4735c9:	6a 7c                	push   0x7c
  4735cb:	68 47 04 00 00       	push   0x447
  4735d0:	8b ce                	mov    ecx,esi
  4735d2:	e8 79 c2 0b 00       	call   0x52f850
  4735d7:	85 c0                	test   eax,eax
  4735d9:	74 25                	je     0x473600
  4735db:	6a 00                	push   0x0
  4735dd:	68 47 04 00 00       	push   0x447
  4735e2:	8b ce                	mov    ecx,esi
  4735e4:	e8 27 c3 0b 00       	call   0x52f910
  4735e9:	6a 00                	push   0x0
  4735eb:	6a 00                	push   0x0
  4735ed:	68 aa 00 00 00       	push   0xaa
  4735f2:	6a 02                	push   0x2
  4735f4:	68 47 04 00 00       	push   0x447
  4735f9:	8b ce                	mov    ecx,esi
  4735fb:	e8 d0 c3 0b 00       	call   0x52f9d0
  473600:	68 c4 4a 56 00       	push   0x564ac4
  473605:	68 88 47 56 00       	push   0x564788
  47360a:	68 38 01 00 00       	push   0x138
  47360f:	6a 7c                	push   0x7c
  473611:	68 48 04 00 00       	push   0x448
  473616:	8b ce                	mov    ecx,esi
  473618:	e8 33 c2 0b 00       	call   0x52f850
  47361d:	85 c0                	test   eax,eax
  47361f:	74 25                	je     0x473646
  473621:	6a 00                	push   0x0
  473623:	68 48 04 00 00       	push   0x448
  473628:	8b ce                	mov    ecx,esi
  47362a:	e8 e1 c2 0b 00       	call   0x52f910
  47362f:	6a 00                	push   0x0
  473631:	6a 00                	push   0x0
  473633:	68 aa 00 00 00       	push   0xaa
  473638:	6a 02                	push   0x2
  47363a:	68 48 04 00 00       	push   0x448
  47363f:	8b ce                	mov    ecx,esi
  473641:	e8 8a c3 0b 00       	call   0x52f9d0
  473646:	68 78 71 56 00       	push   0x567178
  47364b:	68 a8 3e 56 00       	push   0x563ea8
  473650:	68 57 01 00 00       	push   0x157
  473655:	6a 7c                	push   0x7c
  473657:	68 49 04 00 00       	push   0x449
  47365c:	8b ce                	mov    ecx,esi
  47365e:	e8 ed c1 0b 00       	call   0x52f850
  473663:	85 c0                	test   eax,eax
  473665:	74 25                	je     0x47368c
  473667:	6a 00                	push   0x0
  473669:	68 49 04 00 00       	push   0x449
  47366e:	8b ce                	mov    ecx,esi
  473670:	e8 9b c2 0b 00       	call   0x52f910
  473675:	6a 00                	push   0x0
  473677:	6a 00                	push   0x0
  473679:	68 aa 00 00 00       	push   0xaa
  47367e:	6a 02                	push   0x2
  473680:	68 49 04 00 00       	push   0x449
  473685:	8b ce                	mov    ecx,esi
  473687:	e8 44 c3 0b 00       	call   0x52f9d0
  47368c:	68 c4 4a 56 00       	push   0x564ac4
  473691:	68 88 47 56 00       	push   0x564788
  473696:	68 73 01 00 00       	push   0x173
  47369b:	6a 7c                	push   0x7c
  47369d:	68 4a 04 00 00       	push   0x44a
  4736a2:	8b ce                	mov    ecx,esi
  4736a4:	e8 a7 c1 0b 00       	call   0x52f850
  4736a9:	85 c0                	test   eax,eax
  4736ab:	74 25                	je     0x4736d2
  4736ad:	6a 00                	push   0x0
  4736af:	68 4a 04 00 00       	push   0x44a
  4736b4:	8b ce                	mov    ecx,esi
  4736b6:	e8 55 c2 0b 00       	call   0x52f910
  4736bb:	6a 00                	push   0x0
  4736bd:	6a 00                	push   0x0
  4736bf:	68 aa 00 00 00       	push   0xaa
  4736c4:	6a 02                	push   0x2
  4736c6:	68 4a 04 00 00       	push   0x44a
  4736cb:	8b ce                	mov    ecx,esi
  4736cd:	e8 fe c2 0b 00       	call   0x52f9d0
  4736d2:	8b 15 88 12 58 00    	mov    edx,DWORD PTR ds:0x581288
  4736d8:	8b ce                	mov    ecx,esi
  4736da:	52                   	push   edx
  4736db:	68 88 47 56 00       	push   0x564788
  4736e0:	6a 2f                	push   0x2f
  4736e2:	68 6e 01 00 00       	push   0x16e
  4736e7:	68 4b 04 00 00       	push   0x44b
  4736ec:	e8 5f c1 0b 00       	call   0x52f850
  4736f1:	85 c0                	test   eax,eax
  4736f3:	74 22                	je     0x473717
  4736f5:	6a 00                	push   0x0
  4736f7:	68 4b 04 00 00       	push   0x44b
  4736fc:	8b ce                	mov    ecx,esi
  4736fe:	e8 0d c2 0b 00       	call   0x52f910
  473703:	6a 00                	push   0x0
  473705:	6a 00                	push   0x0
  473707:	6a 73                	push   0x73
  473709:	6a 00                	push   0x0
  47370b:	68 4b 04 00 00       	push   0x44b
  473710:	8b ce                	mov    ecx,esi
  473712:	e8 b9 c2 0b 00       	call   0x52f9d0
  473717:	a1 90 29 58 00       	mov    eax,ds:0x582990
  47371c:	8b ce                	mov    ecx,esi
  47371e:	50                   	push   eax
  47371f:	68 88 47 56 00       	push   0x564788
  473724:	6a 43                	push   0x43
  473726:	68 6e 01 00 00       	push   0x16e
  47372b:	68 4d 04 00 00       	push   0x44d
  473730:	e8 1b c1 0b 00       	call   0x52f850
  473735:	85 c0                	test   eax,eax
  473737:	74 22                	je     0x47375b
  473739:	6a 00                	push   0x0
  47373b:	68 4d 04 00 00       	push   0x44d
  473740:	8b ce                	mov    ecx,esi
  473742:	e8 c9 c1 0b 00       	call   0x52f910
  473747:	6a 00                	push   0x0
  473749:	6a 00                	push   0x0
  47374b:	6a 73                	push   0x73
  47374d:	6a 00                	push   0x0
  47374f:	68 4d 04 00 00       	push   0x44d
  473754:	8b ce                	mov    ecx,esi
  473756:	e8 75 c2 0b 00       	call   0x52f9d0
  47375b:	6a 00                	push   0x0
  47375d:	6a 00                	push   0x0
  47375f:	68 10 46 56 00       	push   0x564610
  473764:	6a 2e                	push   0x2e
  473766:	68 d9 01 00 00       	push   0x1d9
  47376b:	68 4e 04 00 00       	push   0x44e
  473770:	8b ce                	mov    ecx,esi
  473772:	e8 39 be 0b 00       	call   0x52f5b0
  473777:	6a 00                	push   0x0
  473779:	6a 00                	push   0x0
  47377b:	68 fc 45 56 00       	push   0x5645fc
  473780:	6a 2e                	push   0x2e
  473782:	68 1e 02 00 00       	push   0x21e
  473787:	68 4f 04 00 00       	push   0x44f
  47378c:	8b ce                	mov    ecx,esi
  47378e:	e8 1d be 0b 00       	call   0x52f5b0
  473793:	6a 00                	push   0x0
  473795:	6a 00                	push   0x0
  473797:	68 fc 45 56 00       	push   0x5645fc
  47379c:	6a 41                	push   0x41
  47379e:	68 1e 02 00 00       	push   0x21e
  4737a3:	68 50 04 00 00       	push   0x450
  4737a8:	8b ce                	mov    ecx,esi
  4737aa:	e8 01 be 0b 00       	call   0x52f5b0
  4737af:	6a 00                	push   0x0
  4737b1:	6a 00                	push   0x0
  4737b3:	68 10 46 56 00       	push   0x564610
  4737b8:	6a 41                	push   0x41
  4737ba:	68 d9 01 00 00       	push   0x1d9
  4737bf:	68 51 04 00 00       	push   0x451
  4737c4:	8b ce                	mov    ecx,esi
  4737c6:	e8 e5 bd 0b 00       	call   0x52f5b0
  4737cb:	68 00 74 56 00       	push   0x567400
  4737d0:	68 88 47 56 00       	push   0x564788
  4737d5:	6a 43                	push   0x43
  4737d7:	68 f2 01 00 00       	push   0x1f2
  4737dc:	68 52 04 00 00       	push   0x452
  4737e1:	8b ce                	mov    ecx,esi
  4737e3:	e8 68 c0 0b 00       	call   0x52f850
  4737e8:	85 c0                	test   eax,eax
  4737ea:	74 22                	je     0x47380e
  4737ec:	6a 00                	push   0x0
  4737ee:	68 52 04 00 00       	push   0x452
  4737f3:	8b ce                	mov    ecx,esi
  4737f5:	e8 16 c1 0b 00       	call   0x52f910
  4737fa:	6a 00                	push   0x0
  4737fc:	6a 00                	push   0x0
  4737fe:	6a 2d                	push   0x2d
  473800:	6a 02                	push   0x2
  473802:	68 52 04 00 00       	push   0x452
  473807:	8b ce                	mov    ecx,esi
  473809:	e8 c2 c1 0b 00       	call   0x52f9d0
  47380e:	68 f8 73 56 00       	push   0x5673f8
  473813:	68 88 47 56 00       	push   0x564788
  473818:	6a 2f                	push   0x2f
  47381a:	68 f2 01 00 00       	push   0x1f2
  47381f:	68 53 04 00 00       	push   0x453
  473824:	8b ce                	mov    ecx,esi
  473826:	e8 25 c0 0b 00       	call   0x52f850
  47382b:	85 c0                	test   eax,eax
  47382d:	74 22                	je     0x473851
  47382f:	6a 00                	push   0x0
  473831:	68 53 04 00 00       	push   0x453
  473836:	8b ce                	mov    ecx,esi
  473838:	e8 d3 c0 0b 00       	call   0x52f910
  47383d:	6a 00                	push   0x0
  47383f:	6a 00                	push   0x0
  473841:	6a 2d                	push   0x2d
  473843:	6a 02                	push   0x2
  473845:	68 53 04 00 00       	push   0x453
  47384a:	8b ce                	mov    ecx,esi
  47384c:	e8 7f c1 0b 00       	call   0x52f9d0
  473851:	8b 0d 88 12 58 00    	mov    ecx,DWORD PTR ds:0x581288
  473857:	51                   	push   ecx
  473858:	68 88 47 56 00       	push   0x564788
  47385d:	6a 6a                	push   0x6a
  47385f:	68 6e 01 00 00       	push   0x16e
  473864:	68 54 04 00 00       	push   0x454
  473869:	8b ce                	mov    ecx,esi
  47386b:	e8 e0 bf 0b 00       	call   0x52f850
  473870:	85 c0                	test   eax,eax
  473872:	74 22                	je     0x473896
  473874:	6a 00                	push   0x0
  473876:	68 54 04 00 00       	push   0x454
  47387b:	8b ce                	mov    ecx,esi
  47387d:	e8 8e c0 0b 00       	call   0x52f910
  473882:	6a 00                	push   0x0
  473884:	6a 00                	push   0x0
  473886:	6a 73                	push   0x73
  473888:	6a 00                	push   0x0
  47388a:	68 54 04 00 00       	push   0x454
  47388f:	8b ce                	mov    ecx,esi
  473891:	e8 3a c1 0b 00       	call   0x52f9d0
  473896:	8b 15 90 29 58 00    	mov    edx,DWORD PTR ds:0x582990
  47389c:	8b ce                	mov    ecx,esi
  47389e:	52                   	push   edx
  47389f:	68 88 47 56 00       	push   0x564788
  4738a4:	6a 7e                	push   0x7e
  4738a6:	68 6e 01 00 00       	push   0x16e
  4738ab:	68 55 04 00 00       	push   0x455
  4738b0:	e8 9b bf 0b 00       	call   0x52f850
  4738b5:	85 c0                	test   eax,eax
  4738b7:	74 22                	je     0x4738db
  4738b9:	6a 00                	push   0x0
  4738bb:	68 55 04 00 00       	push   0x455
  4738c0:	8b ce                	mov    ecx,esi
  4738c2:	e8 49 c0 0b 00       	call   0x52f910
  4738c7:	6a 00                	push   0x0
  4738c9:	6a 00                	push   0x0
  4738cb:	6a 73                	push   0x73
  4738cd:	6a 00                	push   0x0
  4738cf:	68 55 04 00 00       	push   0x455
  4738d4:	8b ce                	mov    ecx,esi
  4738d6:	e8 f5 c0 0b 00       	call   0x52f9d0
  4738db:	6a 00                	push   0x0
  4738dd:	6a 00                	push   0x0
  4738df:	68 10 46 56 00       	push   0x564610
  4738e4:	6a 69                	push   0x69
  4738e6:	68 d9 01 00 00       	push   0x1d9
  4738eb:	68 56 04 00 00       	push   0x456
  4738f0:	8b ce                	mov    ecx,esi
  4738f2:	e8 b9 bc 0b 00       	call   0x52f5b0
  4738f7:	6a 00                	push   0x0
  4738f9:	6a 00                	push   0x0
  4738fb:	68 fc 45 56 00       	push   0x5645fc
  473900:	6a 69                	push   0x69
  473902:	68 1e 02 00 00       	push   0x21e
  473907:	68 57 04 00 00       	push   0x457
  47390c:	8b ce                	mov    ecx,esi
  47390e:	e8 9d bc 0b 00       	call   0x52f5b0
  473913:	6a 00                	push   0x0
  473915:	6a 00                	push   0x0
  473917:	68 fc 45 56 00       	push   0x5645fc
  47391c:	6a 7c                	push   0x7c
  47391e:	68 1e 02 00 00       	push   0x21e
  473923:	68 58 04 00 00       	push   0x458
  473928:	8b ce                	mov    ecx,esi
  47392a:	e8 81 bc 0b 00       	call   0x52f5b0
  47392f:	6a 00                	push   0x0
  473931:	6a 00                	push   0x0
  473933:	68 10 46 56 00       	push   0x564610
  473938:	6a 7c                	push   0x7c
  47393a:	68 d9 01 00 00       	push   0x1d9
  47393f:	68 59 04 00 00       	push   0x459
  473944:	8b ce                	mov    ecx,esi
  473946:	e8 65 bc 0b 00       	call   0x52f5b0
  47394b:	68 00 74 56 00       	push   0x567400
  473950:	68 88 47 56 00       	push   0x564788
  473955:	6a 7e                	push   0x7e
  473957:	68 f2 01 00 00       	push   0x1f2
  47395c:	68 5a 04 00 00       	push   0x45a
  473961:	8b ce                	mov    ecx,esi
  473963:	e8 e8 be 0b 00       	call   0x52f850
  473968:	85 c0                	test   eax,eax
  47396a:	74 22                	je     0x47398e
  47396c:	6a 00                	push   0x0
  47396e:	68 5a 04 00 00       	push   0x45a
  473973:	8b ce                	mov    ecx,esi
  473975:	e8 96 bf 0b 00       	call   0x52f910
  47397a:	6a 00                	push   0x0
  47397c:	6a 00                	push   0x0
  47397e:	6a 2d                	push   0x2d
  473980:	6a 02                	push   0x2
  473982:	68 5a 04 00 00       	push   0x45a
  473987:	8b ce                	mov    ecx,esi
  473989:	e8 42 c0 0b 00       	call   0x52f9d0
  47398e:	68 f8 73 56 00       	push   0x5673f8
  473993:	68 88 47 56 00       	push   0x564788
  473998:	6a 6a                	push   0x6a
  47399a:	68 f2 01 00 00       	push   0x1f2
  47399f:	68 5b 04 00 00       	push   0x45b
  4739a4:	8b ce                	mov    ecx,esi
  4739a6:	e8 a5 be 0b 00       	call   0x52f850
  4739ab:	85 c0                	test   eax,eax
  4739ad:	74 22                	je     0x4739d1
  4739af:	6a 00                	push   0x0
  4739b1:	68 5b 04 00 00       	push   0x45b
  4739b6:	8b ce                	mov    ecx,esi
  4739b8:	e8 53 bf 0b 00       	call   0x52f910
  4739bd:	6a 00                	push   0x0
  4739bf:	6a 00                	push   0x0
  4739c1:	6a 2d                	push   0x2d
  4739c3:	6a 02                	push   0x2
  4739c5:	68 5b 04 00 00       	push   0x45b
  4739ca:	8b ce                	mov    ecx,esi
  4739cc:	e8 ff bf 0b 00       	call   0x52f9d0
  4739d1:	a1 88 12 58 00       	mov    eax,ds:0x581288
  4739d6:	8b ce                	mov    ecx,esi
  4739d8:	50                   	push   eax
  4739d9:	68 88 47 56 00       	push   0x564788
  4739de:	68 a6 00 00 00       	push   0xa6
  4739e3:	68 6e 01 00 00       	push   0x16e
  4739e8:	68 5c 04 00 00       	push   0x45c
  4739ed:	e8 5e be 0b 00       	call   0x52f850
  4739f2:	85 c0                	test   eax,eax
  4739f4:	74 22                	je     0x473a18
  4739f6:	6a 00                	push   0x0
  4739f8:	68 5c 04 00 00       	push   0x45c
  4739fd:	8b ce                	mov    ecx,esi
  4739ff:	e8 0c bf 0b 00       	call   0x52f910
  473a04:	6a 00                	push   0x0
  473a06:	6a 00                	push   0x0
  473a08:	6a 73                	push   0x73
  473a0a:	6a 00                	push   0x0
  473a0c:	68 5c 04 00 00       	push   0x45c
  473a11:	8b ce                	mov    ecx,esi
  473a13:	e8 b8 bf 0b 00       	call   0x52f9d0
  473a18:	8b 0d 90 29 58 00    	mov    ecx,DWORD PTR ds:0x582990
  473a1e:	51                   	push   ecx
  473a1f:	68 88 47 56 00       	push   0x564788
  473a24:	68 ba 00 00 00       	push   0xba
  473a29:	68 6e 01 00 00       	push   0x16e
  473a2e:	68 5d 04 00 00       	push   0x45d
  473a33:	8b ce                	mov    ecx,esi
  473a35:	e8 16 be 0b 00       	call   0x52f850
  473a3a:	85 c0                	test   eax,eax
  473a3c:	74 22                	je     0x473a60
  473a3e:	6a 00                	push   0x0
  473a40:	68 5d 04 00 00       	push   0x45d
  473a45:	8b ce                	mov    ecx,esi
  473a47:	e8 c4 be 0b 00       	call   0x52f910
  473a4c:	6a 00                	push   0x0
  473a4e:	6a 00                	push   0x0
  473a50:	6a 73                	push   0x73
  473a52:	6a 00                	push   0x0
  473a54:	68 5d 04 00 00       	push   0x45d
  473a59:	8b ce                	mov    ecx,esi
  473a5b:	e8 70 bf 0b 00       	call   0x52f9d0
  473a60:	6a 00                	push   0x0
  473a62:	6a 00                	push   0x0
  473a64:	68 10 46 56 00       	push   0x564610
  473a69:	68 a5 00 00 00       	push   0xa5
  473a6e:	68 d9 01 00 00       	push   0x1d9
  473a73:	68 5e 04 00 00       	push   0x45e
  473a78:	8b ce                	mov    ecx,esi
  473a7a:	e8 31 bb 0b 00       	call   0x52f5b0
  473a7f:	6a 00                	push   0x0
  473a81:	6a 00                	push   0x0
  473a83:	68 fc 45 56 00       	push   0x5645fc
  473a88:	68 a5 00 00 00       	push   0xa5
  473a8d:	68 1e 02 00 00       	push   0x21e
  473a92:	68 5f 04 00 00       	push   0x45f
  473a97:	8b ce                	mov    ecx,esi
  473a99:	e8 12 bb 0b 00       	call   0x52f5b0
  473a9e:	6a 00                	push   0x0
  473aa0:	6a 00                	push   0x0
  473aa2:	68 fc 45 56 00       	push   0x5645fc
  473aa7:	68 b8 00 00 00       	push   0xb8
  473aac:	68 1e 02 00 00       	push   0x21e
  473ab1:	68 60 04 00 00       	push   0x460
  473ab6:	8b ce                	mov    ecx,esi
  473ab8:	e8 f3 ba 0b 00       	call   0x52f5b0
  473abd:	6a 00                	push   0x0
  473abf:	6a 00                	push   0x0
  473ac1:	68 10 46 56 00       	push   0x564610
  473ac6:	68 b8 00 00 00       	push   0xb8
  473acb:	68 d9 01 00 00       	push   0x1d9
  473ad0:	68 61 04 00 00       	push   0x461
  473ad5:	8b ce                	mov    ecx,esi
  473ad7:	e8 d4 ba 0b 00       	call   0x52f5b0
  473adc:	68 00 74 56 00       	push   0x567400
  473ae1:	68 88 47 56 00       	push   0x564788
  473ae6:	68 ba 00 00 00       	push   0xba
  473aeb:	68 f2 01 00 00       	push   0x1f2
  473af0:	68 62 04 00 00       	push   0x462
  473af5:	8b ce                	mov    ecx,esi
  473af7:	e8 54 bd 0b 00       	call   0x52f850
  473afc:	85 c0                	test   eax,eax
  473afe:	74 22                	je     0x473b22
  473b00:	6a 00                	push   0x0
  473b02:	68 62 04 00 00       	push   0x462
  473b07:	8b ce                	mov    ecx,esi
  473b09:	e8 02 be 0b 00       	call   0x52f910
  473b0e:	6a 00                	push   0x0
  473b10:	6a 00                	push   0x0
  473b12:	6a 2d                	push   0x2d
  473b14:	6a 02                	push   0x2
  473b16:	68 62 04 00 00       	push   0x462
  473b1b:	8b ce                	mov    ecx,esi
  473b1d:	e8 ae be 0b 00       	call   0x52f9d0
  473b22:	68 f8 73 56 00       	push   0x5673f8
  473b27:	68 88 47 56 00       	push   0x564788
  473b2c:	68 a6 00 00 00       	push   0xa6
  473b31:	68 f2 01 00 00       	push   0x1f2
  473b36:	68 63 04 00 00       	push   0x463
  473b3b:	8b ce                	mov    ecx,esi
  473b3d:	e8 0e bd 0b 00       	call   0x52f850
  473b42:	85 c0                	test   eax,eax
  473b44:	74 22                	je     0x473b68
  473b46:	6a 00                	push   0x0
  473b48:	68 63 04 00 00       	push   0x463
  473b4d:	8b ce                	mov    ecx,esi
  473b4f:	e8 bc bd 0b 00       	call   0x52f910
  473b54:	6a 00                	push   0x0
  473b56:	6a 00                	push   0x0
  473b58:	6a 2d                	push   0x2d
  473b5a:	6a 02                	push   0x2
  473b5c:	68 63 04 00 00       	push   0x463
  473b61:	8b ce                	mov    ecx,esi
  473b63:	e8 68 be 0b 00       	call   0x52f9d0
  473b68:	8b 15 88 12 58 00    	mov    edx,DWORD PTR ds:0x581288
  473b6e:	8b ce                	mov    ecx,esi
  473b70:	52                   	push   edx
  473b71:	68 88 47 56 00       	push   0x564788
  473b76:	68 e3 00 00 00       	push   0xe3
  473b7b:	68 6e 01 00 00       	push   0x16e
  473b80:	68 64 04 00 00       	push   0x464
  473b85:	e8 c6 bc 0b 00       	call   0x52f850
  473b8a:	85 c0                	test   eax,eax
  473b8c:	74 22                	je     0x473bb0
  473b8e:	6a 00                	push   0x0
  473b90:	68 64 04 00 00       	push   0x464
  473b95:	8b ce                	mov    ecx,esi
  473b97:	e8 74 bd 0b 00       	call   0x52f910
  473b9c:	6a 00                	push   0x0
  473b9e:	6a 00                	push   0x0
  473ba0:	6a 73                	push   0x73
  473ba2:	6a 00                	push   0x0
  473ba4:	68 64 04 00 00       	push   0x464
  473ba9:	8b ce                	mov    ecx,esi
  473bab:	e8 20 be 0b 00       	call   0x52f9d0
  473bb0:	a1 90 29 58 00       	mov    eax,ds:0x582990
  473bb5:	8b ce                	mov    ecx,esi
  473bb7:	50                   	push   eax
  473bb8:	68 88 47 56 00       	push   0x564788
  473bbd:	68 f7 00 00 00       	push   0xf7
  473bc2:	68 6e 01 00 00       	push   0x16e
  473bc7:	68 65 04 00 00       	push   0x465
  473bcc:	e8 7f bc 0b 00       	call   0x52f850
  473bd1:	85 c0                	test   eax,eax
  473bd3:	74 22                	je     0x473bf7
  473bd5:	6a 00                	push   0x0
  473bd7:	68 65 04 00 00       	push   0x465
  473bdc:	8b ce                	mov    ecx,esi
  473bde:	e8 2d bd 0b 00       	call   0x52f910
  473be3:	6a 00                	push   0x0
  473be5:	6a 00                	push   0x0
  473be7:	6a 73                	push   0x73
  473be9:	6a 00                	push   0x0
  473beb:	68 65 04 00 00       	push   0x465
  473bf0:	8b ce                	mov    ecx,esi
  473bf2:	e8 d9 bd 0b 00       	call   0x52f9d0
  473bf7:	6a 00                	push   0x0
  473bf9:	6a 00                	push   0x0
  473bfb:	68 10 46 56 00       	push   0x564610
  473c00:	68 e2 00 00 00       	push   0xe2
  473c05:	68 d9 01 00 00       	push   0x1d9
  473c0a:	68 66 04 00 00       	push   0x466
  473c0f:	8b ce                	mov    ecx,esi
  473c11:	e8 9a b9 0b 00       	call   0x52f5b0
  473c16:	6a 00                	push   0x0
  473c18:	6a 00                	push   0x0
  473c1a:	68 fc 45 56 00       	push   0x5645fc
  473c1f:	68 e2 00 00 00       	push   0xe2
  473c24:	68 1e 02 00 00       	push   0x21e
  473c29:	68 67 04 00 00       	push   0x467
  473c2e:	8b ce                	mov    ecx,esi
  473c30:	e8 7b b9 0b 00       	call   0x52f5b0
  473c35:	6a 00                	push   0x0
  473c37:	6a 00                	push   0x0
  473c39:	68 fc 45 56 00       	push   0x5645fc
  473c3e:	68 f5 00 00 00       	push   0xf5
  473c43:	68 1e 02 00 00       	push   0x21e
  473c48:	68 68 04 00 00       	push   0x468
  473c4d:	8b ce                	mov    ecx,esi
  473c4f:	e8 5c b9 0b 00       	call   0x52f5b0
  473c54:	6a 00                	push   0x0
  473c56:	6a 00                	push   0x0
  473c58:	68 10 46 56 00       	push   0x564610
  473c5d:	68 f5 00 00 00       	push   0xf5
  473c62:	68 d9 01 00 00       	push   0x1d9
  473c67:	68 69 04 00 00       	push   0x469
  473c6c:	8b ce                	mov    ecx,esi
  473c6e:	e8 3d b9 0b 00       	call   0x52f5b0
  473c73:	68 00 74 56 00       	push   0x567400
  473c78:	68 88 47 56 00       	push   0x564788
  473c7d:	68 f7 00 00 00       	push   0xf7
  473c82:	68 f2 01 00 00       	push   0x1f2
  473c87:	68 6a 04 00 00       	push   0x46a
  473c8c:	8b ce                	mov    ecx,esi
  473c8e:	e8 bd bb 0b 00       	call   0x52f850
  473c93:	85 c0                	test   eax,eax
  473c95:	74 22                	je     0x473cb9
  473c97:	6a 00                	push   0x0
  473c99:	68 6a 04 00 00       	push   0x46a
  473c9e:	8b ce                	mov    ecx,esi
  473ca0:	e8 6b bc 0b 00       	call   0x52f910
  473ca5:	6a 00                	push   0x0
  473ca7:	6a 00                	push   0x0
  473ca9:	6a 2d                	push   0x2d
  473cab:	6a 02                	push   0x2
  473cad:	68 6a 04 00 00       	push   0x46a
  473cb2:	8b ce                	mov    ecx,esi
  473cb4:	e8 17 bd 0b 00       	call   0x52f9d0
  473cb9:	68 f8 73 56 00       	push   0x5673f8
  473cbe:	68 88 47 56 00       	push   0x564788
  473cc3:	68 e3 00 00 00       	push   0xe3
  473cc8:	68 f2 01 00 00       	push   0x1f2
  473ccd:	68 6b 04 00 00       	push   0x46b
  473cd2:	8b ce                	mov    ecx,esi
  473cd4:	e8 77 bb 0b 00       	call   0x52f850
  473cd9:	85 c0                	test   eax,eax
  473cdb:	74 22                	je     0x473cff
  473cdd:	6a 00                	push   0x0
  473cdf:	68 6b 04 00 00       	push   0x46b
  473ce4:	8b ce                	mov    ecx,esi
  473ce6:	e8 25 bc 0b 00       	call   0x52f910
  473ceb:	6a 00                	push   0x0
  473ced:	6a 00                	push   0x0
  473cef:	6a 2d                	push   0x2d
  473cf1:	6a 02                	push   0x2
  473cf3:	68 6b 04 00 00       	push   0x46b
  473cf8:	8b ce                	mov    ecx,esi
  473cfa:	e8 d1 bc 0b 00       	call   0x52f9d0
  473cff:	8b 0d 88 12 58 00    	mov    ecx,DWORD PTR ds:0x581288
  473d05:	51                   	push   ecx
  473d06:	68 88 47 56 00       	push   0x564788
  473d0b:	68 1f 01 00 00       	push   0x11f
  473d10:	68 6e 01 00 00       	push   0x16e
  473d15:	68 6c 04 00 00       	push   0x46c
  473d1a:	8b ce                	mov    ecx,esi
  473d1c:	e8 2f bb 0b 00       	call   0x52f850
  473d21:	85 c0                	test   eax,eax
  473d23:	74 22                	je     0x473d47
  473d25:	6a 00                	push   0x0
  473d27:	68 6c 04 00 00       	push   0x46c
  473d2c:	8b ce                	mov    ecx,esi
  473d2e:	e8 dd bb 0b 00       	call   0x52f910
  473d33:	6a 00                	push   0x0
  473d35:	6a 00                	push   0x0
  473d37:	6a 73                	push   0x73
  473d39:	6a 00                	push   0x0
  473d3b:	68 6c 04 00 00       	push   0x46c
  473d40:	8b ce                	mov    ecx,esi
  473d42:	e8 89 bc 0b 00       	call   0x52f9d0
  473d47:	8b 15 90 29 58 00    	mov    edx,DWORD PTR ds:0x582990
  473d4d:	8b ce                	mov    ecx,esi
  473d4f:	52                   	push   edx
  473d50:	68 88 47 56 00       	push   0x564788
  473d55:	68 33 01 00 00       	push   0x133
  473d5a:	68 6e 01 00 00       	push   0x16e
  473d5f:	68 6d 04 00 00       	push   0x46d
  473d64:	e8 e7 ba 0b 00       	call   0x52f850
  473d69:	85 c0                	test   eax,eax
  473d6b:	74 22                	je     0x473d8f
  473d6d:	6a 00                	push   0x0
  473d6f:	68 6d 04 00 00       	push   0x46d
  473d74:	8b ce                	mov    ecx,esi
  473d76:	e8 95 bb 0b 00       	call   0x52f910
  473d7b:	6a 00                	push   0x0
  473d7d:	6a 00                	push   0x0
  473d7f:	6a 73                	push   0x73
  473d81:	6a 00                	push   0x0
  473d83:	68 6d 04 00 00       	push   0x46d
  473d88:	8b ce                	mov    ecx,esi
  473d8a:	e8 41 bc 0b 00       	call   0x52f9d0
  473d8f:	6a 00                	push   0x0
  473d91:	6a 00                	push   0x0
  473d93:	68 10 46 56 00       	push   0x564610
  473d98:	68 1e 01 00 00       	push   0x11e
  473d9d:	68 d9 01 00 00       	push   0x1d9
  473da2:	68 6e 04 00 00       	push   0x46e
  473da7:	8b ce                	mov    ecx,esi
  473da9:	e8 02 b8 0b 00       	call   0x52f5b0
  473dae:	6a 00                	push   0x0
  473db0:	6a 00                	push   0x0
  473db2:	68 fc 45 56 00       	push   0x5645fc
  473db7:	68 1e 01 00 00       	push   0x11e
  473dbc:	68 1e 02 00 00       	push   0x21e
  473dc1:	68 6f 04 00 00       	push   0x46f
  473dc6:	8b ce                	mov    ecx,esi
  473dc8:	e8 e3 b7 0b 00       	call   0x52f5b0
  473dcd:	6a 00                	push   0x0
  473dcf:	6a 00                	push   0x0
  473dd1:	68 fc 45 56 00       	push   0x5645fc
  473dd6:	68 31 01 00 00       	push   0x131
  473ddb:	68 1e 02 00 00       	push   0x21e
  473de0:	68 70 04 00 00       	push   0x470
  473de5:	8b ce                	mov    ecx,esi
  473de7:	e8 c4 b7 0b 00       	call   0x52f5b0
  473dec:	6a 00                	push   0x0
  473dee:	6a 00                	push   0x0
  473df0:	68 10 46 56 00       	push   0x564610
  473df5:	68 31 01 00 00       	push   0x131
  473dfa:	68 d9 01 00 00       	push   0x1d9
  473dff:	68 71 04 00 00       	push   0x471
  473e04:	8b ce                	mov    ecx,esi
  473e06:	e8 a5 b7 0b 00       	call   0x52f5b0
  473e0b:	68 00 74 56 00       	push   0x567400
  473e10:	68 88 47 56 00       	push   0x564788
  473e15:	68 33 01 00 00       	push   0x133
  473e1a:	68 f2 01 00 00       	push   0x1f2
  473e1f:	68 72 04 00 00       	push   0x472
  473e24:	8b ce                	mov    ecx,esi
  473e26:	e8 25 ba 0b 00       	call   0x52f850
  473e2b:	85 c0                	test   eax,eax
  473e2d:	74 22                	je     0x473e51
  473e2f:	6a 00                	push   0x0
  473e31:	68 72 04 00 00       	push   0x472
  473e36:	8b ce                	mov    ecx,esi
  473e38:	e8 d3 ba 0b 00       	call   0x52f910
  473e3d:	6a 00                	push   0x0
  473e3f:	6a 00                	push   0x0
  473e41:	6a 2d                	push   0x2d
  473e43:	6a 02                	push   0x2
  473e45:	68 72 04 00 00       	push   0x472
  473e4a:	8b ce                	mov    ecx,esi
  473e4c:	e8 7f bb 0b 00       	call   0x52f9d0
  473e51:	68 f8 73 56 00       	push   0x5673f8
  473e56:	68 88 47 56 00       	push   0x564788
  473e5b:	68 1f 01 00 00       	push   0x11f
  473e60:	68 f2 01 00 00       	push   0x1f2
  473e65:	68 73 04 00 00       	push   0x473
  473e6a:	8b ce                	mov    ecx,esi
  473e6c:	e8 df b9 0b 00       	call   0x52f850
  473e71:	85 c0                	test   eax,eax
  473e73:	74 22                	je     0x473e97
  473e75:	6a 00                	push   0x0
  473e77:	68 73 04 00 00       	push   0x473
  473e7c:	8b ce                	mov    ecx,esi
  473e7e:	e8 8d ba 0b 00       	call   0x52f910
  473e83:	6a 00                	push   0x0
  473e85:	6a 00                	push   0x0
  473e87:	6a 2d                	push   0x2d
  473e89:	6a 02                	push   0x2
  473e8b:	68 73 04 00 00       	push   0x473
  473e90:	8b ce                	mov    ecx,esi
  473e92:	e8 39 bb 0b 00       	call   0x52f9d0
  473e97:	a1 88 12 58 00       	mov    eax,ds:0x581288
  473e9c:	8b ce                	mov    ecx,esi
  473e9e:	50                   	push   eax
  473e9f:	68 88 47 56 00       	push   0x564788
  473ea4:	68 5b 01 00 00       	push   0x15b
  473ea9:	68 6e 01 00 00       	push   0x16e
  473eae:	68 74 04 00 00       	push   0x474
  473eb3:	e8 98 b9 0b 00       	call   0x52f850
  473eb8:	85 c0                	test   eax,eax
  473eba:	74 22                	je     0x473ede
  473ebc:	6a 00                	push   0x0
  473ebe:	68 74 04 00 00       	push   0x474
  473ec3:	8b ce                	mov    ecx,esi
  473ec5:	e8 46 ba 0b 00       	call   0x52f910
  473eca:	6a 00                	push   0x0
  473ecc:	6a 00                	push   0x0
  473ece:	6a 73                	push   0x73
  473ed0:	6a 00                	push   0x0
  473ed2:	68 74 04 00 00       	push   0x474
  473ed7:	8b ce                	mov    ecx,esi
  473ed9:	e8 f2 ba 0b 00       	call   0x52f9d0
  473ede:	8b 0d 90 29 58 00    	mov    ecx,DWORD PTR ds:0x582990
  473ee4:	51                   	push   ecx
  473ee5:	68 88 47 56 00       	push   0x564788
  473eea:	68 6f 01 00 00       	push   0x16f
  473eef:	68 6e 01 00 00       	push   0x16e
  473ef4:	68 75 04 00 00       	push   0x475
  473ef9:	8b ce                	mov    ecx,esi
  473efb:	e8 50 b9 0b 00       	call   0x52f850
  473f00:	85 c0                	test   eax,eax
  473f02:	74 22                	je     0x473f26
  473f04:	6a 00                	push   0x0
  473f06:	68 75 04 00 00       	push   0x475
  473f0b:	8b ce                	mov    ecx,esi
  473f0d:	e8 fe b9 0b 00       	call   0x52f910
  473f12:	6a 00                	push   0x0
  473f14:	6a 00                	push   0x0
  473f16:	6a 73                	push   0x73
  473f18:	6a 00                	push   0x0
  473f1a:	68 75 04 00 00       	push   0x475
  473f1f:	8b ce                	mov    ecx,esi
  473f21:	e8 aa ba 0b 00       	call   0x52f9d0
  473f26:	6a 00                	push   0x0
  473f28:	6a 00                	push   0x0
  473f2a:	68 10 46 56 00       	push   0x564610
  473f2f:	68 5a 01 00 00       	push   0x15a
  473f34:	68 d9 01 00 00       	push   0x1d9
  473f39:	68 76 04 00 00       	push   0x476
  473f3e:	8b ce                	mov    ecx,esi
  473f40:	e8 6b b6 0b 00       	call   0x52f5b0
  473f45:	6a 00                	push   0x0
  473f47:	6a 00                	push   0x0
  473f49:	68 fc 45 56 00       	push   0x5645fc
  473f4e:	68 5a 01 00 00       	push   0x15a
  473f53:	68 1e 02 00 00       	push   0x21e
  473f58:	68 77 04 00 00       	push   0x477
  473f5d:	8b ce                	mov    ecx,esi
  473f5f:	e8 4c b6 0b 00       	call   0x52f5b0
  473f64:	6a 00                	push   0x0
  473f66:	6a 00                	push   0x0
  473f68:	68 fc 45 56 00       	push   0x5645fc
  473f6d:	68 6d 01 00 00       	push   0x16d
  473f72:	68 1e 02 00 00       	push   0x21e
  473f77:	68 78 04 00 00       	push   0x478
  473f7c:	8b ce                	mov    ecx,esi
  473f7e:	e8 2d b6 0b 00       	call   0x52f5b0
  473f83:	6a 00                	push   0x0
  473f85:	6a 00                	push   0x0
  473f87:	68 10 46 56 00       	push   0x564610
  473f8c:	68 6d 01 00 00       	push   0x16d
  473f91:	68 d9 01 00 00       	push   0x1d9
  473f96:	68 79 04 00 00       	push   0x479
  473f9b:	8b ce                	mov    ecx,esi
  473f9d:	e8 0e b6 0b 00       	call   0x52f5b0
  473fa2:	68 00 74 56 00       	push   0x567400
  473fa7:	68 88 47 56 00       	push   0x564788
  473fac:	68 6f 01 00 00       	push   0x16f
  473fb1:	68 f2 01 00 00       	push   0x1f2
  473fb6:	68 7a 04 00 00       	push   0x47a
  473fbb:	8b ce                	mov    ecx,esi
  473fbd:	e8 8e b8 0b 00       	call   0x52f850
  473fc2:	85 c0                	test   eax,eax
  473fc4:	74 22                	je     0x473fe8
  473fc6:	6a 00                	push   0x0
  473fc8:	68 7a 04 00 00       	push   0x47a
  473fcd:	8b ce                	mov    ecx,esi
  473fcf:	e8 3c b9 0b 00       	call   0x52f910
  473fd4:	6a 00                	push   0x0
  473fd6:	6a 00                	push   0x0
  473fd8:	6a 2d                	push   0x2d
  473fda:	6a 02                	push   0x2
  473fdc:	68 7a 04 00 00       	push   0x47a
  473fe1:	8b ce                	mov    ecx,esi
  473fe3:	e8 e8 b9 0b 00       	call   0x52f9d0
  473fe8:	68 f8 73 56 00       	push   0x5673f8
  473fed:	68 88 47 56 00       	push   0x564788
  473ff2:	68 5b 01 00 00       	push   0x15b
  473ff7:	68 f2 01 00 00       	push   0x1f2
  473ffc:	68 7b 04 00 00       	push   0x47b
  474001:	8b ce                	mov    ecx,esi
  474003:	e8 48 b8 0b 00       	call   0x52f850
  474008:	85 c0                	test   eax,eax
  47400a:	74 22                	je     0x47402e
  47400c:	6a 00                	push   0x0
  47400e:	68 7b 04 00 00       	push   0x47b
  474013:	8b ce                	mov    ecx,esi
  474015:	e8 f6 b8 0b 00       	call   0x52f910
  47401a:	6a 00                	push   0x0
  47401c:	6a 00                	push   0x0
  47401e:	6a 2d                	push   0x2d
  474020:	6a 02                	push   0x2
  474022:	68 7b 04 00 00       	push   0x47b
  474027:	8b ce                	mov    ecx,esi
  474029:	e8 a2 b9 0b 00       	call   0x52f9d0
  47402e:	6a 00                	push   0x0
  474030:	6a 00                	push   0x0
  474032:	68 74 41 56 00       	push   0x564174
  474037:	6a 22                	push   0x22
  474039:	68 5c 02 00 00       	push   0x25c
  47403e:	68 7f 04 00 00       	push   0x47f
  474043:	8b ce                	mov    ecx,esi
  474045:	e8 66 b5 0b 00       	call   0x52f5b0
  47404a:	68 60 41 56 00       	push   0x564160
  47404f:	6a 00                	push   0x0
  474051:	68 98 57 56 00       	push   0x565798
  474056:	68 98 3e 56 00       	push   0x563e98
  47405b:	6a 23                	push   0x23
  47405d:	68 70 02 00 00       	push   0x270
  474062:	68 80 04 00 00       	push   0x480
  474067:	8b ce                	mov    ecx,esi
  474069:	e8 22 b6 0b 00       	call   0x52f690
  47406e:	85 c0                	test   eax,eax
  474070:	74 2b                	je     0x47409d
  474072:	6a 00                	push   0x0
  474074:	6a 00                	push   0x0
  474076:	6a 00                	push   0x0
  474078:	68 80 04 00 00       	push   0x480
  47407d:	8b ce                	mov    ecx,esi
  47407f:	e8 cc b6 0b 00       	call   0x52f750
  474084:	6a fe                	push   0xfffffffe
  474086:	6a 00                	push   0x0
  474088:	6a 00                	push   0x0
  47408a:	68 93 00 00 00       	push   0x93
  47408f:	6a 02                	push   0x2
  474091:	68 80 04 00 00       	push   0x480
  474096:	8b ce                	mov    ecx,esi
  474098:	e8 03 b7 0b 00       	call   0x52f7a0
  47409d:	6a 00                	push   0x0
  47409f:	6a 00                	push   0x0
  4740a1:	68 44 41 56 00       	push   0x564144
  4740a6:	6a 22                	push   0x22
  4740a8:	68 fd 02 00 00       	push   0x2fd
  4740ad:	68 81 04 00 00       	push   0x481
  4740b2:	8b ce                	mov    ecx,esi
  4740b4:	e8 f7 b4 0b 00       	call   0x52f5b0
  4740b9:	6a 00                	push   0x0
  4740bb:	6a 00                	push   0x0
  4740bd:	68 74 41 56 00       	push   0x564174
  4740c2:	68 19 01 00 00       	push   0x119
  4740c7:	68 5c 02 00 00       	push   0x25c
  4740cc:	68 82 04 00 00       	push   0x482
  4740d1:	8b ce                	mov    ecx,esi
  4740d3:	e8 d8 b4 0b 00       	call   0x52f5b0
  4740d8:	68 60 41 56 00       	push   0x564160
  4740dd:	6a 00                	push   0x0
  4740df:	68 e8 73 56 00       	push   0x5673e8
  4740e4:	68 98 3e 56 00       	push   0x563e98
  4740e9:	68 1a 01 00 00       	push   0x11a
  4740ee:	68 70 02 00 00       	push   0x270
  4740f3:	68 83 04 00 00       	push   0x483
  4740f8:	8b ce                	mov    ecx,esi
  4740fa:	e8 91 b5 0b 00       	call   0x52f690
  4740ff:	85 c0                	test   eax,eax
  474101:	74 2b                	je     0x47412e
  474103:	6a 00                	push   0x0
  474105:	6a 00                	push   0x0
  474107:	6a 00                	push   0x0
  474109:	68 83 04 00 00       	push   0x483
  47410e:	8b ce                	mov    ecx,esi
  474110:	e8 3b b6 0b 00       	call   0x52f750
  474115:	6a fe                	push   0xfffffffe
  474117:	6a 00                	push   0x0
  474119:	6a 00                	push   0x0
  47411b:	68 93 00 00 00       	push   0x93
  474120:	6a 02                	push   0x2
  474122:	68 83 04 00 00       	push   0x483
  474127:	8b ce                	mov    ecx,esi
  474129:	e8 72 b6 0b 00       	call   0x52f7a0
  47412e:	6a 00                	push   0x0
  474130:	6a 00                	push   0x0
  474132:	68 44 41 56 00       	push   0x564144
  474137:	68 19 01 00 00       	push   0x119
  47413c:	68 fd 02 00 00       	push   0x2fd
  474141:	68 84 04 00 00       	push   0x484
  474146:	8b ce                	mov    ecx,esi
  474148:	e8 63 b4 0b 00       	call   0x52f5b0
  47414d:	6a 00                	push   0x0
  47414f:	6a 00                	push   0x0
  474151:	68 74 41 56 00       	push   0x564174
  474156:	68 47 01 00 00       	push   0x147
  47415b:	68 5c 02 00 00       	push   0x25c
  474160:	68 85 04 00 00       	push   0x485
  474165:	8b ce                	mov    ecx,esi
  474167:	e8 44 b4 0b 00       	call   0x52f5b0
  47416c:	68 60 41 56 00       	push   0x564160
  474171:	6a 00                	push   0x0
  474173:	68 d8 73 56 00       	push   0x5673d8
  474178:	68 98 3e 56 00       	push   0x563e98
  47417d:	68 48 01 00 00       	push   0x148
  474182:	68 70 02 00 00       	push   0x270
  474187:	68 86 04 00 00       	push   0x486
  47418c:	8b ce                	mov    ecx,esi
  47418e:	e8 fd b4 0b 00       	call   0x52f690
  474193:	85 c0                	test   eax,eax
  474195:	74 2b                	je     0x4741c2
  474197:	6a 00                	push   0x0
  474199:	6a 00                	push   0x0
  47419b:	6a 00                	push   0x0
  47419d:	68 86 04 00 00       	push   0x486
  4741a2:	8b ce                	mov    ecx,esi
  4741a4:	e8 a7 b5 0b 00       	call   0x52f750
  4741a9:	6a fe                	push   0xfffffffe
  4741ab:	6a 00                	push   0x0
  4741ad:	6a 00                	push   0x0
  4741af:	68 93 00 00 00       	push   0x93
  4741b4:	6a 02                	push   0x2
  4741b6:	68 86 04 00 00       	push   0x486
  4741bb:	8b ce                	mov    ecx,esi
  4741bd:	e8 de b5 0b 00       	call   0x52f7a0
  4741c2:	6a 00                	push   0x0
  4741c4:	6a 00                	push   0x0
  4741c6:	68 44 41 56 00       	push   0x564144
  4741cb:	68 47 01 00 00       	push   0x147
  4741d0:	68 fd 02 00 00       	push   0x2fd
  4741d5:	68 87 04 00 00       	push   0x487
  4741da:	8b ce                	mov    ecx,esi
  4741dc:	e8 cf b3 0b 00       	call   0x52f5b0
  4741e1:	6a 00                	push   0x0
  4741e3:	6a 00                	push   0x0
  4741e5:	68 74 41 56 00       	push   0x564174
  4741ea:	68 75 01 00 00       	push   0x175
  4741ef:	68 5c 02 00 00       	push   0x25c
  4741f4:	68 88 04 00 00       	push   0x488
  4741f9:	8b ce                	mov    ecx,esi
  4741fb:	e8 b0 b3 0b 00       	call   0x52f5b0
  474200:	68 60 41 56 00       	push   0x564160
  474205:	6a 00                	push   0x0
  474207:	68 c8 73 56 00       	push   0x5673c8
  47420c:	68 98 3e 56 00       	push   0x563e98
  474211:	68 76 01 00 00       	push   0x176
  474216:	68 70 02 00 00       	push   0x270
  47421b:	68 89 04 00 00       	push   0x489
  474220:	8b ce                	mov    ecx,esi
  474222:	e8 69 b4 0b 00       	call   0x52f690
  474227:	85 c0                	test   eax,eax
  474229:	74 2b                	je     0x474256
  47422b:	6a 00                	push   0x0
  47422d:	6a 00                	push   0x0
  47422f:	6a 00                	push   0x0
  474231:	68 89 04 00 00       	push   0x489
  474236:	8b ce                	mov    ecx,esi
  474238:	e8 13 b5 0b 00       	call   0x52f750
  47423d:	6a fe                	push   0xfffffffe
  47423f:	6a 00                	push   0x0
  474241:	6a 00                	push   0x0
  474243:	68 93 00 00 00       	push   0x93
  474248:	6a 02                	push   0x2
  47424a:	68 89 04 00 00       	push   0x489
  47424f:	8b ce                	mov    ecx,esi
  474251:	e8 4a b5 0b 00       	call   0x52f7a0
  474256:	6a 00                	push   0x0
  474258:	6a 00                	push   0x0
  47425a:	68 44 41 56 00       	push   0x564144
  47425f:	68 75 01 00 00       	push   0x175
  474264:	68 fd 02 00 00       	push   0x2fd
  474269:	68 8a 04 00 00       	push   0x48a
  47426e:	8b ce                	mov    ecx,esi
  474270:	e8 3b b3 0b 00       	call   0x52f5b0
  474275:	8b 15 88 22 58 00    	mov    edx,DWORD PTR ds:0x582288
  47427b:	8b ce                	mov    ecx,esi
  47427d:	52                   	push   edx
  47427e:	68 64 3e 56 00       	push   0x563e64
  474283:	68 05 01 00 00       	push   0x105
  474288:	68 5f 02 00 00       	push   0x25f
  47428d:	68 8b 04 00 00       	push   0x48b
  474292:	e8 b9 b5 0b 00       	call   0x52f850
  474297:	85 c0                	test   eax,eax
  474299:	74 25                	je     0x4742c0
  47429b:	6a 00                	push   0x0
  47429d:	68 8b 04 00 00       	push   0x48b
  4742a2:	8b ce                	mov    ecx,esi
  4742a4:	e8 67 b6 0b 00       	call   0x52f910
  4742a9:	6a 00                	push   0x0
  4742ab:	6a 00                	push   0x0
  4742ad:	68 b4 00 00 00       	push   0xb4
  4742b2:	6a 02                	push   0x2
  4742b4:	68 8b 04 00 00       	push   0x48b
  4742b9:	8b ce                	mov    ecx,esi
  4742bb:	e8 10 b7 0b 00       	call   0x52f9d0
  4742c0:	a1 f8 26 58 00       	mov    eax,ds:0x5826f8
  4742c5:	8b ce                	mov    ecx,esi
  4742c7:	50                   	push   eax
  4742c8:	68 64 3e 56 00       	push   0x563e64
  4742cd:	68 34 01 00 00       	push   0x134
  4742d2:	68 5f 02 00 00       	push   0x25f
  4742d7:	68 8c 04 00 00       	push   0x48c
  4742dc:	e8 6f b5 0b 00       	call   0x52f850
  4742e1:	85 c0                	test   eax,eax
  4742e3:	74 25                	je     0x47430a
  4742e5:	6a 00                	push   0x0
  4742e7:	68 8c 04 00 00       	push   0x48c
  4742ec:	8b ce                	mov    ecx,esi
  4742ee:	e8 1d b6 0b 00       	call   0x52f910
  4742f3:	6a 00                	push   0x0
  4742f5:	6a 00                	push   0x0
  4742f7:	68 b4 00 00 00       	push   0xb4
  4742fc:	6a 02                	push   0x2
  4742fe:	68 8c 04 00 00       	push   0x48c
  474303:	8b ce                	mov    ecx,esi
  474305:	e8 c6 b6 0b 00       	call   0x52f9d0
  47430a:	8b 0d 64 2c 58 00    	mov    ecx,DWORD PTR ds:0x582c64
  474310:	51                   	push   ecx
  474311:	68 64 3e 56 00       	push   0x563e64
  474316:	68 62 01 00 00       	push   0x162
  47431b:	68 5f 02 00 00       	push   0x25f
  474320:	68 8d 04 00 00       	push   0x48d
  474325:	8b ce                	mov    ecx,esi
  474327:	e8 24 b5 0b 00       	call   0x52f850
  47432c:	85 c0                	test   eax,eax
  47432e:	74 25                	je     0x474355
  474330:	6a 00                	push   0x0
  474332:	68 8d 04 00 00       	push   0x48d
  474337:	8b ce                	mov    ecx,esi
  474339:	e8 d2 b5 0b 00       	call   0x52f910
  47433e:	6a 00                	push   0x0
  474340:	6a 00                	push   0x0
  474342:	68 b4 00 00 00       	push   0xb4
  474347:	6a 02                	push   0x2
  474349:	68 8d 04 00 00       	push   0x48d
  47434e:	8b ce                	mov    ecx,esi
  474350:	e8 7b b6 0b 00       	call   0x52f9d0
  474355:	8b 15 e4 0b 58 00    	mov    edx,DWORD PTR ds:0x580be4
  47435b:	8b ce                	mov    ecx,esi
  47435d:	52                   	push   edx
  47435e:	68 98 3e 56 00       	push   0x563e98
  474363:	68 c3 00 00 00       	push   0xc3
  474368:	68 62 02 00 00       	push   0x262
  47436d:	68 8e 04 00 00       	push   0x48e
  474372:	e8 d9 b4 0b 00       	call   0x52f850
  474377:	85 c0                	test   eax,eax
  474379:	74 25                	je     0x4743a0
  47437b:	6a 00                	push   0x0
  47437d:	68 8e 04 00 00       	push   0x48e
  474382:	8b ce                	mov    ecx,esi
  474384:	e8 87 b5 0b 00       	call   0x52f910
  474389:	6a 00                	push   0x0
  47438b:	6a ff                	push   0xffffffff
  47438d:	68 b4 00 00 00       	push   0xb4
  474392:	6a 00                	push   0x0
  474394:	68 8e 04 00 00       	push   0x48e
  474399:	8b ce                	mov    ecx,esi
  47439b:	e8 30 b6 0b 00       	call   0x52f9d0
  4743a0:	68 c4 73 56 00       	push   0x5673c4
  4743a5:	68 c8 3e 56 00       	push   0x563ec8
  4743aa:	68 d1 00 00 00       	push   0xd1
  4743af:	68 62 02 00 00       	push   0x262
  4743b4:	68 8f 04 00 00       	push   0x48f
  4743b9:	8b ce                	mov    ecx,esi
  4743bb:	e8 90 b4 0b 00       	call   0x52f850
  4743c0:	85 c0                	test   eax,eax
  4743c2:	74 22                	je     0x4743e6
  4743c4:	6a 00                	push   0x0
  4743c6:	68 8f 04 00 00       	push   0x48f
  4743cb:	8b ce                	mov    ecx,esi
  4743cd:	e8 3e b5 0b 00       	call   0x52f910
  4743d2:	6a 00                	push   0x0
  4743d4:	6a ff                	push   0xffffffff
  4743d6:	6a 0f                	push   0xf
  4743d8:	6a 00                	push   0x0
  4743da:	68 8f 04 00 00       	push   0x48f
  4743df:	8b ce                	mov    ecx,esi
  4743e1:	e8 ea b5 0b 00       	call   0x52f9d0
  4743e6:	68 44 55 56 00       	push   0x565544
  4743eb:	68 c8 3e 56 00       	push   0x563ec8
  4743f0:	68 dc 00 00 00       	push   0xdc
  4743f5:	68 62 02 00 00       	push   0x262
  4743fa:	68 90 04 00 00       	push   0x490
  4743ff:	8b ce                	mov    ecx,esi
  474401:	e8 4a b4 0b 00       	call   0x52f850
  474406:	85 c0                	test   eax,eax
  474408:	74 22                	je     0x47442c
  47440a:	6a 00                	push   0x0
  47440c:	68 90 04 00 00       	push   0x490
  474411:	8b ce                	mov    ecx,esi
  474413:	e8 f8 b4 0b 00       	call   0x52f910
  474418:	6a 00                	push   0x0
  47441a:	6a ff                	push   0xffffffff
  47441c:	6a 0f                	push   0xf
  47441e:	6a 00                	push   0x0
  474420:	68 90 04 00 00       	push   0x490
  474425:	8b ce                	mov    ecx,esi
  474427:	e8 a4 b5 0b 00       	call   0x52f9d0
  47442c:	68 40 55 56 00       	push   0x565540
  474431:	68 c8 3e 56 00       	push   0x563ec8
  474436:	68 e8 00 00 00       	push   0xe8
  47443b:	68 62 02 00 00       	push   0x262
  474440:	68 91 04 00 00       	push   0x491
  474445:	8b ce                	mov    ecx,esi
  474447:	e8 04 b4 0b 00       	call   0x52f850
  47444c:	85 c0                	test   eax,eax
  47444e:	74 22                	je     0x474472
  474450:	6a 00                	push   0x0
  474452:	68 91 04 00 00       	push   0x491
  474457:	8b ce                	mov    ecx,esi
  474459:	e8 b2 b4 0b 00       	call   0x52f910
  47445e:	6a 00                	push   0x0
  474460:	6a ff                	push   0xffffffff
  474462:	6a 0f                	push   0xf
  474464:	6a 00                	push   0x0
  474466:	68 91 04 00 00       	push   0x491
  47446b:	8b ce                	mov    ecx,esi
  47446d:	e8 5e b5 0b 00       	call   0x52f9d0
  474472:	a1 20 2c 58 00       	mov    eax,ds:0x582c20
  474477:	8b ce                	mov    ecx,esi
  474479:	50                   	push   eax
  47447a:	68 c8 3e 56 00       	push   0x563ec8
  47447f:	68 d1 00 00 00       	push   0xd1
  474484:	68 70 02 00 00       	push   0x270
  474489:	68 92 04 00 00       	push   0x492
  47448e:	e8 bd b3 0b 00       	call   0x52f850
  474493:	85 c0                	test   eax,eax
  474495:	74 22                	je     0x4744b9
  474497:	6a 00                	push   0x0
  474499:	68 92 04 00 00       	push   0x492
  47449e:	8b ce                	mov    ecx,esi
  4744a0:	e8 6b b4 0b 00       	call   0x52f910
  4744a5:	6a 00                	push   0x0
  4744a7:	6a ff                	push   0xffffffff
  4744a9:	6a 64                	push   0x64
  4744ab:	6a 00                	push   0x0
  4744ad:	68 92 04 00 00       	push   0x492
  4744b2:	8b ce                	mov    ecx,esi
  4744b4:	e8 17 b5 0b 00       	call   0x52f9d0
  4744b9:	8b 0d 20 2c 58 00    	mov    ecx,DWORD PTR ds:0x582c20
  4744bf:	51                   	push   ecx
  4744c0:	68 c8 3e 56 00       	push   0x563ec8
  4744c5:	68 dc 00 00 00       	push   0xdc
  4744ca:	68 70 02 00 00       	push   0x270
  4744cf:	68 93 04 00 00       	push   0x493
  4744d4:	8b ce                	mov    ecx,esi
  4744d6:	e8 75 b3 0b 00       	call   0x52f850
  4744db:	85 c0                	test   eax,eax
  4744dd:	74 22                	je     0x474501
  4744df:	6a 00                	push   0x0
  4744e1:	68 93 04 00 00       	push   0x493
  4744e6:	8b ce                	mov    ecx,esi
  4744e8:	e8 23 b4 0b 00       	call   0x52f910
  4744ed:	6a 00                	push   0x0
  4744ef:	6a ff                	push   0xffffffff
  4744f1:	6a 64                	push   0x64
  4744f3:	6a 00                	push   0x0
  4744f5:	68 93 04 00 00       	push   0x493
  4744fa:	8b ce                	mov    ecx,esi
  4744fc:	e8 cf b4 0b 00       	call   0x52f9d0
  474501:	8b 15 20 2c 58 00    	mov    edx,DWORD PTR ds:0x582c20
  474507:	8b ce                	mov    ecx,esi
  474509:	52                   	push   edx
  47450a:	68 c8 3e 56 00       	push   0x563ec8
  47450f:	68 e8 00 00 00       	push   0xe8
  474514:	68 70 02 00 00       	push   0x270
  474519:	68 94 04 00 00       	push   0x494
  47451e:	e8 2d b3 0b 00       	call   0x52f850
  474523:	85 c0                	test   eax,eax
  474525:	74 22                	je     0x474549
  474527:	6a 00                	push   0x0
  474529:	68 94 04 00 00       	push   0x494
  47452e:	8b ce                	mov    ecx,esi
  474530:	e8 db b3 0b 00       	call   0x52f910
  474535:	6a 00                	push   0x0
  474537:	6a ff                	push   0xffffffff
  474539:	6a 64                	push   0x64
  47453b:	6a 00                	push   0x0
  47453d:	68 94 04 00 00       	push   0x494
  474542:	8b ce                	mov    ecx,esi
  474544:	e8 87 b4 0b 00       	call   0x52f9d0
  474549:	68 b8 73 56 00       	push   0x5673b8
  47454e:	68 c8 3e 56 00       	push   0x563ec8
  474553:	68 d1 00 00 00       	push   0xd1
  474558:	68 c5 02 00 00       	push   0x2c5
  47455d:	68 95 04 00 00       	push   0x495
  474562:	8b ce                	mov    ecx,esi
  474564:	e8 e7 b2 0b 00       	call   0x52f850
  474569:	85 c0                	test   eax,eax
  47456b:	74 22                	je     0x47458f
  47456d:	6a 00                	push   0x0
  47456f:	68 95 04 00 00       	push   0x495
  474574:	8b ce                	mov    ecx,esi
  474576:	e8 95 b3 0b 00       	call   0x52f910
  47457b:	6a 00                	push   0x0
  47457d:	6a ff                	push   0xffffffff
  47457f:	6a 50                	push   0x50
  474581:	6a 01                	push   0x1
  474583:	68 95 04 00 00       	push   0x495
  474588:	8b ce                	mov    ecx,esi
  47458a:	e8 41 b4 0b 00       	call   0x52f9d0
  47458f:	68 b8 73 56 00       	push   0x5673b8
  474594:	68 c8 3e 56 00       	push   0x563ec8
  474599:	68 dc 00 00 00       	push   0xdc
  47459e:	68 c5 02 00 00       	push   0x2c5
  4745a3:	68 96 04 00 00       	push   0x496
  4745a8:	8b ce                	mov    ecx,esi
  4745aa:	e8 a1 b2 0b 00       	call   0x52f850
  4745af:	85 c0                	test   eax,eax
  4745b1:	74 22                	je     0x4745d5
  4745b3:	6a 00                	push   0x0
  4745b5:	68 96 04 00 00       	push   0x496
  4745ba:	8b ce                	mov    ecx,esi
  4745bc:	e8 4f b3 0b 00       	call   0x52f910
  4745c1:	6a 00                	push   0x0
  4745c3:	6a ff                	push   0xffffffff
  4745c5:	6a 50                	push   0x50
  4745c7:	6a 01                	push   0x1
  4745c9:	68 96 04 00 00       	push   0x496
  4745ce:	8b ce                	mov    ecx,esi
  4745d0:	e8 fb b3 0b 00       	call   0x52f9d0
  4745d5:	68 b8 73 56 00       	push   0x5673b8
  4745da:	68 c8 3e 56 00       	push   0x563ec8
  4745df:	68 e8 00 00 00       	push   0xe8
  4745e4:	68 c5 02 00 00       	push   0x2c5
  4745e9:	68 97 04 00 00       	push   0x497
  4745ee:	8b ce                	mov    ecx,esi
  4745f0:	e8 5b b2 0b 00       	call   0x52f850
  4745f5:	85 c0                	test   eax,eax
  4745f7:	74 22                	je     0x47461b
  4745f9:	6a 00                	push   0x0
  4745fb:	68 97 04 00 00       	push   0x497
  474600:	8b ce                	mov    ecx,esi
  474602:	e8 09 b3 0b 00       	call   0x52f910
  474607:	6a 00                	push   0x0
  474609:	6a ff                	push   0xffffffff
  47460b:	6a 50                	push   0x50
  47460d:	6a 01                	push   0x1
  47460f:	68 97 04 00 00       	push   0x497
  474614:	8b ce                	mov    ecx,esi
  474616:	e8 b5 b3 0b 00       	call   0x52f9d0
  47461b:	6a 00                	push   0x0
  47461d:	6a 01                	push   0x1
  47461f:	68 c4 42 56 00       	push   0x5642c4
  474624:	68 c5 00 00 00       	push   0xc5
  474629:	6a 19                	push   0x19
  47462b:	68 9f 04 00 00       	push   0x49f
  474630:	8b ce                	mov    ecx,esi
  474632:	e8 79 af 0b 00       	call   0x52f5b0
  474637:	6a 00                	push   0x0
  474639:	6a 01                	push   0x1
  47463b:	68 c4 42 56 00       	push   0x5642c4
  474640:	68 01 01 00 00       	push   0x101
  474645:	6a 19                	push   0x19
  474647:	68 a0 04 00 00       	push   0x4a0
  47464c:	8b ce                	mov    ecx,esi
  47464e:	e8 5d af 0b 00       	call   0x52f5b0
  474653:	6a 00                	push   0x0
  474655:	6a 01                	push   0x1
  474657:	68 c4 42 56 00       	push   0x5642c4
  47465c:	68 3d 01 00 00       	push   0x13d
  474661:	6a 19                	push   0x19
  474663:	68 a1 04 00 00       	push   0x4a1
  474668:	8b ce                	mov    ecx,esi
  47466a:	e8 41 af 0b 00       	call   0x52f5b0
  47466f:	6a 00                	push   0x0
  474671:	6a 01                	push   0x1
  474673:	68 c4 42 56 00       	push   0x5642c4
  474678:	68 79 01 00 00       	push   0x179
  47467d:	6a 19                	push   0x19
  47467f:	68 a2 04 00 00       	push   0x4a2
  474684:	8b ce                	mov    ecx,esi
  474686:	e8 25 af 0b 00       	call   0x52f5b0
  47468b:	6a 00                	push   0x0
  47468d:	6a 01                	push   0x1
  47468f:	68 c4 42 56 00       	push   0x5642c4
  474694:	68 a4 01 00 00       	push   0x1a4
  474699:	6a 19                	push   0x19
  47469b:	68 a3 04 00 00       	push   0x4a3
  4746a0:	8b ce                	mov    ecx,esi
  4746a2:	e8 09 af 0b 00       	call   0x52f5b0
  4746a7:	6a 00                	push   0x0
  4746a9:	6a 01                	push   0x1
  4746ab:	68 c4 42 56 00       	push   0x5642c4
  4746b0:	68 b7 01 00 00       	push   0x1b7
  4746b5:	6a 19                	push   0x19
  4746b7:	68 a4 04 00 00       	push   0x4a4
  4746bc:	8b ce                	mov    ecx,esi
  4746be:	e8 ed ae 0b 00       	call   0x52f5b0
  4746c3:	6a 00                	push   0x0
  4746c5:	6a 01                	push   0x1
  4746c7:	68 c4 42 56 00       	push   0x5642c4
  4746cc:	68 ca 01 00 00       	push   0x1ca
  4746d1:	6a 19                	push   0x19
  4746d3:	68 a5 04 00 00       	push   0x4a5
  4746d8:	8b ce                	mov    ecx,esi
  4746da:	e8 d1 ae 0b 00       	call   0x52f5b0
  4746df:	6a 00                	push   0x0
  4746e1:	6a 01                	push   0x1
  4746e3:	68 c4 42 56 00       	push   0x5642c4
  4746e8:	68 de 01 00 00       	push   0x1de
  4746ed:	6a 19                	push   0x19
  4746ef:	68 a6 04 00 00       	push   0x4a6
  4746f4:	8b ce                	mov    ecx,esi
  4746f6:	e8 b5 ae 0b 00       	call   0x52f5b0
  4746fb:	68 10 43 56 00       	push   0x564310
  474700:	6a 26                	push   0x26
  474702:	6a 35                	push   0x35
  474704:	68 bc 04 00 00       	push   0x4bc
  474709:	8b ce                	mov    ecx,esi
  47470b:	e8 40 d1 0b 00       	call   0x531850
  474710:	68 10 43 56 00       	push   0x564310
  474715:	6a 26                	push   0x26
  474717:	68 26 01 00 00       	push   0x126
  47471c:	68 be 04 00 00       	push   0x4be
  474721:	8b ce                	mov    ecx,esi
  474723:	e8 28 d1 0b 00       	call   0x531850
  474728:	68 10 43 56 00       	push   0x564310
  47472d:	6a 62                	push   0x62
  47472f:	6a 35                	push   0x35
  474731:	68 c0 04 00 00       	push   0x4c0
  474736:	8b ce                	mov    ecx,esi
  474738:	e8 13 d1 0b 00       	call   0x531850
  47473d:	68 10 43 56 00       	push   0x564310
  474742:	6a 62                	push   0x62
  474744:	68 26 01 00 00       	push   0x126
  474749:	68 c2 04 00 00       	push   0x4c2
  47474e:	8b ce                	mov    ecx,esi
  474750:	e8 fb d0 0b 00       	call   0x531850
  474755:	68 10 43 56 00       	push   0x564310
  47475a:	68 9e 00 00 00       	push   0x9e
  47475f:	6a 35                	push   0x35
  474761:	68 c4 04 00 00       	push   0x4c4
  474766:	8b ce                	mov    ecx,esi
  474768:	e8 e3 d0 0b 00       	call   0x531850
  47476d:	68 10 43 56 00       	push   0x564310
  474772:	68 9e 00 00 00       	push   0x9e
  474777:	68 26 01 00 00       	push   0x126
  47477c:	68 c6 04 00 00       	push   0x4c6
  474781:	8b ce                	mov    ecx,esi
  474783:	e8 c8 d0 0b 00       	call   0x531850
  474788:	68 10 43 56 00       	push   0x564310
  47478d:	68 da 00 00 00       	push   0xda
  474792:	6a 35                	push   0x35
  474794:	68 c8 04 00 00       	push   0x4c8
  474799:	8b ce                	mov    ecx,esi
  47479b:	e8 b0 d0 0b 00       	call   0x531850
  4747a0:	68 10 43 56 00       	push   0x564310
  4747a5:	68 da 00 00 00       	push   0xda
  4747aa:	68 26 01 00 00       	push   0x126
  4747af:	68 ca 04 00 00       	push   0x4ca
  4747b4:	8b ce                	mov    ecx,esi
  4747b6:	e8 95 d0 0b 00       	call   0x531850
  4747bb:	68 10 43 56 00       	push   0x564310
  4747c0:	68 16 01 00 00       	push   0x116
  4747c5:	6a 35                	push   0x35
  4747c7:	68 cc 04 00 00       	push   0x4cc
  4747cc:	8b ce                	mov    ecx,esi
  4747ce:	e8 7d d0 0b 00       	call   0x531850
  4747d3:	68 10 43 56 00       	push   0x564310
  4747d8:	68 16 01 00 00       	push   0x116
  4747dd:	68 26 01 00 00       	push   0x126
  4747e2:	68 ce 04 00 00       	push   0x4ce
  4747e7:	8b ce                	mov    ecx,esi
  4747e9:	e8 62 d0 0b 00       	call   0x531850
  4747ee:	68 10 43 56 00       	push   0x564310
  4747f3:	68 52 01 00 00       	push   0x152
  4747f8:	6a 35                	push   0x35
  4747fa:	68 d0 04 00 00       	push   0x4d0
  4747ff:	8b ce                	mov    ecx,esi
  474801:	e8 4a d0 0b 00       	call   0x531850
  474806:	68 10 43 56 00       	push   0x564310
  47480b:	68 52 01 00 00       	push   0x152
  474810:	68 26 01 00 00       	push   0x126
  474815:	68 d2 04 00 00       	push   0x4d2
  47481a:	8b ce                	mov    ecx,esi
  47481c:	e8 2f d0 0b 00       	call   0x531850
  474821:	68 00 43 56 00       	push   0x564300
  474826:	6a 2b                	push   0x2b
  474828:	6a 3a                	push   0x3a
  47482a:	68 d3 04 00 00       	push   0x4d3
  47482f:	8b ce                	mov    ecx,esi
  474831:	e8 1a d0 0b 00       	call   0x531850
  474836:	68 00 43 56 00       	push   0x564300
  47483b:	6a 67                	push   0x67
  47483d:	6a 3a                	push   0x3a
  47483f:	68 d4 04 00 00       	push   0x4d4
  474844:	8b ce                	mov    ecx,esi
  474846:	e8 05 d0 0b 00       	call   0x531850
  47484b:	68 00 43 56 00       	push   0x564300
  474850:	68 df 00 00 00       	push   0xdf
  474855:	6a 3a                	push   0x3a
  474857:	68 d5 04 00 00       	push   0x4d5
  47485c:	8b ce                	mov    ecx,esi
  47485e:	e8 ed cf 0b 00       	call   0x531850
  474863:	68 00 43 56 00       	push   0x564300
  474868:	68 a3 00 00 00       	push   0xa3
  47486d:	6a 3a                	push   0x3a
  47486f:	68 d6 04 00 00       	push   0x4d6
  474874:	8b ce                	mov    ecx,esi
  474876:	e8 d5 cf 0b 00       	call   0x531850
  47487b:	68 00 43 56 00       	push   0x564300
  474880:	68 1b 01 00 00       	push   0x11b
  474885:	6a 3a                	push   0x3a
  474887:	68 d9 04 00 00       	push   0x4d9
  47488c:	8b ce                	mov    ecx,esi
  47488e:	e8 bd cf 0b 00       	call   0x531850
  474893:	68 00 43 56 00       	push   0x564300
  474898:	68 57 01 00 00       	push   0x157
  47489d:	6a 3a                	push   0x3a
  47489f:	68 da 04 00 00       	push   0x4da
  4748a4:	8b ce                	mov    ecx,esi
  4748a6:	e8 a5 cf 0b 00       	call   0x531850
  4748ab:	68 00 43 56 00       	push   0x564300
  4748b0:	6a 2b                	push   0x2b
  4748b2:	68 2b 01 00 00       	push   0x12b
  4748b7:	68 db 04 00 00       	push   0x4db
  4748bc:	8b ce                	mov    ecx,esi
  4748be:	e8 8d cf 0b 00       	call   0x531850
  4748c3:	68 00 43 56 00       	push   0x564300
  4748c8:	6a 67                	push   0x67
  4748ca:	68 2b 01 00 00       	push   0x12b
  4748cf:	68 dc 04 00 00       	push   0x4dc
  4748d4:	8b ce                	mov    ecx,esi
  4748d6:	e8 75 cf 0b 00       	call   0x531850
  4748db:	68 00 43 56 00       	push   0x564300
  4748e0:	68 a3 00 00 00       	push   0xa3
  4748e5:	68 2b 01 00 00       	push   0x12b
  4748ea:	68 dd 04 00 00       	push   0x4dd
  4748ef:	8b ce                	mov    ecx,esi
  4748f1:	e8 5a cf 0b 00       	call   0x531850
  4748f6:	68 00 43 56 00       	push   0x564300
  4748fb:	68 df 00 00 00       	push   0xdf
  474900:	68 2b 01 00 00       	push   0x12b
  474905:	68 de 04 00 00       	push   0x4de
  47490a:	8b ce                	mov    ecx,esi
  47490c:	e8 3f cf 0b 00       	call   0x531850
  474911:	68 00 43 56 00       	push   0x564300
  474916:	68 1b 01 00 00       	push   0x11b
  47491b:	68 2b 01 00 00       	push   0x12b
  474920:	68 df 04 00 00       	push   0x4df
  474925:	8b ce                	mov    ecx,esi
  474927:	e8 24 cf 0b 00       	call   0x531850
  47492c:	68 00 43 56 00       	push   0x564300
  474931:	68 57 01 00 00       	push   0x157
  474936:	68 2b 01 00 00       	push   0x12b
  47493b:	68 e0 04 00 00       	push   0x4e0
  474940:	8b ce                	mov    ecx,esi
  474942:	e8 09 cf 0b 00       	call   0x531850
  474947:	6a 10                	push   0x10
  474949:	6a 7f                	push   0x7f
  47494b:	68 80 00 00 00       	push   0x80
  474950:	6a 3e                	push   0x3e
  474952:	68 79 02 00 00       	push   0x279
  474957:	68 e1 04 00 00       	push   0x4e1
  47495c:	8b ce                	mov    ecx,esi
  47495e:	e8 fd d2 0b 00       	call   0x531c60
  474963:	a1 40 2d 58 00       	mov    eax,ds:0x582d40
  474968:	68 08 72 56 00       	push   0x567208
  47496d:	6a 00                	push   0x0
  47496f:	50                   	push   eax
  474970:	68 a8 3e 56 00       	push   0x563ea8
  474975:	68 fd 01 00 00       	push   0x1fd
  47497a:	68 53 02 00 00       	push   0x253
  47497f:	68 e2 04 00 00       	push   0x4e2
  474984:	8b ce                	mov    ecx,esi
  474986:	e8 05 ad 0b 00       	call   0x52f690
  47498b:	85 c0                	test   eax,eax
  47498d:	74 2b                	je     0x4749ba
  47498f:	6a 00                	push   0x0
  474991:	6a 00                	push   0x0
  474993:	6a 00                	push   0x0
  474995:	68 e2 04 00 00       	push   0x4e2
  47499a:	8b ce                	mov    ecx,esi
  47499c:	e8 af ad 0b 00       	call   0x52f750
  4749a1:	6a 00                	push   0x0
  4749a3:	6a 00                	push   0x0
  4749a5:	6a 00                	push   0x0
  4749a7:	68 cc 00 00 00       	push   0xcc
  4749ac:	6a 02                	push   0x2
  4749ae:	68 e2 04 00 00       	push   0x4e2
  4749b3:	8b ce                	mov    ecx,esi
  4749b5:	e8 e6 ad 0b 00       	call   0x52f7a0
  4749ba:	8b 0d 38 13 58 00    	mov    ecx,DWORD PTR ds:0x581338
  4749c0:	68 ec 71 56 00       	push   0x5671ec
  4749c5:	6a 00                	push   0x0
  4749c7:	51                   	push   ecx
  4749c8:	68 a8 3e 56 00       	push   0x563ea8
  4749cd:	68 26 02 00 00       	push   0x226
  4749d2:	68 53 02 00 00       	push   0x253
  4749d7:	68 e3 04 00 00       	push   0x4e3
  4749dc:	8b ce                	mov    ecx,esi
  4749de:	e8 ad ac 0b 00       	call   0x52f690
  4749e3:	85 c0                	test   eax,eax
  4749e5:	74 2b                	je     0x474a12
  4749e7:	6a 00                	push   0x0
  4749e9:	6a 00                	push   0x0
  4749eb:	6a 00                	push   0x0
  4749ed:	68 e3 04 00 00       	push   0x4e3
  4749f2:	8b ce                	mov    ecx,esi
  4749f4:	e8 57 ad 0b 00       	call   0x52f750
  4749f9:	6a 00                	push   0x0
  4749fb:	6a 00                	push   0x0
  4749fd:	6a 00                	push   0x0
  4749ff:	68 cc 00 00 00       	push   0xcc
  474a04:	6a 02                	push   0x2
  474a06:	68 e3 04 00 00       	push   0x4e3
  474a0b:	8b ce                	mov    ecx,esi
  474a0d:	e8 8e ad 0b 00       	call   0x52f7a0
  474a12:	68 b0 71 56 00       	push   0x5671b0
  474a17:	6a 3d                	push   0x3d
  474a19:	68 79 02 00 00       	push   0x279
  474a1e:	68 e4 04 00 00       	push   0x4e4
  474a23:	8b ce                	mov    ecx,esi
  474a25:	e8 26 ce 0b 00       	call   0x531850
  474a2a:	68 00 73 56 00       	push   0x567300
  474a2f:	6a 2b                	push   0x2b
  474a31:	6a 3a                	push   0x3a
  474a33:	68 e5 04 00 00       	push   0x4e5
  474a38:	8b ce                	mov    ecx,esi
  474a3a:	e8 11 ce 0b 00       	call   0x531850
  474a3f:	68 a4 73 56 00       	push   0x5673a4
  474a44:	6a 2b                	push   0x2b
  474a46:	68 2b 01 00 00       	push   0x12b
  474a4b:	68 e6 04 00 00       	push   0x4e6
  474a50:	8b ce                	mov    ecx,esi
  474a52:	e8 f9 cd 0b 00       	call   0x531850
  474a57:	68 00 73 56 00       	push   0x567300
  474a5c:	6a 67                	push   0x67
  474a5e:	6a 3a                	push   0x3a
  474a60:	68 e7 04 00 00       	push   0x4e7
  474a65:	8b ce                	mov    ecx,esi
  474a67:	e8 e4 cd 0b 00       	call   0x531850
  474a6c:	68 a4 73 56 00       	push   0x5673a4
  474a71:	6a 67                	push   0x67
  474a73:	68 2b 01 00 00       	push   0x12b
  474a78:	68 e8 04 00 00       	push   0x4e8
  474a7d:	8b ce                	mov    ecx,esi
  474a7f:	e8 cc cd 0b 00       	call   0x531850
  474a84:	68 00 73 56 00       	push   0x567300
  474a89:	68 df 00 00 00       	push   0xdf
  474a8e:	6a 3a                	push   0x3a
  474a90:	68 e9 04 00 00       	push   0x4e9
  474a95:	8b ce                	mov    ecx,esi
  474a97:	e8 b4 cd 0b 00       	call   0x531850
  474a9c:	68 a4 73 56 00       	push   0x5673a4
  474aa1:	68 df 00 00 00       	push   0xdf
  474aa6:	68 2b 01 00 00       	push   0x12b
  474aab:	68 ea 04 00 00       	push   0x4ea
  474ab0:	8b ce                	mov    ecx,esi
  474ab2:	e8 99 cd 0b 00       	call   0x531850
  474ab7:	68 00 73 56 00       	push   0x567300
  474abc:	68 a3 00 00 00       	push   0xa3
  474ac1:	6a 3a                	push   0x3a
  474ac3:	68 eb 04 00 00       	push   0x4eb
  474ac8:	8b ce                	mov    ecx,esi
  474aca:	e8 81 cd 0b 00       	call   0x531850
  474acf:	68 a4 73 56 00       	push   0x5673a4
  474ad4:	68 a3 00 00 00       	push   0xa3
  474ad9:	68 2b 01 00 00       	push   0x12b
  474ade:	68 ec 04 00 00       	push   0x4ec
  474ae3:	8b ce                	mov    ecx,esi
  474ae5:	e8 66 cd 0b 00       	call   0x531850
  474aea:	68 00 73 56 00       	push   0x567300
  474aef:	68 1b 01 00 00       	push   0x11b
  474af4:	6a 3a                	push   0x3a
  474af6:	68 ed 04 00 00       	push   0x4ed
  474afb:	8b ce                	mov    ecx,esi
  474afd:	e8 4e cd 0b 00       	call   0x531850
  474b02:	68 a4 73 56 00       	push   0x5673a4
  474b07:	68 1b 01 00 00       	push   0x11b
  474b0c:	68 2b 01 00 00       	push   0x12b
  474b11:	68 ee 04 00 00       	push   0x4ee
  474b16:	8b ce                	mov    ecx,esi
  474b18:	e8 33 cd 0b 00       	call   0x531850
  474b1d:	68 a4 73 56 00       	push   0x5673a4
  474b22:	68 57 01 00 00       	push   0x157
  474b27:	68 2b 01 00 00       	push   0x12b
  474b2c:	68 ef 04 00 00       	push   0x4ef
  474b31:	8b ce                	mov    ecx,esi
  474b33:	e8 18 cd 0b 00       	call   0x531850
  474b38:	68 00 73 56 00       	push   0x567300
  474b3d:	68 57 01 00 00       	push   0x157
  474b42:	6a 3a                	push   0x3a
  474b44:	68 f0 04 00 00       	push   0x4f0
  474b49:	8b ce                	mov    ecx,esi
  474b4b:	e8 00 cd 0b 00       	call   0x531850
  474b50:	68 a0 71 56 00       	push   0x5671a0
  474b55:	6a 36                	push   0x36
  474b57:	68 72 02 00 00       	push   0x272
  474b5c:	68 f1 04 00 00       	push   0x4f1
  474b61:	8b ce                	mov    ecx,esi
  474b63:	e8 e8 cc 0b 00       	call   0x531850
  474b68:	6a 00                	push   0x0
  474b6a:	6a 01                	push   0x1
  474b6c:	68 c4 42 56 00       	push   0x5642c4
  474b71:	68 87 00 00 00       	push   0x87
  474b76:	6a 19                	push   0x19
  474b78:	68 9e 04 00 00       	push   0x49e
  474b7d:	8b ce                	mov    ecx,esi
  474b7f:	e8 2c aa 0b 00       	call   0x52f5b0
  474b84:	8b c6                	mov    eax,esi
  474b86:	5e                   	pop    esi
  474b87:	83 c4 10             	add    esp,0x10
```

## `FreePlaySetup_InitWindow` — `0x4cbcd0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x4cbcd0.c`
- Callers: `GameLoop_DispatchScreens` (0x4052c0)
- Callees: `FUN_005570c0` (0x5570c0), `FreePlaySetup_FillCityTable` (0x4cb6e0), `FreePlaySetup_FillGameLengthText` (0x4cb7e0), `FreePlaySetup_FillHighScoreTable` (0x4cbb10), `FreePlaySetup_FillStartCapitalText` (0x4cb7a0), `FreePlaySetup_RefreshPlayerProfiles` (0x4cb480), `FreePlaySetup_SetDifficultyText` (0x4c7090), `FreePlaySetup_ShowMapPreview` (0x4cb900), `Gadget_SetText` (0x52f830), `IDMap_Lookup` (0x4017f0), `MapList_LoadAllMapDefinitions` (0x4cd960), `NameMap_GetString` (0x4cda30), `String_Format` (0x54dd83), `UI_DisableButton` (0x52ff80), `UI_RemoveObjectByKey` (0x531740), `UI_SetImageFromTemplate` (0x4cb860), `UI_SetPlayerLogoSprite` (0x4cb8b0), `UI_ShowDialogTemplate` (0x4cc230), `Window_GadgetNotify_Button_SetState` (0x52ff50), `Window_GadgetNotify_Slider_SetChangeNotify` (0x52fce0), `Window_GadgetNotify_Slider_SetRange` (0x52fd00), `Window_GadgetNotify_Slider_SetValue` (0x52fd70), `Window_GadgetNotify_Text_SetText` (0x52f9b0)

- Signature: `{'call_site': '0x405480', 'confidence': 'derived from call site', 'recovered': 'void __cdecl FreePlaySetup_InitWindow(void *window)', 'return': 'void'}`
- Dispatch: `call` None -> ['0x4cd960'], `call` None -> ['0x4017f0'], `call` None -> ['0x5570c0']
- Unresolved questions: The full control table and all map/opponent UI states are not part of this batch; only the data paths that feed world creation are annotated.

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

004cbcd0 <.text+0xcacd0>:
  4cbcd0:	83 ec 24             	sub    esp,0x24
  4cbcd3:	53                   	push   ebx
  4cbcd4:	55                   	push   ebp
  4cbcd5:	8b 6c 24 30          	mov    ebp,DWORD PTR [esp+0x30]
  4cbcd9:	56                   	push   esi
  4cbcda:	57                   	push   edi
  4cbcdb:	55                   	push   ebp
  4cbcdc:	e8 4f 05 00 00       	call   0x4cc230
  4cbce1:	a1 4c 2e 58 00       	mov    eax,ds:0x582e4c
  4cbce6:	83 c4 04             	add    esp,0x4
  4cbce9:	8b cd                	mov    ecx,ebp
  4cbceb:	50                   	push   eax
  4cbcec:	68 29 04 00 00       	push   0x429
  4cbcf1:	e8 ba 3c 06 00       	call   0x52f9b0
  4cbcf6:	68 4d 04 00 00       	push   0x44d
  4cbcfb:	8b cd                	mov    ecx,ebp
  4cbcfd:	89 2d 60 de 57 00    	mov    DWORD PTR ds:0x57de60,ebp
  4cbd03:	e8 38 5a 06 00       	call   0x531740
  4cbd08:	68 51 04 00 00       	push   0x451
  4cbd0d:	8b cd                	mov    ecx,ebp
  4cbd0f:	e8 2c 5a 06 00       	call   0x531740
  4cbd14:	68 50 04 00 00       	push   0x450
  4cbd19:	8b cd                	mov    ecx,ebp
  4cbd1b:	e8 20 5a 06 00       	call   0x531740
  4cbd20:	68 52 04 00 00       	push   0x452
  4cbd25:	8b cd                	mov    ecx,ebp
  4cbd27:	e8 14 5a 06 00       	call   0x531740
  4cbd2c:	be 4f 04 00 00       	mov    esi,0x44f
  4cbd31:	8d 4e ff             	lea    ecx,[esi-0x1]
  4cbd34:	51                   	push   ecx
  4cbd35:	8b cd                	mov    ecx,ebp
  4cbd37:	e8 44 42 06 00       	call   0x52ff80
  4cbd3c:	56                   	push   esi
  4cbd3d:	8b cd                	mov    ecx,ebp
  4cbd3f:	e8 3c 42 06 00       	call   0x52ff80
  4cbd44:	83 c6 08             	add    esi,0x8
  4cbd47:	81 fe 7f 04 00 00    	cmp    esi,0x47f
  4cbd4d:	7c e2                	jl     0x4cbd31
  4cbd4f:	68 58 bc 57 00       	push   0x57bc58
  4cbd54:	68 3f 04 00 00       	push   0x43f
  4cbd59:	8b cd                	mov    ecx,ebp
  4cbd5b:	e8 50 3c 06 00       	call   0x52f9b0
  4cbd60:	68 98 bc 57 00       	push   0x57bc98
  4cbd65:	68 40 04 00 00       	push   0x440
  4cbd6a:	8b cd                	mov    ecx,ebp
  4cbd6c:	e8 3f 3c 06 00       	call   0x52f9b0
  4cbd71:	68 e5 04 00 00       	push   0x4e5
  4cbd76:	b9 30 00 00 00       	mov    ecx,0x30
  4cbd7b:	81 ec c0 00 00 00    	sub    esp,0xc0
  4cbd81:	be 58 bc 57 00       	mov    esi,0x57bc58
  4cbd86:	8b fc                	mov    edi,esp
  4cbd88:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  4cbd8a:	55                   	push   ebp
  4cbd8b:	e8 d0 fa ff ff       	call   0x4cb860
  4cbd90:	8b 15 10 bd 57 00    	mov    edx,DWORD PTR ds:0x57bd10
  4cbd96:	a1 0c bd 57 00       	mov    eax,ds:0x57bd0c
  4cbd9b:	68 e6 04 00 00       	push   0x4e6
  4cbda0:	52                   	push   edx
  4cbda1:	50                   	push   eax
  4cbda2:	55                   	push   ebp
  4cbda3:	e8 08 fb ff ff       	call   0x4cb8b0
  4cbda8:	81 c4 d8 00 00 00    	add    esp,0xd8
  4cbdae:	68 38 de 57 00       	push   0x57de38
  4cbdb3:	e8 a8 1b 00 00       	call   0x4cd960
  4cbdb8:	8b 3d 64 b9 57 00    	mov    edi,DWORD PTR ds:0x57b964
  4cbdbe:	8b 35 68 b9 57 00    	mov    esi,DWORD PTR ds:0x57b968
  4cbdc4:	b8 01 00 00 00       	mov    eax,0x1
  4cbdc9:	83 c4 04             	add    esp,0x4
  4cbdcc:	3b f8                	cmp    edi,eax
  4cbdce:	0f 94 c1             	sete   cl
  4cbdd1:	3b f0                	cmp    esi,eax
  4cbdd3:	88 0d 3e bb 57 00    	mov    BYTE PTR ds:0x57bb3e,cl
  4cbdd9:	0f 94 c2             	sete   dl
  4cbddc:	88 15 3d bb 57 00    	mov    BYTE PTR ds:0x57bb3d,dl
  4cbde2:	8b 15 6c b9 57 00    	mov    edx,DWORD PTR ds:0x57b96c
  4cbde8:	3b d0                	cmp    edx,eax
  4cbdea:	0f 94 c1             	sete   cl
  4cbded:	88 0d 34 bb 57 00    	mov    BYTE PTR ds:0x57bb34,cl
  4cbdf3:	8b 0d 70 b9 57 00    	mov    ecx,DWORD PTR ds:0x57b970
  4cbdf9:	3b c8                	cmp    ecx,eax
  4cbdfb:	a1 74 b9 57 00       	mov    eax,ds:0x57b974
  4cbe00:	8b 0d 78 b9 57 00    	mov    ecx,DWORD PTR ds:0x57b978
  4cbe06:	a3 30 bb 57 00       	mov    ds:0x57bb30,eax
  4cbe0b:	a1 cc b9 57 00       	mov    eax,ds:0x57b9cc
  4cbe10:	89 0d 38 bb 57 00    	mov    DWORD PTR ds:0x57bb38,ecx
  4cbe16:	8b 0d b4 b8 57 00    	mov    ecx,DWORD PTR ds:0x57b8b4
  4cbe1c:	a3 2c bb 57 00       	mov    ds:0x57bb2c,eax
  4cbe21:	a1 d4 b9 57 00       	mov    eax,ds:0x57b9d4
  4cbe26:	89 0d 24 bb 57 00    	mov    DWORD PTR ds:0x57bb24,ecx
  4cbe2c:	8b 0d d8 b9 57 00    	mov    ecx,DWORD PTR ds:0x57b9d8
  4cbe32:	a3 4c bb 57 00       	mov    ds:0x57bb4c,eax
  4cbe37:	a1 4c de 57 00       	mov    eax,ds:0x57de4c
  4cbe3c:	89 0d 50 bb 57 00    	mov    DWORD PTR ds:0x57bb50,ecx
  4cbe42:	0f 94 c2             	sete   dl
  4cbe45:	88 15 3c bb 57 00    	mov    BYTE PTR ds:0x57bb3c,dl
  4cbe4b:	8b 15 c8 b9 57 00    	mov    edx,DWORD PTR ds:0x57b9c8
  4cbe51:	89 15 28 bb 57 00    	mov    DWORD PTR ds:0x57bb28,edx
  4cbe57:	8b 15 d0 b9 57 00    	mov    edx,DWORD PTR ds:0x57b9d0
  4cbe5d:	33 ff                	xor    edi,edi
  4cbe5f:	33 f6                	xor    esi,esi
  4cbe61:	3b c7                	cmp    eax,edi
  4cbe63:	89 15 48 bb 57 00    	mov    DWORD PTR ds:0x57bb48,edx
  4cbe69:	89 3d 40 bb 57 00    	mov    DWORD PTR ds:0x57bb40,edi
  4cbe6f:	7e 33                	jle    0x4cbea4
  4cbe71:	57                   	push   edi
  4cbe72:	56                   	push   esi
  4cbe73:	b9 38 de 57 00       	mov    ecx,0x57de38
  4cbe78:	e8 73 59 f3 ff       	call   0x4017f0
  4cbe7d:	83 c0 40             	add    eax,0x40
  4cbe80:	68 c4 b9 57 00       	push   0x57b9c4
  4cbe85:	50                   	push   eax
  4cbe86:	e8 35 b2 08 00       	call   0x5570c0
  4cbe8b:	83 c4 08             	add    esp,0x8
  4cbe8e:	85 c0                	test   eax,eax
  4cbe90:	74 0c                	je     0x4cbe9e
  4cbe92:	a1 4c de 57 00       	mov    eax,ds:0x57de4c
  4cbe97:	46                   	inc    esi
  4cbe98:	3b f0                	cmp    esi,eax
  4cbe9a:	7c d5                	jl     0x4cbe71
  4cbe9c:	eb 06                	jmp    0x4cbea4
  4cbe9e:	89 35 40 bb 57 00    	mov    DWORD PTR ds:0x57bb40,esi
  4cbea4:	55                   	push   ebp
  4cbea5:	e8 66 fc ff ff       	call   0x4cbb10
  4cbeaa:	83 c4 04             	add    esp,0x4
  4cbead:	b9 dc bc 57 00       	mov    ecx,0x57bcdc
  4cbeb2:	b8 94 b9 57 00       	mov    eax,0x57b994
  4cbeb7:	8b 50 e8             	mov    edx,DWORD PTR [eax-0x18]
  4cbeba:	83 c0 04             	add    eax,0x4
  4cbebd:	89 51 fc             	mov    DWORD PTR [ecx-0x4],edx
  4cbec0:	8b 50 fc             	mov    edx,DWORD PTR [eax-0x4]
  4cbec3:	89 11                	mov    DWORD PTR [ecx],edx
  4cbec5:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4cbec8:	89 51 38             	mov    DWORD PTR [ecx+0x38],edx
  4cbecb:	81 c1 c0 00 00 00    	add    ecx,0xc0
  4cbed1:	3d ac b9 57 00       	cmp    eax,0x57b9ac
  4cbed6:	7c df                	jl     0x4cbeb7
  4cbed8:	33 c9                	xor    ecx,ecx
  4cbeda:	b8 4c b9 57 00       	mov    eax,0x57b94c
  4cbedf:	8b 18                	mov    ebx,DWORD PTR [eax]
  4cbee1:	83 c0 04             	add    eax,0x4
  4cbee4:	2b cb                	sub    ecx,ebx
  4cbee6:	3d 64 b9 57 00       	cmp    eax,0x57b964
  4cbeeb:	7c f2                	jl     0x4cbedf
  4cbeed:	89 0d dc bc 57 00    	mov    DWORD PTR ds:0x57bcdc,ecx
  4cbef3:	b8 cc bd 57 00       	mov    eax,0x57bdcc
  4cbef8:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  4cbefb:	8b 15 10 bd 57 00    	mov    edx,DWORD PTR ds:0x57bd10
  4cbf01:	3b ca                	cmp    ecx,edx
  4cbf03:	75 09                	jne    0x4cbf0e
  4cbf05:	8b 15 70 c2 57 00    	mov    edx,DWORD PTR ds:0x57c270
  4cbf0b:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  4cbf0e:	8b 08                	mov    ecx,DWORD PTR [eax]
  4cbf10:	8b 15 0c bd 57 00    	mov    edx,DWORD PTR ds:0x57bd0c
  4cbf16:	3b ca                	cmp    ecx,edx
  4cbf18:	75 08                	jne    0x4cbf22
  4cbf1a:	8b 15 80 b7 57 00    	mov    edx,DWORD PTR ds:0x57b780
  4cbf20:	89 10                	mov    DWORD PTR [eax],edx
  4cbf22:	05 c0 00 00 00       	add    eax,0xc0
  4cbf27:	3d 8c c1 57 00       	cmp    eax,0x57c18c
  4cbf2c:	7c ca                	jl     0x4cbef8
  4cbf2e:	be 42 04 00 00       	mov    esi,0x442
  4cbf33:	bb 18 bd 57 00       	mov    ebx,0x57bd18
  4cbf38:	89 74 24 38          	mov    DWORD PTR [esp+0x38],esi
  4cbf3c:	89 7c 24 10          	mov    DWORD PTR [esp+0x10],edi
  4cbf40:	eb 04                	jmp    0x4cbf46
  4cbf42:	8b 74 24 38          	mov    esi,DWORD PTR [esp+0x38]
  4cbf46:	8d 46 ff             	lea    eax,[esi-0x1]
  4cbf49:	53                   	push   ebx
  4cbf4a:	50                   	push   eax
  4cbf4b:	8b cd                	mov    ecx,ebp
  4cbf4d:	e8 5e 3a 06 00       	call   0x52f9b0
  4cbf52:	8d 4b 40             	lea    ecx,[ebx+0x40]
  4cbf55:	51                   	push   ecx
  4cbf56:	56                   	push   esi
  4cbf57:	8b cd                	mov    ecx,ebp
  4cbf59:	e8 52 3a 06 00       	call   0x52f9b0
  4cbf5e:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  4cbf62:	b9 30 00 00 00       	mov    ecx,0x30
  4cbf67:	8b f3                	mov    esi,ebx
  4cbf69:	8b 82 b0 b2 56 00    	mov    eax,DWORD PTR [edx+0x56b2b0]
  4cbf6f:	50                   	push   eax
  4cbf70:	81 ec c0 00 00 00    	sub    esp,0xc0
  4cbf76:	8b fc                	mov    edi,esp
  4cbf78:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  4cbf7a:	55                   	push   ebp
  4cbf7b:	e8 e0 f8 ff ff       	call   0x4cb860
  4cbf80:	8b b4 24 d8 00 00 00 	mov    esi,DWORD PTR [esp+0xd8]
  4cbf87:	8b 93 b8 00 00 00    	mov    edx,DWORD PTR [ebx+0xb8]
  4cbf8d:	8b 83 b4 00 00 00    	mov    eax,DWORD PTR [ebx+0xb4]
  4cbf93:	8b 8e c8 b2 56 00    	mov    ecx,DWORD PTR [esi+0x56b2c8]
  4cbf99:	51                   	push   ecx
  4cbf9a:	52                   	push   edx
  4cbf9b:	50                   	push   eax
  4cbf9c:	55                   	push   ebp
  4cbf9d:	e8 0e f9 ff ff       	call   0x4cb8b0
  4cbfa2:	8b 84 24 10 01 00 00 	mov    eax,DWORD PTR [esp+0x110]
  4cbfa9:	81 c4 d8 00 00 00    	add    esp,0xd8
  4cbfaf:	83 c0 02             	add    eax,0x2
  4cbfb2:	83 c6 04             	add    esi,0x4
  4cbfb5:	81 c3 c0 00 00 00    	add    ebx,0xc0
  4cbfbb:	3d 4c 04 00 00       	cmp    eax,0x44c
  4cbfc0:	89 44 24 38          	mov    DWORD PTR [esp+0x38],eax
  4cbfc4:	89 74 24 10          	mov    DWORD PTR [esp+0x10],esi
  4cbfc8:	0f 8c 74 ff ff ff    	jl     0x4cbf42
  4cbfce:	bf 9e 04 00 00       	mov    edi,0x49e
  4cbfd3:	be d4 bd 57 00       	mov    esi,0x57bdd4
  4cbfd8:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4cbfda:	51                   	push   ecx
  4cbfdb:	57                   	push   edi
  4cbfdc:	8b cd                	mov    ecx,ebp
  4cbfde:	e8 6d 3f 06 00       	call   0x52ff50
  4cbfe3:	81 c6 c0 00 00 00    	add    esi,0xc0
  4cbfe9:	47                   	inc    edi
  4cbfea:	81 fe 94 c1 57 00    	cmp    esi,0x57c194
  4cbff0:	7c e6                	jl     0x4cbfd8
  4cbff2:	55                   	push   ebp
  4cbff3:	e8 88 f4 ff ff       	call   0x4cb480
  4cbff8:	8a 1d 3e bb 57 00    	mov    bl,BYTE PTR ds:0x57bb3e
  4cbffe:	83 c4 04             	add    esp,0x4
  4cc001:	33 d2                	xor    edx,edx
  4cc003:	80 fb 01             	cmp    bl,0x1
  4cc006:	0f 94 c2             	sete   dl
  4cc009:	52                   	push   edx
  4cc00a:	68 a3 04 00 00       	push   0x4a3
  4cc00f:	8b cd                	mov    ecx,ebp
  4cc011:	e8 3a 3f 06 00       	call   0x52ff50
  4cc016:	8a 15 3d bb 57 00    	mov    dl,BYTE PTR ds:0x57bb3d
  4cc01c:	33 c0                	xor    eax,eax
  4cc01e:	80 fa 01             	cmp    dl,0x1
  4cc021:	8b cd                	mov    ecx,ebp
  4cc023:	0f 94 c0             	sete   al
  4cc026:	50                   	push   eax
  4cc027:	68 a4 04 00 00       	push   0x4a4
  4cc02c:	e8 1f 3f 06 00       	call   0x52ff50
  4cc031:	8a 1d 34 bb 57 00    	mov    bl,BYTE PTR ds:0x57bb34
  4cc037:	33 c9                	xor    ecx,ecx
  4cc039:	80 fb 01             	cmp    bl,0x1
  4cc03c:	0f 94 c1             	sete   cl
  4cc03f:	51                   	push   ecx
  4cc040:	68 a5 04 00 00       	push   0x4a5
  4cc045:	8b cd                	mov    ecx,ebp
  4cc047:	e8 04 3f 06 00       	call   0x52ff50
  4cc04c:	8a 1d 3c bb 57 00    	mov    bl,BYTE PTR ds:0x57bb3c
  4cc052:	33 d2                	xor    edx,edx
  4cc054:	80 fb 01             	cmp    bl,0x1
  4cc057:	8b cd                	mov    ecx,ebp
  4cc059:	0f 94 c2             	sete   dl
  4cc05c:	52                   	push   edx
  4cc05d:	68 a6 04 00 00       	push   0x4a6
  4cc062:	e8 e9 3e 06 00       	call   0x52ff50
  4cc067:	a1 30 bb 57 00       	mov    eax,ds:0x57bb30
  4cc06c:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  4cc070:	50                   	push   eax
  4cc071:	68 f4 86 56 00       	push   0x5686f4
  4cc076:	51                   	push   ecx
  4cc077:	e8 07 1d 08 00       	call   0x54dd83
  4cc07c:	83 c4 0c             	add    esp,0xc
  4cc07f:	8d 54 24 14          	lea    edx,[esp+0x14]
  4cc083:	8b cd                	mov    ecx,ebp
  4cc085:	52                   	push   edx
  4cc086:	68 3e 04 00 00       	push   0x43e
  4cc08b:	e8 20 39 06 00       	call   0x52f9b0
  4cc090:	a1 38 bb 57 00       	mov    eax,ds:0x57bb38
  4cc095:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  4cc099:	50                   	push   eax
  4cc09a:	68 f4 86 56 00       	push   0x5686f4
  4cc09f:	51                   	push   ecx
  4cc0a0:	e8 de 1c 08 00       	call   0x54dd83
  4cc0a5:	83 c4 0c             	add    esp,0xc
  4cc0a8:	8d 54 24 14          	lea    edx,[esp+0x14]
  4cc0ac:	8b cd                	mov    ecx,ebp
  4cc0ae:	52                   	push   edx
  4cc0af:	68 3d 04 00 00       	push   0x43d
  4cc0b4:	e8 f7 38 06 00       	call   0x52f9b0
  4cc0b9:	6a 00                	push   0x0
  4cc0bb:	68 f4 01 00 00       	push   0x1f4
  4cc0c0:	6a 64                	push   0x64
  4cc0c2:	68 37 04 00 00       	push   0x437
  4cc0c7:	8b cd                	mov    ecx,ebp
  4cc0c9:	e8 32 3c 06 00       	call   0x52fd00
  4cc0ce:	a1 28 bb 57 00       	mov    eax,ds:0x57bb28
  4cc0d3:	6a 00                	push   0x0
  4cc0d5:	50                   	push   eax
  4cc0d6:	68 37 04 00 00       	push   0x437
  4cc0db:	8b cd                	mov    ecx,ebp
  4cc0dd:	e8 8e 3c 06 00       	call   0x52fd70
  4cc0e2:	6a 01                	push   0x1
  4cc0e4:	68 37 04 00 00       	push   0x437
  4cc0e9:	8b cd                	mov    ecx,ebp
  4cc0eb:	e8 f0 3b 06 00       	call   0x52fce0
  4cc0f0:	6a 00                	push   0x0
  4cc0f2:	6a 6e                	push   0x6e
  4cc0f4:	6a 0a                	push   0xa
  4cc0f6:	68 34 04 00 00       	push   0x434
  4cc0fb:	8b cd                	mov    ecx,ebp
  4cc0fd:	e8 fe 3b 06 00       	call   0x52fd00
  4cc102:	a1 2c bb 57 00       	mov    eax,ds:0x57bb2c
  4cc107:	6a 00                	push   0x0
  4cc109:	8d 0c 80             	lea    ecx,[eax+eax*4]
  4cc10c:	d1 e1                	shl    ecx,1
  4cc10e:	51                   	push   ecx
  4cc10f:	68 34 04 00 00       	push   0x434
  4cc114:	8b cd                	mov    ecx,ebp
  4cc116:	e8 55 3c 06 00       	call   0x52fd70
  4cc11b:	6a 01                	push   0x1
  4cc11d:	68 34 04 00 00       	push   0x434
  4cc122:	8b cd                	mov    ecx,ebp
  4cc124:	e8 b7 3b 06 00       	call   0x52fce0
  4cc129:	6a 00                	push   0x0
  4cc12b:	6a 0a                	push   0xa
  4cc12d:	6a 00                	push   0x0
  4cc12f:	68 07 04 00 00       	push   0x407
  4cc134:	8b cd                	mov    ecx,ebp
  4cc136:	e8 c5 3b 06 00       	call   0x52fd00
  4cc13b:	8b 15 24 bb 57 00    	mov    edx,DWORD PTR ds:0x57bb24
  4cc141:	6a 00                	push   0x0
  4cc143:	52                   	push   edx
  4cc144:	68 07 04 00 00       	push   0x407
  4cc149:	8b cd                	mov    ecx,ebp
  4cc14b:	e8 20 3c 06 00       	call   0x52fd70
  4cc150:	6a 01                	push   0x1
  4cc152:	68 07 04 00 00       	push   0x407
  4cc157:	8b cd                	mov    ecx,ebp
  4cc159:	e8 82 3b 06 00       	call   0x52fce0
  4cc15e:	a1 40 bb 57 00       	mov    eax,ds:0x57bb40
  4cc163:	50                   	push   eax
  4cc164:	68 38 de 57 00       	push   0x57de38
  4cc169:	e8 c2 18 00 00       	call   0x4cda30
  4cc16e:	83 c4 08             	add    esp,0x8
  4cc171:	8b cd                	mov    ecx,ebp
  4cc173:	50                   	push   eax
  4cc174:	68 80 04 00 00       	push   0x480
  4cc179:	e8 b2 36 06 00       	call   0x52f830
  4cc17e:	a1 48 bb 57 00       	mov    eax,ds:0x57bb48
  4cc183:	83 f8 ff             	cmp    eax,0xffffffff
  4cc186:	7e 0a                	jle    0x4cc192
  4cc188:	8b 0c 85 9c 36 58 00 	mov    ecx,DWORD PTR [eax*4+0x58369c]
  4cc18f:	51                   	push   ecx
  4cc190:	eb 07                	jmp    0x4cc199
  4cc192:	8b 15 98 2a 58 00    	mov    edx,DWORD PTR ds:0x582a98
  4cc198:	52                   	push   edx
  4cc199:	68 83 04 00 00       	push   0x483
  4cc19e:	8b cd                	mov    ecx,ebp
  4cc1a0:	e8 8b 36 06 00       	call   0x52f830
  4cc1a5:	a1 4c bb 57 00       	mov    eax,ds:0x57bb4c
  4cc1aa:	83 f8 ff             	cmp    eax,0xffffffff
  4cc1ad:	7e 0a                	jle    0x4cc1b9
  4cc1af:	8b 04 85 9c 36 58 00 	mov    eax,DWORD PTR [eax*4+0x58369c]
  4cc1b6:	50                   	push   eax
  4cc1b7:	eb 07                	jmp    0x4cc1c0
  4cc1b9:	8b 0d 98 2a 58 00    	mov    ecx,DWORD PTR ds:0x582a98
  4cc1bf:	51                   	push   ecx
  4cc1c0:	68 86 04 00 00       	push   0x486
  4cc1c5:	8b cd                	mov    ecx,ebp
  4cc1c7:	e8 64 36 06 00       	call   0x52f830
  4cc1cc:	a1 50 bb 57 00       	mov    eax,ds:0x57bb50
  4cc1d1:	83 f8 ff             	cmp    eax,0xffffffff
  4cc1d4:	7e 0a                	jle    0x4cc1e0
  4cc1d6:	8b 14 85 9c 36 58 00 	mov    edx,DWORD PTR [eax*4+0x58369c]
  4cc1dd:	52                   	push   edx
  4cc1de:	eb 06                	jmp    0x4cc1e6
  4cc1e0:	a1 98 2a 58 00       	mov    eax,ds:0x582a98
  4cc1e5:	50                   	push   eax
  4cc1e6:	68 89 04 00 00       	push   0x489
  4cc1eb:	8b cd                	mov    ecx,ebp
  4cc1ed:	e8 3e 36 06 00       	call   0x52f830
  4cc1f2:	55                   	push   ebp
  4cc1f3:	e8 e8 f4 ff ff       	call   0x4cb6e0
  4cc1f8:	55                   	push   ebp
  4cc1f9:	e8 a2 f5 ff ff       	call   0x4cb7a0
  4cc1fe:	55                   	push   ebp
  4cc1ff:	e8 dc f5 ff ff       	call   0x4cb7e0
  4cc204:	8b 0d 24 bb 57 00    	mov    ecx,DWORD PTR ds:0x57bb24
  4cc20a:	51                   	push   ecx
  4cc20b:	55                   	push   ebp
  4cc20c:	e8 7f ae ff ff       	call   0x4c7090
  4cc211:	55                   	push   ebp
  4cc212:	e8 e9 f6 ff ff       	call   0x4cb900
  4cc217:	83 c4 18             	add    esp,0x18
  4cc21a:	5f                   	pop    edi
  4cc21b:	5e                   	pop    esi
  4cc21c:	5d                   	pop    ebp
  4cc21d:	5b                   	pop    ebx
  4cc21e:	83 c4 24             	add    esp,0x24
```

## `FreePlaySetup_ControlCallback` — `0x4cc640`

- Body: `curated`
- Callers: none in the named export
- Callees: none resolved

- Signature: `{'call_site': '0x472daa callback registration; control id at [esp+0x44], value at [esp+0x4c]', 'confidence': 'derived from register/stack use', 'recovered': 'int __cdecl FreePlaySetup_ControlCallback(void *window, unsigned message, int control_id, int value)', 'return': 'callback return consumed by UI dispatcher'}`
- Dispatch: `control_table` None -> {'0x4e2': '0x4cd2b9', '0x4e3': '0x4cd33d'}, `screen_state` None -> ['GameLoop_DispatchScreens case 0x17 at 0x40542e'], `screen_state` None -> ['GameLoop_DispatchScreens case 0x15 at 0x4053aa']
- Unresolved questions: The complete 0x3fa..0x4e3 control jump table is not annotated; only Back (0x4e2) and Start (0x4e3) are in this batch.; Virtual cleanup calls at 0x4cd376/0x4cd38b have unresolved targets.

## `GameLoop_DispatchScreens` — `0x4052c0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x4052c0.c`
- Callers: `GameMain` (0x4043e0)
- Callees: `CharacterSelect_UpdateScreen` (0x4c7110), `FreePlaySetup_InitWindow` (0x4cbcd0), `Game_GenerateRandomPlayers` (0x4050e0), `Game_RunSession` (0x404af0), `Game_ShutdownSubsystems` (0x4055d0), `List_Add` (0x4014b0), `NoOp_Stub` (0x48e0a0), `Resource_Close` (0x402990), `Resource_Open` (0x402290), `Resource_ReadLine` (0x402840), `Screen_CharacterSelect` (0x46dbd0), `Screen_CloseSubStartMenu` (0x4052a0), `Screen_FreePlaySetup` (0x472da0), `Screen_MainMenu` (0x476920), `Screen_MissionBriefing` (0x474df0), `Screen_MissionBriefing_Populate` (0x4cdac0), `Screen_SubStartMenu_A` (0x4750b0), `Screen_SubStartMenu_B` (0x46e960), `String_Format` (0x54dd83), `SubStartMenuA_InitSaveGamePage` (0x4cded0), `SubStartMenu_FillOptions` (0x4c7d80), `Window_DestroyChild` (0x526700), `Window_ProcessMessageQueue` (0x525a10), `Window_ShowWindowById` (0x523d60)

- Signature: `{'confidence': 'derived from internal dispatch', 'note': 'Provider signature has many stack parameters; this batch uses the observed internal state machine: DAT_0056386c selects the screen, no explicit arguments are forwarded to Game_RunSession.', 'recovered': 'void __cdecl GameLoop_DispatchScreens(void)'}`
- Dispatch: `screen_state_table` None -> {'0x15': '0x4053aa', '0x16': '0x405407', '0x17': '0x40542e', '0x18': '0x405463', '0x19': '0x40548f', '0x1a': '0x4054ba', '0x1b': '0x4054e4', '0x1c': '0x4053d8', '0x1d': '0x40552c'}, `call` None -> ['0x404af0']
- Unresolved questions: Other screen cases are enumerated by table target but not semantically annotated in this batch.

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

004052c0 <.text+0x42c0>:
  4052c0:	8b 0d d8 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5d8
  4052c6:	81 ec 04 01 00 00    	sub    esp,0x104
  4052cc:	53                   	push   ebx
  4052cd:	55                   	push   ebp
  4052ce:	33 db                	xor    ebx,ebx
  4052d0:	56                   	push   esi
  4052d1:	53                   	push   ebx
  4052d2:	68 d8 3b 56 00       	push   0x563bd8
  4052d7:	33 f6                	xor    esi,esi
  4052d9:	e8 b2 cf ff ff       	call   0x402290
  4052de:	8b e8                	mov    ebp,eax
  4052e0:	3b eb                	cmp    ebp,ebx
  4052e2:	75 0d                	jne    0x4052f1
  4052e4:	68 b8 3b 56 00       	push   0x563bb8
  4052e9:	e8 b2 8d 08 00       	call   0x48e0a0
  4052ee:	83 c4 04             	add    esp,0x4
  4052f1:	8b 0d d8 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5d8
  4052f7:	57                   	push   edi
  4052f8:	55                   	push   ebp
  4052f9:	8d 44 24 18          	lea    eax,[esp+0x18]
  4052fd:	68 00 01 00 00       	push   0x100
  405302:	50                   	push   eax
  405303:	e8 38 d5 ff ff       	call   0x402840
  405308:	83 f8 ff             	cmp    eax,0xffffffff
  40530b:	74 52                	je     0x40535f
  40530d:	8d 7c 24 14          	lea    edi,[esp+0x14]
  405311:	83 c9 ff             	or     ecx,0xffffffff
  405314:	33 c0                	xor    eax,eax
  405316:	f2 ae                	repnz scas al,BYTE PTR es:[edi]
  405318:	f7 d1                	not    ecx
  40531a:	49                   	dec    ecx
  40531b:	74 42                	je     0x40535f
  40531d:	6a 20                	push   0x20
  40531f:	e8 fd 8e 14 00       	call   0x54e221
  405324:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  405328:	8b f8                	mov    edi,eax
  40532a:	51                   	push   ecx
  40532b:	68 d0 30 56 00       	push   0x5630d0
  405330:	57                   	push   edi
  405331:	e8 4d 8a 14 00       	call   0x54dd83
  405336:	83 c4 10             	add    esp,0x10
  405339:	b9 90 c5 57 00       	mov    ecx,0x57c590
  40533e:	57                   	push   edi
  40533f:	e8 6c c1 ff ff       	call   0x4014b0
  405344:	8b 0d d8 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5d8
  40534a:	55                   	push   ebp
  40534b:	8d 54 24 18          	lea    edx,[esp+0x18]
  40534f:	68 00 01 00 00       	push   0x100
  405354:	52                   	push   edx
  405355:	e8 e6 d4 ff ff       	call   0x402840
  40535a:	83 f8 ff             	cmp    eax,0xffffffff
  40535d:	75 ae                	jne    0x40530d
  40535f:	8b 0d d8 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5d8
  405365:	55                   	push   ebp
  405366:	e8 25 d6 ff ff       	call   0x402990
  40536b:	8b 3d 90 c0 55 00    	mov    edi,DWORD PTR ds:0x55c090
  405371:	89 1d f0 c5 57 00    	mov    DWORD PTR ds:0x57c5f0,ebx
  405377:	a1 d8 c0 57 00       	mov    eax,ds:0x57c0d8
  40537c:	6a 0a                	push   0xa
  40537e:	50                   	push   eax
  40537f:	ff d7                	call   edi
  405381:	85 c0                	test   eax,eax
  405383:	0f 84 e4 01 00 00    	je     0x40556d
  405389:	a1 6c 38 56 00       	mov    eax,ds:0x56386c
  40538e:	3b c3                	cmp    eax,ebx
  405390:	74 05                	je     0x405397
  405392:	a3 b8 c5 57 00       	mov    ds:0x57c5b8,eax
  405397:	83 c0 eb             	add    eax,0xffffffeb
  40539a:	83 f8 08             	cmp    eax,0x8
  40539d:	0f 87 b8 01 00 00    	ja     0x40555b
  4053a3:	ff 24 85 a4 55 40 00 	jmp    DWORD PTR [eax*4+0x4055a4]
  4053aa:	e8 31 fd ff ff       	call   0x4050e0
  4053af:	3b f3                	cmp    esi,ebx
  4053b1:	74 0c                	je     0x4053bf
  4053b3:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  4053b9:	56                   	push   esi
  4053ba:	e8 41 13 12 00       	call   0x526700
  4053bf:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  4053c3:	51                   	push   ecx
  4053c4:	e8 57 15 07 00       	call   0x476920
  4053c9:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  4053cd:	83 c4 04             	add    esp,0x4
  4053d0:	8b f0                	mov    esi,eax
  4053d2:	52                   	push   edx
  4053d3:	e9 31 01 00 00       	jmp    0x405509
  4053d8:	3b f3                	cmp    esi,ebx
  4053da:	74 0c                	je     0x4053e8
  4053dc:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  4053e2:	56                   	push   esi
  4053e3:	e8 18 13 12 00       	call   0x526700
  4053e8:	8d 44 24 10          	lea    eax,[esp+0x10]
  4053ec:	50                   	push   eax
  4053ed:	e8 de 87 06 00       	call   0x46dbd0
  4053f2:	8b f0                	mov    esi,eax
  4053f4:	56                   	push   esi
  4053f5:	e8 16 1d 0c 00       	call   0x4c7110
  4053fa:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4053fe:	83 c4 08             	add    esp,0x8
  405401:	51                   	push   ecx
  405402:	e9 02 01 00 00       	jmp    0x405509
  405407:	3b f3                	cmp    esi,ebx
  405409:	74 0c                	je     0x405417
  40540b:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  405411:	56                   	push   esi
  405412:	e8 e9 12 12 00       	call   0x526700
  405417:	8d 54 24 10          	lea    edx,[esp+0x10]
  40541b:	52                   	push   edx
  40541c:	e8 cf f9 06 00       	call   0x474df0
  405421:	8b f0                	mov    esi,eax
  405423:	56                   	push   esi
  405424:	e8 97 86 0c 00       	call   0x4cdac0
  405429:	e9 d3 00 00 00       	jmp    0x405501
  40542e:	3b f3                	cmp    esi,ebx
  405430:	74 0c                	je     0x40543e
  405432:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  405438:	56                   	push   esi
  405439:	e8 c2 12 12 00       	call   0x526700
  40543e:	89 1d c0 c5 57 00    	mov    DWORD PTR ds:0x57c5c0,ebx
  405444:	e8 a7 f6 ff ff       	call   0x404af0
  405449:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  40544f:	6a 01                	push   0x1
  405451:	89 1d c0 c5 57 00    	mov    DWORD PTR ds:0x57c5c0,ebx
  405457:	33 f6                	xor    esi,esi
  405459:	e8 b2 05 12 00       	call   0x525a10
  40545e:	e9 14 ff ff ff       	jmp    0x405377
  405463:	3b f3                	cmp    esi,ebx
  405465:	74 0c                	je     0x405473
  405467:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  40546d:	56                   	push   esi
  40546e:	e8 8d 12 12 00       	call   0x526700
  405473:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  405477:	51                   	push   ecx
  405478:	e8 23 d9 06 00       	call   0x472da0
  40547d:	8b f0                	mov    esi,eax
  40547f:	56                   	push   esi
  405480:	e8 4b 68 0c 00       	call   0x4cbcd0
  405485:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  405489:	83 c4 08             	add    esp,0x8
  40548c:	52                   	push   edx
  40548d:	eb 7a                	jmp    0x405509
  40548f:	39 1d f0 c5 57 00    	cmp    DWORD PTR ds:0x57c5f0,ebx
  405495:	0f 85 c0 00 00 00    	jne    0x40555b
  40549b:	8d 44 24 10          	lea    eax,[esp+0x10]
  40549f:	50                   	push   eax
  4054a0:	e8 0b fc 06 00       	call   0x4750b0
  4054a5:	50                   	push   eax
  4054a6:	a3 f0 c5 57 00       	mov    ds:0x57c5f0,eax
  4054ab:	e8 20 8a 0c 00       	call   0x4cded0
  4054b0:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4054b4:	83 c4 08             	add    esp,0x8
  4054b7:	51                   	push   ecx
  4054b8:	eb 4f                	jmp    0x405509
  4054ba:	3b f3                	cmp    esi,ebx
  4054bc:	74 0c                	je     0x4054ca
  4054be:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  4054c4:	56                   	push   esi
  4054c5:	e8 36 12 12 00       	call   0x526700
  4054ca:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  4054d0:	6a 01                	push   0x1
  4054d2:	33 f6                	xor    esi,esi
  4054d4:	89 1d 6c 38 56 00    	mov    DWORD PTR ds:0x56386c,ebx
  4054da:	e8 31 05 12 00       	call   0x525a10
  4054df:	e9 93 fe ff ff       	jmp    0x405377
  4054e4:	39 1d f0 c5 57 00    	cmp    DWORD PTR ds:0x57c5f0,ebx
  4054ea:	75 6f                	jne    0x40555b
  4054ec:	8d 54 24 10          	lea    edx,[esp+0x10]
  4054f0:	52                   	push   edx
  4054f1:	e8 6a 94 06 00       	call   0x46e960
  4054f6:	50                   	push   eax
  4054f7:	a3 f0 c5 57 00       	mov    ds:0x57c5f0,eax
  4054fc:	e8 7f 28 0c 00       	call   0x4c7d80
  405501:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  405505:	83 c4 08             	add    esp,0x8
  405508:	50                   	push   eax
  405509:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  40550f:	e8 4c e8 11 00       	call   0x523d60
  405514:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  40551a:	6a 01                	push   0x1
  40551c:	89 1d 6c 38 56 00    	mov    DWORD PTR ds:0x56386c,ebx
  405522:	e8 e9 04 12 00       	call   0x525a10
  405527:	e9 4b fe ff ff       	jmp    0x405377
  40552c:	e8 6f fd ff ff       	call   0x4052a0
  405531:	3b f3                	cmp    esi,ebx
  405533:	74 0c                	je     0x405541
  405535:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  40553b:	56                   	push   esi
  40553c:	e8 bf 11 12 00       	call   0x526700
  405541:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  405547:	6a 01                	push   0x1
  405549:	e8 c2 04 12 00       	call   0x525a10
  40554e:	38 1d 54 bb 57 00    	cmp    BYTE PTR ds:0x57bb54,bl
  405554:	74 05                	je     0x40555b
  405556:	e8 95 f5 ff ff       	call   0x404af0
  40555b:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  405561:	6a 01                	push   0x1
  405563:	e8 a8 04 12 00       	call   0x525a10
  405568:	e9 0a fe ff ff       	jmp    0x405377
  40556d:	e8 5e 00 00 00       	call   0x4055d0
  405572:	8b 0d 10 ba 57 00    	mov    ecx,DWORD PTR ds:0x57ba10
  405578:	5f                   	pop    edi
  405579:	3b cb                	cmp    ecx,ebx
  40557b:	74 06                	je     0x405583
  40557d:	8b 11                	mov    edx,DWORD PTR [ecx]
  40557f:	6a 01                	push   0x1
  405581:	ff 12                	call   DWORD PTR [edx]
  405583:	8b 0d cc c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5cc
  405589:	3b cb                	cmp    ecx,ebx
  40558b:	74 06                	je     0x405593
  40558d:	8b 01                	mov    eax,DWORD PTR [ecx]
  40558f:	6a 01                	push   0x1
  405591:	ff 10                	call   DWORD PTR [eax]
  405593:	5e                   	pop    esi
  405594:	89 1d cc c5 57 00    	mov    DWORD PTR ds:0x57c5cc,ebx
  40559a:	5d                   	pop    ebp
  40559b:	5b                   	pop    ebx
  40559c:	81 c4 04 01 00 00    	add    esp,0x104
```

## `Game_RunSession` — `0x404af0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x404af0.c`
- Callers: `GameLoop_DispatchScreens` (0x4052c0)
- Callees: `CRT_Ifstream_Construct` (0x54cc99), `CRT_Istream_Read` (0x54cbc1), `CS_Enter` (0x401320), `CS_Leave` (0x401340), `Font_DrawTextLine` (0x535740), `GameSession_Construct` (0x4811b0), `Game_AcquireStateLock` (0x486be0), `Game_ApplyPendingScreen` (0x485bb0), `Game_DestroyCachedScreens` (0x483c40), `Game_DestroyEventWindow` (0x4830e0), `Game_InitScenario` (0x481d90), `Game_LoadSaveGame` (0x488110), `Game_RemoveScreenTimers` (0x48d0c0), `Game_ResumeSimulation` (0x488d20), `Game_SetGlobalWord16` (0x4dd650), `Game_SetViewMode` (0x4850a0), `Game_SuspendSimulation` (0x488cc0), `Object_GetRootType` (0x539f00), `Set_Field9B8` (0x535500), `SoundBuffer_Release` (0x547fd0), `String_Format` (0x54dd83), `Surface_LockPrimary` (0x538f90), `Surface_Unlock` (0x539260), `Text_SetMetrics` (0x535520), `UI_CloseLoadingScreen` (0x406a60), `UI_LoadFontByName` (0x527090), `UI_MessageBoxf` (0x526870), `UI_ReleaseRefCount` (0x5271d0), `UI_ShowLoadingOverlay` (0x406910), `Window_GadgetNotify_Slider_SetValue` (0x52fd70), `Window_ProcessMessageQueue` (0x525a10), `Window_ShowWindowById` (0x523d60), `Window_UnlockState` (0x486e00)

- Signature: `{'call_site': '0x405444', 'confidence': 'derived from call site and no stack arguments', 'recovered': 'void __cdecl Game_RunSession(void)', 'return': 'void'}`
- Dispatch: `call` None -> ['0x4811b0'], `call` None -> ['0x481d90']
- Unresolved questions: Indirect virtual/import calls in the session loop are outside this batch.

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

00404af0 <.text+0x3af0>:
  404af0:	6a ff                	push   0xffffffff
  404af2:	68 cc 7c 55 00       	push   0x557ccc
  404af7:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  404afd:	50                   	push   eax
  404afe:	64 89 25 00 00 00 00 	mov    DWORD PTR fs:0x0,esp
  404b05:	81 ec 64 01 00 00    	sub    esp,0x164
  404b0b:	a0 ec 9a 57 00       	mov    al,ds:0x579aec
  404b10:	53                   	push   ebx
  404b11:	55                   	push   ebp
  404b12:	56                   	push   esi
  404b13:	57                   	push   edi
  404b14:	88 44 24 44          	mov    BYTE PTR [esp+0x44],al
  404b18:	b9 0f 00 00 00       	mov    ecx,0xf
  404b1d:	33 c0                	xor    eax,eax
  404b1f:	8d 7c 24 45          	lea    edi,[esp+0x45]
  404b23:	be 01 00 00 00       	mov    esi,0x1
  404b28:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  404b2a:	66 ab                	stos   WORD PTR es:[edi],ax
  404b2c:	aa                   	stos   BYTE PTR es:[edi],al
  404b2d:	33 ff                	xor    edi,edi
  404b2f:	56                   	push   esi
  404b30:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  404b34:	89 7c 24 30          	mov    DWORD PTR [esp+0x30],edi
  404b38:	89 7c 24 1c          	mov    DWORD PTR [esp+0x1c],edi
  404b3c:	89 7c 24 34          	mov    DWORD PTR [esp+0x34],edi
  404b40:	89 74 24 24          	mov    DWORD PTR [esp+0x24],esi
  404b44:	89 7c 24 18          	mov    DWORD PTR [esp+0x18],edi
  404b48:	89 7c 24 2c          	mov    DWORD PTR [esp+0x2c],edi
  404b4c:	89 7c 24 3c          	mov    DWORD PTR [esp+0x3c],edi
  404b50:	89 7c 24 40          	mov    DWORD PTR [esp+0x40],edi
  404b54:	89 7c 24 44          	mov    DWORD PTR [esp+0x44],edi
  404b58:	e8 b3 1d 00 00       	call   0x406910
  404b5d:	83 c4 04             	add    esp,0x4
  404b60:	ff 15 94 c2 55 00    	call   DWORD PTR ds:0x55c294
  404b66:	8b 0d f4 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5f4
  404b6c:	8b d8                	mov    ebx,eax
  404b6e:	57                   	push   edi
  404b6f:	81 c3 e8 03 00 00    	add    ebx,0x3e8
  404b75:	6a 05                	push   0x5
  404b77:	68 f7 03 00 00       	push   0x3f7
  404b7c:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  404b80:	e8 eb b1 12 00       	call   0x52fd70
  404b85:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  404b8b:	57                   	push   edi
  404b8c:	e8 7f 0e 12 00       	call   0x525a10
  404b91:	68 28 2e 00 00       	push   0x2e28
  404b96:	e8 86 96 14 00       	call   0x54e221
  404b9b:	83 c4 04             	add    esp,0x4
  404b9e:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  404ba2:	3b c7                	cmp    eax,edi
  404ba4:	89 bc 24 7c 01 00 00 	mov    DWORD PTR [esp+0x17c],edi
  404bab:	74 0a                	je     0x404bb7
  404bad:	57                   	push   edi
  404bae:	8b c8                	mov    ecx,eax
  404bb0:	e8 fb c5 07 00       	call   0x4811b0
  404bb5:	eb 02                	jmp    0x404bb9
  404bb7:	33 c0                	xor    eax,eax
  404bb9:	8b 0d f4 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5f4
  404bbf:	57                   	push   edi
  404bc0:	83 cd ff             	or     ebp,0xffffffff
  404bc3:	6a 0f                	push   0xf
  404bc5:	68 f7 03 00 00       	push   0x3f7
  404bca:	89 ac 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],ebp
  404bd1:	a3 70 c6 57 00       	mov    ds:0x57c670,eax
  404bd6:	e8 95 b1 12 00       	call   0x52fd70
  404bdb:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  404be1:	57                   	push   edi
  404be2:	e8 29 0e 12 00       	call   0x525a10
  404be7:	a0 54 bb 57 00       	mov    al,ds:0x57bb54
  404bec:	84 c0                	test   al,al
  404bee:	0f 84 d9 01 00 00    	je     0x404dcd
  404bf4:	6a 5c                	push   0x5c
  404bf6:	e8 26 96 14 00       	call   0x54e221
  404bfb:	83 c4 04             	add    esp,0x4
  404bfe:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  404c02:	3b c7                	cmp    eax,edi
  404c04:	89 b4 24 7c 01 00 00 	mov    DWORD PTR [esp+0x17c],esi
  404c0b:	74 1d                	je     0x404c2a
  404c0d:	8b 0d 38 cc 55 00    	mov    ecx,DWORD PTR ds:0x55cc38
  404c13:	56                   	push   esi
  404c14:	51                   	push   ecx
  404c15:	68 a1 00 00 00       	push   0xa1
  404c1a:	68 54 bb 57 00       	push   0x57bb54
  404c1f:	8b c8                	mov    ecx,eax
  404c21:	e8 73 80 14 00       	call   0x54cc99
  404c26:	8b f0                	mov    esi,eax
  404c28:	eb 02                	jmp    0x404c2c
  404c2a:	33 f6                	xor    esi,esi
  404c2c:	8b 16                	mov    edx,DWORD PTR [esi]
  404c2e:	89 ac 24 7c 01 00 00 	mov    DWORD PTR [esp+0x17c],ebp
  404c35:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  404c38:	8b 54 30 04          	mov    edx,DWORD PTR [eax+esi*1+0x4]
  404c3c:	8d 0c 30             	lea    ecx,[eax+esi*1]
  404c3f:	8b 42 4c             	mov    eax,DWORD PTR [edx+0x4c]
  404c42:	3b c5                	cmp    eax,ebp
  404c44:	75 13                	jne    0x404c59
  404c46:	3b f7                	cmp    esi,edi
  404c48:	0f 84 a8 01 00 00    	je     0x404df6
  404c4e:	8b 01                	mov    eax,DWORD PTR [ecx]
  404c50:	6a 01                	push   0x1
  404c52:	ff 10                	call   DWORD PTR [eax]
  404c54:	e9 9d 01 00 00       	jmp    0x404df6
  404c59:	8b 2d 78 c2 55 00    	mov    ebp,DWORD PTR ds:0x55c278
  404c5f:	68 02 7f 00 00       	push   0x7f02
  404c64:	57                   	push   edi
  404c65:	ff d5                	call   ebp
  404c67:	8b 0d d0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5d0
  404c6d:	8b 1d 54 c2 55 00    	mov    ebx,DWORD PTR ds:0x55c254
  404c73:	8b f8                	mov    edi,eax
  404c75:	57                   	push   edi
  404c76:	6a f4                	push   0xfffffff4
  404c78:	51                   	push   ecx
  404c79:	ff d3                	call   ebx
  404c7b:	8b 15 d0 c5 57 00    	mov    edx,DWORD PTR ds:0x57c5d0
  404c81:	57                   	push   edi
  404c82:	8b 3d 64 c2 55 00    	mov    edi,DWORD PTR ds:0x55c264
  404c88:	6a 00                	push   0x0
  404c8a:	68 00 04 00 00       	push   0x400
  404c8f:	52                   	push   edx
  404c90:	ff d7                	call   edi
  404c92:	8d 84 24 84 00 00 00 	lea    eax,[esp+0x84]
  404c99:	68 f0 00 00 00       	push   0xf0
  404c9e:	50                   	push   eax
  404c9f:	8b ce                	mov    ecx,esi
  404ca1:	e8 1b 7f 14 00       	call   0x54cbc1
  404ca6:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  404cac:	e8 0f 40 08 00       	call   0x488cc0
  404cb1:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  404cb7:	6a 00                	push   0x0
  404cb9:	e8 22 1f 08 00       	call   0x486be0
  404cbe:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  404cc4:	8b 89 40 02 00 00    	mov    ecx,DWORD PTR [ecx+0x240]
  404cca:	e8 51 c6 ff ff       	call   0x401320
  404ccf:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  404cd5:	8d 54 24 34          	lea    edx,[esp+0x34]
  404cd9:	52                   	push   edx
  404cda:	56                   	push   esi
  404cdb:	e8 30 34 08 00       	call   0x488110
  404ce0:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  404ce4:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  404ce9:	8b 88 40 02 00 00    	mov    ecx,DWORD PTR [eax+0x240]
  404cef:	e8 4c c6 ff ff       	call   0x401340
  404cf4:	85 f6                	test   esi,esi
  404cf6:	74 0f                	je     0x404d07
  404cf8:	8b 0e                	mov    ecx,DWORD PTR [esi]
  404cfa:	6a 01                	push   0x1
  404cfc:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  404cff:	03 f2                	add    esi,edx
  404d01:	8b ce                	mov    ecx,esi
  404d03:	8b 06                	mov    eax,DWORD PTR [esi]
  404d05:	ff 10                	call   DWORD PTR [eax]
  404d07:	68 00 7f 00 00       	push   0x7f00
  404d0c:	6a 00                	push   0x0
  404d0e:	ff d5                	call   ebp
  404d10:	8b 0d d0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5d0
  404d16:	8b f0                	mov    esi,eax
  404d18:	56                   	push   esi
  404d19:	6a f4                	push   0xfffffff4
  404d1b:	51                   	push   ecx
  404d1c:	ff d3                	call   ebx
  404d1e:	8b 15 d0 c5 57 00    	mov    edx,DWORD PTR ds:0x57c5d0
  404d24:	56                   	push   esi
  404d25:	6a 00                	push   0x0
  404d27:	68 00 04 00 00       	push   0x400
  404d2c:	52                   	push   edx
  404d2d:	ff d7                	call   edi
  404d2f:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  404d33:	85 c0                	test   eax,eax
  404d35:	75 4f                	jne    0x404d86
  404d37:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  404d3b:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  404d41:	50                   	push   eax
  404d42:	68 98 3b 56 00       	push   0x563b98
  404d47:	51                   	push   ecx
  404d48:	e8 23 1b 12 00       	call   0x526870
  404d4d:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  404d53:	83 c4 0c             	add    esp,0xc
  404d56:	e8 a5 20 08 00       	call   0x486e00
  404d5b:	8b 15 70 c6 57 00    	mov    edx,DWORD PTR ds:0x57c670
  404d61:	8b 82 24 2e 00 00    	mov    eax,DWORD PTR [edx+0x2e24]
  404d67:	85 c0                	test   eax,eax
  404d69:	74 0c                	je     0x404d77
  404d6b:	a1 d8 c0 57 00       	mov    eax,ds:0x57c0d8
  404d70:	50                   	push   eax
  404d71:	ff 15 94 c0 55 00    	call   DWORD PTR ds:0x55c094
  404d77:	8b 5c 24 10          	mov    ebx,DWORD PTR [esp+0x10]
  404d7b:	c6 05 54 bb 57 00 00 	mov    BYTE PTR ds:0x57bb54,0x0
  404d82:	33 ff                	xor    edi,edi
  404d84:	eb 70                	jmp    0x404df6
  404d86:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  404d8c:	e8 6f 20 08 00       	call   0x486e00
  404d91:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  404d97:	6a 00                	push   0x0
  404d99:	6a 01                	push   0x1
  404d9b:	e8 00 03 08 00       	call   0x4850a0
  404da0:	bf 90 3b 56 00       	mov    edi,0x563b90
  404da5:	83 c9 ff             	or     ecx,0xffffffff
  404da8:	33 c0                	xor    eax,eax
  404daa:	8b 5c 24 10          	mov    ebx,DWORD PTR [esp+0x10]
  404dae:	f2 ae                	repnz scas al,BYTE PTR es:[edi]
  404db0:	f7 d1                	not    ecx
  404db2:	2b f9                	sub    edi,ecx
  404db4:	8b d1                	mov    edx,ecx
  404db6:	8b f7                	mov    esi,edi
  404db8:	bf 54 bb 57 00       	mov    edi,0x57bb54
  404dbd:	c1 e9 02             	shr    ecx,0x2
  404dc0:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  404dc2:	8b ca                	mov    ecx,edx
  404dc4:	83 e1 03             	and    ecx,0x3
  404dc7:	f3 a4                	rep movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
  404dc9:	33 ff                	xor    edi,edi
  404dcb:	eb 29                	jmp    0x404df6
  404dcd:	39 3d 40 bb 57 00    	cmp    DWORD PTR ds:0x57bb40,edi
  404dd3:	7e 21                	jle    0x404df6
  404dd5:	a0 20 bb 57 00       	mov    al,ds:0x57bb20
  404dda:	84 c0                	test   al,al
  404ddc:	75 18                	jne    0x404df6
  404dde:	a1 4c c2 57 00       	mov    eax,ds:0x57c24c
  404de3:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  404de9:	40                   	inc    eax
  404dea:	8b 89 94 00 00 00    	mov    ecx,DWORD PTR [ecx+0x94]
  404df0:	50                   	push   eax
  404df1:	e8 5a 88 0d 00       	call   0x4dd650
  404df6:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  404dfc:	e8 8f cf 07 00       	call   0x481d90
  404e01:	e8 5a 1c 00 00       	call   0x406a60
  404e06:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  404e0c:	68 80 3b 56 00       	push   0x563b80
  404e11:	c7 44 24 14 01 00 00 	mov    DWORD PTR [esp+0x14],0x1
  404e18:	00 
  404e19:	e8 72 22 12 00       	call   0x527090
  404e1e:	8b 15 d8 c0 57 00    	mov    edx,DWORD PTR ds:0x57c0d8
  404e24:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  404e2a:	8b f0                	mov    esi,eax
  404e2c:	a1 ac c5 57 00       	mov    eax,ds:0x57c5ac
  404e31:	89 54 24 38          	mov    DWORD PTR [esp+0x38],edx
  404e35:	89 44 24 3c          	mov    DWORD PTR [esp+0x3c],eax
  404e39:	8a 81 94 2d 00 00    	mov    al,BYTE PTR [ecx+0x2d94]
  404e3f:	84 c0                	test   al,al
  404e41:	0f 84 19 02 00 00    	je     0x405060
  404e47:	6a 14                	push   0x14
  404e49:	8d 54 24 3c          	lea    edx,[esp+0x3c]
  404e4d:	57                   	push   edi
  404e4e:	52                   	push   edx
  404e4f:	6a 02                	push   0x2
  404e51:	ff 15 88 c0 55 00    	call   DWORD PTR ds:0x55c088
  404e57:	85 c0                	test   eax,eax
  404e59:	0f 84 01 02 00 00    	je     0x405060
  404e5f:	39 3d e0 c5 57 00    	cmp    DWORD PTR ds:0x57c5e0,edi
  404e65:	0f 84 e2 01 00 00    	je     0x40504d
  404e6b:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  404e71:	e8 3a 0d 08 00       	call   0x485bb0
  404e76:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  404e7b:	8b 88 4c 02 00 00    	mov    ecx,DWORD PTR [eax+0x24c]
  404e81:	3b cf                	cmp    ecx,edi
  404e83:	75 2b                	jne    0x404eb0
  404e85:	8b 88 3c 02 00 00    	mov    ecx,DWORD PTR [eax+0x23c]
  404e8b:	e8 90 c4 ff ff       	call   0x401320
  404e90:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  404e95:	c7 80 4c 02 00 00 01 	mov    DWORD PTR [eax+0x24c],0x1
  404e9c:	00 00 00 
  404e9f:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  404ea5:	8b 89 3c 02 00 00    	mov    ecx,DWORD PTR [ecx+0x23c]
  404eab:	e8 90 c4 ff ff       	call   0x401340
  404eb0:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  404eb6:	6a 01                	push   0x1
  404eb8:	e8 53 0b 12 00       	call   0x525a10
  404ebd:	8b 15 70 c6 57 00    	mov    edx,DWORD PTR ds:0x57c670
  404ec3:	8b e8                	mov    ebp,eax
  404ec5:	89 ba 4c 02 00 00    	mov    DWORD PTR [edx+0x24c],edi
  404ecb:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  404ecf:	3b c7                	cmp    eax,edi
  404ed1:	74 26                	je     0x404ef9
  404ed3:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  404ed9:	89 7c 24 10          	mov    DWORD PTR [esp+0x10],edi
  404edd:	e8 3e 3e 08 00       	call   0x488d20
  404ee2:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  404ee7:	8b 88 ac 2d 00 00    	mov    ecx,DWORD PTR [eax+0x2dac]
  404eed:	51                   	push   ecx
  404eee:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  404ef4:	e8 67 ee 11 00       	call   0x523d60
  404ef9:	39 3d e8 c5 57 00    	cmp    DWORD PTR ds:0x57c5e8,edi
  404eff:	0f 84 f9 00 00 00    	je     0x404ffe
  404f05:	3b ef                	cmp    ebp,edi
  404f07:	77 66                	ja     0x404f6f
  404f09:	39 7c 24 20          	cmp    DWORD PTR [esp+0x20],edi
  404f0d:	75 60                	jne    0x404f6f
  404f0f:	8b 0d c8 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5c8
  404f15:	e8 e6 4f 13 00       	call   0x539f00
  404f1a:	85 c0                	test   eax,eax
  404f1c:	0f 85 dc 00 00 00    	jne    0x404ffe
  404f22:	3b f7                	cmp    esi,edi
  404f24:	0f 84 d4 00 00 00    	je     0x404ffe
  404f2a:	8b 0d c8 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5c8
  404f30:	e8 5b 40 13 00       	call   0x538f90
  404f35:	57                   	push   edi
  404f36:	6a 10                	push   0x10
  404f38:	6a 0a                	push   0xa
  404f3a:	8b ce                	mov    ecx,esi
  404f3c:	e8 df 05 13 00       	call   0x535520
  404f41:	68 ff ff ff 00       	push   0xffffff
  404f46:	8b ce                	mov    ecx,esi
  404f48:	e8 b3 05 13 00       	call   0x535500
  404f4d:	a1 c8 c5 57 00       	mov    eax,ds:0x57c5c8
  404f52:	8d 54 24 44          	lea    edx,[esp+0x44]
  404f56:	52                   	push   edx
  404f57:	50                   	push   eax
  404f58:	8b ce                	mov    ecx,esi
  404f5a:	e8 e1 07 13 00       	call   0x535740
  404f5f:	8b 0d c8 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5c8
  404f65:	e8 f6 42 13 00       	call   0x539260
  404f6a:	e9 8f 00 00 00       	jmp    0x404ffe
  404f6f:	3b 6c 24 18          	cmp    ebp,DWORD PTR [esp+0x18]
  404f73:	76 04                	jbe    0x404f79
  404f75:	89 6c 24 18          	mov    DWORD PTR [esp+0x18],ebp
  404f79:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  404f7d:	3b cf                	cmp    ecx,edi
  404f7f:	7e 0a                	jle    0x404f8b
  404f81:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  404f85:	33 d2                	xor    edx,edx
  404f87:	f7 f1                	div    ecx
  404f89:	eb 02                	jmp    0x404f8d
  404f8b:	33 c0                	xor    eax,eax
  404f8d:	8b 54 24 30          	mov    edx,DWORD PTR [esp+0x30]
  404f91:	50                   	push   eax
  404f92:	52                   	push   edx
  404f93:	51                   	push   ecx
  404f94:	8d 44 24 50          	lea    eax,[esp+0x50]
  404f98:	68 6c 3b 56 00       	push   0x563b6c
  404f9d:	50                   	push   eax
  404f9e:	e8 e0 8d 14 00       	call   0x54dd83
  404fa3:	8b 0d c8 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5c8
  404fa9:	83 c4 14             	add    esp,0x14
  404fac:	e8 4f 4f 13 00       	call   0x539f00
  404fb1:	85 c0                	test   eax,eax
  404fb3:	75 45                	jne    0x404ffa
  404fb5:	3b f7                	cmp    esi,edi
  404fb7:	74 41                	je     0x404ffa
  404fb9:	8b 0d c8 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5c8
  404fbf:	e8 cc 3f 13 00       	call   0x538f90
  404fc4:	57                   	push   edi
  404fc5:	6a 10                	push   0x10
  404fc7:	6a 0a                	push   0xa
  404fc9:	8b ce                	mov    ecx,esi
  404fcb:	e8 50 05 13 00       	call   0x535520
  404fd0:	68 ff ff ff 00       	push   0xffffff
  404fd5:	8b ce                	mov    ecx,esi
  404fd7:	e8 24 05 13 00       	call   0x535500
  404fdc:	8b 15 c8 c5 57 00    	mov    edx,DWORD PTR ds:0x57c5c8
  404fe2:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  404fe6:	51                   	push   ecx
  404fe7:	52                   	push   edx
  404fe8:	8b ce                	mov    ecx,esi
  404fea:	e8 51 07 13 00       	call   0x535740
  404fef:	8b 0d c8 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5c8
  404ff5:	e8 66 42 13 00       	call   0x539260
  404ffa:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  404ffe:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  405002:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  405006:	40                   	inc    eax
  405007:	03 d5                	add    edx,ebp
  405009:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  40500d:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  405011:	ff 15 94 c2 55 00    	call   DWORD PTR ds:0x55c294
  405017:	3b c3                	cmp    eax,ebx
  405019:	72 32                	jb     0x40504d
  40501b:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  40501f:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  405023:	8b 54 24 1c          	mov    edx,DWORD PTR [esp+0x1c]
  405027:	81 c3 e8 03 00 00    	add    ebx,0x3e8
  40502d:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  405031:	89 4c 24 28          	mov    DWORD PTR [esp+0x28],ecx
  405035:	89 7c 24 18          	mov    DWORD PTR [esp+0x18],edi
  405039:	89 54 24 2c          	mov    DWORD PTR [esp+0x2c],edx
  40503d:	89 7c 24 1c          	mov    DWORD PTR [esp+0x1c],edi
  405041:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  405045:	c7 44 24 20 01 00 00 	mov    DWORD PTR [esp+0x20],0x1
  40504c:	00 
  40504d:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  405052:	8a 88 94 2d 00 00    	mov    cl,BYTE PTR [eax+0x2d94]
  405058:	84 c9                	test   cl,cl
  40505a:	0f 85 e7 fd ff ff    	jne    0x404e47
  405060:	c7 05 0c b4 56 00 01 	mov    DWORD PTR ds:0x56b40c,0x1
  405067:	00 00 00 
  40506a:	8b 0d 0c ba 57 00    	mov    ecx,DWORD PTR ds:0x57ba0c
  405070:	e8 5b 2f 14 00       	call   0x547fd0
  405075:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  40507b:	e8 40 80 08 00       	call   0x48d0c0
  405080:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  405086:	56                   	push   esi
  405087:	e8 44 21 12 00       	call   0x5271d0
  40508c:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405092:	6a ff                	push   0xffffffff
  405094:	e8 a7 eb 07 00       	call   0x483c40
  405099:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  40509f:	e8 3c e0 07 00       	call   0x4830e0
  4050a4:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4050aa:	3b cf                	cmp    ecx,edi
  4050ac:	74 06                	je     0x4050b4
  4050ae:	8b 11                	mov    edx,DWORD PTR [ecx]
  4050b0:	6a 01                	push   0x1
  4050b2:	ff 12                	call   DWORD PTR [edx]
  4050b4:	89 3d 70 c6 57 00    	mov    DWORD PTR ds:0x57c670,edi
  4050ba:	89 3d 0c b4 56 00    	mov    DWORD PTR ds:0x56b40c,edi
  4050c0:	8b 8c 24 74 01 00 00 	mov    ecx,DWORD PTR [esp+0x174]
  4050c7:	5f                   	pop    edi
  4050c8:	5e                   	pop    esi
  4050c9:	5d                   	pop    ebp
  4050ca:	5b                   	pop    ebx
  4050cb:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4050d2:	81 c4 70 01 00 00    	add    esp,0x170
```

## `Game_InitScenario` — `0x481d90`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x481d90.c`
- Callers: `Game_RunSession` (0x404af0)
- Callees: `CS_Enter` (0x401320), `CS_Leave` (0x401340), `Character_Construct` (0x4d3730), `City_ConstructFromName` (0x4d44e0), `City_Register` (0x482740), `Company_ConstructDefault` (0x4dd6b0), `Company_GenerateStartingRecipes` (0x4dd8f0), `Game_AddPoliceStations` (0x4ffbe0), `Game_AddScreenTimer` (0x482590), `Game_GetStartingCapital` (0x48d3a0), `Game_InitCompanySlots` (0x4f6e70), `Map_RefreshObjectSprites` (0x48cb30), `Mission_ApplySettings` (0x4dc080), `Object_SetField8` (0x50efb0), `PlayerCompany_InitDefaults` (0x50f590), `Player_AIState_Init` (0x50f4c0), `Player_Construct` (0x50e8e0), `Player_ResetAiState` (0x50efc0), `Random_RangeFast` (0x4034d0), `Sound_InitSpeechVoice` (0x5476f0), `Sound_UpdatePositionCountdown` (0x548510), `String_Format` (0x54dd83), `UI_UpdateAllSlots` (0x500030), `Window_GadgetNotify_Slider_SetValue` (0x52fd70), `Window_ProcessMessageQueue` (0x525a10)

- Signature: `{'call_site': '0x404dfc', 'confidence': 'derived from call site', 'note': 'Provider signature has extra stack-tracking parameters; observed call passes only ECX=Game* and no stack arguments.', 'recovered': 'void __thiscall Game_InitScenario(Game *this)', 'return': 'void'}`
- Dispatch: `call` None -> ['0x4d44e0'], `call` None -> ['0x482740'], `call` None -> ['0x48d3a0']
- Unresolved questions: Company/player object fields other than cash +0x108 are outside this batch.; The provider signature carries spurious stack parameters; use the call-site signature.

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

00481d90 <.text+0x80d90>:
  481d90:	55                   	push   ebp
  481d91:	8b ec                	mov    ebp,esp
  481d93:	83 e4 f8             	and    esp,0xfffffff8
  481d96:	6a ff                	push   0xffffffff
  481d98:	68 dc 81 55 00       	push   0x5581dc
  481d9d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  481da3:	50                   	push   eax
  481da4:	64 89 25 00 00 00 00 	mov    DWORD PTR fs:0x0,esp
  481dab:	83 ec 48             	sub    esp,0x48
  481dae:	a0 44 bb 57 00       	mov    al,ds:0x57bb44
  481db3:	53                   	push   ebx
  481db4:	55                   	push   ebp
  481db5:	33 db                	xor    ebx,ebx
  481db7:	56                   	push   esi
  481db8:	57                   	push   edi
  481db9:	84 c0                	test   al,al
  481dbb:	8b e9                	mov    ebp,ecx
  481dbd:	75 25                	jne    0x481de4
  481dbf:	bf 9c 80 56 00       	mov    edi,0x56809c
  481dc4:	83 c9 ff             	or     ecx,0xffffffff
  481dc7:	33 c0                	xor    eax,eax
  481dc9:	f2 ae                	repnz scas al,BYTE PTR es:[edi]
  481dcb:	f7 d1                	not    ecx
  481dcd:	2b f9                	sub    edi,ecx
  481dcf:	8b c1                	mov    eax,ecx
  481dd1:	8b f7                	mov    esi,edi
  481dd3:	bf 44 bb 57 00       	mov    edi,0x57bb44
  481dd8:	c1 e9 02             	shr    ecx,0x2
  481ddb:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  481ddd:	8b c8                	mov    ecx,eax
  481ddf:	83 e1 03             	and    ecx,0x3
  481de2:	f3 a4                	rep movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
  481de4:	8b 0d f4 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5f4
  481dea:	6a 00                	push   0x0
  481dec:	6a 14                	push   0x14
  481dee:	68 f7 03 00 00       	push   0x3f7
  481df3:	e8 78 df 0a 00       	call   0x52fd70
  481df8:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  481dfe:	6a 00                	push   0x0
  481e00:	e8 0b 3c 0a 00       	call   0x525a10
  481e05:	8b 8d 40 02 00 00    	mov    ecx,DWORD PTR [ebp+0x240]
  481e0b:	e8 10 f5 f7 ff       	call   0x401320
  481e10:	a0 54 bb 57 00       	mov    al,ds:0x57bb54
  481e15:	84 c0                	test   al,al
  481e17:	0f 85 07 07 00 00    	jne    0x482524
  481e1d:	b8 cc bd 57 00       	mov    eax,0x57bdcc
  481e22:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  481e25:	85 c9                	test   ecx,ecx
  481e27:	74 2a                	je     0x481e53
  481e29:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  481e2c:	8b 15 10 bd 57 00    	mov    edx,DWORD PTR ds:0x57bd10
  481e32:	3b ca                	cmp    ecx,edx
  481e34:	75 09                	jne    0x481e3f
  481e36:	8b 15 70 c2 57 00    	mov    edx,DWORD PTR ds:0x57c270
  481e3c:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  481e3f:	8b 08                	mov    ecx,DWORD PTR [eax]
  481e41:	8b 15 0c bd 57 00    	mov    edx,DWORD PTR ds:0x57bd0c
  481e47:	3b ca                	cmp    ecx,edx
  481e49:	75 08                	jne    0x481e53
  481e4b:	8b 15 80 b7 57 00    	mov    edx,DWORD PTR ds:0x57b780
  481e51:	89 10                	mov    DWORD PTR [eax],edx
  481e53:	05 c0 00 00 00       	add    eax,0xc0
  481e58:	3d 8c c1 57 00       	cmp    eax,0x57c18c
  481e5d:	7c c3                	jl     0x481e22
  481e5f:	68 58 11 00 00       	push   0x1158
  481e64:	e8 b8 c3 0c 00       	call   0x54e221
  481e69:	83 c4 04             	add    esp,0x4
  481e6c:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  481e70:	85 c0                	test   eax,eax
  481e72:	c7 44 24 60 00 00 00 	mov    DWORD PTR [esp+0x60],0x0
  481e79:	00 
  481e7a:	74 12                	je     0x481e8e
  481e7c:	6a 00                	push   0x0
  481e7e:	68 44 bb 57 00       	push   0x57bb44
  481e83:	8b c8                	mov    ecx,eax
  481e85:	e8 56 26 05 00       	call   0x4d44e0
  481e8a:	8b f0                	mov    esi,eax
  481e8c:	eb 02                	jmp    0x481e90
  481e8e:	33 f6                	xor    esi,esi
  481e90:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  481e94:	c7 44 24 60 ff ff ff 	mov    DWORD PTR [esp+0x60],0xffffffff
  481e9b:	ff 
  481e9c:	33 c9                	xor    ecx,ecx
  481e9e:	b8 14 bd 57 00       	mov    eax,0x57bd14
  481ea3:	83 38 00             	cmp    DWORD PTR [eax],0x0
  481ea6:	74 01                	je     0x481ea9
  481ea8:	41                   	inc    ecx
  481ea9:	05 c0 00 00 00       	add    eax,0xc0
  481eae:	3d 94 c1 57 00       	cmp    eax,0x57c194
  481eb3:	7c ee                	jl     0x481ea3
  481eb5:	a0 20 bb 57 00       	mov    al,ds:0x57bb20
  481eba:	bf 01 00 00 00       	mov    edi,0x1
  481ebf:	84 c0                	test   al,al
  481ec1:	74 11                	je     0x481ed4
  481ec3:	a1 28 bb 57 00       	mov    eax,ds:0x57bb28
  481ec8:	51                   	push   ecx
  481ec9:	50                   	push   eax
  481eca:	56                   	push   esi
  481ecb:	8b cd                	mov    ecx,ebp
  481ecd:	e8 6e 08 00 00       	call   0x482740
  481ed2:	eb 5d                	jmp    0x481f31
  481ed4:	8b 46 48             	mov    eax,DWORD PTR [esi+0x48]
  481ed7:	51                   	push   ecx
  481ed8:	50                   	push   eax
  481ed9:	56                   	push   esi
  481eda:	8b cd                	mov    ecx,ebp
  481edc:	e8 5f 08 00 00       	call   0x482740
  481ee1:	8b ce                	mov    ecx,esi
  481ee3:	e8 98 a1 05 00       	call   0x4dc080
  481ee8:	8b 86 0c 04 00 00    	mov    eax,DWORD PTR [esi+0x40c]
  481eee:	33 d2                	xor    edx,edx
  481ef0:	8d 48 01             	lea    ecx,[eax+0x1]
  481ef3:	85 c9                	test   ecx,ecx
  481ef5:	7e 1d                	jle    0x481f14
  481ef7:	b8 d8 bc 57 00       	mov    eax,0x57bcd8
  481efc:	8b d1                	mov    edx,ecx
  481efe:	89 78 3c             	mov    DWORD PTR [eax+0x3c],edi
  481f01:	c7 00 64 00 00 00    	mov    DWORD PTR [eax],0x64
  481f07:	05 c0 00 00 00       	add    eax,0xc0
  481f0c:	49                   	dec    ecx
  481f0d:	75 ef                	jne    0x481efe
  481f0f:	83 fa 06             	cmp    edx,0x6
  481f12:	7d 1d                	jge    0x481f31
  481f14:	8d 04 52             	lea    eax,[edx+edx*2]
  481f17:	c1 e0 06             	shl    eax,0x6
  481f1a:	05 14 bd 57 00       	add    eax,0x57bd14
  481f1f:	c7 00 00 00 00 00    	mov    DWORD PTR [eax],0x0
  481f25:	05 c0 00 00 00       	add    eax,0xc0
  481f2a:	3d 94 c1 57 00       	cmp    eax,0x57c194
  481f2f:	7c ee                	jl     0x481f1f
  481f31:	8b 0d 0c ba 57 00    	mov    ecx,DWORD PTR ds:0x57ba0c
  481f37:	e8 b4 57 0c 00       	call   0x5476f0
  481f3c:	8b 0d f4 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5f4
  481f42:	6a 00                	push   0x0
  481f44:	6a 32                	push   0x32
  481f46:	68 f7 03 00 00       	push   0x3f7
  481f4b:	e8 20 de 0a 00       	call   0x52fd70
  481f50:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  481f56:	6a 00                	push   0x0
  481f58:	e8 b3 3a 0a 00       	call   0x525a10
  481f5d:	8b cd                	mov    ecx,ebp
  481f5f:	e8 3c b4 00 00       	call   0x48d3a0
  481f64:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  481f68:	b8 10 bd 57 00       	mov    eax,0x57bd10
  481f6d:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  481f71:	eb 05                	jmp    0x481f78
  481f73:	bf 01 00 00 00       	mov    edi,0x1
  481f78:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  481f7b:	85 c9                	test   ecx,ecx
  481f7d:	0f 84 9a 03 00 00    	je     0x48231d
  481f83:	68 f0 01 00 00       	push   0x1f0
  481f88:	e8 94 c2 0c 00       	call   0x54e221
  481f8d:	83 c4 04             	add    esp,0x4
  481f90:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  481f94:	85 c0                	test   eax,eax
  481f96:	89 7c 24 60          	mov    DWORD PTR [esp+0x60],edi
  481f9a:	74 0a                	je     0x481fa6
  481f9c:	53                   	push   ebx
  481f9d:	8b c8                	mov    ecx,eax
  481f9f:	e8 0c b7 05 00       	call   0x4dd6b0
  481fa4:	eb 02                	jmp    0x481fa8
  481fa6:	33 c0                	xor    eax,eax
  481fa8:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  481fac:	8d 54 24 38          	lea    edx,[esp+0x38]
  481fb0:	83 c1 88             	add    ecx,0xffffff88
  481fb3:	c7 44 24 60 ff ff ff 	mov    DWORD PTR [esp+0x60],0xffffffff
  481fba:	ff 
  481fbb:	51                   	push   ecx
  481fbc:	68 d0 30 56 00       	push   0x5630d0
  481fc1:	52                   	push   edx
  481fc2:	89 84 9d 00 02 00 00 	mov    DWORD PTR [ebp+ebx*4+0x200],eax
  481fc9:	e8 b5 bd 0c 00       	call   0x54dd83
  481fce:	8b 84 9d 00 02 00 00 	mov    eax,DWORD PTR [ebp+ebx*4+0x200]
  481fd5:	8d 7c 24 44          	lea    edi,[esp+0x44]
  481fd9:	83 c9 ff             	or     ecx,0xffffffff
  481fdc:	83 c4 0c             	add    esp,0xc
  481fdf:	8d 50 08             	lea    edx,[eax+0x8]
  481fe2:	33 c0                	xor    eax,eax
  481fe4:	f2 ae                	repnz scas al,BYTE PTR es:[edi]
  481fe6:	f7 d1                	not    ecx
  481fe8:	2b f9                	sub    edi,ecx
  481fea:	8b c1                	mov    eax,ecx
  481fec:	8b f7                	mov    esi,edi
  481fee:	8b fa                	mov    edi,edx
  481ff0:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  481ff4:	c1 e9 02             	shr    ecx,0x2
  481ff7:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  481ff9:	8b c8                	mov    ecx,eax
  481ffb:	83 e1 03             	and    ecx,0x3
  481ffe:	f3 a4                	rep movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
  482000:	8b 84 9d 00 02 00 00 	mov    eax,DWORD PTR [ebp+ebx*4+0x200]
  482007:	85 db                	test   ebx,ebx
  482009:	89 58 48             	mov    DWORD PTR [eax+0x48],ebx
  48200c:	8b 0a                	mov    ecx,DWORD PTR [edx]
  48200e:	8b 04 8d 74 38 56 00 	mov    eax,DWORD PTR [ecx*4+0x563874]
  482015:	8b 8c 9d 00 02 00 00 	mov    ecx,DWORD PTR [ebp+ebx*4+0x200]
  48201c:	89 81 dc 01 00 00    	mov    DWORD PTR [ecx+0x1dc],eax
  482022:	8b 8c 9d 00 02 00 00 	mov    ecx,DWORD PTR [ebp+ebx*4+0x200]
  482029:	8b 42 fc             	mov    eax,DWORD PTR [edx-0x4]
  48202c:	89 81 e0 01 00 00    	mov    DWORD PTR [ecx+0x1e0],eax
  482032:	75 4f                	jne    0x482083
  482034:	a0 20 bb 57 00       	mov    al,ds:0x57bb20
  482039:	84 c0                	test   al,al
  48203b:	74 2c                	je     0x482069
  48203d:	8b 0d d8 bc 57 00    	mov    ecx,DWORD PTR ds:0x57bcd8
  482043:	b8 1f 85 eb 51       	mov    eax,0x51eb851f
  482048:	0f af 4c 24 18       	imul   ecx,DWORD PTR [esp+0x18]
  48204d:	f7 e9                	imul   ecx
  48204f:	c1 fa 05             	sar    edx,0x5
  482052:	8b c2                	mov    eax,edx
  482054:	c1 e8 1f             	shr    eax,0x1f
  482057:	03 d0                	add    edx,eax
  482059:	8b 85 00 02 00 00    	mov    eax,DWORD PTR [ebp+0x200]
  48205f:	89 54 24 1c          	mov    DWORD PTR [esp+0x1c],edx
  482063:	db 44 24 1c          	fild   DWORD PTR [esp+0x1c]
  482067:	eb 58                	jmp    0x4820c1
  482069:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  48206d:	8b 85 00 02 00 00    	mov    eax,DWORD PTR [ebp+0x200]
  482073:	8b 91 08 04 00 00    	mov    edx,DWORD PTR [ecx+0x408]
  482079:	89 54 24 1c          	mov    DWORD PTR [esp+0x1c],edx
  48207d:	db 44 24 1c          	fild   DWORD PTR [esp+0x1c]
  482081:	eb 3e                	jmp    0x4820c1
  482083:	8d 04 5b             	lea    eax,[ebx+ebx*2]
  482086:	c1 e0 06             	shl    eax,0x6
  482089:	8b 80 d8 bc 57 00    	mov    eax,DWORD PTR [eax+0x57bcd8]
  48208f:	8d 04 80             	lea    eax,[eax+eax*4]
  482092:	8d 04 80             	lea    eax,[eax+eax*4]
  482095:	8d 04 80             	lea    eax,[eax+eax*4]
  482098:	8d 04 80             	lea    eax,[eax+eax*4]
  48209b:	8d 0c 80             	lea    ecx,[eax+eax*4]
  48209e:	b8 1f 85 eb 51       	mov    eax,0x51eb851f
  4820a3:	c1 e1 04             	shl    ecx,0x4
  4820a6:	f7 e9                	imul   ecx
  4820a8:	c1 fa 05             	sar    edx,0x5
  4820ab:	8b 84 9d 00 02 00 00 	mov    eax,DWORD PTR [ebp+ebx*4+0x200]
  4820b2:	8b ca                	mov    ecx,edx
  4820b4:	c1 e9 1f             	shr    ecx,0x1f
  4820b7:	03 d1                	add    edx,ecx
  4820b9:	89 54 24 1c          	mov    DWORD PTR [esp+0x1c],edx
  4820bd:	db 44 24 1c          	fild   DWORD PTR [esp+0x1c]
  4820c1:	dd 98 08 01 00 00    	fstp   QWORD PTR [eax+0x108]
  4820c7:	68 b0 00 00 00       	push   0xb0
  4820cc:	e8 50 c1 0c 00       	call   0x54e221
  4820d1:	83 c4 04             	add    esp,0x4
  4820d4:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  4820d8:	85 c0                	test   eax,eax
  4820da:	c7 44 24 60 02 00 00 	mov    DWORD PTR [esp+0x60],0x2
  4820e1:	00 
  4820e2:	74 0b                	je     0x4820ef
  4820e4:	6a 00                	push   0x0
  4820e6:	8b c8                	mov    ecx,eax
  4820e8:	e8 f3 c7 08 00       	call   0x50e8e0
  4820ed:	eb 02                	jmp    0x4820f1
  4820ef:	33 c0                	xor    eax,eax
  4820f1:	53                   	push   ebx
  4820f2:	8b c8                	mov    ecx,eax
  4820f4:	c7 44 24 64 ff ff ff 	mov    DWORD PTR [esp+0x64],0xffffffff
  4820fb:	ff 
  4820fc:	89 84 9d 24 02 00 00 	mov    DWORD PTR [ebp+ebx*4+0x224],eax
  482103:	e8 a8 ce 08 00       	call   0x50efb0
  482108:	8b 84 9d 24 02 00 00 	mov    eax,DWORD PTR [ebp+ebx*4+0x224]
  48210f:	83 c9 ff             	or     ecx,0xffffffff
  482112:	8d 50 0c             	lea    edx,[eax+0xc]
  482115:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  482119:	8d b8 48 ff ff ff    	lea    edi,[eax-0xb8]
  48211f:	33 c0                	xor    eax,eax
  482121:	f2 ae                	repnz scas al,BYTE PTR es:[edi]
  482123:	f7 d1                	not    ecx
  482125:	2b f9                	sub    edi,ecx
  482127:	8b c1                	mov    eax,ecx
  482129:	8b f7                	mov    esi,edi
  48212b:	8b fa                	mov    edi,edx
  48212d:	c1 e9 02             	shr    ecx,0x2
  482130:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  482132:	8b c8                	mov    ecx,eax
  482134:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  482138:	83 e1 03             	and    ecx,0x3
  48213b:	f3 a4                	rep movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
  48213d:	8b 94 9d 24 02 00 00 	mov    edx,DWORD PTR [ebp+ebx*4+0x224]
  482144:	8b 48 d0             	mov    ecx,DWORD PTR [eax-0x30]
  482147:	85 db                	test   ebx,ebx
  482149:	89 4a 3c             	mov    DWORD PTR [edx+0x3c],ecx
  48214c:	8b 94 9d 24 02 00 00 	mov    edx,DWORD PTR [ebp+ebx*4+0x224]
  482153:	8b 48 d4             	mov    ecx,DWORD PTR [eax-0x2c]
  482156:	89 4a 40             	mov    DWORD PTR [edx+0x40],ecx
  482159:	8b 94 9d 24 02 00 00 	mov    edx,DWORD PTR [ebp+ebx*4+0x224]
  482160:	8b 48 d8             	mov    ecx,DWORD PTR [eax-0x28]
  482163:	89 4a 44             	mov    DWORD PTR [edx+0x44],ecx
  482166:	8b 94 9d 24 02 00 00 	mov    edx,DWORD PTR [ebp+ebx*4+0x224]
  48216d:	8b 48 dc             	mov    ecx,DWORD PTR [eax-0x24]
  482170:	89 4a 48             	mov    DWORD PTR [edx+0x48],ecx
  482173:	8b 94 9d 24 02 00 00 	mov    edx,DWORD PTR [ebp+ebx*4+0x224]
  48217a:	8b 48 e0             	mov    ecx,DWORD PTR [eax-0x20]
  48217d:	89 4a 4c             	mov    DWORD PTR [edx+0x4c],ecx
  482180:	8b 8c 9d 24 02 00 00 	mov    ecx,DWORD PTR [ebp+ebx*4+0x224]
  482187:	8b 40 e4             	mov    eax,DWORD PTR [eax-0x1c]
  48218a:	89 41 50             	mov    DWORD PTR [ecx+0x50],eax
  48218d:	75 10                	jne    0x48219f
  48218f:	8b 8d 24 02 00 00    	mov    ecx,DWORD PTR [ebp+0x224]
  482195:	e8 26 d3 08 00       	call   0x50f4c0
  48219a:	e9 03 01 00 00       	jmp    0x4822a2
  48219f:	8b 8c 9d 24 02 00 00 	mov    ecx,DWORD PTR [ebp+ebx*4+0x224]
  4821a6:	e8 15 ce 08 00       	call   0x50efc0
  4821ab:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4821af:	be 01 00 00 00       	mov    esi,0x1
  4821b4:	8b 41 cc             	mov    eax,DWORD PTR [ecx-0x34]
  4821b7:	85 c0                	test   eax,eax
  4821b9:	7d 03                	jge    0x4821be
  4821bb:	83 ce ff             	or     esi,0xffffffff
  4821be:	99                   	cdq
  4821bf:	8b f8                	mov    edi,eax
  4821c1:	33 fa                	xor    edi,edx
  4821c3:	2b fa                	sub    edi,edx
  4821c5:	85 ff                	test   edi,edi
  4821c7:	0f 8e d5 00 00 00    	jle    0x4822a2
  4821cd:	6a 05                	push   0x5
  4821cf:	6a 00                	push   0x0
  4821d1:	e8 fa 12 f8 ff       	call   0x4034d0
  4821d6:	83 c4 08             	add    esp,0x8
  4821d9:	83 f8 05             	cmp    eax,0x5
  4821dc:	0f 87 b8 00 00 00    	ja     0x48229a
  4821e2:	ff 24 85 78 25 48 00 	jmp    DWORD PTR [eax*4+0x482578]
  4821e9:	8b 8c 9d 24 02 00 00 	mov    ecx,DWORD PTR [ebp+ebx*4+0x224]
  4821f0:	8b 41 3c             	mov    eax,DWORD PTR [ecx+0x3c]
  4821f3:	03 c6                	add    eax,esi
  4821f5:	83 f8 03             	cmp    eax,0x3
  4821f8:	0f 8f 9c 00 00 00    	jg     0x48229a
  4821fe:	83 f8 fd             	cmp    eax,0xfffffffd
  482201:	0f 8c 93 00 00 00    	jl     0x48229a
  482207:	4f                   	dec    edi
  482208:	89 41 3c             	mov    DWORD PTR [ecx+0x3c],eax
  48220b:	e9 8a 00 00 00       	jmp    0x48229a
  482210:	8b 8c 9d 24 02 00 00 	mov    ecx,DWORD PTR [ebp+ebx*4+0x224]
  482217:	8b 41 40             	mov    eax,DWORD PTR [ecx+0x40]
  48221a:	03 c6                	add    eax,esi
  48221c:	83 f8 03             	cmp    eax,0x3
  48221f:	7f 79                	jg     0x48229a
  482221:	83 f8 fd             	cmp    eax,0xfffffffd
  482224:	7c 74                	jl     0x48229a
  482226:	4f                   	dec    edi
  482227:	89 41 40             	mov    DWORD PTR [ecx+0x40],eax
  48222a:	eb 6e                	jmp    0x48229a
  48222c:	8b 8c 9d 24 02 00 00 	mov    ecx,DWORD PTR [ebp+ebx*4+0x224]
  482233:	8b 41 44             	mov    eax,DWORD PTR [ecx+0x44]
  482236:	03 c6                	add    eax,esi
  482238:	83 f8 03             	cmp    eax,0x3
  48223b:	7f 5d                	jg     0x48229a
  48223d:	83 f8 fd             	cmp    eax,0xfffffffd
  482240:	7c 58                	jl     0x48229a
  482242:	4f                   	dec    edi
  482243:	89 41 44             	mov    DWORD PTR [ecx+0x44],eax
  482246:	eb 52                	jmp    0x48229a
  482248:	8b 8c 9d 24 02 00 00 	mov    ecx,DWORD PTR [ebp+ebx*4+0x224]
  48224f:	8b 41 48             	mov    eax,DWORD PTR [ecx+0x48]
  482252:	03 c6                	add    eax,esi
  482254:	83 f8 03             	cmp    eax,0x3
  482257:	7f 41                	jg     0x48229a
  482259:	83 f8 fd             	cmp    eax,0xfffffffd
  48225c:	7c 3c                	jl     0x48229a
  48225e:	4f                   	dec    edi
  48225f:	89 41 48             	mov    DWORD PTR [ecx+0x48],eax
  482262:	eb 36                	jmp    0x48229a
  482264:	8b 8c 9d 24 02 00 00 	mov    ecx,DWORD PTR [ebp+ebx*4+0x224]
  48226b:	8b 41 4c             	mov    eax,DWORD PTR [ecx+0x4c]
  48226e:	03 c6                	add    eax,esi
  482270:	83 f8 03             	cmp    eax,0x3
  482273:	7f 25                	jg     0x48229a
  482275:	83 f8 fd             	cmp    eax,0xfffffffd
  482278:	7c 20                	jl     0x48229a
  48227a:	4f                   	dec    edi
  48227b:	89 41 4c             	mov    DWORD PTR [ecx+0x4c],eax
  48227e:	eb 1a                	jmp    0x48229a
  482280:	8b 8c 9d 24 02 00 00 	mov    ecx,DWORD PTR [ebp+ebx*4+0x224]
  482287:	8b 41 50             	mov    eax,DWORD PTR [ecx+0x50]
  48228a:	03 c6                	add    eax,esi
  48228c:	83 f8 03             	cmp    eax,0x3
  48228f:	7f 09                	jg     0x48229a
  482291:	83 f8 fd             	cmp    eax,0xfffffffd
  482294:	7c 04                	jl     0x48229a
  482296:	4f                   	dec    edi
  482297:	89 41 50             	mov    DWORD PTR [ecx+0x50],eax
  48229a:	85 ff                	test   edi,edi
  48229c:	0f 8f 2b ff ff ff    	jg     0x4821cd
  4822a2:	68 28 08 00 00       	push   0x828
  4822a7:	e8 75 bf 0c 00       	call   0x54e221
  4822ac:	83 c4 04             	add    esp,0x4
  4822af:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  4822b3:	85 c0                	test   eax,eax
  4822b5:	c7 44 24 60 03 00 00 	mov    DWORD PTR [esp+0x60],0x3
  4822bc:	00 
  4822bd:	74 0d                	je     0x4822cc
  4822bf:	6a 01                	push   0x1
  4822c1:	6a ff                	push   0xffffffff
  4822c3:	8b c8                	mov    ecx,eax
  4822c5:	e8 66 14 05 00       	call   0x4d3730
  4822ca:	eb 02                	jmp    0x4822ce
  4822cc:	33 c0                	xor    eax,eax
  4822ce:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  4822d2:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  4822d6:	c7 44 24 60 ff ff ff 	mov    DWORD PTR [esp+0x60],0xffffffff
  4822dd:	ff 
  4822de:	43                   	inc    ebx
  4822df:	8d 8a 48 ff ff ff    	lea    ecx,[edx-0xb8]
  4822e5:	8b 52 e8             	mov    edx,DWORD PTR [edx-0x18]
  4822e8:	89 50 24             	mov    DWORD PTR [eax+0x24],edx
  4822eb:	8b 91 a4 00 00 00    	mov    edx,DWORD PTR [ecx+0xa4]
  4822f1:	89 50 28             	mov    DWORD PTR [eax+0x28],edx
  4822f4:	8b 91 a8 00 00 00    	mov    edx,DWORD PTR [ecx+0xa8]
  4822fa:	89 50 2c             	mov    DWORD PTR [eax+0x2c],edx
  4822fd:	8b 91 ac 00 00 00    	mov    edx,DWORD PTR [ecx+0xac]
  482303:	89 50 30             	mov    DWORD PTR [eax+0x30],edx
  482306:	8b 89 b0 00 00 00    	mov    ecx,DWORD PTR [ecx+0xb0]
  48230c:	89 48 34             	mov    DWORD PTR [eax+0x34],ecx
  48230f:	8b 94 9d 20 02 00 00 	mov    edx,DWORD PTR [ebp+ebx*4+0x220]
  482316:	89 42 04             	mov    DWORD PTR [edx+0x4],eax
  482319:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  48231d:	05 c0 00 00 00       	add    eax,0xc0
  482322:	3d 90 c1 57 00       	cmp    eax,0x57c190
  482327:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  48232b:	0f 8c 42 fc ff ff    	jl     0x481f73
  482331:	a1 40 bb 57 00       	mov    eax,ds:0x57bb40
  482336:	85 c0                	test   eax,eax
  482338:	7e 43                	jle    0x48237d
  48233a:	a0 20 bb 57 00       	mov    al,ds:0x57bb20
  48233f:	84 c0                	test   al,al
  482341:	75 3a                	jne    0x48237d
  482343:	8b 8d 24 02 00 00    	mov    ecx,DWORD PTR [ebp+0x224]
  482349:	e8 42 d2 08 00       	call   0x50f590
  48234e:	83 3d 40 bb 57 00 09 	cmp    DWORD PTR ds:0x57bb40,0x9
  482355:	75 26                	jne    0x48237d
  482357:	8b 0d 54 c2 57 00    	mov    ecx,DWORD PTR ds:0x57c254
  48235d:	b8 40 9c 00 00       	mov    eax,0x9c40
  482362:	3b c8                	cmp    ecx,eax
  482364:	7d 05                	jge    0x48236b
  482366:	a3 54 c2 57 00       	mov    ds:0x57c254,eax
  48236b:	db 05 54 c2 57 00    	fild   DWORD PTR ds:0x57c254
  482371:	8b 85 00 02 00 00    	mov    eax,DWORD PTR [ebp+0x200]
  482377:	dd 98 08 01 00 00    	fstp   QWORD PTR [eax+0x108]
  48237d:	8b 8d 90 00 00 00    	mov    ecx,DWORD PTR [ebp+0x90]
  482383:	e8 e8 4a 07 00       	call   0x4f6e70
  482388:	8b 8d 90 00 00 00    	mov    ecx,DWORD PTR [ebp+0x90]
  48238e:	e8 9d dc 07 00       	call   0x500030
  482393:	a0 20 bb 57 00       	mov    al,ds:0x57bb20
  482398:	84 c0                	test   al,al
  48239a:	0f 85 d7 00 00 00    	jne    0x482477
  4823a0:	85 f6                	test   esi,esi
  4823a2:	74 05                	je     0x4823a9
  4823a4:	8d 46 04             	lea    eax,[esi+0x4]
  4823a7:	eb 02                	jmp    0x4823ab
  4823a9:	33 c0                	xor    eax,eax
  4823ab:	8b 88 44 03 00 00    	mov    ecx,DWORD PTR [eax+0x344]
  4823b1:	51                   	push   ecx
  4823b2:	8b 8d 90 00 00 00    	mov    ecx,DWORD PTR [ebp+0x90]
  4823b8:	e8 23 d8 07 00       	call   0x4ffbe0
  4823bd:	8b 8e 0c 04 00 00    	mov    ecx,DWORD PTR [esi+0x40c]
  4823c3:	85 f6                	test   esi,esi
  4823c5:	74 05                	je     0x4823cc
  4823c7:	8d 46 04             	lea    eax,[esi+0x4]
  4823ca:	eb 02                	jmp    0x4823ce
  4823cc:	33 c0                	xor    eax,eax
  4823ce:	8b 80 3c 03 00 00    	mov    eax,DWORD PTR [eax+0x33c]
  4823d4:	83 e8 04             	sub    eax,0x4
  4823d7:	74 6f                	je     0x482448
  4823d9:	83 e8 02             	sub    eax,0x2
  4823dc:	74 39                	je     0x482417
  4823de:	83 e8 03             	sub    eax,0x3
  4823e1:	0f 85 90 00 00 00    	jne    0x482477
  4823e7:	85 c9                	test   ecx,ecx
  4823e9:	0f 8c 88 00 00 00    	jl     0x482477
  4823ef:	33 c0                	xor    eax,eax
  4823f1:	41                   	inc    ecx
  4823f2:	ba 5a 00 00 00       	mov    edx,0x5a
  4823f7:	8b b5 90 00 00 00    	mov    esi,DWORD PTR [ebp+0x90]
  4823fd:	05 68 01 00 00       	add    eax,0x168
  482402:	49                   	dec    ecx
  482403:	66 89 54 30 c0       	mov    WORD PTR [eax+esi*1-0x40],dx
  482408:	8b b5 90 00 00 00    	mov    esi,DWORD PTR [ebp+0x90]
  48240e:	66 89 54 30 c8       	mov    WORD PTR [eax+esi*1-0x38],dx
  482413:	75 e2                	jne    0x4823f7
  482415:	eb 60                	jmp    0x482477
  482417:	85 c9                	test   ecx,ecx
  482419:	7c 5c                	jl     0x482477
  48241b:	33 c0                	xor    eax,eax
  48241d:	41                   	inc    ecx
  48241e:	be 3c 00 00 00       	mov    esi,0x3c
  482423:	ba 28 00 00 00       	mov    edx,0x28
  482428:	8b bd 90 00 00 00    	mov    edi,DWORD PTR [ebp+0x90]
  48242e:	05 68 01 00 00       	add    eax,0x168
  482433:	49                   	dec    ecx
  482434:	66 89 74 38 c0       	mov    WORD PTR [eax+edi*1-0x40],si
  482439:	8b bd 90 00 00 00    	mov    edi,DWORD PTR [ebp+0x90]
  48243f:	66 89 54 38 c8       	mov    WORD PTR [eax+edi*1-0x38],dx
  482444:	75 e2                	jne    0x482428
  482446:	eb 2f                	jmp    0x482477
  482448:	85 c9                	test   ecx,ecx
  48244a:	7c 2b                	jl     0x482477
  48244c:	33 c0                	xor    eax,eax
  48244e:	41                   	inc    ecx
  48244f:	ba 1e 00 00 00       	mov    edx,0x1e
  482454:	be 14 00 00 00       	mov    esi,0x14
  482459:	8b bd 90 00 00 00    	mov    edi,DWORD PTR [ebp+0x90]
  48245f:	05 68 01 00 00       	add    eax,0x168
  482464:	49                   	dec    ecx
  482465:	66 89 54 38 c0       	mov    WORD PTR [eax+edi*1-0x40],dx
  48246a:	8b bd 90 00 00 00    	mov    edi,DWORD PTR [ebp+0x90]
  482470:	66 89 74 38 c8       	mov    WORD PTR [eax+edi*1-0x38],si
  482475:	75 e2                	jne    0x482459
  482477:	8d 73 ff             	lea    esi,[ebx-0x1]
  48247a:	89 74 24 1c          	mov    DWORD PTR [esp+0x1c],esi
  48247e:	db 44 24 1c          	fild   DWORD PTR [esp+0x1c]
  482482:	da 0d 24 bb 57 00    	fimul  DWORD PTR ds:0x57bb24
  482488:	d8 0d 50 c4 55 00    	fmul   DWORD PTR ds:0x55c450
  48248e:	d8 05 2c c3 55 00    	fadd   DWORD PTR ds:0x55c32c
  482494:	e8 a7 cc 0c 00       	call   0x54f140
  482499:	3b c3                	cmp    eax,ebx
  48249b:	7c 02                	jl     0x48249f
  48249d:	8b c6                	mov    eax,esi
  48249f:	33 c9                	xor    ecx,ecx
  4824a1:	be 01 00 00 00       	mov    esi,0x1
  4824a6:	85 db                	test   ebx,ebx
  4824a8:	7e 73                	jle    0x48251d
  4824aa:	8d 54 24 20          	lea    edx,[esp+0x20]
  4824ae:	3b c8                	cmp    ecx,eax
  4824b0:	75 08                	jne    0x4824ba
  4824b2:	c7 02 00 00 00 00    	mov    DWORD PTR [edx],0x0
  4824b8:	eb 03                	jmp    0x4824bd
  4824ba:	89 32                	mov    DWORD PTR [edx],esi
  4824bc:	46                   	inc    esi
  4824bd:	41                   	inc    ecx
  4824be:	83 c2 04             	add    edx,0x4
  4824c1:	3b cb                	cmp    ecx,ebx
  4824c3:	7c e9                	jl     0x4824ae
  4824c5:	85 db                	test   ebx,ebx
  4824c7:	7e 54                	jle    0x48251d
  4824c9:	be 32 00 00 00       	mov    esi,0x32
  4824ce:	8d 7c 24 20          	lea    edi,[esp+0x20]
  4824d2:	89 5c 24 14          	mov    DWORD PTR [esp+0x14],ebx
  4824d6:	8b 17                	mov    edx,DWORD PTR [edi]
  4824d8:	8b 8c 95 00 02 00 00 	mov    ecx,DWORD PTR [ebp+edx*4+0x200]
  4824df:	e8 0c b4 05 00       	call   0x4dd8f0
  4824e4:	8b c6                	mov    eax,esi
  4824e6:	8b 0d f4 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5f4
  4824ec:	99                   	cdq
  4824ed:	f7 fb                	idiv   ebx
  4824ef:	6a 00                	push   0x0
  4824f1:	83 c0 32             	add    eax,0x32
  4824f4:	50                   	push   eax
  4824f5:	68 f7 03 00 00       	push   0x3f7
  4824fa:	e8 71 d8 0a 00       	call   0x52fd70
  4824ff:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  482505:	6a 00                	push   0x0
  482507:	e8 04 35 0a 00       	call   0x525a10
  48250c:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  482510:	83 c6 32             	add    esi,0x32
  482513:	83 c7 04             	add    edi,0x4
  482516:	48                   	dec    eax
  482517:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  48251b:	75 b9                	jne    0x4824d6
  48251d:	8b cd                	mov    ecx,ebp
  48251f:	e8 0c a6 00 00       	call   0x48cb30
  482524:	8b 8d 40 02 00 00    	mov    ecx,DWORD PTR [ebp+0x240]
  48252a:	e8 11 ee f7 ff       	call   0x401340
  48252f:	8b 0d f4 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5f4
  482535:	6a 00                	push   0x0
  482537:	6a 64                	push   0x64
  482539:	68 f7 03 00 00       	push   0x3f7
  48253e:	e8 2d d8 0a 00       	call   0x52fd70
  482543:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  482549:	6a 00                	push   0x0
  48254b:	e8 c0 34 0a 00       	call   0x525a10
  482550:	8b cd                	mov    ecx,ebp
  482552:	e8 39 00 00 00       	call   0x482590
  482557:	8b 0d 0c ba 57 00    	mov    ecx,DWORD PTR ds:0x57ba0c
  48255d:	e8 ae 5f 0c 00       	call   0x548510
  482562:	8b 4c 24 58          	mov    ecx,DWORD PTR [esp+0x58]
  482566:	5f                   	pop    edi
  482567:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  48256e:	5e                   	pop    esi
  48256f:	5d                   	pop    ebp
  482570:	5b                   	pop    ebx
  482571:	8b e5                	mov    esp,ebp
  482573:	5d                   	pop    ebp
```

## `Game_GetStartingCapital` — `0x48d3a0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x48d3a0.c`
- Callers: `Game_InitScenario` (0x481d90)
- Callees: none resolved

- Signature: `{'call_site': '0x481f5f', 'confidence': 'derived from no stack args and RET', 'recovered': 'int __cdecl Game_GetStartingCapital(void)', 'return': 'int in EAX'}`
- Dispatch: `jump_table` None -> {'0': '0x48d3b1:1000000', '1': '0x48d3b7:500000', '2': '0x48d3bd:200000', '3': '0x48d3c3:100000', '4': '0x48d3c9:75000', '5': '0x48d3cf:50000', '6': '0x48d3d5:40000', '7': '0x48d3db:30000', '8': '0x48d3e1:25000', '9': '0x48d3e7:22000', 'default': '0x48d3ed:20000'}
- Unresolved questions: Values are exact for 0..9; all other difficulty values fall through to 20,000.

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

0048d3a0 <.text+0x8c3a0>:
  48d3a0:	a1 24 bb 57 00       	mov    eax,ds:0x57bb24
  48d3a5:	83 f8 09             	cmp    eax,0x9
  48d3a8:	77 43                	ja     0x48d3ed
  48d3aa:	ff 24 85 f4 d3 48 00 	jmp    DWORD PTR [eax*4+0x48d3f4]
  48d3b1:	b8 40 42 0f 00       	mov    eax,0xf4240
  48d3b6:	c3                   	ret
  48d3b7:	b8 20 a1 07 00       	mov    eax,0x7a120
  48d3bc:	c3                   	ret
  48d3bd:	b8 40 0d 03 00       	mov    eax,0x30d40
  48d3c2:	c3                   	ret
  48d3c3:	b8 a0 86 01 00       	mov    eax,0x186a0
  48d3c8:	c3                   	ret
  48d3c9:	b8 f8 24 01 00       	mov    eax,0x124f8
  48d3ce:	c3                   	ret
  48d3cf:	b8 50 c3 00 00       	mov    eax,0xc350
  48d3d4:	c3                   	ret
  48d3d5:	b8 40 9c 00 00       	mov    eax,0x9c40
  48d3da:	c3                   	ret
  48d3db:	b8 30 75 00 00       	mov    eax,0x7530
  48d3e0:	c3                   	ret
  48d3e1:	b8 a8 61 00 00       	mov    eax,0x61a8
  48d3e6:	c3                   	ret
  48d3e7:	b8 f0 55 00 00       	mov    eax,0x55f0
  48d3ec:	c3                   	ret
  48d3ed:	b8 20 4e 00 00       	mov    eax,0x4e20
```

## `City_Register` — `0x482740`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x482740.c`
- Callers: `Game_InitScenario` (0x481d90)
- Callees: `City_InitBuildings` (0x4d5650), `City_InitOfferSlots` (0x4d8650), `City_InitPopulation` (0x4d4a20), `List_Add` (0x4014b0), `Map_BuildOccupiedCellList` (0x4d5940), `Map_FindIndex` (0x401900)

- Signature: `{'call_site': '0x481ecd', 'confidence': 'derived from call site pushes', 'recovered': 'void __thiscall City_Register(Game *this, City *city, int population, int company_count)', 'return': 'void'}`
- Dispatch: `call` None -> ['0x4d4a20']
- Unresolved questions: City_InitPopulation internals are outside this batch; the first observed use is this+0x48 at 0x4d4a45.

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

00482740 <.text+0x81740>:
  482740:	56                   	push   esi
  482741:	8b 74 24 08          	mov    esi,DWORD PTR [esp+0x8]
  482745:	57                   	push   edi
  482746:	8d 79 04             	lea    edi,[ecx+0x4]
  482749:	56                   	push   esi
  48274a:	8b cf                	mov    ecx,edi
  48274c:	e8 5f ed f7 ff       	call   0x4014b0
  482751:	56                   	push   esi
  482752:	8b cf                	mov    ecx,edi
  482754:	e8 a7 f1 f7 ff       	call   0x401900
  482759:	8b ce                	mov    ecx,esi
  48275b:	89 86 1c 0c 00 00    	mov    DWORD PTR [esi+0xc1c],eax
  482761:	e8 ea 2e 05 00       	call   0x4d5650
  482766:	8b ce                	mov    ecx,esi
  482768:	e8 e3 5e 05 00       	call   0x4d8650
  48276d:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  482771:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  482775:	50                   	push   eax
  482776:	51                   	push   ecx
  482777:	8b ce                	mov    ecx,esi
  482779:	e8 a2 22 05 00       	call   0x4d4a20
  48277e:	8b ce                	mov    ecx,esi
  482780:	e8 bb 31 05 00       	call   0x4d5940
  482785:	5f                   	pop    edi
  482786:	5e                   	pop    esi
  482787:	c2                   	.byte 0xc2
  482788:	0c                   	.byte 0xc
```

## `City_ConstructFromName` — `0x4d44e0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x4d44e0.c`
- Callers: `Game_InitScenario` (0x481d90)
- Callees: `CityDefinition_ParseIni` (0x4db430), `FileObject_Open` (0x402cf0), `Game_RegisterWorldObject` (0x4eac80), `IsoMap_Construct` (0x4eb0f0), `List_Construct` (0x4013a0), `Map_LoadMapSprite` (0x4d4880), `Mem_Free` (0x54dd78), `Random_RangeFast` (0x4034d0), `String_Format` (0x54dd83), `Weather_SelectRandomState` (0x4dca00)

- Signature: `{'call_site': '0x481e85', 'confidence': 'derived from call site pushes and EAX capture', 'recovered': 'City *__thiscall City_ConstructFromName(City *this, const char *city_name, int unused)', 'return': 'City* in EAX'}`
- Dispatch: `call` None -> ['0x4db430'], `call` None -> ['0x4eb0f0'], `call` None -> ['0x4eac80']
- Unresolved questions: Provider signature is varargs/stack-spurious; recovered signature is from the 0x481e85 call site.; The full CityConfig field map and IsoMap loader internals are outside this batch.

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

004d44e0 <.text+0xd34e0>:
  4d44e0:	6a ff                	push   0xffffffff
  4d44e2:	68 fe 8d 55 00       	push   0x558dfe
  4d44e7:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4d44ed:	50                   	push   eax
  4d44ee:	64 89 25 00 00 00 00 	mov    DWORD PTR fs:0x0,esp
  4d44f5:	81 ec 0c 01 00 00    	sub    esp,0x10c
  4d44fb:	53                   	push   ebx
  4d44fc:	55                   	push   ebp
  4d44fd:	8b e9                	mov    ebp,ecx
  4d44ff:	33 db                	xor    ebx,ebx
  4d4501:	57                   	push   edi
  4d4502:	53                   	push   ebx
  4d4503:	8d 8d ac 0f 00 00    	lea    ecx,[ebp+0xfac]
  4d4509:	89 6c 24 14          	mov    DWORD PTR [esp+0x14],ebp
  4d450d:	e8 8e ce f2 ff       	call   0x4013a0
  4d4512:	53                   	push   ebx
  4d4513:	8d 8d c8 0f 00 00    	lea    ecx,[ebp+0xfc8]
  4d4519:	89 9c 24 24 01 00 00 	mov    DWORD PTR [esp+0x124],ebx
  4d4520:	e8 7b ce f2 ff       	call   0x4013a0
  4d4525:	8b 94 24 28 01 00 00 	mov    edx,DWORD PTR [esp+0x128]
  4d452c:	83 c9 ff             	or     ecx,0xffffffff
  4d452f:	8b fa                	mov    edi,edx
  4d4531:	33 c0                	xor    eax,eax
  4d4533:	c7 45 00 00 c5 55 00 	mov    DWORD PTR [ebp+0x0],0x55c500
  4d453a:	c6 84 24 20 01 00 00 	mov    BYTE PTR [esp+0x120],0x1
  4d4541:	01 
  4d4542:	f2 ae                	repnz scas al,BYTE PTR es:[edi]
  4d4544:	f7 d1                	not    ecx
  4d4546:	49                   	dec    ecx
  4d4547:	49                   	dec    ecx
  4d4548:	78 0c                	js     0x4d4556
  4d454a:	80 3c 11 21          	cmp    BYTE PTR [ecx+edx*1],0x21
  4d454e:	7d 06                	jge    0x4d4556
  4d4550:	88 1c 11             	mov    BYTE PTR [ecx+edx*1],bl
  4d4553:	49                   	dec    ecx
  4d4554:	79 f4                	jns    0x4d454a
  4d4556:	56                   	push   esi
  4d4557:	52                   	push   edx
  4d4558:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  4d455c:	68 80 b3 56 00       	push   0x56b380
  4d4561:	50                   	push   eax
  4d4562:	e8 1c 98 07 00       	call   0x54dd83
  4d4567:	8b 15 d8 c5 57 00    	mov    edx,DWORD PTR ds:0x57c5d8
  4d456d:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  4d4571:	51                   	push   ecx
  4d4572:	52                   	push   edx
  4d4573:	e8 b8 6e 00 00       	call   0x4db430
  4d4578:	83 c4 14             	add    esp,0x14
  4d457b:	3b c3                	cmp    eax,ebx
  4d457d:	74 14                	je     0x4d4593
  4d457f:	3b eb                	cmp    ebp,ebx
  4d4581:	74 05                	je     0x4d4588
  4d4583:	8d 7d 04             	lea    edi,[ebp+0x4]
  4d4586:	eb 02                	jmp    0x4d458a
  4d4588:	33 ff                	xor    edi,edi
  4d458a:	b9 06 03 00 00       	mov    ecx,0x306
  4d458f:	8b f0                	mov    esi,eax
  4d4591:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  4d4593:	50                   	push   eax
  4d4594:	e8 df 97 07 00       	call   0x54dd78
  4d4599:	68 c0 00 00 00       	push   0xc0
  4d459e:	6a 30                	push   0x30
  4d45a0:	89 9d ac 10 00 00    	mov    DWORD PTR [ebp+0x10ac],ebx
  4d45a6:	89 9d b0 10 00 00    	mov    DWORD PTR [ebp+0x10b0],ebx
  4d45ac:	89 9d b4 10 00 00    	mov    DWORD PTR [ebp+0x10b4],ebx
  4d45b2:	89 9d b8 10 00 00    	mov    DWORD PTR [ebp+0x10b8],ebx
  4d45b8:	89 9d c4 10 00 00    	mov    DWORD PTR [ebp+0x10c4],ebx
  4d45be:	e8 0d ef f2 ff       	call   0x4034d0
  4d45c3:	6a 60                	push   0x60
  4d45c5:	6a 18                	push   0x18
  4d45c7:	89 85 c8 10 00 00    	mov    DWORD PTR [ebp+0x10c8],eax
  4d45cd:	e8 fe ee f2 ff       	call   0x4034d0
  4d45d2:	83 c4 14             	add    esp,0x14
  4d45d5:	8b cd                	mov    ecx,ebp
  4d45d7:	89 85 cc 10 00 00    	mov    DWORD PTR [ebp+0x10cc],eax
  4d45dd:	89 9d 48 11 00 00    	mov    DWORD PTR [ebp+0x1148],ebx
  4d45e3:	89 9d 4c 11 00 00    	mov    DWORD PTR [ebp+0x114c],ebx
  4d45e9:	89 9d 54 11 00 00    	mov    DWORD PTR [ebp+0x1154],ebx
  4d45ef:	89 9d 50 11 00 00    	mov    DWORD PTR [ebp+0x1150],ebx
  4d45f5:	c7 85 bc 10 00 00 ff 	mov    DWORD PTR [ebp+0x10bc],0xffffffff
  4d45fc:	ff ff ff 
  4d45ff:	e8 fc 83 00 00       	call   0x4dca00
  4d4604:	89 9d c4 0d 00 00    	mov    DWORD PTR [ebp+0xdc4],ebx
  4d460a:	89 9d a4 10 00 00    	mov    DWORD PTR [ebp+0x10a4],ebx
  4d4610:	8d 85 b0 0c 00 00    	lea    eax,[ebp+0xcb0]
  4d4616:	8d 8d 3c 0c 00 00    	lea    ecx,[ebp+0xc3c]
  4d461c:	bf 06 00 00 00       	mov    edi,0x6
  4d4621:	ba 64 00 00 00       	mov    edx,0x64
  4d4626:	be 3c 00 00 00       	mov    esi,0x3c
  4d462b:	89 51 fc             	mov    DWORD PTR [ecx-0x4],edx
  4d462e:	89 11                	mov    DWORD PTR [ecx],edx
  4d4630:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  4d4633:	89 51 08             	mov    DWORD PTR [ecx+0x8],edx
  4d4636:	89 50 e8             	mov    DWORD PTR [eax-0x18],edx
  4d4639:	89 18                	mov    DWORD PTR [eax],ebx
  4d463b:	89 70 18             	mov    DWORD PTR [eax+0x18],esi
  4d463e:	89 90 90 00 00 00    	mov    DWORD PTR [eax+0x90],edx
  4d4644:	83 c0 04             	add    eax,0x4
  4d4647:	83 c1 10             	add    ecx,0x10
  4d464a:	4f                   	dec    edi
  4d464b:	75 de                	jne    0x4d462b
  4d464d:	b9 06 00 00 00       	mov    ecx,0x6
  4d4652:	33 c0                	xor    eax,eax
  4d4654:	8d bd ac 0d 00 00    	lea    edi,[ebp+0xdac]
  4d465a:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  4d465c:	b9 0c 00 00 00       	mov    ecx,0xc
  4d4661:	8d bd 58 0d 00 00    	lea    edi,[ebp+0xd58]
  4d4667:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  4d4669:	b9 09 00 00 00       	mov    ecx,0x9
  4d466e:	8d bd 88 0d 00 00    	lea    edi,[ebp+0xd88]
  4d4674:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  4d4676:	b9 18 00 00 00       	mov    ecx,0x18
  4d467b:	8d bd e0 0c 00 00    	lea    edi,[ebp+0xce0]
  4d4681:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  4d4683:	8d 85 d4 10 00 00    	lea    eax,[ebp+0x10d4]
  4d4689:	b9 05 00 00 00       	mov    ecx,0x5
  4d468e:	83 ca ff             	or     edx,0xffffffff
  4d4691:	89 50 fc             	mov    DWORD PTR [eax-0x4],edx
  4d4694:	89 10                	mov    DWORD PTR [eax],edx
  4d4696:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  4d4699:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  4d469c:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  4d469f:	88 58 10             	mov    BYTE PTR [eax+0x10],bl
  4d46a2:	88 58 11             	mov    BYTE PTR [eax+0x11],bl
  4d46a5:	83 c0 18             	add    eax,0x18
  4d46a8:	49                   	dec    ecx
  4d46a9:	75 e3                	jne    0x4d468e
  4d46ab:	8d b5 e4 0f 00 00    	lea    esi,[ebp+0xfe4]
  4d46b1:	c7 44 24 10 08 00 00 	mov    DWORD PTR [esp+0x10],0x8
  4d46b8:	00 
  4d46b9:	bf 06 00 00 00       	mov    edi,0x6
  4d46be:	6a 55                	push   0x55
  4d46c0:	53                   	push   ebx
  4d46c1:	e8 0a ee f2 ff       	call   0x4034d0
  4d46c6:	89 06                	mov    DWORD PTR [esi],eax
  4d46c8:	83 c4 08             	add    esp,0x8
  4d46cb:	83 c6 04             	add    esi,0x4
  4d46ce:	4f                   	dec    edi
  4d46cf:	75 ed                	jne    0x4d46be
  4d46d1:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  4d46d5:	48                   	dec    eax
  4d46d6:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  4d46da:	75 dd                	jne    0x4d46b9
  4d46dc:	8d bd 20 0c 00 00    	lea    edi,[ebp+0xc20]
  4d46e2:	b9 06 00 00 00       	mov    ecx,0x6
  4d46e7:	33 c0                	xor    eax,eax
  4d46e9:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  4d46eb:	8b 84 24 2c 01 00 00 	mov    eax,DWORD PTR [esp+0x12c]
  4d46f2:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  4d46f6:	50                   	push   eax
  4d46f7:	68 0c cd 56 00       	push   0x56cd0c
  4d46fc:	51                   	push   ecx
  4d46fd:	e8 81 96 07 00       	call   0x54dd83
  4d4702:	68 78 01 01 00       	push   0x10178
  4d4707:	e8 15 9b 07 00       	call   0x54e221
  4d470c:	83 c4 10             	add    esp,0x10
  4d470f:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  4d4713:	3b c3                	cmp    eax,ebx
  4d4715:	c6 84 24 24 01 00 00 	mov    BYTE PTR [esp+0x124],0x2
  4d471c:	02 
  4d471d:	5e                   	pop    esi
  4d471e:	74 15                	je     0x4d4735
  4d4720:	8b 0d cc c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5cc
  4d4726:	8d 54 24 14          	lea    edx,[esp+0x14]
  4d472a:	52                   	push   edx
  4d472b:	51                   	push   ecx
  4d472c:	8b c8                	mov    ecx,eax
  4d472e:	e8 bd 69 01 00       	call   0x4eb0f0
  4d4733:	eb 02                	jmp    0x4d4737
  4d4735:	33 c0                	xor    eax,eax
  4d4737:	89 85 a8 0f 00 00    	mov    DWORD PTR [ebp+0xfa8],eax
  4d473d:	8b 0d cc c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5cc
  4d4743:	6a ff                	push   0xffffffff
  4d4745:	50                   	push   eax
  4d4746:	c6 84 24 28 01 00 00 	mov    BYTE PTR [esp+0x128],0x1
  4d474d:	01 
  4d474e:	e8 2d 65 01 00       	call   0x4eac80
  4d4753:	8b 0d 10 ba 57 00    	mov    ecx,DWORD PTR ds:0x57ba10
  4d4759:	3b cb                	cmp    ecx,ebx
  4d475b:	74 06                	je     0x4d4763
  4d475d:	8b 11                	mov    edx,DWORD PTR [ecx]
  4d475f:	6a 01                	push   0x1
  4d4761:	ff 12                	call   DWORD PTR [edx]
  4d4763:	8d 45 44             	lea    eax,[ebp+0x44]
  4d4766:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  4d476a:	50                   	push   eax
  4d476b:	68 58 83 56 00       	push   0x568358
  4d4770:	51                   	push   ecx
  4d4771:	e8 0d 96 07 00       	call   0x54dd83
  4d4776:	6a 18                	push   0x18
  4d4778:	e8 a4 9a 07 00       	call   0x54e221
  4d477d:	83 c4 10             	add    esp,0x10
  4d4780:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  4d4784:	3b c3                	cmp    eax,ebx
  4d4786:	c6 84 24 20 01 00 00 	mov    BYTE PTR [esp+0x120],0x3
  4d478d:	03 
  4d478e:	74 16                	je     0x4d47a6
  4d4790:	8b 0d d8 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5d8
  4d4796:	8d 54 24 14          	lea    edx,[esp+0x14]
  4d479a:	53                   	push   ebx
  4d479b:	52                   	push   edx
  4d479c:	51                   	push   ecx
  4d479d:	8b c8                	mov    ecx,eax
  4d479f:	e8 4c e5 f2 ff       	call   0x402cf0
  4d47a4:	eb 02                	jmp    0x4d47a8
  4d47a6:	33 c0                	xor    eax,eax
  4d47a8:	8b cd                	mov    ecx,ebp
  4d47aa:	c6 84 24 20 01 00 00 	mov    BYTE PTR [esp+0x120],0x1
  4d47b1:	01 
  4d47b2:	a3 10 ba 57 00       	mov    ds:0x57ba10,eax
  4d47b7:	e8 c4 00 00 00       	call   0x4d4880
  4d47bc:	8b 8c 24 18 01 00 00 	mov    ecx,DWORD PTR [esp+0x118]
  4d47c3:	8b c5                	mov    eax,ebp
  4d47c5:	5f                   	pop    edi
  4d47c6:	5d                   	pop    ebp
  4d47c7:	5b                   	pop    ebx
  4d47c8:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4d47cf:	81 c4 18 01 00 00    	add    esp,0x118
  4d47d5:	c2                   	.byte 0xc2
  4d47d6:	08                   	.byte 0x8
```

## `Settings_InitDefaults` — `0x406a90`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x406a90.c`
- Callers: `WinMain` (0x403d90)
- Callees: `Random_RangeFast` (0x4034d0), `Settings_LoadFromRegistry` (0x406bb0)

- Signature: `{'call_site': 'startup settings path', 'confidence': 'derived from no stack args and RET', 'recovered': 'void __cdecl Settings_InitDefaults(void)', 'return': 'void'}`
- Dispatch: `call` None -> ['0x406bb0']
- Unresolved questions: The registry-loaded branch can overwrite the fresh-path defaults; this packet records the no-registry path.

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

00406a90 <.text+0x5a90>:
  406a90:	57                   	push   edi
  406a91:	b9 59 00 00 00       	mov    ecx,0x59
  406a96:	33 c0                	xor    eax,eax
  406a98:	bf a8 b8 57 00       	mov    edi,0x57b8a8
  406a9d:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  406a9f:	e8 0c 01 00 00       	call   0x406bb0
  406aa4:	85 c0                	test   eax,eax
  406aa6:	0f 85 fa 00 00 00    	jne    0x406ba6
  406aac:	56                   	push   esi
  406aad:	bf 01 00 00 00       	mov    edi,0x1
  406ab2:	33 f6                	xor    esi,esi
  406ab4:	57                   	push   edi
  406ab5:	56                   	push   esi
  406ab6:	c7 05 f0 b9 57 00 05 	mov    DWORD PTR ds:0x57b9f0,0x5
  406abd:	00 00 00 
  406ac0:	c7 05 f8 b9 57 00 04 	mov    DWORD PTR ds:0x57b9f8,0x4
  406ac7:	00 00 00 
  406aca:	89 35 fc b9 57 00    	mov    DWORD PTR ds:0x57b9fc,esi
  406ad0:	89 35 f4 b9 57 00    	mov    DWORD PTR ds:0x57b9f4,esi
  406ad6:	e8 f5 c9 ff ff       	call   0x4034d0
  406adb:	a3 38 b9 57 00       	mov    ds:0x57b938,eax
  406ae0:	a1 7c 55 58 00       	mov    eax,ds:0x58557c
  406ae5:	48                   	dec    eax
  406ae6:	50                   	push   eax
  406ae7:	56                   	push   esi
  406ae8:	e8 e3 c9 ff ff       	call   0x4034d0
  406aed:	8b 0d 80 55 58 00    	mov    ecx,DWORD PTR ds:0x585580
  406af3:	a3 3c b9 57 00       	mov    ds:0x57b93c,eax
  406af8:	49                   	dec    ecx
  406af9:	51                   	push   ecx
  406afa:	56                   	push   esi
  406afb:	e8 d0 c9 ff ff       	call   0x4034d0
  406b00:	8b 15 84 55 58 00    	mov    edx,DWORD PTR ds:0x585584
  406b06:	a3 40 b9 57 00       	mov    ds:0x57b940,eax
  406b0b:	4a                   	dec    edx
  406b0c:	52                   	push   edx
  406b0d:	56                   	push   esi
  406b0e:	e8 bd c9 ff ff       	call   0x4034d0
  406b13:	a3 44 b9 57 00       	mov    ds:0x57b944,eax
  406b18:	a1 88 55 58 00       	mov    eax,ds:0x585588
  406b1d:	48                   	dec    eax
  406b1e:	50                   	push   eax
  406b1f:	56                   	push   esi
  406b20:	e8 ab c9 ff ff       	call   0x4034d0
  406b25:	83 c4 28             	add    esp,0x28
  406b28:	a3 48 b9 57 00       	mov    ds:0x57b948,eax
  406b2d:	83 c8 ff             	or     eax,0xffffffff
  406b30:	c7 05 c8 b9 57 00 fa 	mov    DWORD PTR ds:0x57b9c8,0xfa
  406b37:	00 00 00 
  406b3a:	a3 d0 b9 57 00       	mov    ds:0x57b9d0,eax
  406b3f:	a3 d4 b9 57 00       	mov    ds:0x57b9d4,eax
  406b44:	a3 d8 b9 57 00       	mov    ds:0x57b9d8,eax
  406b49:	c7 05 cc b9 57 00 0b 	mov    DWORD PTR ds:0x57b9cc,0xb
  406b50:	00 00 00 
  406b53:	89 3d 64 b9 57 00    	mov    DWORD PTR ds:0x57b964,edi
  406b59:	89 35 68 b9 57 00    	mov    DWORD PTR ds:0x57b968,esi
  406b5f:	89 3d 6c b9 57 00    	mov    DWORD PTR ds:0x57b96c,edi
  406b65:	89 3d 70 b9 57 00    	mov    DWORD PTR ds:0x57b970,edi
  406b6b:	c7 05 dc b9 57 00 03 	mov    DWORD PTR ds:0x57b9dc,0x3
  406b72:	00 00 00 
  406b75:	c7 05 78 b9 57 00 06 	mov    DWORD PTR ds:0x57b978,0x6
  406b7c:	00 00 00 
  406b7f:	b8 ac b9 57 00       	mov    eax,0x57b9ac
  406b84:	b9 64 00 00 00       	mov    ecx,0x64
  406b89:	33 d2                	xor    edx,edx
  406b8b:	3d b4 b9 57 00       	cmp    eax,0x57b9b4
  406b90:	89 48 d0             	mov    DWORD PTR [eax-0x30],ecx
  406b93:	89 70 e8             	mov    DWORD PTR [eax-0x18],esi
  406b96:	0f 9c c2             	setl   dl
  406b99:	89 10                	mov    DWORD PTR [eax],edx
  406b9b:	83 c0 04             	add    eax,0x4
  406b9e:	3d c4 b9 57 00       	cmp    eax,0x57b9c4
  406ba3:	7c e4                	jl     0x406b89
  406ba5:	5e                   	pop    esi
  406ba6:	5f                   	pop    edi
```

