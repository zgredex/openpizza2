# Function batch packet

## `AI_Action_BuyOrRentBranch` — `0x4f7ed0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x4f7ed0.c`
- Callers: `Company_ExecuteAction` (0x5016c0)
- Callees: `AI_ComputePlanScores` (0x4f7b90), `AI_FindBestBranchSite` (0x4f8240), `DebugConsole_Printf` (0x54a660), `Game_CanAfford` (0x477e40), `Game_ComputeTradeOffers` (0x4d5dd0), `Game_GetPlayerCity` (0x4ddcc0), `Game_SumPlayerAssetValue` (0x4f7a50), `Game_UpdateCompanyAdvancementScore` (0x4f8bf0), `IDMap_Lookup` (0x4017f0), `IsSpecialIdRange` (0x4d2e40), `Map_PickObject` (0x4f7920), `Player_CreateBranch` (0x4f7420)

- Unresolved questions: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

004f7ed0 <.text+0xf6ed0>:
  4f7ed0:	83 ec 58             	sub    esp,0x58
  4f7ed3:	8b 44 24 5c          	mov    eax,DWORD PTR [esp+0x5c]
  4f7ed7:	53                   	push   ebx
  4f7ed8:	8b d9                	mov    ebx,ecx
  4f7eda:	55                   	push   ebp
  4f7edb:	8d 04 80             	lea    eax,[eax+eax*4]
  4f7ede:	56                   	push   esi
  4f7edf:	57                   	push   edi
  4f7ee0:	c7 44 24 10 00 00 00 	mov    DWORD PTR [esp+0x10],0x0
  4f7ee7:	00 
  4f7ee8:	8d 04 c0             	lea    eax,[eax+eax*8]
  4f7eeb:	8b 6c c3 70          	mov    ebp,DWORD PTR [ebx+eax*8+0x70]
  4f7eef:	8b 8c c3 34 01 00 00 	mov    ecx,DWORD PTR [ebx+eax*8+0x134]
  4f7ef6:	8d 34 c3             	lea    esi,[ebx+eax*8]
  4f7ef9:	89 6c 24 2c          	mov    DWORD PTR [esp+0x2c],ebp
  4f7efd:	8b bd 5c 01 00 00    	mov    edi,DWORD PTR [ebp+0x15c]
  4f7f03:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4f7f07:	83 ff 14             	cmp    edi,0x14
  4f7f0a:	89 4c 24 24          	mov    DWORD PTR [esp+0x24],ecx
  4f7f0e:	0f 8d 14 03 00 00    	jge    0x4f8228
  4f7f14:	85 ff                	test   edi,edi
  4f7f16:	0f 8e ac 00 00 00    	jle    0x4f7fc8
  4f7f1c:	8b cd                	mov    ecx,ebp
  4f7f1e:	e8 9d 5d fe ff       	call   0x4ddcc0
  4f7f23:	8b 56 40             	mov    edx,DWORD PTR [esi+0x40]
  4f7f26:	8b cb                	mov    ecx,ebx
  4f7f28:	52                   	push   edx
  4f7f29:	e8 22 fb ff ff       	call   0x4f7a50
  4f7f2e:	8b b6 34 01 00 00    	mov    esi,DWORD PTR [esi+0x134]
  4f7f34:	33 c9                	xor    ecx,ecx
  4f7f36:	2b f0                	sub    esi,eax
  4f7f38:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  4f7f3c:	99                   	cdq
  4f7f3d:	f7 ff                	idiv   edi
  4f7f3f:	3b f9                	cmp    edi,ecx
  4f7f41:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4f7f45:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  4f7f49:	0f 8e 95 00 00 00    	jle    0x4f7fe4
  4f7f4f:	81 c5 48 01 00 00    	add    ebp,0x148
  4f7f55:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4f7f59:	6a 00                	push   0x0
  4f7f5b:	50                   	push   eax
  4f7f5c:	8b cd                	mov    ecx,ebp
  4f7f5e:	e8 8d 98 f0 ff       	call   0x4017f0
  4f7f63:	85 c0                	test   eax,eax
  4f7f65:	74 52                	je     0x4f7fb9
  4f7f67:	8b 88 f0 16 00 00    	mov    ecx,DWORD PTR [eax+0x16f0]
  4f7f6d:	8b 51 38             	mov    edx,DWORD PTR [ecx+0x38]
  4f7f70:	85 d2                	test   edx,edx
  4f7f72:	74 04                	je     0x4f7f78
  4f7f74:	ff 44 24 18          	inc    DWORD PTR [esp+0x18]
  4f7f78:	8b 50 38             	mov    edx,DWORD PTR [eax+0x38]
  4f7f7b:	83 c9 ff             	or     ecx,0xffffffff
  4f7f7e:	2b ca                	sub    ecx,edx
  4f7f80:	6a 04                	push   0x4
  4f7f82:	8d 0c 89             	lea    ecx,[ecx+ecx*4]
  4f7f85:	8d 0c 89             	lea    ecx,[ecx+ecx*4]
  4f7f88:	8d 0c 89             	lea    ecx,[ecx+ecx*4]
  4f7f8b:	8d 14 89             	lea    edx,[ecx+ecx*4]
  4f7f8e:	8d 4c 24 34          	lea    ecx,[esp+0x34]
  4f7f92:	c1 e2 05             	shl    edx,0x5
  4f7f95:	03 f2                	add    esi,edx
  4f7f97:	8d 54 24 20          	lea    edx,[esp+0x20]
  4f7f9b:	51                   	push   ecx
  4f7f9c:	52                   	push   edx
  4f7f9d:	50                   	push   eax
  4f7f9e:	8b cb                	mov    ecx,ebx
  4f7fa0:	e8 eb fb ff ff       	call   0x4f7b90
  4f7fa5:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  4f7fa9:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  4f7fad:	2b c8                	sub    ecx,eax
  4f7faf:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  4f7fb3:	79 04                	jns    0x4f7fb9
  4f7fb5:	ff 44 24 10          	inc    DWORD PTR [esp+0x10]
  4f7fb9:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4f7fbd:	40                   	inc    eax
  4f7fbe:	3b c7                	cmp    eax,edi
  4f7fc0:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4f7fc4:	7c 8f                	jl     0x4f7f55
  4f7fc6:	eb 04                	jmp    0x4f7fcc
  4f7fc8:	8b 74 24 6c          	mov    esi,DWORD PTR [esp+0x6c]
  4f7fcc:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  4f7fd0:	85 c0                	test   eax,eax
  4f7fd2:	0f 8f 50 02 00 00    	jg     0x4f8228
  4f7fd8:	85 ff                	test   edi,edi
  4f7fda:	7e 08                	jle    0x4f7fe4
  4f7fdc:	85 f6                	test   esi,esi
  4f7fde:	0f 8c 44 02 00 00    	jl     0x4f8228
  4f7fe4:	be 01 00 00 00       	mov    esi,0x1
  4f7fe9:	3b fe                	cmp    edi,esi
  4f7feb:	7e 1f                	jle    0x4f800c
  4f7fed:	83 ff 04             	cmp    edi,0x4
  4f7ff0:	7d 08                	jge    0x4f7ffa
  4f7ff2:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  4f7ff6:	85 c0                	test   eax,eax
  4f7ff8:	7f 06                	jg     0x4f8000
  4f7ffa:	39 74 24 10          	cmp    DWORD PTR [esp+0x10],esi
  4f7ffe:	7e 0c                	jle    0x4f800c
  4f8000:	8b c6                	mov    eax,esi
  4f8002:	5f                   	pop    edi
  4f8003:	5e                   	pop    esi
  4f8004:	5d                   	pop    ebp
  4f8005:	5b                   	pop    ebx
  4f8006:	83 c4 58             	add    esp,0x58
  4f8009:	c2 04 00             	ret    0x4
  4f800c:	83 ff 0a             	cmp    edi,0xa
  4f800f:	7c 0c                	jl     0x4f801d
  4f8011:	8b 4c 24 6c          	mov    ecx,DWORD PTR [esp+0x6c]
  4f8015:	51                   	push   ecx
  4f8016:	8b cb                	mov    ecx,ebx
  4f8018:	e8 03 f9 ff ff       	call   0x4f7920
  4f801d:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4f8022:	6a 00                	push   0x0
  4f8024:	8b 90 f4 02 00 00    	mov    edx,DWORD PTR [eax+0x2f4]
  4f802a:	8d 48 04             	lea    ecx,[eax+0x4]
  4f802d:	52                   	push   edx
  4f802e:	e8 bd 97 f0 ff       	call   0x4017f0
  4f8033:	8b 7c 24 6c          	mov    edi,DWORD PTR [esp+0x6c]
  4f8037:	8b e8                	mov    ebp,eax
  4f8039:	8d 44 24 58          	lea    eax,[esp+0x58]
  4f803d:	8b cb                	mov    ecx,ebx
  4f803f:	50                   	push   eax
  4f8040:	6a 00                	push   0x0
  4f8042:	55                   	push   ebp
  4f8043:	57                   	push   edi
  4f8044:	e8 f7 01 00 00       	call   0x4f8240
  4f8049:	85 c0                	test   eax,eax
  4f804b:	89 44 24 54          	mov    DWORD PTR [esp+0x54],eax
  4f804f:	74 21                	je     0x4f8072
  4f8051:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  4f8055:	6a 00                	push   0x0
  4f8057:	8b 51 40             	mov    edx,DWORD PTR [ecx+0x40]
  4f805a:	8d 4c 24 64          	lea    ecx,[esp+0x64]
  4f805e:	52                   	push   edx
  4f805f:	8d 54 24 64          	lea    edx,[esp+0x64]
  4f8063:	51                   	push   ecx
  4f8064:	52                   	push   edx
  4f8065:	56                   	push   esi
  4f8066:	50                   	push   eax
  4f8067:	8b cd                	mov    ecx,ebp
  4f8069:	e8 62 dd fd ff       	call   0x4d5dd0
  4f806e:	89 44 24 64          	mov    DWORD PTR [esp+0x64],eax
  4f8072:	8d 44 24 44          	lea    eax,[esp+0x44]
  4f8076:	8b cb                	mov    ecx,ebx
  4f8078:	50                   	push   eax
  4f8079:	56                   	push   esi
  4f807a:	55                   	push   ebp
  4f807b:	57                   	push   edi
  4f807c:	e8 bf 01 00 00       	call   0x4f8240
  4f8081:	85 c0                	test   eax,eax
  4f8083:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  4f8087:	74 39                	je     0x4f80c2
  4f8089:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  4f808d:	6a 00                	push   0x0
  4f808f:	8b 51 40             	mov    edx,DWORD PTR [ecx+0x40]
  4f8092:	8d 4c 24 50          	lea    ecx,[esp+0x50]
  4f8096:	52                   	push   edx
  4f8097:	8d 54 24 50          	lea    edx,[esp+0x50]
  4f809b:	51                   	push   ecx
  4f809c:	52                   	push   edx
  4f809d:	56                   	push   esi
  4f809e:	50                   	push   eax
  4f809f:	8b cd                	mov    ecx,ebp
  4f80a1:	e8 2a dd fd ff       	call   0x4d5dd0
  4f80a6:	8b 4c 24 4c          	mov    ecx,DWORD PTR [esp+0x4c]
  4f80aa:	89 44 24 50          	mov    DWORD PTR [esp+0x50],eax
  4f80ae:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  4f80b2:	3b c8                	cmp    ecx,eax
  4f80b4:	7e 08                	jle    0x4f80be
  4f80b6:	33 c0                	xor    eax,eax
  4f80b8:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  4f80bc:	eb 04                	jmp    0x4f80c2
  4f80be:	8b 44 24 40          	mov    eax,DWORD PTR [esp+0x40]
  4f80c2:	8b 4c 24 54          	mov    ecx,DWORD PTR [esp+0x54]
  4f80c6:	85 c9                	test   ecx,ecx
  4f80c8:	75 13                	jne    0x4f80dd
  4f80ca:	85 c0                	test   eax,eax
  4f80cc:	75 3d                	jne    0x4f810b
  4f80ce:	5f                   	pop    edi
  4f80cf:	5e                   	pop    esi
  4f80d0:	5d                   	pop    ebp
  4f80d1:	b8 03 00 00 00       	mov    eax,0x3
  4f80d6:	5b                   	pop    ebx
  4f80d7:	83 c4 58             	add    esp,0x58
  4f80da:	c2 04 00             	ret    0x4
  4f80dd:	85 c0                	test   eax,eax
  4f80df:	8d 7c 24 54          	lea    edi,[esp+0x54]
  4f80e3:	c7 44 24 10 00 00 00 	mov    DWORD PTR [esp+0x10],0x0
  4f80ea:	00 
  4f80eb:	74 26                	je     0x4f8113
  4f80ed:	8b 4c 24 58          	mov    ecx,DWORD PTR [esp+0x58]
  4f80f1:	8b 44 24 44          	mov    eax,DWORD PTR [esp+0x44]
  4f80f5:	8d 14 09             	lea    edx,[ecx+ecx*1]
  4f80f8:	3b c2                	cmp    eax,edx
  4f80fa:	7e 17                	jle    0x4f8113
  4f80fc:	8b 44 24 48          	mov    eax,DWORD PTR [esp+0x48]
  4f8100:	8d 0c 00             	lea    ecx,[eax+eax*1]
  4f8103:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  4f8107:	3b c1                	cmp    eax,ecx
  4f8109:	7e 08                	jle    0x4f8113
  4f810b:	8d 7c 24 40          	lea    edi,[esp+0x40]
  4f810f:	89 74 24 10          	mov    DWORD PTR [esp+0x10],esi
  4f8113:	8b 54 24 6c          	mov    edx,DWORD PTR [esp+0x6c]
  4f8117:	8b cb                	mov    ecx,ebx
  4f8119:	52                   	push   edx
  4f811a:	e8 d1 0a 00 00       	call   0x4f8bf0
  4f811f:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4f8121:	e8 1a ad fd ff       	call   0x4d2e40
  4f8126:	85 c0                	test   eax,eax
  4f8128:	74 14                	je     0x4f813e
  4f812a:	8b 07                	mov    eax,DWORD PTR [edi]
  4f812c:	8b 70 20             	mov    esi,DWORD PTR [eax+0x20]
  4f812f:	81 ee 4c 08 00 00    	sub    esi,0x84c
  4f8135:	c1 fe 02             	sar    esi,0x2
  4f8138:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  4f813c:	eb 0c                	jmp    0x4f814a
  4f813e:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  4f8145:	00 
  4f8146:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  4f814a:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  4f814e:	8b 85 1c 0c 00 00    	mov    eax,DWORD PTR [ebp+0xc1c]
  4f8154:	33 c9                	xor    ecx,ecx
  4f8156:	85 d2                	test   edx,edx
  4f8158:	8b 54 24 6c          	mov    edx,DWORD PTR [esp+0x6c]
  4f815c:	0f 94 c1             	sete   cl
  4f815f:	51                   	push   ecx
  4f8160:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4f8162:	56                   	push   esi
  4f8163:	52                   	push   edx
  4f8164:	51                   	push   ecx
  4f8165:	50                   	push   eax
  4f8166:	8b cb                	mov    ecx,ebx
  4f8168:	e8 b3 f2 ff ff       	call   0x4f7420
  4f816d:	8b 54 24 2c          	mov    edx,DWORD PTR [esp+0x2c]
  4f8171:	6a 00                	push   0x0
  4f8173:	50                   	push   eax
  4f8174:	8d 8a 48 01 00 00    	lea    ecx,[edx+0x148]
  4f817a:	e8 71 96 f0 ff       	call   0x4017f0
  4f817f:	8b f0                	mov    esi,eax
  4f8181:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  4f8185:	85 c0                	test   eax,eax
  4f8187:	75 3b                	jne    0x4f81c4
  4f8189:	c6 86 f4 16 00 00 00 	mov    BYTE PTR [esi+0x16f4],0x0
  4f8190:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  4f8193:	89 86 b0 14 00 00    	mov    DWORD PTR [esi+0x14b0],eax
  4f8199:	6a ff                	push   0xffffffff
  4f819b:	db 47 08             	fild   DWORD PTR [edi+0x8]
  4f819e:	6a 00                	push   0x0
  4f81a0:	51                   	push   ecx
  4f81a1:	8b ce                	mov    ecx,esi
  4f81a3:	d9 1c 24             	fstp   DWORD PTR [esp]
  4f81a6:	6a 01                	push   0x1
  4f81a8:	e8 93 fc f7 ff       	call   0x477e40
  4f81ad:	8b 0d e0 c1 57 00    	mov    ecx,DWORD PTR ds:0x57c1e0
  4f81b3:	83 c6 04             	add    esi,0x4
  4f81b6:	56                   	push   esi
  4f81b7:	68 ec 1e 57 00       	push   0x571eec
  4f81bc:	68 ff 00 00 00       	push   0xff
  4f81c1:	51                   	push   ecx
  4f81c2:	eb 5c                	jmp    0x4f8220
  4f81c4:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  4f81c8:	c6 86 f4 16 00 00 01 	mov    BYTE PTR [esi+0x16f4],0x1
  4f81cf:	42                   	inc    edx
  4f81d0:	89 54 24 6c          	mov    DWORD PTR [esp+0x6c],edx
  4f81d4:	db 44 24 6c          	fild   DWORD PTR [esp+0x6c]
  4f81d8:	d8 8d 94 00 00 00    	fmul   DWORD PTR [ebp+0x94]
  4f81de:	d8 0d 5c c5 55 00    	fmul   DWORD PTR ds:0x55c55c
  4f81e4:	e8 57 6f 05 00       	call   0x54f140
  4f81e9:	89 86 b0 14 00 00    	mov    DWORD PTR [esi+0x14b0],eax
  4f81ef:	8b 07                	mov    eax,DWORD PTR [edi]
  4f81f1:	8b 4f 0c             	mov    ecx,DWORD PTR [edi+0xc]
  4f81f4:	6a ff                	push   0xffffffff
  4f81f6:	89 48 3c             	mov    DWORD PTR [eax+0x3c],ecx
  4f81f9:	6a 00                	push   0x0
  4f81fb:	db 47 0c             	fild   DWORD PTR [edi+0xc]
  4f81fe:	51                   	push   ecx
  4f81ff:	8b ce                	mov    ecx,esi
  4f8201:	d9 1c 24             	fstp   DWORD PTR [esp]
  4f8204:	6a 02                	push   0x2
  4f8206:	e8 35 fc f7 ff       	call   0x477e40
  4f820b:	8b 15 e0 c1 57 00    	mov    edx,DWORD PTR ds:0x57c1e0
  4f8211:	83 c6 04             	add    esi,0x4
  4f8214:	56                   	push   esi
  4f8215:	68 d4 1e 57 00       	push   0x571ed4
  4f821a:	68 ff 00 00 00       	push   0xff
  4f821f:	52                   	push   edx
  4f8220:	e8 3b 24 05 00       	call   0x54a660
  4f8225:	83 c4 10             	add    esp,0x10
  4f8228:	5f                   	pop    edi
  4f8229:	5e                   	pop    esi
  4f822a:	5d                   	pop    ebp
  4f822b:	b8 01 00 00 00       	mov    eax,0x1
  4f8230:	5b                   	pop    ebx
  4f8231:	83 c4 58             	add    esp,0x58
  4f8234:	c2                   	.byte 0xc2
  4f8235:	04                   	.byte 0x4
```

## `Company_OpenStartingBranch` — `0x4f8a80`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x4f8a80.c`
- Callers: `Company_PlaceScenarioBranches` (0x4dc0f0)
- Callees: `AI_FindBestBranchSite` (0x4f8240), `Branch_ValidateMenuAndRecalculate` (0x4f7c30), `Customer_VisitBranch` (0x4fb660), `DebugConsole_Printf` (0x54a660), `Game_ComputeTradeOffers` (0x4d5dd0), `IDMap_Lookup` (0x4017f0), `Player_CreateBranch` (0x4f7420)

- Unresolved questions: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

004f8a80 <.text+0xf7a80>:
  4f8a80:	83 ec 10             	sub    esp,0x10
  4f8a83:	53                   	push   ebx
  4f8a84:	8b 5c 24 18          	mov    ebx,DWORD PTR [esp+0x18]
  4f8a88:	55                   	push   ebp
  4f8a89:	56                   	push   esi
  4f8a8a:	8d 04 9b             	lea    eax,[ebx+ebx*4]
  4f8a8d:	57                   	push   edi
  4f8a8e:	8b f9                	mov    edi,ecx
  4f8a90:	6a 00                	push   0x0
  4f8a92:	8d 04 c0             	lea    eax,[eax+eax*8]
  4f8a95:	8b 4c c7 70          	mov    ecx,DWORD PTR [edi+eax*8+0x70]
  4f8a99:	8d 04 c7             	lea    eax,[edi+eax*8]
  4f8a9c:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4f8aa0:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4f8aa5:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  4f8aa9:	8b 90 f4 02 00 00    	mov    edx,DWORD PTR [eax+0x2f4]
  4f8aaf:	8d 48 04             	lea    ecx,[eax+0x4]
  4f8ab2:	52                   	push   edx
  4f8ab3:	e8 38 8d f0 ff       	call   0x4017f0
  4f8ab8:	8b f0                	mov    esi,eax
  4f8aba:	85 f6                	test   esi,esi
  4f8abc:	75 0a                	jne    0x4f8ac8
  4f8abe:	5f                   	pop    edi
  4f8abf:	5e                   	pop    esi
  4f8ac0:	5d                   	pop    ebp
  4f8ac1:	5b                   	pop    ebx
  4f8ac2:	83 c4 10             	add    esp,0x10
  4f8ac5:	c2 10 00             	ret    0x10
  4f8ac8:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  4f8acc:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  4f8ad0:	50                   	push   eax
  4f8ad1:	51                   	push   ecx
  4f8ad2:	56                   	push   esi
  4f8ad3:	53                   	push   ebx
  4f8ad4:	8b cf                	mov    ecx,edi
  4f8ad6:	e8 65 f7 ff ff       	call   0x4f8240
  4f8adb:	8b e8                	mov    ebp,eax
  4f8add:	85 ed                	test   ebp,ebp
  4f8adf:	75 0a                	jne    0x4f8aeb
  4f8ae1:	5f                   	pop    edi
  4f8ae2:	5e                   	pop    esi
  4f8ae3:	5d                   	pop    ebp
  4f8ae4:	5b                   	pop    ebx
  4f8ae5:	83 c4 10             	add    esp,0x10
  4f8ae8:	c2 10 00             	ret    0x10
  4f8aeb:	83 7c 24 28 ff       	cmp    DWORD PTR [esp+0x28],0xffffffff
  4f8af0:	75 08                	jne    0x4f8afa
  4f8af2:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  4f8af9:	00 
  4f8afa:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  4f8afe:	6a 00                	push   0x0
  4f8b00:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  4f8b04:	8b 42 40             	mov    eax,DWORD PTR [edx+0x40]
  4f8b07:	8d 54 24 28          	lea    edx,[esp+0x28]
  4f8b0b:	50                   	push   eax
  4f8b0c:	51                   	push   ecx
  4f8b0d:	52                   	push   edx
  4f8b0e:	6a 01                	push   0x1
  4f8b10:	55                   	push   ebp
  4f8b11:	8b ce                	mov    ecx,esi
  4f8b13:	e8 b8 d2 fd ff       	call   0x4d5dd0
  4f8b18:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  4f8b1c:	8b b6 1c 0c 00 00    	mov    esi,DWORD PTR [esi+0xc1c]
  4f8b22:	6a 01                	push   0x1
  4f8b24:	50                   	push   eax
  4f8b25:	53                   	push   ebx
  4f8b26:	55                   	push   ebp
  4f8b27:	56                   	push   esi
  4f8b28:	8b cf                	mov    ecx,edi
  4f8b2a:	e8 f1 e8 ff ff       	call   0x4f7420
  4f8b2f:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  4f8b33:	6a 00                	push   0x0
  4f8b35:	50                   	push   eax
  4f8b36:	81 c1 48 01 00 00    	add    ecx,0x148
  4f8b3c:	e8 af 8c f0 ff       	call   0x4017f0
  4f8b41:	8b f0                	mov    esi,eax
  4f8b43:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  4f8b47:	85 c0                	test   eax,eax
  4f8b49:	74 45                	je     0x4f8b90
  4f8b4b:	c6 86 f4 16 00 00 01 	mov    BYTE PTR [esi+0x16f4],0x1
  4f8b52:	8b 54 24 24          	mov    edx,DWORD PTR [esp+0x24]
  4f8b56:	c1 fa 02             	sar    edx,0x2
  4f8b59:	89 96 b0 14 00 00    	mov    DWORD PTR [esi+0x14b0],edx
  4f8b5f:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  4f8b63:	8d 4e 04             	lea    ecx,[esi+0x4]
  4f8b66:	89 45 3c             	mov    DWORD PTR [ebp+0x3c],eax
  4f8b69:	8b 15 e0 c1 57 00    	mov    edx,DWORD PTR ds:0x57c1e0
  4f8b6f:	51                   	push   ecx
  4f8b70:	68 24 1f 57 00       	push   0x571f24
  4f8b75:	68 ff 00 00 00       	push   0xff
  4f8b7a:	52                   	push   edx
  4f8b7b:	e8 e0 1a 05 00       	call   0x54a660
  4f8b80:	8b 44 24 40          	mov    eax,DWORD PTR [esp+0x40]
  4f8b84:	83 c4 10             	add    esp,0x10
  4f8b87:	6a ff                	push   0xffffffff
  4f8b89:	6a ff                	push   0xffffffff
  4f8b8b:	6a ff                	push   0xffffffff
  4f8b8d:	50                   	push   eax
  4f8b8e:	eb 38                	jmp    0x4f8bc8
  4f8b90:	c6 86 f4 16 00 00 00 	mov    BYTE PTR [esi+0x16f4],0x0
  4f8b97:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  4f8b9b:	8d 56 04             	lea    edx,[esi+0x4]
  4f8b9e:	89 8e b0 14 00 00    	mov    DWORD PTR [esi+0x14b0],ecx
  4f8ba4:	a1 e0 c1 57 00       	mov    eax,ds:0x57c1e0
  4f8ba9:	52                   	push   edx
  4f8baa:	68 04 1f 57 00       	push   0x571f04
  4f8baf:	68 ff 00 00 00       	push   0xff
  4f8bb4:	50                   	push   eax
  4f8bb5:	e8 a6 1a 05 00       	call   0x54a660
  4f8bba:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  4f8bbe:	83 c4 10             	add    esp,0x10
  4f8bc1:	6a ff                	push   0xffffffff
  4f8bc3:	6a ff                	push   0xffffffff
  4f8bc5:	6a ff                	push   0xffffffff
  4f8bc7:	51                   	push   ecx
  4f8bc8:	56                   	push   esi
  4f8bc9:	53                   	push   ebx
  4f8bca:	8b cf                	mov    ecx,edi
  4f8bcc:	e8 8f 2a 00 00       	call   0x4fb660
  4f8bd1:	56                   	push   esi
  4f8bd2:	8b cf                	mov    ecx,edi
  4f8bd4:	e8 57 f0 ff ff       	call   0x4f7c30
  4f8bd9:	5f                   	pop    edi
  4f8bda:	5e                   	pop    esi
  4f8bdb:	5d                   	pop    ebp
  4f8bdc:	b8 01 00 00 00       	mov    eax,0x1
  4f8be1:	5b                   	pop    ebx
  4f8be2:	83 c4 10             	add    esp,0x10
  4f8be5:	c2                   	.byte 0xc2
  4f8be6:	10                   	.byte 0x10
