# Function batch packet

## `GameClock_Construct` — `0x4dd270`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x4dd270.c`
- Callers: `GameSession_Construct` (0x4811b0)
- Callees: `CRT_BeginThread` (0x54f167), `GameCalendar_Load` (0x4dd590), `GameClock_Reset` (0x4dd4a0)

- Signature: `{'call_site': 'GameSession_Construct caller', 'confidence': 'derived from ECX=this, one stack arg and RET 4', 'recovered': 'GameClock *__thiscall GameClock_Construct(GameClock *this, int load_from_save)', 'return': 'this in EAX; RET 4'}`
- Dispatch: `call` None -> ['0x4dd590'], `call` None -> ['0x4dd4a0'], `call` None -> ['0x54f167']
- Unresolved questions: The exact thread API wrapper at 0x54f167 is named CRT_BeginThread by the export; its thread-argument convention is inferred from the callback thunk.

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

004dd270 <.text+0xdc270>:
  4dd270:	8b 44 24 04          	mov    eax,DWORD PTR [esp+0x4]
  4dd274:	56                   	push   esi
  4dd275:	8b f1                	mov    esi,ecx
  4dd277:	85 c0                	test   eax,eax
  4dd279:	c7 06 64 c5 55 00    	mov    DWORD PTR [esi],0x55c564
  4dd27f:	c7 05 bc df 57 00 d0 	mov    DWORD PTR ds:0x57dfbc,0x7d0
  4dd286:	07 00 00 
  4dd289:	74 08                	je     0x4dd293
  4dd28b:	50                   	push   eax
  4dd28c:	e8 ff 02 00 00       	call   0x4dd590
  4dd291:	eb 07                	jmp    0x4dd29a
  4dd293:	8b ce                	mov    ecx,esi
  4dd295:	e8 06 02 00 00       	call   0x4dd4a0
  4dd29a:	56                   	push   esi
  4dd29b:	6a 00                	push   0x0
  4dd29d:	68 d0 d2 4d 00       	push   0x4dd2d0
  4dd2a2:	c7 46 1c 00 00 00 00 	mov    DWORD PTR [esi+0x1c],0x0
  4dd2a9:	c7 46 24 00 00 00 00 	mov    DWORD PTR [esi+0x24],0x0
  4dd2b0:	c7 46 20 00 00 00 00 	mov    DWORD PTR [esi+0x20],0x0
  4dd2b7:	c7 46 14 35 0c 00 00 	mov    DWORD PTR [esi+0x14],0xc35
  4dd2be:	e8 a4 1e 07 00       	call   0x54f167
  4dd2c3:	83 c4 0c             	add    esp,0xc
  4dd2c6:	8b c6                	mov    eax,esi
  4dd2c8:	5e                   	pop    esi
  4dd2c9:	c2                   	.byte 0xc2
  4dd2ca:	04                   	.byte 0x4
```

## `GameClock_ThreadThunk` — `0x4dd2d0`

- Body: `curated`
- Callers: none in the named export
- Callees: none resolved

- Signature: `{'call_site': 'thread entry registered at 0x4dd29d', 'confidence': 'derived from [esp+4] load into ECX and tail jump', 'recovered': 'void __cdecl GameClock_ThreadThunk(void *clock)', 'return': 'does not return to caller; jumps to worker'}`
- Dispatch: `tail_jump` None -> ['0x4dd300']
- Unresolved questions: Thunk has no named procedure; recovered from registration and disassembly.

## `GameClock_Worker` — `0x4dd300`

- Body: `curated`
- Callers: none in the named export
- Callees: none resolved

- Signature: `{'call_site': 'tail jump 0x4dd2d4', 'confidence': 'derived from ECX=this and thread loop', 'recovered': 'void __fastcall GameClock_Worker(GameClock *this)', 'return': 'sets this+0x24 and returns'}`
- Dispatch: `call` None -> ['0x528190'], `call` None -> ['0x528190'], `call` None -> ['0x488a10']
- Unresolved questions: The thread body has no named procedure; range is recovered by bounded disassembly and the return site at 0x4dd49b.; The import called through [0x55c090] was not named in this batch; it blocks the worker between ticks.

## `GameCalendar_Save` — `0x4dd4f0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x4dd4f0.c`
- Callers: `SaveGame_Serialize` (0x487b50)
- Callees: `CRT_Ostream_Write` (0x54cc2b)

- Signature: `{'call_site': 'calendar save path', 'confidence': 'derived from ECX=this, one stack arg and CRT_Ostream_Write calls', 'recovered': 'void __thiscall GameCalendar_Save(GameClock *this, void *stream)', 'return': 'void; RET 4'}`
- Dispatch: `call` None -> ['0x54cc2b']
- Unresolved questions: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

004dd4f0 <.text+0xdc4f0>:
  4dd4f0:	56                   	push   esi
  4dd4f1:	8b f1                	mov    esi,ecx
  4dd4f3:	57                   	push   edi
  4dd4f4:	8b 7c 24 0c          	mov    edi,DWORD PTR [esp+0xc]
  4dd4f8:	8d 46 07             	lea    eax,[esi+0x7]
  4dd4fb:	6a 01                	push   0x1
  4dd4fd:	50                   	push   eax
  4dd4fe:	8b cf                	mov    ecx,edi
  4dd500:	e8 26 f7 06 00       	call   0x54cc2b
  4dd505:	8d 4e 06             	lea    ecx,[esi+0x6]
  4dd508:	6a 01                	push   0x1
  4dd50a:	51                   	push   ecx
  4dd50b:	8b cf                	mov    ecx,edi
  4dd50d:	e8 19 f7 06 00       	call   0x54cc2b
  4dd512:	8d 56 08             	lea    edx,[esi+0x8]
  4dd515:	6a 01                	push   0x1
  4dd517:	52                   	push   edx
  4dd518:	8b cf                	mov    ecx,edi
  4dd51a:	e8 0c f7 06 00       	call   0x54cc2b
  4dd51f:	8d 46 04             	lea    eax,[esi+0x4]
  4dd522:	6a 02                	push   0x2
  4dd524:	50                   	push   eax
  4dd525:	8b cf                	mov    ecx,edi
  4dd527:	e8 ff f6 06 00       	call   0x54cc2b
  4dd52c:	8d 4e 0a             	lea    ecx,[esi+0xa]
  4dd52f:	6a 02                	push   0x2
  4dd531:	51                   	push   ecx
  4dd532:	8b cf                	mov    ecx,edi
  4dd534:	e8 f2 f6 06 00       	call   0x54cc2b
  4dd539:	8d 56 0c             	lea    edx,[esi+0xc]
  4dd53c:	6a 04                	push   0x4
  4dd53e:	52                   	push   edx
  4dd53f:	8b cf                	mov    ecx,edi
  4dd541:	e8 e5 f6 06 00       	call   0x54cc2b
  4dd546:	8d 46 19             	lea    eax,[esi+0x19]
  4dd549:	6a 01                	push   0x1
  4dd54b:	50                   	push   eax
  4dd54c:	8b cf                	mov    ecx,edi
  4dd54e:	e8 d8 f6 06 00       	call   0x54cc2b
  4dd553:	8d 4e 18             	lea    ecx,[esi+0x18]
  4dd556:	6a 01                	push   0x1
  4dd558:	51                   	push   ecx
  4dd559:	8b cf                	mov    ecx,edi
  4dd55b:	e8 cb f6 06 00       	call   0x54cc2b
  4dd560:	8d 56 14             	lea    edx,[esi+0x14]
  4dd563:	6a 04                	push   0x4
  4dd565:	52                   	push   edx
  4dd566:	8b cf                	mov    ecx,edi
  4dd568:	e8 be f6 06 00       	call   0x54cc2b
  4dd56d:	83 c6 10             	add    esi,0x10
  4dd570:	6a 04                	push   0x4
  4dd572:	56                   	push   esi
  4dd573:	8b cf                	mov    ecx,edi
  4dd575:	e8 b1 f6 06 00       	call   0x54cc2b
  4dd57a:	6a 04                	push   0x4
  4dd57c:	68 bc df 57 00       	push   0x57dfbc
  4dd581:	8b cf                	mov    ecx,edi
  4dd583:	e8 a3 f6 06 00       	call   0x54cc2b
  4dd588:	5f                   	pop    edi
  4dd589:	5e                   	pop    esi
  4dd58a:	c2                   	.byte 0xc2
  4dd58b:	04                   	.byte 0x4
```

## `GameCalendar_Load` — `0x4dd590`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x4dd590.c`
- Callers: `Game_LoadSaveGame` (0x488110), `GameClock_Construct` (0x4dd270)
- Callees: `CRT_Istream_Read` (0x54cbc1)

- Signature: `{'call_site': 'GameClock_Construct load path', 'confidence': 'derived from ECX=this, one stack arg and CRT_Istream_Read calls', 'recovered': 'void __thiscall GameCalendar_Load(GameClock *this, void *stream)', 'return': 'void; RET 4'}`
- Dispatch: `call` None -> ['0x54cbc1']
- Unresolved questions: Saved-state layout is exact for the clock fields; the stream wrapper version field 0x57c668 is outside this batch.

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

004dd590 <.text+0xdc590>:
  4dd590:	53                   	push   ebx
  4dd591:	56                   	push   esi
  4dd592:	8b f1                	mov    esi,ecx
  4dd594:	57                   	push   edi
  4dd595:	8b 7c 24 10          	mov    edi,DWORD PTR [esp+0x10]
  4dd599:	6a 01                	push   0x1
  4dd59b:	8d 46 07             	lea    eax,[esi+0x7]
  4dd59e:	8b cf                	mov    ecx,edi
  4dd5a0:	50                   	push   eax
  4dd5a1:	e8 1b f6 06 00       	call   0x54cbc1
  4dd5a6:	8d 4e 06             	lea    ecx,[esi+0x6]
  4dd5a9:	6a 01                	push   0x1
  4dd5ab:	51                   	push   ecx
  4dd5ac:	8b cf                	mov    ecx,edi
  4dd5ae:	e8 0e f6 06 00       	call   0x54cbc1
  4dd5b3:	8d 56 08             	lea    edx,[esi+0x8]
  4dd5b6:	6a 01                	push   0x1
  4dd5b8:	52                   	push   edx
  4dd5b9:	8b cf                	mov    ecx,edi
  4dd5bb:	e8 01 f6 06 00       	call   0x54cbc1
  4dd5c0:	8d 46 04             	lea    eax,[esi+0x4]
  4dd5c3:	6a 02                	push   0x2
  4dd5c5:	50                   	push   eax
  4dd5c6:	8b cf                	mov    ecx,edi
  4dd5c8:	e8 f4 f5 06 00       	call   0x54cbc1
  4dd5cd:	8d 4e 0a             	lea    ecx,[esi+0xa]
  4dd5d0:	6a 02                	push   0x2
  4dd5d2:	51                   	push   ecx
  4dd5d3:	8b cf                	mov    ecx,edi
  4dd5d5:	e8 e7 f5 06 00       	call   0x54cbc1
  4dd5da:	8d 56 0c             	lea    edx,[esi+0xc]
  4dd5dd:	6a 04                	push   0x4
  4dd5df:	52                   	push   edx
  4dd5e0:	8b cf                	mov    ecx,edi
  4dd5e2:	e8 da f5 06 00       	call   0x54cbc1
  4dd5e7:	8d 46 19             	lea    eax,[esi+0x19]
  4dd5ea:	6a 01                	push   0x1
  4dd5ec:	50                   	push   eax
  4dd5ed:	8b cf                	mov    ecx,edi
  4dd5ef:	e8 cd f5 06 00       	call   0x54cbc1
  4dd5f4:	8d 4e 18             	lea    ecx,[esi+0x18]
  4dd5f7:	6a 01                	push   0x1
  4dd5f9:	51                   	push   ecx
  4dd5fa:	8b cf                	mov    ecx,edi
  4dd5fc:	e8 c0 f5 06 00       	call   0x54cbc1
  4dd601:	8d 5e 14             	lea    ebx,[esi+0x14]
  4dd604:	6a 04                	push   0x4
  4dd606:	53                   	push   ebx
  4dd607:	8b cf                	mov    ecx,edi
  4dd609:	e8 b3 f5 06 00       	call   0x54cbc1
  4dd60e:	83 c6 10             	add    esi,0x10
  4dd611:	6a 04                	push   0x4
  4dd613:	56                   	push   esi
  4dd614:	8b cf                	mov    ecx,edi
  4dd616:	c7 03 35 0c 00 00    	mov    DWORD PTR [ebx],0xc35
  4dd61c:	e8 a0 f5 06 00       	call   0x54cbc1
  4dd621:	83 3d 68 c6 57 00 2d 	cmp    DWORD PTR ds:0x57c668,0x2d
  4dd628:	7e 14                	jle    0x4dd63e
  4dd62a:	6a 04                	push   0x4
  4dd62c:	68 bc df 57 00       	push   0x57dfbc
  4dd631:	8b cf                	mov    ecx,edi
  4dd633:	e8 89 f5 06 00       	call   0x54cbc1
  4dd638:	5f                   	pop    edi
  4dd639:	5e                   	pop    esi
  4dd63a:	5b                   	pop    ebx
  4dd63b:	c2 04 00             	ret    0x4
  4dd63e:	5f                   	pop    edi
  4dd63f:	5e                   	pop    esi
  4dd640:	c7 05 bc df 57 00 d0 	mov    DWORD PTR ds:0x57dfbc,0x7d0
  4dd647:	07 00 00 
  4dd64a:	5b                   	pop    ebx
  4dd64b:	c2                   	.byte 0xc2
  4dd64c:	04                   	.byte 0x4
