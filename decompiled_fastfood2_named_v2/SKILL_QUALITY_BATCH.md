# Function batch packet

## `Game_ComputeSkillRatings` — `0x513760`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x513760.c`
- Callers: `Game_GetSkillRating` (0x5139e0)
- Callees: `IDMap_Lookup` (0x4017f0), `Rating_GetFloat` (0x489070)

- Unresolved placeholders: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

00513760 <.text+0x112760>:
  513760:	83 ec 20             	sub    esp,0x20
  513763:	53                   	push   ebx
  513764:	55                   	push   ebp
  513765:	8b 6c 24 2c          	mov    ebp,DWORD PTR [esp+0x2c]
  513769:	8b d9                	mov    ebx,ecx
  51376b:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  513771:	56                   	push   esi
  513772:	8b 45 34             	mov    eax,DWORD PTR [ebp+0x34]
  513775:	57                   	push   edi
  513776:	6a 00                	push   0x0
  513778:	50                   	push   eax
  513779:	83 c1 04             	add    ecx,0x4
  51377c:	e8 6f e0 ee ff       	call   0x4017f0
  513781:	8b f0                	mov    esi,eax
  513783:	8d bb e4 02 00 00    	lea    edi,[ebx+0x2e4]
  513789:	b9 08 00 00 00       	mov    ecx,0x8
  51378e:	33 c0                	xor    eax,eax
  513790:	f3 ab                	rep stos DWORD PTR es:[edi],eax
  513792:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  513798:	50                   	push   eax
  513799:	56                   	push   esi
  51379a:	e8 d1 58 f7 ff       	call   0x489070
  51379f:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  5137a3:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  5137a9:	6a 01                	push   0x1
  5137ab:	56                   	push   esi
  5137ac:	e8 bf 58 f7 ff       	call   0x489070
  5137b1:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  5137b5:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  5137bb:	6a 02                	push   0x2
  5137bd:	56                   	push   esi
  5137be:	e8 ad 58 f7 ff       	call   0x489070
  5137c3:	d9 5c 24 18          	fstp   DWORD PTR [esp+0x18]
  5137c7:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  5137cd:	6a 03                	push   0x3
  5137cf:	56                   	push   esi
  5137d0:	e8 9b 58 f7 ff       	call   0x489070
  5137d5:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  5137d9:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  5137df:	6a 04                	push   0x4
  5137e1:	56                   	push   esi
  5137e2:	e8 89 58 f7 ff       	call   0x489070
  5137e7:	d9 5c 24 20          	fstp   DWORD PTR [esp+0x20]
  5137eb:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  5137f1:	6a 05                	push   0x5
  5137f3:	56                   	push   esi
  5137f4:	e8 77 58 f7 ff       	call   0x489070
  5137f9:	d9 5c 24 24          	fstp   DWORD PTR [esp+0x24]
  5137fd:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  513803:	6a 06                	push   0x6
  513805:	56                   	push   esi
  513806:	e8 65 58 f7 ff       	call   0x489070
  51380b:	d9 5c 24 28          	fstp   DWORD PTR [esp+0x28]
  51380f:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  513815:	6a 07                	push   0x7
  513817:	56                   	push   esi
  513818:	e8 53 58 f7 ff       	call   0x489070
  51381d:	d9 5c 24 2c          	fstp   DWORD PTR [esp+0x2c]
  513821:	d9 86 98 00 00 00    	fld    DWORD PTR [esi+0x98]
  513827:	8b 6d 38             	mov    ebp,DWORD PTR [ebp+0x38]
  51382a:	8d 44 24 10          	lea    eax,[esp+0x10]
  51382e:	b9 08 00 00 00       	mov    ecx,0x8
  513833:	8b d5                	mov    edx,ebp
  513835:	4a                   	dec    edx
  513836:	74 0d                	je     0x513845
  513838:	4a                   	dec    edx
  513839:	75 12                	jne    0x51384d
  51383b:	d9 c0                	fld    st(0)
  51383d:	d8 0d 6c c4 55 00    	fmul   DWORD PTR ds:0x55c46c
  513843:	eb 04                	jmp    0x513849
  513845:	d9 c0                	fld    st(0)
  513847:	dc c0                	fadd   st(0),st
  513849:	d8 00                	fadd   DWORD PTR [eax]
  51384b:	d9 18                	fstp   DWORD PTR [eax]
  51384d:	83 c0 04             	add    eax,0x4
  513850:	49                   	dec    ecx
  513851:	75 e0                	jne    0x513833
  513853:	dd d8                	fstp   st(0)
  513855:	33 f6                	xor    esi,esi
  513857:	bf 28 00 00 00       	mov    edi,0x28
  51385c:	bd 14 00 00 00       	mov    ebp,0x14
  513861:	d9 44 24 38          	fld    DWORD PTR [esp+0x38]
  513865:	d8 5c b4 10          	fcomp  DWORD PTR [esp+esi*4+0x10]
  513869:	df e0                	fnstsw ax
  51386b:	f6 c4 41             	test   ah,0x41
  51386e:	75 20                	jne    0x513890
  513870:	d9 44 24 38          	fld    DWORD PTR [esp+0x38]
  513874:	d8 74 b4 10          	fdiv   DWORD PTR [esp+esi*4+0x10]
  513878:	dc 25 68 c3 55 00    	fsub   QWORD PTR ds:0x55c368
  51387e:	dc 0d f8 c6 55 00    	fmul   QWORD PTR ds:0x55c6f8
  513884:	e8 b7 b8 03 00       	call   0x54f140
  513889:	89 84 b3 e4 02 00 00 	mov    DWORD PTR [ebx+esi*4+0x2e4],eax
  513890:	d9 44 24 38          	fld    DWORD PTR [esp+0x38]
  513894:	d8 5c b4 10          	fcomp  DWORD PTR [esp+esi*4+0x10]
  513898:	df e0                	fnstsw ax
  51389a:	f6 c4 01             	test   ah,0x1
  51389d:	0f 84 a9 00 00 00    	je     0x51394c
  5138a3:	d9 44 24 38          	fld    DWORD PTR [esp+0x38]
  5138a7:	d8 1d e4 c2 55 00    	fcomp  DWORD PTR ds:0x55c2e4
  5138ad:	df e0                	fnstsw ax
  5138af:	f6 c4 40             	test   ah,0x40
  5138b2:	75 22                	jne    0x5138d6
  5138b4:	d9 44 b4 10          	fld    DWORD PTR [esp+esi*4+0x10]
  5138b8:	d8 74 24 38          	fdiv   DWORD PTR [esp+0x38]
  5138bc:	dc 25 68 c3 55 00    	fsub   QWORD PTR ds:0x55c368
  5138c2:	dc 0d e0 c6 55 00    	fmul   QWORD PTR ds:0x55c6e0
  5138c8:	e8 73 b8 03 00       	call   0x54f140
  5138cd:	89 84 b3 e4 02 00 00 	mov    DWORD PTR [ebx+esi*4+0x2e4],eax
  5138d4:	eb 0b                	jmp    0x5138e1
  5138d6:	c7 84 b3 e4 02 00 00 	mov    DWORD PTR [ebx+esi*4+0x2e4],0x64
  5138dd:	64 00 00 00 
  5138e1:	83 fe 07             	cmp    esi,0x7
  5138e4:	77 66                	ja     0x51394c
  5138e6:	ff 24 b5 60 39 51 00 	jmp    DWORD PTR [esi*4+0x513960]
  5138ed:	39 bc b3 e4 02 00 00 	cmp    DWORD PTR [ebx+esi*4+0x2e4],edi
  5138f4:	7e 56                	jle    0x51394c
  5138f6:	89 bc b3 e4 02 00 00 	mov    DWORD PTR [ebx+esi*4+0x2e4],edi
  5138fd:	eb 4d                	jmp    0x51394c
  5138ff:	b8 0a 00 00 00       	mov    eax,0xa
  513904:	eb 17                	jmp    0x51391d
  513906:	39 ac b3 e4 02 00 00 	cmp    DWORD PTR [ebx+esi*4+0x2e4],ebp
  51390d:	7e 3d                	jle    0x51394c
  51390f:	eb 34                	jmp    0x513945
  513911:	b8 1e 00 00 00       	mov    eax,0x1e
  513916:	eb 05                	jmp    0x51391d
  513918:	b8 05 00 00 00       	mov    eax,0x5
  51391d:	39 84 b3 e4 02 00 00 	cmp    DWORD PTR [ebx+esi*4+0x2e4],eax
  513924:	7e 26                	jle    0x51394c
  513926:	89 84 b3 e4 02 00 00 	mov    DWORD PTR [ebx+esi*4+0x2e4],eax
  51392d:	eb 1d                	jmp    0x51394c
  51392f:	c7 84 b3 e4 02 00 00 	mov    DWORD PTR [ebx+esi*4+0x2e4],0x0
  513936:	00 00 00 00 
  51393a:	eb 10                	jmp    0x51394c
  51393c:	39 ac b3 e4 02 00 00 	cmp    DWORD PTR [ebx+esi*4+0x2e4],ebp
  513943:	7e 07                	jle    0x51394c
  513945:	89 ac b3 e4 02 00 00 	mov    DWORD PTR [ebx+esi*4+0x2e4],ebp
  51394c:	46                   	inc    esi
  51394d:	83 fe 08             	cmp    esi,0x8
  513950:	0f 8c 0b ff ff ff    	jl     0x513861
  513956:	5f                   	pop    edi
  513957:	5e                   	pop    esi
  513958:	5d                   	pop    ebp
  513959:	5b                   	pop    ebx
  51395a:	83 c4 20             	add    esp,0x20
  51395d:	c2                   	.byte 0xc2
  51395e:	08                   	.byte 0x8