```

## `Mission_EvaluateGoals` — `0x4f5fd0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x4f5fd0.c`
- Callers: `Game_WindowProc` (0x4058d0), `Mission_TickGoalDeadline` (0x4f6b80)
- Callees: `AI_GetMaxPlanSteps` (0x4e2c40), `AI_SumPlanSteps` (0x4e2ca0), `Game_CountObjectsByState` (0x486910), `Game_CountRecordsByOwner` (0x4d8780), `Game_CountRecordsWithFlag16F4` (0x4de710), `Game_GetCategoryShare` (0x48c920), `Game_GetCurrentPlayerCompanyName` (0x482820), `Game_GetPlayerBySlot` (0x488be0), `Game_GetPlayerCity` (0x4ddcc0), `Game_GetPlayerFieldC20` (0x4e2280), `Game_GetPlayerValueSharePercent` (0x48ca10), `IDMap_Lookup` (0x4017f0), `LookupTable_HasKey` (0x514220), `Player_ComputeAverageRating` (0x4e2d00), `Stats_SumFilteredFloats` (0x477fe0), `Stats_SumFilteredFloats2` (0x478090), `UI_Briefing_Printf` (0x48bf90)

- Unresolved questions: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

004f5fd0 <.text+0xf4fd0>:
  4f5fd0:	83 ec 38             	sub    esp,0x38
  4f5fd3:	53                   	push   ebx
  4f5fd4:	55                   	push   ebp
  4f5fd5:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4f5fd9:	33 c0                	xor    eax,eax
  4f5fdb:	8b 4c 24 44          	mov    ecx,DWORD PTR [esp+0x44]
  4f5fdf:	8b 5c 24 14          	mov    ebx,DWORD PTR [esp+0x14]
  4f5fe3:	56                   	push   esi
  4f5fe4:	57                   	push   edi
  4f5fe5:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4f5fe9:	c7 44 24 28 03 00 00 	mov    DWORD PTR [esp+0x28],0x3
  4f5ff0:	00 
  4f5ff1:	89 44 24 2c          	mov    DWORD PTR [esp+0x2c],eax
  4f5ff5:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  4f5ff9:	8b e8                	mov    ebp,eax
  4f5ffb:	ba 01 00 00 00       	mov    edx,0x1
  4f6000:	eb 0d                	jmp    0x4f600f
  4f6002:	8b 5c 24 1c          	mov    ebx,DWORD PTR [esp+0x1c]
  4f6006:	8b 4c 24 4c          	mov    ecx,DWORD PTR [esp+0x4c]
  4f600a:	ba 01 00 00 00       	mov    edx,0x1
  4f600f:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4f6014:	33 ff                	xor    edi,edi
  4f6016:	8b b0 ec 02 00 00    	mov    esi,DWORD PTR [eax+0x2ec]
  4f601c:	8b b4 b0 00 02 00 00 	mov    esi,DWORD PTR [eax+esi*4+0x200]
  4f6023:	8a 84 2b c4 00 00 00 	mov    al,BYTE PTR [ebx+ebp*1+0xc4]
  4f602a:	3c 01                	cmp    al,0x1
  4f602c:	0f 84 36 09 00 00    	je     0x4f6968
  4f6032:	8b 44 ab 04          	mov    eax,DWORD PTR [ebx+ebp*4+0x4]
  4f6036:	40                   	inc    eax
  4f6037:	83 f8 2c             	cmp    eax,0x2c
  4f603a:	0f 87 28 09 00 00    	ja     0x4f6968
  4f6040:	ff 24 85 9c 6a 4f 00 	jmp    DWORD PTR [eax*4+0x4f6a9c]
  4f6047:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4f604b:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  4f604f:	49                   	dec    ecx
  4f6050:	40                   	inc    eax
  4f6051:	89 4c 24 28          	mov    DWORD PTR [esp+0x28],ecx
  4f6055:	89 44 24 2c          	mov    DWORD PTR [esp+0x2c],eax
  4f6059:	e9 0a 09 00 00       	jmp    0x4f6968
  4f605e:	a0 20 bb 57 00       	mov    al,ds:0x57bb20
  4f6063:	8b ce                	mov    ecx,esi
  4f6065:	84 c0                	test   al,al
  4f6067:	74 13                	je     0x4f607c
  4f6069:	e8 12 c2 fe ff       	call   0x4e2280
  4f606e:	83 f8 05             	cmp    eax,0x5
  4f6071:	0f 8e f1 08 00 00    	jle    0x4f6968
  4f6077:	e9 e4 08 00 00       	jmp    0x4f6960
  4f607c:	e8 ff c1 fe ff       	call   0x4e2280
  4f6081:	83 f8 02             	cmp    eax,0x2
  4f6084:	0f 8e de 08 00 00    	jle    0x4f6968
  4f608a:	e9 d1 08 00 00       	jmp    0x4f6960
  4f608f:	39 7b 14             	cmp    DWORD PTR [ebx+0x14],edi
  4f6092:	0f 8e d0 08 00 00    	jle    0x4f6968
  4f6098:	e9 c3 08 00 00       	jmp    0x4f6960
  4f609d:	8b ce                	mov    ecx,esi
  4f609f:	e8 6c 86 fe ff       	call   0x4de710
  4f60a4:	85 c0                	test   eax,eax
  4f60a6:	0f 84 bc 08 00 00    	je     0x4f6968
  4f60ac:	e9 af 08 00 00       	jmp    0x4f6960
  4f60b1:	3b cf                	cmp    ecx,edi
  4f60b3:	0f 85 af 08 00 00    	jne    0x4f6968
  4f60b9:	8b 76 48             	mov    esi,DWORD PTR [esi+0x48]
  4f60bc:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f60c2:	56                   	push   esi
  4f60c3:	6a 05                	push   0x5
  4f60c5:	e8 56 68 f9 ff       	call   0x48c920
  4f60ca:	83 f8 3c             	cmp    eax,0x3c
  4f60cd:	0f 8c 95 08 00 00    	jl     0x4f6968
  4f60d3:	e9 88 08 00 00       	jmp    0x4f6960
  4f60d8:	8b ae 5c 01 00 00    	mov    ebp,DWORD PTR [esi+0x15c]
  4f60de:	33 ff                	xor    edi,edi
  4f60e0:	85 ed                	test   ebp,ebp
  4f60e2:	7e 29                	jle    0x4f610d
  4f60e4:	81 c6 48 01 00 00    	add    esi,0x148
  4f60ea:	6a 00                	push   0x0
  4f60ec:	57                   	push   edi
  4f60ed:	8b ce                	mov    ecx,esi
  4f60ef:	e8 fc b6 f0 ff       	call   0x4017f0
  4f60f4:	80 b8 f4 16 00 00 01 	cmp    BYTE PTR [eax+0x16f4],0x1
  4f60fb:	75 0b                	jne    0x4f6108
  4f60fd:	8b 48 38             	mov    ecx,DWORD PTR [eax+0x38]
  4f6100:	85 c9                	test   ecx,ecx
  4f6102:	7e 04                	jle    0x4f6108
  4f6104:	ff 44 24 14          	inc    DWORD PTR [esp+0x14]
  4f6108:	47                   	inc    edi
  4f6109:	3b fd                	cmp    edi,ebp
  4f610b:	7c dd                	jl     0x4f60ea
  4f610d:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4f6111:	85 c0                	test   eax,eax
  4f6113:	0f 8e 4f 08 00 00    	jle    0x4f6968
  4f6119:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  4f611d:	c6 84 03 c4 00 00 00 	mov    BYTE PTR [ebx+eax*1+0xc4],0x1
  4f6124:	01 
  4f6125:	e9 3e 08 00 00       	jmp    0x4f6968
  4f612a:	8b 86 5c 01 00 00    	mov    eax,DWORD PTR [esi+0x15c]
  4f6130:	c6 44 24 13 01       	mov    BYTE PTR [esp+0x13],0x1
  4f6135:	3b c7                	cmp    eax,edi
  4f6137:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4f613b:	89 7c 24 24          	mov    DWORD PTR [esp+0x24],edi
  4f613f:	7e 7f                	jle    0x4f61c0
  4f6141:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  4f6145:	33 ff                	xor    edi,edi
  4f6147:	57                   	push   edi
  4f6148:	51                   	push   ecx
  4f6149:	8d 8e 48 01 00 00    	lea    ecx,[esi+0x148]
  4f614f:	89 7c 24 1c          	mov    DWORD PTR [esp+0x1c],edi
  4f6153:	e8 98 b6 f0 ff       	call   0x4017f0
  4f6158:	8b e8                	mov    ebp,eax
  4f615a:	8b 86 94 01 00 00    	mov    eax,DWORD PTR [esi+0x194]
  4f6160:	3b c7                	cmp    eax,edi
  4f6162:	7e 3a                	jle    0x4f619e
  4f6164:	8d 9e 80 01 00 00    	lea    ebx,[esi+0x180]
  4f616a:	6a 00                	push   0x0
  4f616c:	57                   	push   edi
  4f616d:	8b cb                	mov    ecx,ebx
  4f616f:	e8 7c b6 f0 ff       	call   0x4017f0
  4f6174:	8b 4d 3c             	mov    ecx,DWORD PTR [ebp+0x3c]
  4f6177:	51                   	push   ecx
  4f6178:	8b c8                	mov    ecx,eax
  4f617a:	e8 a1 e0 01 00       	call   0x514220
  4f617f:	84 c0                	test   al,al
  4f6181:	74 08                	je     0x4f618b
  4f6183:	c7 44 24 14 01 00 00 	mov    DWORD PTR [esp+0x14],0x1
  4f618a:	00 
  4f618b:	8b 86 94 01 00 00    	mov    eax,DWORD PTR [esi+0x194]
  4f6191:	47                   	inc    edi
  4f6192:	3b f8                	cmp    edi,eax
  4f6194:	7c d4                	jl     0x4f616a
  4f6196:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4f619a:	85 c0                	test   eax,eax
  4f619c:	75 05                	jne    0x4f61a3
  4f619e:	c6 44 24 13 00       	mov    BYTE PTR [esp+0x13],0x0
  4f61a3:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  4f61a7:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  4f61ab:	40                   	inc    eax
  4f61ac:	3b c1                	cmp    eax,ecx
  4f61ae:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  4f61b2:	7c 8d                	jl     0x4f6141
  4f61b4:	8a 44 24 13          	mov    al,BYTE PTR [esp+0x13]
  4f61b8:	84 c0                	test   al,al
  4f61ba:	0f 84 a8 07 00 00    	je     0x4f6968
  4f61c0:	8b 54 24 1c          	mov    edx,DWORD PTR [esp+0x1c]
  4f61c4:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  4f61c8:	c6 84 02 c4 00 00 00 	mov    BYTE PTR [edx+eax*1+0xc4],0x1
  4f61cf:	01 
  4f61d0:	e9 93 07 00 00       	jmp    0x4f6968
  4f61d5:	83 7b 28 0a          	cmp    DWORD PTR [ebx+0x28],0xa
  4f61d9:	0f 8c 89 07 00 00    	jl     0x4f6968
  4f61df:	e9 7c 07 00 00       	jmp    0x4f6960
  4f61e4:	39 7b 2c             	cmp    DWORD PTR [ebx+0x2c],edi
  4f61e7:	0f 8e 7b 07 00 00    	jle    0x4f6968
  4f61ed:	e9 6e 07 00 00       	jmp    0x4f6960
  4f61f2:	8b ae 5c 01 00 00    	mov    ebp,DWORD PTR [esi+0x15c]
  4f61f8:	33 ff                	xor    edi,edi
  4f61fa:	85 ed                	test   ebp,ebp
  4f61fc:	0f 8e 66 07 00 00    	jle    0x4f6968
  4f6202:	81 c6 48 01 00 00    	add    esi,0x148
  4f6208:	6a 00                	push   0x0
  4f620a:	57                   	push   edi
  4f620b:	8b ce                	mov    ecx,esi
  4f620d:	e8 de b5 f0 ff       	call   0x4017f0
  4f6212:	8b 88 b4 14 00 00    	mov    ecx,DWORD PTR [eax+0x14b4]
  4f6218:	85 c9                	test   ecx,ecx
  4f621a:	7e 0c                	jle    0x4f6228
  4f621c:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4f6220:	c6 84 19 c4 00 00 00 	mov    BYTE PTR [ecx+ebx*1+0xc4],0x1
  4f6227:	01 
  4f6228:	47                   	inc    edi
  4f6229:	3b fd                	cmp    edi,ebp
  4f622b:	7c db                	jl     0x4f6208
  4f622d:	e9 36 07 00 00       	jmp    0x4f6968
  4f6232:	8b ae 5c 01 00 00    	mov    ebp,DWORD PTR [esi+0x15c]
  4f6238:	33 ff                	xor    edi,edi
  4f623a:	85 ed                	test   ebp,ebp
  4f623c:	7e 22                	jle    0x4f6260
  4f623e:	81 c6 48 01 00 00    	add    esi,0x148
  4f6244:	6a 00                	push   0x0
  4f6246:	57                   	push   edi
  4f6247:	8b ce                	mov    ecx,esi
  4f6249:	e8 a2 b5 f0 ff       	call   0x4017f0
  4f624e:	83 b8 b4 14 00 00 03 	cmp    DWORD PTR [eax+0x14b4],0x3
  4f6255:	7e 04                	jle    0x4f625b
  4f6257:	ff 44 24 14          	inc    DWORD PTR [esp+0x14]
  4f625b:	47                   	inc    edi
  4f625c:	3b fd                	cmp    edi,ebp
  4f625e:	7c e4                	jl     0x4f6244
  4f6260:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4f6264:	85 c0                	test   eax,eax
  4f6266:	e9 12 05 00 00       	jmp    0x4f677d
  4f626b:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f6271:	6a ff                	push   0xffffffff
  4f6273:	e8 98 06 f9 ff       	call   0x486910
  4f6278:	33 db                	xor    ebx,ebx
  4f627a:	3b c7                	cmp    eax,edi
  4f627c:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4f6280:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  4f6284:	89 7c 24 30          	mov    DWORD PTR [esp+0x30],edi
  4f6288:	89 7c 24 34          	mov    DWORD PTR [esp+0x34],edi
  4f628c:	89 7c 24 38          	mov    DWORD PTR [esp+0x38],edi
  4f6290:	89 7c 24 3c          	mov    DWORD PTR [esp+0x3c],edi
  4f6294:	89 7c 24 40          	mov    DWORD PTR [esp+0x40],edi
  4f6298:	89 7c 24 44          	mov    DWORD PTR [esp+0x44],edi
  4f629c:	7e 54                	jle    0x4f62f2
  4f629e:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4f62a3:	6a 00                	push   0x0
  4f62a5:	53                   	push   ebx
  4f62a6:	8d 48 3c             	lea    ecx,[eax+0x3c]
  4f62a9:	e8 42 b5 f0 ff       	call   0x4017f0
  4f62ae:	83 78 30 07          	cmp    DWORD PTR [eax+0x30],0x7
  4f62b2:	7f 35                	jg     0x4f62e9
  4f62b4:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  4f62b8:	8d 6c 24 30          	lea    ebp,[esp+0x30]
  4f62bc:	41                   	inc    ecx
  4f62bd:	33 f6                	xor    esi,esi
  4f62bf:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4f62c3:	8d 78 5c             	lea    edi,[eax+0x5c]
  4f62c6:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f62cc:	e8 4f c5 f8 ff       	call   0x482820
  4f62d1:	3b f0                	cmp    esi,eax
  4f62d3:	74 08                	je     0x4f62dd
  4f62d5:	83 3f 00             	cmp    DWORD PTR [edi],0x0
  4f62d8:	7d 03                	jge    0x4f62dd
  4f62da:	ff 45 00             	inc    DWORD PTR [ebp+0x0]
  4f62dd:	46                   	inc    esi
  4f62de:	83 c7 04             	add    edi,0x4
  4f62e1:	83 c5 04             	add    ebp,0x4
  4f62e4:	83 fe 06             	cmp    esi,0x6
  4f62e7:	7c dd                	jl     0x4f62c6
  4f62e9:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4f62ed:	43                   	inc    ebx
  4f62ee:	3b d8                	cmp    ebx,eax
  4f62f0:	7c ac                	jl     0x4f629e
  4f62f2:	b8 67 66 66 66       	mov    eax,0x66666667
  4f62f7:	32 db                	xor    bl,bl
  4f62f9:	f7 6c 24 14          	imul   DWORD PTR [esp+0x14]
  4f62fd:	c1 fa 02             	sar    edx,0x2
  4f6300:	8b c2                	mov    eax,edx
  4f6302:	33 c9                	xor    ecx,ecx
  4f6304:	c1 e8 1f             	shr    eax,0x1f
  4f6307:	03 d0                	add    edx,eax
  4f6309:	8d 44 24 30          	lea    eax,[esp+0x30]
  4f630d:	39 10                	cmp    DWORD PTR [eax],edx
  4f630f:	7f 1d                	jg     0x4f632e
  4f6311:	41                   	inc    ecx
  4f6312:	83 c0 04             	add    eax,0x4
  4f6315:	83 f9 06             	cmp    ecx,0x6
  4f6318:	7c f3                	jl     0x4f630d
  4f631a:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  4f631e:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  4f6322:	88 9c 11 c4 00 00 00 	mov    BYTE PTR [ecx+edx*1+0xc4],bl
  4f6329:	e9 3a 06 00 00       	jmp    0x4f6968
  4f632e:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  4f6332:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  4f6336:	b3 01                	mov    bl,0x1
  4f6338:	88 9c 11 c4 00 00 00 	mov    BYTE PTR [ecx+edx*1+0xc4],bl
  4f633f:	e9 24 06 00 00       	jmp    0x4f6968
  4f6344:	3b cf                	cmp    ecx,edi
  4f6346:	0f 85 1c 06 00 00    	jne    0x4f6968
  4f634c:	8b 76 48             	mov    esi,DWORD PTR [esi+0x48]
  4f634f:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f6355:	56                   	push   esi
  4f6356:	6a ff                	push   0xffffffff
  4f6358:	e8 c3 65 f9 ff       	call   0x48c920
  4f635d:	83 f8 32             	cmp    eax,0x32
  4f6360:	0f 8c 02 06 00 00    	jl     0x4f6968
  4f6366:	e9 f5 05 00 00       	jmp    0x4f6960
  4f636b:	3b cf                	cmp    ecx,edi
  4f636d:	0f 85 f5 05 00 00    	jne    0x4f6968
  4f6373:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4f6378:	8b 88 94 00 00 00    	mov    ecx,DWORD PTR [eax+0x94]
  4f637e:	66 8b 41 0a          	mov    ax,WORD PTR [ecx+0xa]
  4f6382:	8b ce                	mov    ecx,esi
  4f6384:	25 ff ff 00 00       	and    eax,0xffff
  4f6389:	48                   	dec    eax
  4f638a:	50                   	push   eax
  4f638b:	e8 b0 c8 fe ff       	call   0x4e2c40
  4f6390:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4f6394:	33 ff                	xor    edi,edi
  4f6396:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f639c:	57                   	push   edi
  4f639d:	e8 3e 28 f9 ff       	call   0x488be0
  4f63a2:	8b f0                	mov    esi,eax
  4f63a4:	85 f6                	test   esi,esi
  4f63a6:	74 3a                	je     0x4f63e2
  4f63a8:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f63ae:	8b 6e 48             	mov    ebp,DWORD PTR [esi+0x48]
  4f63b1:	e8 6a c4 f8 ff       	call   0x482820
  4f63b6:	3b e8                	cmp    ebp,eax
  4f63b8:	74 28                	je     0x4f63e2
  4f63ba:	8b 15 70 c6 57 00    	mov    edx,DWORD PTR ds:0x57c670
  4f63c0:	8b ce                	mov    ecx,esi
  4f63c2:	8b 82 94 00 00 00    	mov    eax,DWORD PTR [edx+0x94]
  4f63c8:	66 8b 40 0a          	mov    ax,WORD PTR [eax+0xa]
  4f63cc:	25 ff ff 00 00       	and    eax,0xffff
  4f63d1:	48                   	dec    eax
  4f63d2:	50                   	push   eax
  4f63d3:	e8 68 c8 fe ff       	call   0x4e2c40
  4f63d8:	3b 44 24 14          	cmp    eax,DWORD PTR [esp+0x14]
  4f63dc:	7e 04                	jle    0x4f63e2
  4f63de:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4f63e2:	47                   	inc    edi
  4f63e3:	83 ff 06             	cmp    edi,0x6
  4f63e6:	7c ae                	jl     0x4f6396
  4f63e8:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  4f63ec:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4f63f0:	8d 14 09             	lea    edx,[ecx+ecx*1]
  4f63f3:	3b c2                	cmp    eax,edx
  4f63f5:	0f 8c 6d 05 00 00    	jl     0x4f6968
  4f63fb:	85 c0                	test   eax,eax
  4f63fd:	0f 8e 65 05 00 00    	jle    0x4f6968
  4f6403:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  4f6407:	c6 84 03 c4 00 00 00 	mov    BYTE PTR [ebx+eax*1+0xc4],0x1
  4f640e:	01 
  4f640f:	e9 54 05 00 00       	jmp    0x4f6968
  4f6414:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4f6419:	57                   	push   edi
  4f641a:	8b 88 f4 02 00 00    	mov    ecx,DWORD PTR [eax+0x2f4]
  4f6420:	51                   	push   ecx
  4f6421:	8d 48 04             	lea    ecx,[eax+0x4]
  4f6424:	e8 c7 b3 f0 ff       	call   0x4017f0
  4f6429:	6a 11                	push   0x11
  4f642b:	8b c8                	mov    ecx,eax
  4f642d:	e8 4e 23 fe ff       	call   0x4d8780
  4f6432:	83 f8 02             	cmp    eax,0x2
  4f6435:	0f 8e 2d 05 00 00    	jle    0x4f6968
  4f643b:	e9 20 05 00 00       	jmp    0x4f6960
  4f6440:	39 bb c0 00 00 00    	cmp    DWORD PTR [ebx+0xc0],edi
  4f6446:	0f 85 1c 05 00 00    	jne    0x4f6968
  4f644c:	e9 0f 05 00 00       	jmp    0x4f6960
  4f6451:	8b 86 5c 01 00 00    	mov    eax,DWORD PTR [esi+0x15c]
  4f6457:	33 ff                	xor    edi,edi
  4f6459:	3b c7                	cmp    eax,edi
  4f645b:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  4f645f:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4f6463:	0f 8e f7 04 00 00    	jle    0x4f6960
  4f6469:	81 c6 48 01 00 00    	add    esi,0x148
  4f646f:	6a 00                	push   0x0
  4f6471:	57                   	push   edi
  4f6472:	8b ce                	mov    ecx,esi
  4f6474:	e8 77 b3 f0 ff       	call   0x4017f0
  4f6479:	8b 80 04 1a 00 00    	mov    eax,DWORD PTR [eax+0x1a04]
  4f647f:	83 f8 02             	cmp    eax,0x2
  4f6482:	74 26                	je     0x4f64aa
  4f6484:	85 c0                	test   eax,eax
  4f6486:	74 22                	je     0x4f64aa
  4f6488:	83 f8 04             	cmp    eax,0x4
  4f648b:	74 1d                	je     0x4f64aa
  4f648d:	83 f8 03             	cmp    eax,0x3
  4f6490:	75 04                	jne    0x4f6496
  4f6492:	ff 44 24 14          	inc    DWORD PTR [esp+0x14]
  4f6496:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4f649a:	47                   	inc    edi
  4f649b:	3b f8                	cmp    edi,eax
  4f649d:	7c d0                	jl     0x4f646f
  4f649f:	83 7c 24 14 02       	cmp    DWORD PTR [esp+0x14],0x2
  4f64a4:	0f 8c b6 04 00 00    	jl     0x4f6960
  4f64aa:	c6 84 2b c4 00 00 00 	mov    BYTE PTR [ebx+ebp*1+0xc4],0x0
  4f64b1:	00 
  4f64b2:	e9 b1 04 00 00       	jmp    0x4f6968
  4f64b7:	3b cf                	cmp    ecx,edi
  4f64b9:	0f 85 a9 04 00 00    	jne    0x4f6968
  4f64bf:	8b 15 70 c6 57 00    	mov    edx,DWORD PTR ds:0x57c670
  4f64c5:	8b ce                	mov    ecx,esi
  4f64c7:	8b 82 94 00 00 00    	mov    eax,DWORD PTR [edx+0x94]
  4f64cd:	66 8b 40 0a          	mov    ax,WORD PTR [eax+0xa]
  4f64d1:	25 ff ff 00 00       	and    eax,0xffff
  4f64d6:	48                   	dec    eax
  4f64d7:	50                   	push   eax
  4f64d8:	e8 c3 c7 fe ff       	call   0x4e2ca0
  4f64dd:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4f64e1:	33 ff                	xor    edi,edi
  4f64e3:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f64e9:	57                   	push   edi
  4f64ea:	e8 f1 26 f9 ff       	call   0x488be0
  4f64ef:	8b f0                	mov    esi,eax
  4f64f1:	85 f6                	test   esi,esi
  4f64f3:	74 38                	je     0x4f652d
  4f64f5:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f64fb:	8b 6e 48             	mov    ebp,DWORD PTR [esi+0x48]
  4f64fe:	e8 1d c3 f8 ff       	call   0x482820
  4f6503:	3b e8                	cmp    ebp,eax
  4f6505:	74 22                	je     0x4f6529
  4f6507:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f650d:	8b 91 94 00 00 00    	mov    edx,DWORD PTR [ecx+0x94]
  4f6513:	8b ce                	mov    ecx,esi
  4f6515:	66 8b 42 0a          	mov    ax,WORD PTR [edx+0xa]
  4f6519:	25 ff ff 00 00       	and    eax,0xffff
  4f651e:	48                   	dec    eax
  4f651f:	50                   	push   eax
  4f6520:	e8 7b c7 fe ff       	call   0x4e2ca0
  4f6525:	01 44 24 14          	add    DWORD PTR [esp+0x14],eax
  4f6529:	8b 6c 24 18          	mov    ebp,DWORD PTR [esp+0x18]
  4f652d:	47                   	inc    edi
  4f652e:	83 ff 06             	cmp    edi,0x6
  4f6531:	7c b0                	jl     0x4f64e3
  4f6533:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4f6537:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  4f653b:	3b c1                	cmp    eax,ecx
  4f653d:	0f 8c 25 04 00 00    	jl     0x4f6968
  4f6543:	85 c0                	test   eax,eax
  4f6545:	0f 8e 1d 04 00 00    	jle    0x4f6968
  4f654b:	e9 10 04 00 00       	jmp    0x4f6960
  4f6550:	dd 86 08 01 00 00    	fld    QWORD PTR [esi+0x108]
  4f6556:	dc 1d 10 c6 55 00    	fcomp  QWORD PTR ds:0x55c610
  4f655c:	df e0                	fnstsw ax
  4f655e:	f6 c4 01             	test   ah,0x1
  4f6561:	0f 85 01 04 00 00    	jne    0x4f6968
  4f6567:	e9 f4 03 00 00       	jmp    0x4f6960
  4f656c:	39 7b 58             	cmp    DWORD PTR [ebx+0x58],edi
  4f656f:	0f 8e f3 03 00 00    	jle    0x4f6968
  4f6575:	e9 e6 03 00 00       	jmp    0x4f6960
  4f657a:	39 53 5c             	cmp    DWORD PTR [ebx+0x5c],edx
  4f657d:	0f 8e e5 03 00 00    	jle    0x4f6968
  4f6583:	e9 d8 03 00 00       	jmp    0x4f6960
  4f6588:	39 7b 60             	cmp    DWORD PTR [ebx+0x60],edi
  4f658b:	0f 8e d7 03 00 00    	jle    0x4f6968
  4f6591:	e9 ca 03 00 00       	jmp    0x4f6960
  4f6596:	8b 9e 5c 01 00 00    	mov    ebx,DWORD PTR [esi+0x15c]
  4f659c:	83 fb 05             	cmp    ebx,0x5
  4f659f:	0f 8c c3 03 00 00    	jl     0x4f6968
  4f65a5:	33 ff                	xor    edi,edi
  4f65a7:	3b df                	cmp    ebx,edi
  4f65a9:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  4f65ad:	0f 8e b5 03 00 00    	jle    0x4f6968
  4f65b3:	8d ae 48 01 00 00    	lea    ebp,[esi+0x148]
  4f65b9:	6a 00                	push   0x0
  4f65bb:	57                   	push   edi
  4f65bc:	8b cd                	mov    ecx,ebp
  4f65be:	e8 2d b2 f0 ff       	call   0x4017f0
  4f65c3:	8b f0                	mov    esi,eax
  4f65c5:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4f65ca:	8b 88 94 00 00 00    	mov    ecx,DWORD PTR [eax+0x94]
  4f65d0:	66 8b 41 0a          	mov    ax,WORD PTR [ecx+0xa]
  4f65d4:	8b ce                	mov    ecx,esi
  4f65d6:	25 ff ff 00 00       	and    eax,0xffff
  4f65db:	50                   	push   eax
  4f65dc:	6a ff                	push   0xffffffff
  4f65de:	6a ff                	push   0xffffffff
  4f65e0:	e8 ab 1a f8 ff       	call   0x478090
  4f65e5:	8b 15 70 c6 57 00    	mov    edx,DWORD PTR ds:0x57c670
  4f65eb:	8b ce                	mov    ecx,esi
  4f65ed:	d9 5c 24 24          	fstp   DWORD PTR [esp+0x24]
  4f65f1:	8b 82 94 00 00 00    	mov    eax,DWORD PTR [edx+0x94]
  4f65f7:	66 8b 40 0a          	mov    ax,WORD PTR [eax+0xa]
  4f65fb:	25 ff ff 00 00       	and    eax,0xffff
  4f6600:	50                   	push   eax
  4f6601:	6a ff                	push   0xffffffff
  4f6603:	6a ff                	push   0xffffffff
  4f6605:	e8 d6 19 f8 ff       	call   0x477fe0
  4f660a:	d8 54 24 24          	fcom   DWORD PTR [esp+0x24]
  4f660e:	df e0                	fnstsw ax
  4f6610:	f6 c4 01             	test   ah,0x1
  4f6613:	75 13                	jne    0x4f6628
  4f6615:	d8 1d e4 c2 55 00    	fcomp  DWORD PTR ds:0x55c2e4
  4f661b:	df e0                	fnstsw ax
  4f661d:	f6 c4 41             	test   ah,0x41
  4f6620:	75 08                	jne    0x4f662a
  4f6622:	ff 44 24 14          	inc    DWORD PTR [esp+0x14]
  4f6626:	eb 02                	jmp    0x4f662a
  4f6628:	dd d8                	fstp   st(0)
  4f662a:	47                   	inc    edi
  4f662b:	3b fb                	cmp    edi,ebx
  4f662d:	7c 8a                	jl     0x4f65b9
  4f662f:	83 7c 24 14 04       	cmp    DWORD PTR [esp+0x14],0x4
  4f6634:	0f 8e 2e 03 00 00    	jle    0x4f6968
  4f663a:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  4f663e:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  4f6642:	c6 84 11 c4 00 00 00 	mov    BYTE PTR [ecx+edx*1+0xc4],0x1
  4f6649:	01 
  4f664a:	e9 19 03 00 00       	jmp    0x4f6968
  4f664f:	8b ce                	mov    ecx,esi
  4f6651:	e8 aa c6 fe ff       	call   0x4e2d00
  4f6656:	8b d8                	mov    ebx,eax
  4f6658:	c6 44 24 13 01       	mov    BYTE PTR [esp+0x13],0x1
  4f665d:	33 ff                	xor    edi,edi
  4f665f:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f6665:	57                   	push   edi
  4f6666:	e8 75 25 f9 ff       	call   0x488be0
  4f666b:	8b f0                	mov    esi,eax
  4f666d:	85 f6                	test   esi,esi
  4f666f:	74 26                	je     0x4f6697
  4f6671:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f6677:	8b 6e 48             	mov    ebp,DWORD PTR [esi+0x48]
  4f667a:	e8 a1 c1 f8 ff       	call   0x482820
  4f667f:	3b e8                	cmp    ebp,eax
  4f6681:	74 14                	je     0x4f6697
  4f6683:	8b ce                	mov    ecx,esi
  4f6685:	e8 76 c6 fe ff       	call   0x4e2d00
  4f668a:	3b c3                	cmp    eax,ebx
  4f668c:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4f6690:	7e 05                	jle    0x4f6697
  4f6692:	c6 44 24 13 00       	mov    BYTE PTR [esp+0x13],0x0
  4f6697:	47                   	inc    edi
  4f6698:	83 ff 06             	cmp    edi,0x6
  4f669b:	7c c2                	jl     0x4f665f
  4f669d:	8a 44 24 13          	mov    al,BYTE PTR [esp+0x13]
  4f66a1:	84 c0                	test   al,al
  4f66a3:	0f 84 bf 02 00 00    	je     0x4f6968
  4f66a9:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  4f66ad:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4f66b1:	c6 84 08 c4 00 00 00 	mov    BYTE PTR [eax+ecx*1+0xc4],0x1
  4f66b8:	01 
  4f66b9:	e9 aa 02 00 00       	jmp    0x4f6968
  4f66be:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f66c4:	e8 57 c1 f8 ff       	call   0x482820
  4f66c9:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f66cf:	50                   	push   eax
  4f66d0:	e8 3b 63 f9 ff       	call   0x48ca10
  4f66d5:	83 f8 32             	cmp    eax,0x32
  4f66d8:	0f 8c 8a 02 00 00    	jl     0x4f6968
  4f66de:	e9 7d 02 00 00       	jmp    0x4f6960
  4f66e3:	3b cf                	cmp    ecx,edi
  4f66e5:	0f 85 7d 02 00 00    	jne    0x4f6968
  4f66eb:	8b 46 48             	mov    eax,DWORD PTR [esi+0x48]
  4f66ee:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f66f4:	50                   	push   eax
  4f66f5:	6a 03                	push   0x3
  4f66f7:	e8 24 62 f9 ff       	call   0x48c920
  4f66fc:	83 f8 46             	cmp    eax,0x46
  4f66ff:	0f 8c 63 02 00 00    	jl     0x4f6968
  4f6705:	8b 76 48             	mov    esi,DWORD PTR [esi+0x48]
  4f6708:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f670e:	56                   	push   esi
  4f670f:	6a 05                	push   0x5
  4f6711:	e8 0a 62 f9 ff       	call   0x48c920
  4f6716:	83 f8 46             	cmp    eax,0x46
  4f6719:	0f 8c 49 02 00 00    	jl     0x4f6968
  4f671f:	e9 3c 02 00 00       	jmp    0x4f6960
  4f6724:	81 7b 78 40 9c 00 00 	cmp    DWORD PTR [ebx+0x78],0x9c40
  4f672b:	0f 8c 37 02 00 00    	jl     0x4f6968
  4f6731:	e9 2a 02 00 00       	jmp    0x4f6960
  4f6736:	39 7b 74             	cmp    DWORD PTR [ebx+0x74],edi
  4f6739:	0f 8e 29 02 00 00    	jle    0x4f6968
  4f673f:	e9 1c 02 00 00       	jmp    0x4f6960
  4f6744:	8b ae 5c 01 00 00    	mov    ebp,DWORD PTR [esi+0x15c]
  4f674a:	33 ff                	xor    edi,edi
  4f674c:	85 ed                	test   ebp,ebp
  4f674e:	7e 28                	jle    0x4f6778
  4f6750:	81 c6 48 01 00 00    	add    esi,0x148
  4f6756:	6a 00                	push   0x0
  4f6758:	57                   	push   edi
  4f6759:	8b ce                	mov    ecx,esi
  4f675b:	e8 90 b0 f0 ff       	call   0x4017f0
  4f6760:	80 b8 f4 16 00 00 01 	cmp    BYTE PTR [eax+0x16f4],0x1
  4f6767:	75 0a                	jne    0x4f6773
  4f6769:	83 78 38 01          	cmp    DWORD PTR [eax+0x38],0x1
  4f676d:	7e 04                	jle    0x4f6773
  4f676f:	ff 44 24 14          	inc    DWORD PTR [esp+0x14]
  4f6773:	47                   	inc    edi
  4f6774:	3b fd                	cmp    edi,ebp
  4f6776:	7c de                	jl     0x4f6756
  4f6778:	83 7c 24 14 05       	cmp    DWORD PTR [esp+0x14],0x5
  4f677d:	0f 8e e5 01 00 00    	jle    0x4f6968
  4f6783:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  4f6787:	c6 84 13 c4 00 00 00 	mov    BYTE PTR [ebx+edx*1+0xc4],0x1
  4f678e:	01 
  4f678f:	e9 d4 01 00 00       	jmp    0x4f6968
  4f6794:	39 93 84 00 00 00    	cmp    DWORD PTR [ebx+0x84],edx
  4f679a:	0f 8e c8 01 00 00    	jle    0x4f6968
  4f67a0:	e9 bb 01 00 00       	jmp    0x4f6960
  4f67a5:	dd 86 08 01 00 00    	fld    QWORD PTR [esi+0x108]
  4f67ab:	dc 1d 08 c6 55 00    	fcomp  QWORD PTR ds:0x55c608
  4f67b1:	df e0                	fnstsw ax
  4f67b3:	f6 c4 01             	test   ah,0x1
  4f67b6:	0f 85 ac 01 00 00    	jne    0x4f6968
  4f67bc:	e9 9f 01 00 00       	jmp    0x4f6960
  4f67c1:	dd 86 08 01 00 00    	fld    QWORD PTR [esi+0x108]
  4f67c7:	dc 1d 00 c6 55 00    	fcomp  QWORD PTR ds:0x55c600
  4f67cd:	df e0                	fnstsw ax
  4f67cf:	f6 c4 01             	test   ah,0x1
  4f67d2:	0f 85 90 01 00 00    	jne    0x4f6968
  4f67d8:	e9 83 01 00 00       	jmp    0x4f6960
  4f67dd:	dd 86 08 01 00 00    	fld    QWORD PTR [esi+0x108]
  4f67e3:	dc 1d f8 c5 55 00    	fcomp  QWORD PTR ds:0x55c5f8
  4f67e9:	df e0                	fnstsw ax
  4f67eb:	f6 c4 01             	test   ah,0x1
  4f67ee:	0f 85 74 01 00 00    	jne    0x4f6968
  4f67f4:	e9 67 01 00 00       	jmp    0x4f6960
  4f67f9:	dd 86 08 01 00 00    	fld    QWORD PTR [esi+0x108]
  4f67ff:	dc 1d f0 c5 55 00    	fcomp  QWORD PTR ds:0x55c5f0
  4f6805:	df e0                	fnstsw ax
  4f6807:	f6 c4 01             	test   ah,0x1
  4f680a:	0f 85 58 01 00 00    	jne    0x4f6968
  4f6810:	e9 4b 01 00 00       	jmp    0x4f6960
  4f6815:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f681b:	e8 00 c0 f8 ff       	call   0x482820
  4f6820:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f6826:	50                   	push   eax
  4f6827:	e8 e4 61 f9 ff       	call   0x48ca10
  4f682c:	83 f8 46             	cmp    eax,0x46
  4f682f:	0f 8c 33 01 00 00    	jl     0x4f6968
  4f6835:	e9 26 01 00 00       	jmp    0x4f6960
  4f683a:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f6840:	e8 db bf f8 ff       	call   0x482820
  4f6845:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f684b:	50                   	push   eax
  4f684c:	e8 bf 61 f9 ff       	call   0x48ca10
  4f6851:	83 f8 50             	cmp    eax,0x50
  4f6854:	0f 8c 0e 01 00 00    	jl     0x4f6968
  4f685a:	e9 01 01 00 00       	jmp    0x4f6960
  4f685f:	3b cf                	cmp    ecx,edi
  4f6861:	0f 85 01 01 00 00    	jne    0x4f6968
  4f6867:	8b 76 48             	mov    esi,DWORD PTR [esi+0x48]
  4f686a:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f6870:	56                   	push   esi
  4f6871:	6a ff                	push   0xffffffff
  4f6873:	e8 a8 60 f9 ff       	call   0x48c920
  4f6878:	83 f8 50             	cmp    eax,0x50
  4f687b:	0f 8c e7 00 00 00    	jl     0x4f6968
  4f6881:	e9 da 00 00 00       	jmp    0x4f6960
  4f6886:	3b cf                	cmp    ecx,edi
  4f6888:	0f 85 da 00 00 00    	jne    0x4f6968
  4f688e:	8b 76 48             	mov    esi,DWORD PTR [esi+0x48]
  4f6891:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f6897:	56                   	push   esi
  4f6898:	57                   	push   edi
  4f6899:	e8 82 60 f9 ff       	call   0x48c920
  4f689e:	83 f8 3c             	cmp    eax,0x3c
  4f68a1:	0f 8c c1 00 00 00    	jl     0x4f6968
  4f68a7:	e9 b4 00 00 00       	jmp    0x4f6960
  4f68ac:	3b cf                	cmp    ecx,edi
  4f68ae:	0f 85 b4 00 00 00    	jne    0x4f6968
  4f68b4:	8b 76 48             	mov    esi,DWORD PTR [esi+0x48]
  4f68b7:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f68bd:	56                   	push   esi
  4f68be:	52                   	push   edx
  4f68bf:	e8 5c 60 f9 ff       	call   0x48c920
  4f68c4:	83 f8 3c             	cmp    eax,0x3c
  4f68c7:	0f 8c 9b 00 00 00    	jl     0x4f6968
  4f68cd:	e9 8e 00 00 00       	jmp    0x4f6960
  4f68d2:	3b cf                	cmp    ecx,edi
  4f68d4:	0f 85 8e 00 00 00    	jne    0x4f6968
  4f68da:	8b 76 48             	mov    esi,DWORD PTR [esi+0x48]
  4f68dd:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f68e3:	56                   	push   esi
  4f68e4:	6a 02                	push   0x2
  4f68e6:	e8 35 60 f9 ff       	call   0x48c920
  4f68eb:	83 f8 3c             	cmp    eax,0x3c
  4f68ee:	7c 78                	jl     0x4f6968
  4f68f0:	eb 6e                	jmp    0x4f6960
  4f68f2:	3b cf                	cmp    ecx,edi
  4f68f4:	75 72                	jne    0x4f6968
  4f68f6:	8b 76 48             	mov    esi,DWORD PTR [esi+0x48]
  4f68f9:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f68ff:	56                   	push   esi
  4f6900:	6a 03                	push   0x3
  4f6902:	e8 19 60 f9 ff       	call   0x48c920
  4f6907:	83 f8 3c             	cmp    eax,0x3c
  4f690a:	7c 5c                	jl     0x4f6968
  4f690c:	eb 52                	jmp    0x4f6960
  4f690e:	3b cf                	cmp    ecx,edi
  4f6910:	75 56                	jne    0x4f6968
  4f6912:	8b 76 48             	mov    esi,DWORD PTR [esi+0x48]
  4f6915:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f691b:	56                   	push   esi
  4f691c:	6a 04                	push   0x4
  4f691e:	e8 fd 5f f9 ff       	call   0x48c920
  4f6923:	83 f8 3c             	cmp    eax,0x3c
  4f6926:	7c 40                	jl     0x4f6968
  4f6928:	eb 36                	jmp    0x4f6960
  4f692a:	3b cf                	cmp    ecx,edi
  4f692c:	75 3a                	jne    0x4f6968
  4f692e:	8b 76 48             	mov    esi,DWORD PTR [esi+0x48]
  4f6931:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f6937:	56                   	push   esi
  4f6938:	6a 06                	push   0x6
  4f693a:	e8 e1 5f f9 ff       	call   0x48c920
  4f693f:	83 f8 3c             	cmp    eax,0x3c
  4f6942:	7c 24                	jl     0x4f6968
  4f6944:	eb 1a                	jmp    0x4f6960
  4f6946:	3b cf                	cmp    ecx,edi
  4f6948:	75 1e                	jne    0x4f6968
  4f694a:	8b 76 48             	mov    esi,DWORD PTR [esi+0x48]
  4f694d:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f6953:	56                   	push   esi
  4f6954:	6a 07                	push   0x7
  4f6956:	e8 c5 5f f9 ff       	call   0x48c920
  4f695b:	83 f8 3c             	cmp    eax,0x3c
  4f695e:	7c 08                	jl     0x4f6968
  4f6960:	c6 84 2b c4 00 00 00 	mov    BYTE PTR [ebx+ebp*1+0xc4],0x1
  4f6967:	01 
  4f6968:	8b 6c 24 18          	mov    ebp,DWORD PTR [esp+0x18]
  4f696c:	45                   	inc    ebp
  4f696d:	83 fd 03             	cmp    ebp,0x3
  4f6970:	89 6c 24 18          	mov    DWORD PTR [esp+0x18],ebp
  4f6974:	0f 8c 88 f6 ff ff    	jl     0x4f6002
  4f697a:	8a 44 24 50          	mov    al,BYTE PTR [esp+0x50]
  4f697e:	84 c0                	test   al,al
  4f6980:	74 19                	je     0x4f699b
  4f6982:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  4f6986:	c6 80 c4 00 00 00 01 	mov    BYTE PTR [eax+0xc4],0x1
  4f698d:	c6 80 c5 00 00 00 01 	mov    BYTE PTR [eax+0xc5],0x1
  4f6994:	c6 80 c6 00 00 00 01 	mov    BYTE PTR [eax+0xc6],0x1
  4f699b:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  4f699f:	33 ff                	xor    edi,edi
  4f69a1:	33 c0                	xor    eax,eax
  4f69a3:	8a 91 c4 00 00 00    	mov    dl,BYTE PTR [ecx+0xc4]
  4f69a9:	84 d2                	test   dl,dl
  4f69ab:	74 05                	je     0x4f69b2
  4f69ad:	b8 01 00 00 00       	mov    eax,0x1
  4f69b2:	8a 91 c5 00 00 00    	mov    dl,BYTE PTR [ecx+0xc5]
  4f69b8:	84 d2                	test   dl,dl
  4f69ba:	74 01                	je     0x4f69bd
  4f69bc:	40                   	inc    eax
  4f69bd:	8a 91 c6 00 00 00    	mov    dl,BYTE PTR [ecx+0xc6]
  4f69c3:	84 d2                	test   dl,dl
  4f69c5:	74 01                	je     0x4f69c8
  4f69c7:	40                   	inc    eax
  4f69c8:	3b 44 24 28          	cmp    eax,DWORD PTR [esp+0x28]
  4f69cc:	75 0e                	jne    0x4f69dc
  4f69ce:	83 7c 24 2c 03       	cmp    DWORD PTR [esp+0x2c],0x3
  4f69d3:	74 07                	je     0x4f69dc
  4f69d5:	c6 81 cc 00 00 00 01 	mov    BYTE PTR [ecx+0xcc],0x1
  4f69dc:	33 db                	xor    ebx,ebx
  4f69de:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  4f69e2:	be 24 02 00 00       	mov    esi,0x224
  4f69e7:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4f69ec:	8b 04 06             	mov    eax,DWORD PTR [esi+eax*1]
  4f69ef:	85 c0                	test   eax,eax
  4f69f1:	74 2d                	je     0x4f6a20
  4f69f3:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f69f9:	8b 68 08             	mov    ebp,DWORD PTR [eax+0x8]
  4f69fc:	e8 1f be f8 ff       	call   0x482820
  4f6a01:	3b e8                	cmp    ebp,eax
  4f6a03:	74 1b                	je     0x4f6a20
  4f6a05:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f6a0b:	43                   	inc    ebx
  4f6a0c:	8b 91 90 00 00 00    	mov    edx,DWORD PTR [ecx+0x90]
  4f6a12:	83 bc 3a 2c 01 00 00 	cmp    DWORD PTR [edx+edi*1+0x12c],0x18
  4f6a19:	18 
  4f6a1a:	75 04                	jne    0x4f6a20
  4f6a1c:	ff 44 24 14          	inc    DWORD PTR [esp+0x14]
  4f6a20:	83 c6 04             	add    esi,0x4
  4f6a23:	81 c7 68 01 00 00    	add    edi,0x168
  4f6a29:	81 fe 3c 02 00 00    	cmp    esi,0x23c
  4f6a2f:	7c b6                	jl     0x4f69e7
  4f6a31:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4f6a35:	5f                   	pop    edi
  4f6a36:	5e                   	pop    esi
  4f6a37:	5d                   	pop    ebp
  4f6a38:	3b d8                	cmp    ebx,eax
  4f6a3a:	5b                   	pop    ebx
  4f6a3b:	75 0b                	jne    0x4f6a48
  4f6a3d:	8b 44 24 0c          	mov    eax,DWORD PTR [esp+0xc]
  4f6a41:	c6 80 cc 00 00 00 01 	mov    BYTE PTR [eax+0xcc],0x1
  4f6a48:	8b 4c 24 0c          	mov    ecx,DWORD PTR [esp+0xc]
  4f6a4c:	8a 81 cc 00 00 00    	mov    al,BYTE PTR [ecx+0xcc]
  4f6a52:	84 c0                	test   al,al
  4f6a54:	74 40                	je     0x4f6a96
  4f6a56:	8b 15 2c 10 58 00    	mov    edx,DWORD PTR ds:0x58102c
  4f6a5c:	a1 14 1b 58 00       	mov    eax,ds:0x581b14
  4f6a61:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4f6a67:	52                   	push   edx
  4f6a68:	50                   	push   eax
  4f6a69:	6a 00                	push   0x0
  4f6a6b:	6a 04                	push   0x4
  4f6a6d:	6a 01                	push   0x1
  4f6a6f:	6a 06                	push   0x6
  4f6a71:	6a 25                	push   0x25
  4f6a73:	51                   	push   ecx
  4f6a74:	e8 17 55 f9 ff       	call   0x48bf90
  4f6a79:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4f6a7e:	83 c4 20             	add    esp,0x20
  4f6a81:	8b 90 ec 02 00 00    	mov    edx,DWORD PTR [eax+0x2ec]
  4f6a87:	8b 8c 90 00 02 00 00 	mov    ecx,DWORD PTR [eax+edx*4+0x200]
  4f6a8e:	e8 2d 72 fe ff       	call   0x4ddcc0
  4f6a93:	ff 40 30             	inc    DWORD PTR [eax+0x30]
  4f6a96:	83 c4 38             	add    esp,0x38
  4f6a99:	c2                   	.byte 0xc2
  4f6a9a:	08                   	.byte 0x8
```

