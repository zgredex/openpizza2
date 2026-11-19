# Function batch packet

## `Branch_ComputeRecipePrice` — `0x513bf0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x513bf0.c`
- Callers: `Branch_RecomputeMenuPriceRatings` (0x4784e0), `CityBuildingListPage_Update` (0x4962e0), `CompareScreen_UpdateRows` (0x496680), `CompanyBranches_InitBranchRows` (0x4b98e0), `Action_AddBestRecipeToBranchMenu` (0x509580)
- Callees: `Branch_GetBuildingValue` (0x47fd90), `Get_Float44` (0x510570)

- Unresolved placeholders: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

00513bf0 <.text+0x112bf0>:
  513bf0:	8b 44 24 08          	mov    eax,DWORD PTR [esp+0x8]
  513bf4:	56                   	push   esi
  513bf5:	8b f1                	mov    esi,ecx
  513bf7:	3d 19 fc ff ff       	cmp    eax,0xfffffc19
  513bfc:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  513c00:	75 0a                	jne    0x513c0c
  513c02:	8b 81 a8 14 00 00    	mov    eax,DWORD PTR [ecx+0x14a8]
  513c08:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  513c0c:	8b 91 ac 14 00 00    	mov    edx,DWORD PTR [ecx+0x14ac]
  513c12:	89 54 24 08          	mov    DWORD PTR [esp+0x8],edx
  513c16:	e8 75 c1 f6 ff       	call   0x47fd90
  513c1b:	db 44 24 0c          	fild   DWORD PTR [esp+0xc]
  513c1f:	8b ce                	mov    ecx,esi
  513c21:	d8 0d 48 c3 55 00    	fmul   DWORD PTR ds:0x55c348
  513c27:	de c9                	fmulp  st(1),st
  513c29:	d9 5c 24 0c          	fstp   DWORD PTR [esp+0xc]
  513c2d:	e8 3e c9 ff ff       	call   0x510570
  513c32:	d8 4c 24 0c          	fmul   DWORD PTR [esp+0xc]
  513c36:	da 44 24 08          	fiadd  DWORD PTR [esp+0x8]
  513c3a:	5e                   	pop    esi
  513c3b:	c2                   	.byte 0xc2
  513c3c:	08                   	.byte 0x8
```

## `Game_ComputeObjectDetails` — `0x5092b0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x5092b0.c`
- Callers: `Action_AddBestRecipeToBranchMenu` (0x509580)
- Callees: `Game_GetPlayerBySlot` (0x488be0), `Game_GetPlayerSubmapValue` (0x489820), `Game_GetSkillRating` (0x5139e0), `IDMap_Lookup` (0x4017f0), `Market_ComputeValueAdjustment` (0x4d7640), `Market_GetPriceModifier` (0x4dbfc0), `Player_ComputeProductQualityScore` (0x47d910)

- Unresolved placeholders: `extraout_EDX`, `unaff_EDI`

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

005092b0 <.text+0x1082b0>:
  5092b0:	83 ec 1c             	sub    esp,0x1c
  5092b3:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  5092b7:	53                   	push   ebx
  5092b8:	55                   	push   ebp
  5092b9:	56                   	push   esi
  5092ba:	8b 58 2c             	mov    ebx,DWORD PTR [eax+0x2c]
  5092bd:	57                   	push   edi
  5092be:	8b 78 08             	mov    edi,DWORD PTR [eax+0x8]
  5092c1:	8b f1                	mov    esi,ecx
  5092c3:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  5092c9:	57                   	push   edi
  5092ca:	e8 11 f9 f7 ff       	call   0x488be0
  5092cf:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  5092d5:	53                   	push   ebx
  5092d6:	57                   	push   edi
  5092d7:	e8 44 05 f8 ff       	call   0x489820
  5092dc:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  5092e2:	8b d8                	mov    ebx,eax
  5092e4:	8b 46 28             	mov    eax,DWORD PTR [esi+0x28]
  5092e7:	33 ed                	xor    ebp,ebp
  5092e9:	55                   	push   ebp
  5092ea:	50                   	push   eax
  5092eb:	83 c1 04             	add    ecx,0x4
  5092ee:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  5092f2:	e8 f9 84 ef ff       	call   0x4017f0
  5092f7:	8b 4e 34             	mov    ecx,DWORD PTR [esi+0x34]
  5092fa:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  5092fe:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  509302:	51                   	push   ecx
  509303:	8b 38                	mov    edi,DWORD PTR [eax]
  509305:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  509308:	50                   	push   eax
  509309:	53                   	push   ebx
  50930a:	8b cf                	mov    ecx,edi
  50930c:	89 7c 24 2c          	mov    DWORD PTR [esp+0x2c],edi
  509310:	e8 cb a6 00 00       	call   0x5139e0
  509315:	8b 4c 24 3c          	mov    ecx,DWORD PTR [esp+0x3c]
  509319:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  50931d:	3b cd                	cmp    ecx,ebp
  50931f:	74 02                	je     0x509323
  509321:	89 01                	mov    DWORD PTR [ecx],eax
  509323:	8b 46 34             	mov    eax,DWORD PTR [esi+0x34]
  509326:	8b cb                	mov    ecx,ebx
  509328:	50                   	push   eax
  509329:	57                   	push   edi
  50932a:	e8 e1 45 f7 ff       	call   0x47d910
  50932f:	8b c8                	mov    ecx,eax
  509331:	8b 44 24 40          	mov    eax,DWORD PTR [esp+0x40]
  509335:	3b c5                	cmp    eax,ebp
  509337:	89 4c 24 24          	mov    DWORD PTR [esp+0x24],ecx
  50933b:	74 02                	je     0x50933f
  50933d:	89 08                	mov    DWORD PTR [eax],ecx
  50933f:	33 c9                	xor    ecx,ecx
  509341:	89 6c 24 3c          	mov    DWORD PTR [esp+0x3c],ebp
  509345:	89 4c 24 34          	mov    DWORD PTR [esp+0x34],ecx
  509349:	89 6c 24 30          	mov    DWORD PTR [esp+0x30],ebp
  50934d:	bb a8 00 00 00       	mov    ebx,0xa8
  509352:	8b 44 1f bc          	mov    eax,DWORD PTR [edi+ebx*1-0x44]
  509356:	85 c0                	test   eax,eax
  509358:	7e 7a                	jle    0x5093d4
  50935a:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  509360:	8d 54 24 1c          	lea    edx,[esp+0x1c]
  509364:	8d 44 24 18          	lea    eax,[esp+0x18]
  509368:	52                   	push   edx
  509369:	8b 3c 0b             	mov    edi,DWORD PTR [ebx+ecx*1]
  50936c:	8b 4e 34             	mov    ecx,DWORD PTR [esi+0x34]
  50936f:	50                   	push   eax
  509370:	57                   	push   edi
  509371:	51                   	push   ecx
  509372:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  509376:	6a 00                	push   0x0
  509378:	e8 c3 e2 fc ff       	call   0x4d7640
  50937d:	81 fb a8 00 00 00    	cmp    ebx,0xa8
  509383:	74 3b                	je     0x5093c0
  509385:	8a 97 a8 00 00 00    	mov    dl,BYTE PTR [edi+0xa8]
  50938b:	8b 46 34             	mov    eax,DWORD PTR [esi+0x34]
  50938e:	88 54 24 40          	mov    BYTE PTR [esp+0x40],dl
  509392:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  509396:	81 e1 ff 00 00 00    	and    ecx,0xff
  50939c:	51                   	push   ecx
  50939d:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  5093a1:	50                   	push   eax
  5093a2:	e8 19 2c fd ff       	call   0x4dbfc0
  5093a7:	8b 54 24 3c          	mov    edx,DWORD PTR [esp+0x3c]
  5093ab:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  5093af:	03 d0                	add    edx,eax
  5093b1:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  5093b5:	03 e9                	add    ebp,ecx
  5093b7:	40                   	inc    eax
  5093b8:	89 54 24 3c          	mov    DWORD PTR [esp+0x3c],edx
  5093bc:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  5093c0:	8b 54 24 1c          	mov    edx,DWORD PTR [esp+0x1c]
  5093c4:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  5093c8:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  5093cc:	03 c2                	add    eax,edx
  5093ce:	89 44 24 34          	mov    DWORD PTR [esp+0x34],eax
  5093d2:	8b c8                	mov    ecx,eax
  5093d4:	83 c3 04             	add    ebx,0x4
  5093d7:	81 fb 00 02 00 00    	cmp    ebx,0x200
  5093dd:	0f 8c 6f ff ff ff    	jl     0x509352
  5093e3:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  5093e7:	85 c0                	test   eax,eax
  5093e9:	7e 1a                	jle    0x509405
  5093eb:	8b 44 24 3c          	mov    eax,DWORD PTR [esp+0x3c]
  5093ef:	8b 74 24 30          	mov    esi,DWORD PTR [esp+0x30]
  5093f3:	99                   	cdq
  5093f4:	f7 fe                	idiv   esi
  5093f6:	8b f8                	mov    edi,eax
  5093f8:	8b c5                	mov    eax,ebp
  5093fa:	99                   	cdq
  5093fb:	f7 fe                	idiv   esi
  5093fd:	03 cf                	add    ecx,edi
  5093ff:	8b f0                	mov    esi,eax
  509401:	03 f1                	add    esi,ecx
  509403:	eb 05                	jmp    0x50940a
  509405:	be d8 ff ff ff       	mov    esi,0xffffffd8
  50940a:	8b 44 24 44          	mov    eax,DWORD PTR [esp+0x44]
  50940e:	85 c0                	test   eax,eax
  509410:	74 02                	je     0x509414
  509412:	89 30                	mov    DWORD PTR [eax],esi
  509414:	8b 44 24 38          	mov    eax,DWORD PTR [esp+0x38]
  509418:	85 c0                	test   eax,eax
  50941a:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  50941e:	74 0b                	je     0x50942b
  509420:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  509424:	03 c1                	add    eax,ecx
  509426:	99                   	cdq
  509427:	2b c2                	sub    eax,edx
  509429:	d1 f8                	sar    eax,1
  50942b:	03 c6                	add    eax,esi
  50942d:	5f                   	pop    edi
  50942e:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  509432:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  509436:	5e                   	pop    esi
  509437:	5d                   	pop    ebp
  509438:	8b 88 c4 14 00 00    	mov    ecx,DWORD PTR [eax+0x14c4]
  50943e:	5b                   	pop    ebx
  50943f:	85 c9                	test   ecx,ecx
  509441:	74 0c                	je     0x50944f
  509443:	8b 90 c0 14 00 00    	mov    edx,DWORD PTR [eax+0x14c0]
  509449:	89 54 24 20          	mov    DWORD PTR [esp+0x20],edx
  50944d:	eb 08                	jmp    0x509457
  50944f:	c7 44 24 20 00 00 00 	mov    DWORD PTR [esp+0x20],0x0
  509456:	00 
  509457:	db 44 24 20          	fild   DWORD PTR [esp+0x20]
  50945b:	d8 05 20 c3 55 00    	fadd   DWORD PTR ds:0x55c320
  509461:	da 4c 24 24          	fimul  DWORD PTR [esp+0x24]
  509465:	d8 0d 48 c3 55 00    	fmul   DWORD PTR ds:0x55c348
  50946b:	e8 d0 5c 04 00       	call   0x54f140
  509470:	83 f8 64             	cmp    eax,0x64
  509473:	7e 07                	jle    0x50947c
  509475:	b8 64 00 00 00       	mov    eax,0x64
  50947a:	eb 06                	jmp    0x509482
  50947c:	85 c0                	test   eax,eax
  50947e:	7d 02                	jge    0x509482
  509480:	33 c0                	xor    eax,eax
  509482:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  509486:	85 c9                	test   ecx,ecx
  509488:	74 02                	je     0x50948c
  50948a:	89 01                	mov    DWORD PTR [ecx],eax
  50948c:	83 c4 1c             	add    esp,0x1c
  50948f:	c2                   	.byte 0xc2
  509490:	1c                   	.byte 0x1c
```

