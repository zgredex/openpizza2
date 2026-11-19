# Vtables and class skeletons

Recovered from `game/fastfood2.exe` using PE `.rdata` code-pointer runs, constructor vtable writes, named exports, and exact field-access extraction.

- **77 vtables**
- **308 virtual slots**
- **130 slots backed by analyzed procedures**
- **178 slots backed by 75 indirect-only function entries**
- **1573 observed field offsets**

Ghidra only promoted directly-called code to procedures. Vtable-only targets are real function entries but require raw-disassembly analysis; they are named structurally here and listed in `vtable_slot_targets.csv`.

| Subsystem | Vtables |
|---|---:|
| Game | 32 |
| UI/Rendering | 22 |
| Sound | 11 |
| COM/CRT | 12 |

## Game vtables

| Vtable | Class | Ctor | Dtor | Slots | Base | Fields |
|---|---|---|---|---:|---|---:|
| `0x55c2e0` | `StatsPeriodReport` | `StatsPeriodReport_StreamConstruct` | `StatsPeriodReport_Delete` | 1 | `` | 6 |
| `0x55c2e8` | `NamedLockable` | `NamedLockable_Construct` | `NamedLockable_Delete` | 1 | `` | 2 |
| `0x55c2ec` | `List` | `List_Construct` | `List_Node_Delete` | 1 | `` | 6 |
| `0x55c2f0` | `ResourceManager` | `ResourceManager_Construct` | `ResourceManager_ScalarDeletingDestructor` | 1 | `` | 6 |
| `0x55c2f4` | `FileObject` | `FileObject_Open` | `FileObject_Delete` | 1 | `` | 7 |
| `0x55c308` | `TimerClass` | `TimerClass_Construct` | `TimerClass_ScalarDeletingDestructor` | 1 | `` | 5 |
| `0x55c30c` | `Branch` | `Branch_Construct` | `Branch_Delete` | 1 | `` | 98 |
| `0x55c44c` | `GameWorld` | `GameSession_Construct` | `GameWorld_Delete` | 1 | `` | 77 |
| `0x55c4e8` | `RecipeTopping` | `RecipeTopping_StreamConstruct` | `RecipeTopping_Delete` | 1 | `` | 9 |
| `0x55c4ec` | `MapObject` | `MapObject_Construct` | `MapObject_Delete` | 1 | `` | 24 |
| `0x55c4f8` | `Car` | `Car_Construct` | `Car_Delete` | 1 | `` | 4 |
| `0x55c4fc` | `Character` | `Character_StreamConstruct` | `Character_Delete` | 1 | `` | 27 |
| `0x55c500` | `City` | `City_ConstructFromName` | `City_Delete` | 1 | `` | 25 |
| `0x55c564` | `GameClock` | `GameClock_Construct` | `GameClock_Delete` | 1 | `` | 13 |
| `0x55c568` | `Company` | `Company_ConstructDefault` | `Company_Delete` | 1 | `` | 39 |
| `0x55c5a0` | `FurnitureType` | `FurnitureType_Construct` | `FurnitureType_Delete` | 1 | `` | 6 |
| `0x55c5a4` | `BuildingValue` | `BuildingValue_Construct` | `BuildingValue_Delete` | 1 | `` | 6 |
| `0x55c5b8` | `Ingredient` | `Ingredient_Construct` | `Ingredient_Delete` | 1 | `` | 86 |
| `0x55c5bc` | `ConstructionOrder` | `ConstructionOrder_Construct` | `ConstructionOrder_Delete` | 1 | `` | 8 |
| `0x55c5d0` | `Game` | `Game_Construct` | `Game_Delete` | 1 | `` | 271 |
| `0x55c5d4` | `IsoMap` | `IsoMap_Construct` | `IsoMap_Delete` | 1 | `` | 39 |
| `0x55c5e8` | `PlayerMissionState` | `Player_MissionState_Construct` | `Player_MissionState_Delete` | 1 | `` | 8 |
| `0x55c618` | `GameCompanyManager` | `Game_CompanyManager_Construct` | `Game_CompanyManager_Delete` | 1 | `` | 7 |
| `0x55c660` | `Player_Event` | `Player_Event_StreamConstruct` | `AwardNode_Delete` | 1 | `` | 2 |
| `0x55c664` | `PlayerAIState` | `Player_AIState_StreamConstruct` | `Player_AIState_Delete` | 1 | `` | 19 |
| `0x55c668` | `WorldObject` | `Object_Construct` | `WorldObject_Delete` | 1 | `` | 39 |
| `0x55c684` | `Player` | `Player_Construct` | `Player_Delete` | 1 | `` | 25 |
| `0x55c688` | `GamePlan` | `GamePlan_Construct` | `GamePlan_Delete` | 1 | `` | 11 |
| `0x55c698` | `Recipe` | `Recipe_Construct` | `Recipe_Delete` | 1 | `` | 30 |
| `0x55c700` | `Storage` | `Storage_Construct` | `Storage_Delete` | 1 | `` | 11 |
| `0x55cb3c` | `DebugConsole` | `DebugConsole_Construct` | `DebugConsole_Delete` | 1 | `` | 5 |
| `0x55cb44` | `EmployeeAvatar` | `EmployeeAvatar_Construct` | `EmployeeAvatar_Delete` | 1 | `` | 8 |

## UI/Rendering vtables

| Vtable | Class | Ctor | Dtor | Slots | Base | Fields |
|---|---|---|---|---:|---|---:|
| `0x55c2f8` | `UI_ListEntry` | `UI_ListEntry_ConstructWithValue` | `UI_ListEntry_Delete` | 1 | `` | 4 |
| `0x55c704` | `UI_ImageElement` | `UI_Image_Construct` | `UI_ImageElement_Delete` | 7 | `UI_Child` | 10 |
| `0x55c720` | `UI_Child` | `UI_Child_Construct` | `UI_Child_Delete` | 7 | `` | 19 |
| `0x55c73c` | `UI_Viewport` | `UI_ImageChild_Construct` | `UI_Viewport_Delete` | 7 | `UI_Child` | 11 |
| `0x55c758` | `UI_LabelElement` | `UI_TextLabel_Construct` | `UI_LabelElement_Delete` | 7 | `UI_Child` | 17 |
| `0x55c774` | `Array` | `Array_Construct` | `Array_Delete` | 1 | `` | 4 |
| `0x55c778` | `UI_Manager` | `UI_Manager_Construct` | `UI_Manager_ScalarDeletingDestructor` | 1 | `` | 83 |
| `0x55c788` | `UI_ContextMenu` | `ContextMenu_Construct` | `UI_ContextMenu_Delete` | 1 | `` | 13 |
| `0x55c78c` | `UI_Slider` | `UI_Bar_Construct` | `UI_Slider_Delete` | 7 | `UI_Child` | 39 |
| `0x55c7b0` | `MovieWindow` | `MovieWindow_Construct` | `MovieWindow_Delete` | 7 | `UI_Child` | 16 |
| `0x55c7cc` | `UI_TextElement` | `UI_Text_Construct` | `UI_TextElement_Delete` | 7 | `UI_Child` | 13 |
| `0x55c7e8` | `UI_ButtonElement` | `UI_TextPanel_Construct` | `UI_ButtonElement_Delete` | 7 | `UI_Child` | 25 |
| `0x55c804` | `UI_Tooltip` | `Tooltip_Construct` | `UI_Tooltip_Delete` | 1 | `` | 14 |
| `0x55c808` | `Dialog` | `Dialog_Construct` | `Dialog_Delete` | 1 | `` | 58 |
| `0x55c80c` | `SpriteFile` | `Anim_Load` | `Animation_ScalarDeletingDestructor` | 1 | `SpriteBase` | 28 |
| `0x55c810` | `Gfx_RectList` | `Gfx_RectList_Construct` | `Gfx_RectList_Delete` | 1 | `` | 5 |
| `0x55c814` | `Window` | `Window_Construct` | `Window_Delete` | 1 | `` | 10 |
| `0x55c818` | `Renderer` | `Renderer_ConstructRoot` | `Renderer_Delete` | 1 | `` | 30 |
| `0x55c828` | `SpriteBase` | `SpriteBase_Construct` | `SpriteBase_Delete` | 1 | `` | 0 |
| `0x55c82c` | `Sprite` | `Sprite_CreateRaw` | `Sprite_ScalarDeletingDestructor` | 1 | `SpriteBase` | 29 |
| `0x55cb04` | `ListContainer` | `` | `List_ContainerDestroy` | 4 | `` | 3 |
| `0x55cb40` | `UI_BriefingList` | `UI_BriefingList_Construct` | `UI_BriefingList_Delete` | 1 | `` | 6 |

## Sound vtables

| Vtable | Class | Ctor | Dtor | Slots | Base | Fields |
|---|---|---|---|---:|---|---:|
| `0x55c830` | `SoundDevice` | `SoundDevice_Construct` | `SoundBuffer_Delete` | 4 | `` | 4 |
| `0x55c840` | `SoundBufferBase` | `SoundBuffer_ConstructBase` | `SoundBufferBase_Delete` | 4 | `` | 41 |
| `0x55c850` | `SoundSample` | `SoundSample_Construct` | `SoundSample_Delete` | 4 | `` | 11 |
| `0x55c860` | `DirectSoundBuffer` | `Sound_CreatePrimaryBuffer` | `DirectSoundBuffer_Delete` | 1 | `` | 10 |
| `0x55c864` | `SoundPakManagerBase` | `SoundBuffer_ConstructBase` | `SoundPakManager_Delete` | 4 | `` | 4 |
| `0x55c874` | `SoundBuffer` | `SoundBuffer_CreateDSBuffer` | `SoundBuffer_DeleteObject` | 6 | `SoundBufferBase` | 33 |
| `0x55c8b0` | `SoundStreamBuffer` | `SoundStreamBuffer_Construct` | `SoundStreamBuffer_DeleteObject` | 6 | `` | 16 |
| `0x55c8c8` | `SoundStreamBuffer3D` | `SoundStreamBuffer_Construct` | `SoundBuffer_ScalarDeletingDestructor` | 6 | `SoundStreamBuffer` | 19 |
| `0x55c8e0` | `SoundVoice` | `SoundVoice_Construct` | `SoundTrack_Delete` | 4 | `` | 34 |
| `0x55c8f0` | `SoundMixerThread` | `SoundVoiceThread_Construct` | `SoundMixerThread_Delete` | 1 | `` | 8 |
| `0x55cb14` | `SoundBufferAux` | `` | `SoundBuffer_Delete2` | 4 | `` | 2 |

## COM/CRT vtables

| Vtable | Class | Ctor | Dtor | Slots | Base | Fields |
|---|---|---|---|---:|---|---:|
| `0x55c8f4` | `ComInterface_55C8F4` | `Sound_CreatePrimaryBuffer` | `` | 1 | `` | 0 |
| `0x55c8f8` | `ComIDirectSoundBuffer` | `Sound_CreatePrimaryBuffer` | `` | 63 | `` | 0 |
| `0x55c9f4` | `ComInterface_55C9F4` | `Sound_CreatePrimaryBuffer` | `` | 1 | `` | 0 |
| `0x55c9f8` | `ComIDirectSound` | `Sound_CreatePrimaryBuffer` | `SoundSystem_Delete` | 4 | `` | 0 |
| `0x55ca08` | `ComIDirectSound3DListener` | `` | `` | 63 | `` | 0 |
| `0x55cc2c` | `CRT_Ifstream` | `CRT_Ifstream_Construct` | `CRT_Ifstream_ScalarDeletingDestructor` | 1 | `` | 0 |
| `0x55cc54` | `CRT_Filebuf` | `CRT_FileBuf_Construct` | `CRT_Filebuf_Delete` | 11 | `CRT_Streambuf` | 2 |
| `0x55cc84` | `CRT_Ofstream` | `CRT_Ofstream_Construct` | `CRT_Ofstream_ScalarDeletingDestructor` | 1 | `` | 0 |
| `0x55cc94` | `CRT_Istream` | `CRT_Istream_Construct` | `CRT_Istream_ScalarDeletingDestructor` | 1 | `` | 0 |
| `0x55cca4` | `CRT_Ostream` | `CRT_Ostream_Construct` | `CRT_Ostream_ScalarDeletingDestructor` | 1 | `` | 0 |
| `0x55ccc0` | `CRT_Ios` | `CRT_Ios_Construct` | `CRT_Ios_Delete` | 1 | `` | 11 |
| `0x55ccc8` | `CRT_Streambuf` | `CRT_Streambuf_Construct` | `CRT_Streambuf_Delete` | 11 | `` | 12 |

`*` = indirect-only function entry not promoted by Ghidra.


## Undiscovered vtable targets

These addresses are valid function entries reachable only through vtables, so they are absent from the procedure inventory. They were verified by raw disassembly (`ret`/padding boundaries) and named by observed behavior or structural slot role.