## `Game_CountRecordsWithFlag16F4` — `0x4de710`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x4de710.c`
- Callers: `Mission_EvaluateGoals` (0x4f5fd0)
- Callees: `IDMap_Lookup` (0x4017f0)

- Unresolved questions: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

004de710 <.text+0xdd710>:
  4de710:	55                   	push   ebp
  4de711:	56                   	push   esi
  4de712:	57                   	push   edi
  4de713:	8b f9                	mov    edi,ecx
  4de715:	33 ed                	xor    ebp,ebp
  4de717:	33 f6                	xor    esi,esi
  4de719:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4de71f:	85 c0                	test   eax,eax
  4de721:	7e 2e                	jle    0x4de751
  4de723:	53                   	push   ebx
  4de724:	8d 9f 48 01 00 00    	lea    ebx,[edi+0x148]
  4de72a:	6a 00                	push   0x0
  4de72c:	56                   	push   esi
  4de72d:	8b cb                	mov    ecx,ebx
  4de72f:	e8 bc 30 f2 ff       	call   0x4017f0
  4de734:	8a 88 f4 16 00 00    	mov    cl,BYTE PTR [eax+0x16f4]
  4de73a:	84 c9                	test   cl,cl
  4de73c:	74 01                	je     0x4de73f
  4de73e:	45                   	inc    ebp
  4de73f:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4de745:	46                   	inc    esi
  4de746:	3b f0                	cmp    esi,eax
  4de748:	7c e0                	jl     0x4de72a
  4de74a:	5b                   	pop    ebx
  4de74b:	5f                   	pop    edi
  4de74c:	8b c5                	mov    eax,ebp
  4de74e:	5e                   	pop    esi
  4de74f:	5d                   	pop    ebp
  4de750:	c3                   	ret
  4de751:	5f                   	pop    edi
  4de752:	8b c5                	mov    eax,ebp
  4de754:	5e                   	pop    esi
  4de755:	5d                   	pop    ebp