```

## `UI_QueueChildCommand` — `0x528190`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x528190.c`
- Callers: `Game_RenderFrame` (0x485140), `IngredientMenu_HandleInput` (0x4c67f0), `Company_ProcessHourlyTick` (0x4e0200), `Game_CompleteMissionStage` (0x4f6b50), `Window_RenderFrame` (0x5243c0)
- Callees: `UI_QueueCommand` (0x525bc0)

- Signature: `{'call_site': '0x4dd420 and 0x4dd469', 'confidence': 'derived from ECX=this, two stack args and return branches', 'recovered': 'int __thiscall UI_QueueChildCommand(UI *this, int command, int value)', 'return': '1 when queued, 0 when no child window'}`
- Dispatch: `call` None -> []
- Unresolved questions: UI_QueueCommand address is not annotated in this batch; the record focuses on the clock command handoff.

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

00528190 <.text+0x127190>:
  528190:	8b 81 04 83 00 00    	mov    eax,DWORD PTR [ecx+0x8304]
  528196:	85 c0                	test   eax,eax
  528198:	75 03                	jne    0x52819d
  52819a:	c2 08 00             	ret    0x8
  52819d:	8b 54 24 08          	mov    edx,DWORD PTR [esp+0x8]
  5281a1:	52                   	push   edx
  5281a2:	8b 54 24 08          	mov    edx,DWORD PTR [esp+0x8]
  5281a6:	52                   	push   edx
  5281a7:	6a 00                	push   0x0
  5281a9:	6a 00                	push   0x0
  5281ab:	50                   	push   eax
  5281ac:	e8 0f da ff ff       	call   0x525bc0
  5281b1:	b8 01 00 00 00       	mov    eax,0x1
  5281b6:	c2                   	.byte 0xc2
  5281b7:	08                   	.byte 0x8