| Address | Name | Used by |
|---|---|---|
| `0x504980` | `WorldObject_Delete` | WorldObject[0] |
| `0x51f2b0` | `UI_ImageElement_vfunc1` | UI_ImageElement[1] |
| `0x51f310` | `UI_ImageElement_vfunc3` | UI_ImageElement[3] |
| `0x51f980` | `UI_ImageElement_vfunc4` | UI_ImageElement[4] |
| `0x51f9f0` | `UI_ImageElement_vfunc2` | UI_ImageElement[2] |
| `0x51fa60` | `UI_Child_ForwardToVFunc4` | UI_ImageElement[5], UI_Child[5], UI_Viewport[5], UI_LabelElement[5], MovieWindow[5], UI_TextElement[5] ... |
| `0x520fb0` | `UI_Child_InvokeCallback` | UI_ImageElement[6], UI_Child[6], UI_LabelElement[6], UI_Slider[6], UI_TextElement[6], UI_ButtonElement[6] |
| `0x520ff0` | `UI_Child_ReturnTrue` | UI_Child[4], UI_LabelElement[4], UI_TextElement[4], UI_ButtonElement[4] |
| `0x521630` | `UI_Viewport_vfunc4` | UI_Viewport[4] |
| `0x521b00` | `UI_Viewport_GetTypeId` | UI_Viewport[2] |
| `0x521e50` | `UI_Viewport_vfunc6` | UI_Viewport[6] |
| `0x522250` | `UI_LabelElement_vfunc1` | UI_LabelElement[1] |
| `0x522360` | `UI_LabelElement_vfunc3` | UI_LabelElement[3] |
| `0x522cb0` | `UI_LabelElement_vfunc2` | UI_LabelElement[2] |
| `0x529370` | `UI_Slider_vfunc1` | UI_Slider[1] |
| `0x5299c0` | `UI_Slider_vfunc3` | UI_Slider[3] |
| `0x52ab00` | `UI_Slider_vfunc4` | UI_Slider[4] |
| `0x52ac40` | `UI_Slider_ReturnTrue` | UI_Slider[5] |
| `0x52b4c0` | `MovieWindow_vfunc3` | MovieWindow[3] |
| `0x52b9e0` | `MovieWindow_IsPlaying` | MovieWindow[4] |
| `0x52ba30` | `MovieWindow_vfunc2` | MovieWindow[2] |
| `0x52be20` | `UI_TextElement_vfunc1` | UI_TextElement[1] |
| `0x52bfe0` | `UI_TextElement_vfunc3` | UI_TextElement[3] |
| `0x52c470` | `UI_TextElement_vfunc2` | UI_TextElement[2] |
| `0x52d750` | `UI_ButtonElement_vfunc1` | UI_ButtonElement[1] |
| `0x52dac0` | `UI_ButtonElement_vfunc3` | UI_ButtonElement[3] |
| `0x52e3a0` | `UI_ButtonElement_vfunc2` | UI_ButtonElement[2] |
| `0x53ef60` | `RefCount_AddRef` | SoundDevice[0], SoundBufferBase[0], SoundSample[0], SoundPakManagerBase[0], SoundBuffer[0], SoundStreamBuffer[0] ... |
| `0x53efe0` | `SoundBufferBase_Delete` | SoundBufferBase[3] |
| `0x540c80` | `SoundBuffer_vfunc4` | SoundBuffer[4] |
| `0x541750` | `SoundStreamBuffer_vfunc4_ForwardQuery` | SoundStreamBuffer[4], SoundStreamBuffer3D[4] |
| `0x542e30` | `ComIDirectSoundBuffer_vfunc0` | ComIDirectSoundBuffer[0] |
| `0x542e50` | `ComIDirectSoundBuffer_vfunc1` | ComIDirectSoundBuffer[1] |
| `0x542e80` | `ComIDirectSoundBuffer_vfunc2` | ComIDirectSoundBuffer[2] |
| `0x543080` | `ComIDirectSoundBuffer_vfunc4` | ComIDirectSoundBuffer[4] |
| `0x543170` | `ComIDirectSoundBuffer_vfunc5` | ComIDirectSoundBuffer[5] |
| `0x543240` | `ComIDirectSoundBuffer_vfunc6` | ComIDirectSoundBuffer[6] |
| `0x543430` | `ComIDirectSoundBuffer_vfunc26` | ComIDirectSoundBuffer[26] |
| `0x543500` | `ComIDirectSoundBuffer_vfunc28` | ComIDirectSoundBuffer[28] |
| `0x5435c0` | `ComIDirectSoundBuffer_vfunc27` | ComIDirectSoundBuffer[27] |
| `0x543700` | `ComIDirectSoundBuffer_vfunc29` | ComIDirectSoundBuffer[29] |
| `0x543810` | `ComIDirectSoundBuffer_vfunc30` | ComIDirectSoundBuffer[30] |
| `0x543890` | `ComIDirectSoundBuffer_vfunc31` | ComIDirectSoundBuffer[31] |
| `0x543960` | `ComIDirectSoundBuffer_vfunc32` | ComIDirectSoundBuffer[32] |
| `0x543a50` | `ComIDirectSoundBuffer_vfunc33` | ComIDirectSoundBuffer[33] |
| `0x543b20` | `ComIDirectSoundBuffer_vfunc34` | ComIDirectSoundBuffer[34] |
| `0x544030` | `ComIDirectSoundBuffer_vfunc38` | ComIDirectSoundBuffer[38] |
| `0x544110` | `ComIDirectSoundBuffer_vfunc45` | ComIDirectSoundBuffer[45] |
| `0x544180` | `ComIDirectSoundBuffer_vfunc46` | ComIDirectSoundBuffer[46] |
| `0x544260` | `ComIDirectSoundBuffer_vfunc44` | ComIDirectSoundBuffer[44] |
| `0x544480` | `ComIDirectSoundBuffer_vfunc42` | ComIDirectSoundBuffer[42] |
| `0x544700` | `COM_E_NOTIMPL_Ret4` | SoundStreamBuffer[5], SoundStreamBuffer3D[5], ComIDirectSoundBuffer[50], ComIDirectSoundBuffer[51] |
| `0x544710` | `COM_E_NOTIMPL_Ret12` | ComIDirectSoundBuffer[43], ComIDirectSoundBuffer[48], ComIDirectSoundBuffer[54], ComIDirectSoundBuffer[56] |
| `0x544720` | `COM_E_NOTIMPL_Ret8` | ComIDirectSoundBuffer[47], ComIDirectSoundBuffer[49], ComIDirectSoundBuffer[52], ComIDirectSoundBuffer[53], ComIDirectSoundBuffer[55], ComIDirectSoundBuffer[57] |
| `0x544730` | `ComIDirectSoundBuffer_vfunc58_GetError` | ComIDirectSoundBuffer[58] |
| `0x545a10` | `ComIDirectSoundBuffer_vfunc14` | ComIDirectSoundBuffer[14] |
| `0x545bd0` | `ComIDirectSoundBuffer_vfunc15` | ComIDirectSoundBuffer[15] |
| `0x545ca0` | `ComIDirectSoundBuffer_vfunc16` | ComIDirectSoundBuffer[16] |
| `0x5465a0` | `ComIDirectSoundBuffer_vfunc39` | ComIDirectSoundBuffer[39] |
| `0x5467c0` | `ComIDirectSoundBuffer_vfunc40` | ComIDirectSoundBuffer[40] |
| `0x546950` | `ComIDirectSoundBuffer_vfunc22` | ComIDirectSoundBuffer[22] |
| `0x546a40` | `ComIDirectSoundBuffer_vfunc23` | ComIDirectSoundBuffer[23] |
| `0x546f90` | `ComIDirectSound_AdjustorThunk0` | ComIDirectSound[0] |
| `0x546fa0` | `ComIDirectSound_AdjustorThunk1` | ComIDirectSound[1] |
| `0x546fb0` | `ComInterface_55C8F4_AdjustorThunk0` | ComInterface_55C8F4[0] |
| `0x546fc0` | `ComInterface_55C9F4_AdjustorThunk0` | ComInterface_55C9F4[0] |
| `0x54cc6e` | `CRT_Ifstream_ScalarDeletingDestructor` | CRT_Ifstream[0] |
| `0x54cf92` | `CRT_Filebuf_vfunc3` | CRT_Filebuf[3] |
| `0x54d115` | `CRT_Ofstream_ScalarDeletingDestructor` | CRT_Ofstream[0] |
| `0x54d3e3` | `CRT_Istream_ScalarDeletingDestructor` | CRT_Istream[0] |
| `0x54d7be` | `CRT_Ostream_ScalarDeletingDestructor` | CRT_Ostream[0] |
| `0x54db51` | `CRT_Streambuf_SetBuffer` | CRT_Streambuf[2] |
| `0x54dd04` | `CRT_Streambuf_ReturnMinusOne` | CRT_Streambuf[3] |
| `0x54dd0a` | `CRT_Streambuf_ForwardToVFunc3` | CRT_Filebuf[4], CRT_Streambuf[4] |
| `0x54fb1e` | `_purecall` | UI_Child[1], UI_Child[2], UI_Child[3], ComIDirectSound3DListener[0], ComIDirectSound3DListener[1], ComIDirectSound3DListener[2] ... |

## Excluded code-pointer tables

A raw scan found 57 maximal code-pointer runs in `.rdata`. Every run is either covered by one of the 77 class vtables above or is one of the following non-class tables:

| Address | Kind | Reason for exclusion |
|---|---|---|
| `0x55ccfc` | CRT float/printf dispatch table | two conversion routines, not a C++ vtable |
| `0x55cd0c`, `0x55cd10` | CRT helper pointer tables | isolated CRT function pointers with adjacent non-code data |
| `0x55cd18` | CRT `type_info` RTTI vtable | one destructor slot; referenced only by 8 `.data` type descriptors, never by a constructor |
| `0x55ce1c`-`0x55ceb0` | CRT dispatch tables | scanf/printf/validation routine pairs, not object vtables |
| 15 isolated pointers (`0x55d1d8`, `0x561ba4`, `0x561c18`, `0x561df0`, `0x561e84`, `0x561f24`, `0x561f58`, `0x562084`, `0x56208c`, `0x5620f4`, `0x562100`, `0x562394`, `0x562434`, `0x5625a4`, `0x562710`) | embedded function pointers | no code xref and no vtable-shaped run; data fields, not class vtables |


## Class skeletons

### StatsPeriodReport

- Vtable: `0x55c2e0`
- Constructor: `StatsPeriodReport_StreamConstruct`
- Destructor: `StatsPeriodReport_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `StatsPeriodReport_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 4 | StatsPeriodReport_Load, StatsPeriodReport_Save, Stats_Report_Construct, Stats_Report_ConstructEmpty |
| `0x8` | 4 | 4 | StatsPeriodReport_Load, StatsPeriodReport_Save, Stats_Report_Construct, Stats_Report_ConstructEmpty |
| `0xc` | 4 | 4 | StatsPeriodReport_Load, StatsPeriodReport_Save, Stats_Report_Construct, Stats_Report_ConstructEmpty |
| `0x10` | 0 | 2 | StatsPeriodReport_Load, StatsPeriodReport_Save |
| `0x78` | 0 | 2 | StatsPeriodReport_Load, StatsPeriodReport_Save |
| `0xdc` | 0 | 2 | StatsPeriodReport_Load, StatsPeriodReport_Save |

### NamedLockable

- Vtable: `0x55c2e8`
- Constructor: `NamedLockable_Construct`
- Destructor: `NamedLockable_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `NamedLockable_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x50` | 4 | 1 | NamedLockable_Construct |
| `0x54` | 4 | 1 | NamedLockable_Construct |

### List

- Vtable: `0x55c2ec`
- Constructor: `List_Construct`
- Destructor: `List_Node_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: slot0 symbol List_Node_Delete is a legacy name; List_Construct initializes this container vtable

| # | Method |
|---:|---|
| 0 | `List_Node_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 3 | List_Construct, List_Node_Destroy, List_Node_Reset |
| `0x8` | 4 | 3 | List_Construct, List_Node_Destroy, List_Node_Reset |
| `0xc` | 4 | 2 | List_Construct, List_Node_Reset |
| `0x10` | 4 | 2 | List_Construct, List_Node_Reset |
| `0x14` | 4 | 2 | List_Construct, List_Node_Reset |
| `0x18` | 4 | 2 | List_Construct, List_Node_Reset |

### ResourceManager

- Vtable: `0x55c2f0`
- Constructor: `ResourceManager_Construct`
- Destructor: `ResourceManager_ScalarDeletingDestructor`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `ResourceManager_ScalarDeletingDestructor` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x66c` | 1 | 1 | ResourceManager_Construct |
| `0x1684` | 4 | 2 | ResourceManager_Construct, ResourceManager_Destruct |
| `0x1ab4` | 4 | 2 | ResourceManager_Construct, ResourceManager_Destruct |
| `0x1ab8` | 4 | 1 | ResourceManager_Construct |
| `0x1abc` | 4 | 1 | ResourceManager_Construct |
| `0x1ac0` | 4 | 1 | ResourceManager_Construct |

### FileObject

- Vtable: `0x55c2f4`
- Constructor: `FileObject_Open`
- Destructor: `FileObject_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `FileObject_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | FileObject_Destroy, FileObject_Open |
| `0x8` | 4 | 2 | FileObject_Destroy, FileObject_Open |
| `0xc` | 4 | 2 | FileObject_Destroy, FileObject_Open |
| `0x10` | 2 | 1 | FileObject_Open |
| `0x12` | 2 | 1 | FileObject_Open |
| `0x14` | 4 | 2 | FileObject_InitBase, FileObject_Open |
| `0x50` | 0 | 1 | FileObject_InitBase |

### UI_ListEntry

- Vtable: `0x55c2f8`
- Constructor: `UI_ListEntry_ConstructWithValue`
- Destructor: `UI_ListEntry_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `UI_ListEntry_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x44` | 4 | 3 | UI_ListEntry_Construct, UI_ListEntry_ConstructWithValue, UI_ListEntry_Destroy |
| `0x48` | 4 | 3 | UI_ListEntry_Construct, UI_ListEntry_ConstructWithValue, UI_ListEntry_Destroy |
| `0x4c` | 4 | 2 | UI_ListEntry_Construct, UI_ListEntry_ConstructWithValue |
| `0x54` | 4 | 2 | UI_ListEntry_Construct, UI_ListEntry_ConstructWithValue |

### TimerClass

- Vtable: `0x55c308`
- Constructor: `TimerClass_Construct`
- Destructor: `TimerClass_ScalarDeletingDestructor`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `TimerClass_ScalarDeletingDestructor` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | TimerClass_Construct, Timer_Destroy |
| `0x8` | 4 | 2 | TimerClass_Construct, Timer_Destroy |
| `0xc` | 4 | 1 | TimerClass_Construct |
| `0x68` | 4 | 1 | TimerClass_Construct |
| `0x6c` | 4 | 2 | TimerClass_Construct, Timer_Destroy |

### Branch

- Vtable: `0x55c30c`
- Constructor: `Branch_Construct`
- Destructor: `Branch_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Branch_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 0 | 2 | Branch_Load, Branch_Save |
| `0x24` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x28` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x2c` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x30` | 4 | 4 | Branch_Construct, Branch_InitCityObjects, Branch_Load, Branch_Save |
| `0x34` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x38` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x3c` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x40` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x44` | 0 | 2 | Branch_Load, Branch_Save |
| `0x188` | 0 | 2 | Branch_Load, Branch_Save |
| `0x2cc` | 0 | 2 | Branch_Load, Branch_Save |
| `0x410` | 0 | 2 | Branch_Load, Branch_Save |
| `0x554` | 0 | 2 | Branch_Load, Branch_Save |
| `0x1364` | 0 | 2 | Branch_Load, Branch_Save |
| `0x1388` | 0 | 2 | Branch_Load, Branch_Save |
| `0x13d0` | 0 | 2 | Branch_Load, Branch_Save |
| `0x1418` | 0 | 2 | Branch_Load, Branch_Save |
| `0x1460` | 0 | 2 | Branch_Load, Branch_Save |
| `0x14a8` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x14ac` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x14b0` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x14b4` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x14b8` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x14bc` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x14c0` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x14c4` | 4 | 2 | Branch_Construct, Branch_Load |
| `0x14c8` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x14cc` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x14d0` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x14d4` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x14d8` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x14dc` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x14e0` | 4 | 5 | Branch_Construct, Branch_Destroy, Branch_InitCityObjects, Branch_Load, Branch_Save |
| `0x14f8` | 4 | 2 | Branch_Destroy, Branch_Save |
| `0x1514` | 4 | 2 | Branch_Load, Branch_Save |
| `0x151c` | 0 | 2 | Branch_Load, Branch_Save |
| `0x16bc` | 0 | 2 | Branch_Load, Branch_Save |
| `0x16f0` | 4 | 5 | Branch_Construct, Branch_Destroy, Branch_InitCityObjects, Branch_Load, Branch_Save |
| `0x16f4` | 1 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x16f5` | 1 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x170c` | 4 | 2 | Branch_Destroy, Branch_Save |
| `0x1714` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1718` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x171c` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1720` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1724` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x173c` | 4 | 1 | Branch_Save |
| `0x1758` | 4 | 1 | Branch_Save |
| `0x1774` | 4 | 1 | Branch_Save |
| `0x177c` | 0 | 2 | Branch_Load, Branch_Save |
| `0x179c` | 0 | 2 | Branch_Load, Branch_Save |
| `0x17bc` | 0 | 2 | Branch_Load, Branch_Save |
| `0x17dc` | 0 | 2 | Branch_Load, Branch_Save |
| `0x17fc` | 0 | 2 | Branch_Load, Branch_Save |
| `0x181c` | 0 | 2 | Branch_Load, Branch_Save |
| `0x183c` | 0 | 2 | Branch_Load, Branch_Save |
| `0x1850` | 4 | 2 | Branch_Load, Branch_Save |
| `0x1854` | 4 | 2 | Branch_Load, Branch_Save |
| `0x1858` | 4 | 2 | Branch_Load, Branch_Save |
| `0x185c` | 4 | 2 | Branch_Load, Branch_Save |
| `0x1860` | 4 | 2 | Branch_Load, Branch_Save |
| `0x1864` | 4 | 2 | Branch_Load, Branch_Save |
| `0x1868` | 4 | 2 | Branch_Load, Branch_Save |
| `0x186c` | 4 | 2 | Branch_Load, Branch_Save |
| `0x1870` | 4 | 2 | Branch_Load, Branch_Save |
| `0x1874` | 4 | 2 | Branch_Load, Branch_Save |
| `0x1878` | 4 | 2 | Branch_Load, Branch_Save |
| `0x187c` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1880` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1881` | 1 | 1 | Branch_Construct |
| `0x1882` | 1 | 1 | Branch_Construct |
| `0x1883` | 1 | 1 | Branch_Construct |
| `0x1884` | 0 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1888` | 4 | 1 | Branch_Construct |
| `0x188c` | 4 | 1 | Branch_Construct |
| `0x1890` | 4 | 1 | Branch_Construct |
| `0x1894` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1898` | 0 | 2 | Branch_Load, Branch_Save |
| `0x18d8` | 0 | 2 | Branch_Load, Branch_Save |
| `0x19ac` | 4 | 2 | Branch_Destroy, Branch_Save |
| `0x19b4` | 0 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x19b8` | 4 | 1 | Branch_Construct |
| `0x19bc` | 4 | 1 | Branch_Construct |
| `0x19c0` | 4 | 1 | Branch_Construct |
| `0x19d8` | 4 | 2 | Branch_Destroy, Branch_Save |
| `0x19f4` | 4 | 1 | Branch_Save |
| `0x19fc` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1a00` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1a04` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1a20` | 1 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1a21` | 1 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1a24` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1a28` | 4 | 2 | Branch_Construct, Branch_ConstructFromStream |
| `0x1a2c` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1a30` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1a34` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |
| `0x1a38` | 4 | 3 | Branch_Construct, Branch_Load, Branch_Save |

### GameWorld