## `Action_AddBestRecipeToBranchMenu` — `0x509580`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x509580.c`
- Callers: `Object_UpdateProductionWorker` (0x40a380)
- Callees: `Array_SearchSet` (0x4f5fa0), `Branch_ComputeAdvisorTipId` (0x509a20), `Branch_ComputeBuildingRating` (0x478be0), `Branch_ComputeRecipePrice` (0x513bf0), `Branch_GetMenuRating` (0x478320), `Branch_ProcessCustomerOrder` (0x47d4a0), `Game_AddRecordTo19C4` (0x47eba0), `Game_ComputeObjectDetails` (0x5092b0), `Game_CountActiveCompanies` (0x4ddde0), `Game_GetActiveCompanyById` (0x4dde30), `Game_GetCurrentPlayerCompanyName` (0x482820), `Game_GetPlayerBySlot` (0x488be0), `Game_GetPlayerSubmapValue` (0x489820), `Game_GetTimeSegment` (0x488d90), `IDMap_Lookup` (0x4017f0), `Index_Map8To5` (0x513980), `List_Node_Reset` (0x401440), `Mem_Free` (0x54dd78), `MissionGoal_HandleEvent` (0x502f10), `Object_SyncChildState` (0x5094a0), `Random_RangeFast` (0x4034d0), `Rating_ComputeBuildingScore` (0x47a000), `Stats_GetAverage8` (0x4787f0), `Stats_Increment2D` (0x47db10), `UI_AppendCommandIfActive` (0x503250)

- Unresolved placeholders: `extraout_EDX`

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

