# Pizza Connection 2 — mission/campaign data

Source: `main.pak` → `daten/<city>.ini` (German tab-separated init files).

These ten files define the campaign order, city modifiers, goal IDs, starting conditions and briefing text. `mission.txt` lists the city order: `lon, ber, mad, par, rom, syd, mos, tok, rio, yor`.

| City | Code | Country | Difficulty | Goals (ZIELE) | Start money | Opponents | Play years |
|---|---|---|---:|---|---:|---:|---:|
| Berlin | `ber` | Germany | 20 | 3/4/5 | 70,000 | 2 | 3 |
| London | `lon` | UK | 10 | 0/1/2 | 500,000 | 1 | 2 |
| Madrid | `mad` | Spain | 40 | 6/7/8 | 50,000 | 2 | 3 |
| Moscow | `mos` | Russia | 100 | 24/19/20 | 70,000 | 4 | 5 |
| Paris | `par` | France | 80 | 9/10/11 | 40,000 | 3 | 5 |
| Rio de Janeiro | `Rio` | Brasil | 100 | 18/25/26 | 40,000 | 2 | 5 |
| Roma | `rom` | Italy | 70 | 12/13/14 | 60,000 | 4 | 2 |
| Sydney | `syd` | Australia | 60 | 15/16/17 | 50,000 | 5 | 4 |
| Tokyo | `tok` | Japan | 90 | 21/22/23 | 80,000 | 3 | 2 |
| New York | `yor` | USA | 100 | 27/28/29 | 30,000 | 1 | 10 |

## Key fields

| Key | Meaning |
|---|---|
| `NAME` | city display name |
| `SHORT` | three-letter city code used by `mission.txt` and `%s.iso` |
| `LAND` | country/taste region |
| `MIETEN` | rent multiplier (50 = neutral) |
| `GEDULT` | patience multiplier |
| `KAUFPREIS` | purchase-price multiplier |
| `EINKOMMEN` | income multiplier |
| `QUALITAET` | quality expectation |
| `KOMFORT` | comfort expectation |
| `KLIMA` | spring/summer/autumn/winter temperatures |
| `BEVOELKERUNG` | population percentage |
| `RATTE` | rat tolerance |
| `KAKERLAKE` | cockroach tolerance |
| `STINKBOMBE` | stink-bomb tolerance |
| `PUNK` | punk tolerance |
| `GRAFFITI` | graffiti tolerance |
| `VOLK` | population split: kids/teens/students/proll/clerk/rich/grufti/tourist |
| `BESUCHER` | stadium visitor rates by group |
| `GESCHMACK` | country taste preferences |
| `BESONDERHEIT` | special-city flag |
| `SCHWIERIGKEITSGRAD` | difficulty 0-100 |
| `POLIZEIANZAHL` | police presence |
| `SPIELZEIT` | campaign length in years |
| `ZIELE` | goal IDs from the mission goal table |
| `STARTHQ` | starting HQ level 0-6 |
| `MAXHQ` | maximum HQ level |
| `STARTGELD` | starting money |
| `GEGNERANZAHL` | number of AI opponents 0-5 |
| `GEGNER_STARTHQ` | opponent starting HQ |
| `GEGNER_MAXHQ` | opponent maximum HQ |
| `BRIEFING` | intro text |
| `DEBRIEFING` | outro text |
| `FILIALEN` | starting branch layout: owner/size/style/owned |
| `SCHLAGER` | music rating by target group |
| `EINFACH` | furniture rating by target group |

Full normalized records, including briefing/debriefing text: `mission_data.csv`.