```

## `Game_GetSkillRating` — `0x5139e0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x5139e0.c`
- Callers: `Branch_RecomputeMenuPriceRatings` (0x4784e0), `Game_ComputeObjectDetails` (0x5092b0), `Game_ComputeCompanyProductScore` (0x513b00)
- Callees: `Game_ComputeSkillRatings` (0x513760), `IDMap_Lookup` (0x4017f0)

- Unresolved placeholders: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

005139e0 <.text+0x1129e0>:
  5139e0:	51                   	push   ecx
  5139e1:	53                   	push   ebx
  5139e2:	56                   	push   esi
  5139e3:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  5139e7:	57                   	push   edi
  5139e8:	83 fe 08             	cmp    esi,0x8
  5139eb:	8b f9                	mov    edi,ecx
  5139ed:	c7 44 24 0c 00 00 00 	mov    DWORD PTR [esp+0xc],0x0
  5139f4:	00 
  5139f5:	75 05                	jne    0x5139fc
  5139f7:	be 05 00 00 00       	mov    esi,0x5
  5139fc:	8b 5c 24 14          	mov    ebx,DWORD PTR [esp+0x14]
  513a00:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  513a06:	6a 00                	push   0x0
  513a08:	83 c1 04             	add    ecx,0x4
  513a0b:	8b 43 34             	mov    eax,DWORD PTR [ebx+0x34]
  513a0e:	50                   	push   eax
  513a0f:	e8 dc dd ee ff       	call   0x4017f0
  513a14:	85 c0                	test   eax,eax
  513a16:	75 07                	jne    0x513a1f
  513a18:	5f                   	pop    edi
  513a19:	5e                   	pop    esi
  513a1a:	5b                   	pop    ebx
  513a1b:	59                   	pop    ecx
  513a1c:	c2 0c 00             	ret    0xc
  513a1f:	83 fe ff             	cmp    esi,0xffffffff
  513a22:	75 43                	jne    0x513a67
  513a24:	55                   	push   ebp
  513a25:	8d b7 c4 02 00 00    	lea    esi,[edi+0x2c4]
  513a2b:	bd 08 00 00 00       	mov    ebp,0x8
  513a30:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  513a34:	8b cf                	mov    ecx,edi
  513a36:	50                   	push   eax
  513a37:	53                   	push   ebx
  513a38:	e8 23 fd ff ff       	call   0x513760
  513a3d:	8b 4e 20             	mov    ecx,DWORD PTR [esi+0x20]
  513a40:	8b 06                	mov    eax,DWORD PTR [esi]
  513a42:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  513a46:	03 c8                	add    ecx,eax
  513a48:	03 d1                	add    edx,ecx
  513a4a:	83 c6 04             	add    esi,0x4
  513a4d:	4d                   	dec    ebp
  513a4e:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  513a52:	75 dc                	jne    0x513a30
  513a54:	8b c2                	mov    eax,edx
  513a56:	5d                   	pop    ebp
  513a57:	99                   	cdq
  513a58:	83 e2 07             	and    edx,0x7
  513a5b:	5f                   	pop    edi
  513a5c:	03 c2                	add    eax,edx
  513a5e:	5e                   	pop    esi
  513a5f:	c1 f8 03             	sar    eax,0x3
  513a62:	5b                   	pop    ebx
  513a63:	59                   	pop    ecx
  513a64:	c2 0c 00             	ret    0xc
  513a67:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  513a6b:	8b cf                	mov    ecx,edi
  513a6d:	52                   	push   edx
  513a6e:	53                   	push   ebx
  513a6f:	e8 ec fc ff ff       	call   0x513760
  513a74:	8b 84 b7 e4 02 00 00 	mov    eax,DWORD PTR [edi+esi*4+0x2e4]
  513a7b:	8b 8c b7 c4 02 00 00 	mov    ecx,DWORD PTR [edi+esi*4+0x2c4]
  513a82:	5f                   	pop    edi
  513a83:	5e                   	pop    esi
  513a84:	03 c1                	add    eax,ecx
  513a86:	5b                   	pop    ebx
  513a87:	59                   	pop    ecx
  513a88:	c2                   	.byte 0xc2
  513a89:	0c                   	.byte 0xc
```

