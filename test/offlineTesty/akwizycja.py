import cv2
import os

# Tworzenie folderu "img", jeśli nie istnieje
if not os.path.exists("img"):
    os.makedirs("img")

# Inicjalizacja kamery
cap = cv2.VideoCapture(0)

frame_count = 1

while True:
    # Pobieranie klatki obrazu z kamery
    ret, frame = cap.read()

    # Zapisywanie klatki jako obrazu PNG
    filename = f"img/{str(frame_count).zfill(6)}.png"
    cv2.imwrite(filename, frame)

    # Wyświetlanie informacji o zapisanej klatce
    print(f"Zapisano klatkę: {filename}")

    frame_count += 1

    # Przerwanie pętli po naciśnięciu klawisza 'q'
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Zwalnianie zasobów kamery i zamykanie okna
cap.release()
cv2.destroyAllWindows()