- Vtable: `0x55c44c`
- Constructor: `GameSession_Construct`
- Destructor: `GameWorld_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: renamed GameState -> GameWorld; slot0 and pointer symbol are GameWorld_Delete; constructor symbol is GameSession_Construct (base/sibling name)

| # | Method |
|---:|---|
| 0 | `GameWorld_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x88` | 4 | 1 | GameState_Destruct |
| `0x90` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x94` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x98` | 4 | 1 | GameSession_Construct |
| `0x9c` | 4 | 1 | GameSession_Construct |
| `0xa0` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0xa4` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0xa5` | 1 | 1 | GameSession_Construct |
| `0x218` | 4 | 1 | GameSession_Construct |
| `0x21c` | 4 | 1 | GameSession_Construct |
| `0x220` | 4 | 1 | GameSession_Construct |
| `0x23c` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x240` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x244` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x248` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x24c` | 4 | 1 | GameSession_Construct |
| `0x250` | 4 | 1 | GameSession_Construct |
| `0x254` | 4 | 1 | GameSession_Construct |
| `0x258` | 4 | 1 | GameSession_Construct |
| `0x25c` | 4 | 1 | GameSession_Construct |
| `0x260` | 4 | 1 | GameSession_Construct |
| `0x264` | 4 | 1 | GameSession_Construct |
| `0x268` | 4 | 1 | GameSession_Construct |
| `0x26c` | 4 | 1 | GameSession_Construct |
| `0x270` | 4 | 1 | GameSession_Construct |
| `0x274` | 4 | 1 | GameSession_Construct |
| `0x278` | 4 | 1 | GameSession_Construct |
| `0x27c` | 4 | 1 | GameSession_Construct |
| `0x280` | 4 | 1 | GameSession_Construct |
| `0x284` | 4 | 1 | GameSession_Construct |
| `0x290` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x29c` | 4 | 1 | GameSession_Construct |
| `0x2a0` | 4 | 1 | GameSession_Construct |
| `0x2a4` | 4 | 1 | GameSession_Construct |
| `0x2a8` | 4 | 1 | GameSession_Construct |
| `0x2ac` | 4 | 1 | GameSession_Construct |
| `0x2b0` | 4 | 1 | GameSession_Construct |
| `0x2b4` | 4 | 1 | GameSession_Construct |
| `0x2d8` | 4 | 1 | GameSession_Construct |
| `0x2dc` | 4 | 1 | GameSession_Construct |
| `0x2e0` | 4 | 1 | GameSession_Construct |
| `0x2e4` | 4 | 1 | GameSession_Construct |
| `0x2e8` | 4 | 1 | GameSession_Construct |
| `0x2ec` | 4 | 1 | GameSession_Construct |
| `0x2f0` | 4 | 1 | GameSession_Construct |
| `0x2f4` | 4 | 1 | GameSession_Construct |
| `0x2f8` | 4 | 1 | GameSession_Construct |
| `0x2fc` | 4 | 1 | GameSession_Construct |
| `0x300` | 4 | 1 | GameSession_Construct |
| `0x33c` | 4 | 1 | GameSession_Construct |
| `0x340` | 4 | 1 | GameSession_Construct |
| `0x344` | 4 | 1 | GameSession_Construct |
| `0x348` | 4 | 1 | GameSession_Construct |
| `0x34c` | 4 | 1 | GameSession_Construct |
| `0x350` | 4 | 1 | GameSession_Construct |
| `0x354` | 4 | 1 | GameSession_Construct |
| `0x358` | 4 | 1 | GameSession_Construct |
| `0x35c` | 4 | 1 | GameSession_Construct |
| `0x360` | 4 | 1 | GameSession_Construct |
| `0x364` | 4 | 1 | GameSession_Construct |
| `0x368` | 4 | 1 | GameSession_Construct |
| `0x384` | 4 | 1 | GameSession_Construct |
| `0xb65` | 1 | 1 | GameSession_Construct |
| `0x1508` | 4 | 1 | GameSession_Construct |
| `0x150c` | 4 | 1 | GameSession_Construct |
| `0x2d10` | 4 | 1 | GameSession_Construct |
| `0x2d14` | 4 | 1 | GameSession_Construct |
| `0x2d18` | 4 | 1 | GameSession_Construct |
| `0x2d8c` | 4 | 1 | GameSession_Construct |
| `0x2d90` | 4 | 1 | GameSession_Construct |
| `0x2d98` | 4 | 1 | GameSession_Construct |
| `0x2d9c` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x2da0` | 4 | 1 | GameSession_Construct |
| `0x2da4` | 4 | 1 | GameSession_Construct |
| `0x2da8` | 4 | 1 | GameSession_Construct |
| `0x2dac` | 4 | 2 | GameSession_Construct, GameState_Destruct |
| `0x2e18` | 4 | 1 | GameSession_Construct |

### RecipeTopping

- Vtable: `0x55c4e8`
- Constructor: `RecipeTopping_StreamConstruct`
- Destructor: `RecipeTopping_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `RecipeTopping_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 1 | 3 | RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct |
| `0x5` | 1 | 3 | RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct |
| `0x6` | 1 | 3 | RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct |
| `0x8` | 4 | 3 | RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct |
| `0xc` | 4 | 3 | RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct |
| `0x10` | 1 | 3 | RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct |
| `0x11` | 1 | 3 | RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct |
| `0x14` | 8 | 3 | RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct |
| `0x18` | 4 | 1 | RecipeTopping_StreamConstruct |

### MapObject

- Vtable: `0x55c4ec`
- Constructor: `MapObject_Construct`
- Destructor: `MapObject_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `MapObject_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 4 | MapObject_Construct, MapObject_Destroy, MapObject_Load, MapObject_Save |
| `0x8` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0xc` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x10` | 0 | 2 | MapObject_Load, MapObject_Save |
| `0x20` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x24` | 4 | 4 | MapObject_Construct, MapObject_InitRenderRecord, MapObject_Load, MapObject_Save |
| `0x28` | 4 | 2 | MapObject_Construct, MapObject_Load |
| `0x2c` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x30` | 4 | 4 | MapObject_Construct, MapObject_InitRenderRecord, MapObject_Load, MapObject_Save |
| `0x34` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x38` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x3c` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x40` | 8 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x44` | 4 | 1 | MapObject_Construct |
| `0x48` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x4c` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x50` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x54` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x6c` | 4 | 1 | MapObject_Save |
| `0x74` | 4 | 5 | MapObject_Construct, MapObject_Destroy, MapObject_InitRenderRecord, MapObject_Load, MapObject_Save |
| `0x8c` | 0 | 1 | MapObject_Save |
| `0x94` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0xc4` | 4 | 1 | MapObject_InitRenderRecord |
| `0xc8` | 4 | 1 | MapObject_InitRenderRecord |

### Car

- Vtable: `0x55c4f8`
- Constructor: `Car_Construct`
- Destructor: `Car_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Car_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | Car_Construct, Car_LoadFromStream |
| `0x8` | 4 | 3 | Car_Destroy, Car_LoadSpriteRecord, Car_Save |
| `0xc` | 4 | 3 | Car_Construct, Car_Destroy, Car_LoadFromStream |
| `0x10` | 4 | 1 | Car_Destroy |

### Character

- Vtable: `0x55c4fc`
- Constructor: `Character_StreamConstruct`
- Destructor: `Character_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Character_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x8` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0xc` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x10` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x14` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x18` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x1c` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x20` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x24` | 4 | 2 | Character_Load, Character_Save |
| `0x28` | 4 | 2 | Character_Load, Character_Save |
| `0x2c` | 4 | 2 | Character_Load, Character_Save |
| `0x30` | 4 | 2 | Character_Load, Character_Save |
| `0x34` | 4 | 2 | Character_Load, Character_Save |
| `0x38` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x3c` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x40` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x44` | 0 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x1d4` | 4 | 1 | Character_Construct |
| `0x364` | 4 | 1 | Character_Construct |
| `0x4f4` | 4 | 1 | Character_Construct |
| `0x684` | 4 | 1 | Character_Construct |
| `0x814` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x818` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x81c` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x820` | 4 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x824` | 1 | 3 | Character_Construct, Character_Load, Character_Save |
| `0x825` | 1 | 3 | Character_Construct, Character_Load, Character_Save |

### City

- Vtable: `0x55c500`
- Constructor: `City_ConstructFromName`
- Destructor: `City_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `City_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x14` | 4 | 1 | City_InitOfferSlots |
| `0x1c` | 4 | 1 | City_InitBuildings |
| `0x20` | 4 | 1 | City_InitBuildings |
| `0x24` | 4 | 1 | City_InitBuildings |
| `0x28` | 4 | 1 | City_InitBuildings |
| `0x48` | 4 | 1 | City_InitPopulation |
| `0xc1c` | 4 | 1 | City_InitPopulation |
| `0xdc4` | 4 | 1 | City_ConstructFromName |
| `0xfa8` | 4 | 4 | City_ConstructFromName, City_Destroy, City_InitBuildings, City_InitPopulation |
| `0xfc0` | 4 | 2 | City_Destroy, City_InitPopulation |
| `0xfdc` | 4 | 1 | City_Destroy |
| `0x10a4` | 4 | 1 | City_ConstructFromName |
| `0x10a8` | 4 | 1 | City_Destroy |
| `0x10ac` | 4 | 1 | City_ConstructFromName |
| `0x10b0` | 4 | 1 | City_ConstructFromName |
| `0x10b4` | 4 | 1 | City_ConstructFromName |
| `0x10b8` | 4 | 1 | City_ConstructFromName |
| `0x10bc` | 4 | 1 | City_ConstructFromName |
| `0x10c4` | 4 | 1 | City_ConstructFromName |
| `0x10c8` | 4 | 1 | City_ConstructFromName |
| `0x10cc` | 4 | 1 | City_ConstructFromName |
| `0x1148` | 4 | 1 | City_ConstructFromName |
| `0x114c` | 4 | 1 | City_ConstructFromName |
| `0x1150` | 4 | 1 | City_ConstructFromName |
| `0x1154` | 4 | 1 | City_ConstructFromName |

### GameClock

- Vtable: `0x55c564`
- Constructor: `GameClock_Construct`
- Destructor: `GameClock_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `GameClock_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 2 | 1 | GameClock_Reset |
| `0x6` | 1 | 1 | GameClock_Reset |
| `0x7` | 1 | 1 | GameClock_Reset |
| `0x8` | 1 | 1 | GameClock_Reset |
| `0xa` | 2 | 1 | GameClock_Reset |
| `0xc` | 4 | 1 | GameClock_Reset |
| `0x10` | 4 | 1 | GameClock_Reset |
| `0x14` | 4 | 1 | GameClock_Construct |
| `0x18` | 1 | 1 | GameClock_Reset |
| `0x19` | 1 | 1 | GameClock_Reset |
| `0x1c` | 4 | 1 | GameClock_Construct |
| `0x20` | 4 | 2 | GameClock_Construct, GameClock_Destroy |
| `0x24` | 4 | 2 | GameClock_Construct, GameClock_Destroy |

### Company

- Vtable: `0x55c568`
- Constructor: `Company_ConstructDefault`
- Destructor: `Company_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Company_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 0 | 1 | Company_Load |
| `0x48` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0x4c` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0x50` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0x54` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0x58` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0x5c` | 2 | 2 | Company_ConstructDefault, Company_Load |
| `0x60` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0x64` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0x68` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0x6c` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0x70` | 0 | 1 | Company_Load |
| `0x94` | 0 | 1 | Company_Load |
| `0xac` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0xb0` | 2 | 1 | Company_ConstructDefault |
| `0xb4` | 0 | 1 | Company_Load |
| `0xcc` | 0 | 1 | Company_Load |
| `0xe4` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0xe8` | 4 | 1 | Company_ConstructDefault |
| `0xec` | 2 | 1 | Company_ConstructDefault |
| `0xf0` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0xf4` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0xf8` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0xfc` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0x100` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0x108` | 8 | 2 | Company_ConstructDefault, Company_Load |
| `0x10c` | 4 | 1 | Company_ConstructDefault |
| `0x124` | 4 | 1 | Company_Destroy |
| `0x15c` | 4 | 1 | Company_Destroy |
| `0x178` | 4 | 1 | Company_Destroy |
| `0x194` | 4 | 1 | Company_Destroy |
| `0x1b0` | 4 | 1 | Company_Destroy |
| `0x1cc` | 4 | 1 | Company_Destroy |
| `0x1d4` | 4 | 3 | Company_ConstructDefault, Company_Destroy, Company_Load |
| `0x1d8` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0x1dc` | 4 | 1 | Company_Load |
| `0x1e0` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0x1e4` | 4 | 2 | Company_ConstructDefault, Company_Load |
| `0x1e8` | 4 | 2 | Company_ConstructDefault, Company_Load |

### FurnitureType

- Vtable: `0x55c5a0`
- Constructor: `FurnitureType_Construct`
- Destructor: `FurnitureType_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `FurnitureType_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | FurnitureType_Construct |
| `0xc` | 4 | 1 | FurnitureType_Construct |
| `0x10` | 4 | 1 | FurnitureType_Construct |
| `0x14` | 4 | 1 | FurnitureType_Construct |
| `0x70` | 4 | 1 | FurnitureType_Construct |
| `0x74` | 4 | 1 | FurnitureType_Construct |

### BuildingValue

- Vtable: `0x55c5a4`
- Constructor: `BuildingValue_Construct`
- Destructor: `BuildingValue_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `BuildingValue_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 2 | BuildingValue_Load, BuildingValue_Save |
| `0xc` | 4 | 4 | BuildingValue_Construct, BuildingValue_ConstructDefault, BuildingValue_Load, BuildingValue_Save |
| `0x10` | 8 | 4 | BuildingValue_Construct, BuildingValue_ConstructDefault, BuildingValue_Load, BuildingValue_Save |
| `0x14` | 4 | 2 | BuildingValue_Construct, BuildingValue_ConstructDefault |
| `0x18` | 4 | 4 | BuildingValue_Construct, BuildingValue_ConstructDefault, BuildingValue_Load, BuildingValue_Save |
| `0x1c` | 1 | 4 | BuildingValue_Construct, BuildingValue_ConstructDefault, BuildingValue_Load, BuildingValue_Save |

### Ingredient