00509580 <.text+0x108580>:
  509580:	8b 44 24 04          	mov    eax,DWORD PTR [esp+0x4]
  509584:	81 ec 30 03 00 00    	sub    esp,0x330
  50958a:	85 c0                	test   eax,eax
  50958c:	53                   	push   ebx
  50958d:	55                   	push   ebp
  50958e:	56                   	push   esi
  50958f:	57                   	push   edi
  509590:	8b f1                	mov    esi,ecx
  509592:	75 0d                	jne    0x5095a1
  509594:	8b 86 f4 00 00 00    	mov    eax,DWORD PTR [esi+0xf4]
  50959a:	89 84 24 44 03 00 00 	mov    DWORD PTR [esp+0x344],eax
  5095a1:	8b 78 08             	mov    edi,DWORD PTR [eax+0x8]
  5095a4:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  5095aa:	8b 58 2c             	mov    ebx,DWORD PTR [eax+0x2c]
  5095ad:	57                   	push   edi
  5095ae:	e8 2d f6 f7 ff       	call   0x488be0
  5095b3:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  5095b9:	8b e8                	mov    ebp,eax
  5095bb:	53                   	push   ebx
  5095bc:	57                   	push   edi
  5095bd:	89 6c 24 18          	mov    DWORD PTR [esp+0x18],ebp
  5095c1:	e8 5a 02 f8 ff       	call   0x489820
  5095c6:	33 db                	xor    ebx,ebx
  5095c8:	8b cd                	mov    ecx,ebp
  5095ca:	8b f8                	mov    edi,eax
  5095cc:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  5095d0:	e8 0b 48 fd ff       	call   0x4ddde0
  5095d5:	85 c0                	test   eax,eax
  5095d7:	0f 8c 92 00 00 00    	jl     0x50966f
  5095dd:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  5095e1:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  5095e5:	eb 04                	jmp    0x5095eb
  5095e7:	8b 6c 24 10          	mov    ebp,DWORD PTR [esp+0x10]
  5095eb:	8b cd                	mov    ecx,ebp
  5095ed:	e8 ee 47 fd ff       	call   0x4ddde0
  5095f2:	3b d8                	cmp    ebx,eax
  5095f4:	75 0c                	jne    0x509602
  5095f6:	8b af dc 14 00 00    	mov    ebp,DWORD PTR [edi+0x14dc]
  5095fc:	85 ed                	test   ebp,ebp
  5095fe:	74 6f                	je     0x50966f
  509600:	eb 0a                	jmp    0x50960c
  509602:	53                   	push   ebx
  509603:	8b cd                	mov    ecx,ebp
  509605:	e8 26 48 fd ff       	call   0x4dde30
  50960a:	8b e8                	mov    ebp,eax
  50960c:	6a 30                	push   0x30
  50960e:	e8 0e 4c 04 00       	call   0x54e221
  509613:	83 c4 04             	add    esp,0x4
  509616:	8b d8                	mov    ebx,eax
  509618:	8b cd                	mov    ecx,ebp
  50961a:	68 19 fc ff ff       	push   0xfffffc19
  50961f:	57                   	push   edi
  509620:	89 2b                	mov    DWORD PTR [ebx],ebp
  509622:	e8 c9 a5 00 00       	call   0x513bf0
  509627:	8b 6c 24 1c          	mov    ebp,DWORD PTR [esp+0x1c]
  50962b:	8b 94 24 44 03 00 00 	mov    edx,DWORD PTR [esp+0x344]
  509632:	d9 5b 04             	fstp   DWORD PTR [ebx+0x4]
  509635:	6a 00                	push   0x0
  509637:	6a 00                	push   0x0
  509639:	6a 00                	push   0x0
  50963b:	6a 00                	push   0x0
  50963d:	6a 00                	push   0x0
  50963f:	53                   	push   ebx
  509640:	52                   	push   edx
  509641:	8b ce                	mov    ecx,esi
  509643:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  509646:	e8 65 fc ff ff       	call   0x5092b0
  50964b:	8b 5c 24 18          	mov    ebx,DWORD PTR [esp+0x18]
  50964f:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  509653:	89 45 00             	mov    DWORD PTR [ebp+0x0],eax
  509656:	43                   	inc    ebx
  509657:	83 c5 08             	add    ebp,0x8
  50965a:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  50965e:	89 6c 24 1c          	mov    DWORD PTR [esp+0x1c],ebp
  509662:	e8 79 47 fd ff       	call   0x4ddde0
  509667:	3b d8                	cmp    ebx,eax
  509669:	0f 8e 78 ff ff ff    	jle    0x5095e7
  50966f:	8d 6b ff             	lea    ebp,[ebx-0x1]
  509672:	85 ed                	test   ebp,ebp
  509674:	7e 3f                	jle    0x5096b5
  509676:	8d 44 24 20          	lea    eax,[esp+0x20]
  50967a:	89 6c 24 10          	mov    DWORD PTR [esp+0x10],ebp
  50967e:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  509681:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  509684:	3b ca                	cmp    ecx,edx
  509686:	7d 1a                	jge    0x5096a2
  509688:	8b 58 08             	mov    ebx,DWORD PTR [eax+0x8]
  50968b:	8b 08                	mov    ecx,DWORD PTR [eax]
  50968d:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  509690:	89 18                	mov    DWORD PTR [eax],ebx
  509692:	8b 58 0c             	mov    ebx,DWORD PTR [eax+0xc]
  509695:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  509698:	8b 5c 24 18          	mov    ebx,DWORD PTR [esp+0x18]
  50969c:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  50969f:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  5096a2:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  5096a6:	83 c0 08             	add    eax,0x8
  5096a9:	49                   	dec    ecx
  5096aa:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  5096ae:	75 ce                	jne    0x50967e
  5096b0:	4d                   	dec    ebp
  5096b1:	85 ed                	test   ebp,ebp
  5096b3:	7f c1                	jg     0x509676
  5096b5:	83 c8 ff             	or     eax,0xffffffff
  5096b8:	83 fb 03             	cmp    ebx,0x3
  5096bb:	7e 33                	jle    0x5096f0
  5096bd:	6a 64                	push   0x64
  5096bf:	6a 01                	push   0x1
  5096c1:	e8 0a 9e ef ff       	call   0x4034d0
  5096c6:	83 c4 08             	add    esp,0x8
  5096c9:	83 f8 32             	cmp    eax,0x32
  5096cc:	7e 04                	jle    0x5096d2
  5096ce:	33 c0                	xor    eax,eax
  5096d0:	eb 30                	jmp    0x509702
  5096d2:	83 f8 14             	cmp    eax,0x14
  5096d5:	7e 07                	jle    0x5096de
  5096d7:	b8 01 00 00 00       	mov    eax,0x1
  5096dc:	eb 24                	jmp    0x509702
  5096de:	83 f8 05             	cmp    eax,0x5
  5096e1:	7e 07                	jle    0x5096ea
  5096e3:	b8 02 00 00 00       	mov    eax,0x2
  5096e8:	eb 18                	jmp    0x509702
  5096ea:	8d 53 ff             	lea    edx,[ebx-0x1]
  5096ed:	52                   	push   edx
  5096ee:	eb 08                	jmp    0x5096f8
  5096f0:	85 db                	test   ebx,ebx
  5096f2:	7e 0e                	jle    0x509702
  5096f4:	8d 43 ff             	lea    eax,[ebx-0x1]
  5096f7:	50                   	push   eax
  5096f8:	6a 00                	push   0x0
  5096fa:	e8 d1 9d ef ff       	call   0x4034d0
  5096ff:	83 c4 08             	add    esp,0x8
  509702:	33 ed                	xor    ebp,ebp
  509704:	83 f8 ff             	cmp    eax,0xffffffff
  509707:	89 6c 24 1c          	mov    DWORD PTR [esp+0x1c],ebp
  50970b:	74 38                	je     0x509745
  50970d:	8b 6c c4 20          	mov    ebp,DWORD PTR [esp+eax*8+0x20]
  509711:	8b 4c c4 24          	mov    ecx,DWORD PTR [esp+eax*8+0x24]
  509715:	6a 01                	push   0x1
  509717:	55                   	push   ebp
  509718:	89 4d 0c             	mov    DWORD PTR [ebp+0xc],ecx
  50971b:	8b 56 34             	mov    edx,DWORD PTR [esi+0x34]
  50971e:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  509721:	8b 86 64 01 00 00    	mov    eax,DWORD PTR [esi+0x164]
  509727:	8b cf                	mov    ecx,edi
  509729:	89 45 10             	mov    DWORD PTR [ebp+0x10],eax
  50972c:	e8 6f 3d f7 ff       	call   0x47d4a0
  509731:	85 c0                	test   eax,eax
  509733:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  509737:	75 18                	jne    0x509751
  509739:	66 ff 87 d4 16 00 00 	inc    WORD PTR [edi+0x16d4]
  509740:	e9 a0 02 00 00       	jmp    0x5099e5
  509745:	66 ff 87 da 16 00 00 	inc    WORD PTR [edi+0x16da]
  50974c:	e9 94 02 00 00       	jmp    0x5099e5
  509751:	8b 4e 34             	mov    ecx,DWORD PTR [esi+0x34]
  509754:	51                   	push   ecx
  509755:	8b 4d 00             	mov    ecx,DWORD PTR [ebp+0x0]
  509758:	e8 23 a2 00 00       	call   0x513980
  50975d:	8b 56 24             	mov    edx,DWORD PTR [esi+0x24]
  509760:	8b 46 34             	mov    eax,DWORD PTR [esi+0x34]
  509763:	83 e2 01             	and    edx,0x1
  509766:	8b cf                	mov    ecx,edi
  509768:	52                   	push   edx
  509769:	50                   	push   eax
  50976a:	e8 a1 43 f7 ff       	call   0x47db10
  50976f:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  509775:	8b 5e 34             	mov    ebx,DWORD PTR [esi+0x34]
  509778:	e8 13 f6 f7 ff       	call   0x488d90
  50977d:	8d 0c d8             	lea    ecx,[eax+ebx*8]
  509780:	03 d9                	add    ebx,ecx
  509782:	8b 44 9f 44          	mov    eax,DWORD PTR [edi+ebx*4+0x44]
  509786:	8d 5c 9f 44          	lea    ebx,[edi+ebx*4+0x44]
  50978a:	40                   	inc    eax
  50978b:	89 03                	mov    DWORD PTR [ebx],eax
  50978d:	8b 8e 44 01 00 00    	mov    ecx,DWORD PTR [esi+0x144]
  509793:	33 c0                	xor    eax,eax
  509795:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  509799:	85 c9                	test   ecx,ecx
  50979b:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  50979f:	0f 8e d0 00 00 00    	jle    0x509875
  5097a5:	6a 00                	push   0x0
  5097a7:	50                   	push   eax
  5097a8:	8d 8e 30 01 00 00    	lea    ecx,[esi+0x130]
  5097ae:	e8 3d 80 ef ff       	call   0x4017f0
  5097b3:	83 78 04 0f          	cmp    DWORD PTR [eax+0x4],0xf
  5097b7:	0f 85 a3 00 00 00    	jne    0x509860
  5097bd:	8b 58 2c             	mov    ebx,DWORD PTR [eax+0x2c]
  5097c0:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5097c3:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  5097c9:	50                   	push   eax
  5097ca:	e8 11 f4 f7 ff       	call   0x488be0
  5097cf:	6a 00                	push   0x0
  5097d1:	53                   	push   ebx
  5097d2:	8d 88 48 01 00 00    	lea    ecx,[eax+0x148]
  5097d8:	e8 13 80 ef ff       	call   0x4017f0
  5097dd:	85 c0                	test   eax,eax
  5097df:	74 7f                	je     0x509860
  5097e1:	3b c7                	cmp    eax,edi
  5097e3:	74 7b                	je     0x509860
  5097e5:	8b 57 30             	mov    edx,DWORD PTR [edi+0x30]
  5097e8:	8b 48 30             	mov    ecx,DWORD PTR [eax+0x30]
  5097eb:	3b ca                	cmp    ecx,edx
  5097ed:	74 71                	je     0x509860
  5097ef:	8b 4e 34             	mov    ecx,DWORD PTR [esi+0x34]
  5097f2:	8d 8c 49 1b 03 00 00 	lea    ecx,[ecx+ecx*2+0x31b]
  5097f9:	8d 14 4a             	lea    edx,[edx+ecx*2]
  5097fc:	8b 1c 90             	mov    ebx,DWORD PTR [eax+edx*4]
  5097ff:	8d 0c 90             	lea    ecx,[eax+edx*4]
  509802:	43                   	inc    ebx
  509803:	89 19                	mov    DWORD PTR [ecx],ebx
  509805:	8b 4e 34             	mov    ecx,DWORD PTR [esi+0x34]
  509808:	8b 94 88 64 13 00 00 	mov    edx,DWORD PTR [eax+ecx*4+0x1364]
  50980f:	42                   	inc    edx
  509810:	89 94 88 64 13 00 00 	mov    DWORD PTR [eax+ecx*4+0x1364],edx
  509817:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  50981d:	8b 5f 30             	mov    ebx,DWORD PTR [edi+0x30]
  509820:	e8 fb 8f f7 ff       	call   0x482820
  509825:	3b d8                	cmp    ebx,eax
  509827:	75 37                	jne    0x509860
  509829:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  50982e:	6a 01                	push   0x1
  509830:	6a 22                	push   0x22
  509832:	8b 88 24 02 00 00    	mov    ecx,DWORD PTR [eax+0x224]
  509838:	8b 89 a8 00 00 00    	mov    ecx,DWORD PTR [ecx+0xa8]
  50983e:	e8 0d 9a ff ff       	call   0x503250
  509843:	8b 15 70 c6 57 00    	mov    edx,DWORD PTR ds:0x57c670
  509849:	6a ff                	push   0xffffffff
  50984b:	6a ff                	push   0xffffffff
  50984d:	6a 22                	push   0x22
  50984f:	8b 82 24 02 00 00    	mov    eax,DWORD PTR [edx+0x224]
  509855:	8b 88 a8 00 00 00    	mov    ecx,DWORD PTR [eax+0xa8]
  50985b:	e8 b0 96 ff ff       	call   0x502f10
  509860:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  509864:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  509868:	40                   	inc    eax
  509869:	3b c1                	cmp    eax,ecx
  50986b:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  50986f:	0f 8c 30 ff ff ff    	jl     0x5097a5
  509875:	8d 8e 30 01 00 00    	lea    ecx,[esi+0x130]
  50987b:	e8 c0 7b ef ff       	call   0x401440
  509880:	8b 8c 24 44 03 00 00 	mov    ecx,DWORD PTR [esp+0x344]
  509887:	6a 00                	push   0x0
  509889:	6a 00                	push   0x0
  50988b:	6a 00                	push   0x0
  50988d:	6a 00                	push   0x0
  50988f:	6a 01                	push   0x1
  509891:	55                   	push   ebp
  509892:	51                   	push   ecx
  509893:	8b ce                	mov    ecx,esi
  509895:	e8 16 fa ff ff       	call   0x5092b0
  50989a:	89 45 0c             	mov    DWORD PTR [ebp+0xc],eax
  50989d:	8b 46 34             	mov    eax,DWORD PTR [esi+0x34]
  5098a0:	50                   	push   eax
  5098a1:	8b cf                	mov    ecx,edi
  5098a3:	e8 38 f3 f6 ff       	call   0x478be0
  5098a8:	8b d8                	mov    ebx,eax
  5098aa:	8b 46 34             	mov    eax,DWORD PTR [esi+0x34]
  5098ad:	50                   	push   eax
  5098ae:	8b cf                	mov    ecx,edi
  5098b0:	e8 3b ef f6 ff       	call   0x4787f0
  5098b5:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  5098b9:	8b 46 34             	mov    eax,DWORD PTR [esi+0x34]
  5098bc:	50                   	push   eax
  5098bd:	8b cf                	mov    ecx,edi
  5098bf:	e8 5c ea f6 ff       	call   0x478320
  5098c4:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5098c8:	8b 46 34             	mov    eax,DWORD PTR [esi+0x34]
  5098cb:	50                   	push   eax
  5098cc:	8b cf                	mov    ecx,edi
  5098ce:	e8 2d 07 f7 ff       	call   0x47a000
  5098d3:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  5098d7:	8b c8                	mov    ecx,eax
  5098d9:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  5098dd:	03 c2                	add    eax,edx
  5098df:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  5098e2:	03 c3                	add    eax,ebx
  5098e4:	03 c2                	add    eax,edx
  5098e6:	99                   	cdq
  5098e7:	83 e2 03             	and    edx,0x3
  5098ea:	03 c2                	add    eax,edx
  5098ec:	8b d8                	mov    ebx,eax
  5098ee:	c1 fb 02             	sar    ebx,0x2
  5098f1:	03 d9                	add    ebx,ecx
  5098f3:	8b 4f 30             	mov    ecx,DWORD PTR [edi+0x30]
  5098f6:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  5098fa:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  509900:	e8 1b 8f f7 ff       	call   0x482820
  509905:	39 44 24 14          	cmp    DWORD PTR [esp+0x14],eax
  509909:	75 24                	jne    0x50992f
  50990b:	83 fb 50             	cmp    ebx,0x50
  50990e:	7c 1f                	jl     0x50992f
  509910:	83 7e 30 07          	cmp    DWORD PTR [esi+0x30],0x7
  509914:	75 19                	jne    0x50992f
  509916:	8b 15 70 c6 57 00    	mov    edx,DWORD PTR ds:0x57c670
  50991c:	6a 06                	push   0x6
  50991e:	8b 82 24 02 00 00    	mov    eax,DWORD PTR [edx+0x224]
  509924:	8b 88 ac 00 00 00    	mov    ecx,DWORD PTR [eax+0xac]
  50992a:	e8 71 c6 fe ff       	call   0x4f5fa0
  50992f:	8b 46 30             	mov    eax,DWORD PTR [esi+0x30]
  509932:	83 f8 0b             	cmp    eax,0xb
  509935:	74 7a                	je     0x5099b1
  509937:	83 f8 0f             	cmp    eax,0xf
  50993a:	74 75                	je     0x5099b1
  50993c:	83 f8 21             	cmp    eax,0x21
  50993f:	74 70                	je     0x5099b1
  509941:	8b 47 30             	mov    eax,DWORD PTR [edi+0x30]
  509944:	8b 94 86 4c 01 00 00 	mov    edx,DWORD PTR [esi+eax*4+0x14c]
  50994b:	42                   	inc    edx
  50994c:	89 94 86 4c 01 00 00 	mov    DWORD PTR [esi+eax*4+0x14c],edx
  509953:	8b 4f 30             	mov    ecx,DWORD PTR [edi+0x30]
  509956:	89 9c 8e ac 00 00 00 	mov    DWORD PTR [esi+ecx*4+0xac],ebx
  50995d:	8b 57 30             	mov    edx,DWORD PTR [edi+0x30]
  509960:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  509966:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  50996a:	e8 b1 8e f7 ff       	call   0x482820
  50996f:	39 44 24 14          	cmp    DWORD PTR [esp+0x14],eax
  509973:	75 3c                	jne    0x5099b1
  509975:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  50997b:	8b 86 64 01 00 00    	mov    eax,DWORD PTR [esi+0x164]
  509981:	50                   	push   eax
  509982:	6a 16                	push   0x16
  509984:	8b 91 24 02 00 00    	mov    edx,DWORD PTR [ecx+0x224]
  50998a:	8b 8a a8 00 00 00    	mov    ecx,DWORD PTR [edx+0xa8]
  509990:	e8 bb 98 ff ff       	call   0x503250
  509995:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  50999a:	6a ff                	push   0xffffffff
  50999c:	6a ff                	push   0xffffffff
  50999e:	6a 16                	push   0x16
  5099a0:	8b 88 24 02 00 00    	mov    ecx,DWORD PTR [eax+0x224]
  5099a6:	8b 89 a8 00 00 00    	mov    ecx,DWORD PTR [ecx+0xa8]
  5099ac:	e8 5f 95 ff ff       	call   0x502f10
  5099b1:	53                   	push   ebx
  5099b2:	57                   	push   edi
  5099b3:	8b ce                	mov    ecx,esi
  5099b5:	e8 e6 fa ff ff       	call   0x5094a0
  5099ba:	8b 56 34             	mov    edx,DWORD PTR [esi+0x34]
  5099bd:	8b cf                	mov    ecx,edi
  5099bf:	52                   	push   edx
  5099c0:	e8 1b f2 f6 ff       	call   0x478be0
  5099c5:	8b 45 00             	mov    eax,DWORD PTR [ebp+0x0]
  5099c8:	53                   	push   ebx
  5099c9:	50                   	push   eax
  5099ca:	57                   	push   edi
  5099cb:	8b ce                	mov    ecx,esi
  5099cd:	e8 4e 00 00 00       	call   0x509a20
  5099d2:	55                   	push   ebp
  5099d3:	8b cf                	mov    ecx,edi
  5099d5:	c7 45 00 00 00 00 00 	mov    DWORD PTR [ebp+0x0],0x0
  5099dc:	e8 bf 51 f7 ff       	call   0x47eba0
  5099e1:	8b 5c 24 18          	mov    ebx,DWORD PTR [esp+0x18]
  5099e5:	85 db                	test   ebx,ebx
  5099e7:	7e 1d                	jle    0x509a06
  5099e9:	8d 74 24 20          	lea    esi,[esp+0x20]
  5099ed:	8b 06                	mov    eax,DWORD PTR [esi]
  5099ef:	85 c0                	test   eax,eax
  5099f1:	74 0d                	je     0x509a00
  5099f3:	3b c5                	cmp    eax,ebp
  5099f5:	74 09                	je     0x509a00
  5099f7:	50                   	push   eax
  5099f8:	e8 7b 43 04 00       	call   0x54dd78
  5099fd:	83 c4 04             	add    esp,0x4
  509a00:	83 c6 08             	add    esi,0x8
  509a03:	4b                   	dec    ebx
  509a04:	75 e7                	jne    0x5099ed
  509a06:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  509a0a:	5f                   	pop    edi
  509a0b:	5e                   	pop    esi
  509a0c:	5d                   	pop    ebp
  509a0d:	5b                   	pop    ebx
  509a0e:	81 c4 30 03 00 00    	add    esp,0x330
  509a14:	c2                   	.byte 0xc2
  509a15:	04                   	.byte 0x4
