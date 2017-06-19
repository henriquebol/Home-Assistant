

//Elfen Lied:

int melody[] = {
NOTE_FS4, NOTE_CS5, NOTE_GS4, 0, 0, NOTE_A4, NOTE_A4, 0,
NOTE_FS4, NOTE_CS5, NOTE_GS4, 0, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_FS4,
0, 0,
NOTE_GS4, NOTE_E4, NOTE_D4, NOTE_E4,
0, 0,
NOTE_FS4, NOTE_D4, NOTE_CS4, NOTE_D4, NOTE_E4, NOTE_FS4, 0,
NOTE_GS4, NOTE_A4, NOTE_B4, NOTE_A4, 0,
NOTE_CS4, NOTE_FS4, NOTE_CS4, NOTE_GS4, 0,
NOTE_FS4, NOTE_CS5, NOTE_GS4, 0, 0, NOTE_A4, NOTE_A4, 0,
NOTE_FS4, NOTE_CS5, NOTE_GS4, 0, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_FS4,
0, 0,
NOTE_GS4, NOTE_E4, NOTE_D4, NOTE_E4,
0, 0,
NOTE_FS4, NOTE_D4, NOTE_CS4, NOTE_D4, NOTE_B4, NOTE_A4,
NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_DS4, NOTE_F4, NOTE_FS4
};

int noteDurations[] = {
4, 4, 4, 4, 4, 4, 4, 4,
4, 4, 4, 4, 4, 4, 4, 4,
4, 4,
4, 4, 4, 4,
4, 4,
4, 4, 4, 4, 4, 4, 4,
4, 4, 4, 4, 4,
4, 4, 4, 4, 2,
4, 4, 4, 4, 4, 4, 4, 4,
4, 4, 4, 4, 4, 4, 4, 4,
4, 4,
4, 4, 4, 4,
4, 4,
4, 4, 4, 4, 4, 4, 4,
4, 4, 4, 4, 4, 4, 4
};

void elfen_song() {
  int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
 
      tone(BUZZER_PIN, melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      tone(BUZZER_PIN, 0, noteDuration);
    }
}