- Vtable: `0x55c5b8`
- Constructor: `Ingredient_Construct`
- Destructor: `Ingredient_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Ingredient_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0xa8` | 1 | 1 | Ingredient_Construct |
| `0xac` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xb0` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xb4` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xb8` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xbc` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xc0` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xc4` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xc8` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xcc` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xd0` | 4 | 2 | Ingredient_Construct, Ingredient_LoadMarketTable |
| `0xd4` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xd8` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xdc` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xe0` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xe4` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xe8` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xec` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xf0` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xf4` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xf8` | 0 | 1 | Ingredient_LoadMarketTable |
| `0xfc` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x100` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x104` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x108` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x10c` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x110` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x114` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x118` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x11c` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x120` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x124` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x128` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x12c` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x130` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x134` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x138` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x13c` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x140` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x144` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x148` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x14c` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x150` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x154` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x158` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x15c` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x160` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x164` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x168` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x16c` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x170` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x174` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x178` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x17c` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x180` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x184` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x188` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x18c` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x190` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x194` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x198` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x19c` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1a0` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1a4` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1a8` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1ac` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1b0` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1b4` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1b8` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1bc` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1c0` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1c4` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1c8` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1cc` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1d0` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1d4` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1d8` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1dc` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1e0` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1e4` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1e8` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1ec` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1f0` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1f4` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1f8` | 0 | 1 | Ingredient_LoadMarketTable |
| `0x1fc` | 0 | 1 | Ingredient_LoadMarketTable |

### ConstructionOrder

- Vtable: `0x55c5bc`
- Constructor: `ConstructionOrder_Construct`
- Destructor: `ConstructionOrder_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `ConstructionOrder_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 3 | ConstructionOrder_Construct, ConstructionOrder_Load, ConstructionOrder_Save |
| `0x8` | 4 | 3 | ConstructionOrder_Construct, ConstructionOrder_Load, ConstructionOrder_Save |
| `0xc` | 4 | 3 | ConstructionOrder_Construct, ConstructionOrder_Load, ConstructionOrder_Save |
| `0x10` | 4 | 2 | ConstructionOrder_Construct, ConstructionOrder_Save |
| `0x14` | 4 | 3 | ConstructionOrder_Construct, ConstructionOrder_Load, ConstructionOrder_Save |
| `0x18` | 4 | 3 | ConstructionOrder_Construct, ConstructionOrder_Load, ConstructionOrder_Save |
| `0x1c` | 4 | 3 | ConstructionOrder_Construct, ConstructionOrder_Load, ConstructionOrder_Save |
| `0x20` | 4 | 3 | ConstructionOrder_Construct, ConstructionOrder_Load, ConstructionOrder_Save |

### Game

- Vtable: `0x55c5d0`
- Constructor: `Game_Construct`
- Destructor: `Game_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Game_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | Game_InitDateState |
| `0x8` | 4 | 1 | Game_InitDateState |
| `0xc` | 4 | 3 | Game_Construct, Game_Destroy, Game_InitDateState |
| `0x10` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x14` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x18` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x1c` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x20` | 4 | 1 | Game_Construct |
| `0x31` | 2 | 1 | Game_InitDateState |
| `0x33` | 1 | 1 | Game_InitDateState |
| `0x34` | 4 | 1 | Game_InitStatBaselines |
| `0x6c` | 4 | 1 | Game_ResetBuildingUtilization |
| `0x90` | 4 | 2 | Game_InitScenario, Game_LoadSaveGame |
| `0x94` | 0 | 1 | Game_LoadSaveGame |
| `0x9c` | 4 | 1 | Game_LoadSaveGame |
| `0xa8` | 4 | 1 | Game_ResetBuildingUtilization |
| `0xc0` | 4 | 1 | Game_InitDateState |
| `0xc6` | 1 | 1 | Game_InitDateState |
| `0xc8` | 4 | 1 | Game_InitDateState |
| `0xd0` | 4 | 1 | Game_InitDateState |
| `0xd4` | 4 | 1 | Game_InitDateState |
| `0x124` | 4 | 1 | Game_ResetRecordTurnCounters |
| `0x1cc` | 4 | 1 | Game_ResetBuildingUtilization |
| `0x200` | 4 | 1 | Game_InitScenario |
| `0x224` | 4 | 2 | Game_InitScenario, Game_LoadSaveGame |
| `0x240` | 4 | 3 | Game_InitScenario, Game_LoadBackgroundImage, Game_ResetStats |
| `0x244` | 4 | 1 | Game_ResetStats |
| `0x248` | 4 | 1 | Game_ResetStats |
| `0x24c` | 4 | 1 | Game_ResetStats |
| `0x250` | 4 | 1 | Game_ResetStats |
| `0x254` | 4 | 1 | Game_ResetStats |
| `0x258` | 4 | 1 | Game_ResetStats |
| `0x25c` | 4 | 1 | Game_ResetStats |
| `0x260` | 4 | 1 | Game_ResetStats |
| `0x298` | 0 | 1 | Game_LoadSaveGame |
| `0x2b8` | 0 | 1 | Game_LoadSaveGame |
| `0x2d8` | 4 | 1 | Game_LoadSaveGame |
| `0x2dc` | 4 | 1 | Game_LoadSaveGame |
| `0x2e8` | 4 | 1 | Game_LoadSaveGame |
| `0x2ec` | 4 | 1 | Game_LoadSaveGame |
| `0x2f0` | 4 | 1 | Game_LoadSaveGame |
| `0x2f4` | 4 | 1 | Game_LoadSaveGame |
| `0x2f8` | 4 | 1 | Game_LoadSaveGame |
| `0x300` | 4 | 1 | Game_LoadBackgroundImage |
| `0x33c` | 4 | 1 | Game_LoadSaveGame |
| `0x340` | 4 | 1 | Game_LoadSaveGame |
| `0x344` | 4 | 1 | Game_LoadSaveGame |
| `0x348` | 4 | 1 | Game_LoadSaveGame |
| `0x34c` | 4 | 1 | Game_LoadSaveGame |
| `0x350` | 4 | 1 | Game_LoadSaveGame |
| `0x354` | 4 | 1 | Game_LoadSaveGame |
| `0x358` | 4 | 1 | Game_LoadSaveGame |
| `0x35c` | 4 | 1 | Game_LoadSaveGame |
| `0x360` | 4 | 1 | Game_LoadSaveGame |
| `0x364` | 4 | 1 | Game_LoadSaveGame |
| `0x368` | 4 | 1 | Game_LoadSaveGame |
| `0x81c` | 4 | 1 | Game_ResetPlayerStatsByCity |
| `0x820` | 4 | 1 | Game_ResetPlayerStatsByCity |
| `0x1148` | 4 | 1 | Game_InitCompanyAIStrategy |
| `0x114c` | 4 | 1 | Game_InitCompanyAIStrategy |
| `0x1150` | 4 | 1 | Game_InitCompanyAIStrategy |
| `0x1154` | 4 | 1 | Game_InitCompanyAIStrategy |
| `0x14d8` | 4 | 1 | Game_InitStatBaselines |
| `0x186c` | 4 | 1 | Game_InitStatBaselines |
| `0x2d90` | 4 | 1 | Game_LoadSaveGame |
| `0x2e24` | 4 | 1 | Game_LoadSaveGame |
| `0x2bf44` | 4 | 1 | Game_Construct |
| `0x2bf48` | 1 | 1 | Game_Construct |
| `0x2bf4c` | 4 | 1 | Game_Construct |
| `0x2bf50` | 4 | 1 | Game_Construct |
| `0x2bf54` | 4 | 1 | Game_Construct |
| `0x2bf58` | 4 | 1 | Game_Construct |
| `0x2bf5c` | 4 | 1 | Game_Construct |
| `0x2bf60` | 4 | 1 | Game_Construct |
| `0x2bf64` | 4 | 1 | Game_Construct |
| `0x2bf68` | 4 | 1 | Game_Construct |
| `0x2bf74` | 4 | 1 | Game_Construct |
| `0x2bf78` | 4 | 1 | Game_Construct |
| `0x2bf7c` | 4 | 1 | Game_Construct |
| `0x2bf80` | 4 | 1 | Game_Construct |
| `0x2bf84` | 4 | 1 | Game_Construct |
| `0x2bf88` | 4 | 1 | Game_Construct |
| `0x2bf90` | 4 | 1 | Game_Construct |
| `0x2bf94` | 4 | 1 | Game_Construct |
| `0x2bf98` | 4 | 1 | Game_Construct |
| `0x2bf9c` | 4 | 1 | Game_Construct |
| `0x2bfa4` | 4 | 1 | Game_Construct |
| `0x2bfa8` | 4 | 1 | Game_Construct |
| `0x2bfac` | 4 | 1 | Game_Construct |
| `0x2bfc0` | 4 | 1 | Game_Construct |
| `0x2bfc4` | 4 | 1 | Game_Construct |
| `0x2bfc8` | 4 | 1 | Game_Construct |
| `0x2bfcc` | 4 | 1 | Game_Construct |
| `0x2bfd0` | 4 | 1 | Game_Construct |
| `0x2bfd4` | 4 | 1 | Game_Construct |
| `0x2bfe0` | 4 | 1 | Game_Construct |
| `0x2bfe4` | 4 | 1 | Game_Construct |
| `0x2bfe8` | 4 | 1 | Game_Construct |
| `0x2bfec` | 4 | 1 | Game_Construct |
| `0x2c00c` | 4 | 1 | Game_Construct |
| `0x2c010` | 4 | 1 | Game_Construct |
| `0x2c014` | 4 | 1 | Game_Construct |
| `0x2c018` | 4 | 1 | Game_Construct |
| `0x2c01c` | 4 | 1 | Game_Construct |
| `0x2c020` | 4 | 1 | Game_Construct |
| `0x2c024` | 4 | 1 | Game_Construct |
| `0x2c028` | 4 | 1 | Game_Construct |
| `0x2c048` | 4 | 1 | Game_Construct |
| `0x2c050` | 4 | 1 | Game_Construct |
| `0x2c054` | 4 | 1 | Game_Construct |
| `0x2c058` | 4 | 1 | Game_Construct |
| `0x2c05c` | 4 | 1 | Game_Construct |
| `0x2c0a0` | 4 | 1 | Game_Construct |
| `0x2c0a4` | 4 | 1 | Game_Construct |
| `0x2c0a8` | 4 | 1 | Game_Construct |
| `0x2c0ac` | 4 | 1 | Game_Construct |
| `0x2c0cc` | 4 | 1 | Game_Construct |
| `0x2c0d0` | 4 | 1 | Game_Construct |
| `0x2c0d4` | 4 | 1 | Game_Construct |
| `0x2c0d8` | 4 | 1 | Game_Construct |
| `0x2c0dc` | 4 | 1 | Game_Construct |
| `0x2c0e0` | 4 | 1 | Game_Construct |
| `0x2c0e4` | 4 | 1 | Game_Construct |
| `0x2c0e8` | 4 | 1 | Game_Construct |
| `0x2c0ec` | 4 | 1 | Game_Construct |
| `0x2c0f0` | 4 | 1 | Game_Construct |
| `0x2c0f4` | 4 | 1 | Game_Construct |
| `0x2c0f8` | 4 | 1 | Game_Construct |
| `0x2c0fc` | 4 | 1 | Game_Construct |
| `0x2c100` | 4 | 1 | Game_Construct |
| `0x2c104` | 4 | 1 | Game_Construct |
| `0x2c108` | 4 | 1 | Game_Construct |
| `0x2c10c` | 4 | 1 | Game_Construct |
| `0x2c110` | 4 | 1 | Game_Construct |
| `0x2c114` | 4 | 1 | Game_Construct |
| `0x2c118` | 4 | 1 | Game_Construct |
| `0x2c11c` | 4 | 1 | Game_Construct |
| `0x2c120` | 4 | 1 | Game_Construct |
| `0x2c124` | 4 | 1 | Game_Construct |
| `0x2c128` | 4 | 1 | Game_Construct |
| `0x2c12c` | 4 | 1 | Game_Construct |
| `0x2c130` | 4 | 1 | Game_Construct |
| `0x2c134` | 4 | 1 | Game_Construct |
| `0x2c138` | 4 | 1 | Game_Construct |
| `0x2c13c` | 4 | 1 | Game_Construct |
| `0x2c140` | 4 | 1 | Game_Construct |
| `0x2c144` | 4 | 1 | Game_Construct |
| `0x2c148` | 4 | 1 | Game_Construct |
| `0x2c14c` | 4 | 1 | Game_Construct |
| `0x2c150` | 4 | 1 | Game_Construct |
| `0x2c154` | 4 | 1 | Game_Construct |
| `0x2c158` | 4 | 1 | Game_Construct |
| `0x2c15c` | 4 | 1 | Game_Construct |
| `0x2c160` | 4 | 1 | Game_Construct |
| `0x2c164` | 4 | 1 | Game_Construct |
| `0x2c168` | 4 | 1 | Game_Construct |
| `0x2c16c` | 4 | 1 | Game_Construct |
| `0x2c170` | 4 | 1 | Game_Construct |
| `0x2c174` | 4 | 1 | Game_Construct |
| `0x2c178` | 4 | 1 | Game_Construct |
| `0x2c17c` | 4 | 1 | Game_Construct |
| `0x2c180` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c184` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c188` | 4 | 1 | Game_Construct |
| `0x2c18c` | 4 | 1 | Game_Construct |
| `0x2c190` | 4 | 1 | Game_Construct |
| `0x2c194` | 4 | 1 | Game_Construct |
| `0x2c198` | 4 | 1 | Game_Construct |
| `0x2c19c` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c1a0` | 4 | 1 | Game_Construct |
| `0x2c1a4` | 4 | 1 | Game_Construct |
| `0x2c1a8` | 4 | 1 | Game_Construct |
| `0x2c1ac` | 4 | 1 | Game_Construct |
| `0x2c1b0` | 4 | 1 | Game_Construct |
| `0x2c1b4` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c1b8` | 4 | 1 | Game_Construct |
| `0x2c1bc` | 4 | 1 | Game_Construct |
| `0x2c1c0` | 4 | 1 | Game_Construct |
| `0x2c1c4` | 4 | 1 | Game_Construct |
| `0x2c1c8` | 4 | 1 | Game_Construct |
| `0x2c1cc` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c1d0` | 4 | 1 | Game_Construct |
| `0x2c1d4` | 4 | 1 | Game_Construct |
| `0x2c1d8` | 4 | 1 | Game_Construct |
| `0x2c1dc` | 4 | 1 | Game_Construct |
| `0x2c1e0` | 4 | 1 | Game_Construct |
| `0x2c1e4` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c1e8` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c1ec` | 4 | 1 | Game_Construct |
| `0x2c1f0` | 4 | 1 | Game_Construct |
| `0x2c1f4` | 4 | 1 | Game_Construct |
| `0x2c1f8` | 4 | 1 | Game_Construct |
| `0x2c1fc` | 4 | 1 | Game_Construct |
| `0x2c200` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c204` | 4 | 1 | Game_Construct |
| `0x2c208` | 4 | 1 | Game_Construct |
| `0x2c20c` | 4 | 1 | Game_Construct |
| `0x2c210` | 4 | 1 | Game_Construct |
| `0x2c214` | 4 | 1 | Game_Construct |
| `0x2c218` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c21c` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c220` | 4 | 1 | Game_Construct |
| `0x2c224` | 4 | 1 | Game_Construct |
| `0x2c228` | 4 | 1 | Game_Construct |
| `0x2c22c` | 4 | 1 | Game_Construct |
| `0x2c230` | 4 | 1 | Game_Construct |
| `0x2c234` | 4 | 1 | Game_Construct |
| `0x2c238` | 4 | 1 | Game_Construct |
| `0x2c23c` | 4 | 1 | Game_Construct |
| `0x2c240` | 4 | 1 | Game_Construct |
| `0x2c244` | 4 | 1 | Game_Construct |
| `0x2c248` | 4 | 1 | Game_Construct |
| `0x2c24c` | 4 | 1 | Game_Construct |
| `0x2c250` | 4 | 1 | Game_Construct |
| `0x2c25c` | 4 | 1 | Game_Construct |
| `0x2c260` | 4 | 1 | Game_Construct |
| `0x2c268` | 4 | 1 | Game_Construct |
| `0x2c26c` | 4 | 1 | Game_Construct |
| `0x2c270` | 4 | 1 | Game_Construct |
| `0x2c278` | 4 | 1 | Game_Construct |
| `0x2c27c` | 4 | 1 | Game_Construct |
| `0x2c280` | 4 | 1 | Game_Construct |
| `0x2c284` | 4 | 1 | Game_Construct |
| `0x2c28c` | 4 | 1 | Game_Construct |
| `0x2c290` | 4 | 1 | Game_Construct |
| `0x2c294` | 4 | 1 | Game_Construct |
| `0x2c29c` | 4 | 1 | Game_Construct |
| `0x2c2a0` | 4 | 1 | Game_Construct |
| `0x2c2a4` | 4 | 1 | Game_Construct |
| `0x2c2a8` | 4 | 1 | Game_Construct |
| `0x2c2ac` | 4 | 1 | Game_Construct |
| `0x2c2b0` | 4 | 1 | Game_Construct |
| `0x2c2b4` | 4 | 1 | Game_Construct |
| `0x2c2b8` | 4 | 1 | Game_Construct |
| `0x2c2f4` | 4 | 1 | Game_Construct |
| `0x2c2f8` | 4 | 1 | Game_Construct |
| `0x2c2fc` | 4 | 1 | Game_Construct |
| `0x2c300` | 4 | 1 | Game_Construct |
| `0x2c304` | 4 | 1 | Game_Construct |
| `0x2c308` | 4 | 1 | Game_Construct |
| `0x2c30c` | 4 | 1 | Game_Construct |
| `0x2c310` | 4 | 1 | Game_Construct |
| `0x2c330` | 4 | 1 | Game_Construct |
| `0x2c338` | 4 | 1 | Game_Construct |
| `0x2c33c` | 4 | 1 | Game_Construct |
| `0x2c340` | 4 | 1 | Game_Construct |
| `0x2c344` | 4 | 1 | Game_Construct |
| `0x2c3b4` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3b8` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3bc` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3c0` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3c4` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3c8` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3cc` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3d0` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3d4` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3d8` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3dc` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3e0` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3e4` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3e8` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3ec` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3f0` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c3f4` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c414` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2c418` | 4 | 2 | Game_Construct, Game_Destroy |
| `0x2f87c` | 4 | 1 | Game_Construct |
| `0x2f880` | 4 | 1 | Game_Construct |
| `0x2f884` | 4 | 1 | Game_Construct |
| `0x2f888` | 4 | 1 | Game_Construct |
| `0x2f88c` | 4 | 1 | Game_Construct |

### IsoMap

- Vtable: `0x55c5d4`
- Constructor: `IsoMap_Construct`
- Destructor: `IsoMap_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `IsoMap_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 5 | IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Destroy, IsoMap_Load, IsoMap_Save |
| `0x8` | 4 | 3 | IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Destroy |
| `0xc` | 4 | 3 | IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Save |
| `0x10` | 4 | 1 | IsoMap_Save |
| `0x14` | 4 | 1 | IsoMap_Save |
| `0x18` | 4 | 1 | IsoMap_Save |
| `0x1c` | 4 | 2 | IsoMap_Destroy, IsoMap_Save |
| `0x20` | 4 | 2 | IsoMap_Destroy, IsoMap_Save |
| `0x24` | 4 | 3 | IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Save |
| `0x28` | 4 | 3 | IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Save |
| `0x2c` | 4 | 1 | IsoMap_Save |
| `0x30` | 4 | 1 | IsoMap_Save |
| `0x34` | 4 | 1 | IsoMap_Save |
| `0x38` | 4 | 1 | IsoMap_Save |
| `0x3c` | 0 | 1 | IsoMap_Save |
| `0x4c` | 4 | 3 | IsoMap_Destroy, IsoMap_Load, IsoMap_Save |
| `0x50` | 4 | 1 | IsoMap_Destroy |
| `0x54` | 4 | 1 | IsoMap_Destroy |
| `0x60` | 4 | 1 | IsoMap_Save |
| `0x64` | 4 | 1 | IsoMap_Destroy |
| `0x6c` | 4 | 1 | IsoMap_Save |
| `0x70` | 4 | 3 | IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Destroy |
| `0x74` | 4 | 4 | IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Destroy, IsoMap_Load |
| `0x78` | 4 | 3 | IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Destroy |
| `0x7c` | 0 | 2 | IsoMap_Load, IsoMap_Save |
| `0x9c` | 4 | 2 | IsoMap_Destroy, IsoMap_Save |
| `0xa0` | 4 | 2 | IsoMap_Destroy, IsoMap_Save |
| `0xa8` | 4 | 1 | IsoMap_Save |
| `0xb0` | 4 | 1 | IsoMap_Destroy |
| `0xba` | 2 | 1 | IsoMap_Save |
| `0xe8` | 4 | 2 | IsoMap_Construct, IsoMap_ConstructFromStream |
| `0xec` | 4 | 2 | IsoMap_Construct, IsoMap_ConstructFromStream |
| `0xf0` | 4 | 1 | IsoMap_Save |
| `0xf4` | 4 | 1 | IsoMap_Load |
| `0x110` | 4 | 1 | IsoMap_Destroy |
| `0x114` | 4 | 1 | IsoMap_Destroy |
| `0x118` | 4 | 2 | IsoMap_Destroy, IsoMap_Save |
| `0x138` | 4 | 1 | IsoMap_Destroy |
| `0x1015c` | 4 | 2 | IsoMap_Construct, IsoMap_ConstructFromStream |