```

## `Stats_Report_FillCompanyOverview` — `0x4decf0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x4decf0.c`
- Callers: `Company_RecordDailyStatistics` (0x4dec10)
- Callees: `City_CollectBuildingsByType` (0x4d59c0), `Game_GetPlayerBySlot` (0x488be0), `Game_GetPlayerFieldC20` (0x4e2280), `Get_Field2C` (0x513fd0), `IDMap_Lookup` (0x4017f0)

- Unresolved questions: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

004decf0 <.text+0xddcf0>:
  4decf0:	83 ec 10             	sub    esp,0x10
  4decf3:	53                   	push   ebx
  4decf4:	55                   	push   ebp
  4decf5:	56                   	push   esi
  4decf6:	8b 74 24 20          	mov    esi,DWORD PTR [esp+0x20]
  4decfa:	57                   	push   edi
  4decfb:	33 ff                	xor    edi,edi
  4decfd:	8b 06                	mov    eax,DWORD PTR [esi]
  4decff:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  4ded03:	89 38                	mov    DWORD PTR [eax],edi
  4ded05:	8b 16                	mov    edx,DWORD PTR [esi]
  4ded07:	89 7a 04             	mov    DWORD PTR [edx+0x4],edi
  4ded0a:	8b 06                	mov    eax,DWORD PTR [esi]
  4ded0c:	89 b8 20 01 00 00    	mov    DWORD PTR [eax+0x120],edi
  4ded12:	8b 81 5c 01 00 00    	mov    eax,DWORD PTR [ecx+0x15c]
  4ded18:	3b c7                	cmp    eax,edi
  4ded1a:	7e 7a                	jle    0x4ded96
  4ded1c:	8d 99 48 01 00 00    	lea    ebx,[ecx+0x148]
  4ded22:	6a 00                	push   0x0
  4ded24:	57                   	push   edi
  4ded25:	8b cb                	mov    ecx,ebx
  4ded27:	e8 c4 2a f2 ff       	call   0x4017f0
  4ded2c:	8a 88 f4 16 00 00    	mov    cl,BYTE PTR [eax+0x16f4]
  4ded32:	84 c9                	test   cl,cl
  4ded34:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4ded36:	74 2a                	je     0x4ded62
  4ded38:	8b 29                	mov    ebp,DWORD PTR [ecx]
  4ded3a:	45                   	inc    ebp
  4ded3b:	89 29                	mov    DWORD PTR [ecx],ebp
  4ded3d:	8b 40 38             	mov    eax,DWORD PTR [eax+0x38]
  4ded40:	40                   	inc    eax
  4ded41:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4ded43:	8d 04 40             	lea    eax,[eax+eax*2]
  4ded46:	8d 04 80             	lea    eax,[eax+eax*4]
  4ded49:	8d 04 80             	lea    eax,[eax+eax*4]
  4ded4c:	8d 14 80             	lea    edx,[eax+eax*4]
  4ded4f:	8b 81 20 01 00 00    	mov    eax,DWORD PTR [ecx+0x120]
  4ded55:	c1 e2 02             	shl    edx,0x2
  4ded58:	03 c2                	add    eax,edx
  4ded5a:	89 81 20 01 00 00    	mov    DWORD PTR [ecx+0x120],eax
  4ded60:	eb 27                	jmp    0x4ded89
  4ded62:	8b 69 04             	mov    ebp,DWORD PTR [ecx+0x4]
  4ded65:	45                   	inc    ebp
  4ded66:	89 69 04             	mov    DWORD PTR [ecx+0x4],ebp
  4ded69:	8b 40 38             	mov    eax,DWORD PTR [eax+0x38]
  4ded6c:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4ded6e:	40                   	inc    eax
  4ded6f:	8d 04 40             	lea    eax,[eax+eax*2]
  4ded72:	8b 91 20 01 00 00    	mov    edx,DWORD PTR [ecx+0x120]
  4ded78:	8d 04 80             	lea    eax,[eax+eax*4]
  4ded7b:	8d 04 80             	lea    eax,[eax+eax*4]
  4ded7e:	c1 e0 03             	shl    eax,0x3
  4ded81:	03 d0                	add    edx,eax
  4ded83:	89 91 20 01 00 00    	mov    DWORD PTR [ecx+0x120],edx
  4ded89:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4ded8d:	47                   	inc    edi
  4ded8e:	3b b9 5c 01 00 00    	cmp    edi,DWORD PTR [ecx+0x15c]
  4ded94:	7c 8c                	jl     0x4ded22
  4ded96:	8b 16                	mov    edx,DWORD PTR [esi]
  4ded98:	33 ed                	xor    ebp,ebp
  4ded9a:	89 6a 08             	mov    DWORD PTR [edx+0x8],ebp
  4ded9d:	8b 06                	mov    eax,DWORD PTR [esi]
  4ded9f:	89 68 0c             	mov    DWORD PTR [eax+0xc],ebp
  4deda2:	8b 16                	mov    edx,DWORD PTR [esi]
  4deda4:	89 aa 24 01 00 00    	mov    DWORD PTR [edx+0x124],ebp
  4dedaa:	8b 81 94 01 00 00    	mov    eax,DWORD PTR [ecx+0x194]
  4dedb0:	3b c5                	cmp    eax,ebp
  4dedb2:	0f 8e 81 00 00 00    	jle    0x4dee39
  4dedb8:	8d 99 80 01 00 00    	lea    ebx,[ecx+0x180]
  4dedbe:	6a 00                	push   0x0
  4dedc0:	55                   	push   ebp
  4dedc1:	8b cb                	mov    ecx,ebx
  4dedc3:	e8 28 2a f2 ff       	call   0x4017f0
  4dedc8:	8b c8                	mov    ecx,eax
  4dedca:	8a 41 3c             	mov    al,BYTE PTR [ecx+0x3c]
  4dedcd:	84 c0                	test   al,al
  4dedcf:	74 30                	je     0x4dee01
  4dedd1:	8b 16                	mov    edx,DWORD PTR [esi]
  4dedd3:	8b 7a 08             	mov    edi,DWORD PTR [edx+0x8]
  4dedd6:	47                   	inc    edi
  4dedd7:	89 7a 08             	mov    DWORD PTR [edx+0x8],edi
  4dedda:	8b 3e                	mov    edi,DWORD PTR [esi]
  4deddc:	e8 ef 51 03 00       	call   0x513fd0
  4dede1:	40                   	inc    eax
  4dede2:	8b 8f 24 01 00 00    	mov    ecx,DWORD PTR [edi+0x124]
  4dede8:	8d 04 40             	lea    eax,[eax+eax*2]
  4dedeb:	8d 04 80             	lea    eax,[eax+eax*4]
  4dedee:	8d 04 80             	lea    eax,[eax+eax*4]
  4dedf1:	8d 04 80             	lea    eax,[eax+eax*4]
  4dedf4:	c1 e0 02             	shl    eax,0x2
  4dedf7:	03 c8                	add    ecx,eax
  4dedf9:	89 8f 24 01 00 00    	mov    DWORD PTR [edi+0x124],ecx
  4dedff:	eb 2b                	jmp    0x4dee2c
  4dee01:	8b 06                	mov    eax,DWORD PTR [esi]
  4dee03:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  4dee06:	42                   	inc    edx
  4dee07:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4dee0a:	8b 3e                	mov    edi,DWORD PTR [esi]
  4dee0c:	e8 bf 51 03 00       	call   0x513fd0
  4dee11:	40                   	inc    eax
  4dee12:	8d 04 40             	lea    eax,[eax+eax*2]
  4dee15:	8d 04 80             	lea    eax,[eax+eax*4]
  4dee18:	8d 0c 80             	lea    ecx,[eax+eax*4]
  4dee1b:	8b 87 24 01 00 00    	mov    eax,DWORD PTR [edi+0x124]
  4dee21:	c1 e1 03             	shl    ecx,0x3
  4dee24:	03 c1                	add    eax,ecx
  4dee26:	89 87 24 01 00 00    	mov    DWORD PTR [edi+0x124],eax
  4dee2c:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  4dee30:	45                   	inc    ebp
  4dee31:	3b aa 94 01 00 00    	cmp    ebp,DWORD PTR [edx+0x194]
  4dee37:	7c 85                	jl     0x4dedbe
  4dee39:	8b 06                	mov    eax,DWORD PTR [esi]
  4dee3b:	6a 00                	push   0x0
  4dee3d:	c7 40 10 00 00 00 00 	mov    DWORD PTR [eax+0x10],0x0
  4dee44:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4dee49:	8b 88 f4 02 00 00    	mov    ecx,DWORD PTR [eax+0x2f4]
  4dee4f:	51                   	push   ecx
  4dee50:	8d 48 04             	lea    ecx,[eax+0x4]
  4dee53:	e8 98 29 f2 ff       	call   0x4017f0
  4dee58:	6a 00                	push   0x0
  4dee5a:	6a 00                	push   0x0
  4dee5c:	6a 11                	push   0x11
  4dee5e:	8b c8                	mov    ecx,eax
  4dee60:	e8 5b 6b ff ff       	call   0x4d59c0
  4dee65:	8b f8                	mov    edi,eax
  4dee67:	33 ed                	xor    ebp,ebp
  4dee69:	8b 47 14             	mov    eax,DWORD PTR [edi+0x14]
  4dee6c:	85 c0                	test   eax,eax
  4dee6e:	7e 23                	jle    0x4dee93
  4dee70:	6a 00                	push   0x0
  4dee72:	55                   	push   ebp
  4dee73:	8b cf                	mov    ecx,edi
  4dee75:	e8 76 29 f2 ff       	call   0x4017f0
  4dee7a:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  4dee7d:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  4dee81:	3b 50 48             	cmp    edx,DWORD PTR [eax+0x48]
  4dee84:	75 05                	jne    0x4dee8b
  4dee86:	8b 06                	mov    eax,DWORD PTR [esi]
  4dee88:	ff 40 10             	inc    DWORD PTR [eax+0x10]
  4dee8b:	8b 47 14             	mov    eax,DWORD PTR [edi+0x14]
  4dee8e:	45                   	inc    ebp
  4dee8f:	3b e8                	cmp    ebp,eax
  4dee91:	7c dd                	jl     0x4dee70
  4dee93:	33 db                	xor    ebx,ebx
  4dee95:	33 c0                	xor    eax,eax
  4dee97:	c7 44 24 24 06 00 00 	mov    DWORD PTR [esp+0x24],0x6
  4dee9e:	00 
  4dee9f:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4deea3:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4deea9:	50                   	push   eax
  4deeaa:	e8 31 9d fa ff       	call   0x488be0
  4deeaf:	8b f8                	mov    edi,eax
  4deeb1:	85 ff                	test   edi,edi
  4deeb3:	0f 84 96 00 00 00    	je     0x4def4f
  4deeb9:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4deebe:	8b 6f 48             	mov    ebp,DWORD PTR [edi+0x48]
  4deec1:	6a 00                	push   0x0
  4deec3:	8b 88 f4 02 00 00    	mov    ecx,DWORD PTR [eax+0x2f4]
  4deec9:	51                   	push   ecx
  4deeca:	8d 48 04             	lea    ecx,[eax+0x4]
  4deecd:	e8 1e 29 f2 ff       	call   0x4017f0
  4deed2:	8b 8c a8 b0 0c 00 00 	mov    ecx,DWORD PTR [eax+ebp*4+0xcb0]
  4deed9:	8b 6c 24 10          	mov    ebp,DWORD PTR [esp+0x10]
  4deedd:	03 d9                	add    ebx,ecx
  4deedf:	3b fd                	cmp    edi,ebp
  4deee1:	75 26                	jne    0x4def09
  4deee3:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4deee8:	8b 7f 48             	mov    edi,DWORD PTR [edi+0x48]
  4deeeb:	6a 00                	push   0x0
  4deeed:	8b 90 f4 02 00 00    	mov    edx,DWORD PTR [eax+0x2f4]
  4deef3:	8d 48 04             	lea    ecx,[eax+0x4]
  4deef6:	52                   	push   edx
  4deef7:	e8 f4 28 f2 ff       	call   0x4017f0
  4deefc:	8b 84 b8 b0 0c 00 00 	mov    eax,DWORD PTR [eax+edi*4+0xcb0]
  4def03:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  4def07:	eb 46                	jmp    0x4def4f
  4def09:	8b cf                	mov    ecx,edi
  4def0b:	e8 70 33 00 00       	call   0x4e2280
  4def10:	8b d0                	mov    edx,eax
  4def12:	8b cd                	mov    ecx,ebp
  4def14:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  4def18:	e8 63 33 00 00       	call   0x4e2280
  4def1d:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4def21:	3b c8                	cmp    ecx,eax
  4def23:	7e 04                	jle    0x4def29
  4def25:	ff 4c 24 24          	dec    DWORD PTR [esp+0x24]
  4def29:	8b cf                	mov    ecx,edi
  4def2b:	e8 50 33 00 00       	call   0x4e2280
  4def30:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4def34:	8b e8                	mov    ebp,eax
  4def36:	e8 45 33 00 00       	call   0x4e2280
  4def3b:	3b e8                	cmp    ebp,eax
  4def3d:	75 10                	jne    0x4def4f
  4def3f:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  4def43:	8b 57 60             	mov    edx,DWORD PTR [edi+0x60]
  4def46:	3b 50 60             	cmp    edx,DWORD PTR [eax+0x60]
  4def49:	7d 04                	jge    0x4def4f
  4def4b:	ff 4c 24 24          	dec    DWORD PTR [esp+0x24]
  4def4f:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4def53:	40                   	inc    eax
  4def54:	83 f8 06             	cmp    eax,0x6
  4def57:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4def5b:	0f 8c 42 ff ff ff    	jl     0x4deea3
  4def61:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4def63:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  4def67:	85 db                	test   ebx,ebx
  4def69:	89 41 14             	mov    DWORD PTR [ecx+0x14],eax
  4def6c:	7e 13                	jle    0x4def81
  4def6e:	6b c0 64             	imul   eax,eax,0x64
  4def71:	99                   	cdq
  4def72:	f7 fb                	idiv   ebx
  4def74:	8b 16                	mov    edx,DWORD PTR [esi]
  4def76:	6b c0 64             	imul   eax,eax,0x64
  4def79:	89 82 28 01 00 00    	mov    DWORD PTR [edx+0x128],eax
  4def7f:	eb 0c                	jmp    0x4def8d
  4def81:	8b 06                	mov    eax,DWORD PTR [esi]
  4def83:	c7 80 28 01 00 00 00 	mov    DWORD PTR [eax+0x128],0x0
  4def8a:	00 00 00 
  4def8d:	8b 7c 24 10          	mov    edi,DWORD PTR [esp+0x10]
  4def91:	8b cf                	mov    ecx,edi
  4def93:	e8 e8 32 00 00       	call   0x4e2280
  4def98:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4def9a:	89 41 18             	mov    DWORD PTR [ecx+0x18],eax
  4def9d:	8b 16                	mov    edx,DWORD PTR [esi]
  4def9f:	8b 47 60             	mov    eax,DWORD PTR [edi+0x60]
  4defa2:	8b cf                	mov    ecx,edi
  4defa4:	89 42 1c             	mov    DWORD PTR [edx+0x1c],eax
  4defa7:	e8 d4 32 00 00       	call   0x4e2280
  4defac:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  4defb0:	5f                   	pop    edi
  4defb1:	8d 14 41             	lea    edx,[ecx+eax*2]
  4defb4:	8b 06                	mov    eax,DWORD PTR [esi]
  4defb6:	69 d2 e8 03 00 00    	imul   edx,edx,0x3e8
  4defbc:	5e                   	pop    esi
  4defbd:	5d                   	pop    ebp
  4defbe:	89 90 2c 01 00 00    	mov    DWORD PTR [eax+0x12c],edx
  4defc4:	5b                   	pop    ebx
  4defc5:	83 c4 10             	add    esp,0x10
  4defc8:	c2                   	.byte 0xc2
  4defc9:	04                   	.byte 0x4
```

## `Branch_Load` — `0x47b000`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x47b000.c`
- Callers: `Branch_ConstructFromStream` (0x477000)
- Callees: `Branch_ApplyBuildingStyleVariant` (0x47e6a0), `CRT_Istream_Read` (0x54cbc1), `ConstructionOrder_StreamConstruct` (0x4e5dc0), `Game_GetSizeName` (0x47e5e0), `Game_ShowBuildingOverlay` (0x47fe10), `Game_UpdateIDMapEntry` (0x4eacd0), `IDMap_InsertGrow` (0x4015b0), `IDMap_Lookup` (0x4017f0), `IsoMap_MarkPlayerFootprints` (0x4f2e50), `List_Add` (0x4014b0), `StatsPeriodReport_StreamConstruct` (0x401000)

- Unresolved questions: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

