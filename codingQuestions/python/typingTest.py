# import keyboard -- this is root for read key input
from pynput.keyboard import Key, Listener
import random
import string
import time

LETTERS_TO_TYPE = list(string.ascii_lowercase)


class TypingGame():

    keys_pressed = []
    currentAttempt = None
    loopingListen = True

    def __init__(self):
        self.currentAttempt = LETTERS_TO_TYPE.copy()
        self.keys_pressed = []
        self.loopingListen = False

    def onPress(self, key):
        if key == Key.esc:
            self.loopingListen = False
            return False
        c = None
        try:
            c = key.char
            self.keys_pressed.append(c)
            self.loopingListen = False
            return False
        except AttributeError:
            # only listening to regular letter characters
            return True

    def onRelease(self):
        pass

    def typeTheLetter(self):
        idx = 0
        while (len(self.currentAttempt) >= 0):
            idx = random.randint(0, len(self.currentAttempt) - 1)

            ch = self.currentAttempt[idx]
            print("type " + ch)

            correctPress = False
            while correctPress is False:
                listener = Listener(
                    on_press=self.onPress,
                    on_release=self.onRelease
                )
                listener.start()

                self.loopingListen = True
                while self.loopingListen:
                    time.sleep(0.5)

                listener.stop()
                listener.join()

                if len(self.keys_pressed) > 0:
                    # check only the first key pressed, then continue
                    k = self.keys_pressed[0]
                    if k == Key.esc:
                        return False
                    if k == ch:
                        # correct key, set flag and continue
                        self.currentAttempt.remove(ch)
                        correctPress = True


def __main__():
    game = TypingGame()
    print(game.currentAttempt)

    start = time.time()
    res = game.typeTheLetter()
    if res is False:
        print("escaped")
        return
    end = time.time()

    print(f"Time taken to type all letters: {round(end-start, 2)}s")


if __name__ == "__main__":
    __main__()