```

## `Game_WindowProc` — `0x4058d0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x4058d0.c`
- Callers: `UI_Init` (0x4067d0)
- Callees: `AI_InitActionPlan` (0x502ce0), `Array_GetRecordByKeyPtr` (0x52ff20), `Branch_EnqueueConstructionOrder` (0x47e0e0), `CRT_Fclose` (0x54dee4), `CRT_Fopen` (0x54dfe0), `CS_Enter` (0x401320), `CS_Leave` (0x401340), `City_OpenBuildingDirectory` (0x48a4c0), `ConstructionOrder_Construct` (0x4e5d60), `Game_AutoSaveTick` (0x48b570), `Game_CanAfford` (0x477e40), `Game_CenterViewOnObject` (0x4d23b0), `Game_ClearSelectedObject` (0x48cfa0), `Game_CommitObjectPlacement` (0x489bc0), `Game_ComputeRecordCompanyPrice` (0x4e63f0), `Game_EndOfHour` (0x486590), `Game_GetPlayerCity` (0x4ddcc0), `Game_HandleQueryEndSession` (0x4a21a0), `Game_OnObjectListSelection` (0x48bda0), `Game_ResumeSimulation` (0x488d20), `Game_SearchObjectsByName` (0x48bb70), `Game_SelectBuilding` (0x4a9320), `Game_SelectPlayer` (0x48c160), `Game_SetObjectInfoWindowVisible` (0x48cae0), `Game_SetViewMode` (0x4850a0), `Game_ShowFindPersonPrompt` (0x48bae0), `Game_SuspendSimulation` (0x488cc0), `Game_ValidateObjectPlacement` (0x489180), `Grid_GetCell` (0x4ef4b0), `IDMap_Lookup` (0x4017f0), `IsoMap_MarkPlayerFootprints` (0x4f2e50), `MapView_GetRotation` (0x527ab0), `Map_ScreenToGridCell` (0x4f4e90), `Map_SetTileFieldWithDefault` (0x4ed330), `MissionGoal_HandleEvent` (0x502f10), `Mission_EvaluateGoals` (0x4f5fd0), `Object_GetChildOrigin` (0x527ad0), `Random_Mod` (0x4034b0), `Random_RangeFast` (0x4034d0), `SoundSystem_Init` (0x5475a0), `Sound_PlaySpeechStatement` (0x548e00), `Sound_PlayStatusAdvisory` (0x548ed0), `Sound_SelectCurrentTrack` (0x547e70), `Sprite_TestCollision` (0x53d720), `String_Format` (0x54dd83), `Surface_SaveTga` (0x5377f0), `UI_ApplyChildSpriteTint` (0x527a80), `UI_Briefing_AddPinnedMessage` (0x54aa10), `UI_QueueControlCommand` (0x5301c0), `UI_RefreshAndCenter` (0x523de0), `UI_RefreshChildSprite` (0x527a10), `UI_ResetInputHelper` (0x527aa0), `UI_SetButtonRecordVariant` (0x531b70), `UI_ShowAIStatusWindow` (0x482b30), `UI_ShowMessageDialog` (0x48d420), `UI_ShowPauseDialog` (0x48d4c0), `Window_Construct` (0x537230)

- Signature: `{'call_site': 'UI command dispatch', 'confidence': 'derived from [esp+0x150] command load and [esp+0x164] value load; provider signature is noisy', 'recovered': 'int __cdecl Game_WindowProc(int command, int value)', 'return': 'int in EAX'}`
- Dispatch: `switch_case` None -> ['0x405ae0'], `call` None -> ['0x4034d0'], `call` None -> ['0x52ff20'], `call` None -> ['0x531b70'], `switch_table` None -> ['0x405aa9', '0x486590']
- Unresolved questions: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

004058d0 <.text+0x48d0>:
  4058d0:	6a ff                	push   0xffffffff
  4058d2:	68 fc 7c 55 00       	push   0x557cfc
  4058d7:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4058dd:	50                   	push   eax
  4058de:	64 89 25 00 00 00 00 	mov    DWORD PTR fs:0x0,esp
  4058e5:	81 ec 38 01 00 00    	sub    esp,0x138
  4058eb:	8b 84 24 50 01 00 00 	mov    eax,DWORD PTR [esp+0x150]
  4058f2:	53                   	push   ebx
  4058f3:	55                   	push   ebp
  4058f4:	56                   	push   esi
  4058f5:	3d f7 79 fe ff       	cmp    eax,0xfffe79f7
  4058fa:	57                   	push   edi
  4058fb:	c6 44 24 10 13       	mov    BYTE PTR [esp+0x10],0x13
  405900:	c6 44 24 11 14       	mov    BYTE PTR [esp+0x11],0x14
  405905:	c6 44 24 12 0f       	mov    BYTE PTR [esp+0x12],0xf
  40590a:	c6 44 24 13 0c       	mov    BYTE PTR [esp+0x13],0xc
  40590f:	c6 44 24 14 10       	mov    BYTE PTR [esp+0x14],0x10
  405914:	c6 44 24 15 ff       	mov    BYTE PTR [esp+0x15],0xff
  405919:	0f 8f 46 02 00 00    	jg     0x405b65
  40591f:	0f 84 bb 01 00 00    	je     0x405ae0
  405925:	05 84 86 01 00       	add    eax,0x18684
  40592a:	83 f8 7a             	cmp    eax,0x7a
  40592d:	0f 87 cb 0c 00 00    	ja     0x4065fe
  405933:	33 c9                	xor    ecx,ecx
  405935:	8a 88 40 66 40 00    	mov    cl,BYTE PTR [eax+0x406640]
  40593b:	ff 24 8d 18 66 40 00 	jmp    DWORD PTR [ecx*4+0x406618]
  405942:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405948:	85 c9                	test   ecx,ecx
  40594a:	0f 84 ae 0c 00 00    	je     0x4065fe
  405950:	e8 cb 33 08 00       	call   0x488d20
  405955:	e9 a4 0c 00 00       	jmp    0x4065fe
  40595a:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  40595f:	85 c0                	test   eax,eax
  405961:	0f 84 97 0c 00 00    	je     0x4065fe
  405967:	8b b0 88 02 00 00    	mov    esi,DWORD PTR [eax+0x288]
  40596d:	85 f6                	test   esi,esi
  40596f:	0f 84 89 0c 00 00    	je     0x4065fe
  405975:	8b 88 90 02 00 00    	mov    ecx,DWORD PTR [eax+0x290]
  40597b:	83 f9 01             	cmp    ecx,0x1
  40597e:	74 2b                	je     0x4059ab
  405980:	83 f9 02             	cmp    ecx,0x2
  405983:	74 26                	je     0x4059ab
  405985:	83 f9 03             	cmp    ecx,0x3
  405988:	74 21                	je     0x4059ab
  40598a:	8b ce                	mov    ecx,esi
  40598c:	89 b0 18 02 00 00    	mov    DWORD PTR [eax+0x218],esi
  405992:	e8 19 ca 0c 00       	call   0x4d23b0
  405997:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  40599d:	6a 01                	push   0x1
  40599f:	6a 01                	push   0x1
  4059a1:	e8 fa f6 07 00       	call   0x4850a0
  4059a6:	e9 53 0c 00 00       	jmp    0x4065fe
  4059ab:	6a 00                	push   0x0
  4059ad:	56                   	push   esi
  4059ae:	c7 80 18 02 00 00 00 	mov    DWORD PTR [eax+0x218],0x0
  4059b5:	00 00 00 
  4059b8:	e8 63 39 0a 00       	call   0x4a9320
  4059bd:	8b 15 70 c6 57 00    	mov    edx,DWORD PTR ds:0x57c670
  4059c3:	83 c4 08             	add    esp,0x8
  4059c6:	8b ce                	mov    ecx,esi
  4059c8:	89 b2 18 02 00 00    	mov    DWORD PTR [edx+0x218],esi
  4059ce:	e8 dd c9 0c 00       	call   0x4d23b0
  4059d3:	e9 26 0c 00 00       	jmp    0x4065fe
  4059d8:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4059de:	85 c9                	test   ecx,ecx
  4059e0:	0f 84 18 0c 00 00    	je     0x4065fe
  4059e6:	8b 81 24 02 00 00    	mov    eax,DWORD PTR [ecx+0x224]
  4059ec:	8b 90 ac 00 00 00    	mov    edx,DWORD PTR [eax+0xac]
  4059f2:	8b 82 c0 00 00 00    	mov    eax,DWORD PTR [edx+0xc0]
  4059f8:	85 c0                	test   eax,eax
  4059fa:	a1 78 16 58 00       	mov    eax,ds:0x581678
  4059ff:	74 05                	je     0x405a06
  405a01:	a1 98 17 58 00       	mov    eax,ds:0x581798
  405a06:	8b 15 4c 2e 58 00    	mov    edx,DWORD PTR ds:0x582e4c
  405a0c:	50                   	push   eax
  405a0d:	52                   	push   edx
  405a0e:	e8 0d 7a 08 00       	call   0x48d420
  405a13:	8b 0d 0c ba 57 00    	mov    ecx,DWORD PTR ds:0x57ba0c
  405a19:	6a 28                	push   0x28
  405a1b:	e8 e0 33 14 00       	call   0x548e00
  405a20:	e9 d9 0b 00 00       	jmp    0x4065fe
  405a25:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405a2b:	85 c9                	test   ecx,ecx
  405a2d:	0f 84 cb 0b 00 00    	je     0x4065fe
  405a33:	a1 4c 2e 58 00       	mov    eax,ds:0x582e4c
  405a38:	8b 15 68 2d 58 00    	mov    edx,DWORD PTR ds:0x582d68
  405a3e:	50                   	push   eax
  405a3f:	52                   	push   edx
  405a40:	e8 db 79 08 00       	call   0x48d420
  405a45:	8b 0d 0c ba 57 00    	mov    ecx,DWORD PTR ds:0x57ba0c
  405a4b:	6a 2b                	push   0x2b
  405a4d:	e8 ae 33 14 00       	call   0x548e00
  405a52:	e9 a7 0b 00 00       	jmp    0x4065fe
  405a57:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405a5d:	85 c9                	test   ecx,ecx
  405a5f:	0f 84 99 0b 00 00    	je     0x4065fe
  405a65:	8b 84 24 64 01 00 00 	mov    eax,DWORD PTR [esp+0x164]
  405a6c:	50                   	push   eax
  405a6d:	e8 fe 60 08 00       	call   0x48bb70
  405a72:	e9 87 0b 00 00       	jmp    0x4065fe
  405a77:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405a7d:	85 c9                	test   ecx,ecx
  405a7f:	0f 84 79 0b 00 00    	je     0x4065fe
  405a85:	e8 16 63 08 00       	call   0x48bda0
  405a8a:	e9 6f 0b 00 00       	jmp    0x4065fe
  405a8f:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405a95:	85 c9                	test   ecx,ecx
  405a97:	0f 84 61 0b 00 00    	je     0x4065fe
  405a9d:	6a ff                	push   0xffffffff
  405a9f:	e8 bc 66 08 00       	call   0x48c160
  405aa4:	e9 55 0b 00 00       	jmp    0x4065fe
  405aa9:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405aaf:	85 c9                	test   ecx,ecx
  405ab1:	74 05                	je     0x405ab8
  405ab3:	e8 d8 0a 08 00       	call   0x486590
  405ab8:	8b 0d 0c ba 57 00    	mov    ecx,DWORD PTR ds:0x57ba0c
  405abe:	e8 0d 34 14 00       	call   0x548ed0
  405ac3:	e9 36 0b 00 00       	jmp    0x4065fe
  405ac8:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405ace:	85 c9                	test   ecx,ecx
  405ad0:	0f 84 28 0b 00 00    	je     0x4065fe
  405ad6:	e8 95 5a 08 00       	call   0x48b570
  405adb:	e9 1e 0b 00 00       	jmp    0x4065fe
  405ae0:	6a 64                	push   0x64
  405ae2:	6a 00                	push   0x0
  405ae4:	c7 44 24 38 15 04 00 	mov    DWORD PTR [esp+0x38],0x415
  405aeb:	00 
  405aec:	c7 44 24 3c 14 04 00 	mov    DWORD PTR [esp+0x3c],0x414
  405af3:	00 
  405af4:	c7 44 24 40 13 04 00 	mov    DWORD PTR [esp+0x40],0x413
  405afb:	00 
  405afc:	c7 44 24 44 12 04 00 	mov    DWORD PTR [esp+0x44],0x412
  405b03:	00 
  405b04:	c7 44 24 48 11 04 00 	mov    DWORD PTR [esp+0x48],0x411
  405b0b:	00 
  405b0c:	e8 bf d9 ff ff       	call   0x4034d0
  405b11:	83 c4 08             	add    esp,0x8
  405b14:	83 f8 4b             	cmp    eax,0x4b
  405b17:	0f 8e e1 0a 00 00    	jle    0x4065fe
  405b1d:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  405b22:	85 c0                	test   eax,eax
  405b24:	0f 84 d4 0a 00 00    	je     0x4065fe
  405b2a:	8b b0 5c 02 00 00    	mov    esi,DWORD PTR [eax+0x25c]
  405b30:	85 f6                	test   esi,esi
  405b32:	0f 84 c6 0a 00 00    	je     0x4065fe
  405b38:	6a 05                	push   0x5
  405b3a:	e8 71 d9 ff ff       	call   0x4034b0
  405b3f:	8b 7c 84 34          	mov    edi,DWORD PTR [esp+eax*4+0x34]
  405b43:	83 c4 04             	add    esp,0x4
  405b46:	8b ce                	mov    ecx,esi
  405b48:	57                   	push   edi
  405b49:	e8 d2 a3 12 00       	call   0x52ff20
  405b4e:	85 c0                	test   eax,eax
  405b50:	0f 84 a8 0a 00 00    	je     0x4065fe
  405b56:	6a 01                	push   0x1
  405b58:	57                   	push   edi
  405b59:	8b ce                	mov    ecx,esi
  405b5b:	e8 10 c0 12 00       	call   0x531b70
  405b60:	e9 99 0a 00 00       	jmp    0x4065fe
  405b65:	83 f8 12             	cmp    eax,0x12
  405b68:	0f 8f 86 09 00 00    	jg     0x4064f4
  405b6e:	0f 84 4a 07 00 00    	je     0x4062be
  405b74:	83 f8 0e             	cmp    eax,0xe
  405b77:	0f 8f 7b 05 00 00    	jg     0x4060f8
  405b7d:	74 4a                	je     0x405bc9
  405b7f:	3d f8 79 fe ff       	cmp    eax,0xfffe79f8
  405b84:	74 27                	je     0x405bad
  405b86:	3d f9 79 fe ff       	cmp    eax,0xfffe79f9
  405b8b:	0f 85 6d 0a 00 00    	jne    0x4065fe
  405b91:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405b97:	85 c9                	test   ecx,ecx
  405b99:	0f 84 5f 0a 00 00    	je     0x4065fe
  405b9f:	6a 01                	push   0x1
  405ba1:	6a 01                	push   0x1
  405ba3:	e8 f8 f4 07 00       	call   0x4850a0
  405ba8:	e9 51 0a 00 00       	jmp    0x4065fe
  405bad:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405bb3:	85 c9                	test   ecx,ecx
  405bb5:	0f 84 43 0a 00 00    	je     0x4065fe
  405bbb:	6a 01                	push   0x1
  405bbd:	6a 04                	push   0x4
  405bbf:	e8 dc f4 07 00       	call   0x4850a0
  405bc4:	e9 35 0a 00 00       	jmp    0x4065fe
  405bc9:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405bcf:	8b bc 24 64 01 00 00 	mov    edi,DWORD PTR [esp+0x164]
  405bd6:	33 ed                	xor    ebp,ebp
  405bd8:	3b cd                	cmp    ecx,ebp
  405bda:	74 6a                	je     0x405c46
  405bdc:	8b b1 68 02 00 00    	mov    esi,DWORD PTR [ecx+0x268]
  405be2:	3b f5                	cmp    esi,ebp
  405be4:	74 60                	je     0x405c46
  405be6:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  405bea:	89 6c 24 18          	mov    DWORD PTR [esp+0x18],ebp
  405bee:	8b 46 48             	mov    eax,DWORD PTR [esi+0x48]
  405bf1:	51                   	push   ecx
  405bf2:	68 a9 79 fe ff       	push   0xfffe79a9
  405bf7:	57                   	push   edi
  405bf8:	56                   	push   esi
  405bf9:	ff d0                	call   eax
  405bfb:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  405bff:	83 c4 10             	add    esp,0x10
  405c02:	3b c5                	cmp    eax,ebp
  405c04:	0f 85 f4 09 00 00    	jne    0x4065fe
  405c0a:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405c10:	a1 08 c6 57 00       	mov    eax,ds:0x57c608
  405c15:	0f be 54 04 10       	movsx  edx,BYTE PTR [esp+eax*1+0x10]
  405c1a:	3b fa                	cmp    edi,edx
  405c1c:	75 31                	jne    0x405c4f
  405c1e:	8a 4c 04 11          	mov    cl,BYTE PTR [esp+eax*1+0x11]
  405c22:	40                   	inc    eax
  405c23:	80 f9 ff             	cmp    cl,0xff
  405c26:	a3 08 c6 57 00       	mov    ds:0x57c608,eax
  405c2b:	0f 85 cd 09 00 00    	jne    0x4065fe
  405c31:	c7 05 b4 c5 57 00 01 	mov    DWORD PTR ds:0x57c5b4,0x1
  405c38:	00 00 00 
  405c3b:	89 2d 08 c6 57 00    	mov    DWORD PTR ds:0x57c608,ebp
  405c41:	e9 b8 09 00 00       	jmp    0x4065fe
  405c46:	8b b4 24 58 01 00 00 	mov    esi,DWORD PTR [esp+0x158]
  405c4d:	eb c1                	jmp    0x405c10
  405c4f:	3b f5                	cmp    esi,ebp
  405c51:	74 26                	je     0x405c79
  405c53:	8b 46 48             	mov    eax,DWORD PTR [esi+0x48]
  405c56:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  405c5a:	51                   	push   ecx
  405c5b:	68 a9 79 fe ff       	push   0xfffe79a9
  405c60:	57                   	push   edi
  405c61:	56                   	push   esi
  405c62:	ff d0                	call   eax
  405c64:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  405c68:	83 c4 10             	add    esp,0x10
  405c6b:	3b c5                	cmp    eax,ebp
  405c6d:	0f 85 8b 09 00 00    	jne    0x4065fe
  405c73:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405c79:	a1 90 df 57 00       	mov    eax,ds:0x57df90
  405c7e:	3b c5                	cmp    eax,ebp
  405c80:	74 10                	je     0x405c92
  405c82:	55                   	push   ebp
  405c83:	6a 0e                	push   0xe
  405c85:	57                   	push   edi
  405c86:	56                   	push   esi
  405c87:	ff 50 48             	call   DWORD PTR [eax+0x48]
  405c8a:	83 c4 10             	add    esp,0x10
  405c8d:	e9 6c 09 00 00       	jmp    0x4065fe
  405c92:	83 ff 10             	cmp    edi,0x10
  405c95:	74 37                	je     0x405cce
  405c97:	81 ff 3f 01 00 00    	cmp    edi,0x13f
  405c9d:	0f 85 f2 00 00 00    	jne    0x405d95
  405ca3:	a1 b4 c5 57 00       	mov    eax,ds:0x57c5b4
  405ca8:	3b c5                	cmp    eax,ebp
  405caa:	0f 84 ea 00 00 00    	je     0x405d9a
  405cb0:	8b 0d 0c ba 57 00    	mov    ecx,DWORD PTR ds:0x57ba0c
  405cb6:	33 d2                	xor    edx,edx
  405cb8:	8a 99 fc 00 00 00    	mov    bl,BYTE PTR [ecx+0xfc]
  405cbe:	84 db                	test   bl,bl
  405cc0:	0f 94 c2             	sete   dl
  405cc3:	52                   	push   edx
  405cc4:	e8 d7 18 14 00       	call   0x5475a0
  405cc9:	e9 c1 00 00 00       	jmp    0x405d8f
  405cce:	39 2d e0 c5 57 00    	cmp    DWORD PTR ds:0x57c5e0,ebp
  405cd4:	0f 84 bb 00 00 00    	je     0x405d95
  405cda:	68 1c 01 00 00       	push   0x11c
  405cdf:	e8 3d 85 14 00       	call   0x54e221
  405ce4:	83 c4 04             	add    esp,0x4
  405ce7:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  405ceb:	3b c5                	cmp    eax,ebp
  405ced:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x1
  405cf4:	01 00 00 00 
  405cf8:	74 17                	je     0x405d11
  405cfa:	6a 02                	push   0x2
  405cfc:	68 58 02 00 00       	push   0x258
  405d01:	68 20 03 00 00       	push   0x320
  405d06:	8b c8                	mov    ecx,eax
  405d08:	e8 23 15 13 00       	call   0x537230
  405d0d:	8b f0                	mov    esi,eax
  405d0f:	eb 02                	jmp    0x405d13
  405d11:	33 f6                	xor    esi,esi
  405d13:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  405d19:	56                   	push   esi
  405d1a:	c7 84 24 54 01 00 00 	mov    DWORD PTR [esp+0x154],0xffffffff
  405d21:	ff ff ff ff 
  405d25:	e8 b6 e0 11 00       	call   0x523de0
  405d2a:	a1 0c c6 57 00       	mov    eax,ds:0x57c60c
  405d2f:	8b c8                	mov    ecx,eax
  405d31:	40                   	inc    eax
  405d32:	a3 0c c6 57 00       	mov    ds:0x57c60c,eax
  405d37:	51                   	push   ecx
  405d38:	8d 44 24 48          	lea    eax,[esp+0x48]
  405d3c:	68 20 3c 56 00       	push   0x563c20
  405d41:	50                   	push   eax
  405d42:	e8 3c 80 14 00       	call   0x54dd83
  405d47:	8d 4c 24 50          	lea    ecx,[esp+0x50]
  405d4b:	68 84 31 56 00       	push   0x563184
  405d50:	51                   	push   ecx
  405d51:	e8 8a 82 14 00       	call   0x54dfe0
  405d56:	83 c4 14             	add    esp,0x14
  405d59:	3b c5                	cmp    eax,ebp
  405d5b:	74 0b                	je     0x405d68
  405d5d:	50                   	push   eax
  405d5e:	e8 81 81 14 00       	call   0x54dee4
  405d63:	83 c4 04             	add    esp,0x4
  405d66:	eb c2                	jmp    0x405d2a
  405d68:	a1 c8 c5 57 00       	mov    eax,ds:0x57c5c8
  405d6d:	8d 54 24 44          	lea    edx,[esp+0x44]
  405d71:	52                   	push   edx
  405d72:	6a 01                	push   0x1
  405d74:	50                   	push   eax
  405d75:	8b ce                	mov    ecx,esi
  405d77:	e8 74 1a 13 00       	call   0x5377f0
  405d7c:	55                   	push   ebp
  405d7d:	ff 15 5c c2 55 00    	call   DWORD PTR ds:0x55c25c
  405d83:	3b f5                	cmp    esi,ebp
  405d85:	74 08                	je     0x405d8f
  405d87:	8b 16                	mov    edx,DWORD PTR [esi]
  405d89:	6a 01                	push   0x1
  405d8b:	8b ce                	mov    ecx,esi
  405d8d:	ff 12                	call   DWORD PTR [edx]
  405d8f:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405d95:	a1 b4 c5 57 00       	mov    eax,ds:0x57c5b4
  405d9a:	3b cd                	cmp    ecx,ebp
  405d9c:	0f 84 5c 08 00 00    	je     0x4065fe
  405da2:	81 ff 31 01 00 00    	cmp    edi,0x131
  405da8:	0f 8f 58 01 00 00    	jg     0x405f06
  405dae:	0f 84 70 01 00 00    	je     0x405f24
  405db4:	8d 77 fe             	lea    esi,[edi-0x2]
  405db7:	83 fe 6b             	cmp    esi,0x6b
  405dba:	0f 87 3e 08 00 00    	ja     0x4065fe
  405dc0:	33 d2                	xor    edx,edx
  405dc2:	8a 96 e0 66 40 00    	mov    dl,BYTE PTR [esi+0x4066e0]
  405dc8:	ff 24 95 bc 66 40 00 	jmp    DWORD PTR [edx*4+0x4066bc]
  405dcf:	83 b9 90 02 00 00 04 	cmp    DWORD PTR [ecx+0x290],0x4
  405dd6:	0f 85 22 08 00 00    	jne    0x4065fe
  405ddc:	83 b9 a8 02 00 00 03 	cmp    DWORD PTR [ecx+0x2a8],0x3
  405de3:	0f 85 15 08 00 00    	jne    0x4065fe
  405de9:	6a 01                	push   0x1
  405deb:	e8 b0 71 08 00       	call   0x48cfa0
  405df0:	e9 09 08 00 00       	jmp    0x4065fe
  405df5:	55                   	push   ebp
  405df6:	e8 c5 46 08 00       	call   0x48a4c0
  405dfb:	e9 fe 07 00 00       	jmp    0x4065fe
  405e00:	e8 db 5c 08 00       	call   0x48bae0
  405e05:	e9 f4 07 00 00       	jmp    0x4065fe
  405e0a:	3b c5                	cmp    eax,ebp
  405e0c:	0f 84 ec 07 00 00    	je     0x4065fe
  405e12:	8b 81 24 02 00 00    	mov    eax,DWORD PTR [ecx+0x224]
  405e18:	8b 88 a8 00 00 00    	mov    ecx,DWORD PTR [eax+0xa8]
  405e1e:	8a 41 04             	mov    al,BYTE PTR [ecx+0x4]
  405e21:	84 c0                	test   al,al
  405e23:	0f 85 d5 07 00 00    	jne    0x4065fe
  405e29:	6a ff                	push   0xffffffff
  405e2b:	6a ff                	push   0xffffffff
  405e2d:	6a ff                	push   0xffffffff
  405e2f:	6a ff                	push   0xffffffff
  405e31:	6a ff                	push   0xffffffff
  405e33:	6a ff                	push   0xffffffff
  405e35:	6a ff                	push   0xffffffff
  405e37:	e8 a4 ce 0f 00       	call   0x502ce0
  405e3c:	a1 fc c5 57 00       	mov    eax,ds:0x57c5fc
  405e41:	40                   	inc    eax
  405e42:	83 f8 23             	cmp    eax,0x23
  405e45:	a3 fc c5 57 00       	mov    ds:0x57c5fc,eax
  405e4a:	7e 06                	jle    0x405e52
  405e4c:	89 2d fc c5 57 00    	mov    DWORD PTR ds:0x57c5fc,ebp
  405e52:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  405e57:	8b 15 4c 2e 58 00    	mov    edx,DWORD PTR ds:0x582e4c
  405e5d:	52                   	push   edx
  405e5e:	8b 88 24 02 00 00    	mov    ecx,DWORD PTR [eax+0x224]
  405e64:	05 04 03 00 00       	add    eax,0x304
  405e69:	8b b1 a8 00 00 00    	mov    esi,DWORD PTR [ecx+0xa8]
  405e6f:	8b 0d 60 0d 58 00    	mov    ecx,DWORD PTR ds:0x580d60
  405e75:	51                   	push   ecx
  405e76:	55                   	push   ebp
  405e77:	6a ff                	push   0xffffffff
  405e79:	6a ff                	push   0xffffffff
  405e7b:	6a 01                	push   0x1
  405e7d:	6a 21                	push   0x21
  405e7f:	50                   	push   eax
  405e80:	e8 8b 4b 14 00       	call   0x54aa10
  405e85:	89 46 64             	mov    DWORD PTR [esi+0x64],eax
  405e88:	8b 15 70 c6 57 00    	mov    edx,DWORD PTR ds:0x57c670
  405e8e:	83 c4 20             	add    esp,0x20
  405e91:	8b 82 24 02 00 00    	mov    eax,DWORD PTR [edx+0x224]
  405e97:	8b 88 a8 00 00 00    	mov    ecx,DWORD PTR [eax+0xa8]
  405e9d:	c6 41 04 01          	mov    BYTE PTR [ecx+0x4],0x1
  405ea1:	e9 58 07 00 00       	jmp    0x4065fe
  405ea6:	3b c5                	cmp    eax,ebp
  405ea8:	0f 84 50 07 00 00    	je     0x4065fe
  405eae:	8b 91 24 02 00 00    	mov    edx,DWORD PTR [ecx+0x224]
  405eb4:	55                   	push   ebp
  405eb5:	6a ff                	push   0xffffffff
  405eb7:	6a ff                	push   0xffffffff
  405eb9:	8b 8a a8 00 00 00    	mov    ecx,DWORD PTR [edx+0xa8]
  405ebf:	e8 4c d0 0f 00       	call   0x502f10
  405ec4:	e9 35 07 00 00       	jmp    0x4065fe
  405ec9:	3b c5                	cmp    eax,ebp
  405ecb:	0f 84 2d 07 00 00    	je     0x4065fe
  405ed1:	e8 5a cc 07 00       	call   0x482b30
  405ed6:	e9 23 07 00 00       	jmp    0x4065fe
  405edb:	e8 c0 c2 09 00       	call   0x4a21a0
  405ee0:	e9 19 07 00 00       	jmp    0x4065fe
  405ee5:	3b c5                	cmp    eax,ebp
  405ee7:	0f 84 11 07 00 00    	je     0x4065fe
  405eed:	8b 81 24 02 00 00    	mov    eax,DWORD PTR [ecx+0x224]
  405ef3:	6a 01                	push   0x1
  405ef5:	55                   	push   ebp
  405ef6:	8b 88 ac 00 00 00    	mov    ecx,DWORD PTR [eax+0xac]
  405efc:	e8 cf 00 0f 00       	call   0x4f5fd0
  405f01:	e9 f8 06 00 00       	jmp    0x4065fe
  405f06:	8d b7 cd fe ff ff    	lea    esi,[edi-0x133]
  405f0c:	83 fe 5e             	cmp    esi,0x5e
  405f0f:	0f 87 e9 06 00 00    	ja     0x4065fe
  405f15:	33 d2                	xor    edx,edx
  405f17:	8a 96 70 67 40 00    	mov    dl,BYTE PTR [esi+0x406770]
  405f1d:	ff 24 95 4c 67 40 00 	jmp    DWORD PTR [edx*4+0x40674c]
  405f24:	8b 81 90 02 00 00    	mov    eax,DWORD PTR [ecx+0x290]
  405f2a:	83 f8 01             	cmp    eax,0x1
  405f2d:	74 0e                	je     0x405f3d
  405f2f:	83 f8 03             	cmp    eax,0x3
  405f32:	74 09                	je     0x405f3d
  405f34:	83 f8 02             	cmp    eax,0x2
  405f37:	0f 85 c1 06 00 00    	jne    0x4065fe
  405f3d:	8b 81 9c 00 00 00    	mov    eax,DWORD PTR [ecx+0x9c]
  405f43:	3b c5                	cmp    eax,ebp
  405f45:	75 28                	jne    0x405f6f
  405f47:	8b 81 ec 02 00 00    	mov    eax,DWORD PTR [ecx+0x2ec]
  405f4d:	55                   	push   ebp
  405f4e:	55                   	push   ebp
  405f4f:	8b 8c 81 00 02 00 00 	mov    ecx,DWORD PTR [ecx+eax*4+0x200]
  405f56:	81 c1 48 01 00 00    	add    ecx,0x148
  405f5c:	e8 8f b8 ff ff       	call   0x4017f0
  405f61:	3b c5                	cmp    eax,ebp
  405f63:	0f 84 95 06 00 00    	je     0x4065fe
  405f69:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405f6f:	8b b0 f0 16 00 00    	mov    esi,DWORD PTR [eax+0x16f0]
  405f75:	3b f5                	cmp    esi,ebp
  405f77:	0f 84 81 06 00 00    	je     0x4065fe
  405f7d:	55                   	push   ebp
  405f7e:	56                   	push   esi
  405f7f:	89 a9 18 02 00 00    	mov    DWORD PTR [ecx+0x218],ebp
  405f85:	e8 96 33 0a 00       	call   0x4a9320
  405f8a:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  405f90:	83 c4 08             	add    esp,0x8
  405f93:	89 b1 18 02 00 00    	mov    DWORD PTR [ecx+0x218],esi
  405f99:	8b ce                	mov    ecx,esi
  405f9b:	e8 10 c4 0c 00       	call   0x4d23b0
  405fa0:	e9 59 06 00 00       	jmp    0x4065fe
  405fa5:	8b 81 90 02 00 00    	mov    eax,DWORD PTR [ecx+0x290]
  405fab:	83 f8 08             	cmp    eax,0x8
  405fae:	0f 8d 4a 06 00 00    	jge    0x4065fe
  405fb4:	83 f8 01             	cmp    eax,0x1
  405fb7:	0f 84 41 06 00 00    	je     0x4065fe
  405fbd:	55                   	push   ebp
  405fbe:	6a 01                	push   0x1
  405fc0:	e8 db f0 07 00       	call   0x4850a0
  405fc5:	e9 34 06 00 00       	jmp    0x4065fe
  405fca:	8b 81 90 02 00 00    	mov    eax,DWORD PTR [ecx+0x290]
  405fd0:	83 f8 08             	cmp    eax,0x8
  405fd3:	0f 8d 25 06 00 00    	jge    0x4065fe
  405fd9:	8b 91 ec 02 00 00    	mov    edx,DWORD PTR [ecx+0x2ec]
  405fdf:	8b 94 91 00 02 00 00 	mov    edx,DWORD PTR [ecx+edx*4+0x200]
  405fe6:	39 aa 5c 01 00 00    	cmp    DWORD PTR [edx+0x15c],ebp
  405fec:	0f 8e 0c 06 00 00    	jle    0x4065fe
  405ff2:	83 f8 04             	cmp    eax,0x4
  405ff5:	0f 84 03 06 00 00    	je     0x4065fe
  405ffb:	55                   	push   ebp
  405ffc:	6a 04                	push   0x4
  405ffe:	e8 9d f0 07 00       	call   0x4850a0
  406003:	e9 f6 05 00 00       	jmp    0x4065fe
  406008:	8b 81 90 02 00 00    	mov    eax,DWORD PTR [ecx+0x290]
  40600e:	83 f8 08             	cmp    eax,0x8
  406011:	0f 8d e7 05 00 00    	jge    0x4065fe
  406017:	83 f8 05             	cmp    eax,0x5
  40601a:	0f 84 de 05 00 00    	je     0x4065fe
  406020:	55                   	push   ebp
  406021:	6a 05                	push   0x5
  406023:	e8 78 f0 07 00       	call   0x4850a0
  406028:	e9 d1 05 00 00       	jmp    0x4065fe
  40602d:	8b 81 90 02 00 00    	mov    eax,DWORD PTR [ecx+0x290]
  406033:	83 f8 08             	cmp    eax,0x8
  406036:	0f 8d c2 05 00 00    	jge    0x4065fe
  40603c:	83 f8 06             	cmp    eax,0x6
  40603f:	0f 84 b9 05 00 00    	je     0x4065fe
  406045:	55                   	push   ebp
  406046:	6a 06                	push   0x6
  406048:	e8 53 f0 07 00       	call   0x4850a0
  40604d:	e9 ac 05 00 00       	jmp    0x4065fe
  406052:	8b 81 90 02 00 00    	mov    eax,DWORD PTR [ecx+0x290]
  406058:	83 f8 08             	cmp    eax,0x8
  40605b:	0f 8d 9d 05 00 00    	jge    0x4065fe
  406061:	83 f8 07             	cmp    eax,0x7
  406064:	0f 84 94 05 00 00    	je     0x4065fe
  40606a:	55                   	push   ebp
  40606b:	6a 07                	push   0x7
  40606d:	e8 2e f0 07 00       	call   0x4850a0
  406072:	e9 87 05 00 00       	jmp    0x4065fe
  406077:	3b c5                	cmp    eax,ebp
  406079:	0f 84 7f 05 00 00    	je     0x4065fe
  40607f:	8b 89 94 00 00 00    	mov    ecx,DWORD PTR [ecx+0x94]
  406085:	8b 41 14             	mov    eax,DWORD PTR [ecx+0x14]
  406088:	2d 35 0c 00 00       	sub    eax,0xc35
  40608d:	f7 d8                	neg    eax
  40608f:	1b c0                	sbb    eax,eax
  406091:	25 d1 0b 00 00       	and    eax,0xbd1
  406096:	83 c0 64             	add    eax,0x64
  406099:	89 41 14             	mov    DWORD PTR [ecx+0x14],eax
  40609c:	e9 5d 05 00 00       	jmp    0x4065fe
  4060a1:	3b c5                	cmp    eax,ebp
  4060a3:	8b 81 08 15 00 00    	mov    eax,DWORD PTR [ecx+0x1508]
  4060a9:	74 18                	je     0x4060c3
  4060ab:	3b c5                	cmp    eax,ebp
  4060ad:	74 0a                	je     0x4060b9
  4060af:	e8 6c 2c 08 00       	call   0x488d20
  4060b4:	e9 45 05 00 00       	jmp    0x4065fe
  4060b9:	e8 02 2c 08 00       	call   0x488cc0
  4060be:	e9 3b 05 00 00       	jmp    0x4065fe
  4060c3:	3b c5                	cmp    eax,ebp
  4060c5:	0f 85 33 05 00 00    	jne    0x4065fe
  4060cb:	e8 f0 2b 08 00       	call   0x488cc0
  4060d0:	8b 0d e8 27 58 00    	mov    ecx,DWORD PTR ds:0x5827e8
  4060d6:	8b 15 4c 2e 58 00    	mov    edx,DWORD PTR ds:0x582e4c
  4060dc:	51                   	push   ecx
  4060dd:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4060e3:	52                   	push   edx
  4060e4:	c7 05 c0 c5 57 00 08 	mov    DWORD PTR ds:0x57c5c0,0x8
  4060eb:	00 00 00 
  4060ee:	e8 cd 73 08 00       	call   0x48d4c0
  4060f3:	e9 06 05 00 00       	jmp    0x4065fe
  4060f8:	83 f8 0f             	cmp    eax,0xf
  4060fb:	0f 85 fd 04 00 00    	jne    0x4065fe
  406101:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  406106:	33 ed                	xor    ebp,ebp
  406108:	3b c5                	cmp    eax,ebp
  40610a:	0f 84 ee 04 00 00    	je     0x4065fe
  406110:	8b 88 90 02 00 00    	mov    ecx,DWORD PTR [eax+0x290]
  406116:	8b b4 24 64 01 00 00 	mov    esi,DWORD PTR [esp+0x164]
  40611d:	83 f9 05             	cmp    ecx,0x5
  406120:	75 37                	jne    0x406159
  406122:	8b 8c 88 98 02 00 00 	mov    ecx,DWORD PTR [eax+ecx*4+0x298]
  406129:	83 f9 02             	cmp    ecx,0x2
  40612c:	74 05                	je     0x406133
  40612e:	83 f9 07             	cmp    ecx,0x7
  406131:	75 26                	jne    0x406159
  406133:	8b 88 64 02 00 00    	mov    ecx,DWORD PTR [eax+0x264]
  406139:	3b cd                	cmp    ecx,ebp
  40613b:	74 1c                	je     0x406159
  40613d:	8a 15 e6 c5 57 00    	mov    dl,BYTE PTR ds:0x57c5e6
  406143:	84 d2                	test   dl,dl
  406145:	74 12                	je     0x406159
  406147:	56                   	push   esi
  406148:	6a 23                	push   0x23
  40614a:	68 94 79 fe ff       	push   0xfffe7994
  40614f:	e8 6c a0 12 00       	call   0x5301c0
  406154:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  406159:	8b 88 90 02 00 00    	mov    ecx,DWORD PTR [eax+0x290]
  40615f:	83 f9 04             	cmp    ecx,0x4
  406162:	0f 85 96 04 00 00    	jne    0x4065fe
  406168:	8b 8c 88 98 02 00 00 	mov    ecx,DWORD PTR [eax+ecx*4+0x298]
  40616f:	83 f9 03             	cmp    ecx,0x3
  406172:	74 0d                	je     0x406181
  406174:	83 b8 d8 02 00 00 0b 	cmp    DWORD PTR [eax+0x2d8],0xb
  40617b:	0f 85 7d 04 00 00    	jne    0x4065fe
  406181:	39 a8 5c 03 00 00    	cmp    DWORD PTR [eax+0x35c],ebp
  406187:	74 0b                	je     0x406194
  406189:	89 a8 5c 03 00 00    	mov    DWORD PTR [eax+0x35c],ebp
  40618f:	e9 6a 04 00 00       	jmp    0x4065fe
  406194:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  406197:	8b 88 4c 03 00 00    	mov    ecx,DWORD PTR [eax+0x34c]
  40619d:	8b 98 48 03 00 00    	mov    ebx,DWORD PTR [eax+0x348]
  4061a3:	52                   	push   edx
  4061a4:	8b 16                	mov    edx,DWORD PTR [esi]
  4061a6:	89 4c 24 24          	mov    DWORD PTR [esp+0x24],ecx
  4061aa:	52                   	push   edx
  4061ab:	6a 01                	push   0x1
  4061ad:	6a 01                	push   0x1
  4061af:	51                   	push   ecx
  4061b0:	53                   	push   ebx
  4061b1:	8b c8                	mov    ecx,eax
  4061b3:	e8 c8 2f 08 00       	call   0x489180
  4061b8:	85 c0                	test   eax,eax
  4061ba:	0f 84 3e 04 00 00    	je     0x4065fe
  4061c0:	6a 24                	push   0x24
  4061c2:	e8 5a 80 14 00       	call   0x54e221
  4061c7:	83 c4 04             	add    esp,0x4
  4061ca:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  4061ce:	3b c5                	cmp    eax,ebp
  4061d0:	89 ac 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],ebp
  4061d7:	74 1d                	je     0x4061f6
  4061d9:	8b 15 70 c6 57 00    	mov    edx,DWORD PTR ds:0x57c670
  4061df:	8b c8                	mov    ecx,eax
  4061e1:	8b b2 54 03 00 00    	mov    esi,DWORD PTR [edx+0x354]
  4061e7:	8b 92 44 03 00 00    	mov    edx,DWORD PTR [edx+0x344]
  4061ed:	56                   	push   esi
  4061ee:	52                   	push   edx
  4061ef:	e8 6c fb 0d 00       	call   0x4e5d60
  4061f4:	8b e8                	mov    ebp,eax
  4061f6:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4061fb:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  406202:	ff ff ff ff 
  406206:	8b 88 d8 02 00 00    	mov    ecx,DWORD PTR [eax+0x2d8]
  40620c:	8b b0 fc 02 00 00    	mov    esi,DWORD PTR [eax+0x2fc]
  406212:	8b b8 9c 00 00 00    	mov    edi,DWORD PTR [eax+0x9c]
  406218:	83 f9 0b             	cmp    ecx,0xb
  40621b:	74 2d                	je     0x40624a
  40621d:	8b 88 ec 02 00 00    	mov    ecx,DWORD PTR [eax+0x2ec]
  406223:	6a ff                	push   0xffffffff
  406225:	6a 00                	push   0x0
  406227:	8b 84 88 00 02 00 00 	mov    eax,DWORD PTR [eax+ecx*4+0x200]
  40622e:	8b c8                	mov    ecx,eax
  406230:	e8 8b 7a 0d 00       	call   0x4ddcc0
  406235:	50                   	push   eax
  406236:	8b cd                	mov    ecx,ebp
  406238:	e8 b3 01 0e 00       	call   0x4e63f0
  40623d:	51                   	push   ecx
  40623e:	8b cf                	mov    ecx,edi
  406240:	d9 1c 24             	fstp   DWORD PTR [esp]
  406243:	6a 04                	push   0x4
  406245:	e8 f6 1b 07 00       	call   0x477e40
  40624a:	8b 54 24 20          	mov    edx,DWORD PTR [esp+0x20]
  40624e:	8b cf                	mov    ecx,edi
  406250:	52                   	push   edx
  406251:	53                   	push   ebx
  406252:	55                   	push   ebp
  406253:	e8 88 7e 07 00       	call   0x47e0e0
  406258:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  40625c:	8b ce                	mov    ecx,esi
  40625e:	50                   	push   eax
  40625f:	53                   	push   ebx
  406260:	e8 4b 92 0e 00       	call   0x4ef4b0
  406265:	8b 4e 68             	mov    ecx,DWORD PTR [esi+0x68]
  406268:	6a 01                	push   0x1
  40626a:	51                   	push   ecx
  40626b:	50                   	push   eax
  40626c:	8b ce                	mov    ecx,esi
  40626e:	e8 bd 70 0e 00       	call   0x4ed330
  406273:	6a 01                	push   0x1
  406275:	57                   	push   edi
  406276:	8b ce                	mov    ecx,esi
  406278:	e8 d3 cb 0e 00       	call   0x4f2e50
  40627d:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  406283:	55                   	push   ebp
  406284:	57                   	push   edi
  406285:	e8 36 39 08 00       	call   0x489bc0
  40628a:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  40628f:	83 b8 d8 02 00 00 0b 	cmp    DWORD PTR [eax+0x2d8],0xb
  406296:	0f 85 62 03 00 00    	jne    0x4065fe
  40629c:	c7 80 44 03 00 00 ff 	mov    DWORD PTR [eax+0x344],0xffffffff
  4062a3:	ff ff ff 
  4062a6:	c7 46 60 00 00 00 00 	mov    DWORD PTR [esi+0x60],0x0
  4062ad:	8b 15 70 c6 57 00    	mov    edx,DWORD PTR ds:0x57c670
  4062b3:	89 aa 20 02 00 00    	mov    DWORD PTR [edx+0x220],ebp
  4062b9:	e9 40 03 00 00       	jmp    0x4065fe
  4062be:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  4062c4:	85 c9                	test   ecx,ecx
  4062c6:	0f 84 32 03 00 00    	je     0x4065fe
  4062cc:	8b 81 90 02 00 00    	mov    eax,DWORD PTR [ecx+0x290]
  4062d2:	83 e8 04             	sub    eax,0x4
  4062d5:	0f 84 59 01 00 00    	je     0x406434
  4062db:	48                   	dec    eax
  4062dc:	0f 85 1c 03 00 00    	jne    0x4065fe
  4062e2:	a1 e0 c5 57 00       	mov    eax,ds:0x57c5e0
  4062e7:	8b 9c 24 64 01 00 00 	mov    ebx,DWORD PTR [esp+0x164]
  4062ee:	8b 90 14 83 00 00    	mov    edx,DWORD PTR [eax+0x8314]
  4062f4:	85 d2                	test   edx,edx
  4062f6:	74 20                	je     0x406318
  4062f8:	81 3b 44 02 00 00    	cmp    DWORD PTR [ebx],0x244
  4062fe:	7d 0d                	jge    0x40630d
  406300:	81 7b 04 b4 00 00 00 	cmp    DWORD PTR [ebx+0x4],0xb4
  406307:	7d 04                	jge    0x40630d
  406309:	33 c0                	xor    eax,eax
  40630b:	eb 05                	jmp    0x406312
  40630d:	b8 01 00 00 00       	mov    eax,0x1
  406312:	50                   	push   eax
  406313:	e8 c8 67 08 00       	call   0x48cae0
  406318:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  40631e:	8b b1 14 83 00 00    	mov    esi,DWORD PTR [ecx+0x8314]
  406324:	85 f6                	test   esi,esi
  406326:	0f 84 94 00 00 00    	je     0x4063c0
  40632c:	8d 54 24 24          	lea    edx,[esp+0x24]
  406330:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  406334:	52                   	push   edx
  406335:	50                   	push   eax
  406336:	e8 95 17 12 00       	call   0x527ad0
  40633b:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  406341:	e8 6a 17 12 00       	call   0x527ab0
  406346:	8b f8                	mov    edi,eax
  406348:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  40634d:	83 b8 90 02 00 00 05 	cmp    DWORD PTR [eax+0x290],0x5
  406354:	75 6a                	jne    0x4063c0
  406356:	8b 88 a0 00 00 00    	mov    ecx,DWORD PTR [eax+0xa0]
  40635c:	8b 54 24 24          	mov    edx,DWORD PTR [esp+0x24]
  406360:	8b 41 18             	mov    eax,DWORD PTR [ecx+0x18]
  406363:	8b ce                	mov    ecx,esi
  406365:	50                   	push   eax
  406366:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  40636a:	52                   	push   edx
  40636b:	50                   	push   eax
  40636c:	e8 af 73 13 00       	call   0x53d720
  406371:	85 c0                	test   eax,eax
  406373:	74 27                	je     0x40639c
  406375:	83 ff 01             	cmp    edi,0x1
  406378:	75 19                	jne    0x406393
  40637a:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  406380:	e8 1b 17 12 00       	call   0x527aa0
  406385:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  40638b:	6a 00                	push   0x0
  40638d:	50                   	push   eax
  40638e:	e8 ed 16 12 00       	call   0x527a80
  406393:	c6 05 e6 c5 57 00 01 	mov    BYTE PTR ds:0x57c5e6,0x1
  40639a:	eb 24                	jmp    0x4063c0
  40639c:	85 ff                	test   edi,edi
  40639e:	75 19                	jne    0x4063b9
  4063a0:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  4063a6:	e8 f5 16 12 00       	call   0x527aa0
  4063ab:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  4063b1:	6a 01                	push   0x1
  4063b3:	50                   	push   eax
  4063b4:	e8 c7 16 12 00       	call   0x527a80
  4063b9:	c6 05 e6 c5 57 00 00 	mov    BYTE PTR ds:0x57c5e6,0x0
  4063c0:	a0 e4 c5 57 00       	mov    al,ds:0x57c5e4
  4063c5:	3c 01                	cmp    al,0x1
  4063c7:	8b 03                	mov    eax,DWORD PTR [ebx]
  4063c9:	75 2e                	jne    0x4063f9
  4063cb:	3d 53 02 00 00       	cmp    eax,0x253
  4063d0:	0f 8e 28 02 00 00    	jle    0x4065fe
  4063d6:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  4063dc:	68 f1 d8 ff ff       	push   0xffffd8f1
  4063e1:	68 f1 d8 ff ff       	push   0xffffd8f1
  4063e6:	6a 00                	push   0x0
  4063e8:	e8 23 16 12 00       	call   0x527a10
  4063ed:	c6 05 e4 c5 57 00 00 	mov    BYTE PTR ds:0x57c5e4,0x0
  4063f4:	e9 05 02 00 00       	jmp    0x4065fe
  4063f9:	3d 53 02 00 00       	cmp    eax,0x253
  4063fe:	0f 8d fa 01 00 00    	jge    0x4065fe
  406404:	a0 e5 c5 57 00       	mov    al,ds:0x57c5e5
  406409:	84 c0                	test   al,al
  40640b:	0f 85 ed 01 00 00    	jne    0x4065fe
  406411:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  406417:	68 f1 d8 ff ff       	push   0xffffd8f1
  40641c:	68 f1 d8 ff ff       	push   0xffffd8f1
  406421:	6a 01                	push   0x1
  406423:	e8 e8 15 12 00       	call   0x527a10
  406428:	c6 05 e4 c5 57 00 01 	mov    BYTE PTR ds:0x57c5e4,0x1
  40642f:	e9 ca 01 00 00       	jmp    0x4065fe
  406434:	83 b9 a8 02 00 00 03 	cmp    DWORD PTR [ecx+0x2a8],0x3
  40643b:	74 0d                	je     0x40644a
  40643d:	83 b9 d8 02 00 00 0b 	cmp    DWORD PTR [ecx+0x2d8],0xb
  406444:	0f 85 b4 01 00 00    	jne    0x4065fe
  40644a:	8b 89 40 02 00 00    	mov    ecx,DWORD PTR [ecx+0x240]
  406450:	e8 cb ae ff ff       	call   0x401320
  406455:	8b b4 24 64 01 00 00 	mov    esi,DWORD PTR [esp+0x164]
  40645c:	6a ff                	push   0xffffffff
  40645e:	6a ff                	push   0xffffffff
  406460:	6a 00                	push   0x0
  406462:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  406465:	8b 16                	mov    edx,DWORD PTR [esi]
  406467:	6a 00                	push   0x0
  406469:	51                   	push   ecx
  40646a:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  406470:	52                   	push   edx
  406471:	e8 0a 2d 08 00       	call   0x489180
  406476:	85 c0                	test   eax,eax
  406478:	74 58                	je     0x4064d2
  40647a:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  40647d:	8d 44 24 28          	lea    eax,[esp+0x28]
  406481:	6a 00                	push   0x0
  406483:	8d 4c 24 30          	lea    ecx,[esp+0x30]
  406487:	50                   	push   eax
  406488:	8b 06                	mov    eax,DWORD PTR [esi]
  40648a:	51                   	push   ecx
  40648b:	8b 0d 70 c6 57 00    	mov    ecx,DWORD PTR ds:0x57c670
  406491:	52                   	push   edx
  406492:	50                   	push   eax
  406493:	8b 89 fc 02 00 00    	mov    ecx,DWORD PTR [ecx+0x2fc]
  406499:	e8 f2 e9 0e 00       	call   0x4f4e90
  40649e:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4064a3:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  4064a7:	39 88 48 03 00 00    	cmp    DWORD PTR [eax+0x348],ecx
  4064ad:	75 0e                	jne    0x4064bd
  4064af:	8b 90 4c 03 00 00    	mov    edx,DWORD PTR [eax+0x34c]
  4064b5:	8b 74 24 28          	mov    esi,DWORD PTR [esp+0x28]
  4064b9:	3b d6                	cmp    edx,esi
  4064bb:	74 1a                	je     0x4064d7
  4064bd:	89 88 48 03 00 00    	mov    DWORD PTR [eax+0x348],ecx
  4064c3:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4064c8:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4064cc:	89 88 4c 03 00 00    	mov    DWORD PTR [eax+0x34c],ecx
  4064d2:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4064d7:	8b 88 40 02 00 00    	mov    ecx,DWORD PTR [eax+0x240]
  4064dd:	e8 5e ae ff ff       	call   0x401340
  4064e2:	8b 15 ac c5 57 00    	mov    edx,DWORD PTR ds:0x57c5ac
  4064e8:	52                   	push   edx
  4064e9:	ff 15 94 c0 55 00    	call   DWORD PTR ds:0x55c094
  4064ef:	e9 0a 01 00 00       	jmp    0x4065fe
  4064f4:	83 e8 15             	sub    eax,0x15
  4064f7:	74 3c                	je     0x406535
  4064f9:	83 e8 02             	sub    eax,0x2
  4064fc:	74 26                	je     0x406524
  4064fe:	83 e8 09             	sub    eax,0x9
  406501:	0f 85 f7 00 00 00    	jne    0x4065fe
  406507:	a1 0c b4 56 00       	mov    eax,ds:0x56b40c
  40650c:	85 c0                	test   eax,eax
  40650e:	0f 85 ea 00 00 00    	jne    0x4065fe
  406514:	8b 0d 0c ba 57 00    	mov    ecx,DWORD PTR ds:0x57ba0c
  40651a:	e8 51 19 14 00       	call   0x547e70
  40651f:	e9 da 00 00 00       	jmp    0x4065fe
  406524:	a1 d8 c0 57 00       	mov    eax,ds:0x57c0d8
  406529:	50                   	push   eax
  40652a:	ff 15 94 c0 55 00    	call   DWORD PTR ds:0x55c094
  406530:	e9 c9 00 00 00       	jmp    0x4065fe
  406535:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  40653a:	85 c0                	test   eax,eax
  40653c:	0f 84 bc 00 00 00    	je     0x4065fe
  406542:	83 b8 90 02 00 00 05 	cmp    DWORD PTR [eax+0x290],0x5
  406549:	0f 85 af 00 00 00    	jne    0x4065fe
  40654f:	80 3d 70 38 56 00 01 	cmp    BYTE PTR ds:0x563870,0x1
  406556:	0f 85 9b 00 00 00    	jne    0x4065f7
  40655c:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  406562:	8b 99 14 83 00 00    	mov    ebx,DWORD PTR [ecx+0x8314]
  406568:	85 db                	test   ebx,ebx
  40656a:	0f 84 8e 00 00 00    	je     0x4065fe
  406570:	e8 2b 15 12 00       	call   0x527aa0
  406575:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  40657b:	8b f0                	mov    esi,eax
  40657d:	46                   	inc    esi
  40657e:	83 e6 07             	and    esi,0x7
  406581:	e8 2a 15 12 00       	call   0x527ab0
  406586:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  40658c:	8b f8                	mov    edi,eax
  40658e:	57                   	push   edi
  40658f:	56                   	push   esi
  406590:	e8 eb 14 12 00       	call   0x527a80
  406595:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  406599:	8d 54 24 1c          	lea    edx,[esp+0x1c]
  40659d:	51                   	push   ecx
  40659e:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  4065a4:	52                   	push   edx
  4065a5:	e8 26 15 12 00       	call   0x527ad0
  4065aa:	a1 70 c6 57 00       	mov    eax,ds:0x57c670
  4065af:	8b 54 24 24          	mov    edx,DWORD PTR [esp+0x24]
  4065b3:	8b 88 a0 00 00 00    	mov    ecx,DWORD PTR [eax+0xa0]
  4065b9:	8b 41 18             	mov    eax,DWORD PTR [ecx+0x18]
  4065bc:	8b cb                	mov    ecx,ebx
  4065be:	50                   	push   eax
  4065bf:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4065c3:	52                   	push   edx
  4065c4:	50                   	push   eax
  4065c5:	e8 56 71 13 00       	call   0x53d720
  4065ca:	85 c0                	test   eax,eax
  4065cc:	74 15                	je     0x4065e3
  4065ce:	83 ff 01             	cmp    edi,0x1
  4065d1:	75 2b                	jne    0x4065fe
  4065d3:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  4065d9:	6a 00                	push   0x0
  4065db:	56                   	push   esi
  4065dc:	e8 9f 14 12 00       	call   0x527a80
  4065e1:	eb 1b                	jmp    0x4065fe
  4065e3:	85 ff                	test   edi,edi
  4065e5:	75 17                	jne    0x4065fe
  4065e7:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  4065ed:	6a 01                	push   0x1
  4065ef:	56                   	push   esi
  4065f0:	e8 8b 14 12 00       	call   0x527a80
  4065f5:	eb 07                	jmp    0x4065fe
  4065f7:	c6 05 70 38 56 00 01 	mov    BYTE PTR ds:0x563870,0x1
  4065fe:	8b 8c 24 48 01 00 00 	mov    ecx,DWORD PTR [esp+0x148]
  406605:	5f                   	pop    edi
  406606:	5e                   	pop    esi
  406607:	5d                   	pop    ebp
  406608:	5b                   	pop    ebx
  406609:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  406610:	81 c4 44 01 00 00    	add    esp,0x144
```

