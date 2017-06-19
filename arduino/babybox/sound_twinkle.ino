int melody2[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4,
NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations2[] = {
  2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};


void twinkle_song() {
  int size = sizeof(melody2) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations2[thisNote];
 
      tone(BUZZER_PIN, melody2[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      tone(BUZZER_PIN, 0, noteDuration);
    }
}