### PlayerMissionState

- Vtable: `0x55c5e8`
- Constructor: `Player_MissionState_Construct`
- Destructor: `Player_MissionState_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Player_MissionState_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 0 | 2 | Player_MissionState_Load, Player_MissionState_Save |
| `0x10` | 0 | 2 | Player_MissionState_Load, Player_MissionState_Save |
| `0xc0` | 4 | 2 | Player_MissionState_Load, Player_MissionState_Save |
| `0xc4` | 0 | 2 | Player_MissionState_Load, Player_MissionState_Save |
| `0xc8` | 4 | 2 | Player_MissionState_Load, Player_MissionState_Save |
| `0xcc` | 1 | 2 | Player_MissionState_Load, Player_MissionState_Save |
| `0xd0` | 4 | 2 | Player_MissionState_Load, Player_MissionState_Save |
| `0xd4` | 4 | 2 | Player_MissionState_Load, Player_MissionState_Save |

### GameCompanyManager

- Vtable: `0x55c618`
- Constructor: `Game_CompanyManager_Construct`
- Destructor: `Game_CompanyManager_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Game_CompanyManager_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | Game_CompanyManager_Destructor |
| `0x8` | 4 | 2 | Game_CompanyManager_Construct, Game_CompanyManager_Destructor |
| `0xc` | 4 | 1 | Game_CompanyManager_Construct |
| `0x10` | 4 | 1 | Game_CompanyManager_Construct |
| `0x18` | 4 | 2 | Game_CompanyManager_Construct, Game_CompanyManager_Destructor |
| `0x1c` | 4 | 2 | Game_CompanyManager_Construct, Game_CompanyManager_Destructor |
| `0x38` | 4 | 1 | Game_CompanyManager_Construct |

### Player_Event

- Vtable: `0x55c660`
- Constructor: `Player_Event_StreamConstruct`
- Destructor: `AwardNode_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: Player_Event ctor/save/load; slot0 symbol retains legacy AwardNode_Delete name

| # | Method |
|---:|---|
| 0 | `AwardNode_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | Player_Event_Load, Player_Event_Save |
| `0x8` | 2 | 3 | Player_Event_Load, Player_Event_Save, Player_Event_StreamConstruct |

### PlayerAIState

- Vtable: `0x55c664`
- Constructor: `Player_AIState_StreamConstruct`
- Destructor: `Player_AIState_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Player_AIState_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 1 | 2 | Player_AIState_Load, Player_AIState_Save |
| `0x8` | 4 | 2 | Player_AIState_Load, Player_AIState_Save |
| `0xc` | 0 | 2 | Player_AIState_Load, Player_AIState_Save |
| `0x40` | 4 | 2 | Player_AIState_Load, Player_AIState_Save |
| `0x44` | 4 | 2 | Player_AIState_Load, Player_AIState_Save |
| `0x48` | 4 | 2 | Player_AIState_Load, Player_AIState_Save |
| `0x4c` | 4 | 2 | Player_AIState_Load, Player_AIState_Save |
| `0x50` | 4 | 2 | Player_AIState_Load, Player_AIState_Save |
| `0x54` | 4 | 2 | Player_AIState_Load, Player_AIState_Save |
| `0x58` | 4 | 2 | Player_AIState_Load, Player_AIState_Save |
| `0x5c` | 4 | 3 | Player_AIState_Load, Player_AIState_Save, Player_AIState_StreamConstruct |
| `0x60` | 1 | 2 | Player_AIState_Load, Player_AIState_Save |
| `0x64` | 4 | 2 | Player_AIState_Load, Player_AIState_Save |
| `0x7c` | 0 | 1 | Player_AIState_Save |
| `0x84` | 4 | 2 | Player_AIState_Load, Player_AIState_Save |
| `0x88` | 0 | 2 | Player_AIState_Load, Player_AIState_Save |
| `0xa8` | 4 | 1 | Player_AIState_Init |
| `0xac` | 4 | 1 | Player_AIState_Init |
| `0x16c` | 0 | 2 | Player_AIState_Load, Player_AIState_Save |

### WorldObject

- Vtable: `0x55c668`
- Constructor: `Object_Construct`
- Destructor: `WorldObject_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: constructor symbol is Object_Construct (base/sibling name)

| # | Method |
|---:|---|
| 0 | `WorldObject_Delete` * |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x24` | 4 | 1 | Object_Construct |
| `0x28` | 4 | 1 | Object_Construct |
| `0x2c` | 4 | 1 | Object_Construct |
| `0x30` | 4 | 1 | Object_Construct |
| `0x34` | 4 | 1 | Object_Construct |
| `0x38` | 4 | 1 | Object_Construct |
| `0x3c` | 4 | 1 | Object_Construct |
| `0x40` | 2 | 1 | Object_Construct |
| `0x4c` | 4 | 1 | Object_Construct |
| `0x50` | 4 | 1 | Object_Construct |
| `0x54` | 4 | 1 | Object_Construct |
| `0x58` | 4 | 1 | Object_Construct |
| `0x74` | 4 | 1 | Object_Construct |
| `0x78` | 4 | 1 | Object_Construct |
| `0x7c` | 4 | 1 | Object_Construct |
| `0x80` | 1 | 1 | Object_Construct |
| `0x81` | 1 | 1 | Object_Construct |
| `0x84` | 4 | 1 | Object_Construct |
| `0x88` | 4 | 1 | Object_Construct |
| `0x8c` | 4 | 1 | Object_Construct |
| `0x90` | 4 | 1 | Object_Construct |
| `0x94` | 4 | 1 | Object_Construct |
| `0x98` | 4 | 1 | Object_Construct |
| `0x9c` | 4 | 1 | Object_Construct |
| `0xa0` | 4 | 1 | Object_Construct |
| `0xa4` | 4 | 1 | Object_Construct |
| `0xa8` | 4 | 1 | Object_Construct |
| `0xc4` | 4 | 1 | Object_Construct |
| `0xcc` | 4 | 1 | Object_Construct |
| `0xd0` | 4 | 1 | Object_Construct |
| `0xf4` | 4 | 1 | Object_Construct |
| `0xf8` | 4 | 1 | Object_Construct |
| `0x100` | 4 | 1 | Object_Construct |
| `0x104` | 1 | 1 | Object_Construct |
| `0x108` | 4 | 1 | Object_Construct |
| `0x10c` | 4 | 1 | Object_Construct |
| `0x110` | 4 | 1 | Object_Construct |
| `0x164` | 4 | 1 | Object_Construct |
| `0x168` | 4 | 2 | Object_Construct, Person_ConstructFromSave |

### Player

- Vtable: `0x55c684`
- Constructor: `Player_Construct`
- Destructor: `Player_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Player_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 3 | Player_Destroy, Player_Load, Player_Save |
| `0x8` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0xc` | 0 | 2 | Player_Load, Player_Save |
| `0x2c` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x30` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x34` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x38` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x3c` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x40` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x44` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x48` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x4c` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x50` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x54` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x58` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x5c` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x60` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x64` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x68` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x6c` | 0 | 2 | Player_Load, Player_Save |
| `0x84` | 4 | 4 | Player_Construct, Player_Load, Player_ResetAiState, Player_Save |
| `0x88` | 4 | 4 | Player_Construct, Player_Load, Player_ResetAiState, Player_Save |
| `0xa0` | 4 | 2 | Player_Destroy, Player_Save |
| `0xa8` | 4 | 4 | Player_Construct, Player_Destroy, Player_Load, Player_Save |
| `0xac` | 4 | 5 | Player_Construct, Player_Destroy, Player_InitSlotFlags, Player_Load, Player_Save |

### GamePlan

- Vtable: `0x55c688`
- Constructor: `GamePlan_Construct`
- Destructor: `GamePlan_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `GamePlan_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 3 | GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord |
| `0x8` | 4 | 3 | GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord |
| `0xc` | 4 | 3 | GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord |
| `0x10` | 4 | 3 | GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord |
| `0x14` | 4 | 3 | GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord |
| `0x18` | 4 | 3 | GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord |
| `0x1c` | 4 | 3 | GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord |
| `0x20` | 4 | 3 | GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord |
| `0x24` | 4 | 3 | GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord |
| `0x28` | 4 | 3 | GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord |
| `0x2c` | 4 | 3 | GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord |

### Recipe

- Vtable: `0x55c698`
- Constructor: `Recipe_Construct`
- Destructor: `Recipe_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Recipe_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x44` | 4 | 4 | Recipe_Construct, Recipe_CreateGenerated, Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x5c` | 0 | 1 | Recipe_SaveToStream |
| `0x64` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x1bc` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x1d8` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x1dc` | 1 | 4 | Recipe_Construct, Recipe_CreateGenerated, Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x1dd` | 1 | 2 | Recipe_Construct, Recipe_CreateGenerated |
| `0x1e0` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x240` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x244` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x248` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x24c` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x250` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x254` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x258` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x264` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x284` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x2a4` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x2c4` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x304` | 4 | 4 | Recipe_Construct, Recipe_CreateGenerated, Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x308` | 4 | 4 | Recipe_Construct, Recipe_CreateGenerated, Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x30c` | 4 | 3 | Recipe_Construct, Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x310` | 4 | 2 | Recipe_CreateGenerated, Recipe_StreamConstruct |
| `0x318` | 0 | 1 | Recipe_CreateGenerated |
| `0x31c` | 0 | 1 | Recipe_CreateGenerated |
| `0x320` | 0 | 1 | Recipe_CreateGenerated |
| `0x324` | 0 | 1 | Recipe_CreateGenerated |
| `0x328` | 0 | 1 | Recipe_CreateGenerated |
| `0x32c` | 0 | 1 | Recipe_CreateGenerated |

### Storage

- Vtable: `0x55c700`
- Constructor: `Storage_Construct`
- Destructor: `Storage_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Storage_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 0 | 2 | Storage_LoadRecord, Storage_SaveRecord |
| `0x24` | 4 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x28` | 4 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x2c` | 4 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x30` | 4 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x34` | 4 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x38` | 4 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x3c` | 1 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x40` | 4 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x58` | 0 | 1 | Storage_SaveRecord |
| `0x60` | 0 | 2 | Storage_LoadRecord, Storage_SaveRecord |

### UI_ImageElement

- Vtable: `0x55c704`
- Constructor: `UI_Image_Construct`
- Destructor: `UI_ImageElement_Delete`
- Base guess: `UI_Child`
- Slots: 7
- Naming notes: constructor symbol is UI_Image_Construct (base/sibling name)

| # | Method |
|---:|---|
| 0 | `UI_ImageElement_Delete` |
| 1 | `UI_ImageElement_vfunc1` * |
| 2 | `UI_ImageElement_vfunc2` * |
| 3 | `UI_ImageElement_vfunc3` * |
| 4 | `UI_ImageElement_vfunc4` * |
| 5 | `UI_Child_ForwardToVFunc4` * |
| 6 | `UI_Child_InvokeCallback` * |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | UI_ImageElement_Destroy |
| `0x28` | 4 | 1 | UI_Image_Construct |
| `0x2c` | 4 | 1 | UI_Image_Construct |
| `0x30` | 4 | 1 | UI_Image_Construct |
| `0x34` | 4 | 1 | UI_Image_Construct |
| `0x40` | 4 | 1 | UI_Image_Construct |
| `0x164` | 4 | 1 | UI_Image_Construct |
| `0x168` | 4 | 1 | UI_Image_Construct |
| `0x16c` | 4 | 1 | UI_Image_Construct |
| `0x170` | 4 | 1 | UI_Image_Construct |

### UI_Child

- Vtable: `0x55c720`
- Constructor: `UI_Child_Construct`
- Destructor: `UI_Child_Delete`
- Base guess: ``
- Slots: 7
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `UI_Child_Delete` |
| 1 | `_purecall` * |
| 2 | `_purecall` * |
| 3 | `_purecall` * |
| 4 | `UI_Child_ReturnTrue` * |
| 5 | `UI_Child_ForwardToVFunc4` * |
| 6 | `UI_Child_InvokeCallback` * |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | UI_Child_Construct |
| `0x8` | 4 | 1 | UI_Child_Construct |
| `0xc` | 4 | 2 | UI_Child_Construct, UI_Child_Destroy |
| `0x10` | 4 | 2 | UI_Child_Construct, UI_Child_Destroy |
| `0x14` | 4 | 1 | UI_Child_Construct |
| `0x18` | 4 | 1 | UI_Child_Construct |
| `0x1c` | 4 | 1 | UI_Child_Construct |
| `0x20` | 4 | 1 | UI_Child_Construct |
| `0x24` | 4 | 1 | UI_Child_Construct |
| `0x28` | 4 | 1 | UI_Child_Construct |
| `0x2c` | 4 | 1 | UI_Child_Construct |
| `0x30` | 4 | 1 | UI_Child_Construct |
| `0x34` | 4 | 1 | UI_Child_Construct |
| `0x38` | 4 | 1 | UI_Child_Construct |
| `0x3c` | 4 | 1 | UI_Child_Construct |
| `0x44` | 4 | 1 | UI_Child_Construct |
| `0x48` | 4 | 1 | UI_Child_Construct |
| `0x4c` | 4 | 1 | UI_Child_Construct |
| `0x50` | 4 | 1 | UI_Child_Construct |

### UI_Viewport

- Vtable: `0x55c73c`
- Constructor: `UI_ImageChild_Construct`
- Destructor: `UI_Viewport_Delete`
- Base guess: `UI_Child`
- Slots: 7
- Naming notes: constructor symbol is UI_ImageChild_Construct (base/sibling name)

| # | Method |
|---:|---|
| 0 | `UI_Viewport_Delete` |
| 1 | `UI_UpdateCustomControl` |
| 2 | `UI_Viewport_GetTypeId` * |
| 3 | `UI_Child_HandleControlCommand` |
| 4 | `UI_Viewport_vfunc4` * |
| 5 | `UI_Child_ForwardToVFunc4` * |
| 6 | `UI_Viewport_vfunc6` * |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | UI_CustomControl_Destructor |
| `0x38` | 4 | 1 | UI_CustomControl_Destructor |
| `0x3c` | 4 | 1 | UI_CustomControl_Destructor |
| `0x40` | 4 | 1 | UI_ImageChild_Construct |
| `0x60` | 4 | 2 | UI_CustomControl_Destructor, UI_ImageChild_Construct |
| `0x64` | 4 | 1 | UI_CustomControl_Destructor |
| `0x68` | 4 | 2 | UI_CustomControl_Destructor, UI_ImageChild_Construct |
| `0x6c` | 4 | 1 | UI_CustomControl_Destructor |
| `0x7c` | 4 | 2 | UI_CustomControl_Destructor, UI_ImageChild_Construct |
| `0x80` | 4 | 2 | UI_CustomControl_Destructor, UI_ImageChild_Construct |
| `0x98` | 4 | 1 | UI_ImageChild_Construct |

### UI_LabelElement

- Vtable: `0x55c758`
- Constructor: `UI_TextLabel_Construct`
- Destructor: `UI_LabelElement_Delete`
- Base guess: `UI_Child`
- Slots: 7
- Naming notes: constructor symbol is UI_TextLabel_Construct (base/sibling name)

| # | Method |
|---:|---|
| 0 | `UI_LabelElement_Delete` |
| 1 | `UI_LabelElement_vfunc1` * |
| 2 | `UI_LabelElement_vfunc2` * |
| 3 | `UI_LabelElement_vfunc3` * |
| 4 | `UI_Child_ReturnTrue` * |
| 5 | `UI_Child_ForwardToVFunc4` * |
| 6 | `UI_Child_InvokeCallback` * |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | UI_LabelElement_Destroy |
| `0x40` | 4 | 1 | UI_TextLabel_Construct |
| `0x54` | 4 | 1 | UI_TextLabel_Construct |
| `0x58` | 4 | 1 | UI_TextLabel_Construct |
| `0x5c` | 4 | 1 | UI_TextLabel_Construct |
| `0x60` | 4 | 1 | UI_TextLabel_Construct |
| `0x64` | 4 | 1 | UI_TextLabel_Construct |
| `0x68` | 4 | 1 | UI_TextLabel_Construct |
| `0x6c` | 4 | 2 | UI_LabelElement_Destroy, UI_TextLabel_Construct |
| `0x70` | 4 | 2 | UI_LabelElement_Destroy, UI_TextLabel_Construct |
| `0x74` | 4 | 1 | UI_TextLabel_Construct |
| `0x78` | 4 | 1 | UI_TextLabel_Construct |
| `0x7c` | 4 | 1 | UI_TextLabel_Construct |
| `0x80` | 4 | 1 | UI_TextLabel_Construct |
| `0x84` | 4 | 1 | UI_TextLabel_Construct |
| `0x88` | 4 | 1 | UI_TextLabel_Construct |
| `0x98` | 4 | 1 | UI_TextLabel_Construct |

### Array

