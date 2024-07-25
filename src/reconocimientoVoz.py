import speech_recognition as sr

def main():
    recognizer = sr.Recognizer()

    # Verificar si el micrófono está disponible
    try:
        with sr.Microphone() as source:
            print("Ajustando el micrófono para el ruido ambiente...")
            recognizer.adjust_for_ambient_noise(source)
            print("Escuchando...")
            # Captura de audio con un tiempo de espera
            audio = recognizer.listen(source, timeout=10)
            try:
                print("Reconociendo...")
                text = recognizer.recognize_google(audio, language='es-ES')  # Cambia 'es-ES' por el idioma que prefieras
                print("Texto reconocido: " + text)
            except sr.UnknownValueError:
                print("No se pudo entender el audio")
            except sr.RequestError:
                print("No se pudo conectar al servicio de reconocimiento de voz")
    except sr.RequestError:
        print("No se pudo obtener el micrófono")

if __name__ == "__main__":
    main()