## `Random_RangeFast` — `0x4034d0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x4034d0.c`
- Callers: `Game_GenerateRandomPlayers` (0x4050e0), `Game_WindowProc` (0x4058d0), `Settings_InitDefaults` (0x406a90), `Object_UpdateBranchOps` (0x406ff0), `Object_UpdateSupplyBuilding` (0x4082d0), `Person_UpdateStreetBehavior` (0x40b110), `Branch_SpawnWalkInCustomer` (0x477190), `Branch_GenerateUniqueName` (0x477aa0), `Company_AssignEmployee` (0x47c3e0), `Game_PickRandomUnownedAdjacentRecord` (0x47d080), `Game_PickFreeConstructionPlot` (0x47e750), `Branch_SpawnRandomPedestrian` (0x480900), `Branch_PickRandomActiveCounter` (0x480c40), `Game_InitScenario` (0x481d90), `Game_DispatchQuarterlyVisitors` (0x486960), `Game_RedirectPersonDestination` (0x48c6d0), `HighScore_UpdatePlayerEntry` (0x48e270), `GlossaryWeapons_FillWeaponPage` (0x4af8f0), `CharacterSelect_UpdateScreen` (0x4c7110), `FreePlaySetup_FillHighScoreTable` (0x4cbb10), `Map_ApplyRandomTileVariant` (0x4d22c0), `Car_Construct` (0x4d31f0), `Character_Construct` (0x4d3730), `City_ConstructFromName` (0x4d44e0), `City_SpawnPerson` (0x4d4940), `City_RemovePersonAndMaintainPopulation` (0x4d6c10), `Map_GetRandomBuildingOfType` (0x4d74c0), `MapObject_SpawnByKind` (0x4d77b0), `City_InitOfferSlots` (0x4d8650), `City_TickSimulation` (0x4d8d50), `City_SpawnResidentWeighted` (0x4da110), `City_ProcessQuarterEnd` (0x4da480), `City_SpawnResidentInPreferredCity` (0x4da550), `Game_PickRandomBuildingType` (0x4da880), `City_AddRandomBuilding` (0x4daaf0), `Game_SelectRandomPlayerCompany` (0x4db1d0), `Array_MoveActiveSlotToRandom` (0x4db260), `City_SpawnDeliveryVehicles` (0x4dc1a0), `City_ResetPoliceDistrictSlot` (0x4dc330), `Map_SpawnAdvertisingZeppelin` (0x4dc760), `City_ApplyCrimeWave` (0x4dca80), `Random_SwapOneOfFour` (0x4dcb70), `Game_ShuffleProductMarketValues` (0x4dcc20), `Person_RefreshShopChoices` (0x4dcd00), `Game_InitCompanyAIStrategy` (0x4dce00), `Company_GenerateStartingRecipes` (0x4dd8f0), `Company_ProcessHourlyTick` (0x4e0200), `Company_CreateAIStrategy` (0x4e3c00), `Map_PickRandomExitDirection` (0x4e4810), `Map_DrawObject` (0x4ee010), `Array_GetRandomRecord28B` (0x4f1280), `Grid_GetRandomRecord28` (0x4f3a90), `Array_GetRandomRecord28` (0x4f3ad0), `Map_LinkNeighbors` (0x4f3ce0), `Map_PickRandomSpawnCell` (0x4f4f20), `AI_ComputePath` (0x4f50d0), `Map_PickRandomType355Cell` (0x4f5260), `AI_ChooseWalkTarget` (0x4f5310), `Game_InitCompanySlots` (0x4f6e70), `AI_FindBestBranchSite` (0x4f8240), `AI_FindBranchPlotNearOwn` (0x4f8510), `AI_PickInitialBranchPlot` (0x4f8710), `AI_FindCheapestShop` (0x4f88c0), `CityMap_PlaceLargeComplexes` (0x4fb060), `AI_Action_AnnoyRival` (0x4fd610), `Game_PickRandomIdleObject` (0x4fdbe0), `City_MoveResidentIntoVacantHouse` (0x4fdcf0), `AI_SendGraffitiPunk` (0x4fde00), `AI_SendTroublePunks` (0x4fdf00), `AI_Annoy_SendGangsterGroup` (0x4fefb0), `Branch_AutoTunePrice` (0x4ff6e0), `Game_AddPoliceStations` (0x4ffbe0), `Player_AIState_StreamConstruct` (0x501aa0), `AI_SelectRandomAction` (0x5024f0), `AI_SelectExpansionAction` (0x502610), `AI_SelectStrategyAction` (0x502a90), `AI_SelectActionForType` (0x502b80), `Building_GetRandomResidentCount` (0x502c50), `Game_PickRandomTableValue` (0x502cb0), `AI_InitActionPlan` (0x502ce0), `MissionGoal_HandleEvent` (0x502f10), `BuildingProject_AdvanceStep` (0x503180), `Object_Construct` (0x504610), `Game_GetTimeByMode` (0x504a90), `Object_SetCompanyStylePalette` (0x505f40), `Object_PickWeightedBuildingRecord` (0x506010), `Person_DecideWaitOrLeaveHouse` (0x506c00), `Person_UpdateWaitAndHunger` (0x5071d0), `Map_PickRandomLinkedCellInSteps` (0x507b90), `Action_AddBestRecipeToBranchMenu` (0x509580), `UI_RandomChildEffect` (0x509ff0), `Person_FindFreeNeighborCell` (0x50bf50), `Person_ResolveGroupFight` (0x50c2e0), `AI_TestActionChance` (0x50d5e0), `AI_WanderToRandomRoadTile` (0x50d790), `Object_FindOpposingTarget` (0x50dbf0), `Person_UpdateFightAction` (0x50dd10), `Person_UpdateSocialEncounter` (0x50df30), `Player_MissionState_Tick` (0x50efe0), `Recipe_Construct` (0x50fc20), `Recipe_CreateGenerated` (0x510c90), `Recipe_StreamConstruct` (0x511be0), `Recipe_AddCategoryIngredients` (0x511ff0)
- Callees: none resolved

