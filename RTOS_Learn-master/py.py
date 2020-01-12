
import threading as th

import time
class Watek(th.Thread2):
    def __init__(self,numer):
        self.numer= numer
        super().__init__()
#
    def run(self):
        for i in range(100):
            time.sleep(1)
            print("Watek" +str(self.numer)+"-"+str(i))
#
w1 = Watek(1)
w2 = Watek(2)
w1.start()
w2.start()