0047b000 <.text+0x7a000>:
  47b000:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b006:	6a ff                	push   0xffffffff
  47b008:	68 6c 7f 55 00       	push   0x557f6c
  47b00d:	50                   	push   eax
  47b00e:	64 89 25 00 00 00 00 	mov    DWORD PTR fs:0x0,esp
  47b015:	83 ec 10             	sub    esp,0x10
  47b018:	53                   	push   ebx
  47b019:	55                   	push   ebp
  47b01a:	56                   	push   esi
  47b01b:	8b 74 24 2c          	mov    esi,DWORD PTR [esp+0x2c]
  47b01f:	57                   	push   edi
  47b020:	8b f9                	mov    edi,ecx
  47b022:	6a 20                	push   0x20
  47b024:	8b ce                	mov    ecx,esi
  47b026:	8d 47 04             	lea    eax,[edi+0x4]
  47b029:	50                   	push   eax
  47b02a:	e8 92 1b 0d 00       	call   0x54cbc1
  47b02f:	8d 4f 2c             	lea    ecx,[edi+0x2c]
  47b032:	6a 04                	push   0x4
  47b034:	51                   	push   ecx
  47b035:	8b ce                	mov    ecx,esi
  47b037:	e8 85 1b 0d 00       	call   0x54cbc1
  47b03c:	8d 57 24             	lea    edx,[edi+0x24]
  47b03f:	6a 04                	push   0x4
  47b041:	52                   	push   edx
  47b042:	8b ce                	mov    ecx,esi
  47b044:	e8 78 1b 0d 00       	call   0x54cbc1
  47b049:	8d 47 28             	lea    eax,[edi+0x28]
  47b04c:	6a 04                	push   0x4
  47b04e:	50                   	push   eax
  47b04f:	8b ce                	mov    ecx,esi
  47b051:	e8 6b 1b 0d 00       	call   0x54cbc1
  47b056:	8d 4f 30             	lea    ecx,[edi+0x30]
  47b059:	6a 04                	push   0x4
  47b05b:	51                   	push   ecx
  47b05c:	8b ce                	mov    ecx,esi
  47b05e:	e8 5e 1b 0d 00       	call   0x54cbc1
  47b063:	8d 6f 34             	lea    ebp,[edi+0x34]
  47b066:	6a 04                	push   0x4
  47b068:	55                   	push   ebp
  47b069:	8b ce                	mov    ecx,esi
  47b06b:	e8 51 1b 0d 00       	call   0x54cbc1
  47b070:	8d 57 3c             	lea    edx,[edi+0x3c]
  47b073:	6a 04                	push   0x4
  47b075:	52                   	push   edx
  47b076:	8b ce                	mov    ecx,esi
  47b078:	e8 44 1b 0d 00       	call   0x54cbc1
  47b07d:	8d 47 40             	lea    eax,[edi+0x40]
  47b080:	6a 04                	push   0x4
  47b082:	50                   	push   eax
  47b083:	8b ce                	mov    ecx,esi
  47b085:	e8 37 1b 0d 00       	call   0x54cbc1
  47b08a:	8d 4f 44             	lea    ecx,[edi+0x44]
  47b08d:	68 44 01 00 00       	push   0x144
  47b092:	51                   	push   ecx
  47b093:	8b ce                	mov    ecx,esi
  47b095:	e8 27 1b 0d 00       	call   0x54cbc1
  47b09a:	8d 97 88 01 00 00    	lea    edx,[edi+0x188]
  47b0a0:	68 44 01 00 00       	push   0x144
  47b0a5:	52                   	push   edx
  47b0a6:	8b ce                	mov    ecx,esi
  47b0a8:	e8 14 1b 0d 00       	call   0x54cbc1
  47b0ad:	8d 87 54 05 00 00    	lea    eax,[edi+0x554]
  47b0b3:	68 10 0e 00 00       	push   0xe10
  47b0b8:	50                   	push   eax
  47b0b9:	8b ce                	mov    ecx,esi
  47b0bb:	e8 01 1b 0d 00       	call   0x54cbc1
  47b0c0:	8d 8f 64 13 00 00    	lea    ecx,[edi+0x1364]
  47b0c6:	6a 24                	push   0x24
  47b0c8:	51                   	push   ecx
  47b0c9:	8b ce                	mov    ecx,esi
  47b0cb:	e8 f1 1a 0d 00       	call   0x54cbc1
  47b0d0:	8d 97 cc 02 00 00    	lea    edx,[edi+0x2cc]
  47b0d6:	68 44 01 00 00       	push   0x144
  47b0db:	52                   	push   edx
  47b0dc:	8b ce                	mov    ecx,esi
  47b0de:	e8 de 1a 0d 00       	call   0x54cbc1
  47b0e3:	8d 87 10 04 00 00    	lea    eax,[edi+0x410]
  47b0e9:	68 44 01 00 00       	push   0x144
  47b0ee:	50                   	push   eax
  47b0ef:	8b ce                	mov    ecx,esi
  47b0f1:	e8 cb 1a 0d 00       	call   0x54cbc1
  47b0f6:	8d 8f 88 13 00 00    	lea    ecx,[edi+0x1388]
  47b0fc:	6a 48                	push   0x48
  47b0fe:	51                   	push   ecx
  47b0ff:	8b ce                	mov    ecx,esi
  47b101:	e8 bb 1a 0d 00       	call   0x54cbc1
  47b106:	8d 97 d0 13 00 00    	lea    edx,[edi+0x13d0]
  47b10c:	6a 48                	push   0x48
  47b10e:	52                   	push   edx
  47b10f:	8b ce                	mov    ecx,esi
  47b111:	e8 ab 1a 0d 00       	call   0x54cbc1
  47b116:	8d 87 18 14 00 00    	lea    eax,[edi+0x1418]
  47b11c:	6a 48                	push   0x48
  47b11e:	50                   	push   eax
  47b11f:	8b ce                	mov    ecx,esi
  47b121:	e8 9b 1a 0d 00       	call   0x54cbc1
  47b126:	8d 8f 60 14 00 00    	lea    ecx,[edi+0x1460]
  47b12c:	6a 48                	push   0x48
  47b12e:	51                   	push   ecx
  47b12f:	8b ce                	mov    ecx,esi
  47b131:	e8 8b 1a 0d 00       	call   0x54cbc1
  47b136:	8d 97 a8 14 00 00    	lea    edx,[edi+0x14a8]
  47b13c:	6a 04                	push   0x4
  47b13e:	52                   	push   edx
  47b13f:	8b ce                	mov    ecx,esi
  47b141:	e8 7b 1a 0d 00       	call   0x54cbc1
  47b146:	8d 87 ac 14 00 00    	lea    eax,[edi+0x14ac]
  47b14c:	6a 04                	push   0x4
  47b14e:	50                   	push   eax
  47b14f:	8b ce                	mov    ecx,esi
  47b151:	e8 6b 1a 0d 00       	call   0x54cbc1
  47b156:	8d 8f c8 14 00 00    	lea    ecx,[edi+0x14c8]
  47b15c:	6a 04                	push   0x4
  47b15e:	51                   	push   ecx
  47b15f:	8b ce                	mov    ecx,esi
  47b161:	e8 5b 1a 0d 00       	call   0x54cbc1
  47b166:	8d 97 cc 14 00 00    	lea    edx,[edi+0x14cc]
  47b16c:	6a 04                	push   0x4
  47b16e:	52                   	push   edx
  47b16f:	8b ce                	mov    ecx,esi
  47b171:	e8 4b 1a 0d 00       	call   0x54cbc1
  47b176:	8d 87 d0 14 00 00    	lea    eax,[edi+0x14d0]
  47b17c:	6a 04                	push   0x4
  47b17e:	50                   	push   eax
  47b17f:	8b ce                	mov    ecx,esi
  47b181:	e8 3b 1a 0d 00       	call   0x54cbc1
  47b186:	8d 8f d4 14 00 00    	lea    ecx,[edi+0x14d4]
  47b18c:	6a 04                	push   0x4
  47b18e:	51                   	push   ecx
  47b18f:	8b ce                	mov    ecx,esi
  47b191:	e8 2b 1a 0d 00       	call   0x54cbc1
  47b196:	8d 97 c0 14 00 00    	lea    edx,[edi+0x14c0]
  47b19c:	6a 04                	push   0x4
  47b19e:	52                   	push   edx
  47b19f:	8b ce                	mov    ecx,esi
  47b1a1:	e8 1b 1a 0d 00       	call   0x54cbc1
  47b1a6:	8d 87 d8 14 00 00    	lea    eax,[edi+0x14d8]
  47b1ac:	6a 04                	push   0x4
  47b1ae:	50                   	push   eax
  47b1af:	8b ce                	mov    ecx,esi
  47b1b1:	e8 0b 1a 0d 00       	call   0x54cbc1
  47b1b6:	8d 8f f5 16 00 00    	lea    ecx,[edi+0x16f5]
  47b1bc:	6a 01                	push   0x1
  47b1be:	51                   	push   ecx
  47b1bf:	8b ce                	mov    ecx,esi
  47b1c1:	e8 fb 19 0d 00       	call   0x54cbc1
  47b1c6:	8d 97 f4 16 00 00    	lea    edx,[edi+0x16f4]
  47b1cc:	6a 01                	push   0x1
  47b1ce:	52                   	push   edx
  47b1cf:	8b ce                	mov    ecx,esi
  47b1d1:	e8 eb 19 0d 00       	call   0x54cbc1
  47b1d6:	8d 87 b0 14 00 00    	lea    eax,[edi+0x14b0]
  47b1dc:	6a 04                	push   0x4
  47b1de:	50                   	push   eax
  47b1df:	8b ce                	mov    ecx,esi
  47b1e1:	e8 db 19 0d 00       	call   0x54cbc1
  47b1e6:	8d 8f 14 17 00 00    	lea    ecx,[edi+0x1714]
  47b1ec:	6a 04                	push   0x4
  47b1ee:	51                   	push   ecx
  47b1ef:	8b ce                	mov    ecx,esi
  47b1f1:	e8 cb 19 0d 00       	call   0x54cbc1
  47b1f6:	8d 97 18 17 00 00    	lea    edx,[edi+0x1718]
  47b1fc:	6a 04                	push   0x4
  47b1fe:	52                   	push   edx
  47b1ff:	8b ce                	mov    ecx,esi
  47b201:	e8 bb 19 0d 00       	call   0x54cbc1
  47b206:	8d 87 1c 17 00 00    	lea    eax,[edi+0x171c]
  47b20c:	6a 04                	push   0x4
  47b20e:	50                   	push   eax
  47b20f:	8b ce                	mov    ecx,esi
  47b211:	e8 ab 19 0d 00       	call   0x54cbc1
  47b216:	8d 8f 20 17 00 00    	lea    ecx,[edi+0x1720]
  47b21c:	6a 04                	push   0x4
  47b21e:	51                   	push   ecx
  47b21f:	8b ce                	mov    ecx,esi
  47b221:	e8 9b 19 0d 00       	call   0x54cbc1
  47b226:	8d 97 24 17 00 00    	lea    edx,[edi+0x1724]
  47b22c:	6a 04                	push   0x4
  47b22e:	52                   	push   edx
  47b22f:	8b ce                	mov    ecx,esi
  47b231:	e8 8b 19 0d 00       	call   0x54cbc1
  47b236:	8d 87 1c 15 00 00    	lea    eax,[edi+0x151c]
  47b23c:	68 a0 01 00 00       	push   0x1a0
  47b241:	50                   	push   eax
  47b242:	8b ce                	mov    ecx,esi
  47b244:	e8 78 19 0d 00       	call   0x54cbc1
  47b249:	8d 8f bc 16 00 00    	lea    ecx,[edi+0x16bc]
  47b24f:	6a 34                	push   0x34
  47b251:	51                   	push   ecx
  47b252:	8b ce                	mov    ecx,esi
  47b254:	e8 68 19 0d 00       	call   0x54cbc1
  47b259:	8d 97 7c 17 00 00    	lea    edx,[edi+0x177c]
  47b25f:	6a 20                	push   0x20
  47b261:	52                   	push   edx
  47b262:	8b ce                	mov    ecx,esi
  47b264:	e8 58 19 0d 00       	call   0x54cbc1
  47b269:	8d 87 9c 17 00 00    	lea    eax,[edi+0x179c]
  47b26f:	6a 20                	push   0x20
  47b271:	50                   	push   eax
  47b272:	8b ce                	mov    ecx,esi
  47b274:	e8 48 19 0d 00       	call   0x54cbc1
  47b279:	8d 8f bc 17 00 00    	lea    ecx,[edi+0x17bc]
  47b27f:	6a 20                	push   0x20
  47b281:	51                   	push   ecx
  47b282:	8b ce                	mov    ecx,esi
  47b284:	e8 38 19 0d 00       	call   0x54cbc1
  47b289:	8d 97 dc 17 00 00    	lea    edx,[edi+0x17dc]
  47b28f:	6a 20                	push   0x20
  47b291:	52                   	push   edx
  47b292:	8b ce                	mov    ecx,esi
  47b294:	e8 28 19 0d 00       	call   0x54cbc1
  47b299:	8d 87 fc 17 00 00    	lea    eax,[edi+0x17fc]
  47b29f:	6a 20                	push   0x20
  47b2a1:	50                   	push   eax
  47b2a2:	8b ce                	mov    ecx,esi
  47b2a4:	e8 18 19 0d 00       	call   0x54cbc1
  47b2a9:	8d 8f 1c 18 00 00    	lea    ecx,[edi+0x181c]
  47b2af:	6a 20                	push   0x20
  47b2b1:	51                   	push   ecx
  47b2b2:	8b ce                	mov    ecx,esi
  47b2b4:	e8 08 19 0d 00       	call   0x54cbc1
  47b2b9:	8d 97 3c 18 00 00    	lea    edx,[edi+0x183c]
  47b2bf:	6a 14                	push   0x14
  47b2c1:	52                   	push   edx
  47b2c2:	8b ce                	mov    ecx,esi
  47b2c4:	e8 f8 18 0d 00       	call   0x54cbc1
  47b2c9:	8d 87 50 18 00 00    	lea    eax,[edi+0x1850]
  47b2cf:	6a 04                	push   0x4
  47b2d1:	50                   	push   eax
  47b2d2:	8b ce                	mov    ecx,esi
  47b2d4:	e8 e8 18 0d 00       	call   0x54cbc1
  47b2d9:	8d 8f 54 18 00 00    	lea    ecx,[edi+0x1854]
  47b2df:	6a 04                	push   0x4
  47b2e1:	51                   	push   ecx
  47b2e2:	8b ce                	mov    ecx,esi
  47b2e4:	e8 d8 18 0d 00       	call   0x54cbc1
  47b2e9:	8d 97 58 18 00 00    	lea    edx,[edi+0x1858]
  47b2ef:	6a 04                	push   0x4
  47b2f1:	52                   	push   edx
  47b2f2:	8b ce                	mov    ecx,esi
  47b2f4:	e8 c8 18 0d 00       	call   0x54cbc1
  47b2f9:	6a 04                	push   0x4
  47b2fb:	8d 87 5c 18 00 00    	lea    eax,[edi+0x185c]
  47b301:	8b ce                	mov    ecx,esi
  47b303:	50                   	push   eax
  47b304:	e8 b8 18 0d 00       	call   0x54cbc1
  47b309:	8d 8f 60 18 00 00    	lea    ecx,[edi+0x1860]
  47b30f:	6a 04                	push   0x4
  47b311:	51                   	push   ecx
  47b312:	8b ce                	mov    ecx,esi
  47b314:	e8 a8 18 0d 00       	call   0x54cbc1
  47b319:	8d 97 64 18 00 00    	lea    edx,[edi+0x1864]
  47b31f:	6a 04                	push   0x4
  47b321:	52                   	push   edx
  47b322:	8b ce                	mov    ecx,esi
  47b324:	e8 98 18 0d 00       	call   0x54cbc1
  47b329:	8d 87 68 18 00 00    	lea    eax,[edi+0x1868]
  47b32f:	6a 04                	push   0x4
  47b331:	50                   	push   eax
  47b332:	8b ce                	mov    ecx,esi
  47b334:	e8 88 18 0d 00       	call   0x54cbc1
  47b339:	8d 8f 6c 18 00 00    	lea    ecx,[edi+0x186c]
  47b33f:	6a 04                	push   0x4
  47b341:	51                   	push   ecx
  47b342:	8b ce                	mov    ecx,esi
  47b344:	e8 78 18 0d 00       	call   0x54cbc1
  47b349:	8d 97 70 18 00 00    	lea    edx,[edi+0x1870]
  47b34f:	6a 04                	push   0x4
  47b351:	52                   	push   edx
  47b352:	8b ce                	mov    ecx,esi
  47b354:	e8 68 18 0d 00       	call   0x54cbc1
  47b359:	8d 87 74 18 00 00    	lea    eax,[edi+0x1874]
  47b35f:	6a 04                	push   0x4
  47b361:	50                   	push   eax
  47b362:	8b ce                	mov    ecx,esi
  47b364:	e8 58 18 0d 00       	call   0x54cbc1
  47b369:	8d 8f 78 18 00 00    	lea    ecx,[edi+0x1878]
  47b36f:	6a 04                	push   0x4
  47b371:	51                   	push   ecx
  47b372:	8b ce                	mov    ecx,esi
  47b374:	e8 48 18 0d 00       	call   0x54cbc1
  47b379:	8d 57 38             	lea    edx,[edi+0x38]
  47b37c:	6a 04                	push   0x4
  47b37e:	52                   	push   edx
  47b37f:	8b ce                	mov    ecx,esi
  47b381:	e8 3b 18 0d 00       	call   0x54cbc1
  47b386:	8d 87 98 18 00 00    	lea    eax,[edi+0x1898]
  47b38c:	6a 40                	push   0x40
  47b38e:	50                   	push   eax
  47b38f:	8b ce                	mov    ecx,esi
  47b391:	e8 2b 18 0d 00       	call   0x54cbc1
  47b396:	8d 8f d8 18 00 00    	lea    ecx,[edi+0x18d8]
  47b39c:	68 c0 00 00 00       	push   0xc0
  47b3a1:	51                   	push   ecx
  47b3a2:	8b ce                	mov    ecx,esi
  47b3a4:	e8 18 18 0d 00       	call   0x54cbc1
  47b3a9:	8d 97 7c 18 00 00    	lea    edx,[edi+0x187c]
  47b3af:	6a 04                	push   0x4
  47b3b1:	52                   	push   edx
  47b3b2:	8b ce                	mov    ecx,esi
  47b3b4:	e8 08 18 0d 00       	call   0x54cbc1
  47b3b9:	8d 9f fc 19 00 00    	lea    ebx,[edi+0x19fc]
  47b3bf:	6a 04                	push   0x4
  47b3c1:	53                   	push   ebx
  47b3c2:	8b ce                	mov    ecx,esi
  47b3c4:	e8 f8 17 0d 00       	call   0x54cbc1
  47b3c9:	8d 87 00 1a 00 00    	lea    eax,[edi+0x1a00]
  47b3cf:	6a 04                	push   0x4
  47b3d1:	50                   	push   eax
  47b3d2:	8b ce                	mov    ecx,esi
  47b3d4:	e8 e8 17 0d 00       	call   0x54cbc1
  47b3d9:	8d 87 04 1a 00 00    	lea    eax,[edi+0x1a04]
  47b3df:	6a 04                	push   0x4
  47b3e1:	50                   	push   eax
  47b3e2:	8b ce                	mov    ecx,esi
  47b3e4:	e8 d8 17 0d 00       	call   0x54cbc1
  47b3e9:	8d 87 80 18 00 00    	lea    eax,[edi+0x1880]
  47b3ef:	6a 04                	push   0x4
  47b3f1:	50                   	push   eax
  47b3f2:	8b ce                	mov    ecx,esi
  47b3f4:	e8 c8 17 0d 00       	call   0x54cbc1
  47b3f9:	6a 10                	push   0x10
  47b3fb:	8d 8f b4 19 00 00    	lea    ecx,[edi+0x19b4]
  47b401:	51                   	push   ecx
  47b402:	8b ce                	mov    ecx,esi
  47b404:	e8 b8 17 0d 00       	call   0x54cbc1
  47b409:	8d 97 b4 14 00 00    	lea    edx,[edi+0x14b4]
  47b40f:	6a 04                	push   0x4
  47b411:	52                   	push   edx
  47b412:	8b ce                	mov    ecx,esi
  47b414:	e8 a8 17 0d 00       	call   0x54cbc1
  47b419:	8d 87 20 1a 00 00    	lea    eax,[edi+0x1a20]
  47b41f:	6a 01                	push   0x1
  47b421:	50                   	push   eax
  47b422:	8b ce                	mov    ecx,esi
  47b424:	e8 98 17 0d 00       	call   0x54cbc1
  47b429:	8d 87 21 1a 00 00    	lea    eax,[edi+0x1a21]
  47b42f:	6a 01                	push   0x1
  47b431:	50                   	push   eax
  47b432:	8b ce                	mov    ecx,esi
  47b434:	e8 88 17 0d 00       	call   0x54cbc1
  47b439:	8d 8f 84 18 00 00    	lea    ecx,[edi+0x1884]
  47b43f:	6a 10                	push   0x10
  47b441:	51                   	push   ecx
  47b442:	8b ce                	mov    ecx,esi
  47b444:	e8 78 17 0d 00       	call   0x54cbc1
  47b449:	8d 97 2c 1a 00 00    	lea    edx,[edi+0x1a2c]
  47b44f:	6a 04                	push   0x4
  47b451:	52                   	push   edx
  47b452:	8b ce                	mov    ecx,esi
  47b454:	e8 68 17 0d 00       	call   0x54cbc1
  47b459:	8d 87 30 1a 00 00    	lea    eax,[edi+0x1a30]
  47b45f:	6a 04                	push   0x4
  47b461:	50                   	push   eax
  47b462:	8b ce                	mov    ecx,esi
  47b464:	e8 58 17 0d 00       	call   0x54cbc1
  47b469:	8d 8f 34 1a 00 00    	lea    ecx,[edi+0x1a34]
  47b46f:	6a 04                	push   0x4
  47b471:	51                   	push   ecx
  47b472:	8b ce                	mov    ecx,esi
  47b474:	e8 48 17 0d 00       	call   0x54cbc1
  47b479:	8d 97 38 1a 00 00    	lea    edx,[edi+0x1a38]
  47b47f:	6a 04                	push   0x4
  47b481:	52                   	push   edx
  47b482:	8b ce                	mov    ecx,esi
  47b484:	e8 38 17 0d 00       	call   0x54cbc1
  47b489:	8d 87 24 1a 00 00    	lea    eax,[edi+0x1a24]
  47b48f:	6a 04                	push   0x4
  47b491:	50                   	push   eax
  47b492:	8b ce                	mov    ecx,esi
  47b494:	e8 28 17 0d 00       	call   0x54cbc1
  47b499:	8d 8f b8 14 00 00    	lea    ecx,[edi+0x14b8]
  47b49f:	6a 04                	push   0x4
  47b4a1:	51                   	push   ecx
  47b4a2:	8b ce                	mov    ecx,esi
  47b4a4:	e8 18 17 0d 00       	call   0x54cbc1
  47b4a9:	8d 97 bc 14 00 00    	lea    edx,[edi+0x14bc]
  47b4af:	6a 04                	push   0x4
  47b4b1:	52                   	push   edx
  47b4b2:	8b ce                	mov    ecx,esi
  47b4b4:	e8 08 17 0d 00       	call   0x54cbc1
  47b4b9:	83 3d 68 c6 57 00 2c 	cmp    DWORD PTR ds:0x57c668,0x2c
  47b4c0:	7c 12                	jl     0x47b4d4
  47b4c2:	8d 87 94 18 00 00    	lea    eax,[edi+0x1894]
  47b4c8:	6a 04                	push   0x4
  47b4ca:	50                   	push   eax
  47b4cb:	8b ce                	mov    ecx,esi
  47b4cd:	e8 ef 16 0d 00       	call   0x54cbc1
  47b4d2:	eb 0a                	jmp    0x47b4de
  47b4d4:	c7 87 94 18 00 00 00 	mov    DWORD PTR [edi+0x1894],0x0
  47b4db:	00 00 00 
  47b4de:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  47b4e3:	8b 6d 00             	mov    ebp,DWORD PTR [ebp+0x0]
  47b4e6:	6a 00                	push   0x0
  47b4e8:	55                   	push   ebp
  47b4e9:	8d 48 04             	lea    ecx,[eax+0x4]
  47b4ec:	e8 ff 62 f8 ff       	call   0x4017f0
  47b4f1:	8d 4c 24 30          	lea    ecx,[esp+0x30]
  47b4f5:	6a 04                	push   0x4
  47b4f7:	51                   	push   ecx
  47b4f8:	8b ce                	mov    ecx,esi
  47b4fa:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  47b4fe:	e8 be 16 0d 00       	call   0x54cbc1
  47b503:	83 7c 24 30 01       	cmp    DWORD PTR [esp+0x30],0x1
  47b508:	75 2d                	jne    0x47b537
  47b50a:	8d 54 24 14          	lea    edx,[esp+0x14]
  47b50e:	6a 04                	push   0x4
  47b510:	52                   	push   edx
  47b511:	8b ce                	mov    ecx,esi
  47b513:	e8 a9 16 0d 00       	call   0x54cbc1
  47b518:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  47b51c:	8b 4c 24 34          	mov    ecx,DWORD PTR [esp+0x34]
  47b520:	33 ed                	xor    ebp,ebp
  47b522:	81 c1 10 01 00 00    	add    ecx,0x110
  47b528:	55                   	push   ebp
  47b529:	50                   	push   eax
  47b52a:	e8 c1 62 f8 ff       	call   0x4017f0
  47b52f:	89 87 dc 14 00 00    	mov    DWORD PTR [edi+0x14dc],eax
  47b535:	eb 0c                	jmp    0x47b543
  47b537:	c7 87 dc 14 00 00 00 	mov    DWORD PTR [edi+0x14dc],0x0
  47b53e:	00 00 00 
  47b541:	33 ed                	xor    ebp,ebp
  47b543:	8d 54 24 30          	lea    edx,[esp+0x30]
  47b547:	6a 04                	push   0x4
  47b549:	52                   	push   edx
  47b54a:	8b ce                	mov    ecx,esi
  47b54c:	e8 70 16 0d 00       	call   0x54cbc1
  47b551:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  47b555:	8b 0d cc c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5cc
  47b55b:	50                   	push   eax
  47b55c:	e8 6f f7 06 00       	call   0x4eacd0
  47b561:	8b 8f 00 1a 00 00    	mov    ecx,DWORD PTR [edi+0x1a00]
  47b567:	8b 13                	mov    edx,DWORD PTR [ebx]
  47b569:	51                   	push   ecx
  47b56a:	52                   	push   edx
  47b56b:	8b cf                	mov    ecx,edi
  47b56d:	89 87 e0 14 00 00    	mov    DWORD PTR [edi+0x14e0],eax
  47b573:	e8 68 30 00 00       	call   0x47e5e0
  47b578:	8b 87 04 1a 00 00    	mov    eax,DWORD PTR [edi+0x1a04]
  47b57e:	8b cf                	mov    ecx,edi
  47b580:	50                   	push   eax
  47b581:	e8 1a 31 00 00       	call   0x47e6a0
  47b586:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  47b58a:	6a 04                	push   0x4
  47b58c:	51                   	push   ecx
  47b58d:	8b ce                	mov    ecx,esi
  47b58f:	e8 2d 16 0d 00       	call   0x54cbc1
  47b594:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  47b598:	89 6c 24 30          	mov    DWORD PTR [esp+0x30],ebp
  47b59c:	3b c5                	cmp    eax,ebp
  47b59e:	7e 4c                	jle    0x47b5ec
  47b5a0:	8d 9f e4 14 00 00    	lea    ebx,[edi+0x14e4]
  47b5a6:	68 5c 03 00 00       	push   0x35c
  47b5ab:	e8 71 2c 0d 00       	call   0x54e221
  47b5b0:	83 c4 04             	add    esp,0x4
  47b5b3:	89 44 24 34          	mov    DWORD PTR [esp+0x34],eax
  47b5b7:	3b c5                	cmp    eax,ebp
  47b5b9:	89 6c 24 28          	mov    DWORD PTR [esp+0x28],ebp
  47b5bd:	74 0a                	je     0x47b5c9
  47b5bf:	56                   	push   esi
  47b5c0:	8b c8                	mov    ecx,eax
  47b5c2:	e8 39 5a f8 ff       	call   0x401000
  47b5c7:	eb 02                	jmp    0x47b5cb
  47b5c9:	33 c0                	xor    eax,eax
  47b5cb:	50                   	push   eax
  47b5cc:	8b cb                	mov    ecx,ebx
  47b5ce:	c7 44 24 2c ff ff ff 	mov    DWORD PTR [esp+0x2c],0xffffffff
  47b5d5:	ff 
  47b5d6:	e8 d5 5e f8 ff       	call   0x4014b0
  47b5db:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  47b5df:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47b5e3:	40                   	inc    eax
  47b5e4:	3b c1                	cmp    eax,ecx
  47b5e6:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  47b5ea:	7c ba                	jl     0x47b5a6
  47b5ec:	8d 54 24 14          	lea    edx,[esp+0x14]
  47b5f0:	6a 04                	push   0x4
  47b5f2:	52                   	push   edx
  47b5f3:	8b ce                	mov    ecx,esi
  47b5f5:	e8 c7 15 0d 00       	call   0x54cbc1
  47b5fa:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  47b5fe:	83 f8 ff             	cmp    eax,0xffffffff
  47b601:	74 19                	je     0x47b61c
  47b603:	55                   	push   ebp
  47b604:	50                   	push   eax
  47b605:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  47b609:	8d 88 ac 0f 00 00    	lea    ecx,[eax+0xfac]
  47b60f:	e8 dc 61 f8 ff       	call   0x4017f0
  47b614:	89 87 f0 16 00 00    	mov    DWORD PTR [edi+0x16f0],eax
  47b61a:	eb 06                	jmp    0x47b622
  47b61c:	89 af f0 16 00 00    	mov    DWORD PTR [edi+0x16f0],ebp
  47b622:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  47b626:	6a 04                	push   0x4
  47b628:	51                   	push   ecx
  47b629:	8b ce                	mov    ecx,esi
  47b62b:	e8 91 15 0d 00       	call   0x54cbc1
  47b630:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  47b634:	89 6c 24 30          	mov    DWORD PTR [esp+0x30],ebp
  47b638:	3b c5                	cmp    eax,ebp
  47b63a:	0f 8e 83 00 00 00    	jle    0x47b6c3
  47b640:	8d 9f 00 15 00 00    	lea    ebx,[edi+0x1500]
  47b646:	8d 54 24 1c          	lea    edx,[esp+0x1c]
  47b64a:	6a 04                	push   0x4
  47b64c:	52                   	push   edx
  47b64d:	8b ce                	mov    ecx,esi
  47b64f:	e8 6d 15 0d 00       	call   0x54cbc1
  47b654:	8d 44 24 14          	lea    eax,[esp+0x14]
  47b658:	6a 04                	push   0x4
  47b65a:	50                   	push   eax
  47b65b:	8b ce                	mov    ecx,esi
  47b65d:	e8 5f 15 0d 00       	call   0x54cbc1
  47b662:	6a 08                	push   0x8
  47b664:	e8 b8 2b 0d 00       	call   0x54e221
  47b669:	8b e8                	mov    ebp,eax
  47b66b:	83 c4 04             	add    esp,0x4
  47b66e:	89 6c 24 34          	mov    DWORD PTR [esp+0x34],ebp
  47b672:	85 ed                	test   ebp,ebp
  47b674:	c7 44 24 28 01 00 00 	mov    DWORD PTR [esp+0x28],0x1
  47b67b:	00 
  47b67c:	74 20                	je     0x47b69e
  47b67e:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  47b683:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  47b687:	6a 00                	push   0x0
  47b689:	51                   	push   ecx
  47b68a:	8d 48 20             	lea    ecx,[eax+0x20]
  47b68d:	e8 5e 61 f8 ff       	call   0x4017f0
  47b692:	8b 54 24 1c          	mov    edx,DWORD PTR [esp+0x1c]
  47b696:	89 45 00             	mov    DWORD PTR [ebp+0x0],eax
  47b699:	89 55 04             	mov    DWORD PTR [ebp+0x4],edx
  47b69c:	eb 02                	jmp    0x47b6a0
  47b69e:	33 ed                	xor    ebp,ebp
  47b6a0:	55                   	push   ebp
  47b6a1:	8b cb                	mov    ecx,ebx
  47b6a3:	c7 44 24 2c ff ff ff 	mov    DWORD PTR [esp+0x2c],0xffffffff
  47b6aa:	ff 
  47b6ab:	e8 00 5e f8 ff       	call   0x4014b0
  47b6b0:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  47b6b4:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47b6b8:	40                   	inc    eax
  47b6b9:	3b c1                	cmp    eax,ecx
  47b6bb:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  47b6bf:	7c 85                	jl     0x47b646
  47b6c1:	33 ed                	xor    ebp,ebp
  47b6c3:	8d 44 24 10          	lea    eax,[esp+0x10]
  47b6c7:	6a 04                	push   0x4
  47b6c9:	50                   	push   eax
  47b6ca:	8b ce                	mov    ecx,esi
  47b6cc:	e8 f0 14 0d 00       	call   0x54cbc1
  47b6d1:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  47b6d5:	89 6c 24 30          	mov    DWORD PTR [esp+0x30],ebp
  47b6d9:	3b c5                	cmp    eax,ebp
  47b6db:	7e 63                	jle    0x47b740
  47b6dd:	8d 9f f8 16 00 00    	lea    ebx,[edi+0x16f8]
  47b6e3:	bd 02 00 00 00       	mov    ebp,0x2
  47b6e8:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  47b6ec:	6a 04                	push   0x4
  47b6ee:	51                   	push   ecx
  47b6ef:	8b ce                	mov    ecx,esi
  47b6f1:	e8 cb 14 0d 00       	call   0x54cbc1
  47b6f6:	6a 24                	push   0x24
  47b6f8:	e8 24 2b 0d 00       	call   0x54e221
  47b6fd:	83 c4 04             	add    esp,0x4
  47b700:	89 44 24 34          	mov    DWORD PTR [esp+0x34],eax
  47b704:	85 c0                	test   eax,eax
  47b706:	89 6c 24 28          	mov    DWORD PTR [esp+0x28],ebp
  47b70a:	74 0a                	je     0x47b716
  47b70c:	56                   	push   esi
  47b70d:	8b c8                	mov    ecx,eax
  47b70f:	e8 ac a6 06 00       	call   0x4e5dc0
  47b714:	eb 02                	jmp    0x47b718
  47b716:	33 c0                	xor    eax,eax
  47b718:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  47b71c:	8b cb                	mov    ecx,ebx
  47b71e:	52                   	push   edx
  47b71f:	50                   	push   eax
  47b720:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  47b727:	ff 
  47b728:	e8 83 5e f8 ff       	call   0x4015b0
  47b72d:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  47b731:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47b735:	40                   	inc    eax
  47b736:	3b c1                	cmp    eax,ecx
  47b738:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  47b73c:	7c aa                	jl     0x47b6e8
  47b73e:	33 ed                	xor    ebp,ebp
  47b740:	8d 44 24 10          	lea    eax,[esp+0x10]
  47b744:	6a 04                	push   0x4
  47b746:	50                   	push   eax
  47b747:	8b ce                	mov    ecx,esi
  47b749:	e8 73 14 0d 00       	call   0x54cbc1
  47b74e:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  47b752:	89 6c 24 30          	mov    DWORD PTR [esp+0x30],ebp
  47b756:	3b c5                	cmp    eax,ebp
  47b758:	7e 33                	jle    0x47b78d
  47b75a:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  47b75e:	6a 04                	push   0x4
  47b760:	51                   	push   ecx
  47b761:	8b ce                	mov    ecx,esi
  47b763:	e8 59 14 0d 00       	call   0x54cbc1
  47b768:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  47b76c:	3b c5                	cmp    eax,ebp
  47b76e:	7e 0c                	jle    0x47b77c
  47b770:	50                   	push   eax
  47b771:	8d 8f 28 17 00 00    	lea    ecx,[edi+0x1728]
  47b777:	e8 34 5d f8 ff       	call   0x4014b0
  47b77c:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  47b780:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47b784:	40                   	inc    eax
  47b785:	3b c1                	cmp    eax,ecx
  47b787:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  47b78b:	7c cd                	jl     0x47b75a
  47b78d:	8d 54 24 10          	lea    edx,[esp+0x10]
  47b791:	6a 04                	push   0x4
  47b793:	52                   	push   edx
  47b794:	8b ce                	mov    ecx,esi
  47b796:	e8 26 14 0d 00       	call   0x54cbc1
  47b79b:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  47b79f:	89 6c 24 30          	mov    DWORD PTR [esp+0x30],ebp
  47b7a3:	3b c5                	cmp    eax,ebp
  47b7a5:	7e 31                	jle    0x47b7d8
  47b7a7:	8d 9f 44 17 00 00    	lea    ebx,[edi+0x1744]
  47b7ad:	8d 44 24 14          	lea    eax,[esp+0x14]
  47b7b1:	6a 04                	push   0x4
  47b7b3:	50                   	push   eax
  47b7b4:	8b ce                	mov    ecx,esi
  47b7b6:	e8 06 14 0d 00       	call   0x54cbc1
  47b7bb:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  47b7bf:	51                   	push   ecx
  47b7c0:	8b cb                	mov    ecx,ebx
  47b7c2:	e8 e9 5c f8 ff       	call   0x4014b0
  47b7c7:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  47b7cb:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47b7cf:	40                   	inc    eax
  47b7d0:	3b c1                	cmp    eax,ecx
  47b7d2:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  47b7d6:	7c d5                	jl     0x47b7ad
  47b7d8:	8d 54 24 10          	lea    edx,[esp+0x10]
  47b7dc:	6a 04                	push   0x4
  47b7de:	52                   	push   edx
  47b7df:	8b ce                	mov    ecx,esi
  47b7e1:	e8 db 13 0d 00       	call   0x54cbc1
  47b7e6:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  47b7ea:	89 6c 24 30          	mov    DWORD PTR [esp+0x30],ebp
  47b7ee:	3b c5                	cmp    eax,ebp
  47b7f0:	7e 31                	jle    0x47b823
  47b7f2:	8d 9f 60 17 00 00    	lea    ebx,[edi+0x1760]
  47b7f8:	8d 44 24 14          	lea    eax,[esp+0x14]
  47b7fc:	6a 04                	push   0x4
  47b7fe:	50                   	push   eax
  47b7ff:	8b ce                	mov    ecx,esi
  47b801:	e8 bb 13 0d 00       	call   0x54cbc1
  47b806:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  47b80a:	51                   	push   ecx
  47b80b:	8b cb                	mov    ecx,ebx
  47b80d:	e8 9e 5c f8 ff       	call   0x4014b0
  47b812:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  47b816:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47b81a:	40                   	inc    eax
  47b81b:	3b c1                	cmp    eax,ecx
  47b81d:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  47b821:	7c d5                	jl     0x47b7f8
  47b823:	8d 54 24 10          	lea    edx,[esp+0x10]
  47b827:	6a 04                	push   0x4
  47b829:	52                   	push   edx
  47b82a:	8b ce                	mov    ecx,esi
  47b82c:	e8 90 13 0d 00       	call   0x54cbc1
  47b831:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  47b835:	89 6c 24 30          	mov    DWORD PTR [esp+0x30],ebp
  47b839:	3b c5                	cmp    eax,ebp
  47b83b:	7e 4a                	jle    0x47b887
  47b83d:	8d 9f 98 19 00 00    	lea    ebx,[edi+0x1998]
  47b843:	8d 44 24 14          	lea    eax,[esp+0x14]
  47b847:	6a 04                	push   0x4
  47b849:	50                   	push   eax
  47b84a:	8b ce                	mov    ecx,esi
  47b84c:	e8 70 13 0d 00       	call   0x54cbc1
  47b851:	6a 20                	push   0x20
  47b853:	e8 c9 29 0d 00       	call   0x54e221
  47b858:	83 c4 04             	add    esp,0x4
  47b85b:	8b e8                	mov    ebp,eax
  47b85d:	8b ce                	mov    ecx,esi
  47b85f:	6a 20                	push   0x20
  47b861:	55                   	push   ebp
  47b862:	e8 5a 13 0d 00       	call   0x54cbc1
  47b867:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  47b86b:	51                   	push   ecx
  47b86c:	55                   	push   ebp
  47b86d:	8b cb                	mov    ecx,ebx
  47b86f:	e8 3c 5d f8 ff       	call   0x4015b0
  47b874:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  47b878:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47b87c:	40                   	inc    eax
  47b87d:	3b c1                	cmp    eax,ecx
  47b87f:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  47b883:	7c be                	jl     0x47b843
  47b885:	33 ed                	xor    ebp,ebp
  47b887:	8d 54 24 10          	lea    edx,[esp+0x10]
  47b88b:	6a 04                	push   0x4
  47b88d:	52                   	push   edx
  47b88e:	8b ce                	mov    ecx,esi
  47b890:	e8 2c 13 0d 00       	call   0x54cbc1
  47b895:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  47b899:	89 6c 24 30          	mov    DWORD PTR [esp+0x30],ebp
  47b89d:	3b c5                	cmp    eax,ebp
  47b89f:	7e 37                	jle    0x47b8d8
  47b8a1:	8d 9f c4 19 00 00    	lea    ebx,[edi+0x19c4]
  47b8a7:	6a 30                	push   0x30
  47b8a9:	e8 73 29 0d 00       	call   0x54e221
  47b8ae:	83 c4 04             	add    esp,0x4
  47b8b1:	8b e8                	mov    ebp,eax
  47b8b3:	8b ce                	mov    ecx,esi
  47b8b5:	6a 30                	push   0x30
  47b8b7:	55                   	push   ebp
  47b8b8:	e8 04 13 0d 00       	call   0x54cbc1
  47b8bd:	55                   	push   ebp
  47b8be:	8b cb                	mov    ecx,ebx
  47b8c0:	e8 eb 5b f8 ff       	call   0x4014b0
  47b8c5:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  47b8c9:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47b8cd:	40                   	inc    eax
  47b8ce:	3b c1                	cmp    eax,ecx
  47b8d0:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  47b8d4:	7c d1                	jl     0x47b8a7
  47b8d6:	33 ed                	xor    ebp,ebp
  47b8d8:	8d 44 24 10          	lea    eax,[esp+0x10]
  47b8dc:	6a 04                	push   0x4
  47b8de:	50                   	push   eax
  47b8df:	8b ce                	mov    ecx,esi
  47b8e1:	e8 db 12 0d 00       	call   0x54cbc1
  47b8e6:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  47b8ea:	89 6c 24 30          	mov    DWORD PTR [esp+0x30],ebp
  47b8ee:	3b c5                	cmp    eax,ebp
  47b8f0:	7e 63                	jle    0x47b955
  47b8f2:	8d 9f e0 19 00 00    	lea    ebx,[edi+0x19e0]
  47b8f8:	bd 03 00 00 00       	mov    ebp,0x3
  47b8fd:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  47b901:	6a 04                	push   0x4
  47b903:	51                   	push   ecx
  47b904:	8b ce                	mov    ecx,esi
  47b906:	e8 b6 12 0d 00       	call   0x54cbc1
  47b90b:	6a 24                	push   0x24
  47b90d:	e8 0f 29 0d 00       	call   0x54e221
  47b912:	83 c4 04             	add    esp,0x4
  47b915:	89 44 24 34          	mov    DWORD PTR [esp+0x34],eax
  47b919:	85 c0                	test   eax,eax
  47b91b:	89 6c 24 28          	mov    DWORD PTR [esp+0x28],ebp
  47b91f:	74 0a                	je     0x47b92b
  47b921:	56                   	push   esi
  47b922:	8b c8                	mov    ecx,eax
  47b924:	e8 97 a4 06 00       	call   0x4e5dc0
  47b929:	eb 02                	jmp    0x47b92d
  47b92b:	33 c0                	xor    eax,eax
  47b92d:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  47b931:	8b cb                	mov    ecx,ebx
  47b933:	52                   	push   edx
  47b934:	50                   	push   eax
  47b935:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  47b93c:	ff 
  47b93d:	e8 6e 5c f8 ff       	call   0x4015b0
  47b942:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  47b946:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47b94a:	40                   	inc    eax
  47b94b:	3b c1                	cmp    eax,ecx
  47b94d:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  47b951:	7c aa                	jl     0x47b8fd
  47b953:	33 ed                	xor    ebp,ebp
  47b955:	8b 8f e0 14 00 00    	mov    ecx,DWORD PTR [edi+0x14e0]
  47b95b:	55                   	push   ebp
  47b95c:	57                   	push   edi
  47b95d:	e8 ee 74 07 00       	call   0x4f2e50
  47b962:	8a 87 20 1a 00 00    	mov    al,BYTE PTR [edi+0x1a20]
  47b968:	84 c0                	test   al,al
  47b96a:	74 09                	je     0x47b975
  47b96c:	6a 01                	push   0x1
  47b96e:	8b cf                	mov    ecx,edi
  47b970:	e8 9b 44 00 00       	call   0x47fe10
  47b975:	89 af c4 14 00 00    	mov    DWORD PTR [edi+0x14c4],ebp
  47b97b:	8b 8f 14 15 00 00    	mov    ecx,DWORD PTR [edi+0x1514]
  47b981:	33 c0                	xor    eax,eax
  47b983:	3b cd                	cmp    ecx,ebp
  47b985:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  47b989:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  47b98d:	7e 35                	jle    0x47b9c4
  47b98f:	8d b7 00 15 00 00    	lea    esi,[edi+0x1500]
  47b995:	55                   	push   ebp
  47b996:	50                   	push   eax
  47b997:	8b ce                	mov    ecx,esi
  47b999:	e8 52 5e f8 ff       	call   0x4017f0
  47b99e:	8b 08                	mov    ecx,DWORD PTR [eax]
  47b9a0:	80 b9 24 08 00 00 01 	cmp    BYTE PTR [ecx+0x824],0x1
  47b9a7:	74 13                	je     0x47b9bc
  47b9a9:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  47b9ad:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47b9b1:	40                   	inc    eax
  47b9b2:	3b c1                	cmp    eax,ecx
  47b9b4:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  47b9b8:	7c db                	jl     0x47b995
  47b9ba:	eb 08                	jmp    0x47b9c4
  47b9bc:	8b 10                	mov    edx,DWORD PTR [eax]
  47b9be:	89 97 c4 14 00 00    	mov    DWORD PTR [edi+0x14c4],edx
  47b9c4:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  47b9c8:	5f                   	pop    edi
  47b9c9:	5e                   	pop    esi
  47b9ca:	5d                   	pop    ebp
  47b9cb:	5b                   	pop    ebx
  47b9cc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47b9d3:	83 c4 1c             	add    esp,0x1c
  47b9d6:	c2                   	.byte 0xc2
  47b9d7:	08                   	.byte 0x8