- Signature: `{'call_site': '0x405b0c and many gameplay callers', 'confidence': 'derived from pseudocode and caller use', 'recovered': 'unsigned int __cdecl Random_RangeFast(int low, unsigned int high)', 'return': 'inclusive range in EAX'}`
- Dispatch: `call` None -> []
- Unresolved questions: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

004034d0 <.text+0x24d0>:
  4034d0:	56                   	push   esi
  4034d1:	57                   	push   edi
  4034d2:	e8 0b bc 14 00       	call   0x54f0e2
  4034d7:	8b 74 24 10          	mov    esi,DWORD PTR [esp+0x10]
  4034db:	8b 7c 24 0c          	mov    edi,DWORD PTR [esp+0xc]
  4034df:	8b c8                	mov    ecx,eax
  4034e1:	8b c6                	mov    eax,esi
  4034e3:	2b c7                	sub    eax,edi
  4034e5:	40                   	inc    eax
  4034e6:	0f af c8             	imul   ecx,eax
  4034e9:	b8 05 00 02 00       	mov    eax,0x20005
  4034ee:	f7 e1                	mul    ecx
  4034f0:	2b ca                	sub    ecx,edx
  4034f2:	d1 e9                	shr    ecx,1
  4034f4:	03 ca                	add    ecx,edx
  4034f6:	c1 e9 0e             	shr    ecx,0xe
  4034f9:	03 cf                	add    ecx,edi
  4034fb:	8b c1                	mov    eax,ecx
  4034fd:	3b c6                	cmp    eax,esi
  4034ff:	76 02                	jbe    0x403503
  403501:	8b c6                	mov    eax,esi
  403503:	5f                   	pop    edi
  403504:	5e                   	pop    esi
