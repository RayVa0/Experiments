import random
import time



def init():
    x = random.randint(2,4)
    print("gay = ", end='', flush=True)

    if x == 1:
        gay()
    elif x == 2:
        bad()
    elif x == 3:
        netflix()
    else:
        woke()

def bad():
    print("bad = ", end='', flush=True)
    time.sleep(0.1)

    x = random.randint(1,3)

    if x == 1:
        gay()
    elif x == 2:
        netflix()
    else:
        woke()

def gay():
    print("gay = ", end='', flush=True)
    time.sleep(0.1)

    x = random.randint(1,3)

    if x == 1:
        netflix()
    elif x == 2:
        bad()
    else:
        woke()

def woke():
    print("woke = ", end='', flush=True)
    time.sleep(0.1)

    x = random.randint(1,3)

    if x == 1:  
        netflix()
    elif x == 2:
        bad()
    else:
        gay()
def netflix():
    print("netflix = ", end='', flush=True)
    time.sleep(0.1)

    x = random.randint(1,3)

    if x == 1:  
        woke()
    elif x == 2:
        bad()
    else:
        gay()

init()