```

## `Branch_Save` — `0x47b9e0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x47b9e0.c`
- Callers: `CompanyData_Save` (0x4e1540)
- Callees: `Array_FindIndexByPtr` (0x4d7e90), `CRT_Ostream_Write` (0x54cc2b), `ConstructionOrder_Save` (0x4e5e30), `Game_FindCompanyIndex` (0x4dde70), `Game_GetPlayerBySlot` (0x488be0), `Game_RemoveIDMapEntry` (0x4eacb0), `IDMap_Lookup` (0x4017f0), `Map_LookupLinear` (0x401930), `StatsPeriodReport_Save` (0x401200)

- Unresolved questions: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

0047b9e0 <.text+0x7a9e0>:
  47b9e0:	83 ec 14             	sub    esp,0x14
  47b9e3:	53                   	push   ebx
  47b9e4:	55                   	push   ebp
  47b9e5:	56                   	push   esi
  47b9e6:	57                   	push   edi
  47b9e7:	8b f9                	mov    edi,ecx
  47b9e9:	6a 00                	push   0x0
  47b9eb:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  47b9f1:	8b 47 34             	mov    eax,DWORD PTR [edi+0x34]
  47b9f4:	8d 5f 34             	lea    ebx,[edi+0x34]
  47b9f7:	50                   	push   eax
  47b9f8:	83 c1 04             	add    ecx,0x4
  47b9fb:	e8 f0 5d f8 ff       	call   0x4017f0
  47ba00:	8b 74 24 28          	mov    esi,DWORD PTR [esp+0x28]
  47ba04:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  47ba08:	8d 47 04             	lea    eax,[edi+0x4]
  47ba0b:	6a 20                	push   0x20
  47ba0d:	50                   	push   eax
  47ba0e:	8b ce                	mov    ecx,esi
  47ba10:	e8 16 12 0d 00       	call   0x54cc2b
  47ba15:	8d 4f 2c             	lea    ecx,[edi+0x2c]
  47ba18:	6a 04                	push   0x4
  47ba1a:	51                   	push   ecx
  47ba1b:	8b ce                	mov    ecx,esi
  47ba1d:	e8 09 12 0d 00       	call   0x54cc2b
  47ba22:	8d 57 24             	lea    edx,[edi+0x24]
  47ba25:	6a 04                	push   0x4
  47ba27:	52                   	push   edx
  47ba28:	8b ce                	mov    ecx,esi
  47ba2a:	e8 fc 11 0d 00       	call   0x54cc2b
  47ba2f:	8d 47 28             	lea    eax,[edi+0x28]
  47ba32:	6a 04                	push   0x4
  47ba34:	50                   	push   eax
  47ba35:	8b ce                	mov    ecx,esi
  47ba37:	e8 ef 11 0d 00       	call   0x54cc2b
  47ba3c:	8d 6f 30             	lea    ebp,[edi+0x30]
  47ba3f:	6a 04                	push   0x4
  47ba41:	55                   	push   ebp
  47ba42:	8b ce                	mov    ecx,esi
  47ba44:	e8 e2 11 0d 00       	call   0x54cc2b
  47ba49:	6a 04                	push   0x4
  47ba4b:	53                   	push   ebx
  47ba4c:	8b ce                	mov    ecx,esi
  47ba4e:	e8 d8 11 0d 00       	call   0x54cc2b
  47ba53:	8d 4f 3c             	lea    ecx,[edi+0x3c]
  47ba56:	6a 04                	push   0x4
  47ba58:	51                   	push   ecx
  47ba59:	8b ce                	mov    ecx,esi
  47ba5b:	e8 cb 11 0d 00       	call   0x54cc2b
  47ba60:	8d 57 40             	lea    edx,[edi+0x40]
  47ba63:	6a 04                	push   0x4
  47ba65:	52                   	push   edx
  47ba66:	8b ce                	mov    ecx,esi
  47ba68:	e8 be 11 0d 00       	call   0x54cc2b
  47ba6d:	8d 47 44             	lea    eax,[edi+0x44]
  47ba70:	68 44 01 00 00       	push   0x144
  47ba75:	50                   	push   eax
  47ba76:	8b ce                	mov    ecx,esi
  47ba78:	e8 ae 11 0d 00       	call   0x54cc2b
  47ba7d:	8d 8f 88 01 00 00    	lea    ecx,[edi+0x188]
  47ba83:	68 44 01 00 00       	push   0x144
  47ba88:	51                   	push   ecx
  47ba89:	8b ce                	mov    ecx,esi
  47ba8b:	e8 9b 11 0d 00       	call   0x54cc2b
  47ba90:	8d 97 54 05 00 00    	lea    edx,[edi+0x554]
  47ba96:	68 10 0e 00 00       	push   0xe10
  47ba9b:	52                   	push   edx
  47ba9c:	8b ce                	mov    ecx,esi
  47ba9e:	e8 88 11 0d 00       	call   0x54cc2b
  47baa3:	8d 87 64 13 00 00    	lea    eax,[edi+0x1364]
  47baa9:	6a 24                	push   0x24
  47baab:	50                   	push   eax
  47baac:	8b ce                	mov    ecx,esi
  47baae:	e8 78 11 0d 00       	call   0x54cc2b
  47bab3:	8d 8f cc 02 00 00    	lea    ecx,[edi+0x2cc]
  47bab9:	68 44 01 00 00       	push   0x144
  47babe:	51                   	push   ecx
  47babf:	8b ce                	mov    ecx,esi
  47bac1:	e8 65 11 0d 00       	call   0x54cc2b
  47bac6:	8d 97 10 04 00 00    	lea    edx,[edi+0x410]
  47bacc:	68 44 01 00 00       	push   0x144
  47bad1:	52                   	push   edx
  47bad2:	8b ce                	mov    ecx,esi
  47bad4:	e8 52 11 0d 00       	call   0x54cc2b
  47bad9:	8d 87 88 13 00 00    	lea    eax,[edi+0x1388]
  47badf:	6a 48                	push   0x48
  47bae1:	50                   	push   eax
  47bae2:	8b ce                	mov    ecx,esi
  47bae4:	e8 42 11 0d 00       	call   0x54cc2b
  47bae9:	8d 8f d0 13 00 00    	lea    ecx,[edi+0x13d0]
  47baef:	6a 48                	push   0x48
  47baf1:	51                   	push   ecx
  47baf2:	8b ce                	mov    ecx,esi
  47baf4:	e8 32 11 0d 00       	call   0x54cc2b
  47baf9:	8d 97 18 14 00 00    	lea    edx,[edi+0x1418]
  47baff:	6a 48                	push   0x48
  47bb01:	52                   	push   edx
  47bb02:	8b ce                	mov    ecx,esi
  47bb04:	e8 22 11 0d 00       	call   0x54cc2b
  47bb09:	8d 87 60 14 00 00    	lea    eax,[edi+0x1460]
  47bb0f:	6a 48                	push   0x48
  47bb11:	50                   	push   eax
  47bb12:	8b ce                	mov    ecx,esi
  47bb14:	e8 12 11 0d 00       	call   0x54cc2b
  47bb19:	8d 8f a8 14 00 00    	lea    ecx,[edi+0x14a8]
  47bb1f:	6a 04                	push   0x4
  47bb21:	51                   	push   ecx
  47bb22:	8b ce                	mov    ecx,esi
  47bb24:	e8 02 11 0d 00       	call   0x54cc2b
  47bb29:	8d 97 ac 14 00 00    	lea    edx,[edi+0x14ac]
  47bb2f:	6a 04                	push   0x4
  47bb31:	52                   	push   edx
  47bb32:	8b ce                	mov    ecx,esi
  47bb34:	e8 f2 10 0d 00       	call   0x54cc2b
  47bb39:	8d 87 c8 14 00 00    	lea    eax,[edi+0x14c8]
  47bb3f:	6a 04                	push   0x4
  47bb41:	50                   	push   eax
  47bb42:	8b ce                	mov    ecx,esi
  47bb44:	e8 e2 10 0d 00       	call   0x54cc2b
  47bb49:	8d 8f cc 14 00 00    	lea    ecx,[edi+0x14cc]
  47bb4f:	6a 04                	push   0x4
  47bb51:	51                   	push   ecx
  47bb52:	8b ce                	mov    ecx,esi
  47bb54:	e8 d2 10 0d 00       	call   0x54cc2b
  47bb59:	8d 97 d0 14 00 00    	lea    edx,[edi+0x14d0]
  47bb5f:	6a 04                	push   0x4
  47bb61:	52                   	push   edx
  47bb62:	8b ce                	mov    ecx,esi
  47bb64:	e8 c2 10 0d 00       	call   0x54cc2b
  47bb69:	8d 87 d4 14 00 00    	lea    eax,[edi+0x14d4]
  47bb6f:	6a 04                	push   0x4
  47bb71:	50                   	push   eax
  47bb72:	8b ce                	mov    ecx,esi
  47bb74:	e8 b2 10 0d 00       	call   0x54cc2b
  47bb79:	8d 8f c0 14 00 00    	lea    ecx,[edi+0x14c0]
  47bb7f:	6a 04                	push   0x4
  47bb81:	51                   	push   ecx
  47bb82:	8b ce                	mov    ecx,esi
  47bb84:	e8 a2 10 0d 00       	call   0x54cc2b
  47bb89:	8d 97 d8 14 00 00    	lea    edx,[edi+0x14d8]
  47bb8f:	6a 04                	push   0x4
  47bb91:	52                   	push   edx
  47bb92:	8b ce                	mov    ecx,esi
  47bb94:	e8 92 10 0d 00       	call   0x54cc2b
  47bb99:	8d 87 f5 16 00 00    	lea    eax,[edi+0x16f5]
  47bb9f:	6a 01                	push   0x1
  47bba1:	50                   	push   eax
  47bba2:	8b ce                	mov    ecx,esi
  47bba4:	e8 82 10 0d 00       	call   0x54cc2b
  47bba9:	8d 8f f4 16 00 00    	lea    ecx,[edi+0x16f4]
  47bbaf:	6a 01                	push   0x1
  47bbb1:	51                   	push   ecx
  47bbb2:	8b ce                	mov    ecx,esi
  47bbb4:	e8 72 10 0d 00       	call   0x54cc2b
  47bbb9:	8d 97 b0 14 00 00    	lea    edx,[edi+0x14b0]
  47bbbf:	6a 04                	push   0x4
  47bbc1:	52                   	push   edx
  47bbc2:	8b ce                	mov    ecx,esi
  47bbc4:	e8 62 10 0d 00       	call   0x54cc2b
  47bbc9:	8d 87 14 17 00 00    	lea    eax,[edi+0x1714]
  47bbcf:	6a 04                	push   0x4
  47bbd1:	50                   	push   eax
  47bbd2:	8b ce                	mov    ecx,esi
  47bbd4:	e8 52 10 0d 00       	call   0x54cc2b
  47bbd9:	8d 8f 18 17 00 00    	lea    ecx,[edi+0x1718]
  47bbdf:	6a 04                	push   0x4
  47bbe1:	51                   	push   ecx
  47bbe2:	8b ce                	mov    ecx,esi
  47bbe4:	e8 42 10 0d 00       	call   0x54cc2b
  47bbe9:	8d 97 1c 17 00 00    	lea    edx,[edi+0x171c]
  47bbef:	6a 04                	push   0x4
  47bbf1:	52                   	push   edx
  47bbf2:	8b ce                	mov    ecx,esi
  47bbf4:	e8 32 10 0d 00       	call   0x54cc2b
  47bbf9:	8d 87 20 17 00 00    	lea    eax,[edi+0x1720]
  47bbff:	6a 04                	push   0x4
  47bc01:	50                   	push   eax
  47bc02:	8b ce                	mov    ecx,esi
  47bc04:	e8 22 10 0d 00       	call   0x54cc2b
  47bc09:	8d 8f 24 17 00 00    	lea    ecx,[edi+0x1724]
  47bc0f:	6a 04                	push   0x4
  47bc11:	51                   	push   ecx
  47bc12:	8b ce                	mov    ecx,esi
  47bc14:	e8 12 10 0d 00       	call   0x54cc2b
  47bc19:	8d 97 1c 15 00 00    	lea    edx,[edi+0x151c]
  47bc1f:	68 a0 01 00 00       	push   0x1a0
  47bc24:	52                   	push   edx
  47bc25:	8b ce                	mov    ecx,esi
  47bc27:	e8 ff 0f 0d 00       	call   0x54cc2b
  47bc2c:	8d 87 bc 16 00 00    	lea    eax,[edi+0x16bc]
  47bc32:	6a 34                	push   0x34
  47bc34:	50                   	push   eax
  47bc35:	8b ce                	mov    ecx,esi
  47bc37:	e8 ef 0f 0d 00       	call   0x54cc2b
  47bc3c:	8d 8f 7c 17 00 00    	lea    ecx,[edi+0x177c]
  47bc42:	6a 20                	push   0x20
  47bc44:	51                   	push   ecx
  47bc45:	8b ce                	mov    ecx,esi
  47bc47:	e8 df 0f 0d 00       	call   0x54cc2b
  47bc4c:	8d 97 9c 17 00 00    	lea    edx,[edi+0x179c]
  47bc52:	6a 20                	push   0x20
  47bc54:	52                   	push   edx
  47bc55:	8b ce                	mov    ecx,esi
  47bc57:	e8 cf 0f 0d 00       	call   0x54cc2b
  47bc5c:	8d 87 bc 17 00 00    	lea    eax,[edi+0x17bc]
  47bc62:	6a 20                	push   0x20
  47bc64:	50                   	push   eax
  47bc65:	8b ce                	mov    ecx,esi
  47bc67:	e8 bf 0f 0d 00       	call   0x54cc2b
  47bc6c:	8d 8f dc 17 00 00    	lea    ecx,[edi+0x17dc]
  47bc72:	6a 20                	push   0x20
  47bc74:	51                   	push   ecx
  47bc75:	8b ce                	mov    ecx,esi
  47bc77:	e8 af 0f 0d 00       	call   0x54cc2b
  47bc7c:	8d 97 fc 17 00 00    	lea    edx,[edi+0x17fc]
  47bc82:	6a 20                	push   0x20
  47bc84:	52                   	push   edx
  47bc85:	8b ce                	mov    ecx,esi
  47bc87:	e8 9f 0f 0d 00       	call   0x54cc2b
  47bc8c:	8d 87 1c 18 00 00    	lea    eax,[edi+0x181c]
  47bc92:	6a 20                	push   0x20
  47bc94:	50                   	push   eax
  47bc95:	8b ce                	mov    ecx,esi
  47bc97:	e8 8f 0f 0d 00       	call   0x54cc2b
  47bc9c:	8d 8f 3c 18 00 00    	lea    ecx,[edi+0x183c]
  47bca2:	6a 14                	push   0x14
  47bca4:	51                   	push   ecx
  47bca5:	8b ce                	mov    ecx,esi
  47bca7:	e8 7f 0f 0d 00       	call   0x54cc2b
  47bcac:	8d 97 50 18 00 00    	lea    edx,[edi+0x1850]
  47bcb2:	6a 04                	push   0x4
  47bcb4:	52                   	push   edx
  47bcb5:	8b ce                	mov    ecx,esi
  47bcb7:	e8 6f 0f 0d 00       	call   0x54cc2b
  47bcbc:	8d 87 54 18 00 00    	lea    eax,[edi+0x1854]
  47bcc2:	6a 04                	push   0x4
  47bcc4:	50                   	push   eax
  47bcc5:	8b ce                	mov    ecx,esi
  47bcc7:	e8 5f 0f 0d 00       	call   0x54cc2b
  47bccc:	8d 8f 58 18 00 00    	lea    ecx,[edi+0x1858]
  47bcd2:	6a 04                	push   0x4
  47bcd4:	51                   	push   ecx
  47bcd5:	8b ce                	mov    ecx,esi
  47bcd7:	e8 4f 0f 0d 00       	call   0x54cc2b
  47bcdc:	8d 97 5c 18 00 00    	lea    edx,[edi+0x185c]
  47bce2:	6a 04                	push   0x4
  47bce4:	52                   	push   edx
  47bce5:	8b ce                	mov    ecx,esi
  47bce7:	e8 3f 0f 0d 00       	call   0x54cc2b
  47bcec:	8d 87 60 18 00 00    	lea    eax,[edi+0x1860]
  47bcf2:	6a 04                	push   0x4
  47bcf4:	50                   	push   eax
  47bcf5:	8b ce                	mov    ecx,esi
  47bcf7:	e8 2f 0f 0d 00       	call   0x54cc2b
  47bcfc:	8d 8f 64 18 00 00    	lea    ecx,[edi+0x1864]
  47bd02:	6a 04                	push   0x4
  47bd04:	51                   	push   ecx
  47bd05:	8b ce                	mov    ecx,esi
  47bd07:	e8 1f 0f 0d 00       	call   0x54cc2b
  47bd0c:	8d 97 68 18 00 00    	lea    edx,[edi+0x1868]
  47bd12:	6a 04                	push   0x4
  47bd14:	52                   	push   edx
  47bd15:	8b ce                	mov    ecx,esi
  47bd17:	e8 0f 0f 0d 00       	call   0x54cc2b
  47bd1c:	8d 87 6c 18 00 00    	lea    eax,[edi+0x186c]
  47bd22:	6a 04                	push   0x4
  47bd24:	50                   	push   eax
  47bd25:	8b ce                	mov    ecx,esi
  47bd27:	e8 ff 0e 0d 00       	call   0x54cc2b
  47bd2c:	8d 8f 70 18 00 00    	lea    ecx,[edi+0x1870]
  47bd32:	6a 04                	push   0x4
  47bd34:	51                   	push   ecx
  47bd35:	8b ce                	mov    ecx,esi
  47bd37:	e8 ef 0e 0d 00       	call   0x54cc2b
  47bd3c:	8d 97 74 18 00 00    	lea    edx,[edi+0x1874]
  47bd42:	6a 04                	push   0x4
  47bd44:	52                   	push   edx
  47bd45:	8b ce                	mov    ecx,esi
  47bd47:	e8 df 0e 0d 00       	call   0x54cc2b
  47bd4c:	8d 87 78 18 00 00    	lea    eax,[edi+0x1878]
  47bd52:	6a 04                	push   0x4
  47bd54:	50                   	push   eax
  47bd55:	8b ce                	mov    ecx,esi
  47bd57:	e8 cf 0e 0d 00       	call   0x54cc2b
  47bd5c:	8d 4f 38             	lea    ecx,[edi+0x38]
  47bd5f:	6a 04                	push   0x4
  47bd61:	51                   	push   ecx
  47bd62:	8b ce                	mov    ecx,esi
  47bd64:	e8 c2 0e 0d 00       	call   0x54cc2b
  47bd69:	8d 97 98 18 00 00    	lea    edx,[edi+0x1898]
  47bd6f:	6a 40                	push   0x40
  47bd71:	52                   	push   edx
  47bd72:	8b ce                	mov    ecx,esi
  47bd74:	e8 b2 0e 0d 00       	call   0x54cc2b
  47bd79:	8d 87 d8 18 00 00    	lea    eax,[edi+0x18d8]
  47bd7f:	68 c0 00 00 00       	push   0xc0
  47bd84:	50                   	push   eax
  47bd85:	8b ce                	mov    ecx,esi
  47bd87:	e8 9f 0e 0d 00       	call   0x54cc2b
  47bd8c:	8d 8f 7c 18 00 00    	lea    ecx,[edi+0x187c]
  47bd92:	6a 04                	push   0x4
  47bd94:	51                   	push   ecx
  47bd95:	8b ce                	mov    ecx,esi
  47bd97:	e8 8f 0e 0d 00       	call   0x54cc2b
  47bd9c:	8d 97 fc 19 00 00    	lea    edx,[edi+0x19fc]
  47bda2:	6a 04                	push   0x4
  47bda4:	52                   	push   edx
  47bda5:	8b ce                	mov    ecx,esi
  47bda7:	e8 7f 0e 0d 00       	call   0x54cc2b
  47bdac:	8d 87 00 1a 00 00    	lea    eax,[edi+0x1a00]
  47bdb2:	6a 04                	push   0x4
  47bdb4:	50                   	push   eax
  47bdb5:	8b ce                	mov    ecx,esi
  47bdb7:	e8 6f 0e 0d 00       	call   0x54cc2b
  47bdbc:	8d 8f 04 1a 00 00    	lea    ecx,[edi+0x1a04]
  47bdc2:	6a 04                	push   0x4
  47bdc4:	51                   	push   ecx
  47bdc5:	8b ce                	mov    ecx,esi
  47bdc7:	e8 5f 0e 0d 00       	call   0x54cc2b
  47bdcc:	8d 97 80 18 00 00    	lea    edx,[edi+0x1880]
  47bdd2:	6a 04                	push   0x4
  47bdd4:	52                   	push   edx
  47bdd5:	8b ce                	mov    ecx,esi
  47bdd7:	e8 4f 0e 0d 00       	call   0x54cc2b
  47bddc:	6a 10                	push   0x10
  47bdde:	8d 87 b4 19 00 00    	lea    eax,[edi+0x19b4]
  47bde4:	8b ce                	mov    ecx,esi
  47bde6:	50                   	push   eax
  47bde7:	e8 3f 0e 0d 00       	call   0x54cc2b
  47bdec:	8d 8f b4 14 00 00    	lea    ecx,[edi+0x14b4]
  47bdf2:	6a 04                	push   0x4
  47bdf4:	51                   	push   ecx
  47bdf5:	8b ce                	mov    ecx,esi
  47bdf7:	e8 2f 0e 0d 00       	call   0x54cc2b
  47bdfc:	8d 97 20 1a 00 00    	lea    edx,[edi+0x1a20]
  47be02:	6a 01                	push   0x1
  47be04:	52                   	push   edx
  47be05:	8b ce                	mov    ecx,esi
  47be07:	e8 1f 0e 0d 00       	call   0x54cc2b
  47be0c:	8d 87 21 1a 00 00    	lea    eax,[edi+0x1a21]
  47be12:	6a 01                	push   0x1
  47be14:	50                   	push   eax
  47be15:	8b ce                	mov    ecx,esi
  47be17:	e8 0f 0e 0d 00       	call   0x54cc2b
  47be1c:	8d 8f 84 18 00 00    	lea    ecx,[edi+0x1884]
  47be22:	6a 10                	push   0x10
  47be24:	51                   	push   ecx
  47be25:	8b ce                	mov    ecx,esi
  47be27:	e8 ff 0d 0d 00       	call   0x54cc2b
  47be2c:	8d 97 2c 1a 00 00    	lea    edx,[edi+0x1a2c]
  47be32:	6a 04                	push   0x4
  47be34:	52                   	push   edx
  47be35:	8b ce                	mov    ecx,esi
  47be37:	e8 ef 0d 0d 00       	call   0x54cc2b
  47be3c:	8d 87 30 1a 00 00    	lea    eax,[edi+0x1a30]
  47be42:	6a 04                	push   0x4
  47be44:	50                   	push   eax
  47be45:	8b ce                	mov    ecx,esi
  47be47:	e8 df 0d 0d 00       	call   0x54cc2b
  47be4c:	8d 8f 34 1a 00 00    	lea    ecx,[edi+0x1a34]
  47be52:	6a 04                	push   0x4
  47be54:	51                   	push   ecx
  47be55:	8b ce                	mov    ecx,esi
  47be57:	e8 cf 0d 0d 00       	call   0x54cc2b
  47be5c:	8d 97 38 1a 00 00    	lea    edx,[edi+0x1a38]
  47be62:	6a 04                	push   0x4
  47be64:	52                   	push   edx
  47be65:	8b ce                	mov    ecx,esi
  47be67:	e8 bf 0d 0d 00       	call   0x54cc2b
  47be6c:	8d 87 24 1a 00 00    	lea    eax,[edi+0x1a24]
  47be72:	6a 04                	push   0x4
  47be74:	50                   	push   eax
  47be75:	8b ce                	mov    ecx,esi
  47be77:	e8 af 0d 0d 00       	call   0x54cc2b
  47be7c:	8d 8f b8 14 00 00    	lea    ecx,[edi+0x14b8]
  47be82:	6a 04                	push   0x4
  47be84:	51                   	push   ecx
  47be85:	8b ce                	mov    ecx,esi
  47be87:	e8 9f 0d 0d 00       	call   0x54cc2b
  47be8c:	8d 97 bc 14 00 00    	lea    edx,[edi+0x14bc]
  47be92:	6a 04                	push   0x4
  47be94:	52                   	push   edx
  47be95:	8b ce                	mov    ecx,esi
  47be97:	e8 8f 0d 0d 00       	call   0x54cc2b
  47be9c:	8d 87 94 18 00 00    	lea    eax,[edi+0x1894]
  47bea2:	6a 04                	push   0x4
  47bea4:	50                   	push   eax
  47bea5:	8b ce                	mov    ecx,esi
  47bea7:	e8 7f 0d 0d 00       	call   0x54cc2b
  47beac:	8b 87 dc 14 00 00    	mov    eax,DWORD PTR [edi+0x14dc]
  47beb2:	85 c0                	test   eax,eax
  47beb4:	75 11                	jne    0x47bec7
  47beb6:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  47beba:	6a 04                	push   0x4
  47bebc:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  47bec3:	00 
  47bec4:	51                   	push   ecx
  47bec5:	eb 3e                	jmp    0x47bf05
  47bec7:	8d 54 24 14          	lea    edx,[esp+0x14]
  47becb:	6a 04                	push   0x4
  47becd:	52                   	push   edx
  47bece:	8b ce                	mov    ecx,esi
  47bed0:	c7 44 24 1c 01 00 00 	mov    DWORD PTR [esp+0x1c],0x1
  47bed7:	00 
  47bed8:	e8 4e 0d 0d 00       	call   0x54cc2b
  47bedd:	8b 87 dc 14 00 00    	mov    eax,DWORD PTR [edi+0x14dc]
  47bee3:	8b 4d 00             	mov    ecx,DWORD PTR [ebp+0x0]
  47bee6:	50                   	push   eax
  47bee7:	51                   	push   ecx
  47bee8:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  47beee:	e8 ed cc 00 00       	call   0x488be0
  47bef3:	8b c8                	mov    ecx,eax
  47bef5:	e8 76 1f 06 00       	call   0x4dde70
  47befa:	8d 54 24 18          	lea    edx,[esp+0x18]
  47befe:	6a 04                	push   0x4
  47bf00:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  47bf04:	52                   	push   edx
  47bf05:	8b ce                	mov    ecx,esi
  47bf07:	e8 1f 0d 0d 00       	call   0x54cc2b
  47bf0c:	8b 87 e0 14 00 00    	mov    eax,DWORD PTR [edi+0x14e0]
  47bf12:	8b 0d cc c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5cc
  47bf18:	50                   	push   eax
  47bf19:	e8 92 ed 06 00       	call   0x4eacb0
  47bf1e:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  47bf22:	6a 04                	push   0x4
  47bf24:	51                   	push   ecx
  47bf25:	8b ce                	mov    ecx,esi
  47bf27:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  47bf2b:	e8 fb 0c 0d 00       	call   0x54cc2b
  47bf30:	8b 97 f8 14 00 00    	mov    edx,DWORD PTR [edi+0x14f8]
  47bf36:	8d 44 24 10          	lea    eax,[esp+0x10]
  47bf3a:	6a 04                	push   0x4
  47bf3c:	50                   	push   eax
  47bf3d:	8b ce                	mov    ecx,esi
  47bf3f:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  47bf43:	e8 e3 0c 0d 00       	call   0x54cc2b
  47bf48:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47bf4c:	33 c0                	xor    eax,eax
  47bf4e:	85 c9                	test   ecx,ecx
  47bf50:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47bf54:	7e 29                	jle    0x47bf7f
  47bf56:	8d 9f e4 14 00 00    	lea    ebx,[edi+0x14e4]
  47bf5c:	6a 00                	push   0x0
  47bf5e:	50                   	push   eax
  47bf5f:	8b cb                	mov    ecx,ebx
  47bf61:	e8 8a 58 f8 ff       	call   0x4017f0
  47bf66:	56                   	push   esi
  47bf67:	8b c8                	mov    ecx,eax
  47bf69:	e8 92 52 f8 ff       	call   0x401200
  47bf6e:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  47bf72:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47bf76:	40                   	inc    eax
  47bf77:	3b c1                	cmp    eax,ecx
  47bf79:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47bf7d:	7c dd                	jl     0x47bf5c
  47bf7f:	8b 8f f0 16 00 00    	mov    ecx,DWORD PTR [edi+0x16f0]
  47bf85:	51                   	push   ecx
  47bf86:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  47bf8a:	e8 01 bf 05 00       	call   0x4d7e90
  47bf8f:	8d 54 24 18          	lea    edx,[esp+0x18]
  47bf93:	6a 04                	push   0x4
  47bf95:	52                   	push   edx
  47bf96:	8b ce                	mov    ecx,esi
  47bf98:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  47bf9c:	e8 8a 0c 0d 00       	call   0x54cc2b
  47bfa1:	8b 87 14 15 00 00    	mov    eax,DWORD PTR [edi+0x1514]
  47bfa7:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  47bfab:	6a 04                	push   0x4
  47bfad:	51                   	push   ecx
  47bfae:	8b ce                	mov    ecx,esi
  47bfb0:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47bfb4:	e8 72 0c 0d 00       	call   0x54cc2b
  47bfb9:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47bfbd:	33 c0                	xor    eax,eax
  47bfbf:	85 c9                	test   ecx,ecx
  47bfc1:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47bfc5:	7e 5a                	jle    0x47c021
  47bfc7:	8d af 00 15 00 00    	lea    ebp,[edi+0x1500]
  47bfcd:	6a 00                	push   0x0
  47bfcf:	50                   	push   eax
  47bfd0:	8b cd                	mov    ecx,ebp
  47bfd2:	e8 19 58 f8 ff       	call   0x4017f0
  47bfd7:	8b d8                	mov    ebx,eax
  47bfd9:	8d 44 24 20          	lea    eax,[esp+0x20]
  47bfdd:	6a 04                	push   0x4
  47bfdf:	50                   	push   eax
  47bfe0:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  47bfe3:	8b ce                	mov    ecx,esi
  47bfe5:	89 54 24 28          	mov    DWORD PTR [esp+0x28],edx
  47bfe9:	e8 3d 0c 0d 00       	call   0x54cc2b
  47bfee:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  47bff3:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  47bff5:	53                   	push   ebx
  47bff6:	8d 48 20             	lea    ecx,[eax+0x20]
  47bff9:	e8 32 59 f8 ff       	call   0x401930
  47bffe:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  47c002:	6a 04                	push   0x4
  47c004:	51                   	push   ecx
  47c005:	8b ce                	mov    ecx,esi
  47c007:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  47c00b:	e8 1b 0c 0d 00       	call   0x54cc2b
  47c010:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  47c014:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c018:	40                   	inc    eax
  47c019:	3b c1                	cmp    eax,ecx
  47c01b:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c01f:	7c ac                	jl     0x47bfcd
  47c021:	8b 97 0c 17 00 00    	mov    edx,DWORD PTR [edi+0x170c]
  47c027:	8d 44 24 10          	lea    eax,[esp+0x10]
  47c02b:	6a 04                	push   0x4
  47c02d:	50                   	push   eax
  47c02e:	8b ce                	mov    ecx,esi
  47c030:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  47c034:	e8 f2 0b 0d 00       	call   0x54cc2b
  47c039:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c03d:	33 c0                	xor    eax,eax
  47c03f:	85 c9                	test   ecx,ecx
  47c041:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c045:	7e 3c                	jle    0x47c083
  47c047:	8d af f8 16 00 00    	lea    ebp,[edi+0x16f8]
  47c04d:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  47c051:	51                   	push   ecx
  47c052:	50                   	push   eax
  47c053:	8b cd                	mov    ecx,ebp
  47c055:	e8 96 57 f8 ff       	call   0x4017f0
  47c05a:	8d 54 24 18          	lea    edx,[esp+0x18]
  47c05e:	6a 04                	push   0x4
  47c060:	52                   	push   edx
  47c061:	8b ce                	mov    ecx,esi
  47c063:	8b d8                	mov    ebx,eax
  47c065:	e8 c1 0b 0d 00       	call   0x54cc2b
  47c06a:	56                   	push   esi
  47c06b:	8b cb                	mov    ecx,ebx
  47c06d:	e8 be 9d 06 00       	call   0x4e5e30
  47c072:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  47c076:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c07a:	40                   	inc    eax
  47c07b:	3b c1                	cmp    eax,ecx
  47c07d:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c081:	7c ca                	jl     0x47c04d
  47c083:	8b 87 3c 17 00 00    	mov    eax,DWORD PTR [edi+0x173c]
  47c089:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  47c08d:	6a 04                	push   0x4
  47c08f:	51                   	push   ecx
  47c090:	8b ce                	mov    ecx,esi
  47c092:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47c096:	e8 90 0b 0d 00       	call   0x54cc2b
  47c09b:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c09f:	33 c0                	xor    eax,eax
  47c0a1:	85 c9                	test   ecx,ecx
  47c0a3:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c0a7:	7e 33                	jle    0x47c0dc
  47c0a9:	8d 9f 28 17 00 00    	lea    ebx,[edi+0x1728]
  47c0af:	6a 00                	push   0x0
  47c0b1:	50                   	push   eax
  47c0b2:	8b cb                	mov    ecx,ebx
  47c0b4:	e8 37 57 f8 ff       	call   0x4017f0
  47c0b9:	8d 54 24 18          	lea    edx,[esp+0x18]
  47c0bd:	6a 04                	push   0x4
  47c0bf:	52                   	push   edx
  47c0c0:	8b ce                	mov    ecx,esi
  47c0c2:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  47c0c6:	e8 60 0b 0d 00       	call   0x54cc2b
  47c0cb:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  47c0cf:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c0d3:	40                   	inc    eax
  47c0d4:	3b c1                	cmp    eax,ecx
  47c0d6:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c0da:	7c d3                	jl     0x47c0af
  47c0dc:	8b 87 58 17 00 00    	mov    eax,DWORD PTR [edi+0x1758]
  47c0e2:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  47c0e6:	6a 04                	push   0x4
  47c0e8:	51                   	push   ecx
  47c0e9:	8b ce                	mov    ecx,esi
  47c0eb:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47c0ef:	e8 37 0b 0d 00       	call   0x54cc2b
  47c0f4:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c0f8:	33 c0                	xor    eax,eax
  47c0fa:	85 c9                	test   ecx,ecx
  47c0fc:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c100:	7e 33                	jle    0x47c135
  47c102:	8d 9f 44 17 00 00    	lea    ebx,[edi+0x1744]
  47c108:	6a 00                	push   0x0
  47c10a:	50                   	push   eax
  47c10b:	8b cb                	mov    ecx,ebx
  47c10d:	e8 de 56 f8 ff       	call   0x4017f0
  47c112:	8d 54 24 18          	lea    edx,[esp+0x18]
  47c116:	6a 04                	push   0x4
  47c118:	52                   	push   edx
  47c119:	8b ce                	mov    ecx,esi
  47c11b:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  47c11f:	e8 07 0b 0d 00       	call   0x54cc2b
  47c124:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  47c128:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c12c:	40                   	inc    eax
  47c12d:	3b c1                	cmp    eax,ecx
  47c12f:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c133:	7c d3                	jl     0x47c108
  47c135:	8b 87 74 17 00 00    	mov    eax,DWORD PTR [edi+0x1774]
  47c13b:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  47c13f:	6a 04                	push   0x4
  47c141:	51                   	push   ecx
  47c142:	8b ce                	mov    ecx,esi
  47c144:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47c148:	e8 de 0a 0d 00       	call   0x54cc2b
  47c14d:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c151:	33 c0                	xor    eax,eax
  47c153:	85 c9                	test   ecx,ecx
  47c155:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c159:	7e 33                	jle    0x47c18e
  47c15b:	8d 9f 60 17 00 00    	lea    ebx,[edi+0x1760]
  47c161:	6a 00                	push   0x0
  47c163:	50                   	push   eax
  47c164:	8b cb                	mov    ecx,ebx
  47c166:	e8 85 56 f8 ff       	call   0x4017f0
  47c16b:	8d 54 24 18          	lea    edx,[esp+0x18]
  47c16f:	6a 04                	push   0x4
  47c171:	52                   	push   edx
  47c172:	8b ce                	mov    ecx,esi
  47c174:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  47c178:	e8 ae 0a 0d 00       	call   0x54cc2b
  47c17d:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  47c181:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c185:	40                   	inc    eax
  47c186:	3b c1                	cmp    eax,ecx
  47c188:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c18c:	7c d3                	jl     0x47c161
  47c18e:	8b 87 ac 19 00 00    	mov    eax,DWORD PTR [edi+0x19ac]
  47c194:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  47c198:	6a 04                	push   0x4
  47c19a:	51                   	push   ecx
  47c19b:	8b ce                	mov    ecx,esi
  47c19d:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47c1a1:	e8 85 0a 0d 00       	call   0x54cc2b
  47c1a6:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c1aa:	33 c0                	xor    eax,eax
  47c1ac:	85 c9                	test   ecx,ecx
  47c1ae:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c1b2:	7e 3e                	jle    0x47c1f2
  47c1b4:	8d af 98 19 00 00    	lea    ebp,[edi+0x1998]
  47c1ba:	8d 54 24 18          	lea    edx,[esp+0x18]
  47c1be:	8b cd                	mov    ecx,ebp
  47c1c0:	52                   	push   edx
  47c1c1:	50                   	push   eax
  47c1c2:	e8 29 56 f8 ff       	call   0x4017f0
  47c1c7:	8b d8                	mov    ebx,eax
  47c1c9:	8d 44 24 18          	lea    eax,[esp+0x18]
  47c1cd:	6a 04                	push   0x4
  47c1cf:	50                   	push   eax
  47c1d0:	8b ce                	mov    ecx,esi
  47c1d2:	e8 54 0a 0d 00       	call   0x54cc2b
  47c1d7:	6a 20                	push   0x20
  47c1d9:	53                   	push   ebx
  47c1da:	8b ce                	mov    ecx,esi
  47c1dc:	e8 4a 0a 0d 00       	call   0x54cc2b
  47c1e1:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  47c1e5:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c1e9:	40                   	inc    eax
  47c1ea:	3b c1                	cmp    eax,ecx
  47c1ec:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c1f0:	7c c8                	jl     0x47c1ba
  47c1f2:	8b 8f d8 19 00 00    	mov    ecx,DWORD PTR [edi+0x19d8]
  47c1f8:	8d 54 24 10          	lea    edx,[esp+0x10]
  47c1fc:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  47c200:	6a 04                	push   0x4
  47c202:	52                   	push   edx
  47c203:	8b ce                	mov    ecx,esi
  47c205:	e8 21 0a 0d 00       	call   0x54cc2b
  47c20a:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c20e:	33 c0                	xor    eax,eax
  47c210:	85 c9                	test   ecx,ecx
  47c212:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c216:	7e 2b                	jle    0x47c243
  47c218:	8d 9f c4 19 00 00    	lea    ebx,[edi+0x19c4]
  47c21e:	6a 00                	push   0x0
  47c220:	50                   	push   eax
  47c221:	8b cb                	mov    ecx,ebx
  47c223:	e8 c8 55 f8 ff       	call   0x4017f0
  47c228:	6a 30                	push   0x30
  47c22a:	50                   	push   eax
  47c22b:	8b ce                	mov    ecx,esi
  47c22d:	e8 f9 09 0d 00       	call   0x54cc2b
  47c232:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  47c236:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c23a:	40                   	inc    eax
  47c23b:	3b c1                	cmp    eax,ecx
  47c23d:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c241:	7c db                	jl     0x47c21e
  47c243:	8b 87 f4 19 00 00    	mov    eax,DWORD PTR [edi+0x19f4]
  47c249:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  47c24d:	6a 04                	push   0x4
  47c24f:	51                   	push   ecx
  47c250:	8b ce                	mov    ecx,esi
  47c252:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47c256:	e8 d0 09 0d 00       	call   0x54cc2b
  47c25b:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c25f:	33 c0                	xor    eax,eax
  47c261:	85 c9                	test   ecx,ecx
  47c263:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c267:	7e 3c                	jle    0x47c2a5
  47c269:	81 c7 e0 19 00 00    	add    edi,0x19e0
  47c26f:	8d 54 24 18          	lea    edx,[esp+0x18]
  47c273:	8b cf                	mov    ecx,edi
  47c275:	52                   	push   edx
  47c276:	50                   	push   eax
  47c277:	e8 74 55 f8 ff       	call   0x4017f0
  47c27c:	8b d8                	mov    ebx,eax
  47c27e:	8d 44 24 18          	lea    eax,[esp+0x18]
  47c282:	6a 04                	push   0x4
  47c284:	50                   	push   eax
  47c285:	8b ce                	mov    ecx,esi
  47c287:	e8 9f 09 0d 00       	call   0x54cc2b
  47c28c:	56                   	push   esi
  47c28d:	8b cb                	mov    ecx,ebx
  47c28f:	e8 9c 9b 06 00       	call   0x4e5e30
  47c294:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  47c298:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47c29c:	40                   	inc    eax
  47c29d:	3b c1                	cmp    eax,ecx
  47c29f:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47c2a3:	7c ca                	jl     0x47c26f
  47c2a5:	5f                   	pop    edi
  47c2a6:	5e                   	pop    esi
  47c2a7:	5d                   	pop    ebp
  47c2a8:	5b                   	pop    ebx
  47c2a9:	83 c4 14             	add    esp,0x14
  47c2ac:	c2                   	.byte 0xc2
  47c2ad:	04                   	.byte 0x4
```