```

## `Array_GetRecordByKeyPtr` — `0x52ff20`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x52ff20.c`
- Callers: `Game_WindowProc` (0x4058d0), `Game_RenderFrame` (0x485140), `Game_UpdateDateLabels` (0x488a10), `Chart_DrawCustomerGroups` (0x48a5a0), `Chart_DrawCustomerPortraits` (0x48a970), `CustomerGroups_DrawProductSalesGrid` (0x48ac00), `CustomerGroups_DrawTrafficGrid` (0x48aef0), `CustomerGroups_DrawCountRow` (0x48b1b0), `Window_UpdateStaffPlanPage` (0x493110), `UI_RemoveAllObjects` (0x49d280), `UI_DrawAwardMedals` (0x4a6750), `PersonnelPlan_LayoutEmployeeList` (0x4b1f40), `StatisticsPersonnel_UpdateWindow` (0x4b2240), `UI_WarpCursorToControl` (0x4c6780), `Game_UpdateObjectMapMarker` (0x4d2600), `Game_RemoveObjectFromUI` (0x4d28b0), `UI_Group_SelectMemberByKey` (0x532580), `UI_OpenBriefing` (0x54adc0), `UI_RemoveAllById` (0x54afb0)
- Callees: `Array_GetRecordByKey` (0x5313d0)