- Vtable: `0x55c774`
- Constructor: `Array_Construct`
- Destructor: `Array_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Array_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | Array_Construct, Array_Destroy |
| `0x8` | 4 | 1 | Array_Construct |
| `0xc` | 4 | 1 | Array_Construct |
| `0x10` | 4 | 1 | Array_Construct |

### UI_Manager

- Vtable: `0x55c778`
- Constructor: `UI_Manager_Construct`
- Destructor: `UI_Manager_ScalarDeletingDestructor`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `UI_Manager_ScalarDeletingDestructor` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | UI_Manager_Construct |
| `0xc` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x10` | 4 | 1 | UI_Manager_Construct |
| `0x40` | 4 | 1 | UI_Manager_Construct |
| `0x98` | 4 | 1 | UI_Manager_Construct |
| `0x1a4` | 4 | 1 | UI_Manager_Construct |
| `0x1b4` | 4 | 1 | UI_Manager_Construct |
| `0x1b8` | 4 | 1 | UI_Manager_Construct |
| `0x1bc` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x1c0` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x1c4` | 4 | 1 | UI_Manager_Construct |
| `0x1c8` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x224` | 4 | 1 | UI_Manager_Construct |
| `0x228` | 4 | 1 | UI_Manager_Construct |
| `0x22c` | 4 | 1 | UI_Manager_Construct |
| `0x230` | 4 | 1 | UI_Manager_Construct |
| `0x234` | 4 | 1 | UI_Manager_Construct |
| `0x238` | 4 | 1 | UI_Manager_Construct |
| `0x23c` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x240` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x244` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x248` | 4 | 1 | UI_Manager_Construct |
| `0x24c` | 4 | 1 | UI_Manager_Construct |
| `0x270` | 4 | 1 | UI_Manager_Construct |
| `0x274` | 4 | 1 | UI_Manager_Construct |
| `0x278` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x280` | 4 | 1 | UI_Manager_Destroy |
| `0x284` | 4 | 1 | UI_Manager_Construct |
| `0x288` | 4 | 1 | UI_Manager_Construct |
| `0x28c` | 4 | 1 | UI_Manager_Construct |
| `0x290` | 4 | 1 | UI_Manager_Construct |
| `0x294` | 4 | 1 | UI_Manager_Construct |
| `0x298` | 4 | 1 | UI_Manager_Construct |
| `0x29c` | 4 | 1 | UI_Manager_Construct |
| `0x2a0` | 4 | 1 | UI_Manager_Construct |
| `0x2a4` | 4 | 1 | UI_Manager_Construct |
| `0x2a8` | 4 | 1 | UI_Manager_Construct |
| `0x2ac` | 1 | 1 | UI_Manager_Construct |
| `0x2b0` | 0 | 1 | UI_Manager_Construct |
| `0x32b4` | 4 | 1 | UI_Manager_Construct |
| `0x32b8` | 4 | 1 | UI_Manager_Construct |
| `0x82bc` | 4 | 1 | UI_Manager_Construct |
| `0x82c0` | 4 | 1 | UI_Manager_Construct |
| `0x82c4` | 4 | 1 | UI_Manager_Construct |
| `0x82c8` | 4 | 1 | UI_Manager_Construct |
| `0x82cc` | 4 | 1 | UI_Manager_Construct |
| `0x82d0` | 4 | 1 | UI_Manager_Construct |
| `0x82d4` | 4 | 1 | UI_Manager_Construct |
| `0x82d8` | 4 | 1 | UI_Manager_Construct |
| `0x82dc` | 4 | 1 | UI_Manager_Construct |
| `0x82e0` | 4 | 1 | UI_Manager_Construct |
| `0x82e4` | 4 | 1 | UI_Manager_Construct |
| `0x82e8` | 4 | 1 | UI_Manager_Construct |
| `0x82ec` | 4 | 1 | UI_Manager_Construct |
| `0x82f4` | 4 | 1 | UI_Manager_Construct |
| `0x82f8` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x82fc` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x8300` | 4 | 1 | UI_Manager_Construct |
| `0x8304` | 4 | 1 | UI_Manager_Construct |
| `0x8308` | 4 | 1 | UI_Manager_Construct |
| `0x830c` | 4 | 1 | UI_Manager_Construct |
| `0x8310` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x8314` | 4 | 1 | UI_Manager_Construct |
| `0x8318` | 4 | 1 | UI_Manager_Construct |
| `0x831c` | 4 | 1 | UI_Manager_Construct |
| `0x8320` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x8338` | 4 | 1 | UI_Manager_Construct |
| `0x833c` | 4 | 1 | UI_Manager_Construct |
| `0x8340` | 4 | 1 | UI_Manager_Construct |
| `0x8344` | 4 | 1 | UI_Manager_Construct |
| `0x8348` | 4 | 1 | UI_Manager_Construct |
| `0x834c` | 4 | 1 | UI_Manager_Construct |
| `0x8350` | 4 | 1 | UI_Manager_Construct |
| `0x8354` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x8358` | 4 | 1 | UI_Manager_Construct |
| `0x839c` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x83a0` | 4 | 1 | UI_Manager_Construct |
| `0x83a4` | 4 | 1 | UI_Manager_Construct |
| `0x83a8` | 4 | 1 | UI_Manager_Construct |
| `0x83ac` | 4 | 2 | UI_Manager_Construct, UI_Manager_Destroy |
| `0x83b8` | 4 | 1 | UI_Manager_Construct |
| `0x83e0` | 4 | 1 | UI_Manager_Construct |
| `0x83e4` | 4 | 1 | UI_Manager_Construct |

### UI_ContextMenu

- Vtable: `0x55c788`
- Constructor: `ContextMenu_Construct`
- Destructor: `UI_ContextMenu_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: constructor symbol is ContextMenu_Construct (base/sibling name)

| # | Method |
|---:|---|
| 0 | `UI_ContextMenu_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 0 | 1 | ContextMenu_Construct |
| `0x28` | 4 | 1 | ContextMenu_Construct |
| `0x2c` | 4 | 1 | ContextMenu_Construct |
| `0x38` | 4 | 1 | ContextMenu_Construct |
| `0x3c` | 4 | 1 | ContextMenu_Construct |
| `0x44` | 4 | 1 | ContextMenu_Construct |
| `0x48` | 4 | 1 | ContextMenu_Construct |
| `0x50` | 4 | 2 | ContextMenu_Construct, UI_ContextMenu_Destroy |
| `0x54` | 4 | 2 | ContextMenu_Construct, UI_ContextMenu_Destroy |
| `0x5c` | 4 | 1 | ContextMenu_Construct |
| `0x60` | 4 | 1 | ContextMenu_Construct |
| `0x64` | 4 | 1 | ContextMenu_Construct |
| `0x68` | 4 | 2 | ContextMenu_Construct, UI_ContextMenu_Destroy |

### UI_Slider

- Vtable: `0x55c78c`
- Constructor: `UI_Bar_Construct`
- Destructor: `UI_Slider_Delete`
- Base guess: `UI_Child`
- Slots: 7
- Naming notes: constructor symbol is UI_Bar_Construct (base/sibling name)

| # | Method |
|---:|---|
| 0 | `UI_Slider_Delete` |
| 1 | `UI_Slider_vfunc1` * |
| 2 | `UI_BuildListItem` |
| 3 | `UI_Slider_vfunc3` * |
| 4 | `UI_Slider_vfunc4` * |
| 5 | `UI_Slider_ReturnTrue` * |
| 6 | `UI_Child_InvokeCallback` * |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | UI_Slider_Destroy |
| `0x28` | 4 | 1 | UI_Bar_Construct |
| `0x2c` | 4 | 1 | UI_Bar_Construct |
| `0x30` | 4 | 1 | UI_Bar_Construct |
| `0x34` | 4 | 1 | UI_Bar_Construct |
| `0x40` | 4 | 1 | UI_Bar_Construct |
| `0x54` | 4 | 1 | UI_Bar_Construct |
| `0x58` | 4 | 1 | UI_Bar_Construct |
| `0x5c` | 4 | 1 | UI_Bar_Construct |
| `0x60` | 4 | 1 | UI_Bar_Construct |
| `0x64` | 4 | 1 | UI_Bar_Construct |
| `0x68` | 4 | 1 | UI_Bar_Construct |
| `0x84` | 4 | 1 | UI_Bar_Construct |
| `0x88` | 4 | 1 | UI_Bar_Construct |
| `0x94` | 4 | 1 | UI_Bar_Construct |
| `0x98` | 4 | 1 | UI_Bar_Construct |
| `0x9c` | 4 | 1 | UI_Bar_Construct |
| `0xa0` | 4 | 1 | UI_Bar_Construct |
| `0xa4` | 4 | 1 | UI_Bar_Construct |
| `0xa8` | 4 | 1 | UI_Bar_Construct |
| `0xac` | 4 | 1 | UI_Bar_Construct |
| `0xb4` | 4 | 1 | UI_Bar_Construct |
| `0xb8` | 4 | 1 | UI_Bar_Construct |
| `0xbc` | 4 | 2 | UI_Bar_Construct, UI_Slider_Destroy |
| `0xc0` | 4 | 1 | UI_Bar_Construct |
| `0xc4` | 4 | 1 | UI_Bar_Construct |
| `0xc8` | 4 | 1 | UI_Bar_Construct |
| `0xcc` | 4 | 1 | UI_Bar_Construct |
| `0xd0` | 4 | 1 | UI_Bar_Construct |
| `0xd4` | 4 | 1 | UI_Bar_Construct |
| `0xd8` | 4 | 1 | UI_Bar_Construct |
| `0xdc` | 4 | 1 | UI_Bar_Construct |
| `0x1ec` | 0 | 1 | UI_Bar_Construct |
| `0x230` | 0 | 1 | UI_Bar_Construct |
| `0x274` | 0 | 1 | UI_Bar_Construct |
| `0x344` | 4 | 2 | UI_Bar_Construct, UI_Slider_Destroy |
| `0x388` | 4 | 1 | UI_Bar_Construct |
| `0x4f0` | 4 | 1 | UI_Bar_Construct |
| `0x4f4` | 4 | 1 | UI_Bar_Construct |

### MovieWindow

- Vtable: `0x55c7b0`
- Constructor: `MovieWindow_Construct`
- Destructor: `MovieWindow_Delete`
- Base guess: `UI_Child`
- Slots: 7
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `MovieWindow_Delete` |
| 1 | `Map_DrawRenderableByType` |
| 2 | `MovieWindow_vfunc2` * |
| 3 | `MovieWindow_vfunc3` * |
| 4 | `MovieWindow_IsPlaying` * |
| 5 | `UI_Child_ForwardToVFunc4` * |
| 6 | `Movie_UpdateFrame` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | MovieWindow_Destroy |
| `0x15` | 1 | 1 | MovieWindow_Destroy |
| `0x28` | 4 | 1 | MovieWindow_Construct |
| `0x2c` | 4 | 1 | MovieWindow_Construct |
| `0x40` | 4 | 1 | MovieWindow_Construct |
| `0x54` | 4 | 1 | MovieWindow_Destroy |
| `0x94` | 4 | 2 | MovieWindow_Construct, MovieWindow_Destroy |
| `0x98` | 4 | 2 | MovieWindow_Construct, MovieWindow_Destroy |
| `0x9c` | 4 | 1 | MovieWindow_Construct |
| `0xa0` | 4 | 2 | MovieWindow_Construct, MovieWindow_Destroy |
| `0xa4` | 4 | 2 | MovieWindow_Construct, MovieWindow_Destroy |
| `0xa8` | 4 | 1 | MovieWindow_Construct |
| `0xac` | 4 | 2 | MovieWindow_Construct, MovieWindow_Destroy |
| `0xb0` | 4 | 1 | MovieWindow_Construct |
| `0xb4` | 4 | 1 | MovieWindow_Construct |
| `0xb8` | 4 | 2 | MovieWindow_Construct, MovieWindow_Destroy |

### UI_TextElement

- Vtable: `0x55c7cc`
- Constructor: `UI_Text_Construct`
- Destructor: `UI_TextElement_Delete`
- Base guess: `UI_Child`
- Slots: 7
- Naming notes: constructor symbol is UI_Text_Construct (base/sibling name)

| # | Method |
|---:|---|
| 0 | `UI_TextElement_Delete` |
| 1 | `UI_TextElement_vfunc1` * |
| 2 | `UI_TextElement_vfunc2` * |
| 3 | `UI_TextElement_vfunc3` * |
| 4 | `UI_Child_ReturnTrue` * |
| 5 | `UI_Child_ForwardToVFunc4` * |
| 6 | `UI_Child_InvokeCallback` * |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | UI_TextElement_Destroy |
| `0x14` | 4 | 1 | UI_Text_Construct |
| `0x40` | 4 | 1 | UI_Text_Construct |
| `0x54` | 4 | 2 | UI_TextElement_Destroy, UI_Text_Construct |
| `0x58` | 4 | 1 | UI_Text_Construct |
| `0x60` | 4 | 1 | UI_Text_Construct |
| `0x64` | 2 | 1 | UI_Text_Construct |
| `0x66` | 2 | 1 | UI_Text_Construct |
| `0x6c` | 4 | 1 | UI_Text_Construct |
| `0x70` | 4 | 1 | UI_Text_Construct |
| `0x74` | 4 | 2 | UI_TextElement_Destroy, UI_Text_Construct |
| `0x78` | 4 | 1 | UI_Text_Construct |
| `0x88` | 4 | 2 | UI_TextElement_Destroy, UI_Text_Construct |

### UI_ButtonElement

- Vtable: `0x55c7e8`
- Constructor: `UI_TextPanel_Construct`
- Destructor: `UI_ButtonElement_Delete`
- Base guess: `UI_Child`
- Slots: 7
- Naming notes: constructor symbol is UI_TextPanel_Construct (base/sibling name)

| # | Method |
|---:|---|
| 0 | `UI_ButtonElement_Delete` |
| 1 | `UI_ButtonElement_vfunc1` * |
| 2 | `UI_ButtonElement_vfunc2` * |
| 3 | `UI_ButtonElement_vfunc3` * |
| 4 | `UI_Child_ReturnTrue` * |
| 5 | `UI_Child_ForwardToVFunc4` * |
| 6 | `UI_Child_InvokeCallback` * |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | UI_ButtonElement_Destroy |
| `0x28` | 2 | 1 | UI_TextPanel_Construct |
| `0x2c` | 2 | 1 | UI_TextPanel_Construct |
| `0x30` | 2 | 1 | UI_TextPanel_Construct |
| `0x34` | 2 | 1 | UI_TextPanel_Construct |
| `0x40` | 4 | 1 | UI_TextPanel_Construct |
| `0x54` | 4 | 2 | UI_ButtonElement_Destroy, UI_TextPanel_Construct |
| `0x58` | 4 | 2 | UI_ButtonElement_Destroy, UI_TextPanel_Construct |
| `0x9c` | 0 | 1 | UI_TextPanel_Construct |
| `0x38c` | 4 | 1 | UI_TextPanel_Construct |
| `0x390` | 4 | 1 | UI_TextPanel_Construct |
| `0x394` | 4 | 1 | UI_TextPanel_Construct |
| `0x398` | 4 | 1 | UI_TextPanel_Construct |
| `0x39c` | 0 | 1 | UI_TextPanel_Construct |
| `0x3a0` | 4 | 1 | UI_TextPanel_Construct |
| `0x3a4` | 4 | 1 | UI_TextPanel_Construct |
| `0x3a8` | 4 | 1 | UI_TextPanel_Construct |
| `0x3ac` | 4 | 1 | UI_TextPanel_Construct |
| `0x3b0` | 4 | 1 | UI_TextPanel_Construct |
| `0x3b2` | 2 | 1 | UI_TextPanel_Construct |
| `0x3b4` | 4 | 1 | UI_TextPanel_Construct |
| `0x3b8` | 4 | 1 | UI_TextPanel_Construct |
| `0x3bc` | 4 | 1 | UI_TextPanel_Construct |
| `0x3c0` | 4 | 1 | UI_TextPanel_Construct |
| `0x3c4` | 4 | 1 | UI_TextPanel_Construct |

### UI_Tooltip

- Vtable: `0x55c804`
- Constructor: `Tooltip_Construct`
- Destructor: `UI_Tooltip_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: constructor symbol is Tooltip_Construct (base/sibling name)