## `Branch_Construct` — `0x476b60`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x476b60.c`
- Callers: `Branch_ConstructFromStream` (0x477000), `Company_Load` (0x4e0f90), `Player_CreateBranch` (0x4f7420)
- Callees: `Branch_ApplyBuildingStyleVariant` (0x47e6a0), `Game_GetSizeName` (0x47e5e0), `Game_RegisterWorldObject` (0x4eac80), `Grid_RebuildStreetNodes` (0x4f3200), `IsoMap_Construct` (0x4eb0f0), `List_Add` (0x4014b0), `List_Construct` (0x4013a0), `Map_CollectType351ToList` (0x47e6e0), `Object_GetBufferCount` (0x4f1250), `Stats_Report_ConstructEmpty` (0x4010f0), `Stats_ResetAverages` (0x4805d0)

- Unresolved questions: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

00476b60 <.text+0x75b60>:
  476b60:	6a ff                	push   0xffffffff
  476b62:	68 5a 7e 55 00       	push   0x557e5a
  476b67:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  476b6d:	50                   	push   eax
  476b6e:	64 89 25 00 00 00 00 	mov    DWORD PTR fs:0x0,esp
  476b75:	51                   	push   ecx
  476b76:	53                   	push   ebx
  476b77:	55                   	push   ebp
  476b78:	56                   	push   esi
  476b79:	8b f1                	mov    esi,ecx
  476b7b:	33 db                	xor    ebx,ebx
  476b7d:	57                   	push   edi
  476b7e:	8d ae e4 14 00 00    	lea    ebp,[esi+0x14e4]
  476b84:	53                   	push   ebx
  476b85:	8b cd                	mov    ecx,ebp
  476b87:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  476b8b:	e8 10 a8 f8 ff       	call   0x4013a0
  476b90:	53                   	push   ebx
  476b91:	8d 8e 00 15 00 00    	lea    ecx,[esi+0x1500]
  476b97:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  476b9b:	e8 00 a8 f8 ff       	call   0x4013a0
  476ba0:	53                   	push   ebx
  476ba1:	8d 8e f8 16 00 00    	lea    ecx,[esi+0x16f8]
  476ba7:	c6 44 24 20 01       	mov    BYTE PTR [esp+0x20],0x1
  476bac:	e8 ef a7 f8 ff       	call   0x4013a0
  476bb1:	53                   	push   ebx
  476bb2:	8d 8e 28 17 00 00    	lea    ecx,[esi+0x1728]
  476bb8:	c6 44 24 20 02       	mov    BYTE PTR [esp+0x20],0x2
  476bbd:	e8 de a7 f8 ff       	call   0x4013a0
  476bc2:	53                   	push   ebx
  476bc3:	8d 8e 44 17 00 00    	lea    ecx,[esi+0x1744]
  476bc9:	c6 44 24 20 03       	mov    BYTE PTR [esp+0x20],0x3
  476bce:	e8 cd a7 f8 ff       	call   0x4013a0
  476bd3:	53                   	push   ebx
  476bd4:	8d 8e 60 17 00 00    	lea    ecx,[esi+0x1760]
  476bda:	c6 44 24 20 04       	mov    BYTE PTR [esp+0x20],0x4
  476bdf:	e8 bc a7 f8 ff       	call   0x4013a0
  476be4:	53                   	push   ebx
  476be5:	8d 8e 98 19 00 00    	lea    ecx,[esi+0x1998]
  476beb:	c6 44 24 20 05       	mov    BYTE PTR [esp+0x20],0x5
  476bf0:	e8 ab a7 f8 ff       	call   0x4013a0
  476bf5:	53                   	push   ebx
  476bf6:	8d 8e c4 19 00 00    	lea    ecx,[esi+0x19c4]
  476bfc:	c6 44 24 20 06       	mov    BYTE PTR [esp+0x20],0x6
  476c01:	e8 9a a7 f8 ff       	call   0x4013a0
  476c06:	53                   	push   ebx
  476c07:	8d 8e e0 19 00 00    	lea    ecx,[esi+0x19e0]
  476c0d:	c6 44 24 20 07       	mov    BYTE PTR [esp+0x20],0x7
  476c12:	e8 89 a7 f8 ff       	call   0x4013a0
  476c17:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  476c1b:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  476c1f:	8b 54 24 24          	mov    edx,DWORD PTR [esp+0x24]
  476c23:	c7 06 0c c3 55 00    	mov    DWORD PTR [esi],0x55c30c
  476c29:	89 46 30             	mov    DWORD PTR [esi+0x30],eax
  476c2c:	89 4e 34             	mov    DWORD PTR [esi+0x34],ecx
  476c2f:	89 56 38             	mov    DWORD PTR [esi+0x38],edx
  476c32:	89 9e dc 14 00 00    	mov    DWORD PTR [esi+0x14dc],ebx
  476c38:	c7 86 a8 14 00 00 64 	mov    DWORD PTR [esi+0x14a8],0x64
  476c3f:	00 00 00 
  476c42:	c7 86 ac 14 00 00 0a 	mov    DWORD PTR [esi+0x14ac],0xa
  476c49:	00 00 00 
  476c4c:	89 9e b8 14 00 00    	mov    DWORD PTR [esi+0x14b8],ebx
  476c52:	89 9e bc 14 00 00    	mov    DWORD PTR [esi+0x14bc],ebx
  476c58:	89 9e 94 18 00 00    	mov    DWORD PTR [esi+0x1894],ebx
  476c5e:	b9 51 00 00 00       	mov    ecx,0x51
  476c63:	33 c0                	xor    eax,eax
  476c65:	8d 7e 44             	lea    edi,[esi+0x44]
  476c68:	89 9e 28 1a 00 00    	mov    DWORD PTR [esi+0x1a28],ebx
  476c6e:	c6 44 24 1c 08       	mov    BYTE PTR [esp+0x1c],0x8
  476c73:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476c75:	b9 51 00 00 00       	mov    ecx,0x51
  476c7a:	8d be 88 01 00 00    	lea    edi,[esi+0x188]
  476c80:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476c82:	b9 51 00 00 00       	mov    ecx,0x51
  476c87:	8d be cc 02 00 00    	lea    edi,[esi+0x2cc]
  476c8d:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476c8f:	b9 51 00 00 00       	mov    ecx,0x51
  476c94:	8d be 10 04 00 00    	lea    edi,[esi+0x410]
  476c9a:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476c9c:	b9 84 03 00 00       	mov    ecx,0x384
  476ca1:	8d be 54 05 00 00    	lea    edi,[esi+0x554]
  476ca7:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476ca9:	b9 09 00 00 00       	mov    ecx,0x9
  476cae:	8d be 64 13 00 00    	lea    edi,[esi+0x1364]
  476cb4:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476cb6:	8d 8e b4 19 00 00    	lea    ecx,[esi+0x19b4]
  476cbc:	8d be 88 13 00 00    	lea    edi,[esi+0x1388]
  476cc2:	89 01                	mov    DWORD PTR [ecx],eax
  476cc4:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  476cc7:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  476cca:	89 41 0c             	mov    DWORD PTR [ecx+0xc],eax
  476ccd:	b9 12 00 00 00       	mov    ecx,0x12
  476cd2:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476cd4:	b9 12 00 00 00       	mov    ecx,0x12
  476cd9:	8d be d0 13 00 00    	lea    edi,[esi+0x13d0]
  476cdf:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476ce1:	b9 12 00 00 00       	mov    ecx,0x12
  476ce6:	8d be 18 14 00 00    	lea    edi,[esi+0x1418]
  476cec:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476cee:	b9 12 00 00 00       	mov    ecx,0x12
  476cf3:	8d be 60 14 00 00    	lea    edi,[esi+0x1460]
  476cf9:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476cfb:	8d 8e 84 18 00 00    	lea    ecx,[esi+0x1884]
  476d01:	8d be 7c 17 00 00    	lea    edi,[esi+0x177c]
  476d07:	89 01                	mov    DWORD PTR [ecx],eax
  476d09:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  476d0c:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  476d0f:	89 41 0c             	mov    DWORD PTR [ecx+0xc],eax
  476d12:	89 9e c8 14 00 00    	mov    DWORD PTR [esi+0x14c8],ebx
  476d18:	89 9e cc 14 00 00    	mov    DWORD PTR [esi+0x14cc],ebx
  476d1e:	89 9e d0 14 00 00    	mov    DWORD PTR [esi+0x14d0],ebx
  476d24:	89 9e d4 14 00 00    	mov    DWORD PTR [esi+0x14d4],ebx
  476d2a:	89 9e c0 14 00 00    	mov    DWORD PTR [esi+0x14c0],ebx
  476d30:	89 9e b4 14 00 00    	mov    DWORD PTR [esi+0x14b4],ebx
  476d36:	b9 08 00 00 00       	mov    ecx,0x8
  476d3b:	c7 86 d8 14 00 00 ff 	mov    DWORD PTR [esi+0x14d8],0xffffffff
  476d42:	ff ff ff 
  476d45:	89 5e 24             	mov    DWORD PTR [esi+0x24],ebx
  476d48:	89 9e f0 16 00 00    	mov    DWORD PTR [esi+0x16f0],ebx
  476d4e:	89 5e 28             	mov    DWORD PTR [esi+0x28],ebx
  476d51:	89 5e 2c             	mov    DWORD PTR [esi+0x2c],ebx
  476d54:	c6 86 f4 16 00 00 01 	mov    BYTE PTR [esi+0x16f4],0x1
  476d5b:	89 9e b0 14 00 00    	mov    DWORD PTR [esi+0x14b0],ebx
  476d61:	89 9e c4 14 00 00    	mov    DWORD PTR [esi+0x14c4],ebx
  476d67:	89 9e 14 17 00 00    	mov    DWORD PTR [esi+0x1714],ebx
  476d6d:	89 9e 18 17 00 00    	mov    DWORD PTR [esi+0x1718],ebx
  476d73:	89 9e 1c 17 00 00    	mov    DWORD PTR [esi+0x171c],ebx
  476d79:	89 9e 20 17 00 00    	mov    DWORD PTR [esi+0x1720],ebx
  476d7f:	89 9e 24 17 00 00    	mov    DWORD PTR [esi+0x1724],ebx
  476d85:	88 9e f5 16 00 00    	mov    BYTE PTR [esi+0x16f5],bl
  476d8b:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476d8d:	b9 08 00 00 00       	mov    ecx,0x8
  476d92:	8d be 9c 17 00 00    	lea    edi,[esi+0x179c]
  476d98:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476d9a:	b9 08 00 00 00       	mov    ecx,0x8
  476d9f:	8d be bc 17 00 00    	lea    edi,[esi+0x17bc]
  476da5:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476da7:	b9 10 00 00 00       	mov    ecx,0x10
  476dac:	8d be 98 18 00 00    	lea    edi,[esi+0x1898]
  476db2:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476db4:	b9 30 00 00 00       	mov    ecx,0x30
  476db9:	8d be d8 18 00 00    	lea    edi,[esi+0x18d8]
  476dbf:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476dc1:	b9 0d 00 00 00       	mov    ecx,0xd
  476dc6:	8d be bc 16 00 00    	lea    edi,[esi+0x16bc]
  476dcc:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476dce:	b9 68 00 00 00       	mov    ecx,0x68
  476dd3:	8d be 1c 15 00 00    	lea    edi,[esi+0x151c]
  476dd9:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  476ddb:	b8 04 00 00 00       	mov    eax,0x4
  476de0:	89 9e 7c 18 00 00    	mov    DWORD PTR [esi+0x187c],ebx
  476de6:	89 86 fc 19 00 00    	mov    DWORD PTR [esi+0x19fc],eax
  476dec:	89 9e 00 1a 00 00    	mov    DWORD PTR [esi+0x1a00],ebx
  476df2:	89 86 04 1a 00 00    	mov    DWORD PTR [esi+0x1a04],eax
  476df8:	88 9e 80 18 00 00    	mov    BYTE PTR [esi+0x1880],bl
  476dfe:	88 9e 81 18 00 00    	mov    BYTE PTR [esi+0x1881],bl
  476e04:	88 9e 82 18 00 00    	mov    BYTE PTR [esi+0x1882],bl
  476e0a:	88 9e 83 18 00 00    	mov    BYTE PTR [esi+0x1883],bl
  476e10:	88 9e 20 1a 00 00    	mov    BYTE PTR [esi+0x1a20],bl
  476e16:	88 9e 21 1a 00 00    	mov    BYTE PTR [esi+0x1a21],bl
  476e1c:	c7 46 3c ff ff ff ff 	mov    DWORD PTR [esi+0x3c],0xffffffff
  476e23:	c7 86 2c 1a 00 00 01 	mov    DWORD PTR [esi+0x1a2c],0x1
  476e2a:	00 00 00 
  476e2d:	8b c2                	mov    eax,edx
  476e2f:	89 9e 30 1a 00 00    	mov    DWORD PTR [esi+0x1a30],ebx
  476e35:	2b c3                	sub    eax,ebx
  476e37:	89 9e 34 1a 00 00    	mov    DWORD PTR [esi+0x1a34],ebx
  476e3d:	89 9e 38 1a 00 00    	mov    DWORD PTR [esi+0x1a38],ebx
  476e43:	89 9e 24 1a 00 00    	mov    DWORD PTR [esi+0x1a24],ebx
  476e49:	74 68                	je     0x476eb3
  476e4b:	48                   	dec    eax
  476e4c:	74 36                	je     0x476e84
  476e4e:	48                   	dec    eax
  476e4f:	0f 85 9a 00 00 00    	jne    0x476eef
  476e55:	68 78 01 01 00       	push   0x10178
  476e5a:	e8 c2 73 0d 00       	call   0x54e221
  476e5f:	83 c4 04             	add    esp,0x4
  476e62:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  476e66:	3b c3                	cmp    eax,ebx
  476e68:	c6 44 24 1c 0b       	mov    BYTE PTR [esp+0x1c],0xb
  476e6d:	74 73                	je     0x476ee2
  476e6f:	8b 15 cc c5 57 00    	mov    edx,DWORD PTR ds:0x57c5cc
  476e75:	68 90 7b 56 00       	push   0x567b90
  476e7a:	52                   	push   edx
  476e7b:	8b c8                	mov    ecx,eax
  476e7d:	e8 6e 42 07 00       	call   0x4eb0f0
  476e82:	eb 60                	jmp    0x476ee4
  476e84:	68 78 01 01 00       	push   0x10178
  476e89:	e8 93 73 0d 00       	call   0x54e221
  476e8e:	83 c4 04             	add    esp,0x4
  476e91:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  476e95:	3b c3                	cmp    eax,ebx
  476e97:	c6 44 24 1c 0a       	mov    BYTE PTR [esp+0x1c],0xa
  476e9c:	74 44                	je     0x476ee2
  476e9e:	8b 0d cc c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5cc
  476ea4:	68 74 7b 56 00       	push   0x567b74
  476ea9:	51                   	push   ecx
  476eaa:	8b c8                	mov    ecx,eax
  476eac:	e8 3f 42 07 00       	call   0x4eb0f0
  476eb1:	eb 31                	jmp    0x476ee4
  476eb3:	68 78 01 01 00       	push   0x10178
  476eb8:	e8 64 73 0d 00       	call   0x54e221
  476ebd:	83 c4 04             	add    esp,0x4
  476ec0:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  476ec4:	3b c3                	cmp    eax,ebx
  476ec6:	c6 44 24 1c 09       	mov    BYTE PTR [esp+0x1c],0x9
  476ecb:	74 15                	je     0x476ee2
  476ecd:	8b 15 cc c5 57 00    	mov    edx,DWORD PTR ds:0x57c5cc
  476ed3:	68 58 7b 56 00       	push   0x567b58
  476ed8:	52                   	push   edx
  476ed9:	8b c8                	mov    ecx,eax
  476edb:	e8 10 42 07 00       	call   0x4eb0f0
  476ee0:	eb 02                	jmp    0x476ee4
  476ee2:	33 c0                	xor    eax,eax
  476ee4:	c6 44 24 1c 08       	mov    BYTE PTR [esp+0x1c],0x8
  476ee9:	89 86 e0 14 00 00    	mov    DWORD PTR [esi+0x14e0],eax
  476eef:	8b 8e e0 14 00 00    	mov    ecx,DWORD PTR [esi+0x14e0]
  476ef5:	6a 01                	push   0x1
  476ef7:	e8 54 a3 07 00       	call   0x4f1250
  476efc:	85 c0                	test   eax,eax
  476efe:	75 0c                	jne    0x476f0c
  476f00:	8b 8e e0 14 00 00    	mov    ecx,DWORD PTR [esi+0x14e0]
  476f06:	56                   	push   esi
  476f07:	e8 f4 c2 07 00       	call   0x4f3200
  476f0c:	8b 86 00 1a 00 00    	mov    eax,DWORD PTR [esi+0x1a00]
  476f12:	8b 8e fc 19 00 00    	mov    ecx,DWORD PTR [esi+0x19fc]
  476f18:	50                   	push   eax
  476f19:	51                   	push   ecx
  476f1a:	8b ce                	mov    ecx,esi
  476f1c:	e8 bf 76 00 00       	call   0x47e5e0
  476f21:	8b 96 04 1a 00 00    	mov    edx,DWORD PTR [esi+0x1a04]
  476f27:	8b ce                	mov    ecx,esi
  476f29:	52                   	push   edx
  476f2a:	e8 71 77 00 00       	call   0x47e6a0
  476f2f:	8b 86 e0 14 00 00    	mov    eax,DWORD PTR [esi+0x14e0]
  476f35:	8b 0d cc c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5cc
  476f3b:	6a ff                	push   0xffffffff
  476f3d:	50                   	push   eax
  476f3e:	e8 3d 3d 07 00       	call   0x4eac80
  476f43:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  476f49:	68 5c 03 00 00       	push   0x35c
  476f4e:	8b 91 94 00 00 00    	mov    edx,DWORD PTR [ecx+0x94]
  476f54:	66 8b 42 0a          	mov    ax,WORD PTR [edx+0xa]
  476f58:	25 ff ff 00 00       	and    eax,0xffff
  476f5d:	89 46 40             	mov    DWORD PTR [esi+0x40],eax
  476f60:	e8 bc 72 0d 00       	call   0x54e221
  476f65:	83 c4 04             	add    esp,0x4
  476f68:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  476f6c:	3b c3                	cmp    eax,ebx
  476f6e:	c6 44 24 1c 0c       	mov    BYTE PTR [esp+0x1c],0xc
  476f73:	74 2b                	je     0x476fa0
  476f75:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  476f7b:	8b b9 94 00 00 00    	mov    edi,DWORD PTR [ecx+0x94]
  476f81:	8b c8                	mov    ecx,eax
  476f83:	66 8b 57 04          	mov    dx,WORD PTR [edi+0x4]
  476f87:	66 8b 7f 0a          	mov    di,WORD PTR [edi+0xa]
  476f8b:	81 e2 ff ff 00 00    	and    edx,0xffff
  476f91:	81 e7 ff ff 00 00    	and    edi,0xffff
  476f97:	52                   	push   edx
  476f98:	57                   	push   edi
  476f99:	e8 52 a1 f8 ff       	call   0x4010f0
  476f9e:	eb 02                	jmp    0x476fa2
  476fa0:	33 c0                	xor    eax,eax
  476fa2:	50                   	push   eax
  476fa3:	8b cd                	mov    ecx,ebp
  476fa5:	c6 44 24 20 08       	mov    BYTE PTR [esp+0x20],0x8
  476faa:	e8 01 a5 f8 ff       	call   0x4014b0
  476faf:	8b ce                	mov    ecx,esi
  476fb1:	e8 2a 77 00 00       	call   0x47e6e0
  476fb6:	8b ce                	mov    ecx,esi
  476fb8:	e8 13 96 00 00       	call   0x4805d0
  476fbd:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  476fc1:	8b c6                	mov    eax,esi
  476fc3:	5f                   	pop    edi
  476fc4:	5e                   	pop    esi
  476fc5:	5d                   	pop    ebp
  476fc6:	5b                   	pop    ebx
  476fc7:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  476fce:	83 c4 10             	add    esp,0x10
  476fd1:	c2                   	.byte 0xc2
  476fd2:	0c                   	.byte 0xc
