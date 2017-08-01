 * Zaimplementować kolejkę FIFO dla typu int
 * Zaimplementować program testujący kolejkę:
 * Program posiada N wątków pobierających dane z kolejki
 * Wątek główny wrzuca przez M sekund losowe liczby na kolejkę
 * Każdy z N wątków K razy wypisuje specyficzny dla siebie log
 * M i N są argumentami programu
 * K jest wartością pobraną z kolejki
 * Program ma się zakończyć “na czysto”, wszystkie wątki muszą być “z-join'owane”
 * Dla podstawowych elementów wielowątkowych koniecznie
   wykorzystaj elementy zaimplementowane w poprzednim zadaniu
 * TIP: zastanów się nad użyciem bariery (np. boost::barrier lub własnej
   implementacji)