| # | Method |
|---:|---|
| 0 | `UI_Tooltip_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | Tooltip_Construct |
| `0x8` | 4 | 1 | Tooltip_Construct |
| `0xc` | 4 | 1 | Tooltip_Construct |
| `0x10` | 4 | 1 | Tooltip_Construct |
| `0x14` | 4 | 1 | Tooltip_Construct |
| `0x18` | 4 | 2 | Tooltip_Construct, UI_Tooltip_Destroy |
| `0x1c` | 4 | 2 | Tooltip_Construct, UI_Tooltip_Destroy |
| `0x20` | 4 | 1 | Tooltip_Construct |
| `0x24` | 4 | 1 | Tooltip_Construct |
| `0x28` | 4 | 1 | Tooltip_Construct |
| `0x2c` | 4 | 1 | Tooltip_Construct |
| `0x30` | 4 | 2 | Tooltip_Construct, UI_Tooltip_Destroy |
| `0x38` | 4 | 2 | Tooltip_Construct, UI_Tooltip_Destroy |
| `0x3c` | 4 | 1 | Tooltip_Construct |

### Dialog

- Vtable: `0x55c808`
- Constructor: `Dialog_Construct`
- Destructor: `Dialog_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Dialog_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | Dialog_InitBase |
| `0x8` | 4 | 1 | Dialog_ConstructFixed |
| `0xc` | 4 | 1 | Dialog_ConstructFixed |
| `0x10` | 4 | 1 | Dialog_ConstructFixed |
| `0x14` | 4 | 1 | Dialog_ConstructFixed |
| `0x15` | 1 | 1 | Dialog_Destructor |
| `0x18` | 4 | 1 | Dialog_ConstructFixed |
| `0x1c` | 4 | 1 | Dialog_ConstructFixed |
| `0x20` | 4 | 1 | Dialog_ConstructFixed |
| `0x24` | 4 | 1 | Dialog_ConstructFixed |
| `0x28` | 4 | 1 | Dialog_SaveToFile |
| `0x2c` | 4 | 1 | Dialog_SaveToFile |
| `0x30` | 4 | 1 | Dialog_SaveToFile |
| `0x34` | 4 | 1 | Dialog_SaveToFile |
| `0x48` | 4 | 1 | Dialog_InitBase |
| `0x4c` | 4 | 1 | Dialog_InitBase |
| `0x50` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0x54` | 1 | 2 | Dialog_ConstructWithSprite, Dialog_InitBase |
| `0x94` | 4 | 4 | Dialog_ConstructWithSprite, Dialog_Destructor, Dialog_InitBase, Dialog_SaveToFile |
| `0xd8` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0xdc` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0xe0` | 4 | 1 | Dialog_InitBase |
| `0xe4` | 4 | 1 | Dialog_InitBase |
| `0xe8` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0xec` | 4 | 3 | Dialog_Destructor, Dialog_InitBase, Dialog_SaveToFile |
| `0xf0` | 4 | 3 | Dialog_Destructor, Dialog_InitBase, Dialog_SaveToFile |
| `0xf4` | 4 | 1 | Dialog_InitBase |
| `0xf8` | 1 | 5 | Dialog_ConstructWithPicture, Dialog_ConstructWithSprite, Dialog_Destructor, Dialog_InitBase, Dialog_SaveToFile |
| `0xfc` | 4 | 4 | Dialog_Construct, Dialog_ConstructFixed, Dialog_InitBase, Dialog_SaveToFile |
| `0x100` | 4 | 3 | Dialog_ConstructFixed, Dialog_InitBase, Dialog_SaveToFile |
| `0x104` | 4 | 3 | Dialog_ConstructFixed, Dialog_InitBase, Dialog_SaveToFile |
| `0x108` | 4 | 3 | Dialog_ConstructFixed, Dialog_InitBase, Dialog_SaveToFile |
| `0x10c` | 4 | 1 | Dialog_InitBase |
| `0x114` | 4 | 2 | Dialog_InitBase, Dialog_SaveToFile |
| `0x118` | 0 | 1 | Dialog_ConstructFixed |
| `0x120` | 0 | 1 | Dialog_ConstructFixed |
| `0x128` | 0 | 1 | Dialog_ConstructFixed |
| `0x130` | 0 | 1 | Dialog_ConstructFixed |
| `0x134` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0x138` | 4 | 4 | Dialog_ConstructWithPicture, Dialog_Destructor, Dialog_InitBase, Dialog_SaveToFile |
| `0x13c` | 4 | 1 | Dialog_InitBase |
| `0x15c` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0x160` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0x164` | 4 | 1 | Dialog_InitBase |
| `0x168` | 4 | 2 | Dialog_InitBase, Dialog_SaveToFile |
| `0x16c` | 4 | 1 | Dialog_InitBase |
| `0x170` | 4 | 1 | Dialog_InitBase |
| `0x174` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0x178` | 1 | 1 | Dialog_InitBase |
| `0x27c` | 4 | 1 | Dialog_InitBase |
| `0x284` | 4 | 1 | Dialog_InitBase |
| `0x28c` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0x290` | 4 | 1 | Dialog_Destructor |
| `0x298` | 4 | 1 | Dialog_InitBase |
| `0x29c` | 4 | 1 | Dialog_InitBase |
| `0x2bc` | 4 | 1 | Dialog_InitBase |
| `0x2c0` | 4 | 1 | Dialog_InitBase |
| `0x2c4` | 4 | 1 | Dialog_ConstructFixed |

### SpriteFile

- Vtable: `0x55c80c`
- Constructor: `Anim_Load`
- Destructor: `Animation_ScalarDeletingDestructor`
- Base guess: `SpriteBase`
- Slots: 1
- Naming notes: constructor symbol is Anim_Load (base/sibling name)

| # | Method |
|---:|---|
| 0 | `Animation_ScalarDeletingDestructor` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 1 | 1 | Anim_Load |
| `0x5` | 1 | 1 | Anim_Load |
| `0xd` | 1 | 1 | SpriteFile_Destruct |
| `0x18` | 1 | 1 | Anim_Load |
| `0x1c` | 4 | 1 | Anim_Load |
| `0x20` | 4 | 2 | Anim_Load, SpriteFile_Destruct |
| `0x24` | 1 | 1 | Anim_Load |
| `0x28` | 1 | 1 | Anim_Load |
| `0x2c` | 1 | 1 | Anim_Load |
| `0x30` | 4 | 2 | Anim_Load, SpriteFile_Destruct |
| `0x34` | 1 | 1 | Anim_Load |
| `0x35` | 1 | 2 | Anim_Load, SpriteFile_Destruct |
| `0x38` | 4 | 2 | Anim_Load, SpriteFile_Destruct |
| `0x3c` | 4 | 1 | Anim_Load |
| `0x40` | 4 | 1 | Anim_Load |
| `0x44` | 0 | 1 | Anim_Load |
| `0x48` | 4 | 1 | Anim_Load |
| `0x4c` | 4 | 2 | Anim_Load, SpriteFile_Destruct |
| `0x50` | 4 | 2 | Anim_Load, SpriteFile_Destruct |
| `0x54` | 4 | 1 | Anim_Load |
| `0x68` | 4 | 1 | Anim_Load |
| `0x70` | 4 | 1 | Anim_Load |
| `0x78` | 4 | 2 | Anim_Load, SpriteFile_Destruct |
| `0x7c` | 4 | 1 | Anim_Load |
| `0x80` | 4 | 2 | Anim_Load, SpriteFile_Destruct |
| `0x88` | 4 | 2 | Anim_Load, SpriteFile_Destruct |
| `0x90` | 4 | 1 | Anim_Load |
| `0x94` | 4 | 1 | Anim_Load |

### Gfx_RectList

- Vtable: `0x55c810`
- Constructor: `Gfx_RectList_Construct`
- Destructor: `Gfx_RectList_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Gfx_RectList_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | Gfx_RectList_Construct |
| `0x8` | 4 | 1 | Gfx_RectList_Construct |
| `0xc` | 4 | 1 | Gfx_RectList_Construct |
| `0x10` | 4 | 1 | Gfx_RectList_Construct |
| `0x14` | 4 | 2 | Gfx_RectList_Construct, Gfx_RectList_Destroy |

### Window

- Vtable: `0x55c814`
- Constructor: `Window_Construct`
- Destructor: `Window_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Window_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | FullscreenImage_Load, Window_Construct |
| `0x8` | 4 | 2 | FullscreenImage_Load, Window_Construct |
| `0xc` | 4 | 1 | Window_Construct |
| `0x10` | 1 | 2 | Window_Construct, Window_LoadSpriteCached |
| `0x11` | 1 | 2 | FullscreenImage_Load, Window_Construct |
| `0x14` | 4 | 3 | FullscreenImage_Load, Window_Construct, Window_Destroy |
| `0x18` | 4 | 3 | FullscreenImage_Load, Window_Construct, Window_Destroy |
| `0x82f8` | 4 | 1 | Window_LoadSpriteCached |
| `0x82fc` | 4 | 1 | Window_LoadSpriteCached |
| `0x8300` | 4 | 1 | Window_LoadSpriteCached |

### Renderer

- Vtable: `0x55c818`
- Constructor: `Renderer_ConstructRoot`
- Destructor: `Renderer_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Renderer_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0xc` | 1 | 1 | Renderer_Destroy |
| `0x14` | 4 | 2 | Renderer_ConstructChild, Renderer_ConstructRoot |
| `0x18` | 1 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x1a` | 2 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x1c` | 2 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x24` | 4 | 1 | Renderer_InitOrCopyState |
| `0x2c` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x30` | 1 | 2 | Renderer_ConstructChild, Renderer_ConstructRoot |
| `0x34` | 4 | 1 | Renderer_InitOrCopyState |
| `0x38` | 4 | 1 | Renderer_InitOrCopyState |
| `0x3c` | 4 | 1 | Renderer_InitOrCopyState |
| `0x40` | 4 | 5 | Renderer_ConstructChild, Renderer_ConstructRoot, Renderer_Destroy, Renderer_InitForWindow, Renderer_InitOrCopyState |
| `0x44` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x48` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x4c` | 4 | 2 | Renderer_ConstructChild, Renderer_ConstructRoot |
| `0x50` | 4 | 3 | Renderer_ConstructChild, Renderer_ConstructRoot, Renderer_Destroy |
| `0x54` | 4 | 4 | Renderer_ConstructChild, Renderer_ConstructRoot, Renderer_Destroy, Renderer_InitOrCopyState |
| `0x58` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x5c` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x60` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x74` | 4 | 1 | Renderer_InitOrCopyState |
| `0x78` | 4 | 2 | Renderer_ConstructChild, Renderer_ConstructRoot |
| `0x7c` | 4 | 2 | Renderer_ConstructChild, Renderer_ConstructRoot |
| `0x80` | 4 | 2 | Renderer_ConstructChild, Renderer_ConstructRoot |
| `0x84` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x88` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x8c` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x90` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x94` | 4 | 3 | Renderer_ConstructRoot, Renderer_InitForWindow, Renderer_InitOrCopyState |
| `0x98` | 4 | 1 | Renderer_ConstructRoot |

### SpriteBase

- Vtable: `0x55c828`
- Constructor: `SpriteBase_Construct`
- Destructor: `SpriteBase_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: vptr-only base class; no data members observed

| # | Method |
|---:|---|
| 0 | `SpriteBase_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|

### Sprite

- Vtable: `0x55c82c`
- Constructor: `Sprite_CreateRaw`
- Destructor: `Sprite_ScalarDeletingDestructor`
- Base guess: `SpriteBase`
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `Sprite_ScalarDeletingDestructor` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 1 | 4 | Sprite_CreateRaw, Sprite_InitFormat, Sprite_Load, Sprite_LoadIntoSlot78 |
| `0x5` | 1 | 2 | Sprite_InitFormat, Sprite_Load |
| `0x6` | 2 | 1 | Sprite_InitFormat |
| `0x8` | 2 | 1 | Sprite_InitFormat |
| `0xa` | 2 | 1 | Sprite_InitFormat |
| `0xc` | 2 | 1 | Sprite_InitFormat |
| `0xd` | 1 | 1 | Sprite_Destruct |
| `0xe` | 2 | 1 | Sprite_CreateRaw |
| `0x10` | 2 | 1 | Sprite_CreateRaw |
| `0x12` | 2 | 1 | Sprite_InitFormat |
| `0x14` | 2 | 1 | Sprite_InitFormat |
| `0x18` | 4 | 3 | Sprite_CreateRaw, Sprite_InitFormat, Sprite_Load |
| `0x1c` | 4 | 1 | Sprite_InitFormat |
| `0x20` | 4 | 3 | Sprite_CreateRaw, Sprite_Destruct, Sprite_Load |
| `0x24` | 4 | 3 | Sprite_CreateRaw, Sprite_Destruct, Sprite_Load |
| `0x28` | 4 | 2 | Sprite_CreateRaw, Sprite_Load |
| `0x2c` | 4 | 3 | Sprite_CreateRaw, Sprite_Destruct, Sprite_Load |
| `0x30` | 4 | 3 | Sprite_CreateRaw, Sprite_Destruct, Sprite_Load |
| `0x34` | 1 | 2 | Sprite_CreateRaw, Sprite_Load |
| `0x35` | 1 | 1 | Sprite_Load |
| `0x36` | 1 | 2 | Sprite_CreateRaw, Sprite_Load |
| `0x38` | 1 | 2 | Sprite_CreateRaw, Sprite_Load |
| `0x39` | 1 | 2 | Sprite_CreateRaw, Sprite_Load |
| `0x3c` | 4 | 3 | Sprite_CreateRaw, Sprite_Destruct, Sprite_Load |
| `0x40` | 4 | 1 | Sprite_Load |
| `0x44` | 4 | 1 | Sprite_Load |
| `0x48` | 0 | 1 | Sprite_Load |
| `0x78` | 4 | 1 | Sprite_LoadIntoSlot78 |
| `0xf4` | 4 | 1 | Sprite_LoadIntoSlot78 |

### SoundDevice

- Vtable: `0x55c830`
- Constructor: `SoundDevice_Construct`
- Destructor: `SoundBuffer_Delete`
- Base guess: ``
- Slots: 4
- Naming notes: slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundBuffer_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x3` | 1 | 1 | SoundBuffer_DestructBase |
| `0x4` | 4 | 1 | SoundDevice_Construct |
| `0x8` | 4 | 1 | SoundBuffer_DestructBase |
| `0xc` | 1 | 1 | SoundDevice_Construct |

### SoundBufferBase

- Vtable: `0x55c840`
- Constructor: `SoundBuffer_ConstructBase`
- Destructor: `SoundBufferBase_Delete`
- Base guess: ``
- Slots: 4
- Naming notes: constructor symbol is SoundBuffer_ConstructBase (base/sibling name); slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundBufferBase_Delete` * |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x3` | 1 | 1 | SoundBuffer_DestructBase |
| `0x4` | 4 | 3 | SoundBuffer_ConstructBase, SoundBuffer_CreateDSBuffer, SoundVoice_Construct |
| `0x8` | 4 | 6 | List_ContainerDestruct, SoundBuffer_CreateDSBuffer, SoundBuffer_DestructBase, SoundBuffer_Destructor, SoundSample_Destruct, SoundVoice_Construct |
| `0xc` | 4 | 4 | SoundBuffer_CreateDSBuffer, SoundBuffer_Destructor, SoundSample_Destruct, SoundVoice_Construct |
| `0xd` | 1 | 3 | SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundStreamBuffer_Destruct |
| `0x10` | 4 | 4 | List_ContainerDestruct, SoundBuffer_CreateDSBuffer, SoundSample_Destruct, SoundVoice_Construct |
| `0x14` | 4 | 3 | List_ContainerDestruct, SoundBuffer_CreateDSBuffer, SoundVoice_Construct |
| `0x18` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundVoice_Construct |
| `0x1c` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundVoice_Construct |
| `0x20` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundVoice_Construct |
| `0x24` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundVoice_Construct |
| `0x28` | 4 | 3 | SoundBuffer_CreateDSBuffer, SoundTrack_Destruct, SoundVoice_Construct |
| `0x2c` | 4 | 3 | SoundBuffer_CreateDSBuffer, SoundTrack_Destruct, SoundVoice_Construct |
| `0x30` | 4 | 3 | SoundBuffer_CreateDSBuffer, SoundTrack_Destruct, SoundVoice_Construct |
| `0x34` | 4 | 3 | SoundBuffer_CreateDSBuffer, SoundTrack_Destruct, SoundVoice_Construct |
| `0x38` | 4 | 5 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundStreamBuffer_Destruct, SoundVoice_Construct |
| `0x3c` | 4 | 3 | SoundBuffer_CreateDSBuffer, SoundSample_Destruct, SoundVoice_Construct |
| `0x40` | 4 | 5 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundStreamBuffer_Destruct, SoundVoice_Construct |
| `0x44` | 4 | 6 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundStreamBuffer_Destruct, SoundTrack_Destruct, SoundVoice_Construct |
| `0x48` | 4 | 5 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundStreamBuffer_Destruct, SoundVoice_Construct |
| `0x4c` | 4 | 1 | SoundVoice_Construct |
| `0x51` | 1 | 1 | SoundVoice_Construct |
| `0x53` | 1 | 1 | SoundVoice_Construct |
| `0x55` | 1 | 1 | SoundVoice_Construct |
| `0x5c` | 4 | 2 | SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Destruct |
| `0x70` | 1 | 1 | SoundVoice_Construct |
| `0x74` | 4 | 1 | SoundVoice_Construct |
| `0x78` | 4 | 1 | SoundVoice_Construct |
| `0x7c` | 4 | 1 | SoundVoice_Construct |
| `0x80` | 4 | 1 | SoundVoice_Construct |
| `0x84` | 4 | 1 | SoundVoice_Construct |
| `0x88` | 1 | 1 | SoundVoice_Construct |
| `0x8c` | 4 | 1 | SoundVoice_Construct |
| `0x90` | 4 | 1 | SoundVoice_Construct |
| `0x94` | 4 | 1 | SoundVoice_Construct |
| `0x98` | 4 | 1 | SoundVoice_Construct |
| `0x9c` | 4 | 1 | SoundVoice_Construct |
| `0xac` | 4 | 1 | SoundStreamBuffer_Destruct |
| `0x149` | 1 | 1 | SoundBuffer_ConstructBase |
| `0x238` | 4 | 2 | SoundBuffer_ConstructBase, SoundPakManager_Destruct |
| `0x628` | 4 | 2 | SoundBuffer_ConstructBase, SoundPakManager_Destruct |

### SoundSample

- Vtable: `0x55c850`
- Constructor: `SoundSample_Construct`
- Destructor: `SoundSample_Delete`
- Base guess: ``
- Slots: 4
- Naming notes: slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundSample_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | SoundSample_Construct |
| `0x8` | 4 | 2 | SoundSample_Construct, SoundSample_Destruct |
| `0xc` | 4 | 2 | SoundSample_Construct, SoundSample_Destruct |
| `0x10` | 4 | 2 | SoundSample_Construct, SoundSample_Destruct |
| `0x28` | 4 | 1 | SoundSample_Construct |
| `0x2c` | 4 | 1 | SoundSample_Construct |
| `0x30` | 4 | 1 | SoundSample_Construct |
| `0x34` | 1 | 1 | SoundSample_Construct |
| `0x38` | 4 | 1 | SoundSample_Construct |
| `0x3c` | 4 | 2 | SoundSample_Construct, SoundSample_Destruct |
| `0x48` | 1 | 1 | SoundSample_Construct |

### DirectSoundBuffer

- Vtable: `0x55c860`
- Constructor: `Sound_CreatePrimaryBuffer`
- Destructor: `DirectSoundBuffer_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: constructor symbol is Sound_CreatePrimaryBuffer (base/sibling name)