```

## `BranchStats_UpdateRatingPage` — `0x491d40`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x491d40.c`
- Callers: `BuildingInfoMenu_Init` (0x491ea0)
- Callees: `Branch_GetCustomerGroupRating` (0x47a3b0), `Building_ComputeOperatingRevenue` (0x4d6260), `Chart_DrawGroupMatrix` (0x491c80), `Chart_DrawRatingMatrix` (0x4919f0), `Gadget_SetText` (0x52f830), `Gadget_SetTextf` (0x52f080), `Game_GetCurrentPlayerCompanyName` (0x482820), `IDMap_Lookup` (0x4017f0), `Rating_UpdateBarByKey` (0x4a80e0), `UI_RemoveObjectByKey` (0x531740), `UI_ShowChildByID` (0x5316b0), `Window_GadgetNotify_Button_SetState` (0x52ff50)

- Unresolved questions: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

00491d40 <.text+0x90d40>:
  491d40:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  491d45:	53                   	push   ebx
  491d46:	55                   	push   ebp
  491d47:	56                   	push   esi
  491d48:	8b 98 9c 00 00 00    	mov    ebx,DWORD PTR [eax+0x9c]
  491d4e:	8b 74 24 10          	mov    esi,DWORD PTR [esp+0x10]
  491d52:	57                   	push   edi
  491d53:	33 ed                	xor    ebp,ebp
  491d55:	bf 28 86 56 00       	mov    edi,0x568628
  491d5a:	8b 07                	mov    eax,DWORD PTR [edi]
  491d5c:	33 c9                	xor    ecx,ecx
  491d5e:	83 f8 01             	cmp    eax,0x1
  491d61:	8d 95 2c 04 00 00    	lea    edx,[ebp+0x42c]
  491d67:	0f 94 c1             	sete   cl
  491d6a:	51                   	push   ecx
  491d6b:	52                   	push   edx
  491d6c:	8b ce                	mov    ecx,esi
  491d6e:	e8 dd e1 09 00       	call   0x52ff50
  491d73:	83 c7 04             	add    edi,0x4
  491d76:	45                   	inc    ebp
  491d77:	81 ff 38 86 56 00    	cmp    edi,0x568638
  491d7d:	7c db                	jl     0x491d5a
  491d7f:	8a 83 f4 16 00 00    	mov    al,BYTE PTR [ebx+0x16f4]
  491d85:	68 4d 04 00 00       	push   0x44d
  491d8a:	84 c0                	test   al,al
  491d8c:	8b ce                	mov    ecx,esi
  491d8e:	74 55                	je     0x491de5
  491d90:	e8 ab f9 09 00       	call   0x531740
  491d95:	a1 24 26 58 00       	mov    eax,ds:0x582624
  491d9a:	8b ce                	mov    ecx,esi
  491d9c:	50                   	push   eax
  491d9d:	68 4f 04 00 00       	push   0x44f
  491da2:	e8 89 da 09 00       	call   0x52f830
  491da7:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  491dac:	8b 7b 38             	mov    edi,DWORD PTR [ebx+0x38]
  491daf:	8b ab f0 16 00 00    	mov    ebp,DWORD PTR [ebx+0x16f0]
  491db5:	6a 00                	push   0x0
  491db7:	8b 88 f4 02 00 00    	mov    ecx,DWORD PTR [eax+0x2f4]
  491dbd:	51                   	push   ecx
  491dbe:	8d 48 04             	lea    ecx,[eax+0x4]
  491dc1:	e8 2a fa f6 ff       	call   0x4017f0
  491dc6:	57                   	push   edi
  491dc7:	55                   	push   ebp
  491dc8:	8b c8                	mov    ecx,eax
  491dca:	e8 91 44 04 00       	call   0x4d6260
  491dcf:	50                   	push   eax
  491dd0:	68 a4 83 56 00       	push   0x5683a4
  491dd5:	68 eb 04 00 00       	push   0x4eb
  491dda:	56                   	push   esi
  491ddb:	e8 a0 d2 09 00       	call   0x52f080
  491de0:	83 c4 10             	add    esp,0x10
  491de3:	eb 3d                	jmp    0x491e22
  491de5:	e8 c6 f8 09 00       	call   0x5316b0
  491dea:	68 eb 04 00 00       	push   0x4eb
  491def:	8b ce                	mov    ecx,esi
  491df1:	e8 ba f8 09 00       	call   0x5316b0
  491df6:	8b 93 b0 14 00 00    	mov    edx,DWORD PTR [ebx+0x14b0]
  491dfc:	52                   	push   edx
  491dfd:	68 a4 83 56 00       	push   0x5683a4
  491e02:	68 eb 04 00 00       	push   0x4eb
  491e07:	56                   	push   esi
  491e08:	e8 73 d2 09 00       	call   0x52f080
  491e0d:	a1 78 12 58 00       	mov    eax,ds:0x581278
  491e12:	83 c4 10             	add    esp,0x10
  491e15:	8b ce                	mov    ecx,esi
  491e17:	50                   	push   eax
  491e18:	68 4f 04 00 00       	push   0x44f
  491e1d:	e8 0e da 09 00       	call   0x52f830
  491e22:	8b 0d 98 21 58 00    	mov    ecx,DWORD PTR ds:0x582198
  491e28:	51                   	push   ecx
  491e29:	68 ec 04 00 00       	push   0x4ec
  491e2e:	8b ce                	mov    ecx,esi
  491e30:	e8 fb d9 09 00       	call   0x52f830
  491e35:	8b 15 b0 c6 57 00    	mov    edx,DWORD PTR ds:0x57c6b0
  491e3b:	68 28 86 56 00       	push   0x568628
  491e40:	53                   	push   ebx
  491e41:	52                   	push   edx
  491e42:	68 ed 04 00 00       	push   0x4ed
  491e47:	56                   	push   esi
  491e48:	e8 a3 fb ff ff       	call   0x4919f0
  491e4d:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  491e53:	83 c4 14             	add    esp,0x14
  491e56:	53                   	push   ebx
  491e57:	e8 c4 09 ff ff       	call   0x482820
  491e5c:	50                   	push   eax
  491e5d:	68 29 04 00 00       	push   0x429
  491e62:	56                   	push   esi
  491e63:	e8 18 fe ff ff       	call   0x491c80
  491e68:	83 c4 10             	add    esp,0x10
  491e6b:	33 ff                	xor    edi,edi
  491e6d:	6a 01                	push   0x1
  491e6f:	57                   	push   edi
  491e70:	8b cb                	mov    ecx,ebx
  491e72:	e8 39 85 fe ff       	call   0x47a3b0
  491e77:	8b 0d 98 29 58 00    	mov    ecx,DWORD PTR ds:0x582998
  491e7d:	51                   	push   ecx
  491e7e:	50                   	push   eax
  491e7f:	57                   	push   edi
  491e80:	68 e2 04 00 00       	push   0x4e2
  491e85:	56                   	push   esi
  491e86:	e8 55 62 01 00       	call   0x4a80e0
  491e8b:	83 c4 14             	add    esp,0x14
  491e8e:	47                   	inc    edi
  491e8f:	83 ff 08             	cmp    edi,0x8
  491e92:	7c d9                	jl     0x491e6d
  491e94:	5f                   	pop    edi
  491e95:	5e                   	pop    esi
  491e96:	5d                   	pop    ebp
  491e97:	5b                   	pop    ebx
```