```

## `Branch_ProcessCustomerOrder` — `0x47d4a0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x47d4a0.c`
- Callers: `Action_AddBestRecipeToBranchMenu` (0x509580)
- Callees: `Branch_GetCustomerGroupRating` (0x47a3b0), `Branch_UpdateConstructionQueue` (0x47ea30), `DebugConsole_Printf` (0x54a660), `Game_CanAfford` (0x477e40), `Game_GetMarketBonusFactor` (0x47ab20), `IDMap_Lookup` (0x4017f0), `Recipe_AppendSalesRecord` (0x50ff80), `Stats_AddRecordValue` (0x477c80)

- Unresolved placeholders: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

0047d4a0 <.text+0x7c4a0>:
  47d4a0:	55                   	push   ebp
  47d4a1:	8b ec                	mov    ebp,esp
  47d4a3:	83 e4 f8             	and    esp,0xfffffff8
  47d4a6:	81 ec a4 01 00 00    	sub    esp,0x1a4
  47d4ac:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47d4af:	53                   	push   ebx
  47d4b0:	56                   	push   esi
  47d4b1:	33 f6                	xor    esi,esi
  47d4b3:	3b c6                	cmp    eax,esi
  47d4b5:	57                   	push   edi
  47d4b6:	89 4c 24 24          	mov    DWORD PTR [esp+0x24],ecx
  47d4ba:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  47d4be:	75 0b                	jne    0x47d4cb
  47d4c0:	33 c0                	xor    eax,eax
  47d4c2:	5f                   	pop    edi
  47d4c3:	5e                   	pop    esi
  47d4c4:	5b                   	pop    ebx
  47d4c5:	8b e5                	mov    esp,ebp
  47d4c7:	5d                   	pop    ebp
  47d4c8:	c2 08 00             	ret    0x8
  47d4cb:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  47d4ce:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  47d4d4:	56                   	push   esi
  47d4d5:	50                   	push   eax
  47d4d6:	83 c1 3c             	add    ecx,0x3c
  47d4d9:	e8 12 43 f8 ff       	call   0x4017f0
  47d4de:	8b 48 30             	mov    ecx,DWORD PTR [eax+0x30]
  47d4e1:	bb 64 00 00 00       	mov    ebx,0x64
  47d4e6:	83 f9 0b             	cmp    ecx,0xb
  47d4e9:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  47d4ed:	89 5c 24 10          	mov    DWORD PTR [esp+0x10],ebx
  47d4f1:	75 0c                	jne    0x47d4ff
  47d4f3:	c7 44 24 10 c8 00 00 	mov    DWORD PTR [esp+0x10],0xc8
  47d4fa:	00 
  47d4fb:	8b 5c 24 10          	mov    ebx,DWORD PTR [esp+0x10]
  47d4ff:	8b 78 2c             	mov    edi,DWORD PTR [eax+0x2c]
  47d502:	8b 40 34             	mov    eax,DWORD PTR [eax+0x34]
  47d505:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  47d509:	6a 01                	push   0x1
  47d50b:	50                   	push   eax
  47d50c:	e8 9f ce ff ff       	call   0x47a3b0
  47d511:	2b c7                	sub    eax,edi
  47d513:	d1 f8                	sar    eax,1
  47d515:	89 44 24 3c          	mov    DWORD PTR [esp+0x3c],eax
  47d519:	79 08                	jns    0x47d523
  47d51b:	c7 44 24 3c 00 00 00 	mov    DWORD PTR [esp+0x3c],0x0
  47d522:	00 
  47d523:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  47d526:	8b 01                	mov    eax,DWORD PTR [ecx]
  47d528:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  47d52b:	89 44 24 48          	mov    DWORD PTR [esp+0x48],eax
  47d52f:	89 4c 24 50          	mov    DWORD PTR [esp+0x50],ecx
  47d533:	83 c0 64             	add    eax,0x64
  47d536:	b9 56 00 00 00       	mov    ecx,0x56
  47d53b:	8b 10                	mov    edx,DWORD PTR [eax]
  47d53d:	83 c0 04             	add    eax,0x4
  47d540:	03 f2                	add    esi,edx
  47d542:	49                   	dec    ecx
  47d543:	75 f6                	jne    0x47d53b
  47d545:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  47d549:	8b c3                	mov    eax,ebx
  47d54b:	0f af c6             	imul   eax,esi
  47d54e:	8b 91 ac 19 00 00    	mov    edx,DWORD PTR [ecx+0x19ac]
  47d554:	8b fe                	mov    edi,esi
  47d556:	33 f6                	xor    esi,esi
  47d558:	89 7c 24 30          	mov    DWORD PTR [esp+0x30],edi
  47d55c:	85 d2                	test   edx,edx
  47d55e:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47d562:	7e 38                	jle    0x47d59c
  47d564:	8d 99 98 19 00 00    	lea    ebx,[ecx+0x1998]
  47d56a:	6a 00                	push   0x0
  47d56c:	56                   	push   esi
  47d56d:	8b cb                	mov    ecx,ebx
  47d56f:	e8 7c 42 f8 ff       	call   0x4017f0
  47d574:	8b 48 1c             	mov    ecx,DWORD PTR [eax+0x1c]
  47d577:	85 c9                	test   ecx,ecx
  47d579:	74 0c                	je     0x47d587
  47d57b:	8b 10                	mov    edx,DWORD PTR [eax]
  47d57d:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  47d581:	03 c2                	add    eax,edx
  47d583:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47d587:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  47d58b:	46                   	inc    esi
  47d58c:	3b b0 ac 19 00 00    	cmp    esi,DWORD PTR [eax+0x19ac]
  47d592:	7c d6                	jl     0x47d56a
  47d594:	8b 5c 24 10          	mov    ebx,DWORD PTR [esp+0x10]
  47d598:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  47d59c:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  47d5a0:	3b c8                	cmp    ecx,eax
  47d5a2:	7d 12                	jge    0x47d5b6
  47d5a4:	8b c1                	mov    eax,ecx
  47d5a6:	99                   	cdq
  47d5a7:	f7 ff                	idiv   edi
  47d5a9:	0f af f8             	imul   edi,eax
  47d5ac:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  47d5b0:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  47d5b4:	eb 06                	jmp    0x47d5bc
  47d5b6:	89 5c 24 10          	mov    DWORD PTR [esp+0x10],ebx
  47d5ba:	8b c3                	mov    eax,ebx
  47d5bc:	8b 15 70 c6 57 00    	mov    edx,DWORD PTR ds:0x57c670
  47d5c2:	33 c9                	xor    ecx,ecx
  47d5c4:	8b b2 94 00 00 00    	mov    esi,DWORD PTR [edx+0x94]
  47d5ca:	66 8b 4e 0a          	mov    cx,WORD PTR [esi+0xa]
  47d5ce:	83 f9 64             	cmp    ecx,0x64
  47d5d1:	89 4c 24 4c          	mov    DWORD PTR [esp+0x4c],ecx
  47d5d5:	7c 08                	jl     0x47d5df
  47d5d7:	c7 44 24 4c 63 00 00 	mov    DWORD PTR [esp+0x4c],0x63
  47d5de:	00 
  47d5df:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  47d5e2:	85 c9                	test   ecx,ecx
  47d5e4:	74 08                	je     0x47d5ee
  47d5e6:	85 db                	test   ebx,ebx
  47d5e8:	74 04                	je     0x47d5ee
  47d5ea:	89 5c 24 54          	mov    DWORD PTR [esp+0x54],ebx
  47d5ee:	dd 05 10 c3 55 00    	fld    QWORD PTR ds:0x55c310
  47d5f4:	85 c0                	test   eax,eax
  47d5f6:	0f 84 05 03 00 00    	je     0x47d901
  47d5fc:	8b 44 24 48          	mov    eax,DWORD PTR [esp+0x48]
  47d600:	81 c2 a8 00 00 00    	add    edx,0xa8
  47d606:	8d 4c 24 58          	lea    ecx,[esp+0x58]
  47d60a:	83 c0 64             	add    eax,0x64
  47d60d:	bf 56 00 00 00       	mov    edi,0x56
  47d612:	8b 30                	mov    esi,DWORD PTR [eax]
  47d614:	83 c0 04             	add    eax,0x4
  47d617:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  47d61b:	89 31                	mov    DWORD PTR [ecx],esi
  47d61d:	8b 32                	mov    esi,DWORD PTR [edx]
  47d61f:	83 c1 04             	add    ecx,0x4
  47d622:	83 c2 04             	add    edx,0x4
  47d625:	4f                   	dec    edi
  47d626:	dd 86 c0 00 00 00    	fld    QWORD PTR [esi+0xc0]
  47d62c:	da 4c 24 18          	fimul  DWORD PTR [esp+0x18]
  47d630:	dc 0d 28 c4 55 00    	fmul   QWORD PTR ds:0x55c428
  47d636:	de c1                	faddp  st(1),st
  47d638:	75 d8                	jne    0x47d612
  47d63a:	db 44 24 30          	fild   DWORD PTR [esp+0x30]
  47d63e:	8b 5c 24 24          	mov    ebx,DWORD PTR [esp+0x24]
  47d642:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  47d646:	85 c0                	test   eax,eax
  47d648:	d8 f9                	fdivr  st,st(1)
  47d64a:	8b 8b ac 19 00 00    	mov    ecx,DWORD PTR [ebx+0x19ac]
  47d650:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  47d657:	00 
  47d658:	c7 44 24 2c 00 00 00 	mov    DWORD PTR [esp+0x2c],0x0
  47d65f:	00 
  47d660:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  47d664:	dd 5c 24 30          	fstp   QWORD PTR [esp+0x30]
  47d668:	dd d8                	fstp   st(0)
  47d66a:	0f 8e 82 00 00 00    	jle    0x47d6f2
  47d670:	eb 04                	jmp    0x47d676
  47d672:	8b 5c 24 24          	mov    ebx,DWORD PTR [esp+0x24]
  47d676:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  47d67a:	33 f6                	xor    esi,esi
  47d67c:	33 ff                	xor    edi,edi
  47d67e:	85 c0                	test   eax,eax
  47d680:	7e 70                	jle    0x47d6f2
  47d682:	81 c3 98 19 00 00    	add    ebx,0x1998
  47d688:	6a 00                	push   0x0
  47d68a:	57                   	push   edi
  47d68b:	8b cb                	mov    ecx,ebx
  47d68d:	e8 5e 41 f8 ff       	call   0x4017f0
  47d692:	8b 48 1c             	mov    ecx,DWORD PTR [eax+0x1c]
  47d695:	85 c9                	test   ecx,ecx
  47d697:	74 15                	je     0x47d6ae
  47d699:	83 38 00             	cmp    DWORD PTR [eax],0x0
  47d69c:	74 10                	je     0x47d6ae
  47d69e:	85 f6                	test   esi,esi
  47d6a0:	74 0a                	je     0x47d6ac
  47d6a2:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  47d6a5:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  47d6a8:	3b d1                	cmp    edx,ecx
  47d6aa:	7d 02                	jge    0x47d6ae
  47d6ac:	8b f0                	mov    esi,eax
  47d6ae:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  47d6b2:	47                   	inc    edi
  47d6b3:	3b f8                	cmp    edi,eax
  47d6b5:	7c d1                	jl     0x47d688
  47d6b7:	85 f6                	test   esi,esi
  47d6b9:	74 33                	je     0x47d6ee
  47d6bb:	8b 06                	mov    eax,DWORD PTR [esi]
  47d6bd:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  47d6c1:	3b c1                	cmp    eax,ecx
  47d6c3:	7c 02                	jl     0x47d6c7
  47d6c5:	8b c1                	mov    eax,ecx
  47d6c7:	d9 46 10             	fld    DWORD PTR [esi+0x10]
  47d6ca:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47d6ce:	8b 3e                	mov    edi,DWORD PTR [esi]
  47d6d0:	da 4c 24 14          	fimul  DWORD PTR [esp+0x14]
  47d6d4:	2b c8                	sub    ecx,eax
  47d6d6:	2b f8                	sub    edi,eax
  47d6d8:	85 c9                	test   ecx,ecx
  47d6da:	89 3e                	mov    DWORD PTR [esi],edi
  47d6dc:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  47d6e0:	dc 4c 24 30          	fmul   QWORD PTR [esp+0x30]
  47d6e4:	dc 44 24 28          	fadd   QWORD PTR [esp+0x28]
  47d6e8:	dd 5c 24 28          	fstp   QWORD PTR [esp+0x28]
  47d6ec:	7f 84                	jg     0x47d672
  47d6ee:	8b 5c 24 24          	mov    ebx,DWORD PTR [esp+0x24]
  47d6f2:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  47d6f6:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  47d6fa:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  47d6fe:	8b cb                	mov    ecx,ebx
  47d700:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47d704:	e8 17 d4 ff ff       	call   0x47ab20
  47d709:	dc 4c 24 28          	fmul   QWORD PTR [esp+0x28]
  47d70d:	dd 54 24 28          	fst    QWORD PTR [esp+0x28]
  47d711:	dc 64 24 18          	fsub   QWORD PTR [esp+0x18]
  47d715:	dd 54 24 18          	fst    QWORD PTR [esp+0x18]
  47d719:	e8 22 1a 0d 00       	call   0x54f140
  47d71e:	85 c0                	test   eax,eax
  47d720:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  47d724:	6a ff                	push   0xffffffff
  47d726:	7e 15                	jle    0x47d73d
  47d728:	db 44 24 34          	fild   DWORD PTR [esp+0x34]
  47d72c:	6a 00                	push   0x0
  47d72e:	51                   	push   ecx
  47d72f:	8b cb                	mov    ecx,ebx
  47d731:	d9 1c 24             	fstp   DWORD PTR [esp]
  47d734:	6a 13                	push   0x13
  47d736:	e8 05 a7 ff ff       	call   0x477e40
  47d73b:	eb 17                	jmp    0x47d754
  47d73d:	f7 d8                	neg    eax
  47d73f:	89 44 24 34          	mov    DWORD PTR [esp+0x34],eax
  47d743:	51                   	push   ecx
  47d744:	db 44 24 38          	fild   DWORD PTR [esp+0x38]
  47d748:	8b cb                	mov    ecx,ebx
  47d74a:	d9 1c 24             	fstp   DWORD PTR [esp]
  47d74d:	6a 17                	push   0x17
  47d74f:	e8 2c a5 ff ff       	call   0x477c80
  47d754:	dd 44 24 28          	fld    QWORD PTR [esp+0x28]
  47d758:	8b 7c 24 40          	mov    edi,DWORD PTR [esp+0x40]
  47d75c:	6a ff                	push   0xffffffff
  47d75e:	dc 64 24 1c          	fsub   QWORD PTR [esp+0x1c]
  47d762:	8b 47 38             	mov    eax,DWORD PTR [edi+0x38]
  47d765:	6a 00                	push   0x0
  47d767:	51                   	push   ecx
  47d768:	83 f8 1a             	cmp    eax,0x1a
  47d76b:	d9 1c 24             	fstp   DWORD PTR [esp]
  47d76e:	75 04                	jne    0x47d774
  47d770:	6a 12                	push   0x12
  47d772:	eb 02                	jmp    0x47d776
  47d774:	6a 0c                	push   0xc
  47d776:	8b cb                	mov    ecx,ebx
  47d778:	e8 c3 a6 ff ff       	call   0x477e40
  47d77d:	db 44 24 10          	fild   DWORD PTR [esp+0x10]
  47d781:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  47d784:	8b 15 70 c6 57 00    	mov    edx,DWORD PTR ds:0x57c670
  47d78a:	d8 4e 04             	fmul   DWORD PTR [esi+0x4]
  47d78d:	db 44 24 3c          	fild   DWORD PTR [esp+0x3c]
  47d791:	8b 82 9c 00 00 00    	mov    eax,DWORD PTR [edx+0x9c]
  47d797:	dc 05 20 c4 55 00    	fadd   QWORD PTR ds:0x55c420
  47d79d:	3b c3                	cmp    eax,ebx
  47d79f:	de c9                	fmulp  st(1),st
  47d7a1:	dc 0d 18 c4 55 00    	fmul   QWORD PTR ds:0x55c418
  47d7a7:	dd 5c 24 40          	fstp   QWORD PTR [esp+0x40]
  47d7ab:	0f 85 f1 00 00 00    	jne    0x47d8a2
  47d7b1:	8b 0d e0 c1 57 00    	mov    ecx,DWORD PTR ds:0x57c1e0
  47d7b7:	8d 43 04             	lea    eax,[ebx+0x4]
  47d7ba:	50                   	push   eax
  47d7bb:	68 50 7c 56 00       	push   0x567c50
  47d7c0:	68 00 88 88 00       	push   0x888800
  47d7c5:	51                   	push   ecx
  47d7c6:	e8 95 ce 0c 00       	call   0x54a660
  47d7cb:	8b 57 34             	mov    edx,DWORD PTR [edi+0x34]
  47d7ce:	8b 0d e0 c1 57 00    	mov    ecx,DWORD PTR ds:0x57c1e0
  47d7d4:	8b 04 95 d4 34 58 00 	mov    eax,DWORD PTR [edx*4+0x5834d4]
  47d7db:	50                   	push   eax
  47d7dc:	68 48 7c 56 00       	push   0x567c48
  47d7e1:	68 00 88 88 00       	push   0x888800
  47d7e6:	51                   	push   ecx
  47d7e7:	e8 74 ce 0c 00       	call   0x54a660
  47d7ec:	8b 54 24 5c          	mov    edx,DWORD PTR [esp+0x5c]
  47d7f0:	a1 e0 c1 57 00       	mov    eax,ds:0x57c1e0
  47d7f5:	52                   	push   edx
  47d7f6:	68 38 7c 56 00       	push   0x567c38
  47d7fb:	68 00 88 88 00       	push   0x888800
  47d800:	50                   	push   eax
  47d801:	e8 5a ce 0c 00       	call   0x54a660
  47d806:	8b 0e                	mov    ecx,DWORD PTR [esi]
  47d808:	8b 15 e0 c1 57 00    	mov    edx,DWORD PTR ds:0x57c1e0
  47d80e:	83 c1 04             	add    ecx,0x4
  47d811:	51                   	push   ecx
  47d812:	68 28 7c 56 00       	push   0x567c28
  47d817:	68 00 88 88 00       	push   0x888800
  47d81c:	52                   	push   edx
  47d81d:	e8 3e ce 0c 00       	call   0x54a660
  47d822:	8b 44 24 50          	mov    eax,DWORD PTR [esp+0x50]
  47d826:	8b 0d e0 c1 57 00    	mov    ecx,DWORD PTR ds:0x57c1e0
  47d82c:	83 c4 40             	add    esp,0x40
  47d82f:	50                   	push   eax
  47d830:	68 18 7c 56 00       	push   0x567c18
  47d835:	68 00 88 88 00       	push   0x888800
  47d83a:	51                   	push   ecx
  47d83b:	e8 20 ce 0c 00       	call   0x54a660
  47d840:	8b 54 24 3c          	mov    edx,DWORD PTR [esp+0x3c]
  47d844:	8b 44 24 38          	mov    eax,DWORD PTR [esp+0x38]
  47d848:	8b 0d e0 c1 57 00    	mov    ecx,DWORD PTR ds:0x57c1e0
  47d84e:	52                   	push   edx
  47d84f:	50                   	push   eax
  47d850:	68 08 7c 56 00       	push   0x567c08
  47d855:	68 00 88 88 00       	push   0x888800
  47d85a:	51                   	push   ecx
  47d85b:	e8 00 ce 0c 00       	call   0x54a660
  47d860:	d9 46 04             	fld    DWORD PTR [esi+0x4]
  47d863:	8b 15 e0 c1 57 00    	mov    edx,DWORD PTR ds:0x57c1e0
  47d869:	83 c4 1c             	add    esp,0x1c
  47d86c:	dd 1c 24             	fstp   QWORD PTR [esp]
  47d86f:	68 f8 7b 56 00       	push   0x567bf8
  47d874:	68 00 88 88 00       	push   0x888800
  47d879:	52                   	push   edx
  47d87a:	e8 e1 cd 0c 00       	call   0x54a660
  47d87f:	8b 44 24 58          	mov    eax,DWORD PTR [esp+0x58]
  47d883:	8b 4c 24 54          	mov    ecx,DWORD PTR [esp+0x54]
  47d887:	8b 15 e0 c1 57 00    	mov    edx,DWORD PTR ds:0x57c1e0
  47d88d:	50                   	push   eax
  47d88e:	51                   	push   ecx
  47d88f:	68 e8 7b 56 00       	push   0x567be8
  47d894:	68 00 88 88 00       	push   0x888800
  47d899:	52                   	push   edx
  47d89a:	e8 c1 cd 0c 00       	call   0x54a660
  47d89f:	83 c4 28             	add    esp,0x28
  47d8a2:	dd 44 24 40          	fld    QWORD PTR [esp+0x40]
  47d8a6:	dc 05 00 c3 55 00    	fadd   QWORD PTR ds:0x55c300
  47d8ac:	d9 5e 1c             	fstp   DWORD PTR [esi+0x1c]
  47d8af:	dd 44 24 40          	fld    QWORD PTR [esp+0x40]
  47d8b3:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  47d8b7:	8b 4c 24 54          	mov    ecx,DWORD PTR [esp+0x54]
  47d8bb:	dc 64 24 28          	fsub   QWORD PTR [esp+0x28]
  47d8bf:	8b 54 24 4c          	mov    edx,DWORD PTR [esp+0x4c]
  47d8c3:	89 46 14             	mov    DWORD PTR [esi+0x14],eax
  47d8c6:	8b 44 24 50          	mov    eax,DWORD PTR [esp+0x50]
  47d8ca:	89 4e 20             	mov    DWORD PTR [esi+0x20],ecx
  47d8cd:	dc 05 00 c3 55 00    	fadd   QWORD PTR ds:0x55c300
  47d8d3:	d9 5e 18             	fstp   DWORD PTR [esi+0x18]
  47d8d6:	89 56 24             	mov    DWORD PTR [esi+0x24],edx
  47d8d9:	89 46 2c             	mov    DWORD PTR [esi+0x2c],eax
  47d8dc:	8b 4b 3c             	mov    ecx,DWORD PTR [ebx+0x3c]
  47d8df:	89 4e 28             	mov    DWORD PTR [esi+0x28],ecx
  47d8e2:	8b cb                	mov    ecx,ebx
  47d8e4:	e8 47 11 00 00       	call   0x47ea30
  47d8e9:	8b 4c 24 48          	mov    ecx,DWORD PTR [esp+0x48]
  47d8ed:	53                   	push   ebx
  47d8ee:	56                   	push   esi
  47d8ef:	e8 8c 26 09 00       	call   0x50ff80
  47d8f4:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  47d8f8:	5f                   	pop    edi
  47d8f9:	5e                   	pop    esi
  47d8fa:	5b                   	pop    ebx
  47d8fb:	8b e5                	mov    esp,ebp
  47d8fd:	5d                   	pop    ebp
  47d8fe:	c2 08 00             	ret    0x8
  47d901:	5f                   	pop    edi
  47d902:	5e                   	pop    esi
  47d903:	dd d8                	fstp   st(0)
  47d905:	5b                   	pop    ebx
  47d906:	8b e5                	mov    esp,ebp
  47d908:	5d                   	pop    ebp
  47d909:	c2                   	.byte 0xc2
  47d90a:	08                   	.byte 0x8
```