- Signature: `{'call_site': '0x405b49', 'confidence': 'derived from call-site EAX test', 'recovered': 'void *__thiscall Array_GetRecordByKeyPtr(Array *this, int key)', 'return': 'pointer observed in EAX though provider text says void'}`
- Dispatch: `call` None -> []
- Unresolved questions: Provider pseudocode declares void but the caller tests EAX at 0x405b4e.

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

0052ff20 <.text+0x12ef20>:
  52ff20:	8b 44 24 04          	mov    eax,DWORD PTR [esp+0x4]
  52ff24:	50                   	push   eax
  52ff25:	e8 a6 14 00 00       	call   0x5313d0
  52ff2a:	c2                   	.byte 0xc2
  52ff2b:	04                   	.byte 0x4
```

## `UI_SetButtonRecordVariant` — `0x531b70`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x531b70.c`
- Callers: `Game_WindowProc` (0x4058d0), `UI_RecordList_SetVisibleRange` (0x49f640), `Glossary_IngredientList_Update` (0x4af250), `Glossary_ShowIngredientDetail` (0x4af2f0)
- Callees: `Window_GadgetNotify` (0x52fdd0)

- Signature: `{'call_site': '0x405b5b', 'confidence': 'derived from Window_GadgetNotify call', 'recovered': 'void __thiscall UI_SetButtonRecordVariant(UI *this, int control_id, int variant)', 'return': 'void'}`
- Dispatch: `call` None -> []
- Unresolved questions: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

00531b70 <.text+0x130b70>:
  531b70:	8b 44 24 08          	mov    eax,DWORD PTR [esp+0x8]
  531b74:	8b 54 24 04          	mov    edx,DWORD PTR [esp+0x4]
  531b78:	6a 00                	push   0x0
  531b7a:	50                   	push   eax
  531b7b:	68 2c 01 00 00       	push   0x12c
  531b80:	6a 06                	push   0x6
  531b82:	52                   	push   edx
  531b83:	e8 48 e2 ff ff       	call   0x52fdd0
  531b88:	c2                   	.byte 0xc2
  531b89:	08                   	.byte 0x8
```

## `CityDetailView_CreateOwnCityWindow` — `0x41a2b0`

- Body: `decompiled_fastfood2_named_v2/full_game_verification/functions/0x41a2b0.c`
- Callers: `Game_ApplyPendingScreen` (0x485bb0)
- Callees: `UI_AddImage` (0x52f5b0), `UI_AddSprite` (0x531850), `UI_AddText` (0x52f850), `UI_CreateAnimationWindow` (0x531a50), `UI_CreateBitmapGadget` (0x531c60), `UI_CreateWindow` (0x523bb0), `UI_FindWindowByID` (0x528040), `Window_GadgetNotify_Text_SetLayout` (0x52f9d0), `Window_GadgetNotify_Text_SetTextColor` (0x52f910)

- Signature: `{'call_site': '0x485f7b', 'confidence': 'derived from call site and EAX store at 0x485f92', 'recovered': 'void *__cdecl CityDetailView_CreateOwnCityWindow(int *window_out)', 'return': 'window in EAX'}`
- Dispatch: `call` None -> ['0x531a50']
- Unresolved questions: none

### Disassembly

```asm
/home/patryk/pizzaconnection2/game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