| # | Method |
|---:|---|
| 0 | `DirectSoundBuffer_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | DirectSoundBuffer_Delete, DirectSoundBuffer_Destructor |
| `0x10` | 4 | 1 | SoundSystem_Destroy |
| `0x18` | 4 | 1 | SoundSystem_Destroy |
| `0x50` | 4 | 1 | SoundSystem_Destroy |
| `0x58` | 4 | 1 | SoundSystem_Destroy |
| `0x60` | 4 | 1 | SoundSystem_Destroy |
| `0x68` | 4 | 1 | SoundSystem_Destroy |
| `0x70` | 4 | 1 | SoundSystem_Destroy |
| `0x78` | 4 | 1 | SoundSystem_Destroy |
| `0x98` | 4 | 1 | SoundSystem_Destroy |

### SoundPakManagerBase

- Vtable: `0x55c864`
- Constructor: `SoundBuffer_ConstructBase`
- Destructor: `SoundPakManager_Delete`
- Base guess: ``
- Slots: 4
- Naming notes: constructor symbol is SoundBuffer_ConstructBase (base/sibling name); slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundPakManager_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | SoundBuffer_ConstructBase |
| `0x149` | 1 | 1 | SoundBuffer_ConstructBase |
| `0x238` | 4 | 2 | SoundBuffer_ConstructBase, SoundPakManager_Destruct |
| `0x628` | 4 | 2 | SoundBuffer_ConstructBase, SoundPakManager_Destruct |

### SoundBuffer

- Vtable: `0x55c874`
- Constructor: `SoundBuffer_CreateDSBuffer`
- Destructor: `SoundBuffer_DeleteObject`
- Base guess: `SoundBufferBase`
- Slots: 6
- Naming notes: slot0 is RefCount_AddRef; destructor is slot 3; base inferred: SoundBufferBase (slots 0-2 identical; adds slots 4,5); slots 0-2 implement COM AddRef/Release/QueryInterface

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundBuffer_DeleteObject` |
| 4 | `SoundBuffer_vfunc4` * |
| 5 | `Sound_SetVolumeLogarithmic` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x3` | 1 | 1 | SoundBuffer_DestructBase |
| `0x4` | 4 | 3 | SoundBuffer_ConstructBase, SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x8` | 4 | 4 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestructBase, SoundBuffer_Destructor, SoundBuffer_Init |
| `0xc` | 4 | 3 | SoundBuffer_CreateDSBuffer, SoundBuffer_Destructor, SoundBuffer_Init |
| `0xd` | 1 | 3 | SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundStreamBuffer_Destruct |
| `0x10` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x14` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x18` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x1c` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x20` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x24` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x28` | 2 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x2c` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x30` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x34` | 1 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x38` | 4 | 5 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundBuffer_Init, SoundStreamBuffer_Destruct |
| `0x3c` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x40` | 4 | 5 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundBuffer_Init, SoundStreamBuffer_Destruct |
| `0x44` | 4 | 5 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundBuffer_Init, SoundStreamBuffer_Destruct |
| `0x48` | 4 | 5 | SoundBuffer_Construct, SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundStreamBuffer_Destruct |
| `0x4c` | 4 | 1 | SoundBuffer_Construct |
| `0x50` | 4 | 1 | SoundBuffer_Construct |
| `0x54` | 4 | 1 | SoundBuffer_Construct |
| `0x58` | 4 | 1 | SoundBuffer_Construct |
| `0x5c` | 4 | 2 | SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Destruct |
| `0xa0` | 1 | 1 | SoundBuffer_Construct |
| `0xa1` | 1 | 1 | SoundBuffer_Construct |
| `0xa4` | 4 | 1 | SoundBuffer_Construct |
| `0xa8` | 4 | 1 | SoundBuffer_Construct |
| `0xac` | 4 | 1 | SoundStreamBuffer_Destruct |
| `0x149` | 1 | 1 | SoundBuffer_ConstructBase |
| `0x238` | 4 | 1 | SoundBuffer_ConstructBase |
| `0x628` | 4 | 1 | SoundBuffer_ConstructBase |

### SoundStreamBuffer

- Vtable: `0x55c8b0`
- Constructor: `SoundStreamBuffer_Construct`
- Destructor: `SoundStreamBuffer_DeleteObject`
- Base guess: ``
- Slots: 6
- Naming notes: slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundStreamBuffer_DeleteObject` |
| 4 | `SoundStreamBuffer_vfunc4_ForwardQuery` * |
| 5 | `COM_E_NOTIMPL_Ret4` * |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0xd` | 1 | 1 | SoundStreamBuffer_Destruct |
| `0x38` | 4 | 1 | SoundStreamBuffer_Destruct |
| `0x40` | 4 | 1 | SoundStreamBuffer_Destruct |
| `0x44` | 4 | 1 | SoundStreamBuffer_Destruct |
| `0x48` | 4 | 2 | SoundStreamBuffer_Construct, SoundStreamBuffer_Destruct |
| `0x4c` | 4 | 1 | SoundStreamBuffer_Construct |
| `0x50` | 4 | 1 | SoundStreamBuffer_Construct |
| `0x54` | 4 | 1 | SoundStreamBuffer_Construct |
| `0x58` | 4 | 1 | SoundStreamBuffer_Construct |
| `0x5c` | 4 | 1 | SoundStreamBuffer_Destruct |
| `0xa0` | 1 | 1 | SoundStreamBuffer_Construct |
| `0xa1` | 1 | 1 | SoundStreamBuffer_Construct |
| `0xa4` | 4 | 1 | SoundStreamBuffer_Construct |
| `0xa8` | 4 | 1 | SoundStreamBuffer_Construct |
| `0xac` | 4 | 2 | SoundStreamBuffer_Construct, SoundStreamBuffer_Destruct |
| `0xb0` | 4 | 1 | SoundStreamBuffer_Construct |

### SoundStreamBuffer3D

- Vtable: `0x55c8c8`
- Constructor: `SoundStreamBuffer_Construct`
- Destructor: `SoundBuffer_ScalarDeletingDestructor`
- Base guess: `SoundStreamBuffer`
- Slots: 6
- Naming notes: constructor symbol is SoundStreamBuffer_Construct (base/sibling name); slot0 is RefCount_AddRef; destructor is slot 3; base inferred: SoundStreamBuffer (slots 0-2,4,5 identical; only slot 3 differs); slots 0-2 implement COM AddRef/Release/QueryInterface

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundBuffer_ScalarDeletingDestructor` |
| 4 | `SoundStreamBuffer_vfunc4_ForwardQuery` * |
| 5 | `COM_E_NOTIMPL_Ret4` * |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0xc` | 4 | 1 | Sound_CreateAndRegisterBuffer |
| `0xd` | 1 | 2 | SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Destruct |
| `0x28` | 1 | 1 | Sound_CreateAndRegisterBuffer |
| `0x38` | 4 | 2 | SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Destruct |
| `0x40` | 4 | 2 | SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Destruct |
| `0x44` | 4 | 2 | SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Destruct |
| `0x48` | 4 | 5 | SoundBuffer_Construct, SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Construct, SoundStreamBuffer_Destruct, Sound_CreateAndRegisterBuffer |
| `0x4c` | 4 | 3 | SoundBuffer_Construct, SoundStreamBuffer_Construct, Sound_CreateAndRegisterBuffer |
| `0x50` | 4 | 3 | SoundBuffer_Construct, SoundStreamBuffer_Construct, Sound_CreateAndRegisterBuffer |
| `0x54` | 4 | 3 | SoundBuffer_Construct, SoundStreamBuffer_Construct, Sound_CreateAndRegisterBuffer |
| `0x58` | 4 | 3 | SoundBuffer_Construct, SoundStreamBuffer_Construct, Sound_CreateAndRegisterBuffer |
| `0x5c` | 4 | 2 | SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Destruct |
| `0x98` | 4 | 1 | Sound_CreateAndRegisterBuffer |
| `0xa0` | 1 | 2 | SoundBuffer_Construct, SoundStreamBuffer_Construct |
| `0xa1` | 1 | 3 | SoundBuffer_Construct, SoundStreamBuffer_Construct, Sound_CreateAndRegisterBuffer |
| `0xa4` | 4 | 3 | SoundBuffer_Construct, SoundStreamBuffer_Construct, Sound_CreateAndRegisterBuffer |
| `0xa8` | 4 | 3 | SoundBuffer_Construct, SoundStreamBuffer_Construct, Sound_CreateAndRegisterBuffer |
| `0xac` | 4 | 2 | SoundStreamBuffer_Construct, SoundStreamBuffer_Destruct |
| `0xb0` | 4 | 1 | SoundStreamBuffer_Construct |

### SoundVoice

- Vtable: `0x55c8e0`
- Constructor: `SoundVoice_Construct`
- Destructor: `SoundTrack_Delete`
- Base guess: ``
- Slots: 4
- Naming notes: slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundTrack_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | SoundVoice_Construct |
| `0x8` | 4 | 1 | SoundVoice_Construct |
| `0xc` | 4 | 1 | SoundVoice_Construct |
| `0x10` | 4 | 1 | SoundVoice_Construct |
| `0x14` | 4 | 1 | SoundVoice_Construct |
| `0x18` | 4 | 1 | SoundVoice_Construct |
| `0x1c` | 4 | 1 | SoundVoice_Construct |
| `0x20` | 4 | 1 | SoundVoice_Construct |
| `0x24` | 4 | 1 | SoundVoice_Construct |
| `0x28` | 4 | 2 | SoundTrack_Destruct, SoundVoice_Construct |
| `0x2c` | 4 | 2 | SoundTrack_Destruct, SoundVoice_Construct |
| `0x30` | 4 | 2 | SoundTrack_Destruct, SoundVoice_Construct |
| `0x34` | 4 | 2 | SoundTrack_Destruct, SoundVoice_Construct |
| `0x38` | 4 | 1 | SoundVoice_Construct |
| `0x3c` | 1 | 1 | SoundVoice_Construct |
| `0x40` | 4 | 1 | SoundVoice_Construct |
| `0x44` | 4 | 2 | SoundTrack_Destruct, SoundVoice_Construct |
| `0x48` | 4 | 1 | SoundVoice_Construct |
| `0x4c` | 4 | 1 | SoundVoice_Construct |
| `0x51` | 1 | 1 | SoundVoice_Construct |
| `0x53` | 1 | 1 | SoundVoice_Construct |
| `0x55` | 1 | 1 | SoundVoice_Construct |
| `0x70` | 1 | 1 | SoundVoice_Construct |
| `0x74` | 4 | 1 | SoundVoice_Construct |
| `0x78` | 4 | 1 | SoundVoice_Construct |
| `0x7c` | 4 | 1 | SoundVoice_Construct |
| `0x80` | 4 | 1 | SoundVoice_Construct |
| `0x84` | 4 | 1 | SoundVoice_Construct |
| `0x88` | 1 | 1 | SoundVoice_Construct |
| `0x8c` | 4 | 1 | SoundVoice_Construct |
| `0x90` | 4 | 1 | SoundVoice_Construct |
| `0x94` | 4 | 1 | SoundVoice_Construct |
| `0x98` | 4 | 1 | SoundVoice_Construct |
| `0x9c` | 4 | 1 | SoundVoice_Construct |

### SoundMixerThread

- Vtable: `0x55c8f0`
- Constructor: `SoundVoiceThread_Construct`
- Destructor: `SoundMixerThread_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: constructor symbol is SoundVoiceThread_Construct (base/sibling name)

| # | Method |
|---:|---|
| 0 | `SoundMixerThread_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | SoundMixerThread_Destroy, SoundVoiceThread_Construct |
| `0x8` | 4 | 1 | SoundVoiceThread_Construct |
| `0xc` | 4 | 2 | SoundMixerThread_Destroy, SoundVoiceThread_Construct |
| `0xd` | 1 | 1 | SoundMixerThread_Destroy |
| `0x10` | 4 | 2 | SoundMixerThread_Destroy, SoundVoiceThread_Construct |
| `0x2c` | 4 | 2 | SoundMixerThread_Destroy, SoundVoiceThread_Construct |
| `0x30` | 4 | 2 | SoundMixerThread_Destroy, SoundVoiceThread_Construct |
| `0x34` | 1 | 1 | SoundVoiceThread_Construct |

### ListContainer

- Vtable: `0x55cb04`
- Constructor: ``
- Destructor: `List_ContainerDestroy`
- Base guess: ``
- Slots: 4
- Naming notes: slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `List_ContainerDestroy` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | List_ContainerDestruct |
| `0x10` | 4 | 1 | List_ContainerDestruct |
| `0x14` | 4 | 1 | List_ContainerDestruct |

### SoundBufferAux

- Vtable: `0x55cb14`
- Constructor: ``
- Destructor: `SoundBuffer_Delete2`
- Base guess: ``
- Slots: 4
- Naming notes: slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundBuffer_Delete2` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | SoundBuffer_Destructor |
| `0xc` | 4 | 1 | SoundBuffer_Destructor |

### DebugConsole

- Vtable: `0x55cb3c`
- Constructor: `DebugConsole_Construct`
- Destructor: `DebugConsole_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `DebugConsole_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | DebugConsole_Construct, DebugConsole_Destructor |
| `0x8` | 4 | 1 | DebugConsole_Construct |
| `0xc` | 4 | 1 | DebugConsole_Construct |
| `0x20` | 4 | 1 | DebugConsole_Construct |
| `0x24` | 4 | 2 | DebugConsole_Construct, DebugConsole_Destructor |

### UI_BriefingList

- Vtable: `0x55cb40`
- Constructor: `UI_BriefingList_Construct`
- Destructor: `UI_BriefingList_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `UI_BriefingList_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x18` | 4 | 2 | UI_BriefingList_Destroy, UI_BriefingList_Save |
| `0x20` | 4 | 1 | UI_BriefingList_Construct |
| `0x24` | 4 | 1 | UI_BriefingList_Construct |
| `0x28` | 4 | 1 | UI_BriefingList_Construct |
| `0x30` | 4 | 1 | UI_BriefingList_Construct |
| `0x34` | 4 | 1 | UI_BriefingList_Construct |

### EmployeeAvatar

- Vtable: `0x55cb44`
- Constructor: `EmployeeAvatar_Construct`
- Destructor: `EmployeeAvatar_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

| # | Method |
|---:|---|
| 0 | `EmployeeAvatar_Delete` |

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x18` | 4 | 1 | EmployeeAvatar_Construct |
| `0x34` | 4 | 1 | EmployeeAvatar_Construct |
| `0x50` | 4 | 1 | EmployeeAvatar_Construct |
| `0x6c` | 4 | 1 | EmployeeAvatar_Construct |
| `0x88` | 4 | 1 | EmployeeAvatar_Construct |
| `0xa4` | 4 | 1 | EmployeeAvatar_Construct |
| `0xc0` | 4 | 1 | EmployeeAvatar_Construct |
| `0xdc` | 4 | 1 | EmployeeAvatar_Construct |


## Deliverables

- `vtables_full.csv` - one row per vtable with class, ctor/dtor, base, slots and notes
- `vtable_slot_targets.csv` - one row per virtual slot with target status and inferred name
- `class_skeletons.json` - full machine-readable skeletons, slots and observed field offsets
- `class_skeletons/<Class>.md` - 65 per-class skeleton files (game, UI, sound, rendering)
- `vtable_annotations.json` - 77 vtable data labels applied in REA
- `vtable_slot_functions.json` - 75 indirect-only function entries with all slot uses
- `all_symbols_with_vtables.json` - 3,029 procedures + 75 slot functions + 77 vtable labels
- `VTABLE_CLASS_VERIFICATION.json` - counts, readback results, hashes and limitations
- `vtables_classes_rea-evidence.json` - importable REA Evidence bundle
- `tools/build_class_skeletons.py` - reproducible generator

