# RemoteLab_Wobball
# Aufgabenblatt – Remote Lab: Kugel auf beweglicher Plattform

## Ziel

In diesem Versuch steuerst du eine Kugel auf einer Arduino-gesteuerten beweglichen Plattform. Die Kugel liegt auf einem Display und ihre Position können über die bereitgestellte API ausgelesen werden.

Aufbau der Aufgaben:
1. Aufgabe wird geschildert und erklärt
2. Hinweise und Tipps zur Umsetzung
3. Musterlösung oder Beispielcode

Weitere Hinweise:
- Display: Nextion 5.0" TFT Touch Display:
  - Auflösung: 800x480 Pixel
  - Schnittstelle: UART (Serial)
  - weitere Informationen: [Nextion Display Datasheet](https://nextion.tech/datasheets/NX8048P050-011R/)

---

## Aufgabe 1: Punkte auf dem Displays plotten

1.1: Zeichne einen blauen Punkt an der Position **(400, 240)** auf dem Display. Nutze dafür das die Nextionbefehle (siehe Nextion-Dokumentation).
    [[?]]Über die Funktion void sendNextionCommand(const char *command) kannst du Nextion-Befehle an das Display senden.


**Ziel:** Verstehen, wie Punkte auf dem Display dargestellt werden.






**Hinweise:**
- Übr die Funktion void sendNextionCommand(const char *command) kannst du Nextion-Befehle an das Display senden.

```cpp
void sendNextionCommand(const char *command) {
    Serial1.print(command);
    Serial1.write(0xFF);
    Serial1.write(0xFF);
    Serial1.write(0xFF);
}
```
(*siehe Nextion-Dokumentation*)

**Musterlösung:**

```cpp 
char cmd[64];
sprintf(cmd, "cirs %d,%d,2,31", 400 , 240);
sendNextionCommand(cmd);


---

## Aufgabe 2: Kugelkoordinaten ausgeben

Lass dir die aktuellen Koordinaten der Kugel ausgeben.

**Hinweis:** Mit der Methode `jiggle()` kannst du die Kugel leicht anstoßen, damit sich ihre Position verändert.

**Ausgabe-Beispiel:**

```text
x = 123
y = 87
```

**Ziel:** Die Positionsdaten der Kugel auslesen und anzeigen.

---

## Aufgabe 3: Bewegung der Kugel visualisieren

Plotte kontinuierlich einen Punkt an der aktuellen Position der Kugel.

### Anforderungen

* Immer dort einen Punkt zeichnen, wo die Kugel das Display berührt.
* Es dürfen maximal **10 Punkte gleichzeitig** sichtbar sein.
* Sobald ein elfter Punkt hinzugefügt wird, soll der **älteste Punkt gelöscht** werden.

### Beispiel

```text
P1 P2 P3 P4 P5 P6 P7 P8 P9 P10
```

Nach dem nächsten Messpunkt:

```text
P2 P3 P4 P5 P6 P7 P8 P9 P10 P11
```

**Ziel:** Die Bewegung der Kugel als Spur darstellen.

---

## Aufgabe 4: Geschwindigkeit und Richtung berechnen

Gib über die serielle Schnittstelle (`Serial`) kontinuierlich aus:

* Geschwindigkeit in **Pixel pro Sekunde (px/s)**
* Bewegungsrichtung in **Grad (°)**

### Ausgabe-Beispiel

```text
Geschwindigkeit: 54.2 px/s
Richtung: 137.5°
```

### Hinweise

* Berechne die Geschwindigkeit aus zwei aufeinanderfolgenden Positionsmessungen.
* Die Richtung kann über den Winkel zwischen den beiden Positionen bestimmt werden.

**Ziel:** Bewegungsdaten der Kugel auswerten.

---

## Bonusaufgabe 5: Position vorhersagen

Schreibe eine Funktion

```cpp
predict(x, y, vel, dir)
```

welche aus

* aktueller X-Koordinate
* aktueller Y-Koordinate
* Geschwindigkeit (`vel`)
* Richtung (`dir`)

die erwartete Position der Kugel **eine Sekunde später** berechnet.

### Anforderungen

1. Berechne die vorhergesagte Position.
2. Gib die vorhergesagten Koordinaten aus.
3. Zeichne zur Visualisierung einen Punkt an der vorhergesagten Position.

### Beispiel

```text
Aktuelle Position: (100, 50)
Geschwindigkeit: 20 px/s
Richtung: 0°

Vorhersage nach 1 s:
(120, 50)
```

**Ziel:** Einführung in Bewegungsmodelle und Vorhersage von Positionen.

---

## Abgabe

Für jede Aufgabe:

1. Quellcode dokumentieren.
2. Kurze Beschreibung der Lösung.
3. Screenshot oder Foto der Ausgabe bzw. Visualisierung.