0041a2b0 <.text+0x192b0>:
  41a2b0:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  41a2b6:	56                   	push   esi
  41a2b7:	68 f0 ea 48 00       	push   0x48eaf0
  41a2bc:	68 40 48 56 00       	push   0x564840
  41a2c1:	6a 00                	push   0x0
  41a2c3:	6a 00                	push   0x0
  41a2c5:	e8 e6 98 10 00       	call   0x523bb0
  41a2ca:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  41a2ce:	6a 00                	push   0x0
  41a2d0:	50                   	push   eax
  41a2d1:	89 01                	mov    DWORD PTR [ecx],eax
  41a2d3:	8b 0d e0 c5 57 00    	mov    ecx,DWORD PTR ds:0x57c5e0
  41a2d9:	e8 62 dd 10 00       	call   0x528040
  41a2de:	8b f0                	mov    esi,eax
  41a2e0:	85 f6                	test   esi,esi
  41a2e2:	75 02                	jne    0x41a2e6
  41a2e4:	5e                   	pop    esi
  41a2e5:	c3                   	ret
  41a2e6:	68 30 48 56 00       	push   0x564830
  41a2eb:	6a fe                	push   0xfffffffe
  41a2ed:	68 16 02 00 00       	push   0x216
  41a2f2:	68 4e 1f 00 00       	push   0x1f4e
  41a2f7:	8b ce                	mov    ecx,esi
  41a2f9:	e8 52 75 11 00       	call   0x531850
  41a2fe:	6a 00                	push   0x0
  41a300:	6a 00                	push   0x0
  41a302:	68 74 41 56 00       	push   0x564174
  41a307:	6a 03                	push   0x3
  41a309:	68 64 02 00 00       	push   0x264
  41a30e:	68 f5 03 00 00       	push   0x3f5
  41a313:	8b ce                	mov    ecx,esi
  41a315:	e8 96 52 11 00       	call   0x52f5b0
  41a31a:	6a 00                	push   0x0
  41a31c:	6a 00                	push   0x0
  41a31e:	68 44 41 56 00       	push   0x564144
  41a323:	6a 03                	push   0x3
  41a325:	68 f7 02 00 00       	push   0x2f7
  41a32a:	68 f6 03 00 00       	push   0x3f6
  41a32f:	8b ce                	mov    ecx,esi
  41a331:	e8 7a 52 11 00       	call   0x52f5b0
  41a336:	68 24 48 56 00       	push   0x564824
  41a33b:	68 b2 00 00 00       	push   0xb2
  41a340:	68 58 02 00 00       	push   0x258
  41a345:	68 ff 03 00 00       	push   0x3ff
  41a34a:	8b ce                	mov    ecx,esi
  41a34c:	e8 ff 74 11 00       	call   0x531850
  41a351:	68 18 48 56 00       	push   0x564818
  41a356:	68 b2 00 00 00       	push   0xb2
  41a35b:	68 80 02 00 00       	push   0x280
  41a360:	68 00 04 00 00       	push   0x400
  41a365:	8b ce                	mov    ecx,esi
  41a367:	e8 e4 74 11 00       	call   0x531850
  41a36c:	68 0c 48 56 00       	push   0x56480c
  41a371:	68 b2 00 00 00       	push   0xb2
  41a376:	68 a8 02 00 00       	push   0x2a8
  41a37b:	68 01 04 00 00       	push   0x401
  41a380:	8b ce                	mov    ecx,esi
  41a382:	e8 c9 74 11 00       	call   0x531850
  41a387:	68 00 48 56 00       	push   0x564800
  41a38c:	68 b2 00 00 00       	push   0xb2
  41a391:	68 d0 02 00 00       	push   0x2d0
  41a396:	68 02 04 00 00       	push   0x402
  41a39b:	8b ce                	mov    ecx,esi
  41a39d:	e8 ae 74 11 00       	call   0x531850
  41a3a2:	68 f4 47 56 00       	push   0x5647f4
  41a3a7:	68 b2 00 00 00       	push   0xb2
  41a3ac:	68 f8 02 00 00       	push   0x2f8
  41a3b1:	68 03 04 00 00       	push   0x403
  41a3b6:	8b ce                	mov    ecx,esi
  41a3b8:	e8 93 74 11 00       	call   0x531850
  41a3bd:	6a 00                	push   0x0
  41a3bf:	6a 01                	push   0x1
  41a3c1:	68 e8 47 56 00       	push   0x5647e8
  41a3c6:	68 b1 00 00 00       	push   0xb1
  41a3cb:	68 57 02 00 00       	push   0x257
  41a3d0:	68 fa 03 00 00       	push   0x3fa
  41a3d5:	8b ce                	mov    ecx,esi
  41a3d7:	e8 d4 51 11 00       	call   0x52f5b0
  41a3dc:	6a 00                	push   0x0
  41a3de:	6a 01                	push   0x1
  41a3e0:	68 dc 47 56 00       	push   0x5647dc
  41a3e5:	68 b1 00 00 00       	push   0xb1
  41a3ea:	68 7f 02 00 00       	push   0x27f
  41a3ef:	68 fb 03 00 00       	push   0x3fb
  41a3f4:	8b ce                	mov    ecx,esi
  41a3f6:	e8 b5 51 11 00       	call   0x52f5b0
  41a3fb:	6a 00                	push   0x0
  41a3fd:	6a 01                	push   0x1
  41a3ff:	68 d0 47 56 00       	push   0x5647d0
  41a404:	68 b1 00 00 00       	push   0xb1
  41a409:	68 a7 02 00 00       	push   0x2a7
  41a40e:	68 fc 03 00 00       	push   0x3fc
  41a413:	8b ce                	mov    ecx,esi
  41a415:	e8 96 51 11 00       	call   0x52f5b0
  41a41a:	6a 00                	push   0x0
  41a41c:	6a 01                	push   0x1
  41a41e:	68 c4 47 56 00       	push   0x5647c4
  41a423:	68 b1 00 00 00       	push   0xb1
  41a428:	68 cf 02 00 00       	push   0x2cf
  41a42d:	68 fd 03 00 00       	push   0x3fd
  41a432:	8b ce                	mov    ecx,esi
  41a434:	e8 77 51 11 00       	call   0x52f5b0
  41a439:	6a 00                	push   0x0
  41a43b:	6a 01                	push   0x1
  41a43d:	68 b8 47 56 00       	push   0x5647b8
  41a442:	68 b1 00 00 00       	push   0xb1
  41a447:	68 f7 02 00 00       	push   0x2f7
  41a44c:	68 fe 03 00 00       	push   0x3fe
  41a451:	8b ce                	mov    ecx,esi
  41a453:	e8 58 51 11 00       	call   0x52f5b0
  41a458:	6a 00                	push   0x0
  41a45a:	6a 00                	push   0x0
  41a45c:	68 a4 47 56 00       	push   0x5647a4
  41a461:	6a 06                	push   0x6
  41a463:	68 7f 02 00 00       	push   0x27f
  41a468:	68 0c 04 00 00       	push   0x40c
  41a46d:	8b ce                	mov    ecx,esi
  41a46f:	e8 3c 51 11 00       	call   0x52f5b0
  41a474:	68 9c 47 56 00       	push   0x56479c
  41a479:	68 a8 3e 56 00       	push   0x563ea8
  41a47e:	6a 04                	push   0x4
  41a480:	68 80 02 00 00       	push   0x280
  41a485:	68 0f 04 00 00       	push   0x40f
  41a48a:	8b ce                	mov    ecx,esi
  41a48c:	e8 bf 53 11 00       	call   0x52f850
  41a491:	85 c0                	test   eax,eax
  41a493:	74 22                	je     0x41a4b7
  41a495:	6a 00                	push   0x0
  41a497:	68 0f 04 00 00       	push   0x40f
  41a49c:	8b ce                	mov    ecx,esi
  41a49e:	e8 6d 54 11 00       	call   0x52f910
  41a4a3:	6a 00                	push   0x0
  41a4a5:	6a 00                	push   0x0
  41a4a7:	6a 78                	push   0x78
  41a4a9:	6a 02                	push   0x2
  41a4ab:	68 0f 04 00 00       	push   0x40f
  41a4b0:	8b ce                	mov    ecx,esi
  41a4b2:	e8 19 55 11 00       	call   0x52f9d0
  41a4b7:	68 94 47 56 00       	push   0x564794
  41a4bc:	68 88 47 56 00       	push   0x564788
  41a4c1:	68 38 02 00 00       	push   0x238
  41a4c6:	6a 0a                	push   0xa
  41a4c8:	68 10 04 00 00       	push   0x410
  41a4cd:	8b ce                	mov    ecx,esi
  41a4cf:	e8 7c 53 11 00       	call   0x52f850
  41a4d4:	85 c0                	test   eax,eax
  41a4d6:	74 22                	je     0x41a4fa
  41a4d8:	6a 00                	push   0x0
  41a4da:	68 10 04 00 00       	push   0x410
  41a4df:	8b ce                	mov    ecx,esi
  41a4e1:	e8 2a 54 11 00       	call   0x52f910
  41a4e6:	6a 00                	push   0x0
  41a4e8:	6a 00                	push   0x0
  41a4ea:	6a 32                	push   0x32
  41a4ec:	6a 02                	push   0x2
  41a4ee:	68 10 04 00 00       	push   0x410
  41a4f3:	8b ce                	mov    ecx,esi
  41a4f5:	e8 d6 54 11 00       	call   0x52f9d0
  41a4fa:	68 78 47 56 00       	push   0x564778
  41a4ff:	6a 03                	push   0x3
  41a501:	68 68 02 00 00       	push   0x268
  41a506:	68 15 04 00 00       	push   0x415
  41a50b:	8b ce                	mov    ecx,esi
  41a50d:	e8 3e 75 11 00       	call   0x531a50
  41a512:	6a 00                	push   0x0
  41a514:	6a 01                	push   0x1
  41a516:	68 4c 3e 56 00       	push   0x563e4c
  41a51b:	68 d9 00 00 00       	push   0xd9
  41a520:	68 3c 02 00 00       	push   0x23c
  41a525:	68 40 1f 00 00       	push   0x1f40
  41a52a:	8b ce                	mov    ecx,esi
  41a52c:	e8 7f 50 11 00       	call   0x52f5b0
  41a531:	68 74 47 56 00       	push   0x564774
  41a536:	68 64 3e 56 00       	push   0x563e64
  41a53b:	68 40 02 00 00       	push   0x240
  41a540:	68 ca 00 00 00       	push   0xca
  41a545:	68 2b 04 00 00       	push   0x42b
  41a54a:	8b ce                	mov    ecx,esi
  41a54c:	e8 ff 52 11 00       	call   0x52f850
  41a551:	85 c0                	test   eax,eax
  41a553:	74 22                	je     0x41a577
  41a555:	6a 00                	push   0x0
  41a557:	68 2b 04 00 00       	push   0x42b
  41a55c:	8b ce                	mov    ecx,esi
  41a55e:	e8 ad 53 11 00       	call   0x52f910
  41a563:	6a 00                	push   0x0
  41a565:	6a ff                	push   0xffffffff
  41a567:	6a 00                	push   0x0
  41a569:	6a 02                	push   0x2
  41a56b:	68 2b 04 00 00       	push   0x42b
  41a570:	8b ce                	mov    ecx,esi
  41a572:	e8 59 54 11 00       	call   0x52f9d0
  41a577:	6a 10                	push   0x10
  41a579:	6a 10                	push   0x10
  41a57b:	6a 6c                	push   0x6c
  41a57d:	68 40 02 00 00       	push   0x240
  41a582:	6a 58                	push   0x58
  41a584:	68 30 04 00 00       	push   0x430
  41a589:	8b ce                	mov    ecx,esi
  41a58b:	e8 d0 76 11 00       	call   0x531c60
  41a590:	68 68 47 56 00       	push   0x564768
  41a595:	68 98 3e 56 00       	push   0x563e98
  41a59a:	68 30 02 00 00       	push   0x230
  41a59f:	6a 68                	push   0x68
  41a5a1:	68 41 1f 00 00       	push   0x1f41
  41a5a6:	8b ce                	mov    ecx,esi
  41a5a8:	e8 a3 52 11 00       	call   0x52f850
  41a5ad:	85 c0                	test   eax,eax
  41a5af:	74 22                	je     0x41a5d3
  41a5b1:	6a 00                	push   0x0
  41a5b3:	68 41 1f 00 00       	push   0x1f41
  41a5b8:	8b ce                	mov    ecx,esi
  41a5ba:	e8 51 53 11 00       	call   0x52f910
  41a5bf:	6a 00                	push   0x0
  41a5c1:	6a ff                	push   0xffffffff
  41a5c3:	6a 5b                	push   0x5b
  41a5c5:	6a 02                	push   0x2
  41a5c7:	68 41 1f 00 00       	push   0x1f41
  41a5cc:	8b ce                	mov    ecx,esi
  41a5ce:	e8 fd 53 11 00       	call   0x52f9d0
  41a5d3:	68 58 47 56 00       	push   0x564758
  41a5d8:	68 27 02 00 00       	push   0x227
  41a5dd:	6a 1b                	push   0x1b
  41a5df:	68 11 04 00 00       	push   0x411
  41a5e4:	8b ce                	mov    ecx,esi
  41a5e6:	e8 65 74 11 00       	call   0x531a50
  41a5eb:	68 44 47 56 00       	push   0x564744
  41a5f0:	68 32 02 00 00       	push   0x232
  41a5f5:	68 ec 00 00 00       	push   0xec
  41a5fa:	68 48 1f 00 00       	push   0x1f48
  41a5ff:	8b ce                	mov    ecx,esi
  41a601:	e8 4a 72 11 00       	call   0x531850
  41a606:	68 38 47 56 00       	push   0x564738
  41a60b:	6a 35                	push   0x35
  41a60d:	68 ff 02 00 00       	push   0x2ff
  41a612:	68 49 1f 00 00       	push   0x1f49
  41a617:	8b ce                	mov    ecx,esi
  41a619:	e8 32 72 11 00       	call   0x531850
  41a61e:	68 38 47 56 00       	push   0x564738
  41a623:	6a 49                	push   0x49
  41a625:	68 ff 02 00 00       	push   0x2ff
  41a62a:	68 4a 1f 00 00       	push   0x1f4a
  41a62f:	8b ce                	mov    ecx,esi
  41a631:	e8 1a 72 11 00       	call   0x531850
  41a636:	68 38 47 56 00       	push   0x564738
  41a63b:	6a 5d                	push   0x5d
  41a63d:	68 ff 02 00 00       	push   0x2ff
  41a642:	68 4b 1f 00 00       	push   0x1f4b
  41a647:	8b ce                	mov    ecx,esi
  41a649:	e8 02 72 11 00       	call   0x531850
  41a64e:	68 38 47 56 00       	push   0x564738
  41a653:	6a 71                	push   0x71
  41a655:	68 ff 02 00 00       	push   0x2ff
  41a65a:	68 4c 1f 00 00       	push   0x1f4c
  41a65f:	8b ce                	mov    ecx,esi
  41a661:	e8 ea 71 11 00       	call   0x531850
  41a666:	68 38 47 56 00       	push   0x564738
  41a66b:	68 85 00 00 00       	push   0x85
  41a670:	68 ff 02 00 00       	push   0x2ff
  41a675:	68 4d 1f 00 00       	push   0x1f4d
  41a67a:	8b ce                	mov    ecx,esi
  41a67c:	e8 cf 71 11 00       	call   0x531850
  41a681:	68 2c 47 56 00       	push   0x56472c
  41a686:	6a 7c                	push   0x7c
  41a688:	68 fb 02 00 00       	push   0x2fb
  41a68d:	68 12 04 00 00       	push   0x412
  41a692:	8b ce                	mov    ecx,esi
  41a694:	e8 b7 73 11 00       	call   0x531a50
  41a699:	68 1c 47 56 00       	push   0x56471c
  41a69e:	68 be 00 00 00       	push   0xbe
  41a6a3:	68 f4 02 00 00       	push   0x2f4
  41a6a8:	68 13 04 00 00       	push   0x413
  41a6ad:	8b ce                	mov    ecx,esi
  41a6af:	e8 9c 73 11 00       	call   0x531a50
  41a6b4:	68 0c 47 56 00       	push   0x56470c
  41a6b9:	6a 1b                	push   0x1b
  41a6bb:	68 fb 02 00 00       	push   0x2fb
  41a6c0:	68 14 04 00 00       	push   0x414
  41a6c5:	8b ce                	mov    ecx,esi
  41a6c7:	e8 84 73 11 00       	call   0x531a50
  41a6cc:	8b c6                	mov    eax,esi
  41a6ce:	5e                   	pop    esi
```

