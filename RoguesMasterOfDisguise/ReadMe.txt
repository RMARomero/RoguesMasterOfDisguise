Features:

Generen random dungeon 
    - x aantal verdiepingen
    - Random opbouw van kamers in de verdieping, te manipuleren dmv enkele variabelen
    - Elke kamer gerandomized -> Random beschrijving (dmv tekstfile), Random items te vinden, Random traps, Random enemies
    - Stairs om van verdieping te veranderen

Vechten
    - Combat system waarbij gevochten kan worden tegen monsters in een kamer
    - Turn based
    - Normale mobs, gedefinieerd in een tekstbestand waar niet alleen de stats worden gedefinieerd maar ook de levels waar ze te vinden zijn
    - Boss mobs, ook gedefinieerd in het tekstbestand en 1 hiervan spawned in de laatste kamer (boss room)
    - Verslaan van monsters geeft xp, waar de speler levels van omhoog kan gaan en daardoor sterker wordt

Rest
    - Kan uitrusten zolang er geen monsters in de buurt zijn
    - Kans dat je wordt aangevallen tijdens het rusten

Inventory
    - Het bekijken van de huidige items van de speler
    - Het gebruiken van de huidige items van de speler
        (vb: Health potion: Restores health)
    - Items zijn gerandomized op basis van de waarden in de tekstfile

Search
    - Zoeken in de kamer naar items
    - Elke kamer heeft een kans een item te bevatten, maar soms duurt het even zoeken voor je het vind

Traps
    - Elke kamer kan een trap bevatten (random)
    - Tijdens het zoeken van items kan een trap geactiveerd worden
    - Verschillende traps verschillende resultaten

Map
    - Kan een weergave opvragen van de huidige verdieping
    - Hierop zijn alle kamers te zien inclusief de verbindende hallen
    - 

Stats
    - Gebruiker kan huidige stats opvragen (Level, Xp, Attack, Defense)


Saven Status Hero
    - Automatisch na elke gameTick
    - Laden kan door dezelfde naam te gebruiken in het introscherm als voorheen
    - Inventory wordt mee opgeslagen, naast het huidige level/xp/attack/defense etc.
    - Hardcore mode: Save-file delete als je dood gaat