## `Player_ComputeProductQualityScore` — `0x47d910`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x47d910.c`
- Callers: `Game_ComputeObjectDetails` (0x5092b0)
- Callees: `Game_ComputeAverageCategoryValue` (0x47ca80), `Game_GetAverageCompanyValueByByte8` (0x47cb70), `Game_GetAverageRecordValueByByte8` (0x47c9a0), `IDMap_Lookup` (0x4017f0), `Math_RoundFloat` (0x403850), `Rating_ClampAdjusted` (0x4d3f90)

- Unresolved placeholders: `extraout_EDX`

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

0047d910 <.text+0x7c910>:
  47d910:	83 ec 0c             	sub    esp,0xc
  47d913:	53                   	push   ebx
  47d914:	55                   	push   ebp
  47d915:	56                   	push   esi
  47d916:	57                   	push   edi
  47d917:	8b f9                	mov    edi,ecx
  47d919:	33 ed                	xor    ebp,ebp
  47d91b:	33 db                	xor    ebx,ebx
  47d91d:	33 f6                	xor    esi,esi
  47d91f:	8b 87 ac 19 00 00    	mov    eax,DWORD PTR [edi+0x19ac]
  47d925:	c7 44 24 10 64 00 00 	mov    DWORD PTR [esp+0x10],0x64
  47d92c:	00 
  47d92d:	85 c0                	test   eax,eax
  47d92f:	7e 55                	jle    0x47d986
  47d931:	6a 00                	push   0x0
  47d933:	56                   	push   esi
  47d934:	8d 8f 98 19 00 00    	lea    ecx,[edi+0x1998]
  47d93a:	e8 b1 3e f8 ff       	call   0x4017f0
  47d93f:	85 c0                	test   eax,eax
  47d941:	74 0d                	je     0x47d950
  47d943:	8b 48 1c             	mov    ecx,DWORD PTR [eax+0x1c]
  47d946:	85 c9                	test   ecx,ecx
  47d948:	74 06                	je     0x47d950
  47d94a:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  47d94d:	45                   	inc    ebp
  47d94e:	03 d9                	add    ebx,ecx
  47d950:	8b 87 ac 19 00 00    	mov    eax,DWORD PTR [edi+0x19ac]
  47d956:	46                   	inc    esi
  47d957:	3b f0                	cmp    esi,eax
  47d959:	7c d6                	jl     0x47d931
  47d95b:	85 ed                	test   ebp,ebp
  47d95d:	74 27                	je     0x47d986
  47d95f:	8b c3                	mov    eax,ebx
  47d961:	99                   	cdq
  47d962:	f7 fd                	idiv   ebp
  47d964:	85 c0                	test   eax,eax
  47d966:	7d 20                	jge    0x47d988
  47d968:	8b 74 24 24          	mov    esi,DWORD PTR [esp+0x24]
  47d96c:	8d 1c b5 00 00 00 00 	lea    ebx,[esi*4+0x0]
  47d973:	2b 83 38 79 56 00    	sub    eax,DWORD PTR [ebx+0x567938]
  47d979:	8d 04 85 64 00 00 00 	lea    eax,[eax*4+0x64]
  47d980:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  47d984:	eb 25                	jmp    0x47d9ab
  47d986:	33 c0                	xor    eax,eax
  47d988:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  47d98c:	8d 1c 8d 00 00 00 00 	lea    ebx,[ecx*4+0x0]
  47d993:	8b 8b 38 79 56 00    	mov    ecx,DWORD PTR [ebx+0x567938]
  47d999:	3b c1                	cmp    eax,ecx
  47d99b:	7d 0a                	jge    0x47d9a7
  47d99d:	2b c1                	sub    eax,ecx
  47d99f:	8d 54 00 64          	lea    edx,[eax+eax*1+0x64]
  47d9a3:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  47d9a7:	8b 74 24 24          	mov    esi,DWORD PTR [esp+0x24]
  47d9ab:	6a 05                	push   0x5
  47d9ad:	8b cf                	mov    ecx,edi
  47d9af:	e8 cc f0 ff ff       	call   0x47ca80
  47d9b4:	25 ff 00 00 00       	and    eax,0xff
  47d9b9:	89 87 70 18 00 00    	mov    DWORD PTR [edi+0x1870],eax
  47d9bf:	8b 8b 58 79 56 00    	mov    ecx,DWORD PTR [ebx+0x567958]
  47d9c5:	3b c1                	cmp    eax,ecx
  47d9c7:	7d 10                	jge    0x47d9d9
  47d9c9:	2b c1                	sub    eax,ecx
  47d9cb:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47d9cf:	8d 04 80             	lea    eax,[eax+eax*4]
  47d9d2:	8d 14 41             	lea    edx,[ecx+eax*2]
  47d9d5:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  47d9d9:	6a 05                	push   0x5
  47d9db:	8b cf                	mov    ecx,edi
  47d9dd:	e8 be ef ff ff       	call   0x47c9a0
  47d9e2:	25 ff 00 00 00       	and    eax,0xff
  47d9e7:	6a 05                	push   0x5
  47d9e9:	8b cf                	mov    ecx,edi
  47d9eb:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47d9ef:	e8 7c f1 ff ff       	call   0x47cb70
  47d9f4:	db 44 24 14          	fild   DWORD PTR [esp+0x14]
  47d9f8:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47d9fc:	51                   	push   ecx
  47d9fd:	d8 0d 30 c4 55 00    	fmul   DWORD PTR ds:0x55c430
  47da03:	da 4c 24 1c          	fimul  DWORD PTR [esp+0x1c]
  47da07:	d9 1c 24             	fstp   DWORD PTR [esp]
  47da0a:	e8 41 5e f8 ff       	call   0x403850
  47da0f:	83 c4 04             	add    esp,0x4
  47da12:	85 c0                	test   eax,eax
  47da14:	7c 14                	jl     0x47da2a
  47da16:	83 f8 05             	cmp    eax,0x5
  47da19:	7f 14                	jg     0x47da2f
  47da1b:	8d 0c 76             	lea    ecx,[esi+esi*2]
  47da1e:	8d 14 48             	lea    edx,[eax+ecx*2]
  47da21:	8b 04 95 78 79 56 00 	mov    eax,DWORD PTR [edx*4+0x567978]
  47da28:	eb 16                	jmp    0x47da40
  47da2a:	83 f8 05             	cmp    eax,0x5
  47da2d:	7e 0c                	jle    0x47da3b
  47da2f:	8d 04 76             	lea    eax,[esi+esi*2]
  47da32:	8b 04 c5 8c 79 56 00 	mov    eax,DWORD PTR [eax*8+0x56798c]
  47da39:	eb 05                	jmp    0x47da40
  47da3b:	b8 64 00 00 00       	mov    eax,0x64
  47da40:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47da44:	33 db                	xor    ebx,ebx
  47da46:	2b c8                	sub    ecx,eax
  47da48:	8b 87 14 15 00 00    	mov    eax,DWORD PTR [edi+0x1514]
  47da4e:	33 ed                	xor    ebp,ebp
  47da50:	33 f6                	xor    esi,esi
  47da52:	85 c0                	test   eax,eax
  47da54:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  47da58:	7e 6e                	jle    0x47dac8
  47da5a:	6a 00                	push   0x0
  47da5c:	56                   	push   esi
  47da5d:	8d 8f 00 15 00 00    	lea    ecx,[edi+0x1500]
  47da63:	e8 88 3d f8 ff       	call   0x4017f0
  47da68:	8b 08                	mov    ecx,DWORD PTR [eax]
  47da6a:	85 c9                	test   ecx,ecx
  47da6c:	74 12                	je     0x47da80
  47da6e:	8a 81 24 08 00 00    	mov    al,BYTE PTR [ecx+0x824]
  47da74:	84 c0                	test   al,al
  47da76:	75 08                	jne    0x47da80
  47da78:	43                   	inc    ebx
  47da79:	e8 12 65 05 00       	call   0x4d3f90
  47da7e:	03 e8                	add    ebp,eax
  47da80:	8b 87 14 15 00 00    	mov    eax,DWORD PTR [edi+0x1514]
  47da86:	46                   	inc    esi
  47da87:	3b f0                	cmp    esi,eax
  47da89:	7c cf                	jl     0x47da5a
  47da8b:	85 db                	test   ebx,ebx
  47da8d:	7e 39                	jle    0x47dac8
  47da8f:	8b c5                	mov    eax,ebp
  47da91:	99                   	cdq
  47da92:	f7 fb                	idiv   ebx
  47da94:	8b c8                	mov    ecx,eax
  47da96:	b8 ab aa aa 2a       	mov    eax,0x2aaaaaab
  47da9b:	f7 e9                	imul   ecx
  47da9d:	d1 fa                	sar    edx,1
  47da9f:	8b ca                	mov    ecx,edx
  47daa1:	c1 e9 1f             	shr    ecx,0x1f
  47daa4:	03 d1                	add    edx,ecx
  47daa6:	85 d2                	test   edx,edx
  47daa8:	7d 40                	jge    0x47daea
  47daaa:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  47daae:	5f                   	pop    edi
  47daaf:	5e                   	pop    esi
  47dab0:	5d                   	pop    ebp
  47dab1:	8d 14 c0             	lea    edx,[eax+eax*8]
  47dab4:	8b 44 24 04          	mov    eax,DWORD PTR [esp+0x4]
  47dab8:	5b                   	pop    ebx
  47dab9:	8b 0c 95 38 7a 56 00 	mov    ecx,DWORD PTR [edx*4+0x567a38]
  47dac0:	2b c1                	sub    eax,ecx
  47dac2:	83 c4 0c             	add    esp,0xc
  47dac5:	c2 08 00             	ret    0x8
  47dac8:	33 d2                	xor    edx,edx
  47daca:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  47dace:	5f                   	pop    edi
  47dacf:	5e                   	pop    esi
  47dad0:	5d                   	pop    ebp
  47dad1:	8d 0c c2             	lea    ecx,[edx+eax*8]
  47dad4:	5b                   	pop    ebx
  47dad5:	03 c1                	add    eax,ecx
  47dad7:	8b 0c 85 38 7a 56 00 	mov    ecx,DWORD PTR [eax*4+0x567a38]
  47dade:	8b 44 24 00          	mov    eax,DWORD PTR [esp+0x0]
  47dae2:	2b c1                	sub    eax,ecx
  47dae4:	83 c4 0c             	add    esp,0xc
  47dae7:	c2 08 00             	ret    0x8
  47daea:	83 fa 08             	cmp    edx,0x8
  47daed:	7e db                	jle    0x47daca
  47daef:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  47daf3:	5f                   	pop    edi
  47daf4:	5e                   	pop    esi
  47daf5:	5d                   	pop    ebp
  47daf6:	8d 04 c0             	lea    eax,[eax+eax*8]
  47daf9:	5b                   	pop    ebx
  47dafa:	8b 0c 85 58 7a 56 00 	mov    ecx,DWORD PTR [eax*4+0x567a58]
  47db01:	8b 44 24 00          	mov    eax,DWORD PTR [esp+0x0]
  47db05:	2b c1                	sub    eax,ecx
  47db07:	83 c4 0c             	add    esp,0xc
  47db0a:	c2                   	.byte 0xc2
  47db0b:	08                   	.byte 0x8
```

